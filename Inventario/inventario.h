#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
using namespace std;

template <typename T>
class Inventario {
private:
    vector<T> itens;

public:
    void adicionarItem(const T& item);
    void mostrarItens() const;
    int verificaItem(const T& item);
    bool removerItem(const T& item);
    const vector<T>& getItens() const;
    void clear();
};

#endif