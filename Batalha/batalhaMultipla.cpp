
#include "batalhaMultipla.h"
#include <unistd.h>

BatalhaMultipla::BatalhaMultipla(Jogador* p, Inimigo e[]) : Batalha(p), enemy{e} { }

string frases[3] = {" atacou fortemente ", " arrebentou ", " acabou com " };

void BatalhaMultipla::atacar(Personagem &atacante, Personagem &defensor) {
    int ataque = (atacante.getForca() * 10 - defensor.getDefesa()) * -1;
    defensor.alterarVida(ataque);
    int f = rand() % 3;
    cout << atacante.getNome() << frases[f] << defensor.getNome() << endl;
    cout << defensor.getNome() << " levou " << ataque * -1 << " de dano!" << endl;
    
}

int BatalhaMultipla::escolhaBatalha(int escolhaIni) {
    int escolhaAcao;
    cin >> escolhaAcao;
            switch(escolhaAcao) {
                case 1:
                    system("cls");
                    escolhaIni = escolhaInimigo();
                    return 1;
                    break;
                case 2:
                    //player->usarHabilidade(enemy);
                    return 2;
                    break;
                case 3:
                    //player->usarItem();
                    return 3;
                    break;
                default:
                    cout << "Escolha inválida!" << endl;
                    return -1;
            }
}

int BatalhaMultipla::escolhaInimigo(){
    int escolha;
    cout << "Escolha um inimigo para atacar: " << endl;
    cout << "1 - " << enemy[1].getNome() << endl;
    cout << "2 - " << enemy[2].getNome() << endl;
    cout << "3 - " << enemy[3].getNome() << endl;
    cin >> escolha;

    switch(escolha) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            cout << "Escolha inválida!" << endl;
            return -1;
    }
}

void BatalhaMultipla::batalhar() {
    int turno = 1;

    int vidaP = player->getVida();
    int vidaE1 = enemy[1].getVida();
    int vidaE2 = enemy[2].getVida();
    int vidaE3 = enemy[3].getVida();
    int escolha;
    int escolhaIni;
    
    while(player->estaVivo() && (enemy[1].getVida() > 0 || enemy[2].getVida() > 0 || enemy[3].getVida() > 0)) {
        if(turno % 2) {
            cout << "     ------------------------      " << endl;
            cout << "     " << enemy.getNome() << endl;
            cout << "     Vida: " << enemy.getVida() << endl;
            cout << "     ------------------------      " << endl << endl;

            cout << endl << "     ------------------------      " << endl;
            cout << "     " << player->getNome() << endl;
            cout << "     Vida: " << player->getVida() << endl;
            cout << "     ------------------------      " << endl << endl << endl;
            
            cout << " Escolha uma ação: " << endl;
            cout << "   1 - Atacar" << endl;
            cout << "   2 - Usar habilidade" << endl;
            cout << "   3 - Usar item" << endl;
            escolha = escolhaBatalha(&escolhaIni);
            system("cls");
        }

        cout << "     ------------------------      " << endl;
        cout << "     " << enemy.getNome() << endl;
        cout << "     Vida: " << enemy.getVida() << endl;
        cout << "     ------------------------      " << endl << endl;

        if(turno % 2 && escolha == 1) atacar(*player, enemy);
        else atacar(enemy, *player);
         

        cout << endl << "     ------------------------      " << endl;
        cout << "     " << player->getNome() << endl;
        cout << "     Vida: " << player->getVida() << endl;
        cout << "     ------------------------      " << endl << endl << endl;

        if(escolha != -1) turno++; 
        sleep(2);
        system("cls");
    }
    
    if(player->estaVivo()) {
        cout << player->getNome() << " venceu a batalha! " << endl;
        player->setVida(vidaP);
        enemy.setVida(vidaE);
        player->alterarDinheiro(enemy.get_recompensaDinheiro());
        player->alterarXP(enemy.get_recompensaXP());
        player->setFase(player->getFase() + 1);
        cin.ignore();
        cout << "Pressione enter para continuar!" << endl;
    }
    else {
        cout << enemy.getNome() <<" venceu a batalha! " << endl;
        player->setVida(vidaP);
        enemy.setVida(vidaE);
        player->alterarDinheiro(enemy.get_recompensaDinheiro());
        player->alterarXP(enemy.get_recompensaXP());
        cin.ignore();
        cout << "Pressione enter para continuar!" << endl;
    }
}

Jogador* BatalhaMultipla::getPlayer() { return player; }