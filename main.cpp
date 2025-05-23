#include <bits/stdc++.h>
#include <windows.h>
#include "Menu/menuInicial.h"
#include "Personagem/jogador.h"
#include "Personagem/inimigo.h"
#include "Utils/dificuldade.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    

    Jogador player;
    MenuIni m(player);

    ifstream teste("save.txt");
    if (teste.good()) {
        player.carregar("save.txt");
    } else {
        player = m.getPlayer();
    }

    m.menuPrinc();

    return 0;
}