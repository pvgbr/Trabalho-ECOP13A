#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <bits/stdc++.h>
//#include "../Personagem/jogador.h"
using namespace std;

class Jogador;

class Armamento {  
    
    protected:
    
        int id;
        string nome;
    
    public:
        
        Armamento(int, string);
            
        void equiparArma(Jogador*);
        void equiparArmadura(Jogador*);

        // Operadores adicionados
        friend ostream& operator<<(ostream& os, const Armamento& a);
        bool operator==(const Armamento& other) const;

        // Getters adicionados
        int getId() const;
        string getNome() const;
        
};

#endif