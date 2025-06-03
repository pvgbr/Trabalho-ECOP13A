#include <bits/stdc++.h>
#include <unistd.h>
#include <cstdio>
#include "menuInicial.h"
#include "menuLoja.h"
#include "../Batalha/batalhaNormal.h"
#include "../Personagem/inimigo.h"
#include "../Utils/dificuldade.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <fstream>

// Declaração da função limparTela para que seja visível antes do uso
void limparTela();

using namespace std;

MenuIni::MenuIni(Jogador* p) : player{p} {
    ifstream teste("save.txt");
    if (!teste.good()) inicio();
    else menuPrinc();

    dif.setDificuldade(player->getDificuldade());

}  

void MenuIni::inicio() {
    cout << "Seja bem-vindo ao sdasdasddas" << endl;
    cout << "Vamos começar pelo nome do seu personagem: ";
    string n;
    getline(cin, n);
    string nome = n;
    cout << "Perfeito!" << endl << endl;
    map<int, string> m; m[1] = "Facil"; m[2] = "Medio"; m[3] = "Dificil";
    cout << "1- Facil\n2- Medio\n3- Dificil\nAgora selecione o nivel de dificuldade: ";
    int d_input;
    cin >> d_input;
    cout << "Dificuldade " << m[d_input] << " selecionada!" << endl;
    player->setDificuldade(d_input);
    dif.setDificuldade(d_input);
    cin.ignore();
    sleep(3);
    system("cls");

    player->setNome(nome);
    player->setNivel(1);
    player->setXP(0);
    player->setForca(1);
    player->setDefesa(1);
    player->setVida(100);
    player->setDinheiro(0);
    player->setFase(1);

    Fase fase(player);

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
    int op;
    bool sair = false;

    while (!sair) {
        limparTela();
        ifstream teste("save.txt");
        if (teste.good()) {
                    player->carregar("save.txt");
        }
        cout << "===== Menu Principal =====" << endl;
        player->imprimir_dados();
        cout << "------------------------" << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Salvar Jogo" << endl;
        cout << "3 - Carregar Jogo (feito automaticamente ao iniciar, mas pode ser opcao)" << endl;
        cout << "4 - Preferencias (Exemplo)" << endl;
        cout << "0 - Sair do Jogo" << endl;
        cout << "------------------------" << endl;
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
            case 1:
                menuPreparacaoFase();
                break;
            case 2:
                player->salvar("save.txt");
                cout << "Jogo salvo com sucesso!" << endl;
                cin.get();
                break;
            case 3:
            {
                if (teste.good()) {
                    player->carregar("save.txt");
                    cout << "Jogo carregado com sucesso!" << endl;
                }
                else {
                    cout << "Nenhum jogo salvo encontrado." << endl;
                }
                teste.close();
                cin.get();
                break;
            }
            case 4:
                cout << "Opcao de Preferencias ainda nao implementada." << endl;
                cin.get();
                break;
            case 0:
                cout << "Saindo do jogo... Obrigado por jogar!" << endl;
                player->salvar("save.txt");
                sair = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                cin.get();
                break;
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
                
                int forca_base_inimigo = 10;
                int defesa_base_inimigo = 5;
                int vida_base_inimigo = 30;
                int moedas_batalha = 25;

                float multiplicador_status = static_cast<float>(d.getMInimigos());
                if (multiplicador_status == 0) multiplicador_status = 1;

                Inimigo enemy("Goblin Assustador", forca_base_inimigo, defesa_base_inimigo, d);
                
                BatalhaNormal batalha(player, enemy); 
                batalha.batalhar();

                if(player->getVida() <= 0) {
                    cout << "Voce foi derrotado! Game Over." << endl;
                    cout << "Voltando ao menu principal..." << endl;
                    player->setVida(100);
                    cin.get();
                    voltarMenuPrincipal = true;
                } else {
                    player->alterarDinheiro(moedas_batalha);
                    player->setVida(100);
                    cout << "Voce ganhou " << moedas_batalha << " moedas!" << endl;
                    cout << "Batalha concluida! Pressione Enter para continuar..." << endl;
                    cin.get();
                }
                break;
            }
            case 2:
                interagirComLoja(*player);
                break;
            case 3:
                limparTela();
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