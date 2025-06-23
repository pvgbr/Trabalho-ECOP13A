#ifndef DIFICULDADE_H
#define DIFICULDADE_H

#include <bits/stdc++.h>
#include "../Personagem/personagem.h"
using namespace std;

// Classe para definir dificuldade do jogo
class Dificuldade {

    protected:
    
        int dificuldade;
        
        int multInimigos;
        int multEventoAleatorio;
        
    public:
        Dificuldade() { }
        Dificuldade(int);
        ~Dificuldade() { }

        void setDificuldade(int); // Função para definir dificuldade do jogo
        
        int getDificuldade();

        // Multiplicadores de economia e dificuldade
        int getMInimigos();
        double getMultiplicadorRecompensa();
        double getMultiplicadorPreco();
        double getMultiplicadorDanoInimigo();

};

#endif