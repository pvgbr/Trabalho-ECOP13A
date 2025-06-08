#ifndef FASE_H
#define FASE_H

#include <bits/stdc++.h>
#include "../Utils/dificuldade.h"
#include "../Personagem/jogador.h"
#include "../Personagem/inimigo.h"

class Fase {
    protected:

        Jogador* player;
        Inimigo enemy[4];

        int dif;
        int fase;
        
    public:

        Fase(Jogador*);
        ~Fase() { }

        void menu();
        
        void setJogador(Jogador*);
        void setFase(int);
        int getFase();

        Jogador* getPlayer();
         
        void iniciarBatalha();
};

#endif