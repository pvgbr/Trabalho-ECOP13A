# RPG de Batalha — ECOP13A

## Descrição

Este projeto consiste em um jogo de RPG de batalha em modo texto, desenvolvido para fins acadêmicos na disciplina de Programação Orientada a Objetos. O objetivo é proporcionar uma experiência interativa de combate, evolução de personagem, gerenciamento de inventário, missões e loja, utilizando conceitos avançados de C++.

## Funcionalidades

- **Criação e evolução de personagem**
- **Sistema de batalhas**: batalhas normais e batalhas contra chefes (boss)
- **Missões com progressão e recompensas**
- **Inventário de armas e consumíveis**
- **Loja para compra de itens**
- **Sistema de salvamento e carregamento de progresso**
- **Diferentes níveis de dificuldade**
- **Interface textual dinâmica e enriquecida com emojis**

## Estrutura do Projeto

```
Trabalho-ECOP13A/
├── Batalha/           # Lógica de batalhas normais e contra chefes
├── Inventario/        # Gerenciamento de armas e consumíveis
├── Personagem/        # Classes de jogador, inimigos e boss
├── Missao/            # Sistema de missões e progresso
├── Menu/              # Menus do jogo (inicial, loja, etc)
├── Loja/              # Lógica da loja de itens
├── Utils/             # Utilitários (dificuldade, etc)
├── main.cpp           # Ponto de entrada do jogo
├── compile and run.bat# Script para compilar e executar no Windows
└── game.exe           # Executável gerado (Windows)
```

## Como Compilar e Executar

1. **Pré-requisitos:**
   - Compilador C++ (recomendado: g++ ou MinGW para Windows)
   - Sistema operacional Windows (ou ajuste o script para Linux/Mac)

2. **Compilação:**
   - Utilize o script `compile and run.bat` para compilar e executar automaticamente:
     ```
     ./compile and run.bat
     ```
   - Ou compile manualmente todos os arquivos `.cpp`:
     ```
     g++ -std=c++17 -I./ -o game.exe main.cpp Batalha/*.cpp Inventario/*.cpp Personagem/*.cpp Missao/*.cpp Menu/*.cpp Loja/*.cpp Utils/*.cpp
     ```

3. **Execução:**
   - Após compilar, execute o arquivo `game.exe`:
     ```
     ./game.exe
     ```

## Créditos

Este projeto foi desenvolvido por Paulo Vinícius e Felipe Kenji, como projeto final da disciplina ECOP13A.

---

**Observação:**
Este projeto é de caráter didático e pode ser expandido para fins de estudo, pesquisa ou demonstração de conceitos de programação orientada a objetos em C++. 