#include "fase.h"
#include "../Batalha/batalhaNormal.h"
#include "../Batalha/batalhaMultipla.h"


Fase::Fase(Jogador* p) : player{p} {

    fase = player->getFase();
    dif = player->getDificuldade();

    Dificuldade d(dif);

    enemy[0].setNome("Inimigo 1");
    enemy[0].setForca(1 * player->getNivel() + fase);
    enemy[0].setDefesa(1 * fase + player->getNivel());
    enemy[0].setNivel(1);
    enemy[0].setDific(d);
    enemy[0].setVida(100);
    enemy[0].set_recompensas();
    
    enemy[1].setNome("Inimigo 2");
    enemy[1].setForca(1 * player->getNivel() + fase);
    enemy[1].setDefesa(1 * fase + player->getNivel());
    enemy[1].setNivel(1);
    enemy[1].setDific(d);
    enemy[1].setVida(100);
    enemy[1].set_recompensas();

    enemy[2].setNome("Inimigo 3");
    enemy[2].setForca(1 * player->getNivel() + fase);
    enemy[2].setDefesa(1 * fase + player->getNivel());
    enemy[2].setNivel(1);
    enemy[2].setDific(d);
    enemy[2].setVida(100);
    enemy[2].set_recompensas();

    enemy[3].setNome("Inimigo 4");
    enemy[3].setForca(1 * player->getNivel() + fase);
    enemy[3].setDefesa(1 * fase + player->getNivel());
    enemy[3].setNivel(1);
    enemy[3].setDific(d);
    enemy[3].setVida(100);
    enemy[3].set_recompensas();
}

void Fase::setJogador(Jogador* p) { player = p; }

void Fase::iniciarBatalha() {
    switch(fase) {
        case 1: {
            BatalhaNormal bat1(player, enemy[0]);
            bat1.batalhar();
            break;
        }
        case 2: {
            BatalhaMultipla bat2(player, enemy);
            break;
        }
        default: {
            BatalhaNormal bat1(player, enemy[0]);
            bat1.batalhar();
            break;
        }
    }
}

void Fase::setFase(int f) {
    fase = f;
}

int Fase::getFase() {
    return fase;
}

Jogador* Fase::getPlayer() { return player; }

void Fase::menu(){
    while(true){
        int e;
        system("cls");
        player->imprimir_dados();
        cout<< "Fase: " << fase << endl;
        cout<< "Dificuldade: " << dif << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Sair" << endl;
        cout << "Escolha uma opção para continuar: ";
        cin >> e;
        switch(e){
            case 1:
                system("cls");
                iniciarBatalha();
                break;
            default:
                system("cls");
                break;
        }
        if(e == 2) break;
    }
    
}