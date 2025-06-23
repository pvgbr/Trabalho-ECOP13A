#ifndef INIMIGO_H
#define INIMIGO_H

#include <bits/stdc++.h>
#include "personagem.h"
#include "jogador.h"
#include "../Utils/dificuldade.h"

using namespace std;

// Classe de Inimigos, que herda da classe Personagem
class Inimigo : public Personagem {

    protected:
        int recompensaXP;
        int recompensaDinheiro;

        Dificuldade dif;
        
    public:
        Inimigo() { }
        Inimigo(string, int, int, Dificuldade);
        ~Inimigo() { }

        void imprimir_dados(); // Função sobrescrita para imprimir dados do inimigo
        
        void setDific(Dificuldade);
        void setRecompensaXP(int xp);
        void setRecompensaDinheiro(int dinheiro);
};

#endif