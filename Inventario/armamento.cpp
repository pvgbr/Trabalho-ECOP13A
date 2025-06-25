#include "armamento.h"
#include "../Personagem/jogador.h"

Armamento::Armamento(int id, string nome, TipoArmamento tipo, int bonusAtaque, int bonusDefesa, int durabilidade)
    : id(id), nome(nome), tipo(tipo), bonusAtaque(bonusAtaque), bonusDefesa(bonusDefesa), durabilidade(durabilidade), durabilidadeMaxima(durabilidade) {}

int Armamento::getId() const {
    return id;
}

string Armamento::getNome() const {
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

ostream& operator<<(ostream& os, const Armamento& a) {
    os << a.nome << " (";
    if (a.bonusAtaque > 0) {
        os << "ATK: " << a.bonusAtaque;
    }
    if (a.bonusDefesa > 0) {
        if (a.bonusAtaque > 0) os << ", ";
        os << "DEF: " << a.bonusDefesa;
    }
    if (a.getTipo() == TipoArmamento::ARMA || a.getTipo() == TipoArmamento::ESCUDO) {
         if (a.bonusAtaque > 0 || a.bonusDefesa > 0) os << ", ";
         os << "DUR: " << a.durabilidade << "/" << a.durabilidadeMaxima;
    }
    os << ")";
    return os;
}

bool Armamento::operator==(const Armamento& other) const {
    return this->id == other.id;
}