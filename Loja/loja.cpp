#include "Loja.h"
#include <bits/stdc++.h>
#include <iomanip>
#include "../Utils/dificuldade.h"

using namespace std;

Loja::Loja() {
    // Armamentos: (id, nome, tipo, bonusAtaque, bonusDefesa, durabilidade)
    armamentos_disponiveis.push_back(Armamento(101, "Espada Curta", TipoArmamento::ARMA, 5, 0, 10));
    precos_armamentos.push_back(50);
    armamentos_disponiveis.push_back(Armamento(102, "Espada Longa", TipoArmamento::ARMA, 10, 0, 20));
    precos_armamentos.push_back(120);
    armamentos_disponiveis.push_back(Armamento(104, "Lança Longa", TipoArmamento::ARMA, 8, 2, 30));
    precos_armamentos.push_back(150);
    armamentos_disponiveis.push_back(Armamento(103, "Machado Pesado", TipoArmamento::ARMA, 15, 0, 40));
    precos_armamentos.push_back(200);
    armamentos_disponiveis.push_back(Armamento(103, "Espada de Titânio", TipoArmamento::ARMA, 18, 0, 100));
    precos_armamentos.push_back(600);

    // Escudos: (id, nome, tipo, bonusAtaque, bonusDefesa, durabilidade) - durabilidade -1 para infinito
    armamentos_disponiveis.push_back(Armamento(201, "Escudo de Madeira", TipoArmamento::ESCUDO, 0, 5, 10));
    precos_armamentos.push_back(40);
    armamentos_disponiveis.push_back(Armamento(202, "Escudo de Ferro", TipoArmamento::ESCUDO, 0, 10, 25));
    precos_armamentos.push_back(100);
    armamentos_disponiveis.push_back(Armamento(203, "Escudo de Titânio", TipoArmamento::ESCUDO, 0, 20, 50));
    precos_armamentos.push_back(300);

    // Consumíveis: (id, nome) - ID correspondente ao da classe Consumivel
    consumiveis_disponiveis.push_back(Consumiveis(1, "Poção de Vida Pequena"));
    precos_consumiveis.push_back(50);
    consumiveis_disponiveis.push_back(Consumiveis(2, "Pocao de Força"));
    precos_consumiveis.push_back(150);
    consumiveis_disponiveis.push_back(Consumiveis(1, "Super Poção de Vida"));
    precos_consumiveis.push_back(100);
}

void Loja::mostrarItens(const Jogador& jogador) const {
    Dificuldade dif(jogador.getDificuldade());
    double multPreco = dif.getMultiplicadorPreco();
    cout << "\n--- Bem-vindo a Loja! ---" << endl;
    cout << "Você tem " << jogador.getDinheiro() << " moedas." << endl;
    cout << "\n--- Armamentos ---" << endl;
    cout << left << setw(5) << "Num" << setw(30) << "Nome" << "Preco" << endl;
    cout << string(45, '-') << endl;
    for (size_t i = 0; i < armamentos_disponiveis.size(); ++i) {
        int preco = static_cast<int>(precos_armamentos[i] * multPreco);
        cout << left << setw(5) << to_string(i + 1) + "." 
                    << setw(30) << armamentos_disponiveis[i].getNome() 
                    << preco << " moedas" << endl;
    }

    cout << "\n--- Consumiveis ---" << endl;
    cout << left << setw(5) << "Num" << setw(30) << "Nome" << "Preco" << endl;
    cout << string(45, '-') << endl;
    for (size_t i = 0; i < consumiveis_disponiveis.size(); ++i) {
        int preco = static_cast<int>(precos_consumiveis[i] * multPreco);
        cout << left << setw(5) << to_string(i + 1 + armamentos_disponiveis.size()) + "." 
                    << setw(30) << consumiveis_disponiveis[i].getNome() 
                    << preco << " moedas" << endl;
    }

    cout << "-------------------------" << endl;
    cout << "Digite o numero do item para comprar ou 0 para sair." << endl;
}

bool Loja::comprarArmamento(Jogador& jogador, int indice_loja) {
    Dificuldade dif(jogador.getDificuldade());
    double multPreco = dif.getMultiplicadorPreco();
    int indice_real = indice_loja - 1;
    if (indice_real >= 0 && (size_t)indice_real < armamentos_disponiveis.size()) {
        const Armamento& item_para_comprar = armamentos_disponiveis[indice_real];
        int preco = static_cast<int>(precos_armamentos[indice_real] * multPreco);

        if (jogador.getDinheiro() >= preco) {
            jogador.alterarDinheiro(-preco); 
            jogador.adicionarArmamentoAoInventario(item_para_comprar);
            cout << "Você comprou: " << item_para_comprar.getNome() << endl;
            return true;
        } else {
            cout << "Dinheiro insuficiente." << endl;
            return false;
        }
    } else {
        cout << "Seleção de armamento invalida." << endl;
        return false;
    }
}

bool Loja::comprarConsumivel(Jogador& jogador, int indice_loja) {
    Dificuldade dif(jogador.getDificuldade());
    double multPreco = dif.getMultiplicadorPreco();
    int indice_real = indice_loja - 1 - armamentos_disponiveis.size(); 
    if (indice_real >= 0 && (size_t)indice_real < consumiveis_disponiveis.size()) {
        const Consumiveis& item_para_comprar = consumiveis_disponiveis[indice_real];
        int preco = static_cast<int>(precos_consumiveis[indice_real] * multPreco);

        if (jogador.getDinheiro() >= preco) {
            jogador.alterarDinheiro(-preco); 
            jogador.adicionarConsumivelAoInventario(item_para_comprar);
            cout << "Você comprou: " << item_para_comprar.getNome() << endl;
            return true;
        } else {
            cout << "Dinheiro insuficiente." << endl;
            return false;
        }
    } else {
        cout << "Seleção de consumivel invalida." << endl;
        return false;
    }
}

size_t Loja::getNumeroDeArmamentos() const {
    return armamentos_disponiveis.size();
}

size_t Loja::getNumeroDeConsumiveis() const {
    return consumiveis_disponiveis.size();
}
