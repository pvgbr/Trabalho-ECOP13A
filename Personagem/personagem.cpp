#include "personagem.h"
#include <bits/stdc++.h>

using namespace std;

Personagem::Personagem(string n, int f, int d) : nome{n}, forca{f}, defesa{d} {
    vida = 100;
    nivel = 1;
    vivo = true;
} 

bool Personagem::estaVivo() { return vivo; }

void Personagem::alterarVida(int v) {
    vida += v;
    if(vida <= 0) {vivo = false; vida = 0;}
    else vivo = true;
}

void Personagem::alterarForca(int f) {
    forca += f;
}

void Personagem::alterarDefesa(int d) {
    defesa += d;
}

void Personagem::setNome(string n){
    nome = n;
}

void Personagem::setForca(int f){
    forca = f;
}

void Personagem::setDificuldade(int d){
    dificuldade = d;
}

void Personagem::setVida(int v){
    vida = v;
    if(vida <= 0) {vivo = false; vida = 0;}
    else vivo = true;
}

void Personagem::setNivel(int n){
    nivel = n;
}

void Personagem::setDefesa(int d){
    defesa = d;
}

string Personagem::getNome() { return nome; }

int Personagem::getForca(){ return forca; }

int Personagem::getDefesa(){ return defesa; }

int Personagem::getVida(){ return vida; }

int Personagem::getDificuldade(){ return dificuldade; }