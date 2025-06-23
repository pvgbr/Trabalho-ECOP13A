#include "inimigo.h"
#include <bits/stdc++.h>

using namespace std;

Inimigo::Inimigo(string n, int f, int d, Dificuldade dif) : Personagem(n, f, d) {
    forca *= dif.getMInimigos();
    defesa *= dif.getMInimigos();
    recompensaDinheiro = 10;
    recompensaXP = 2;
    vivo = true;
} 

void Inimigo::imprimir_dados() {
    cout<<"----------------------------"<<endl;
    cout<<"Nome: "<< nome << endl;
    cout<<"Vida: "<< vida << endl;
    cout<<"Força: "<< forca << endl;
    cout<<"Defesa: "<< defesa << endl;
    cout<<"----------------------------"<<endl;
}

void Inimigo::setDific(Dificuldade d){
    dif = d;
}


void Inimigo::setRecompensaXP(int xp) {
    recompensaXP = xp;
}

void Inimigo::setRecompensaDinheiro(int dinheiro) {
    recompensaDinheiro = dinheiro;
}
