#include <bits/stdc++.h>
#include <unistd.h>
#include <cstdio>
#include "menuInicial.h"

using namespace std;

MenuIni::MenuIni(Jogador p) : player{p} {
    ifstream teste("save.txt");
    if (!teste.good()) inicio();
    else menuPrinc();
}  

void MenuIni::inicio() {
    cout << "Seja bem-vindo ao sdasdasddas" << endl;
    cout << "Vamos começar pelo nome do seu personagem: ";
    string n;
    getline(cin, n);
    nome = n;
    cout << "Perfeito!" << endl << endl;
    map<int, string> m; m[1] = "Fácil"; m[2] = "Médio"; m[3] = "Difícil";
    cout << "1- Fácil\n2- Médio\n3- Difícil\nAgora selecione o nível de dificuldade: ";
    int d;
    cin >> d;
    cout << "Dificuldade " << m[d] << " selecionada!" << endl;
    dificuldade = d;
    cin.ignore();
    sleep(3);
    system("cls");

    player.setNome(nome);
    player.setNivel(1);
    player.setForca(1);
    player.setDefesa(1);
    player.setVida(100);
    player.setDinheiro(0);

}

void MenuIni::mostra_menu(){
    player.imprimir_dados();
    cout << "1- Jogar" << endl;
    cout << "2- Preferências" << endl;
    cout << "3- Reset" << endl;
    cout << "4- Sair e salvar" << endl; 
}

void MenuIni::preferencias() {
    cout << "Menu de preferências: " << endl;
    cout << "1- Selecionar dificuldade" << endl;
    cout << "2- Alterar nome do personagem" << endl;
    cout << "3- Voltar" << endl;
    cout << "Escolha um opção para continuar: ";
    int e; cin >> e;
    switch(e) {
        case 1: {
            map<int, string> m; m[1] = "Fácil"; m[2] = "Médio"; m[3] = "Difícil";
            cout << "Agora selecione o nível de dificuldade: \n1- Fácil\n2- Médio\n3- Difícil" << endl;
            int d; cin >> d;
            cout << "Dificuldade " << m[d] << " selecionada!" << endl;
            sleep(2);
            system("cls");
            preferencias();
            break;
        }
        case 2: {
            cout << "Entre com o novo nome do seu personagem: ";
            cin.ignore();
            string n = nome, n1; getline(cin, n1);
            cout << "Seu nome foi alterado! (" << n << " -> " << n1 <<")" << endl;
            nome = n1;
            player.setNome(n1);
            sleep(2);
            system("cls");
            preferencias();
            break;
        }
        default:
            system("cls");
            break;
    }

}

void MenuIni::menuPrinc() {

    ifstream arq("save.txt");
    if (arq.good()) {
        player.carregar("save.txt");
        nome = player.getNome();
    }

    while(true) {
        mostra_menu();
        cout << "Escolha uma opção para continuar: ";
        int e;
        cin >> e;

        switch(e){
            case 1:
                cout << "Você está jogando!!!!!!" << endl;
                break;
            case 2:
                system("cls");
                preferencias();
                break;
            case 3:
                cout << "RESET!" << endl;
                sleep(2);
                system("cls");
                exit(0);
                break;
            default:
                cout << "Você escolheu sair! Seu progresso será salvo" << endl;
                player.salvar("save.txt");
                exit(0);
                break;
        }
    }
}

Jogador MenuIni::getPlayer() { return player; }

string MenuIni::getNome() { return nome; }
int MenuIni::getDificuldade() { return dificuldade; }