#include "menuLoja.h"
#include "../Loja/Loja.h" // Para usar a classe Loja
#include <iostream>
#include <string>     // Para std::to_string
#include <iomanip>    // Para std::setw, std::left
#include <limits>     // Para std::numeric_limits

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
            cout << "Entrada invalida. Por favor, digite um numero inteiro valido." << endl;
            escolha = -1; 
        } else {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        }

    } while (escolha != 0);
} 