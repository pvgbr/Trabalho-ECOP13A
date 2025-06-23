#ifndef LOJA_H
#define LOJA_H

#include <bits/stdc++.h>
#include "../Personagem/jogador.h"
#include "../Inventario/armamento.h"
#include "../Inventario/consumiveis.h"

using namespace std;

// Classe de Loja
class Loja {
private:
    vector<Armamento> armamentos_disponiveis;
    vector<int> precos_armamentos;

    vector<Consumiveis> consumiveis_disponiveis;
    vector<int> precos_consumiveis;

public:
    Loja(); // Construtor

    void mostrarItens(const Jogador& jogador) const; // Função para mostrar itens disponiveis na loja
    
    bool comprarArmamento(Jogador& jogador, int indice_item); // Função para comprar armamento na loja
    bool comprarConsumivel(Jogador& jogador, int indice_item); // Função para comprar consumivel na loja

    int getNumeroDeArmamentos() const;
    int getNumeroDeConsumiveis() const;
};

#endif // LOJA_H
