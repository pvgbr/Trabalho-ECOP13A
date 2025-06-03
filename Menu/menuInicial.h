#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <bits/stdc++.h>
#include "../Fase/fase.h"
#include "../Utils/dificuldade.h"
#include "../Personagem/jogador.h"
using namespace std;

class MenuIni {
    
    private:

        Jogador* player;
        Dificuldade dif;


    public:
        MenuIni(Jogador*);
        void mostra_menu();

        Jogador* getPlayer();

        void menuPrinc();
        void inicio();
        void preferencias();
        void reset();
        void menuPreparacaoFase();
};

#endif