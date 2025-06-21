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

class Boss : public Inimigo {
private:
    string fraseFinal;
public:
    Boss(string nome, int forca, int defesa, string frase);
    void imprimir_dados() override;
    string getFraseFinal() const;
    // Mecânica especial: ataque especial do boss
    int ataqueEspecial();
    // Sistema de habilidades
    void usarHabilidade(HabilidadeBoss habilidade);
};

#endif 