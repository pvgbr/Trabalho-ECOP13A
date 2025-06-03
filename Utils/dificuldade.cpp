#include "dificuldade.h"
#include <bits/stdc++.h>

Dificuldade::Dificuldade(int dif) : dificuldade{dif} {
    switch(dificuldade) {
        case 1: //facil
            multInimigos = 1;
            multEventoAleatorio = 1;
            break;
        case 2: //medio
            multInimigos = 2; 
            multEventoAleatorio = 2;
            break;
        case 3: //dificil
            multInimigos = 3;
            multEventoAleatorio = 3;
            break;
    }   
}

void Dificuldade::setDificuldade(int dif) { dificuldade = dif; }

int Dificuldade::getMInimigos() { return multInimigos; }
int Dificuldade::getMEAleatorio() { return multEventoAleatorio; }
int Dificuldade::getDificuldade() { return dificuldade; }