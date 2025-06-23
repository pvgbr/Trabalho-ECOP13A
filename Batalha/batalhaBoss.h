#ifndef BATALHABOSS_H
#define BATALHABOSS_H

#include "batalha.h"
#include "../Personagem/boss.h"

//Classe de Batalha com o inimigo final, herdada da classe base Batalha
class BatalhaBoss : public Batalha {
private:
    Boss& boss;
    bool jogadorDefendendo;
public:
    BatalhaBoss(Jogador* player, Boss& boss);
    ~BatalhaBoss() {}
    bool batalhar() override; // Função sobrescrita para batalhar com o boss
};

#endif 