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
    if(vida <= 0) vivo = false;
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

void Personagem::setDefesa(int d){
    defesa = d;
}

void Personagem::setVida(int v){
    vida = v;
}

void Personagem::setNivel(int n){
    nivel = n;
}

string Personagem::getNome() { return nome; }