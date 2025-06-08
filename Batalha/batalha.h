#ifndef BATALHA_H
#define BATALHA_H

#include <bits/stdc++.h>

#include "../Personagem/jogador.h"
#include "../Personagem/inimigo.h"



class Batalha {

    protected:

        Jogador* player;

    public:

        Batalha(Jogador*);
        ~Batalha() { }

        virtual bool batalhar() = 0;

};

#endif
