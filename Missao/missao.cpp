#include "missao.h"
#include <iostream>

Missao::Missao(int id, string titulo, string descricao, 
               vector<Inimigo> inimigos, int recompensaXP, int recompensaDinheiro)
    : id(id), titulo(titulo), descricao(descricao), inimigos(inimigos),
      inimigosDerrotados(0), concluida(false), recompensaXP(recompensaXP),
      recompensaDinheiro(recompensaDinheiro) {}

void Missao::iniciar() {
    system("cls");
    cout << "\n=== " << titulo << " ===\n";
    cout << descricao << "\n";
    if (id == 0) {
        cout << "\nPressione Enter para começar sua aventura...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore();
        return;
    }
    cout << "Inimigos a derrotar: " << inimigos.size() << "\n";
    cout << "Recompensas:\n";
    cout << "- XP: " << recompensaXP << "\n";
    cout << "- Dinheiro: " << recompensaDinheiro << "\n\n";
    cout << "Pressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore();
}

bool Missao::adicionarInimigoDerrotado() {
    if (id == 0) { // Missão de introdução
        concluida = true;
        return true;
    }
    inimigosDerrotados++;
    if (inimigosDerrotados >= inimigos.size()) {
        concluida = true;
        return true;
    }
    return false;
}

bool Missao::estaConcluida() const {
    if (id == 0) return concluida; // Missão 0 pode ser marcada manualmente
    return concluida;
}

string Missao::getTitulo() const {
    return titulo;
}

string Missao::getDescricao() const {
    return descricao;
}

int Missao::getRecompensaXP() const {
    return recompensaXP;
}

int Missao::getRecompensaDinheiro() const {
    return recompensaDinheiro;
}

void Missao::mostrarProgresso() const {
    cout << "\n=== Progresso da Missão ===\n";
    cout << "Título: " << titulo << "\n";
    cout << "Inimigos derrotados: " << inimigosDerrotados << "/" << inimigos.size() << "\n";
    if (concluida) {
        cout << "Status: Concluída!\n";
    } else {
        cout << "Status: Em andamento\n";
    }
    cout << "==========================\n\n";
}

vector<Inimigo>& Missao::getInimigos() {
    return inimigos;
} 