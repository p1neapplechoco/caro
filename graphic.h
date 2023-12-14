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
void drawGame(char);
void Loading();
int PlayMenu();
#endif