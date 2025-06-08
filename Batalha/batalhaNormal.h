#ifndef BATALHA_NORMAL_H
#define BATALHA_NORMAL_H

#include "batalha.h"
#include "../Personagem/inimigo.h"

class BatalhaNormal : public Batalha {

    private:
        Inimigo& enemy;

    public:
        BatalhaNormal(Jogador* p, Inimigo& e);
        bool batalhar() override;
        void atacar(Personagem &atacante, Personagem &defensor, bool jogador);
        int escolhaBatalha();
        Jogador* getPlayer();
};

#endif