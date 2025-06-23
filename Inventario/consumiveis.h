#ifndef CONSUMIVEIS_H
#define CONSUMIVEIS_H

#include <bits/stdc++.h>
using namespace std;

class Jogador;

// Classe de consumiveis
class Consumiveis {

    private:

        int id;
        string nome;
    
    public:

        Consumiveis(int, string);
        ~Consumiveis() { }

        void usarConsumivel(Jogador*); // Função usada para utlizar um consumivel

        friend ostream& operator<<(ostream& os, const Consumiveis& c);
        bool operator==(const Consumiveis& other) const;

        int getId() const;
        string getNome() const;

};

#endif