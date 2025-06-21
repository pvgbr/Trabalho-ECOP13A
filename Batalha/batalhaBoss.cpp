#include "batalhaBoss.h"
#include <bits/stdc++.h>

using namespace std;

BatalhaBoss::BatalhaBoss(Jogador* player, Boss& bossRef)
    : Batalha(player), boss(bossRef), jogadorDefendendo(false) {}

bool BatalhaBoss::batalhar() {
    bool usouGolpeDuplo = false;
    bool usouAtaqueGelo = false;
    bool bossCongelado = false;
    int turno = 1;

    cout << R"(

================ BATALHA FINAL =================
        _.-^^---....,,--        
    _--                  --_   
   <                        >)
   |  BOSS FINAL APARECEU!  | 
    \._                   _./ 
       ```--. . , ; .--'''    
             | |   |          
          .-=||  | |=-.       
          `-=#$%&%$#=-'       
             | ;  :|          
    _____.,-#%&$@%#&#~,._____

)";
    cout << "\nO Boss ruge: 'Você chegou longe, mas aqui será seu fim! Prepare-se para o verdadeiro poder!\n";
    cout << "\nPressione Enter para começar a batalha...";
    cin.ignore();
    cin.get();

    while (player->estaVivo() && boss.estaVivo()) {
        system("cls");
        cout << "\n========= TURNO " << turno << " =========\n";
        boss.imprimir_dados();
        cout << endl;
        player->imprimir_dados();
        cout << endl;

        // TURNO DO JOGADOR
        if (!bossCongelado) {
            cout << "Sua vez! Escolha sua ação:\n";
            cout << "1 - Atacar\n";
            cout << "2 - Defender (reduz dano do próximo ataque)\n";
            cout << "3 - Usar Habilidade\n";
            cout << "4 - Usar Consumível\n";
            int acao = 0;
            while (!(cin >> acao) || acao < 1 || acao > 4) {
                cout << "Opção inválida! Escolha 1-4: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            switch (acao) {
                case 1: { // Atacar
                    int dano = player->getForca() + player->getBonusAtaqueEquipado() + (rand() % 6);
                    boss.alterarVida(-dano);
                    cout << "Você ataca o Boss e causa " << dano << " de dano!\n";
                    break;
                }
                case 2: { // Defender
                    jogadorDefendendo = true;
                    cout << "Você se prepara para defender o próximo ataque!\n";
                    break;
                }
                case 3: { // Usar Habilidade
                    cout << "Escolha a habilidade:\n";
                    if (!usouGolpeDuplo) cout << "  1 - Golpe Duplo (Ataca duas vezes)\n";
                    else cout << "  1 - Golpe Duplo (JÁ USADO)\n";
                    if (!usouAtaqueGelo) cout << "  2 - Ataque de Gelo (Pode congelar o Boss)\n";
                    else cout << "  2 - Ataque de Gelo (JÁ USADO)\n";
                    int hab = 0;
                    while (!(cin >> hab) || hab < 1 || hab > 2) {
                        cout << "Escolha inválida! Digite 1 ou 2: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore();
                    if (hab == 1 && usouGolpeDuplo) {
                        cout << "Você já usou Golpe Duplo nesta batalha!\n";
                        break;
                    }
                    if (hab == 2 && usouAtaqueGelo) {
                        cout << "Você já usou Ataque de Gelo nesta batalha!\n";
                        break;
                    }
                    if (hab == 1) {
                        player->usarHabilidade(HabilidadeJogador::GOLPE_DUPLO, &boss);
                        usouGolpeDuplo = true;
                    } else if (hab == 2) {
                        auto resultado = player->usarHabilidade(HabilidadeJogador::ATAQUE_GELO, &boss);
                        usouAtaqueGelo = true;
                        if (resultado.second) {
                            bossCongelado = true;
                            cout << R"(
   ██████████
  ██        ██
 ██  BOSS    ██
 ██ CONGELADO ██
  ██        ██
   ██████████
)";
                            cout << "O Boss foi CONGELADO e perderá o próximo turno!\n";
                        }
                    }
                    break;
                }
                case 4: { // Usar Consumível
                    player->mostrarConsumiveisBatalha();
                    cout << "Escolha o número do consumível para usar (0 para cancelar): ";
                    int idx;
                    cin >> idx;
                    cin.ignore();
                    if (idx > 0) {
                        if (!player->usarConsumivelBatalha(idx - 1)) {
                            cout << "Não foi possível usar o consumível!\n";
                        }
                    } else {
                        cout << "Ação cancelada.\n";
                    }
                    break;
                }
            }
            cout << "\nPressione Enter para continuar...";
            cin.get();
        } else {
            cout << R"(
   ██████████
  ██        ██
 ██  BOSS    ██
 ██ CONGELADO ██
  ██        ██
   ██████████
)";
            cout << "O Boss está congelado e perde o turno!\n";
            bossCongelado = false;
            cout << "\nPressione Enter para continuar...";
            cin.get();
            turno++;
            continue;
        }

        // CHECA VITÓRIA ANTES DO TURNO DO BOSS
        if (!boss.estaVivo()) {
            cout << "\nVOCÊ DERROTOU O BOSS FINAL! O reino está salvo!\n";
            cout << "Frase final do Boss: '" << boss.getFraseFinal() << "'\n";
            cout << R"(

   * * * * * * * * * * * * * * * * * * * *
  *   PARABÉNS, HERÓI! VOCÊ VENCEU!   *
   * * * * * * * * * * * * * * * * * * * *
)";
            cout << "\nPressione Enter para encerrar a batalha...";
            cin.get();
            return true;
        }

        // TURNO DO BOSS
        system("cls");
        cout << "\n========= TURNO " << turno << " (Boss) =========\n";
        boss.imprimir_dados();
        cout << endl;
        player->imprimir_dados();
        cout << endl;
        cout << "Turno do Boss!\n";
        int acaoBoss = rand() % 100;
        if (acaoBoss < 50) { // Ataque normal (50%)
            int dano = boss.getForca() + (rand() % 8);
            if (jogadorDefendendo) {
                dano /= 2;
                cout << "Você defendeu! O dano foi reduzido pela metade!\n";
            }
            player->alterarVida(-dano);
            cout << "O Boss ataca e causa " << dano << " de dano em você!\n";
        } else if (acaoBoss < 70) { // Ataque Especial (20%)
            int dano = boss.ataqueEspecial();
            if (jogadorDefendendo) {
                dano /= 2;
                cout << "Você defendeu! O dano foi reduzido pela metade!\n";
            }
            player->alterarVida(-dano);
        } else if (acaoBoss < 85) { // RAIO ANIQUILADOR (15%)
            cout << R"(
   ⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡
)";
            int dano = boss.getForca() * 2 + (rand() % 21);
            if (jogadorDefendendo) {
                dano /= 2;
                cout << "Você defendeu! O dano foi reduzido pela metade!\n";
            }
            cout << "O Boss canaliza energia e dispara o RAIO ANIQUILADOR!\n";
            cout << "Você recebe " << dano << " de dano devastador!\n";
            player->alterarVida(-dano);
        } else { // REGENERAÇÃO DRAGÔNICA (15%)
            int vidaAntes = boss.getVida();
            boss.usarHabilidade(HabilidadeBoss::REGENERACAO_DRAGONICA);
            int vidaDepois = boss.getVida();
            cout << "O Boss se regenera! Recuperou " << (vidaDepois - vidaAntes) << " de vida.\n";
        }
        jogadorDefendendo = false;
        cout << "\nPressione Enter para continuar...";
        cin.get();

        // CHECA DERROTA
        if (!player->estaVivo()) {
            cout << R"(

   X X X X X X X X X X X X X X X X X X X X
  X         VOCÊ FOI DERROTADO...        X
   X X X X X X X X X X X X X X X X X X X X
)";
            cout << "\nO Boss triunfa e o reino cai nas trevas...\n";
            cout << "\nPressione Enter para encerrar a batalha...";
            cin.get();
            return false;
        }
        turno++;
    }
    return false;
} 