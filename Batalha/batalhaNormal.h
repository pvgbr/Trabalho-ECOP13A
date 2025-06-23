#ifndef BATALHA_NORMAL_H
#define BATALHA_NORMAL_H

#include "batalha.h"
#include "../Personagem/inimigo.h"

//Classe de Batalha com inimigos normais, herdada da classe base Batalha
class BatalhaNormal : public Batalha {

    private:
        Inimigo& enemy;
        bool inimigoCongelado = false;
        bool usouGolpeDuplo = false;
        bool usouAtaqueGelo = false;
        void eventoAleatorioPosBatalha();

    public:
        BatalhaNormal(Jogador* p, Inimigo& e);
        bool batalhar() override; // Função sobrescrita para batalhar com os inimigos
        void atacar(Personagem &atacante, Personagem &defensor, bool jogador); // Função usada para efetuar um ataque
        int escolhaBatalha(); // Função para decidir a escolha entre atacar e usar consumivel ou habilidade
        Jogador* getPlayer();
};

#endif