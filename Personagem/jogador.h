#ifndef JOGADOR_H
#define JOGADOR_H

#include <bits/stdc++.h>
#include "personagem.h"
#include "../Inventario/inventario.h"
#include "../Inventario/armamento.h"
#include "../Inventario/consumiveis.h"

using namespace std;

// Enum para habilidades do Jogador
enum class HabilidadeJogador {
    GOLPE_DUPLO = 1,
    ATAQUE_GELO = 2
};

class Jogador : public Personagem {

    private:

        int xp;
        int dinheiro;
        int fase;

        int missaoAtual;

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

        void salvar(string caminho, int missaoAtual = -1);
        void carregar(string caminho, int* missaoAtual = nullptr);

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

        // Sistema de habilidades
        // O método retorna um par: dano causado e se congelou o alvo (bool)
        pair<int, bool> usarHabilidade(HabilidadeJogador habilidade, Personagem* alvo = nullptr);

};

#endif