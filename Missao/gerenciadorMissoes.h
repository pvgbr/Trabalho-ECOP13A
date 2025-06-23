#ifndef GERENCIADORMISSOES_H
#define GERENCIADORMISSOES_H

#include <vector>
#include "missao.h"
#include "../Personagem/jogador.h"

// Classe de gerenciamento das missoes
class GerenciadorMissoes {
private:
    vector<Missao> missoes;
    int missaoAtual;
    Jogador* jogador;

public:
    GerenciadorMissoes(Jogador* jogador);

    Missao* getMissaoAtual(); 
    void setMissaoAtual(int idx);
    int getMissaoAtualIndex() const { return missaoAtual; }

    void inicializarMissoes(); // Função para inicialização das missões
    void mostrarMissoesDisponiveis() const; // Função para imprimir as missões disponíveis
    void iniciarMissaoAtual(); // Função para iniciar a missao atual
    bool avancarMissao(); // Função que verifica se o jogador pode avançar a missão
    void mostrarProgressoAtual() const; // Função que imprime o progresso atual do jogador
    
    bool todasMissoesConcluidas() const; // Função que retorna se todas as missões foram concluidas
};

#endif 