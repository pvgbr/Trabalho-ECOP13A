#include "jogador.h"
#include <bits/stdc++.h>

using namespace std;

Jogador::Jogador(string n, int f, int d) : 
    Personagem(n, f, d),
    fase(1),
    xp(0),
    dinheiro(0),
    armaPadrao(0, "Nenhuma", TipoArmamento::ARMA, 0, 0, 100),
    escudoPadrao(0, "Nenhum", TipoArmamento::ESCUDO, 0, 0, 100) {
    armaEquipada = &armaPadrao;
    escudoEquipado = &escudoPadrao;
}

void Jogador::imprimir_dados(){
    map<int, string> m; 
    m[1] = "Fácil"; 
    m[2] = "Médio"; 
    m[3] = "Difícil";

    cout<<"---------------------------------"<<endl;
    cout<<"Nome: "<< nome <<"   Nível: "<<nivel<<" ("<<xp<<"/"<< nivel*100 <<") "<<endl;
    cout<<"Vida: "<< vida <<" ❤️"<<endl;
    cout<<"Força: "<< forca << " (+" << getBonusAtaqueEquipado() << ") 💪" << endl;
    cout<<"Defesa: "<< defesa << " (+" << getBonusDefesaEquipado() << ") 🛡️" << endl;
    cout<<"Dinheiro: "<< dinheiro <<" 💰"<<endl;
    cout<<"Dificuldade: "<< m[dificuldade] << endl;
    cout << "Equipado: ";
    if (armaEquipada) cout << armaEquipada->getNome(); else cout << "Nenhuma";
    cout << " | ";
    if (escudoEquipado) cout << escudoEquipado->getNome(); else cout << "Nenhum";
    cout << endl;
    cout<<"---------------------------------"<<endl;
}

bool Jogador::verificaNivel() {
    if(xp / 100 >= nivel) {
        nivel++;
        xp -= (nivel-1)*100;
        forca++;
        defesa++;
        return true;
    }
    return false;
}

void Jogador::alterarDinheiro(int d) {
    dinheiro += d;
}

void Jogador::alterarXP(int exp) {
    xp += exp;
    verificaNivel();
}

int Jogador::getNivel(){
    return nivel;
}

int Jogador::getFase(){
    return fase;
}

int Jogador::getDinheiro() const {
    return dinheiro;
}

void Jogador::setDinheiro(int d){
    dinheiro = d;
}

void Jogador::setFase(int f) {
    fase = f;
}

void Jogador::setXP(int exp){
    xp = exp;
    verificaNivel();
}

void Jogador::salvar(string caminho, int missaoAtual) {
    try {
        ofstream arq(caminho);
        if (!arq.is_open()) {
            cout << "Erro ao abrir arquivo para salvar!" << endl;
            return;
        }

        arq << nome << '\n';
        arq << forca << '\n';
        arq << defesa << '\n';
        arq << vida << '\n';
        arq << nivel << '\n';
        arq << xp << '\n';
        arq << dinheiro << '\n';
        arq << fase << '\n';
        arq << dificuldade << '\n';
        if (missaoAtual != -1) {
            arq << missaoAtual << '\n';
        }

        arq << (armaEquipada ? armaEquipada->getId() : 0) << '\n';
        arq << (escudoEquipado ? escudoEquipado->getId() : 0) << '\n';

        const auto& armas = invArma.getItens();
        arq << armas.size() << '\n';
        for (const auto& arma : armas) {
            arq << arma.getId() << '\n';
            arq << arma.getNome() << '\n';
            arq << (int)(arma.getTipo()) << '\n';
            arq << arma.getBonusAtaque() << '\n';
            arq << arma.getBonusDefesa() << '\n';
            arq << arma.getDurabilidade() << '\n';
        }

        const auto& consumiveis = invConsumivel.getItens();
        arq << consumiveis.size() << '\n';
        for (const auto& consumivel : consumiveis) {
            arq << consumivel.getId() << '\n';
            arq << consumivel.getNome() << '\n';
        }

        if (arq.fail()) {
            cout << "Erro ao salvar dados do jogador!" << endl;
            arq.close();
            return;
        }

        arq.close();
    } catch (const exception& e) {
        cout << "Erro ao salvar jogo: " << e.what() << endl;
    }
}

