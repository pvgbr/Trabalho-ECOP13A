@echo off
cls
g++ main.cpp Batalha/batalha.cpp Batalha/batalhaNormal.cpp Batalha/batalhaBoss.cpp Inventario/armamento.cpp Inventario/consumiveis.cpp Loja/Loja.cpp Menu/menuinicial.cpp Menu/menuLoja.cpp Personagem/personagem.cpp Personagem/boss.cpp Personagem/jogador.cpp Personagem/inimigo.cpp Utils/dificuldade.cpp Missao/missao.cpp Missao/gerenciadorMissoes.cpp -o game
echo.
pause
cls
game
echo.
pause
