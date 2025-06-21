#include "inimigo.h"
#include <bits/stdc++.h>

using namespace std;

Inimigo::Inimigo(string n, int f, int d, Dificuldade dif) : Personagem(n, f, d) {
    forca *= dif.getMInimigos();
    defesa *= dif.getMInimigos();
    set_recompensas();
    vivo = true;
} 


void Inimigo::set_recompensas(){
    recompensaDinheiro = 10;
    recompensaXP = 2;
}

void Inimigo::imprimir_dados() {
    cout<<"----------------------------"<<endl;
    cout<<"Nome: "<< nome << endl;
    cout<<"Vida: "<< vida << endl;
    cout<<"Força: "<< forca << endl;
    cout<<"Defesa: "<< defesa << endl;
    cout<<"----------------------------"<<endl;
}

int Inimigo::get_recompensaXP() {
    return recompensaXP;
}

void Inimigo::setDific(Dificuldade d){
    dif = d;
}

int Inimigo::get_recompensaDinheiro() {
    return recompensaDinheiro;
}

void Inimigo::setRecompensaXP(int xp) {
    recompensaXP = xp;
}

void Inimigo::setRecompensaDinheiro(int dinheiro) {
    recompensaDinheiro = dinheiro;
}
