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

// Classe de Jogador, que herda da classe Personagem
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

        void imprimir_dados(); // Função sobrescrita para imprimir dados do jogador
        
        void alterarDinheiro(int d);
        void alterarXP(int exp);
        int getNivel();
        int getFase();
        int getDinheiro() const;
  
        void setDinheiro(int d);
        void setXP(int exp);
        void setFase(int f);

        bool verificaNivel(); // Função que verifica se o jogador pode upar de nivel

        void limparInv(); // Função para limpar os inventarios do jogador

        void salvar(string caminho, int missaoAtual = -1); // Função para salvar as informações do jogo no arquivo
        void carregar(string caminho, int* missaoAtual = nullptr); // Função para carregar as informações do jogo do arquivo

        void equiparItem(int indiceNoInventario); // Função para equipar item do inventário
        void desequiparItem(TipoArmamento tipo); // Função para desequipar item do inventário

        void gerenciarPosBatalha(); // Função que gerencia o pos batalha, reduzindo durabilidades

        void mostrarConsumiveisBatalha() const; // Função que mostra os consumiveis disponiveis na batalha
        bool usarConsumivelBatalha(int indice); // Função para usar um consumível na batalha

        const Inventario<Consumiveis>& getInvConsumivel() const;

        void adicionarArmamentoAoInventario(const Armamento& arma); // Função para adicionar um armamento no inventário
        void adicionarConsumivelAoInventario(const Consumiveis& consumivel); // Função para adicionar um consumivel no inventário

        void mostrarInventariosCompletos() const; // Função para mostrar os dois inventario (arma e consumivel)

        int getBonusAtaqueEquipado() const;
        int getBonusDefesaEquipado() const;

        void gerenciarInventario(); // Função para gerenciar inventario (equipar e desequipar itens)

        pair<int, bool> usarHabilidade(HabilidadeJogador habilidade, Personagem* alvo = nullptr); // Função para usar habilidade, retorna um par: dano causado e se congelou o alvo

        // Gerenciamento de durabilidade
        void reduzirDurabilidadeEquipamentos(); // Função para reduzir durabilidade de equipamento

};

#endif