#include <bits/stdc++.h>
#include <unistd.h>
#include <cstdio>
#include "menuInicial.h"
#include "menuLoja.h"
#include "../Batalha/batalhaNormal.h"
#include "../Personagem/inimigo.h"
#include "../Utils/dificuldade.h"
#include "../Missao/gerenciadorMissoes.h"
#include "../Missao/missao.h"
#include "../Inventario/consumiveis.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <fstream>

// Declaração da função limparTela para que seja visível antes do uso
void limparTela();

using namespace std;

MenuIni::MenuIni(Jogador* p) : player{p} {
    ifstream teste("save.txt");
    if (!teste.good()) {
        inicio();
    } else {
        player->carregar("save.txt");
        dif.setDificuldade(player->getDificuldade());
        menuPrinc();
    }
}  

void MenuIni::inicio() {
    system("cls");
    cout << "=== Bem-vindo ao RPG de Batalha ===\n\n";
    cout << "Vamos começar criando seu personagem!\n\n";
    
    // Nome do personagem
    cout << "Digite o nome do seu personagem: ";
    string nome;
    getline(cin, nome);
    cout << "Perfeito! Seu personagem se chamará " << nome << "!\n\n";
    cin.ignore();
    // Dificuldade
    map<int, string> m; 
    m[1] = "Fácil"; 
    m[2] = "Médio"; 
    m[3] = "Difícil";
    
    int d_input;
    do {
        cout << "Selecione o nível de dificuldade:\n";
        cout << "1 - Fácil\n";
        cout << "2 - Médio\n";
        cout << "3 - Difícil\n";
        cout << "Sua escolha: ";
        cin >> d_input;
        
        if (d_input < 1 || d_input > 3) {
            cout << "\nOpção inválida! Por favor, escolha entre 1 e 3.\n\n";
        }
    } while (d_input < 1 || d_input > 3);
    
    cout << "\nDificuldade " << m[d_input] << " selecionada!\n";
    player->setDificuldade(d_input);
    dif.setDificuldade(d_input);
    
    // Configuração inicial do personagem
    player->setNome(nome);
    player->setNivel(1);
    player->setXP(0);
    player->setForca(5);
    player->setDefesa(3);
    player->setVida(100);
    player->setDinheiro(100);
    player->setFase(1);
    
    // Inicializa o gerenciador de missões
    GerenciadorMissoes gerenciadorMissoes(player);
    
    cout << "\nSeu personagem foi criado com sucesso!\n";
    cout << "Você começa com:\n";
    cout << "- 100 de vida\n";
    cout << "- 5 de força\n";
    cout << "- 3 de defesa\n";
    cout << "- 100 moedas\n\n";
    cout << "Pressione Enter para continuar...";
    cin.get();
    
    system("cls");
    menuPrinc();
}

void MenuIni::mostra_menu(){
    player->imprimir_dados();
    cout << "1- Jogar" << endl;
    cout << "2- Preferencias" << endl;
    cout << "3- Reset" << endl;
    cout << "4- Sair e salvar" << endl; 
}

void MenuIni::preferencias() {
    cout << "Menu de preferencias: " << endl;
    cout << "1- Selecionar dificuldade" << endl;
    cout << "2- Alterar nome do personagem" << endl;
    cout << "3- Voltar" << endl;
    cout << "Escolha um opcao para continuar: ";
    int e; cin >> e;
    switch(e) {
        case 1: {
            map<int, string> m; m[1] = "Facil"; m[2] = "Medio"; m[3] = "Dificil";
            cout << "Agora selecione o nivel de dificuldade: \n1- Facil\n2- Medio\n3- Dificil" << endl;
            int d_input; cin >> d_input;
            dif.setDificuldade(d_input);
            player->setDificuldade(d_input);
            cout << "Dificuldade " << m[d_input] << " selecionada!" << endl;
            sleep(2);
            system("cls");
            preferencias();
            break;
        }
        case 2: {
            cout << "Entre com o novo nome do seu personagem: ";
            cin.ignore();
            string n = player->getNome(), n1; getline(cin, n1);
            cout << "Seu nome foi alterado! (" << n << " -> " << n1 <<")" << endl;
            player->setNome(n1);
            sleep(2);
            system("cls");
            preferencias();
            break;
        }
        default:
            system("cls");
            break;
    }

}

void MenuIni::reset() {
    cout << "Seu jogo foi resetado!" << endl;
    cout << "Entre com o nome do seu personagem: ";
    cin.ignore();
    string n; getline(cin, n);
    player->setNome(n);
    player->setFase(1);
    player->setXP(0);
    player->setNivel(1);
    player->setForca(1);
    player->setDefesa(1);
    player->setDificuldade(1);
    dif.setDificuldade(1);
    player->setVida(100);
    player->setDinheiro(0);
    player->salvar("save.txt");
    cout << endl << "Seu jogo foi resetado com sucesso, abra novamente!" << endl;
    sleep(2);
    exit(0);
}

