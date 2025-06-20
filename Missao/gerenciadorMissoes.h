#ifndef GERENCIADORMISSOES_H
#define GERENCIADORMISSOES_H

#include <vector>
#include "missao.h"
#include "../Personagem/jogador.h"

class GerenciadorMissoes {
private:
    vector<Missao> missoes;
    int missaoAtual;
    Jogador* jogador;

public:
    GerenciadorMissoes(Jogador* jogador);
    void inicializarMissoes();
    void mostrarMissoesDisponiveis() const;
    void iniciarMissaoAtual();
    bool avancarMissao();
    void mostrarProgressoAtual() const;
    Missao* getMissaoAtual();
    void setMissaoAtual(int idx);
    int getMissaoAtualIndex() const { return missaoAtual; }
    bool todasMissoesConcluidas() const;
};

#endif 