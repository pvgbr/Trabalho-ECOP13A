#ifndef MISSAO_H
#define MISSAO_H

#include <string>
#include <vector>
#include "../Personagem/inimigo.h"

class Missao {
private:
    int id;
    std::string titulo;
    std::string descricao;
    std::vector<Inimigo> inimigos;
    int inimigosDerrotados;
    bool concluida;
    int recompensaXP;
    int recompensaDinheiro;

public:
    Missao(int id, std::string titulo, std::string descricao, 
           std::vector<Inimigo> inimigos, int recompensaXP, int recompensaDinheiro);
    
    void iniciar();
    bool adicionarInimigoDerrotado();
    bool estaConcluida() const;
    std::string getTitulo() const;
    std::string getDescricao() const;
    int getRecompensaXP() const;
    int getRecompensaDinheiro() const;
    void mostrarProgresso() const;
    std::vector<Inimigo>& getInimigos();
};

#endif 