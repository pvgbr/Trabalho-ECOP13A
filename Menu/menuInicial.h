#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <bits/stdc++.h>
#include "../Utils/dificuldade.h"
#include "../Personagem/jogador.h"
#include "../Missao/gerenciadorMissoes.h"
#include "../Missao/missao.h"
#include "../Inventario/consumiveis.h"
using namespace std;

// Classe de Menu inicial, na qual todo o jogo acontece
class MenuIni {
    
    private:

        Jogador* player;
        Dificuldade dif;
        int missaoAtual = 0;

    public:
        MenuIni(Jogador*, int missaoAtual = 0);

        Jogador* getPlayer();

        void menuPrinc(); // Função para imprimir o menu
        void inicio(); // Função de inicio do jogo, com a historia incial e criação de personagem
        void preferencias(); // Função para alterar preferencias do jogo
        void reset(); // Função para resetar o jogo
};

#endif