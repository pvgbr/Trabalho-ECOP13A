#include "jogador.h"
#include <bits/stdc++.h>

using namespace std;

Jogador::Jogador(string n, int f, int d) : Personagem(n, f, d) {
    fase = 1;
    xp = 0;
    dinheiro = 0;
} 

void Jogador::imprimir_dados(){
    cout<<"---------------------------------"<<endl;
    cout<<"Nome: "<< nome <<"   Nivel: "<<nivel<<" ("<<xp<<"/"<< nivel*100 <<") "<<endl;
    cout<<"Vida: "<< vida <<endl;
    cout<<"Forca: "<< forca <<endl;
    cout<<"Defesa: "<< defesa <<endl;
    cout<<"Dinheiro: "<< dinheiro <<endl;
    cout<<"Dificuldade: "<< dificuldade <<endl;
    cout<<"---------------------------------"<<endl;
}

bool Jogador::verificaNivel() {
    if(xp / 100 >= nivel) {
        nivel++;
        xp -= nivel*100;
        return true;
    }
    return false;
}

void Jogador::alterarDinheiro(int d) {
    dinheiro += d;
}

void Jogador::alterarXP(int exp) {
    xp += exp;
}

int Jogador::getNivel(){
    return nivel;
}

int Jogador::getFase(){
    return fase;
}


void Jogador::setDinheiro(int d){
    dinheiro = d;
}

void Jogador::setFase(int f) {
    fase = f;
}

void Jogador::setXP(int exp){
    xp = exp;
}

void Jogador::salvar(string caminho) {
    ofstream arq(caminho);
    if (arq.is_open()) {
        arq << nome << '\n';
        arq << forca << '\n';
        arq << defesa << '\n';
        arq << vida << '\n';
        arq << nivel << '\n';
        arq << xp << '\n';
        arq << dinheiro << '\n';
        arq << fase << '\n';
        arq << dificuldade << '\n';
        arq.close();
    }
}


void Jogador::carregar(string caminho) {
    ifstream arq(caminho);
    if (arq.is_open()) {
        getline(arq, nome);
        arq >> forca;
        arq >> defesa;
        arq >> vida;
        arq >> nivel;
        arq >> xp;
        arq >> dinheiro;
        arq >> fase;
        arq >> dificuldade;
        arq.ignore();
        arq.close();
    }
}
