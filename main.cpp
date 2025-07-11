#include <bits/stdc++.h>
#include <windows.h>
#include "Batalha/batalhaNormal.h"
#include "Menu/menuInicial.h"
#include "Personagem/jogador.h"
#include "Personagem/inimigo.h"
#include "Utils/dificuldade.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_  UTF8);
    srand(time(NULL));
    
    Jogador* player = new Jogador();
    int missaoAtual = 0;

    ifstream teste("save.txt");
    if (teste.good()) {
        player->carregar("save.txt", &missaoAtual);
    }

    MenuIni m(player, missaoAtual);

    m.menuPrinc();

    delete player;
    return 0;
}