@echo off
:inicio
cls
g++ main.cpp Menu/menuinicial.cpp Personagem/personagem.cpp Personagem/jogador.cpp Personagem/inimigo.cpp Utils/dificuldade.cpp -o game
echo.
echo ===== Compilação finalizada =====
pause
cls
game
echo.
pause
goto inicio
