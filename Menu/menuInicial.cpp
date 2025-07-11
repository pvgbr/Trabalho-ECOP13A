#include <bits/stdc++.h>
#include <unistd.h>
#include "menuInicial.h"
#include "menuLoja.h"
#include "../Batalha/batalhaNormal.h"
#include "../Batalha/batalhaBoss.h"
#include "../Personagem/inimigo.h"
#include "../Utils/dificuldade.h"
#include "../Missao/gerenciadorMissoes.h"
#include "../Missao/missao.h"
#include "../Inventario/consumiveis.h"

using namespace std;

MenuIni::MenuIni(Jogador* p, int missaoAtual) : player{p}, missaoAtual{missaoAtual} {
    ifstream teste("save.txt");
    if (!teste.good()) {
        inicio();
    } else {
        player->carregar("save.txt", &this->missaoAtual);
        dif.setDificuldade(player->getDificuldade());
        menuPrinc();
    }
}  

void MenuIni::inicio() {
    cout << "🏰 Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "\nPressione Enter para continuar... 👉";
    cin.ignore();
    system("cls");
    cout << "🏰 Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "🧙‍♂️ Você é um jovem habitante de uma vila simples, mas com um coração inquieto e sede de aventura. Numa noite tempestuosa, um velho mago bate à sua porta, trazendo uma mensagem urgente:\n";
    cout << "\nPressione Enter para continuar... 👉";
    cin.ignore();
    system("cls");
    cout << "🏰 Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "🧙‍♂️ Você é um jovem habitante de uma vila simples, mas com um coração inquieto e sede de aventura. Numa noite tempestuosa, um velho mago bate à sua porta, trazendo uma mensagem urgente:\n";
    cout << "— 'O mal retorna, jovem. O destino do reino está em suas mãos. Reúna coragem, prepare-se e escreva seu nome entre os heróis de Eldoria. Sua jornada começa agora...' 🔮\n";
    cout << "\nPressione Enter para continuar... 👉";
    cin.ignore();
    system("cls");
    cout << "🏰 Em tempos antigos, o Reino de Eldoria era um lugar de paz e prosperidade, protegido por heróis lendários e magos poderosos. Mas, nas sombras das montanhas distantes, uma força sombria desperta após séculos de silêncio.\n";
    cout << "🧙‍♂️ Você é um jovem habitante de uma vila simples, mas com um coração inquieto e sede de aventura. Numa noite tempestuosa, um velho mago bate à sua porta, trazendo uma mensagem urgente:\n";
    cout << "— 'O mal retorna, jovem. O destino do reino está em suas mãos. Reúna coragem, prepare-se e escreva seu nome entre os heróis de Eldoria. Sua jornada começa agora...' 🔮\n";
    cout << "Com o coração acelerado, você sente que está prestes a viver a maior aventura de sua vida. ✨\n";
    cout << "\nPressione Enter para continuar... 👉";
    cin.ignore();
    cout << "\n\n=== 🎯 Bem-vindo ao RPG de Batalha! 🎯 ===\n\n";
    cout << "Vamos começar criando seu personagem! 👤✨\n";
    // Nome do personagem
    string nome;
    while (true) {
        try {
            cout << "Digite o nome do seu personagem: ";
            getline(cin, nome);
            if (nome.length() > 30) {
                throw length_error("O nome deve ter no máximo 30 caracteres! ❌");
            }
            break;
        } catch (const length_error& e) {
            cout << "Erro: " << e.what() << endl;
        }
    }
    cout << "Perfeito! Seu personagem se chamará " << nome << "! 🎉\n\n";
    // Dificuldade
    map<int, string> m; 
    m[1] = "Fácil"; 
    m[2] = "Médio"; 
    m[3] = "Difícil";
    int dific;
    do {
        cout << "Selecione o nível de dificuldade: ⚙️\n";
        cout << "1 - Fácil ⭐\n";
        cout << "2 - Médio 💪\n";
        cout << "3 - Difícil 🔥\n";
        cout << "Sua escolha: ";
        cin >> dific;
        if (dific < 1 || dific > 3) {
            cout << "\nOpção inválida! Por favor, escolha entre 1 e 3. ❌\n\n";
        }
    } while (dific < 1 || dific > 3);
    cout << "Dificuldade " << m[dific] << " selecionada! ✅\n";
    player->setDificuldade(dific);
    dif.setDificuldade(dific);
    // Configuração inicial do personagem
    player->setNome(nome);
    player->setNivel(1);
    player->setXP(0);
    player->setForca(5);
    player->setDefesa(3);
    player->setVida(100);
    player->setDinheiro(100);
    player->setFase(1);
    // Inicializa o gerenciador de missões
    GerenciadorMissoes gerenciadorMissoes(player);
    cin.ignore();
    cout << "\nSeu personagem foi criado com sucesso! 🎉\n\n";
    cout << "Você começa com:\n";
    cout << "- 100 de vida ❤️\n";
    cout << "- 5 de força 💪\n";
    cout << "- 3 de defesa 🛡️\n";
    cout << "- 100 moedas 💰\n\n";
    cout << "Pressione Enter para continuar... 👉";
    cin.ignore();
    system("cls");
    menuPrinc();
}


