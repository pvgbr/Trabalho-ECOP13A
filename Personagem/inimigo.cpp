#include "inimigo.h"
#include <bits/stdc++.h>

using namespace std;

Inimigo::Inimigo(string n, int f, int d, Dificuldade dif) : Personagem(n, f, d) {
    forca *= dif.getMInimigos();
    defesa *= dif.getMInimigos();
    recompensaDinheiro = nivel*50*dif.getMInimigos();
    recompensaXP = nivel* 10 *dif.getMInimigos(); 
} 

void Inimigo::imprimir_dados(){
    cout<<"----------------------------"<<endl;
    cout<<"Nome: "<< nome << endl;
    cout<<"Vida: "<< vida << endl;
    cout<<"Forca: "<< forca << endl;
    cout<<"Defesa: "<< defesa << endl;
    cout<<"----------------------------"<<endl;
}
