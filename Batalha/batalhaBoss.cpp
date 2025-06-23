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
    system("cls");

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
    cout << "\nO Boss ruge: 'Você chegou longe, mas aqui será seu fim! Prepare-se para o verdadeiro poder! 🐲'\n";
    cout << "\nPressione Enter para começar a batalha... ⚔️";
    cin.ignore();

    while (player->estaVivo() && boss.estaVivo()) {
        system("cls");
        cout << "\n========= TURNO " << turno << " =========\n";
        // RESUMO VISUAL DOS STATUS
        cout << "================== STATUS ==================" << endl;
        cout << "👑 Boss:  " << boss.getNome() << endl;
        cout << "   Vida:  ";
        int vidaBoss = boss.getVida();
        int vidaBossMax = 200; // Valor simbólico, ajuste se necessário
        int barraBoss = (vidaBoss * 20) / vidaBossMax;
        cout << "[";
        for(int i=0;i<20;i++) cout << (i<barraBoss?"█":" ");
        cout << "] " << vidaBoss << " ❤️" << endl;
        cout << "   Força: " << boss.getForca() << " 💪   Defesa: " << boss.getDefesa() << " 🛡️" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "🧑‍🎤 Jogador: " << player->getNome() << endl;
        cout << "   Vida:  ";
        int vidaPlayer = player->getVida();
        int vidaPlayerMax = 100; // Valor simbólico, ajuste se necessário
        int barraPlayer = (vidaPlayer * 20) / vidaPlayerMax;
        cout << "[";
        for(int i=0;i<20;i++) cout << (i<barraPlayer?"█":" ");
        cout << "] " << vidaPlayer << " ❤️" << endl;
        cout << "   Força: " << player->getForca() << " (+" << player->getBonusAtaqueEquipado() << ") 💪   Defesa: " << player->getDefesa() << " (+" << player->getBonusDefesaEquipado() << ") 🛡️" << endl;
        cout << "   Dinheiro: " << player->getDinheiro() << " 💰" << endl;
        cout << "===========================================\n" << endl;

        // TURNO DO JOGADOR
        if (!bossCongelado) {
            // Reduz durabilidade dos equipamentos a cada turno
            player->reduzirDurabilidadeEquipamentos();
            
            cout << "Sua vez! Escolha sua ação:\n";
            cout << "1 - Atacar\n";
            cout << "2 - Defender (reduz dano do próximo ataque)\n";
            cout << "3 - Usar Habilidade\n";
            cout << "4 - Usar Consumível\n";
            int acao = 0;
            while (!(cin >> acao) || acao < 1 || acao > 4) {
                cout << "Opção inválida! Escolha 1-4: ";
                cin.clear();
                cin.ignore();
            }
            cin.ignore();
            switch (acao) {
                case 1: { // Atacar
                    int dano = player->getForca() + player->getBonusAtaqueEquipado() + (rand() % 6);
                    boss.alterarVida(-dano);
                    cout << "\n💥 Você salta e desfere um golpe poderoso no Boss! 💥\n";
                    cout << "🔥 Dano causado: " << dano << "! 🔥\n";
                    cout << "-----------------------------" << endl;
                    break;
                }
                case 2: { // Defender
                    jogadorDefendendo = true;
                    cout << "\n🛡️ Você ergue seu escudo e se prepara para o impacto! Defesa ativada! 🛡️\n";
                    cout << "-----------------------------" << endl;
                    break;
                }
                case 3: { // Usar Habilidade
                    cout << "Escolha a habilidade:\n";
                    if (!usouGolpeDuplo) cout << "  1 - Golpe Duplo (Ataca duas vezes) 💥" << endl;
                    else cout << "  1 - Golpe Duplo (JÁ USADO)" << endl;
                    if (!usouAtaqueGelo) cout << "  2 - Ataque de Gelo (Pode congelar o Boss) ❄️" << endl;
                    else cout << "  2 - Ataque de Gelo (JÁ USADO)" << endl;
                    int hab = 0;
                    while (!(cin >> hab) || hab < 1 || hab > 2) {
                        cout << "Escolha inválida! Digite 1 ou 2: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore();
                    if (hab == 1 && usouGolpeDuplo) {
                        cout << "Você já usou Golpe Duplo nesta batalha!" << endl;
                        break;
                    }
                    if (hab == 2 && usouAtaqueGelo) {
                        cout << "Você já usou Ataque de Gelo nesta batalha!" << endl;
                        break;
                    }
                    if (hab == 1) {
                        cout << "\n💥💥 Você executa o GOLPE DUPLO! Dois ataques rápidos atingem o Boss! 💥💥\n";
                        player->usarHabilidade(HabilidadeJogador::GOLPE_DUPLO, &boss);
                        usouGolpeDuplo = true;
                        cout << "-----------------------------" << endl;
                    } else if (hab == 2) {
                        cout << "\n❄️ Você canaliza energia e lança o ATAQUE DE GELO! ❄️\n";
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
                            cout << "O Boss foi CONGELADO e perderá o próximo turno! 🧊\n";
                        }
                        cout << "-----------------------------" << endl;
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
                            cout << "Não foi possível usar o consumível!" << endl;
                        } else {
                            cout << "\n🧪 Você usou um consumível! Energia restaurada! 🧪\n";
                        }
                    } else {
                        cout << "Ação cancelada." << endl;
                    }
                    cout << "-----------------------------" << endl;
                    break;
                }
            }
            cout << "\nPressione Enter para continuar... 👉 👉";
            cin.ignore();
        } else {
            cout << R"(
   ██████████
  ██        ██
 ██  BOSS    ██
 ██ CONGELADO ██
  ██        ██
   ██████████
)";
            cout << "O Boss está congelado e perde o turno! 🧊\n";
            bossCongelado = false;
            cout << "\nPressione Enter para continuar... 👉 👉";
            cin.ignore();
            turno++;
            continue;
        }

        // CHECA VITÓRIA ANTES DO TURNO DO BOSS
        if (!boss.estaVivo()) {
            cout << "\nVOCÊ DERROTOU O BOSS FINAL! O reino está salvo! 🏆\n";
            cout << "Frase final do Boss: '" << boss.getFraseFinal() << "'\n";
            cout << R"(

   * * * * * * * * * * * * * * * * * * * *
  *   PARABÉNS, HERÓI! VOCÊ VENCEU!     *
   * * * * * * * * * * * * * * * * * * * *
)";
            cout << "\nPressione Enter para encerrar a batalha... 🥇";
            cin.ignore();
            return true;
        }

        // TURNO DO BOSS
        system("cls");
        cout << "\n========= TURNO " << turno << " (Boss) =========\n";
        // RESUMO VISUAL DOS STATUS
        cout << "================== STATUS ==================" << endl;
        cout << "👑 Boss:  " << boss.getNome() << endl;
        cout << "   Vida:  ";
        vidaBoss = boss.getVida();
        barraBoss = (vidaBoss * 20) / vidaBossMax;
        cout << "[";
        for(int i=0;i<20;i++) cout << (i<barraBoss?"█":" ");
        cout << "] " << vidaBoss << " ❤️" << endl;
        cout << "   Força: " << boss.getForca() << " 💪   Defesa: " << boss.getDefesa() << " 🛡️" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "🧑‍🎤 Jogador: " << player->getNome() << endl;
        cout << "   Vida:  ";
        vidaPlayer = player->getVida();
        barraPlayer = (vidaPlayer * 20) / vidaPlayerMax;
        cout << "[";
        for(int i=0;i<20;i++) cout << (i<barraPlayer?"█":" ");
        cout << "] " << vidaPlayer << " ❤️" << endl;
        cout << "   Força: " << player->getForca() << " (+" << player->getBonusAtaqueEquipado() << ") 💪   Defesa: " << player->getDefesa() << " (+" << player->getBonusDefesaEquipado() << ") 🛡️" << endl;
        cout << "   Dinheiro: " << player->getDinheiro() << " 💰" << endl;
        cout << "===========================================\n" << endl;
        cout << "Turno do Boss! 🐲\n";
        int acaoBoss = rand() % 100;
        if (acaoBoss < 50) { // Ataque normal (50%)
            int dano = boss.getForca() + (rand() % 8);
            if (jogadorDefendendo) {
                dano /= 2;
                cout << "🛡️ Você defendeu! O dano foi reduzido pela metade! 🛡️\n";
            }
            player->alterarVida(-dano);
            cout << "😈 O Boss desfere um ataque brutal! Você recebe " << dano << " de dano! 💢\n";
            cout << "-----------------------------" << endl;
        } else if (acaoBoss < 70) { // Ataque Especial (20%)
            int dano = boss.ataqueEspecial();
            if (jogadorDefendendo) {
                dano /= 2;
                cout << "🛡️ Você defendeu! O dano foi reduzido pela metade! 🛡️\n";
            }
            player->alterarVida(-dano);
            cout << "🔥 O Boss usa um ATAQUE ESPECIAL! Você recebe " << dano << " de dano! 🔥\n";
            cout << "-----------------------------" << endl;
        } else if (acaoBoss < 85) { // RAIO ANIQUILADOR (15%)
            cout << R"(
   ⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡
)";
            int dano = boss.getForca() + (rand() % 21);
            if (jogadorDefendendo) {
                dano /= 2;
                cout << "🛡️ Você defendeu! O dano foi reduzido pela metade! 🛡️\n";
            }
            cout << "⚡ O Boss canaliza energia e dispara o RAIO ANIQUILADOR! Você recebe " << dano << " de dano devastador! ⚡\n";
            player->alterarVida(-dano);
            cout << "-----------------------------" << endl;
        } else { // REGENERAÇÃO DRAGÔNICA (15%)
            int vidaAntes = boss.getVida();
            boss.usarHabilidade(HabilidadeBoss::REGENERACAO_DRAGONICA);
            int vidaDepois = boss.getVida();
            cout << "🧬 O Boss ativa REGENERAÇÃO DRAGÔNICA! Recuperou " << (vidaDepois - vidaAntes) << " de vida! 🧬\n";
            cout << "-----------------------------" << endl;
        }
        jogadorDefendendo = false;
        cout << "\nPressione Enter para continuar... 👉 👉";
        cin.ignore();

        // CHECA DERROTA
        if (!player->estaVivo()) {
            cout << R"(

   X X X X X X X X X X X X X X X X X X X X
  X         VOCÊ FOI DERROTADO...        X
   X X X X X X X X X X X X X X X X X X X X
)";
            cout << "\nO Boss triunfa e o reino cai nas trevas... 💀\n";
            cout << "\nPressione Enter para encerrar a batalha... 👉";
            cin.ignore();
            return false;
        }
        turno++;
    }
    return false;
} 