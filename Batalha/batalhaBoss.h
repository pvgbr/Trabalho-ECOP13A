#ifndef BATALHABOSS_H
#define BATALHABOSS_H

#include "batalha.h"
#include "../Personagem/boss.h"

class BatalhaBoss : public Batalha {
private:
    Boss& boss;
    bool jogadorDefendendo;
public:
    BatalhaBoss(Jogador* player, Boss& boss);
    ~BatalhaBoss() {}
    bool batalhar() override;
};

#endif 