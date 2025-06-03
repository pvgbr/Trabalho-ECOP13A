#ifndef JOGADOR_H
#define JOGADOR_H

#include <bits/stdc++.h>
#include "personagem.h"
#include "../Inventario/inventario.h"
#include "../Inventario/armamento.h"
#include "../Inventario/consumiveis.h"

using namespace std;

class Jogador : public Personagem {

    protected:

        int xp;
        int dinheiro;
        int fase;

        Inventario<Armamento> invArma;
        Inventario<Consumiveis> invConsumivel;
    
    public:

        Jogador() { }
        Jogador(string, int, int);
        ~Jogador() { }

        void imprimir_dados();
        
        void alterarDinheiro(int);
        void alterarXP(int);
        int getNivel();
        int getFase();
        int getDinheiro() const;
  
        void setDinheiro(int);
        void setXP(int);
        void setFase(int);

        bool verificaNivel();

        void salvar(string caminho);
        void carregar(string caminho);

        void mostrarConsumiveisBatalha() const;
        bool usarConsumivelBatalha(int indice);

        void adicionarArmamentoAoInventario(const Armamento& arma);
        void adicionarConsumivelAoInventario(const Consumiveis& consumivel);

        void mostrarInventariosCompletos() const;

};

#endif