#include "console.h"
#include <conio.h>
#include <iostream>

#define BOARD_SIZE 15 //default size

#ifndef _GRAPHIC_H_

void logo();
void drawmenu();
void drawnewgame();
int GameMode();
void drawhcn(int x, int y);
void drawMenu();
void drawNewgame();
void DrawWin(int);
void DrawLogoFrame();
void DrawInforFrame();
void DrawTurn(int n);
void logo2();
void DrawListLoad(string loadName[]);
string getLoadName(string loadName[], bool &isLoad);
void DrawScore(int i, int x, int y);
void EraseScore(int x, int y);
int Pause();
void drawGame(char, int);
void Loading();
int PlayMenu();
void SetColor(int backgound_color, int text_color);
void HighLight(int x, int y, int w, int h, int Color);
void DrawPvP();
void DrawPvC();
void DrawBox(int x, int y, int w, int h);
void DrawHcn(int x, int y);
void MenuLogo(int x, int y);
int getcurrent();
void animal(int x, int y);

#endif