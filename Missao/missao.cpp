#include "missao.h"
#include <iostream>

Missao::Missao(int id, std::string titulo, std::string descricao, 
               std::vector<Inimigo> inimigos, int recompensaXP, int recompensaDinheiro)
    : id(id), titulo(titulo), descricao(descricao), inimigos(inimigos),
      inimigosDerrotados(0), concluida(false), recompensaXP(recompensaXP),
      recompensaDinheiro(recompensaDinheiro) {}

void Missao::iniciar() {
    system("cls");
    std::cout << "\n=== " << titulo << " ===\n";
    std::cout << descricao << "\n\n";
    std::cout << "Inimigos a derrotar: " << inimigos.size() << "\n";
    std::cout << "Recompensas:\n";
    std::cout << "- XP: " << recompensaXP << "\n";
    std::cout << "- Dinheiro: " << recompensaDinheiro << "\n\n";
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

bool Missao::adicionarInimigoDerrotado() {
    inimigosDerrotados++;
    if (inimigosDerrotados >= inimigos.size()) {
        concluida = true;
        return true;
    }
    return false;
}

bool Missao::estaConcluida() const {
    return concluida;
}

std::string Missao::getTitulo() const {
    return titulo;
}

std::string Missao::getDescricao() const {
    return descricao;
}

int Missao::getRecompensaXP() const {
    return recompensaXP;
}

int Missao::getRecompensaDinheiro() const {
    return recompensaDinheiro;
}

void Missao::mostrarProgresso() const {
    std::cout << "\n=== Progresso da Missão ===\n";
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Inimigos derrotados: " << inimigosDerrotados << "/" << inimigos.size() << "\n";
    if (concluida) {
        std::cout << "Status: Concluída!\n";
    } else {
        std::cout << "Status: Em andamento\n";
    }
    std::cout << "==========================\n\n";
}

std::vector<Inimigo>& Missao::getInimigos() {
    return inimigos;
} 