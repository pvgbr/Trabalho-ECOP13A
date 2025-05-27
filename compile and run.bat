@echo off
:inicio
cls
g++ main.cpp Batalha/batalha.cpp Batalha/batalhaNormal.cpp Fase/fase.cpp Menu/menuinicial.cpp Personagem/personagem.cpp Personagem/jogador.cpp Personagem/inimigo.cpp Utils/dificuldade.cpp -o game
echo.
echo ===== Compilação finalizada =====
pause
cls
game
echo.
pause
goto inicio
