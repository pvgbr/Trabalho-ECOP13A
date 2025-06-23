#include "batalhaNormal.h"
#include <unistd.h>
#include <limits>

BatalhaNormal::BatalhaNormal(Jogador* p, Inimigo& e) : Batalha(p), enemy(e) {
    if (!p) {
        throw invalid_argument("Ponteiro do jogador não pode ser nulo");
    }
}

void BatalhaNormal::atacar(Personagem &atacante, Personagem &defensor, bool jogador) {
    if (!player) {
        throw runtime_error("Ponteiro do jogador é nulo durante o ataque");
    }

    string frases[8] = {
        " atacou fortemente ",
        " arrebentou ",
        " acabou com ",
        " desferiu um golpe certeiro em ",
        " surpreendeu ",
        " esmagou ",
        " não deu chance para ",
        " fez um ataque crítico em "
    };
    
    int forcaTotalAtacante = atacante.getForca();
    int defesaTotalDefensor = defensor.getDefesa();
    if(jogador) {
        if (auto* p = dynamic_cast<Jogador*>(&atacante)) {
                forcaTotalAtacante += p->getBonusAtaqueEquipado();
        }
    }
    else {
        if (auto* p = dynamic_cast<Jogador*>(&defensor)) {
            defesaTotalDefensor += p->getBonusDefesaEquipado();
        }
        // Aplicar multiplicador de dano de inimigo
        Dificuldade dif(player->getDificuldade());
        forcaTotalAtacante = static_cast<int>(forcaTotalAtacante * dif.getMultiplicadorDanoInimigo());
    }

    int dano = (forcaTotalAtacante * 1.2) - (defesaTotalDefensor * 0.8);
    if (dano < 1) dano = 1;

    defensor.alterarVida(-dano);
    int f = rand() % 8;
    cout << atacante.getNome() << frases[f] << defensor.getNome() << "! ⚔️" << endl;
    cout << defensor.getNome() << " levou " << dano << " de dano! 💥" << endl;
}

int BatalhaNormal::escolhaBatalha(){
    if (!player) {
        throw runtime_error("Ponteiro do jogador é nulo durante a escolha da batalha");
    }

    int escolha;
    while (!(cin >> escolha)) {
        cout << "Entrada inválida! Digite um número: ";
        cin.clear();
        cin.ignore();
    }
    
    switch(escolha) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            player->mostrarConsumiveisBatalha();
            if (player->getInvConsumivel().getItens().empty()) {
                cout << "Pressione Enter para voltar..." << endl;
                cin.ignore();
                cin.ignore();
                return -1;
            }
            cout << "Escolha qual item deseja usar (ou 0 para cancelar): " << endl;
            int escolhaItem;
            while (!(cin >> escolhaItem)) {
                cout << "Entrada inválida! Digite um número: ";
                cin.clear();
                cin.ignore();
            }
            if (escolhaItem > 0) {
                player->usarConsumivelBatalha(escolhaItem);
                return 3;
            }
            return -1;
        default:
            cout << "Escolha inválida!" << endl;
            return -1;
    }
}

