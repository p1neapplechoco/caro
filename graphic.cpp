#include "graphic.h"
#include "d2data.h"
#include "game.h"

using namespace std;

void logo() {
    color(112);
    gotoxy(42, 5);
    cout << "   ÜÛÛÛÛÛÛÜ   ÜÛÛÛÛÛÛÜ    ÜÜÜÜÛÛÛÜÜÜÜ    ÜÛÛÛÛÛÛÜ     ÜÛ   ÜÛÜ ÛÛÛ    ÛÜ  ";
    gotoxy(42, 6);
    cout << "  ÛÛÛ    ÛÛÛ ÛÛÛ    ÛÛÛ ÜÛÛßßßÛÛÛßßßÛÛÜ ÛÛÛ    ÛÛÛ   ÛÛÛ ÜÛÛÛß ÛÛÛ    ÛÛÛ ";
    gotoxy(42, 7);
    cout << "  ÛÛÛ    Ûß  ÛÛÛ    ÛÛÛ ÛÛÛ   ÛÛÛ   ÛÛÛ ÛÛÛ    ÛÛÛ   ÛÛÛÞÛÛß   ÛÛÛ    ÛÛÛ ";
    gotoxy(42, 8);
    cout << " ÜÛÛÛ        ÛÛÛ    ÛÛÛ ÛÛÛ   ÛÛÛ   ÛÛÛ ÛÛÛ    ÛÛÛ  ÜÛÛÛÛÛß    ÛÛÛ    ÛÛÛ ";
    gotoxy(42, 9);
    cout << "ßßÛÛÛ ÛÛÛÛÜ  ÛÛÛ    ÛÛÛ ÛÛÛ   ÛÛÛ   ÛÛÛ ÛÛÛ    ÛÛÛ ßßÛÛÛÛÛÜ    ÛÛÛ    ÛÛÛ ";
    gotoxy(42, 10);
    cout << "  ÛÛÛ    ÛÛÛ ÛÛÛ    ÛÛÛ ÛÛÛ   ÛÛÛ   ÛÛÛ ÛÛÛ    ÛÛÛ   ÛÛÛÞÛÛÜ   ÛÛÛ    ÛÛÛ ";
    gotoxy(42, 11);
    cout << "  ÛÛÛ    ÛÛÛ ÛÛÛ    ÛÛÛ ÛÛÛ   ÛÛÛ   ÛÛÛ ÛÛÛ    ÛÛÛ   ÛÛÛ ßÛÛÛÜ ÛÛÛ    ÛÛÛ ";
    gotoxy(42, 12);
    cout << "  ÛÛÛÛÛÛÛÛß   ßÛÛÛÛÛÛß   ßÛ   ÛÛÛ   Ûß   ßÛÛÛÛÛÛß    ÛÛÛ   ßÛß ÛÛÛÛÛÛÛÛß  ";
    gotoxy(42, 13);
    cout << "                                                     ß                    ";
}
void drawmenu() {
    for (int i = 60; i < 95; i += 2) {
        gotoxy(i, 15);
        cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
    }
    for (int i = 60; i < 95; i += 2) {
        gotoxy(i, 40);
        cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
    }
    for (int i = 16; i < 41; i++) {
        gotoxy(60, i);
        cout << D2_VERTICAL_FRAME;
    }
    for (int i = 16; i < 41; i++) {
        gotoxy(95, i);
        cout << D2_VERTICAL_FRAME;


    }
}

void drawnewgame() {
    for (int i = 60; i < 95; i += 2) {
        gotoxy(i, 15);
        cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
    }
    for (int i = 60; i < 95; i += 2) {
        gotoxy(i, 32);
        cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
    }
    for (int i = 16; i < 33; i++) {
        gotoxy(60, i);
        cout << D2_VERTICAL_FRAME;
    }
    for (int i = 16; i < 33; i++) {
        gotoxy(95, i);
        cout << D2_VERTICAL_FRAME;
    }
}

int GameMode()
{
    system("cls");
    logo();
    drawnewgame();
    int Set[] = { 116,116,116,116,116 };
    string options[] = { "      NEW GAME       ", "        LOAD         ", "        EXIT         " };
    int counter = 1;
    char key;

    for (int i = 0;;)
    {
       
        gotoxy(67, 18);
        cout << options[0];
       
        gotoxy(67, 23);
        cout << options[1];
        
        gotoxy(67, 28);
        cout << options[2];
       

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3))
        {
            select();
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2))
        {
            select();
            counter++;
        }
        if (key == '\r')
        {
            select();
            return counter;
        }

        Set[0] = 116;
        Set[1] = 116;
        Set[2] = 116;

        options[0] = "      NEW GAME       ";
        options[1] = "        LOAD         ";
        options[2] = "        EXIT         ";

        if (counter == 1)
        {
            select1();
            Set[0] = 117;
            options[0] = "   >> NEW GAME <<    ";
        }
        if (counter == 2)
        {
            select1();
            Set[1] = 117;
            options[1] = "     >> LOAD <<      ";
        }
        if (counter == 3)
        {
            select1();
            Set[2] = 117;
            options[2] = "     >> EXIT <<      ";
        }
    }
}