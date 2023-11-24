#include <Windows.h>
#include <iostream>
#include "data.h"
#include "sfx.h"

#ifndef _CONSOLE_H_
void Exit();
void coloringPixel(int, int, int, int, COLORREF);
void FixedConsoleWindow();
void color(int);
void gotoxy(double, double);
void removeScroll();
void setSize();
void setupConsole();
#endif