#ifndef JOGADOR_H
#define JOGADOR_H

#include <bits/stdc++.h>
#include "personagem.h"
using namespace std;

class Jogador : public Personagem {

    protected:

        int xp;
        int dinheiro;
        int fase;
    
        
    public:

        Jogador() { }
        Jogador(string, int, int);
        ~Jogador() { }

        void imprimir_dados();
        
        void alterarDinheiro(int);
        void alterarXP(int);
        int getNivel();
        int getFase();
  
        void setDinheiro(int);
        void setXP(int);
        void setFase(int);

        bool verificaNivel();

        void salvar(string caminho);
        void carregar(string caminho);


        

};

#endif