void MenuIni::menuPrinc() {
    GerenciadorMissoes gerenciadorMissoes(player);
    int escolha = -1;
    
    while (escolha != 0) {
        system("cls");
        player->imprimir_dados();
        cout << "\n=== Menu Principal ===\n";
        cout << "1 - Iniciar Missão Atual\n";
        cout << "2 - Ver Missões Disponíveis\n";
        cout << "3 - Ver Progresso da Missão\n";
        cout << "4 - Loja\n";
        cout << "5 - Inventário\n";
        cout << "6 - Salvar Jogo\n";
        cout << "7 - Carregar Jogo\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        
        cin >> escolha;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida!" << endl;
            continue;
        }

        switch (escolha) {
            case 1:
                if (!gerenciadorMissoes.todasMissoesConcluidas()) {
                    gerenciadorMissoes.iniciarMissaoAtual();
                    Missao* missaoAtual = gerenciadorMissoes.getMissaoAtual();
                    if (missaoAtual) {
                        for (auto& inimigo : missaoAtual->getInimigos()) {
                            BatalhaNormal batalha(player, inimigo);
                            if (batalha.batalhar()) {
                                if (missaoAtual->adicionarInimigoDerrotado()) {
                                    gerenciadorMissoes.avancarMissao();
                                }
                            } else {
                                cout << "\nVocê foi derrotado! Voltando ao menu principal...\n";
                                cout << "Pressione Enter para continuar...";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }
                        }
                    }
                } else {
                    cout << "\nTodas as missões foram concluídas!\n";
                    cout << "Pressione Enter para continuar...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                }
                break;
            case 2:
                gerenciadorMissoes.mostrarMissoesDisponiveis();
                break;
            case 3:
                gerenciadorMissoes.mostrarProgressoAtual();
                cout << "Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            case 4:
                limparTela();
                interagirComLoja(*player);
                break;
            case 5:
                player->gerenciarInventario();
                break;
            case 6:
                player->salvar("save.txt");
                cout << "\nJogo salvo com sucesso!\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            case 7:
                player->carregar("save.txt");
                cout << "\nJogo carregado com sucesso!\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            case 0:
                cout << "\nSaindo do jogo...\n";
                break;
            default:
                cout << "\nOpção inválida!\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
        }
    }
}

void MenuIni::menuPreparacaoFase() {
    int op;
    bool voltarMenuPrincipal = false;

    while (!voltarMenuPrincipal) {
        limparTela();
        cout << "===== Preparacao da Fase =====" << endl;
        player->imprimir_dados();
        cout << "----------------------------" << endl;
        cout << "1 - Iniciar Proxima Fase/Batalha" << endl;
        cout << "2 - Ir para Loja" << endl;
        cout << "3 - Ver Inventario" << endl;
        cout << "0 - Voltar ao Menu Principal" << endl;
        cout << "----------------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcao invalida. Tente novamente." << endl;
            cin.get();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (op) {
            case 1: {
                limparTela();
                cout << "Iniciando proxima fase/batalha..." << endl;
                
                Dificuldade d(player->getDificuldade());
                
                int forca_base_inimigo = 3;
                int defesa_base_inimigo = 2;
                int vida_base_inimigo = 40;
                
                Inimigo enemy("Goblin Assustador", forca_base_inimigo, defesa_base_inimigo, d);
                enemy.setVida(vida_base_inimigo);
                
                BatalhaNormal batalha(player, enemy); 
                bool vitoria = batalha.batalhar();

                if (vitoria) {
                    cout << "Voce venceu a batalha!" << endl;
                    player->alterarDinheiro(enemy.get_recompensaDinheiro());
                    player->alterarXP(enemy.get_recompensaXP());
                    player->gerenciarPosBatalha();
                    player->setVida(100); 
                    player->salvar("save.txt");
                    cout << "Pressione Enter para continuar..." << endl;
                    cin.get();
                } else {
                    cout << "Voce foi derrotado! Game Over." << endl;
                    cout << "Voltando ao menu principal..." << endl;
                    player->setVida(100);
                    player->salvar("save.txt");
                    cin.get();
                    voltarMenuPrincipal = true;
                }
                break;
            }
            case 2:
                interagirComLoja(*player);
                player->salvar("save.txt");
                break;
            case 3:
                limparTela();
                cout << "Exibindo seu inventario..." << endl;
                player->mostrarInventariosCompletos();
                cout << "\nPressione Enter para voltar..." << endl;
                cin.get();
                break;
            case 0:
                voltarMenuPrincipal = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                cin.get();
                break;
        }
    }
}

Jogador* MenuIni::getPlayer() { return player; }

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}