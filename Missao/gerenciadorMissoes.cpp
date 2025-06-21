#include "gerenciadorMissoes.h"
#include <iostream>
#include "../Personagem/boss.h"

GerenciadorMissoes::GerenciadorMissoes(Jogador* jogador) : jogador(jogador), missaoAtual(0) {
    inicializarMissoes();
}

void GerenciadorMissoes::inicializarMissoes() {

    // Missão 1: O Início da Jornada
    vector<Inimigo> inimigosMissao1 = {
        Inimigo("Goblin Batedor", 3, 2, Dificuldade(1))
    };
    missoes.push_back(Missao(1, "O Início da Jornada",
        "A vila de Greenfield, onde você cresceu, está sob ataque de criaturas que surgem das florestas. Um goblin batedor foi visto espreitando as casas e espalhando o medo entre os moradores.\n\n"
        "Seu primeiro desafio é proteger sua casa e provar seu valor enfrentando o goblin que ameaça a paz da vila.",
        inimigosMissao1, 50, 100));

    // Missão 2: A Caverna dos Goblins
    vector<Inimigo> inimigosMissao2 = {
        Inimigo("Goblin Guerreiro", 4, 3, Dificuldade(1)),
        Inimigo("Goblin Xamã", 5, 2, Dificuldade(1))
    };
    missoes.push_back(Missao(2, "A Caverna dos Goblins",
        "Após derrotar o batedor, você descobre que os goblins estão se organizando em uma caverna próxima. Eles planejam um ataque maior à vila.\n\n"
        "Corajosamente, você decide invadir a caverna, enfrentar os líderes goblins e impedir que o mal se espalhe ainda mais.",
        inimigosMissao2, 100, 200));

    // Missão 3: O Orc Renegado
    vector<Inimigo> inimigosMissao3 = {
        Inimigo("Orc Guerreiro", 6, 4, Dificuldade(2)),
        Inimigo("Orc Berserker", 7, 3, Dificuldade(2)),
        Inimigo("Orc Xamã", 5, 5, Dificuldade(2))
    };
    missoes.push_back(Missao(3, "O Orc Renegado",
        "Com a ameaça dos goblins contida, rumores falam de um orc renegado que lidera ataques brutais contra caravanas e viajantes. Ele é temido por sua força e crueldade.\n\n"
        "Sua missão é encontrar o esconderijo do orc, derrotar seus seguidores e acabar com o reinado de terror que assola as estradas do reino.",
        inimigosMissao3, 200, 400));

    // Missão 4: A Fortaleza Negra
    vector<Inimigo> inimigosMissao4 = {
        Inimigo("Cavaleiro Negro", 8, 6, Dificuldade(3)),
        Inimigo("Arqueiro Sombrio", 7, 5, Dificuldade(3)),
        Inimigo("Mago das Sombras", 9, 4, Dificuldade(3)),
        Inimigo("Lorde das Trevas", 10, 8, Dificuldade(3))
    };
    missoes.push_back(Missao(4, "A Fortaleza Negra",
        "Uma antiga fortaleza, há muito esquecida, foi tomada por servos das trevas. O Lorde das Trevas, um ser envolto em mistério, prepara um ritual que pode mergulhar Eldoria em escuridão eterna.\n\n"
        "Você deve se infiltrar na fortaleza, enfrentar guerreiros sombrios e impedir que o ritual seja concluído.",
        inimigosMissao4, 500, 1000));

    // Missão 5: O Despertar do Dragão
    vector<Inimigo> inimigosMissao5 = { Boss("Dragão Ancião", 15, 10, "Você nunca derrotará as trevas!") };
    missoes.push_back(Missao(5, "O Despertar do Dragão",
        "Quando tudo parecia resolvido, o verdadeiro mal desperta: o lendário Dragão Ancião, criatura de poder inimaginável, ergue-se das profundezas para destruir tudo o que resta de esperança.\n\n"
        "Apenas um herói de coragem inabalável pode enfrentar o dragão e salvar Eldoria do fim. Esta é a batalha final. O destino do reino está em suas mãos!",
        inimigosMissao5, 2000, 5000));
}

void GerenciadorMissoes::mostrarMissoesDisponiveis() const {
    system("cls");
    cout << "\n=== Missões Disponíveis ===\n\n";
    for (int i = 0; i < missoes.size(); ++i) {
        cout << "Missão " << (i + 1) << ": " << missoes[i].getTitulo() << "\n";
        if (i == missaoAtual) {
            cout << "Status: Atual\n";
        } else if (i < missaoAtual) {
            cout << "Status: Concluída\n";
        } else {
            cout << "Status: Bloqueada\n";
        }
        cout << "------------------------\n";
    }
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    cin.ignore();
}

void GerenciadorMissoes::iniciarMissaoAtual() {
    if (missaoAtual < missoes.size()) {
        missoes[missaoAtual].iniciar();
    }
}

bool GerenciadorMissoes::avancarMissao() {
    if (missaoAtual < missoes.size() && missoes[missaoAtual].estaConcluida()) {
        // Dar recompensas ao jogador
        double mult = jogador->getDificuldade() == 1 ? 1.0 : (jogador->getDificuldade() == 2 ? 0.7 : 0.5);
        int xp = static_cast<int>(missoes[missaoAtual].getRecompensaXP() * mult);
        int dinheiro = static_cast<int>(missoes[missaoAtual].getRecompensaDinheiro() * mult);
        jogador->alterarXP(xp);
        jogador->alterarDinheiro(dinheiro);
        
        // Avançar para próxima missão
        missaoAtual++;
        
        // Mostrar mensagem de conclusão
        system("cls");
        cout << "\n=== Missão Concluída! ===\n";
        cout << "Você recebeu:\n";
        cout << "- " << xp << " XP\n";
        cout << "- " << dinheiro << " moedas\n\n";
        
        if (missaoAtual < missoes.size()) {
            cout << "Nova missão disponível!\n";
        } else {
            cout << "Parabéns! Você completou todas as missões!\n";
        }
        
        cout << "\nPressione Enter para continuar...";
        cin.ignore();
        cin.ignore();
        
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

void GerenciadorMissoes::setMissaoAtual(int idx) {
    missaoAtual = idx;
    for (int i = 0; i < (int)missoes.size(); ++i) {
        if (i < idx) {
            while (!missoes[i].estaConcluida()) missoes[i].adicionarInimigoDerrotado();
        } else {
            break;
        }
    }
} 