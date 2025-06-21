#include "menuLoja.h"
#include "../Loja/Loja.h"
#include <bits/stdc++.h>
#include <iomanip>
#include <limits>

using namespace std;

void interagirComLoja(Jogador& jogador) {
    Loja loja; // Cria a instância da loja
    int escolha = -1;

    do {
        loja.mostrarItens(jogador); // Mostra os itens e o dinheiro do jogador
        cout << "> ";
        cin >> escolha;
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
            cout << "Seleção inválida. Tente novamente." << endl;
        }
        
        if (escolha != 0) {
            cout << "Pressione Enter para continuar..." << endl;
            cin.ignore();
            system("cls");
        }

    } while(escolha != 0);
} 