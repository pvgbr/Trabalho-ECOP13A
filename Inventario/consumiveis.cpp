#include "consumiveis.h"
#include "../Personagem/jogador.h"

Consumiveis::Consumiveis(int idx, string n) {
    id = idx;
    nome = n;
}

// Implementação dos operadores
ostream& operator<<(ostream& os, const Consumiveis& c) {
    os << "Consumivel: " << c.nome << " (ID: " << c.id << ")";
    return os;
}

bool Consumiveis::operator==(const Consumiveis& other) const {
    return this->id == other.id && this->nome == other.nome;
}

// Implementação dos getters
int Consumiveis::getId() const {
    return id;
}

string Consumiveis::getNome() const {
    return nome;
}

void Consumiveis::usarConsumivel(Jogador* player) {
    cout << "Usando o item " << nome << endl;
    switch(id){
        case 1:
            player->alterarVida(50);
            break;
        case 2:
            player->alterarForca(5);
            break;
        case 3:
            player->alterarVida(25);
            break;
        case 4:
            player->alterarVida(100);
            break;
        case 5:
            player->alterarForca(10);
            break;   
        default:
            break; 
    }
}   

