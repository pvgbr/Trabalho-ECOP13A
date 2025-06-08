#include "gerenciadorMissoes.h"
#include <iostream>

GerenciadorMissoes::GerenciadorMissoes(Jogador* jogador) : jogador(jogador), missaoAtual(0) {
    inicializarMissoes();
}

void GerenciadorMissoes::inicializarMissoes() {
    // Missão 1: O Início da Jornada
    std::vector<Inimigo> inimigosMissao1 = {
        Inimigo("Goblin Batedor", 3, 2, Dificuldade(1))
    };
    missoes.push_back(Missao(1, "O Início da Jornada", 
        "Uma pequena vila na fronteira do reino está sendo atacada por goblins. "
        "Como um aventureiro iniciante, você foi contratado para ajudar a proteger a vila. "
        "Derrote o goblin batedor que está causando problemas.",
        inimigosMissao1, 50, 100));

    // Missão 2: A Caverna dos Goblins
    std::vector<Inimigo> inimigosMissao2 = {
        Inimigo("Goblin Guerreiro", 4, 3, Dificuldade(1)),
        Inimigo("Goblin Xamã", 5, 2, Dificuldade(1))
    };
    missoes.push_back(Missao(2, "A Caverna dos Goblins",
        "Após derrotar o batedor, você descobriu que os goblins estão usando uma caverna próxima como base. "
        "Infiltre-se na caverna e elimine os líderes da tribo.",
        inimigosMissao2, 100, 200));

    // Missão 3: O Orc Renegado
    std::vector<Inimigo> inimigosMissao3 = {
        Inimigo("Orc Guerreiro", 6, 4, Dificuldade(2)),
        Inimigo("Orc Berserker", 7, 3, Dificuldade(2)),
        Inimigo("Orc Xamã", 5, 5, Dificuldade(2))
    };
    missoes.push_back(Missao(3, "O Orc Renegado",
        "Um poderoso orc renegado está liderando ataques contra as caravanas de comércio. "
        "Ele é conhecido por sua brutalidade e força. Enfrente seu exército e derrote-o.",
        inimigosMissao3, 200, 400));

    // Missão 4: A Fortaleza Negra
    std::vector<Inimigo> inimigosMissao4 = {
        Inimigo("Cavaleiro Negro", 8, 6, Dificuldade(3)),
        Inimigo("Arqueiro Sombrio", 7, 5, Dificuldade(3)),
        Inimigo("Mago das Sombras", 9, 4, Dificuldade(3)),
        Inimigo("Lorde das Trevas", 10, 8, Dificuldade(3))
    };
    missoes.push_back(Missao(4, "A Fortaleza Negra",
        "Uma antiga fortaleza foi tomada por servos das trevas. "
        "O lorde das trevas que a comanda está planejando um ataque ao reino. "
        "Infiltre-se na fortaleza e elimine a ameaça.",
        inimigosMissao4, 500, 1000));
}

void GerenciadorMissoes::mostrarMissoesDisponiveis() const {
    system("cls");
    std::cout << "\n=== Missões Disponíveis ===\n\n";
    for (size_t i = 0; i < missoes.size(); ++i) {
        std::cout << "Missão " << (i + 1) << ": " << missoes[i].getTitulo() << "\n";
        if (i == missaoAtual) {
            std::cout << "Status: Atual\n";
        } else if (i < missaoAtual) {
            std::cout << "Status: Concluída\n";
        } else {
            std::cout << "Status: Bloqueada\n";
        }
        std::cout << "------------------------\n";
    }
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void GerenciadorMissoes::iniciarMissaoAtual() {
    if (missaoAtual < missoes.size()) {
        missoes[missaoAtual].iniciar();
    }
}

bool GerenciadorMissoes::avancarMissao() {
    if (missaoAtual < missoes.size() && missoes[missaoAtual].estaConcluida()) {
        // Dar recompensas ao jogador
        jogador->alterarXP(missoes[missaoAtual].getRecompensaXP());
        jogador->alterarDinheiro(missoes[missaoAtual].getRecompensaDinheiro());
        
        // Avançar para próxima missão
        missaoAtual++;
        
        // Mostrar mensagem de conclusão
        system("cls");
        std::cout << "\n=== Missão Concluída! ===\n";
        std::cout << "Você recebeu:\n";
        std::cout << "- " << missoes[missaoAtual-1].getRecompensaXP() << " XP\n";
        std::cout << "- " << missoes[missaoAtual-1].getRecompensaDinheiro() << " moedas\n\n";
        
        if (missaoAtual < missoes.size()) {
            std::cout << "Nova missão disponível!\n";
        } else {
            std::cout << "Parabéns! Você completou todas as missões!\n";
        }
        
        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        
        return true;
    }
    return false;
}

void GerenciadorMissoes::mostrarProgressoAtual() const {
    if (missaoAtual < missoes.size()) {
        missoes[missaoAtual].mostrarProgresso();
    }
}

Missao* GerenciadorMissoes::getMissaoAtual() {
    if (missaoAtual < missoes.size()) {
        return &missoes[missaoAtual];
    }
    return nullptr;
}

bool GerenciadorMissoes::todasMissoesConcluidas() const {
    return missaoAtual >= missoes.size();
} 