#ifndef JOGADOR_H
#define JOGADOR_H

#include <bits/stdc++.h>
#include "personagem.h"
#include "../Inventario/inventario.h"
#include "../Inventario/armamento.h"
#include "../Inventario/consumiveis.h"
#include <string>

using namespace std;

class Jogador : public Personagem {

    private:

        int xp;
        int dinheiro;
        int fase;

        Inventario<Armamento> invArma;
        Inventario<Consumiveis> invConsumivel;
    
        Armamento* armaEquipada;
        Armamento* escudoEquipado;
        Armamento armaPadrao;
        Armamento escudoPadrao;

    public:

        Jogador(string n = "", int f = 1, int d = 1);
        ~Jogador() { }

        void imprimir_dados();
        
        void alterarDinheiro(int d);
        void alterarXP(int exp);
        int getNivel();
        int getFase();
        int getDinheiro() const;
  
        void setDinheiro(int d);
        void setXP(int exp);
        void setFase(int f);

        bool verificaNivel();

        void salvar(string caminho);
        void carregar(string caminho);

        void equiparItem(int indiceNoInventario);
        void desequiparItem(TipoArmamento tipo);

        void gerenciarPosBatalha();

        void mostrarConsumiveisBatalha() const;
        bool usarConsumivelBatalha(int indice);

        const Inventario<Consumiveis>& getInvConsumivel() const;

        void adicionarArmamentoAoInventario(const Armamento& arma);
        void adicionarConsumivelAoInventario(const Consumiveis& consumivel);

        void mostrarInventariosCompletos() const;

        int getBonusAtaqueEquipado() const;
        int getBonusDefesaEquipado() const;

        void gerenciarInventario();

};

#endif