bool BatalhaNormal::batalhar() {
    if (!player) {
        throw runtime_error("Ponteiro do jogador é nulo durante a batalha");
    }

    int turno = 1;
    
    while(player->estaVivo() && enemy.estaVivo()) {
        system("cls");

        // Exibir status no início de cada turno
        cout << "     ------------------------      " << endl;
        cout << "     " << enemy.getNome() << " 👾" << endl;
        cout << "     Vida: " << enemy.getVida() << " ❤️" << endl;
        cout << "     ------------------------      " << endl << endl;

        cout << endl << "     ------------------------      " << endl;
        cout << "     " << player->getNome() << " 🧑‍🎤" << endl;
        cout << "     Vida: " << player->getVida() << " ❤️" << endl;
        cout << "     ------------------------      " << endl << endl << endl;

        if (turno % 2 != 0) { // Turno do Jogador
            // Reduz durabilidade dos equipamentos a cada turno
            player->reduzirDurabilidadeEquipamentos();
            
            cout << " >> Seu turno! << " << endl;
            cout << " Escolha uma ação: " << endl;
            cout << "   1 - Atacar ⚔️" << endl;
            cout << "   2 - Usar habilidade ✨" << endl;
            cout << "   3 - Usar item 🧪" << endl;
            
            int escolha = escolhaBatalha();
            if (escolha == -1) {
                continue;
            }
            bool acaoRealizada = false;
            switch(escolha){
                case 1:
                    atacar(*player, enemy, true);
                    cin.ignore();
                    acaoRealizada = true;
                    break;
                case 2: {
                    cout << "Escolha a habilidade (ou 0 para cancelar):" << endl;
                    if (!usouGolpeDuplo) cout << "  1 - Golpe Duplo (Ataca duas vezes) 💥" << endl;
                    else cout << "  1 - Golpe Duplo (JÁ USADO)" << endl;
                    if (!usouAtaqueGelo) cout << "  2 - Ataque de Gelo (Pode congelar o inimigo) ❄️" << endl;
                    else cout << "  2 - Ataque de Gelo (JÁ USADO)" << endl;
                    int hab;
                    while (cin >> hab && (hab < 0 || hab > 2)) {
                        cout << "Escolha inválida! Digite 1 ou 2: ";
                        cin.clear();
                        cin.ignore();
                    }
                    cin.ignore();
                    if(hab == 0) break;
                    if ((hab == 1 && usouGolpeDuplo) || (hab == 2 && usouAtaqueGelo)) {
                        cout << "Você já usou essa habilidade nesta batalha! Escolha outra ação. ⚠️" << endl;
                        cout << "\nPressione Enter para continuar... 👉" << endl;
                        cin.ignore();
                        break;
                    }
                    if (hab == 2) {
                        cout << "\033[1;36m";
                        cout << R"(
   *    *   *
 *    *   *    *
   *  ❄️  *   *
 *   *   *    *
)";
                        cout << "\033[0m";
                    }
                    auto resultado = player->usarHabilidade(static_cast<HabilidadeJogador>(hab), &enemy);
                    if (hab == 1) usouGolpeDuplo = true;
                    if (hab == 2) usouAtaqueGelo = true;
                    if (hab == 2 && resultado.second) {
                        inimigoCongelado = true;
                        cout << "\033[1;34m";
                        cout << R"(
   ██████████
  ██        ██
 ██  INIMIGO  ██
 ██ CONGELADO ██
  ██        ██
   ██████████
)";
                        cout << "O inimigo está completamente congelado! 🧊\n";
                        cout << "\033[0m";
                    }
                    acaoRealizada = true;
                    break;
                }
                case 3: 
                    cout<< "Você usou um item! 🧪" << endl;
                    acaoRealizada = true;
                    break;
            }
            if(acaoRealizada) {
                cout << "\nPressione Enter para continuar... 👉" << endl;
                cin.ignore();
                turno++;
            }
        } else { // Turno do Inimigo
            if (inimigoCongelado) {
                cout << "\033[1;34m"; // Azul
                cout << R"(
   ██████████
  ██        ██
 ██  INIMIGO  ██
 ██ CONGELADO ██
  ██        ██
   ██████████
)";
                cout << "O inimigo está congelado e perde o turno!\n";
                cout << "\033[0m";
                inimigoCongelado = false;
                cout << "\nPressione Enter para continuar... 👉" << endl;
                cin.ignore();
                turno++;
                continue;
            }
            cout << " >> Turno de " << enemy.getNome() << "! <<" << endl;
            atacar(enemy, *player, false);
            cout << "\nPressione Enter para continuar... 👉" << endl;
            cin.ignore();
            turno++;
        }
    }
    
    system("cls");
    bool venceu = player->estaVivo();
    // Resetar controle de habilidades ao fim da batalha
    usouGolpeDuplo = false;
    usouAtaqueGelo = false;
    if (venceu) {
        eventoAleatorioPosBatalha();
    }
    return venceu;
}

void BatalhaNormal::eventoAleatorioPosBatalha() {
    int chance = rand() % 100;
    if (chance < 10) { // 30% de chance
        cout << "\033[1;31m"; // Vermelho
        cout << R"(
   !!! INIMIGO SURPRESA APARECEU !!!
   ████████████████████████████
   ██                        ██
   ██    INIMIGO SURPRESA    ██
   ██         👹            ██
   ██                        ██
   ████████████████████████████
)";
        cout << "\033[0m";
        cout << "\nUm inimigo surpresa salta das sombras! Prepare-se para lutar novamente!\n";
        // Cria um inimigo surpresa simples
        Inimigo inimigoSurpresa("Inimigo Surpresa", 5 + rand()%6, 3 + rand()%4, Dificuldade(1 + rand()%3));
        sleep(2);
        BatalhaNormal novaBatalha(player, inimigoSurpresa);
        novaBatalha.batalhar();
    }
}

Jogador* BatalhaNormal::getPlayer() { 
    if (!player) {
        throw runtime_error("Ponteiro do jogador é nulo ao tentar acessá-lo");
    }
    return player; 
}