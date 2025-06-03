#include "Loja.h" // Inclui o cabeçalho da classe Loja, que está no mesmo diretório
#include <iostream>
#include <iomanip> // Para std::setw e std::left
#include <string>  // Para std::to_string

using namespace std;

Loja::Loja() {
    // Adicionar itens de teste
    // Armamentos: (id, nome)
    armamentos_disponiveis.push_back(Armamento(101, "Espada Curta Velha"));
    precos_armamentos.push_back(50);
    armamentos_disponiveis.push_back(Armamento(102, "Escudo de Madeira Podre"));
    precos_armamentos.push_back(30);
    armamentos_disponiveis.push_back(Armamento(201, "Varinha de Graveto"));
    precos_armamentos.push_back(40);

    // Consumíveis: (id, nome) - IDs devem corresponder aos de Consumiveis::usarConsumivel
    consumiveis_disponiveis.push_back(Consumiveis(1, "Pocao de Vida Pequena"));
    precos_consumiveis.push_back(20);
    consumiveis_disponiveis.push_back(Consumiveis(2, "Pocao de Forca Fraca"));
    precos_consumiveis.push_back(30);
    consumiveis_disponiveis.push_back(Consumiveis(1, "Super Pocao de Vida"));
    precos_consumiveis.push_back(100);
}

void Loja::mostrarItens(const Jogador& jogador) const {
    cout << "\n--- Bem-vindo a Loja! ---" << endl;
    cout << "Voce tem " << jogador.getDinheiro() << " moedas." << endl;
    cout << "\n--- Armamentos ---" << endl;
    if (armamentos_disponiveis.empty()) {
        cout << "Nenhum armamento a venda no momento." << endl;
    } else {
        cout << left << setw(5) << "Num" << setw(30) << "Nome" << "Preco" << endl;
        cout << string(45, '-') << endl;
        for (size_t i = 0; i < armamentos_disponiveis.size(); ++i) {
            cout << left << setw(5) << to_string(i + 1) + "." 
                      << setw(30) << armamentos_disponiveis[i].getNome() 
                      << precos_armamentos[i] << " moedas" << endl;
        }
    }

    cout << "\n--- Consumiveis ---" << endl;
    if (consumiveis_disponiveis.empty()) {
        cout << "Nenhum consumivel a venda no momento." << endl;
    } else {
        cout << left << setw(5) << "Num" << setw(30) << "Nome" << "Preco" << endl;
        cout << string(45, '-') << endl;
        for (size_t i = 0; i < consumiveis_disponiveis.size(); ++i) {
            cout << left << setw(5) << to_string(i + 1 + armamentos_disponiveis.size()) + "." 
                      << setw(30) << consumiveis_disponiveis[i].getNome()
                      << precos_consumiveis[i] << " moedas" << endl;
        }
    }
    cout << "-------------------------" << endl;
    cout << "Digite o numero do item para comprar ou 0 para sair." << endl;
}

bool Loja::comprarArmamento(Jogador& jogador, int indice_loja) {
    int indice_real = indice_loja - 1;
    if (indice_real >= 0 && (size_t)indice_real < armamentos_disponiveis.size()) {
        const Armamento& item_para_comprar = armamentos_disponiveis[indice_real];
        int preco = precos_armamentos[indice_real];

        if (jogador.getDinheiro() >= preco) {
            jogador.alterarDinheiro(-preco); 
            jogador.adicionarArmamentoAoInventario(item_para_comprar);
            cout << "Voce comprou: " << item_para_comprar.getNome() << endl;
            return true;
        } else {
            cout << "Dinheiro insuficiente." << endl;
            return false;
        }
    } else {
        cout << "Selecao de armamento invalida." << endl;
        return false;
    }
}

bool Loja::comprarConsumivel(Jogador& jogador, int indice_loja) {
    int indice_real = indice_loja - 1 - armamentos_disponiveis.size(); 
    if (indice_real >= 0 && (size_t)indice_real < consumiveis_disponiveis.size()) {
        const Consumiveis& item_para_comprar = consumiveis_disponiveis[indice_real];
        int preco = precos_consumiveis[indice_real];

        if (jogador.getDinheiro() >= preco) {
            jogador.alterarDinheiro(-preco); 
            jogador.adicionarConsumivelAoInventario(item_para_comprar);
            cout << "Voce comprou: " << item_para_comprar.getNome() << endl;
            return true;
        } else {
            cout << "Dinheiro insuficiente." << endl;
            return false;
        }
    } else {
        cout << "Selecao de consumivel invalida." << endl;
        return false;
    }
}

size_t Loja::getNumeroDeArmamentos() const {
    return armamentos_disponiveis.size();
}

size_t Loja::getNumeroDeConsumiveis() const {
    return consumiveis_disponiveis.size();
}
