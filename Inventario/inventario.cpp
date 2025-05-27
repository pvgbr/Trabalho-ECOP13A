#include "inventario.h"

void Inventario::adicionarItem(const T& item) {
    itens.push_back(item);
}

void Inventario::mostrarItens() const {
    cout << "Itens no inventário: \n";
    for (const auto& item : itens) {
        cout << "- " << item << endl;
    }
}

int Inventario::verificaItem(const T& item) {
    int quant = itens.count(itens.begin(), itens.end(), item);
    return quant;
}

bool Inventario::removerItem(const T& item) {
    if(!verificaItem(item)) return false;
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if (*it == item) {
            itens.erase(it);
            break;
        }
    }
    return true;  
}