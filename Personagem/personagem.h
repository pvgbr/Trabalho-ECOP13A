#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <bits/stdc++.h>
using namespace std;

class Personagem {

    protected:

        string nome;
        
        int nivel;
        int forca;
        int defesa;
        int vida;
        bool vivo;
        int dificuldade;
        
    public:

        Personagem() { }
        Personagem(string, int, int);
        ~Personagem() { }

        virtual void imprimir_dados() = 0;
        
        bool estaVivo();
        void alterarVida(int);
        void alterarForca(int);
        void alterarDefesa(int);

        void setNome(string);
        void setForca(int);
        void setDefesa(int);
        void setVida(int);
        void setNivel(int);
        void setDificuldade(int);

        int getForca();
        int getDefesa();
        int getVida();
        int getDificuldade();
        string getNome();

};

#endif