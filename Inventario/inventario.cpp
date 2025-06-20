#include "inventario.h"
#include "armamento.h"
#include "consumiveis.h"
#include <iostream>
#include <algorithm>

template <typename T>
void Inventario<T>::adicionarItem(const T& item) {
    itens.push_back(item);
}

template <typename T>
bool Inventario<T>::removerItem(const T& item) {
    auto it = find(itens.begin(), itens.end(), item);
    if (it != itens.end()) {
        itens.erase(it);
        return true;
    }
    return false;
}

template <typename T>
void Inventario<T>::removerItemUnico(const T& item) {
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if (&(*it) == &item) {
            itens.erase(it);
            return;
        }
    }
}

template <typename T>
const vector<T>& Inventario<T>::getItens() const {
    return itens;
}

template <typename T>
vector<T>& Inventario<T>::getItens() {
    return itens;
}

template <typename T>
void Inventario<T>::clear() {
    itens.clear();
}

template <typename T>
void Inventario<T>::mostrarItens() const {
    cout << "Itens no inventario: \n";
    for (const auto& item : itens) {
        cout << "- " << item << endl;
    }
}

template <typename T>
int Inventario<T>::verificaItem(const T& item) {
    return count(itens.begin(), itens.end(), item);
}

// Instanciação explícita para os tipos usados no projeto
template class Inventario<Armamento>;
template class Inventario<Consumiveis>; 