#ifndef MENULOJA_H
#define MENULOJA_H

// Forward declaration da classe Jogador para evitar include completo em header, se possível
// class Jogador; 
// No entanto, como Jogador é passado por referência e seus métodos são chamados,
// o include completo é geralmente mais prático aqui.
#include "../Personagem/jogador.h" 

// Declaração da função que vai gerenciar a interação com a loja
void interagirComLoja(Jogador& jogador);

#endif // MENULOJA_H 