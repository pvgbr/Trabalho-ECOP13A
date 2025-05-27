#include "consumiveis.h"

Consumiveis::Consumiveis(int i, string n) : id{i}, nome{n} { }

void Consumiveis::usarConsumivel(Jogador* player) {
    cout << "Usando o item " << nome;
    switch(id){
        case 1: // Poção de vida
            cout << "Poção de vida" << endl;
            player->alterarVida(50);
            break;
        case 2: // Poção de força
            cout << "Poção de força" << endl;
            player->alterarForca(5);
            break;
        default:
            //tratamento de exceção ?
            break; 
 
    }
}   

