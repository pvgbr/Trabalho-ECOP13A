#include "armamento.h"
#include "../Personagem/jogador.h"

Armamento::Armamento(int id, std::string nome, TipoArmamento tipo, int bonusAtaque, int bonusDefesa, int durabilidade)
    : id(id), nome(nome), tipo(tipo), bonusAtaque(bonusAtaque), bonusDefesa(bonusDefesa), durabilidade(durabilidade), durabilidadeMaxima(durabilidade) {}

// Implementação dos getters
int Armamento::getId() const {
    return id;
}

std::string Armamento::getNome() const {
    return nome;
}

TipoArmamento Armamento::getTipo() const {
    return tipo;
}

int Armamento::getBonusAtaque() const {
    return bonusAtaque;
}

int Armamento::getBonusDefesa() const {
    return bonusDefesa;
}

int Armamento::getDurabilidade() const {
    return durabilidade;
}

int Armamento::getDurabilidadeMaxima() const {
    return durabilidadeMaxima;
}

void Armamento::reduzirDurabilidade(int quantidade) {
    durabilidade -= quantidade;
    if (durabilidade < 0) {
        durabilidade = 0;
    }
}

// Implementação dos operadores
std::ostream& operator<<(std::ostream& os, const Armamento& a) {
    os << a.nome << " (";
    if (a.bonusAtaque > 0) {
        os << "ATK: " << a.bonusAtaque;
    }
    if (a.bonusDefesa > 0) {
        if (a.bonusAtaque > 0) os << ", ";
        os << "DEF: " << a.bonusDefesa;
    }
    if (a.getTipo() == TipoArmamento::ARMA) {
         if (a.bonusAtaque > 0 || a.bonusDefesa > 0) os << ", ";
         os << "DUR: " << a.durabilidade << "/" << a.durabilidadeMaxima;
    }
    os << ")";
    return os;
}

bool Armamento::operator==(const Armamento& other) const {
    return this->id == other.id;
}