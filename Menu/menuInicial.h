#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <bits/stdc++.h>
#include "../Personagem/jogador.h"
using namespace std;

class MenuIni {
    
    private:
        string nome;
        int dificuldade;

        Jogador player;

    public:
        MenuIni(Jogador);
        void mostra_menu();
        string getNome();
        Jogador getPlayer();
        int getDificuldade();
        void menuPrinc();
        void inicio();
        void preferencias();
};

#endif