#ifndef CONSUMIVEIS_H
#define CONSUMIVEIS_H

#include <bits/stdc++.h>
#include "../Personagem/jogador.h"
using namespace std;

class Consumiveis {

    private:

        int id;
        string nome;
    
    public:

        Consumiveis(int, string);
        ~Consumiveis() { }

        void usarConsumivel(Jogador*);

};

#endif