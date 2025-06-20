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

using namespace std;

MenuIni::MenuIni(Jogador* p, int missaoAtual) : player{p}, missaoAtual{missaoAtual} {
    ifstream teste("save.txt");
    if (!teste.good()) {
        inicio();
    } else {
        player->carregar("save.txt", &this->missaoAtual);
        dif.setDificuldade(player->getDificuldade());
        menuPrinc();
    }
}  

void MenuIni::inicio() {
    cout << "Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    system("cls");
    cout << "Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "Você é um jovem habitante de uma vila simples, mas com um coração inquieto e sede de aventura. Numa noite tempestuosa, um velho mago bate à sua porta, trazendo uma mensagem urgente:\n";
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    system("cls");
    cout << "Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "Você é um jovem habitante de uma vila simples, mas com um coração inquieto e sede de aventura. Numa noite tempestuosa, um velho mago bate à sua porta, trazendo uma mensagem urgente:\n";
    cout << "— 'O mal retorna, jovem. O destino do reino está em suas mãos. Reúna coragem, prepare-se e escreva seu nome entre os heróis de Eldoria. Sua jornada começa agora...'\n";
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    system("cls");
    cout << "Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "Você é um jovem habitante de uma vila simples, mas com um coração inquieto e sede de aventura. Numa noite tempestuosa, um velho mago bate à sua porta, trazendo uma mensagem urgente:\n";
    cout << "— 'O mal retorna, jovem. O destino do reino está em suas mãos. Reúna coragem, prepare-se e escreva seu nome entre os heróis de Eldoria. Sua jornada começa agora...'\n";
    cout << "Com o coração acelerado, você sente que está prestes a viver a maior aventura de sua vida.\n";
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    cout << "\n\n=== Bem-vindo ao RPG de Batalha ===\n\n";
    cout << "Vamos começar criando seu personagem!\n";
    // Nome do personagem
    string nome;
    while (true) {
        try {
            cout << "Digite o nome do seu personagem: ";
            getline(cin, nome);
            if (nome.length() > 30) {
                throw length_error("O nome deve ter no máximo 30 caracteres!");
            }
            break;
        } catch (const length_error& e) {
            cout << "Erro: " << e.what() << endl;
        }
    }
    cout << "Perfeito! Seu personagem se chamará " << nome << "!\n\n";
    // Dificuldade
    map<int, string> m; 
    m[1] = "Fácil"; 
    m[2] = "Médio"; 
    m[3] = "Difícil";
    
    int dific;
    do {
        cout << "Selecione o nível de dificuldade:\n";
        cout << "1 - Fácil\n";
        cout << "2 - Médio\n";
        cout << "3 - Difícil\n";
        cout << "Sua escolha: ";
        cin >> dific;
        
        if (dific < 1 || dific > 3) {
            cout << "\nOpção inválida! Por favor, escolha entre 1 e 3.\n\n";
        }
    } while (dific < 1 || dific > 3);
    
    cout << "Dificuldade " << m[dific] << " selecionada!\n";
    player->setDificuldade(dific);
    dif.setDificuldade(dific);
    
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
    cin.ignore();
    cout << "\nSeu personagem foi criado com sucesso!\n\n";
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
            int dific; cin >> dific;
            dif.setDificuldade(dific);
            player->setDificuldade(dific);
            cout << "Dificuldade " << m[dific] << " selecionada!" << endl;
            sleep(2);
            system("cls");
            preferencias();
            break;
        }
        case 2: {
            string n = player->getNome(), n1;
            cin.ignore();
            while (true) {
                try {
                    cout << "Entre com o novo nome do seu personagem: ";
                    getline(cin, n1);
                    if (n1.length() > 30) {
                        throw length_error("O nome deve ter no máximo 30 caracteres!");
                    }
                    break;
                } catch (const length_error& e) {
                    cout << "Erro: " << e.what() << endl;
                }
            }
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
    string n;
    cin.ignore();
    while (true) {
        try {
            cout << "Entre com o nome do seu personagem: ";
            getline(cin, n);
            if (n.length() > 30) {
                throw length_error("O nome deve ter no máximo 30 caracteres!");
            }
            break;
        } catch (const length_error& e) {
            cout << "Erro: " << e.what() << endl;
        }
    }
    player->setNome(n);
    player->setFase(0);
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
    gerenciadorMissoes.setMissaoAtual(missaoAtual);
    int escolha = -1;
    
    while (escolha != 0) {
        system("cls");
        if(!player->getVida()) player->setVida(100);
        player->imprimir_dados();
        cout << "\n=== Menu Principal ===\n";
        cout << "1 - Iniciar Missão Atual\n";
        cout << "2 - Ver Missões Disponíveis\n";
        cout << "3 - Ver Progresso da Missão\n";
        cout << "4 - Loja\n";
        cout << "5 - Inventário\n";
        cout << "6 - Salvar Jogo\n";
        cout << "7 - Carregar Jogo\n";
        cout << "8 - Resetar Jogo\n";
        cout << "9 - Preferências\n";
        cout << "0 - Sair e salvar\n";
        cout << "Escolha uma opção: ";
        
        cin >> escolha;

        switch (escolha) {
            case 1:
                if (!gerenciadorMissoes.todasMissoesConcluidas()) {
                    gerenciadorMissoes.iniciarMissaoAtual();
                    Missao* missaoAtual = gerenciadorMissoes.getMissaoAtual();
                    if (missaoAtual) {
                        if (missaoAtual->getInimigos().empty()) {
                            // Missão narrativa, avança automaticamente
                            missaoAtual->adicionarInimigoDerrotado();
                            gerenciadorMissoes.avancarMissao();
                            player->setFase(player->getFase() + 1);
                        } else {
                            for (auto& inimigo : missaoAtual->getInimigos()) {
                                BatalhaNormal batalha(player, inimigo);
                                if (batalha.batalhar()) {
                                    if (missaoAtual->adicionarInimigoDerrotado()) {
                                        gerenciadorMissoes.avancarMissao();
                                        if (missaoAtual->ehMissaoFinal()) {
                                            system("cls");
                                            cout << "\n==============================\n";
                                            cout << "Parabéns! Você derrotou o Boss Final e salvou o reino!\n";
                                            cout << "O Dragão Ancião ruge pela última vez: \"Você nunca derrotará as trevas!\"\n";
                                            cout << "\nFIM DE JOGO\n";
                                            cout << "==============================\n";
                                            cout << "\nPressione Enter para sair...";
                                            cin.ignore();
                                            cin.get();
                                            exit(0);
                                        }
                                    }
                                } else {
                                    cout << "\nVocê foi derrotado! Voltando ao menu principal...\n";
                                    cout << "Você recebeu:\n";
                                    cout << "- " << missaoAtual->getRecompensaXP() / 10 << " XP\n";
                                    cout << "- " << missaoAtual->getRecompensaDinheiro() / 5 << " moedas\n\n";
                                    cout << "Pressione Enter para continuar...";
                                    cin.ignore();
                                    cin.get();
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    cout << "\nTodas as missões foram concluídas!\n";
                    cout << "Pressione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 2:
                gerenciadorMissoes.mostrarMissoesDisponiveis();
                break;
            case 3:
                gerenciadorMissoes.mostrarProgressoAtual();
                cout << "Pressione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                system("cls");
                interagirComLoja(*player);
                break;
            case 5:
                player->gerenciarInventario();
                break;
            case 6:
                player->salvar("save.txt", gerenciadorMissoes.getMissaoAtualIndex());
                cout << "\nJogo salvo com sucesso!\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 7:
                player->carregar("save.txt");
                cout << "\nJogo carregado com sucesso!\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 8:
                system("cls");
                reset();
                break;
            case 9:
                system("cls");
                preferencias();
                break;
            case 0:
                player->salvar("save.txt", gerenciadorMissoes.getMissaoAtualIndex());
                cout << "\nSalvando e saindo do jogo...\n";
                exit(0);
                break;
            default:
                cout << "\nOpção inválida!\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore();
                cin.get();
        }
    }
}

void MenuIni::menuPreparacaoFase() {
    int op;
    bool voltarMenuPrincipal = false;

    while (!voltarMenuPrincipal) {
        system("cls");
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
            cin.ignore();
            cout << "Opcao invalida. Tente novamente." << endl;
            cin.get();
            continue;
        }
        cin.ignore();

        switch (op) {
            case 1: {
                system("cls");
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
                system("cls");
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