void Jogador::carregar(string caminho, int* missaoAtual) {
    ifstream arq(caminho);
    if (arq.is_open()) {

        invArma.clear();
        invConsumivel.clear();
        

        armaEquipada = &armaPadrao;
        escudoEquipado = &escudoPadrao;

        getline(arq, nome);
        arq >> forca;
        arq >> defesa;
        arq >> vida;
        arq >> nivel;
        arq >> xp;
        arq >> dinheiro;
        arq >> fase;
        arq >> dificuldade;
        if (missaoAtual) {
            int missaoSalva;
            if (arq >> missaoSalva) {
                *missaoAtual = missaoSalva;
            }
        }
        arq.ignore(); 

        int idArmaEquipada, idEscudoEquipado;
        arq >> idArmaEquipada >> idEscudoEquipado;
        arq.ignore();

        int numArmas;
        arq >> numArmas;
        arq.ignore();
        
        for (int i = 0; i < numArmas; ++i) {
            int id, tipoInt, bonusAtk, bonusDef, durabilidade;
            string nomeItem;
            
            arq >> id;
            arq.ignore();
            getline(arq, nomeItem);
            arq >> tipoInt >> bonusAtk >> bonusDef >> durabilidade;
            arq.ignore();
            
            Armamento arma(id, nomeItem, static_cast<TipoArmamento>(tipoInt), bonusAtk, bonusDef, durabilidade);
            invArma.adicionarItem(arma);
            
            if (id == idArmaEquipada) {
                armaEquipada = &invArma.getItens().back();
            }
            if (id == idEscudoEquipado) {
                escudoEquipado = &invArma.getItens().back();
            }
        }

        int numConsumiveis;
        arq >> numConsumiveis;
        arq.ignore();
        
        for (int i = 0; i < numConsumiveis; ++i) {
            int id;
            string nomeItem;
            
            arq >> id;
            arq.ignore();
            getline(arq, nomeItem);
            
            if (!nomeItem.empty()) {
                invConsumivel.adicionarItem(Consumiveis(id, nomeItem));
            }
        }

        arq.close();
    }
}

void Jogador::mostrarConsumiveisBatalha() const {
    cout << "\n--- Consumiveis Disponiveis ---" << endl;
    const auto& consumiveis = invConsumivel.getItens();
    if (consumiveis.empty()) {
        cout << "Nenhum consumivel no inventario." << endl;
    } else {
        for (int i = 0; i < consumiveis.size(); ++i) {
            cout << i + 1 << ". " << consumiveis[i] << endl; 
        }
    }
    cout << "-----------------------------" << endl;
}

bool Jogador::usarConsumivelBatalha(int indice) {
    int indiceReal = indice - 1;
    const auto& consumiveis = invConsumivel.getItens();

    if (indiceReal >= 0 && (int)indiceReal < consumiveis.size()) {
        Consumiveis itemParaUsar = consumiveis[indiceReal];
        invConsumivel.removerItem(itemParaUsar); 
        itemParaUsar.usarConsumivel(this);
        cout << "Voce usou: " << itemParaUsar.getNome() << endl;
        return true;
    } else {
        cout << "Indice de consumivel invalido." << endl;
        return false;
    }
}

void Jogador::adicionarArmamentoAoInventario(const Armamento& arma) {

    int idArmaEquipada = -1;
    if (armaEquipada && armaEquipada != &armaPadrao) {
        idArmaEquipada = armaEquipada->getId();
    }

    int idEscudoEquipado = -1;
    if (escudoEquipado && escudoEquipado != &escudoPadrao) {
        idEscudoEquipado = escudoEquipado->getId();
    }

    invArma.adicionarItem(arma);

    armaEquipada = &armaPadrao;
    escudoEquipado = &escudoPadrao;

    auto& inventarioItens = invArma.getItens();
    for (Armamento& item : inventarioItens) {
        if (item.getId() == idArmaEquipada) {
            armaEquipada = &item;
        }
        if (item.getId() == idEscudoEquipado) {
            escudoEquipado = &item;
        }
    }
}

