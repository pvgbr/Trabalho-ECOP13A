#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <bits/stdc++.h>
using namespace std;

// Classe base de Personagem
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

        virtual void imprimir_dados() = 0; // Função virtual para imprimir dados de personagens
        
        bool estaVivo(); // Função que retorna se o personagem está vivo (vida > 0)
        void alterarVida(int); // Função para alterar vida de personagem
        void alterarForca(int); // Função para alterar força de personagem
        void alterarDefesa(int); // Função para alterar defesa de personagem

        void setNome(string);
        void setForca(int);
        void setDefesa(int);
        void setVida(int);
        void setNivel(int);
        void setDificuldade(int);

        int getForca();
        int getDefesa();
        int getVida();
        int getDificuldade() const;
        string getNome();

};

#endif