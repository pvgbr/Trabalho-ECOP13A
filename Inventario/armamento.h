#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <bits/stdc++.h>
using namespace std;

class Jogador; // Forward declaration

enum class TipoArmamento {
    INDETERMINADO,
    ARMA,
    ESCUDO
};

class Armamento {  
    
    protected:
        int id;
        string nome;
        TipoArmamento tipo;
        int bonusAtaque;
        int bonusDefesa;
        int durabilidade;
        int durabilidadeMaxima;
    
    public:
        Armamento(int id, string nome, TipoArmamento tipo, int bonusAtaque, int bonusDefesa, int durabilidade);
            
        // Métodos de acesso (Getters)
        int getId() const;
        string getNome() const;
        TipoArmamento getTipo() const;
        int getBonusAtaque() const;
        int getBonusDefesa() const;
        int getDurabilidade() const;
        int getDurabilidadeMaxima() const;

        // Modificadores
        void reduzirDurabilidade(int quantidade);

        // Operadores
        friend ostream& operator<<(ostream& os, const Armamento& a);
        bool operator==(const Armamento& other) const;
};

#endif