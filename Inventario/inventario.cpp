#include "inventario.h"
#include "armamento.h"    // Incluir para a instanciação explícita de Armamento
#include "consumiveis.h"  // Incluir para a instanciação explícita de Consumiveis
#include <iostream>        // Para std::cout, std::endl
#include <algorithm>       // Para std::count, std::find
// #include <vector> // Já incluído via inventario.h, que agora inclui <vector> explicitamente

using namespace std;

// NOTA: Todas as implementações dos métodos template da classe Inventario
// foram movidas para o arquivo de cabeçalho (Inventario/inventario.h).
// Isso é necessário para que o compilador possa instanciar corretamente
// os templates para tipos específicos (ex: Inventario<Armamento>)
// e para resolver erros de linkagem "undefined reference".
// Manter implementações de template em arquivos .cpp separados geralmente
// leva a esses problemas, a menos que se use exportação explícita de template,
// o que é menos comum e mais complexo.

template <typename T>
void Inventario<T>::adicionarItem(const T& item) {
    itens.push_back(item);
}

template <typename T>
void Inventario<T>::mostrarItens() const {
    cout << "Itens no inventario: \n";
    for (const auto& item : itens) {
        // ATENÇÃO: Requer que o tipo T tenha o operador 'operator<<'
        // sobrecarregado para funcionar corretamente com std::ostream (std::cout).
        cout << "- " << item << endl;
    }
}

template <typename T>
int Inventario<T>::verificaItem(const T& item) { 
    // ATENÇÃO: Requer que o tipo T tenha 'operator==' definido.
    return count(itens.begin(), itens.end(), item);
}

template <typename T>
bool Inventario<T>::removerItem(const T& item) {
    // ATENÇÃO: Requer que o tipo T tenha 'operator==' definido.
    auto it = find(itens.begin(), itens.end(), item);
    if (it != itens.end()) {
        itens.erase(it);
        return true;
    }
    return false;  
}

// A declaração em inventario.h é: const std::vector<T>& getItens() const;
// A definição deve corresponder exatamente.
template <typename T>
const vector<T>& Inventario<T>::getItens() const {
    return itens;
}

template <typename T>
void Inventario<T>::clear() {
    itens.clear();
}

// Para resolver problemas de linkagem "undefined reference" com templates definidos em .cpp,
// adicione instanciações explícitas aqui para cada tipo que usará Inventario.
// Exemplo:
// template class Inventario<Armamento>;
// template class Inventario<Consumiveis>;

// Instanciações explícitas para os tipos usados no projeto
template class Inventario<Armamento>;
template class Inventario<Consumiveis>;