void Jogador::adicionarConsumivelAoInventario(const Consumiveis& consumivel) {
    invConsumivel.adicionarItem(consumivel);
}

void Jogador::mostrarInventariosCompletos() const {
    cout << "\n=== 🎒 Inventário de Armas ===\n";
    const auto& armas = invArma.getItens();
    if (armas.empty()) {
        cout << "Nenhuma arma no inventário. ⚠️\n";
    } else {
        for (int i = 0; i < armas.size(); ++i) {
            cout << i + 1 << ". " << armas[i] << endl;
        }
    }

    cout << "\n=== 🧪 Inventário de Consumíveis ===\n";
    const auto& consumiveis = invConsumivel.getItens();
    if (consumiveis.empty()) {
        cout << "Nenhum consumível no inventário. ⚠️\n";
    } else {
        for (int i = 0; i < consumiveis.size(); ++i) {
            cout << i + 1 << ". " << consumiveis[i] << endl;
        }
    }

    cout << "\n=== 🛡️ Equipamentos Atuais ===\n";
    cout << "Arma: " << (armaEquipada ? armaEquipada->getNome() : "Nenhuma") << endl;
    cout << "Escudo: " << (escudoEquipado ? escudoEquipado->getNome() : "Nenhum") << endl;
}

int Jogador::getBonusAtaqueEquipado() const {
    return armaEquipada ? armaEquipada->getBonusAtaque() : 0;
}

int Jogador::getBonusDefesaEquipado() const {
    return escudoEquipado ? escudoEquipado->getBonusDefesa() : 0;
}

void Jogador::equiparItem(int indiceNoInventario) {
    int indiceReal = indiceNoInventario - 1;
    auto& inventarioArmas = invArma.getItens();

    if (indiceReal < 0 || (int)indiceReal >= inventarioArmas.size()) {
        cout << "Indice de item invalido." << endl;
        return;
    }

    Armamento* itemParaEquipar = &inventarioArmas[indiceReal];

    if (itemParaEquipar->getTipo() == TipoArmamento::ARMA) {
        desequiparItem(TipoArmamento::ARMA);
        armaEquipada = itemParaEquipar;
        cout << "Voce equipou: " << armaEquipada->getNome() << endl;
    } else if (itemParaEquipar->getTipo() == TipoArmamento::ESCUDO) {
        desequiparItem(TipoArmamento::ESCUDO);
        escudoEquipado = itemParaEquipar;
        cout << "Voce equipou: " << escudoEquipado->getNome() << endl;
    } else {
        cout << "Este item nao pode ser equipado." << endl;
    }
}

void Jogador::desequiparItem(TipoArmamento tipo) {
    if (tipo == TipoArmamento::ARMA && armaEquipada) {
        cout << "Voce desequipou: " << armaEquipada->getNome() << endl;
        armaEquipada = nullptr;
    } else if (tipo == TipoArmamento::ESCUDO && escudoEquipado) {
        cout << "Voce desequipou: " << escudoEquipado->getNome() << endl;
        escudoEquipado = nullptr;
    }
}

void Jogador::gerenciarPosBatalha() {
    if (armaEquipada && armaEquipada->getDurabilidade() != -1) {
        armaEquipada->reduzirDurabilidade(1);
        cout << "A durabilidade da sua arma " << armaEquipada->getNome() << " foi reduzida." << endl;
        if (armaEquipada->getDurabilidade() <= 0) {
            cout << "Sua arma " << armaEquipada->getNome() << " quebrou!" << endl;
            invArma.removerItemUnico(*armaEquipada);
            armaEquipada = nullptr;
        }
    }
}

