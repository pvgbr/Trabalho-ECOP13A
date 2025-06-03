#include "jogador.h"
#include <bits/stdc++.h>

using namespace std;

Jogador::Jogador(string n, int f, int d) : Personagem(n, f, d) {
    fase = 1;
    xp = 0;
    dinheiro = 0;
} 

void Jogador::imprimir_dados(){
    cout<<"---------------------------------"<<endl;
    cout<<"Nome: "<< nome <<"   Nivel: "<<nivel<<" ("<<xp<<"/"<< nivel*100 <<") "<<endl;
    cout<<"Vida: "<< vida <<endl;
    cout<<"Forca: "<< forca <<endl;
    cout<<"Defesa: "<< defesa <<endl;
    cout<<"Dinheiro: "<< dinheiro <<endl;
    cout<<"Dificuldade: "<< dificuldade <<endl;
    cout<<"---------------------------------"<<endl;
}

bool Jogador::verificaNivel() {
    if(xp / 100 >= nivel) {
        nivel++;
        xp -= nivel*100;
        return true;
    }
    return false;
}

void Jogador::alterarDinheiro(int d) {
    dinheiro += d;
}

void Jogador::alterarXP(int exp) {
    xp += exp;
}

int Jogador::getNivel(){
    return nivel;
}

int Jogador::getFase(){
    return fase;
}

int Jogador::getDinheiro() const {
    return dinheiro;
}

void Jogador::setDinheiro(int d){
    dinheiro = d;
}

void Jogador::setFase(int f) {
    fase = f;
}

void Jogador::setXP(int exp){
    xp = exp;
}

void Jogador::salvar(string caminho) {
    ofstream arq(caminho);
    if (arq.is_open()) {
        arq << nome << '\n';
        arq << forca << '\n';
        arq << defesa << '\n';
        arq << vida << '\n';
        arq << nivel << '\n';
        arq << xp << '\n';
        arq << dinheiro << '\n';
        arq << fase << '\n';
        arq << dificuldade << '\n';

        arq << invArma.getItens().size() << '\n';
        for (const auto& arma : invArma.getItens()) {
            arq << arma.getId() << '\n';
            arq << arma.getNome() << '\n';
        }

        arq << invConsumivel.getItens().size() << '\n';
        for (const auto& consumivel : invConsumivel.getItens()) {
            arq << consumivel.getId() << '\n';
            arq << consumivel.getNome() << '\n';
        }

        arq.close();
    }
}


void Jogador::carregar(string caminho) {
    ifstream arq(caminho);
    if (arq.is_open()) {
        getline(arq, nome);
        arq >> forca;
        arq >> defesa;
        arq >> vida;
        arq >> nivel;
        arq >> xp;
        arq >> dinheiro;
        arq >> fase;
        arq >> dificuldade;
        arq.ignore(); 

        invArma.clear();
        invConsumivel.clear();

        int numArmas;
        arq >> numArmas;
        arq.ignore(); 
        for (int i = 0; i < numArmas; ++i) {
            int id;
            string nomeItem;
            arq >> id;
            arq.ignore(); 
            getline(arq, nomeItem);
            invArma.adicionarItem(Armamento(id, nomeItem));
        }

        int numConsumiveis;
        arq >> numConsumiveis;
        arq.ignore(); 
        for (int i = 0; i < numConsumiveis; ++i) {
            int id;
            string nomeItem;
            arq >> id;
            arq.ignore(); 
            getline(arq, nomeItem);
            invConsumivel.adicionarItem(Consumiveis(id, nomeItem));
        }

        arq.close();
    }
}

void Jogador::mostrarConsumiveisBatalha() const {
    cout << "\n--- Consumiveis Disponiveis ---" << endl;
    const auto& consumiveis = invConsumivel.getItens();
    if (consumiveis.empty()) {
        cout << "Nenhum consumivel no inventario." << endl;
    } else {
        for (size_t i = 0; i < consumiveis.size(); ++i) {
            cout << i + 1 << ". " << consumiveis[i] << endl; 
        }
    }
    cout << "-----------------------------" << endl;
}

bool Jogador::usarConsumivelBatalha(int indice) {
    int indiceReal = indice - 1;
    const auto& consumiveis = invConsumivel.getItens();

    if (indiceReal >= 0 && (size_t)indiceReal < consumiveis.size()) {
        Consumiveis itemParaUsar = consumiveis[indiceReal];
        invConsumivel.removerItem(itemParaUsar); 
        itemParaUsar.usarConsumivel(this);
        cout << "Voce usou: " << itemParaUsar.getNome() << endl;
        return true;
    } else {
        cout << "Indice de consumivel invalido." << endl;
        return false;
    }
}

void Jogador::adicionarArmamentoAoInventario(const Armamento& arma) {
    invArma.adicionarItem(arma);
}

void Jogador::adicionarConsumivelAoInventario(const Consumiveis& consumivel) {
    invConsumivel.adicionarItem(consumivel);
}

void Jogador::mostrarInventariosCompletos() const {
    cout << "\n--- Inventario de Armamentos ---" << endl;
    invArma.mostrarItens(); 
    cout << "-------------------------------" << endl;

    cout << "\n--- Inventario de Consumiveis ---" << endl;
    invConsumivel.mostrarItens(); 
    cout << "--------------------------------" << endl;
}
