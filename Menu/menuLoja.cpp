#include "menuLoja.h"
#include "../Loja/Loja.h" // Para usar a classe Loja
#include <iostream>
#include <string>     // Para to_string
#include <iomanip>    // Para setw, left
#include <limits>     // Para numeric_limits

using namespace std;

void interagirComLoja(Jogador& jogador) {
    Loja loja; // Cria a instância da loja (itens são carregados no construtor da Loja)
    int escolha = -1;

    do {
        loja.mostrarItens(jogador); // Mostra os itens e o dinheiro do jogador
        cout << "> ";
        cin >> escolha;

        if (cin.fail() || cin.peek() != '\n') { 
            cin.clear(); 
            cin.ignore(); // Descarta entrada inválida
            cout << "Entrada invalida. Por favor, digite um numero inteiro valido." << endl;
            escolha = -1; 
        } else {

            cin.ignore();

            if (escolha == 0) {
                cout << "Saindo da loja..." << endl;
                break;
            }

            if (escolha > 0 && (size_t)escolha <= loja.getNumeroDeArmamentos()) {
                loja.comprarArmamento(jogador, escolha);
            } else if ((size_t)escolha > loja.getNumeroDeArmamentos() && (size_t)escolha <= loja.getNumeroDeArmamentos() + loja.getNumeroDeConsumiveis()) {
                loja.comprarConsumivel(jogador, escolha);
            } else {
                cout << "Selecao invalida. Tente novamente." << endl;
            }
        }
        
        if (escolha != 0) { // Só pausa se não for sair
            cout << "Pressione Enter para continuar..." << endl;
            cin.get(); // Espera pelo Enter
            system("cls");
        }

    } while (escolha != 0);
} 