#ifndef BATALHANORMAL_H
#define BATALHANORMAL_H

#include "batalha.h"
#include <bits/stdc++.h>

class BatalhaNormal : public Batalha {

    protected:

        Inimigo enemy;

    public:

        BatalhaNormal(Jogador*, Inimigo);
        ~BatalhaNormal() { }
        
        int escolhaBatalha();
        void batalhar();
        void atacar(Personagem&, Personagem&);

        Jogador* getPlayer();
};

#endif