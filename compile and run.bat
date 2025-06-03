@echo off
:inicio
cls
g++ main.cpp Batalha/batalha.cpp Batalha/batalhaNormal.cpp Batalha/batalhaMultipla.cpp Fase/fase.cpp Inventario/armamento.cpp Inventario/consumiveis.cpp Inventario/inventario.cpp Loja/Loja.cpp Menu/menuinicial.cpp Menu/menuLoja.cpp Personagem/personagem.cpp Personagem/jogador.cpp Personagem/inimigo.cpp Utils/dificuldade.cpp -o game
echo.
echo ===== Compilação finalizada =====
pause
cls
game
echo.
pause
goto inicio
