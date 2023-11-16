#include "graphic.h"
#include "d2data.h"
#include "game.h"
#include "data.h"
#include "settings.h"


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

void logo2() {
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    wstring logo2[7];
    logo2[0] = L"  ▄▄█▀▀▀█▄█     ██     ▀███▀▀▀██▄   ▄▄█▀▀██▄     ";
    logo2[1] = L"▄██▀     ▀█    ▄██▄      ██   ▀██▄▄██▀    ▀██▄   ";
    logo2[2] = L"██▀       ▀   ▄█▀██▄     ██   ▄██ ██▀      ▀██   ";
    logo2[3] = L"██           ▄█  ▀██     ███████  ██        ██   ";
    logo2[4] = L"██▄          ████████    ██  ██▄  ██▄      ▄██   ";
    logo2[5] = L"▀██▄     ▄▀ █▀      ██   ██   ▀██▄▀██▄    ▄██▀   ";
    logo2[6] = L"  ▀▀█████▀▄███▄   ▄████▄████▄ ▄███▄ ▀▀████▀▀     ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++)
        {
            gotoxy(78 + 25, 4 + j);
            wcout << logo2[j];


        }

    }
    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}


void DrawTurn(int n) {
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    wstring X[6];
    X[0] = L"██╗  ██╗";
    X[1] = L"╚██╗██╔╝";
    X[2] = L" ╚███╔╝";
    X[3] = L" ██╔██╗";
    X[4] = L"██╔╝ ██╗";
    X[5] = L"╚═╝  ╚═╝";

    wstring O[6];
    O[0] = L" ██████╗";
    O[1] = L"██╔═══██╗";
    O[2] = L"██║   ██║";
    O[3] = L"██║   ██║";
    O[4] = L"╚██████╔╝";
    O[5] = L" ╚═════╝";

    //int n = 1: X Turn / n=0: Y Turn
    if (n == 1) {

        for (int i = 0; i < 6; i++) {
            color(113);
            gotoxy(FLeft + 12, FTop + 13 + i);
            wcout << X[i];
        }

        for (int i = 0; i < 6; i++) {
            color(116);
            gotoxy(FLeft + 65, FTop + 13 + i);
            wcout << O[i];
        }

    }
    else if (n == 0) {

        for (int i = 0; i < 6; i++) {
            color(114);
            gotoxy(FLeft + 65, FTop + 13 + i);
            wcout << O[i];
        }

        for (int i = 0; i < 6; i++) {
            color(116);
            gotoxy(FLeft + 12, FTop + 13 + i);
            wcout << X[i];
        }
        Sleep(15);
    }
    int CurrentMode = _setmode(_fileno(stdout), OldMode);

}


void DrawLogoFrame() {

    for (int i = 0; i <= LMax_i; i += 2) {
        gotoxy(LLeft + i, LTop);
        cout << Lower_Vertical << Lower_Vertical;
        gotoxy(LMax_i + LLeft - i, LMax_j);
        cout << Upper_Vertical << Upper_Vertical;
        
    }

    for (int i = 1; i < LMax_j - LTop; i += 2) {
        gotoxy(LMax_i + LLeft + 1, LTop + i);
        cout << Horizontal_Line;
        gotoxy(LMax_i + LLeft + 1, LTop + i + 1);
        cout << Horizontal_Line;
        gotoxy(LLeft, LMax_j - i);
        cout << Horizontal_Line;
        gotoxy(LLeft, LMax_j - i - 1);
        cout << Horizontal_Line;
       
    }

}

void DrawInforFrame() {


    for (int i = 0; i <= FMax_i; i += 2) {
        gotoxy(FLeft + i, FTop);
        cout << Lower_Vertical << Lower_Vertical;
        gotoxy(FMax_i + FLeft - i, FMax_j);
        cout << Upper_Vertical << Upper_Vertical;
       
    }

    for (int i = 1; i < FMax_j - FTop; i += 2) {
        gotoxy(FMax_i + FLeft + 1, FTop + i);
        cout << Horizontal_Line;
        gotoxy(FMax_i + FLeft + 1, FTop + i + 1);
        cout << Horizontal_Line;
        gotoxy(FLeft, FMax_j - i);
        cout << Horizontal_Line;
        gotoxy(FLeft, FMax_j - i - 1);
        cout << Horizontal_Line;
        
    }

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

void DrawWin(int n) {
	
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	
	wstring XWin[6];
	XWin[0] = L"██╗  ██╗     ██╗    ██╗██╗███╗   ██╗";
	XWin[1] = L"╚██╗██╔╝     ██║    ██║██║████╗  ██║";
	XWin[2] = L" ╚███╔╝      ██║ █╗ ██║██║██╔██╗ ██║";
	XWin[3] = L" ██╔██╗      ██║███╗██║██║██║╚██╗██║";
	XWin[4] = L"██╔╝ ██╗     ╚███╔███╔╝██║██║ ╚████║";
	XWin[5] = L"╚═╝  ╚═╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	wstring Draw[6];
	Draw[0] = L"██████╗ ██████╗  █████╗ ██╗    ██╗";
	Draw[1] = L"██╔══██╗██╔══██╗██╔══██╗██║    ██║";
	Draw[2] = L"██║  ██║██████╔╝███████║██║ █╗ ██║";
	Draw[3] = L"██║  ██║██╔══██╗██╔══██║██║███╗██║";
	Draw[4] = L"██████╔╝██║  ██║██║  ██║╚███╔███╔╝";
	Draw[5] = L"╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ";

	wstring OWin[6];
	OWin[0] = L" ██████╗     ██╗    ██╗██╗███╗   ██╗";
	OWin[1] = L"██╔═══██╗    ██║    ██║██║████╗  ██║";
	OWin[2] = L"██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║";
	OWin[3] = L"██║   ██║    ██║███╗██║██║██║╚██╗██║";
	OWin[4] = L"╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║";
	OWin[5] = L" ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++)
		{
			
			gotoxy(82 + 25, 25 + 4 + j);
			if (n == -1) wcout << XWin[j];
			if (n == 0) wcout << Draw[j];
			if (n == 1) wcout << OWin[j];
			Sleep(200);

		}
		Sleep(200);
		for (int j = 0; j < 6; j++)
		{
			gotoxy(82 + 25, 25 + 4 + j);
			wcout << "                                    ";
			Sleep(100);

		}
	}
	
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	
	
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

void drawhcn(int x, int y) {
    for (int i = x; i <= x + 21; i += 1) {
        gotoxy(i, y);
        cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
    }
    for (int i = x; i <= x + 21; i += 1) {
        gotoxy(i, y + 3);
        cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
    }
    for (int i = y + 1; i <= y + 3; i++) {
        gotoxy(x, i);
        cout << D2_VERTICAL_FRAME;
    }
    for (int i = y + 1 ; i <= y +3; i++) {
        gotoxy(x + 22, i);
        cout << D2_VERTICAL_FRAME;


    }
}

void drawMenu() {
    drawhcn(66, 16);
    drawhcn(66, 21);
    drawhcn(66, 26);
    drawhcn(66, 31);
    drawhcn(66, 36);
}
void drawNewgame() {
    drawhcn(66, 16);
    drawhcn(66, 21);
    drawhcn(66, 26);
}
int GameMode()
{
    system("cls");
    logo();
    drawNewgame();
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

        if (key == 27)
        {
            return 4;
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