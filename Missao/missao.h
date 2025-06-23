#ifndef MISSAO_H
#define MISSAO_H

#include "../Personagem/inimigo.h"
#include <bits/stdc++.h>

// Classe de missao
class Missao {
private:
    int id;
    string titulo;
    string descricao;
    vector<Inimigo> inimigos;
    int inimigosDerrotados;
    bool concluida;
    int recompensaXP;
    int recompensaDinheiro;

public:
    Missao(int id, string titulo, string descricao, 
           vector<Inimigo> inimigos, int recompensaXP, int recompensaDinheiro);
    
    string getTitulo() const; 
    string getDescricao() const;
    int getRecompensaXP() const;
    int getRecompensaDinheiro() const;
    vector<Inimigo>& getInimigos();

    void iniciar(); // Função de iniciar missão
    bool adicionarInimigoDerrotado(); // Função que marca inimigo como derrotado
    bool estaConcluida() const; // Função que verifica que a missao foi concluida
    
    void mostrarProgresso() const; // Função para mostrar o progresso da missão
    
    bool ehMissaoFinal() const { return id == 5; } // Função que retorna se a missão é a final (boss)
};

#endif 