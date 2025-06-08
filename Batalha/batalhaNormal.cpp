#include "batalhaNormal.h"
#include <unistd.h>
#include <limits>

BatalhaNormal::BatalhaNormal(Jogador* p, Inimigo& e) : Batalha(p), enemy(e) {
    if (!p) {
        throw std::invalid_argument("Ponteiro do jogador não pode ser nulo");
    }
}

void BatalhaNormal::atacar(Personagem &atacante, Personagem &defensor, bool jogador) {
    if (!player) {
        throw std::runtime_error("Ponteiro do jogador é nulo durante o ataque");
    }

    string frases[3] = {" atacou fortemente ", " arrebentou ", " acabou com " };
    
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
    }

    // Fórmula de dano mais balanceada
    int dano = (forcaTotalAtacante * 1.2) - (defesaTotalDefensor * 0.8);
    if (dano < 1) dano = 1; // Garante um dano mínimo de 1

    defensor.alterarVida(-dano);
    int f = rand() % 3;
    cout << atacante.getNome() << frases[f] << defensor.getNome() << endl;
    cout << defensor.getNome() << " levou " << dano << " de dano!" << endl;
}

int BatalhaNormal::escolhaBatalha(){
    if (!player) {
        throw std::runtime_error("Ponteiro do jogador é nulo durante a escolha da batalha");
    }

    int escolha;
    while (!(cin >> escolha)) {
        cout << "Entrada inválida! Digite um número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                return -1;
            }
            cout << "Escolha qual item deseja usar (ou 0 para cancelar): " << endl;
            int escolhaItem;
            while (!(cin >> escolhaItem)) {
                cout << "Entrada inválida! Digite um número: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        throw std::runtime_error("Ponteiro do jogador é nulo durante a batalha");
    }

    int turno = 1;
    
    while(player->estaVivo() && enemy.estaVivo()) {
        system("cls");

        // Exibir status no início de cada turno
        cout << "     ------------------------      " << endl;
        cout << "     " << enemy.getNome() << endl;
        cout << "     Vida: " << enemy.getVida() << endl;
        cout << "     ------------------------      " << endl << endl;

        cout << endl << "     ------------------------      " << endl;
        cout << "     " << player->getNome() << endl;
        cout << "     Vida: " << player->getVida() << endl;
        cout << "     ------------------------      " << endl << endl << endl;

        if (turno % 2 != 0) { // Turno do Jogador
            cout << " >> Seu turno! << " << endl;
            cout << " Escolha uma acao: " << endl;
            cout << "   1 - Atacar" << endl;
            cout << "   2 - Usar habilidade (Nao implementado)" << endl;
            cout << "   3 - Usar item" << endl;
            
            int escolha = escolhaBatalha();
            if (escolha == -1) {
                continue;
            }
            bool acaoRealizada = false;
            switch(escolha){
                case 1:
                    atacar(*player, enemy, true);
                    acaoRealizada = true;
                    break;
                case 2:
                    cout<< "Habilidades ainda nao foram implementadas!" << endl;
                    break;
                case 3: 
                    cout<< "Voce usou um item!" << endl;
                    acaoRealizada = true;
                    break;
            }
            if(acaoRealizada) {
                cout << "\nPressione Enter para continuar..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                turno++;
            }
        } else { // Turno do Inimigo
            cout << " >> Turno de " << enemy.getNome() << "! <<" << endl;
            atacar(enemy, *player, false);
            cout << "\nPressione Enter para continuar..." << endl;
            cin.ignore();
            turno++;
        }
    }
    
    system("cls");
    return player->estaVivo();
}

Jogador* BatalhaNormal::getPlayer() { 
    if (!player) {
        throw std::runtime_error("Ponteiro do jogador é nulo ao tentar acessá-lo");
    }
    return player; 
}