void Jogador::reduzirDurabilidadeEquipamentos() {
    if (armaEquipada && armaEquipada != &armaPadrao && armaEquipada->getDurabilidade() > 0) {
        armaEquipada->reduzirDurabilidade(1);
        if (armaEquipada->getDurabilidade() <= 0) {
            cout << "\033[1;31m"; // Vermelho
            cout << "⚔️  Sua arma " << armaEquipada->getNome() << " quebrou! ⚔️" << endl;
            cout << "\033[0m";
            invArma.removerItemUnico(*armaEquipada);
            armaEquipada = &armaPadrao; 
        }
    }
    
    if (escudoEquipado && escudoEquipado != &escudoPadrao && escudoEquipado->getDurabilidade() > 0) {
        escudoEquipado->reduzirDurabilidade(1);
        if (escudoEquipado->getDurabilidade() <= 0) {
            cout << "\033[1;31m"; // Vermelho
            cout << "🛡️  Seu escudo " << escudoEquipado->getNome() << " quebrou! 🛡️" << endl;
            cout << "\033[0m";
            invArma.removerItemUnico(*escudoEquipado);
            escudoEquipado = &escudoPadrao; 
        }
    }
}

const Inventario<Consumiveis>& Jogador::getInvConsumivel() const {
    return invConsumivel;
}

void Jogador::gerenciarInventario() {
    int escolha = -1;
    while (escolha != 0) {
        system("cls");
        mostrarInventariosCompletos();
        
        cout << "\nOpções:\n";
        cout << "1-" << invArma.getItens().size() << " - Equipar arma/escudo\n";
        cout << "98 - Desequipar arma\n";
        cout << "99 - Desequipar escudo\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opção: ";
        
        cin >> escolha;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Entrada inválida!" << endl;
            cout << "\nPressione Enter para continuar... 👉";
            cin.ignore();
            cin.ignore();
            continue;
        }

        if (escolha > 0 && (int)escolha <= invArma.getItens().size()) {
            equiparItem(escolha);
            cout << "\nItem equipado com sucesso!" << endl;
        } else if (escolha == 98) {
            desequiparItem(TipoArmamento::ARMA);
            cout << "\nArma desequipada!" << endl;
        } else if (escolha == 99) {
            desequiparItem(TipoArmamento::ESCUDO);
            cout << "\nEscudo desequipado!" << endl;
        } else if (escolha != 0) {
            cout << "\nOpção inválida!" << endl;
        }
        
        if (escolha != 0) {
            cout << "\nPressione Enter para continuar... 👉";
            cin.ignore();
            cin.ignore();
        }
    }
}

pair<int, bool> Jogador::usarHabilidade(HabilidadeJogador habilidade, Personagem* alvo) {
    switch (habilidade) {
        case HabilidadeJogador::GOLPE_DUPLO: {
            if (alvo) {
                int dano1 = forca + (rand() % 6);
                int dano2 = forca + (rand() % 6);
                alvo->alterarVida(-dano1);
                alvo->alterarVida(-dano2);
                cout << "Você usa GOLPE DUPLO! Causa " << dano1 << " + " << dano2 << " de dano no inimigo!" << endl;
                return {dano1 + dano2, false};
            }
            break;
        }
        case HabilidadeJogador::ATAQUE_GELO: {
            if (alvo) {
                int dano = forca + 5 + (rand() % 6);
                alvo->alterarVida(-dano);
                bool congelou = (rand() % 100) < 40; // 40% de chance
                cout << "Você lança um ATAQUE DE GELO! Causa " << dano << " de dano";
                if (congelou) cout << " e CONGELA o inimigo por 1 turno!";
                cout << endl;
                return {dano, congelou};
            }
            break;
        }
        default:
            cout << "Habilidade desconhecida!" << endl;
            break;
    }
    return {0, false};
}

void Jogador::limparInv() {
    invArma.clear();
    invConsumivel.clear();
}
