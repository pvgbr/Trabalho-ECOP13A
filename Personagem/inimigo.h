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
        
    public:

        Inimigo(string, int, int, Dificuldade);
        ~Inimigo() { }

        void imprimir_dados();

};

#endif