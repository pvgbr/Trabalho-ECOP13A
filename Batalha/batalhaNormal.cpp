#include "batalhaNormal.h"
#include <unistd.h>

BatalhaNormal::BatalhaNormal(Jogador* p, Inimigo e) : Batalha(p), enemy{e} { }



void BatalhaNormal::atacar(Personagem &atacante, Personagem &defensor) {
    string frases[3] = {" atacou fortemente ", " arrebentou ", " acabou com " };
    int ataque = (atacante.getForca() * 10 - defensor.getDefesa()) * -1;
    defensor.alterarVida(ataque);
    int f = rand() % 3;
    cout << atacante.getNome() << frases[f] << defensor.getNome() << endl;
    cout << defensor.getNome() << " levou " << ataque * -1 << " de dano!" << endl;
    
}

int BatalhaNormal::escolhaBatalha(){
    int escolha;
    cin >> escolha;
            switch(escolha) {
                case 1:
                    return 1;
                    break;
                case 2:
                    //player->usarHabilidade(enemy);
                    return 2;
                    break;
                case 3:
                    int escolhaItem;
                    player->mostrarInventariosCompletos();
                    cout << "Escolha qual item deseja usar: " << endl;
                    cin >> escolhaItem;
                        switch (escolhaItem){
                            case 1: // Poção de vida
                                
                                break;
                            case 2: // Poção de força

                                break;
                            default:
                                break;
                        }
                    return 3;
                    break;
                default:
                    cout << "Escolha inválida!" << endl;
                    return -1;
            }
}

void BatalhaNormal::batalhar() {
    int turno = 1;

    int vidaP = player->getVida();
    int vidaE = enemy.getVida();
    int escolha;
    
    while(player->estaVivo() && enemy.getVida() > 0) {
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
            escolha = escolhaBatalha();
            system("cls");
        }

        cout << "     ------------------------      " << endl;
        cout << "     " << enemy.getNome() << endl;
        cout << "     Vida: " << enemy.getVida() << endl;
        cout << "     ------------------------      " << endl << endl;

        if(turno % 2){
            switch(escolha){
                case 1:
                    atacar(*player, enemy);
                    break;
                case 2:
                    cout<< "Jogador usou habilidade!" << endl;
                    break;
                case 3: 
                    cout<< "Jogador usou um item!" << endl;
                    break;
                default:
                    break;
            }
        }else atacar(enemy, *player);
         

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
        player->alterarDinheiro(enemy.get_recompensaDinheiro());
        player->alterarXP(enemy.get_recompensaXP());
        player->setFase(player->getFase() + 1);
        cin.ignore();
        cout << "Pressione enter para continuar!" << endl;
    }
    else {
        cout << enemy.getNome() <<" venceu a batalha! " << endl;
        cin.ignore();
        cout << "Pressione enter para continuar!" << endl;
    }
}

Jogador* BatalhaNormal::getPlayer() { return player; }