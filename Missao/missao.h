#ifndef MISSAO_H
#define MISSAO_H

#include "../Personagem/inimigo.h"
#include <string>
#include <vector>

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
    
    void iniciar();
    bool adicionarInimigoDerrotado();
    bool estaConcluida() const;
    string getTitulo() const;
    string getDescricao() const;
    int getRecompensaXP() const;
    int getRecompensaDinheiro() const;
    void mostrarProgresso() const;
    vector<Inimigo>& getInimigos();
    bool ehMissaoFinal() const { return id == 5; }
};

#endif 