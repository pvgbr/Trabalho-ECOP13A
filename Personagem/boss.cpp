#include "boss.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Boss::Boss(string nome, int forca, int defesa, string frase)
    : Personagem(nome, forca, defesa), fraseFinal(frase) {
    vida = 300;
    nivel = 10;
    dificuldade = 3;
}

void Boss::imprimir_dados() {
    cout << "===== BOSS FINAL =====" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Vida: " << vida << endl;
    cout << "Força: " << forca << endl;
    cout << "Defesa: " << defesa << endl;
    cout << "Frase Final: " << fraseFinal << endl;
    cout << "======================" << endl;
}

string Boss::getFraseFinal() const {
    return fraseFinal;
}

// Mecânica especial: ataque especial do boss
int Boss::ataqueEspecial() {
    // Dano: 1.5x força + bônus aleatório entre 0 e 10
    int bonus = rand() % 11;
    int dano = static_cast<int>(forca * 1.5) + bonus;
    cout << "O Boss usa seu ataque especial! Causa " << dano << " de dano!" << endl;
    return dano;
}

void Boss::usarHabilidade(HabilidadeBoss habilidade) {
    switch (habilidade) {
        case HabilidadeBoss::RAIO_ANIQUILADOR: {
            int dano = forca * 2 + (rand() % 21); // Dano massivo
            cout << "O Boss canaliza energia e dispara o RAIO ANIQUILADOR! Causa " << dano << " de dano devastador!" << endl;
            // Aqui você pode aplicar o dano ao jogador (exemplo: return dano;)
            break;
        }
        case HabilidadeBoss::REGENERACAO_DRAGONICA: {
            int cura = 50 + (rand() % 51); // Cura entre 50 e 100
            vida += cura;
            if (vida > 300) vida = 300; // Vida máxima
            cout << "O Boss ativa REGENERAÇÃO DRAGÔNICA e recupera " << cura << " de vida!" << endl;
            break;
        }
        default:
            cout << "O Boss tentou usar uma habilidade desconhecida!" << endl;
            break;
    }
}

// Nenhuma implementação adicional necessária, pois tudo está inline no header. 