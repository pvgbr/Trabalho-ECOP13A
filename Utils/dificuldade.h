#ifndef DIFICULDADE_H
#define DIFICULDADE_H

#include <bits/stdc++.h>
#include "../Personagem/personagem.h"
using namespace std;

class Dificuldade {

    protected:
    
        int dificuldade;
        
        int multInimigos;
        int multEventoAleatorio;
        
    public:
        Dificuldade() { }
        Dificuldade(int);
        ~Dificuldade() { }

        void setDificuldade(int);
        
        int getMInimigos();
        int getMEAleatorio();
        int getDificuldade();

};

#endif