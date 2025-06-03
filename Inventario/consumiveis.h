#ifndef CONSUMIVEIS_H
#define CONSUMIVEIS_H

#include <bits/stdc++.h>
//#include "../Personagem/jogador.h"
using namespace std;

class Jogador;

class Consumiveis {

    private:

        int id;
        string nome;
    
    public:

        Consumiveis(int, string);
        ~Consumiveis() { }

        void usarConsumivel(Jogador*);

        // Operadores adicionados
        friend ostream& operator<<(ostream& os, const Consumiveis& c);
        bool operator==(const Consumiveis& other) const;

        // Getters adicionados
        int getId() const;
        string getNome() const;

};

#endif