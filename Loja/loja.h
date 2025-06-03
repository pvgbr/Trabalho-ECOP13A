#ifndef LOJA_H
#define LOJA_H

#include <vector>
#include <string>
// Os caminhos para Jogador, Armamento e Consumiveis são relativos à localização de Loja.h
// Se Loja.h está em Loja/, e Personagem/ e Inventario/ estão na raiz, então:
#include "../Personagem/jogador.h"
#include "../Inventario/armamento.h"
#include "../Inventario/consumiveis.h"

using namespace std;

class Loja {
private:
    vector<Armamento> armamentos_disponiveis;
    vector<int> precos_armamentos;

    vector<Consumiveis> consumiveis_disponiveis;
    vector<int> precos_consumiveis;

public:
    Loja(); // Construtor

    void mostrarItens(const Jogador& jogador) const;
    
    bool comprarArmamento(Jogador& jogador, int indice_item);
    bool comprarConsumivel(Jogador& jogador, int indice_item);

    size_t getNumeroDeArmamentos() const;
    size_t getNumeroDeConsumiveis() const;
};

#endif // LOJA_H
