#ifndef JOGADOR_H
#define JOGADOR_H

#include <bits/stdc++.h>
#include "personagem.h"
using namespace std;

class Jogador : public Personagem {

    protected:

        int xp;
        int dinheiro;
        
    public:

        Jogador() { }
        Jogador(string, int, int);
        ~Jogador() { }

        void imprimir_dados();
        
        void alterarDinheiro(int);
        void alterarXp(int);
        int getNivel();
        void setDinheiro(int);

        bool verificaNivel();

        void salvar(string caminho);
        void carregar(string caminho);


        

};

#endif