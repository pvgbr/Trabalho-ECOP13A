#include "armamento.h"
#include "../Personagem/jogador.h"

Armamento::Armamento(int idx, string n) {
    id = idx;
    nome = n;
}

// Implementação dos operadores
ostream& operator<<(ostream& os, const Armamento& a) {
    os << "Armamento: " << a.nome << " (ID: " << a.id << ")";
    return os;
}

bool Armamento::operator==(const Armamento& other) const {
    return this->id == other.id && this->nome == other.nome;
}

// Implementação dos getters
int Armamento::getId() const {
    return id;
}

string Armamento::getNome() const {
    return nome;
}

void Armamento::equiparArma(Jogador* player) {
        
} 

void Armamento::equiparArmadura(Jogador* player) {

}