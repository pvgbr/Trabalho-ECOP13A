#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <iostream>

class Jogador; // Forward declaration

enum class TipoArmamento {
    INDETERMINADO,
    ARMA,
    ESCUDO
};

class Armamento {  
    
    protected:
        int id;
        std::string nome;
        TipoArmamento tipo;
        int bonusAtaque;
        int bonusDefesa;
        int durabilidade;
        int durabilidadeMaxima;
    
    public:
        Armamento(int id, std::string nome, TipoArmamento tipo, int bonusAtaque, int bonusDefesa, int durabilidade);
            
        // Métodos de acesso (Getters)
        int getId() const;
        std::string getNome() const;
        TipoArmamento getTipo() const;
        int getBonusAtaque() const;
        int getBonusDefesa() const;
        int getDurabilidade() const;
        int getDurabilidadeMaxima() const;

        // Modificadores
        void reduzirDurabilidade(int quantidade);

        // Operadores
        friend std::ostream& operator<<(std::ostream& os, const Armamento& a);
        bool operator==(const Armamento& other) const;
};

#endif