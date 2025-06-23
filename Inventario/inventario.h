#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <bits/stdc++.h>
#include "armamento.h"
#include "consumiveis.h"
using namespace std;

// Classe template de inventario
template <typename T>
class Inventario {
private:
    vector<T> itens;

public:

    void adicionarItem(const T& item); // Função para adicionar item ao inventario
    void mostrarItens() const; // Função para mostrar todos os itens do inventário
    int verificaItem(const T& item); // Função que retorna a quantidade do item buscado no inventario
    bool removerItem(const T& item); // Função para remover todos os itens do mesmo tipo do inventario
    void removerItemUnico(const T& item); // Função de remover apenas um item do tipo do inventario
    const vector<T>& getItens() const;
    vector<T>& getItens();
    void clear(); // Função para limpar o inventario

};

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

#endif