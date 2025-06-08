#ifndef GERENCIADORMISSOES_H
#define GERENCIADORMISSOES_H

#include <vector>
#include "missao.h"
#include "../Personagem/jogador.h"

class GerenciadorMissoes {
private:
    std::vector<Missao> missoes;
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
    bool todasMissoesConcluidas() const;
};

#endif 