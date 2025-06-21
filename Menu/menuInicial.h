#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <bits/stdc++.h>
#include "../Utils/dificuldade.h"
#include "../Personagem/jogador.h"
#include "../Missao/gerenciadorMissoes.h"
#include "../Missao/missao.h"
#include "../Inventario/consumiveis.h"
using namespace std;

class MenuIni {
    
    private:

        Jogador* player;
        Dificuldade dif;
        int missaoAtual = 0;

    public:
        MenuIni(Jogador*, int missaoAtual = 0);
        void mostra_menu();

        Jogador* getPlayer();

        void menuPrinc();
        void inicio();
        void preferencias();
        void reset();
        void menuLoja(Jogador* player);
};

#endif