void MenuIni::preferencias() {
    cout << "Menu de preferencias: " << endl;
    cout << "1- Selecionar dificuldade" << endl;
    cout << "2- Alterar nome do personagem" << endl;
    cout << "3- Voltar" << endl;
    cout << "Escolha um opcao para continuar: ";
    int e; cin >> e;
    switch(e) {
        case 1: {
            map<int, string> m; m[1] = "Facil"; m[2] = "Medio"; m[3] = "Dificil";
            cout << "Agora selecione o nivel de dificuldade: \n1- Facil\n2- Medio\n3- Dificil" << endl;
            int dific; cin >> dific;
            dif.setDificuldade(dific);
            player->setDificuldade(dific);
            cout << "Dificuldade " << m[dific] << " selecionada!" << endl;
            sleep(2);
            system("cls");
            preferencias();
            break;
        }
        case 2: {
            string n = player->getNome(), n1;
            cin.ignore();
            while (true) {
                try {
                    cout << "Entre com o novo nome do seu personagem: ";
                    getline(cin, n1);
                    if (n1.length() > 30) {
                        throw length_error("O nome deve ter no máximo 30 caracteres!");
                    }
                    break;
                } catch (const length_error& e) {
                    cout << "Erro: " << e.what() << endl;
                }
            }
            cout << "Seu nome foi alterado! (" << n << " -> " << n1 <<")" << endl;
            player->setNome(n1);
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

void MenuIni::reset() {
    cout << "Seu jogo foi resetado!" << endl;
    string n;
    cin.ignore();
    while (true) {
        try {
            cout << "Entre com o nome do seu personagem: ";
            getline(cin, n);
            if (n.length() > 30) {
                throw length_error("O nome deve ter no máximo 30 caracteres!");
            }
            break;
        } catch (const length_error& e) {
            cout << "Erro: " << e.what() << endl;
        }
    }
    player->setNome(n);
    player->setFase(0);
    player->setXP(0);
    player->setNivel(1);
    player->setForca(5);
    player->setDefesa(3);
    player->setDificuldade(1);
    dif.setDificuldade(1);
    player->setVida(100);
    player->setDinheiro(100);
    player->limparInv();
    player->salvar("save.txt", 0);
    cout << endl << "Seu jogo foi resetado com sucesso, abra novamente!" << endl;
    sleep(2);
    exit(0);
}

void MenuIni::menuPrinc() {
    GerenciadorMissoes gerenciadorMissoes(player);
    gerenciadorMissoes.setMissaoAtual(missaoAtual);
    int escolha = -1;
    
    while (escolha != 0) {
        system("cls");
        if(!player->getVida()) player->setVida(100);
        player->imprimir_dados();
        cout << "\n=== 🏠 Menu Principal ===\n";
        cout << "1 - Iniciar Missão Atual ⚔️\n";
        cout << "2 - Ver Missões Disponíveis 📖\n";
        cout << "3 - Ver Progresso da Missão 📈\n";
        cout << "4 - Loja 🛒\n";
        cout << "5 - Inventário 🎒\n";
        cout << "6 - Resetar Jogo 🔄\n";
        cout << "7 - Preferências ⚙️\n";
        cout << "0 - Sair e salvar 🚪\n";
        cout << "Escolha uma opção: ";
        
        cin >> escolha;

        switch (escolha) {
            case 1:
                if (!gerenciadorMissoes.todasMissoesConcluidas()) {
                    gerenciadorMissoes.iniciarMissaoAtual();
                    Missao* missaoAtual = gerenciadorMissoes.getMissaoAtual();
                    if (missaoAtual) {
                        Boss *bossPtr = new Boss("Dragão Ancião", 15, 10, "Você nunca derrotará as trevas!");
                        if (missaoAtual->ehMissaoFinal() && bossPtr) {
                            BatalhaBoss batalhaBoss(player, *bossPtr);
                            if (batalhaBoss.batalhar()) {
                                if (missaoAtual->adicionarInimigoDerrotado()) {
                                    gerenciadorMissoes.avancarMissao();
                                    system("cls");
                                    cout << "\n==============================\n";
                                    cout << "Após uma batalha árdua e intensa, o Dragão Ancião cai diante de sua força e coragem. "
                                        << "O rugido final da criatura ecoa pelas montanhas, dissipando as trevas que há tanto tempo "
                                        << "assolavam o Reino de Eldoria.\n";

                                    cout << "O céu, antes encoberto por nuvens sombrias, se abre e raios de sol dourado iluminam as terras devastadas. "
                                        << "O povo de Eldoria, sentindo a mudança no ar, sai de suas casas e vilarejos, celebrando a vitória do herói "
                                        << "que ousou desafiar o impossível.\n";

                                    cout << "O velho mago, que um dia lhe entregou a missão, surge entre a multidão, sorrindo com orgulho:\n";
                                    cout << "\t— \"Você cumpriu seu destino, bravo aventureiro. O reino está livre graças à sua bravura e ao seu coração puro. "
                                        << "Seu nome será lembrado por gerações!\"\n";

                                    cout << "As cicatrizes da batalha permanecerão como lembrança do sacrifício e da esperança. "
                                        << "Mas agora, Eldoria pode finalmente sonhar com um futuro de paz.\n";

                                    cout << "Parabéns, herói! Você salvou o reino e se tornou uma lenda.\n";
                                    cout << "\nFIM DE JOGO\n";
                                    cout << "==============================\n";
                                    cout << "\nPressione Enter para sair...";
                                    cin.ignore();
                                    cin.ignore();
                                    player->salvar("save.txt", gerenciadorMissoes.getMissaoAtualIndex());
                                    exit(0);
                                }
                            } else {
                                cout << "\nVocê foi derrotado! Voltando ao menu principal...\n";
                                cout << "Você recebeu:\n";
                                cout << "- " << missaoAtual->getRecompensaXP() / 10 << " XP\n";
                                cout << "- " << missaoAtual->getRecompensaDinheiro() / 5 << " moedas\n\n";
                                cout << "Pressione Enter para continuar... 👉";
                                player->alterarXP(missaoAtual->getRecompensaXP() / 10);
                                player->alterarDinheiro(missaoAtual->getRecompensaDinheiro() / 5);
                                cin.ignore();
                                cin.ignore();
                                break;
                            }
                        }
                        else {
                            for (auto& inimigo : missaoAtual->getInimigos()) {
                                BatalhaNormal batalha(player, inimigo);
                                if (batalha.batalhar()) {
                                    if (missaoAtual->adicionarInimigoDerrotado()) {
                                        gerenciadorMissoes.avancarMissao();
                                    }
                                } else {
                                    cout << "\nVocê foi derrotado! Voltando ao menu principal...\n";
                                    cout << "Você recebeu:\n";
                                    cout << "- " << missaoAtual->getRecompensaXP() / 10 << " XP\n";
                                    cout << "- " << missaoAtual->getRecompensaDinheiro() / 5 << " moedas\n\n";
                                    cout << "Pressione Enter para continuar... 👉";
                                    player->alterarXP(missaoAtual->getRecompensaXP() / 10);
                                    player->alterarDinheiro(missaoAtual->getRecompensaDinheiro() / 5);
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    cout << "\nTodas as missões foram concluídas!\n";
                    cout << "Pressione Enter para continuar... 👉";
                    cin.ignore();
                }
                break;
            case 2:
                gerenciadorMissoes.mostrarMissoesDisponiveis();
                break;
            case 3:
                gerenciadorMissoes.mostrarProgressoAtual();
                cout << "Pressione Enter para continuar... 👉";
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                system("cls");
                interagirComLoja(*player);
                break;
            case 5:
                player->gerenciarInventario();
                break;
            case 88:
                player->salvar("save.txt", gerenciadorMissoes.getMissaoAtualIndex());
                cout << "\nJogo salvo com sucesso!\n";
                cout << "Pressione Enter para continuar... 👉";
                cin.ignore();
                cin.ignore();
                break;
            case 89:
                player->carregar("save.txt");
                cout << "\nJogo carregado com sucesso!\n";
                cout << "Pressione Enter para continuar... 👉";
                cin.ignore();
                cin.ignore();
                break;
            case 6:
                system("cls");
                reset();
                break;
            case 7:
                system("cls");
                preferencias();
                break;
            case 0:
                player->salvar("save.txt", gerenciadorMissoes.getMissaoAtualIndex());
                cout << "\nSalvando e saindo do jogo...\n";
                exit(0);
                break;
            default:
                cout << "\nOpção inválida!\n";
                cout << "Pressione Enter para continuar... 👉";
                cin.ignore();
                cin.ignore();
        }
    }
}

Jogador* MenuIni::getPlayer() { return player; }