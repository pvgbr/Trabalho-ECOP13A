#ifndef INIMIGO_H
#define INIMIGO_H

#include <bits/stdc++.h>
#include "personagem.h"
#include "jogador.h"
#include "../Utils/dificuldade.h"

using namespace std;

class Inimigo : public Personagem {

    protected:
        int recompensaXP;
        int recompensaDinheiro;

        Dificuldade dif;
        
    public:
        Inimigo() { }
        Inimigo(string, int, int, Dificuldade);
        ~Inimigo() { }

        void imprimir_dados();
        void setDific(Dificuldade);
        int get_recompensaXP();
        int get_recompensaDinheiro();

        void set_recompensas();
};

#endif