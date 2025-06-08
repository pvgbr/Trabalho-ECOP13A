#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>

template <typename T>
class Inventario {
private:
    std::vector<T> itens;

public:
    void adicionarItem(const T& item);
    void mostrarItens() const;
    int verificaItem(const T& item);
    bool removerItem(const T& item);
    void removerItemUnico(const T& item);
    const std::vector<T>& getItens() const;
    std::vector<T>& getItens();
    void clear();
};

#endif