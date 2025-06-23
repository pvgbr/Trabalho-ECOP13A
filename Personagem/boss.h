#ifndef BOSS_H
#define BOSS_H

#include "inimigo.h"
#include <string>
#include <iostream>

// Enum para habilidades do Boss
enum class HabilidadeBoss {
    RAIO_ANIQUILADOR = 1,
    REGENERACAO_DRAGONICA = 2
};

// Classe do inimigo final (Boss), que herda da classe Inimigo
class Boss : public Inimigo {
private:
    string fraseFinal;
public:
    Boss(string nome, int forca, int defesa, string frase);
    
    string getFraseFinal() const;
    
    void imprimir_dados() override; // Função sobrescrita para imprir dados do boss
    int ataqueEspecial(); // Função para o boss usar o seu ataque especial
    void usarHabilidade(HabilidadeBoss habilidade); // Função para o boss usar sua habilidade
};

#endif 