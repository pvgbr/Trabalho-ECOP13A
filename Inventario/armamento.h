#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <bits/stdc++.h>
#include "../Personagem/jogador.h"
using namespace std;

class Armamento {  
    
    protected:
    
        int id;
        string nome;
    
    public:
        
        Armamento(int, string)
            
        void equiparArma(Jogador*);
        void equiparArmadura(Jogador*);
        
};

#endif