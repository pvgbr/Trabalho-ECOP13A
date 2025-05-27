#ifndef BATALHAMULTIPLA_H
#define BATALHAMULTIPLA_H

#include <bits/stdc++.h>
#include "batalha.h"
#include "../Personagem/jogador.h"
#include "../Personagem/inimigo.h"

class BatalhaMultipla : public Batalha {

    protected:

        Inimigo enemy[5];    

    public:

        BatalhaMultipla(Jogador*, Inimigo[]);
        ~BatalhaNormal() { }

        int escolhaBatalha();
        void batalhar();
        void atacar(Personagem&, Personagem&);
};

#endif