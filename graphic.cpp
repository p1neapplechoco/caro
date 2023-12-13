#include "graphic.h"
#include "d2data.h"
#include "game.h"
#include "data.h"
#include "settings.h"

int current_num_files = 0;

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

int GameMode()
{
    system("cls");
    logo();
    drawNewgame();
    int Set[] = { 116,116,116,116,116 };
    string options[] = { "    PvsCPU (EASY)    ", "    PvsCPU (HARD)    ", "        PvsP         " };
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

        options[0] = "    PvsCPU (EASY)    ";
        options[1] = "    PvsCPU (HARD)    ";
        options[2] = "        PvsP         ";

        if (counter == 1)
        {
            select1();
            Set[0] = 117;
            options[0] = " >> PvsCPU (EASY) << ";
        }
        if (counter == 2)
        {
            select1();
            Set[1] = 117;
            options[1] = " >> PvsCPU (HARD) << ";
        }
        if (counter == 3)
        {
            select1();
            Set[2] = 117;
            options[2] = "     >> PvsP <<      ";
        }
    }
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


void drawBoard(char PLAYER) {
    DrawTurn((int)(PLAYER));
    color(116);
    int Max_i = BOARD_SIZE * 2;
    int Max_j = BOARD_SIZE * 4;
    //Effect
    gotoxy(LEFT, TOP);
    cout << LEFT_TOP << HORIZONTAL_LINE;
    gotoxy(LEFT + Max_j, TOP + Max_i);
    cout << RIGHT_BOTTOM;
    int j = 1;
    for (int i = 1; j < Max_j / 2; i++, j++) {

        gotoxy(LEFT + 2 * j, TOP);
        cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
        gotoxy(LEFT, TOP + i);
        cout << VERTICAL_LINE;

        gotoxy(LEFT + Max_j - 2 * j, TOP + Max_i);
        cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
        gotoxy(LEFT + Max_j, TOP + Max_i - i);
        cout << VERTICAL_LINE;


    }
    //Draw board
    for (int i = 0; i <= Max_i; i++) {
        gotoxy(LEFT, TOP + i);
        for (int j = 0; j <= Max_j; j++) {
            if (i == 0) {
                if (j == 0) cout << LEFT_TOP;
                else if (j == Max_j) cout << RIGHT_TOP;
                else if (j % 4 == 0) cout << T_SHAPE_DOWN;
                else cout << HORIZONTAL_LINE;
            }
            else if (i == Max_i) {
                if (j == 0) cout << LEFT_BOTTOM;
                else if (j == Max_j) cout << RIGHT_BOTTOM;
                else if (j % 4 == 0) cout << T_SHAPE_UP;
                else cout << HORIZONTAL_LINE;
            }
            else if (i % 2 == 0) {
                if (j == 0) cout << T_SHAPE_RIGHT;
                else if (j == Max_j) cout << T_SHAPE_LEFT;
                else if (j % 4 == 0) cout << CROSS;
                else cout << HORIZONTAL_LINE;
            }
            else {
                if (j % 4 == 0) cout << VERTICAL_LINE;
                else cout << " ";
            }
        }
    }
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

    //int n = 1: X Turn / n = 0: Y Turn
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


void DrawPause() {

    drawhcn(66, 16);
    drawhcn(66, 21);
    drawhcn(66, 26);
    drawhcn(66, 31);

    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    wstring pause[6];
    pause[0] = L"  ██████╗  █████╗ ██╗   ██╗███████╗███████╗██████╗   ";
    pause[1] = L"  ██╔══██╗██╔══██╗██║   ██║██╔════╝██╔════╝██╔══██╗  ";
    pause[2] = L"  ██████╔╝███████║██║   ██║███████╗█████╗  ██║  ██║  ";
    pause[3] = L"  ██╔═══╝ ██╔══██║██║   ██║╚════██║██╔══╝  ██║  ██║  ";
    pause[4] = L"  ██║     ██║  ██║╚██████╔╝███████║███████╗██████╔╝  ";
    pause[5] = L"  ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝╚═════╝   ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(51, 8 + j);
            wcout << pause[j];
        }
    }
    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void DrawListLoad(string loadName[]) {
    color(116);
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    wstring list[6];
    list[0] = L"    ███████╗ █████╗ ██╗   ██╗███████╗██████╗     ███████╗██╗██╗     ███████╗███████╗ ";
    list[1] = L"    ██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗    ██╔════╝██║██║     ██╔════╝██╔════╝ ";
    list[2] = L"    ███████╗███████║██║   ██║█████╗  ██║  ██║    █████╗  ██║██║     █████╗  ███████╗ ";
    list[3] = L"    ╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  ██║  ██║    ██╔══╝  ██║██║     ██╔══╝  ╚════██║ ";
    list[4] = L"    ███████║██║  ██║ ╚████╔╝ ███████╗██████╔╝    ██║     ██║███████╗███████╗███████║ ";
    list[5] = L"    ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═════╝     ╚═╝     ╚═╝╚══════╝╚══════╝╚══════╝ ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(10 + 25, 5 + j);
            wcout << list[j];
        }
    }
    
    int CurrentMode = _setmode(_fileno(stdout), OldMode);

    for (int i = 0; i < 82; i += 2) {
        gotoxy(D2_X_SETTING + i, D2_Y_SETTING);
        cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
        gotoxy(D2_X_SETTING + 80 - i, D2_Y_SETTING + 22);
        cout << D2_UPPER_FRAME << D2_UPPER_FRAME;

    }
    for (int i = 1; i < 22; i += 2) {
        gotoxy(D2_X_SETTING + 81, D2_Y_SETTING + i - 1);
        cout << D2_VERTICAL_FRAME;
        gotoxy(D2_X_SETTING + 81, D2_Y_SETTING + i);
        cout << D2_VERTICAL_FRAME;
        gotoxy(D2_X_SETTING, D2_Y_SETTING + 22 - i);
        cout << D2_VERTICAL_FRAME;
        gotoxy(D2_X_SETTING, D2_Y_SETTING + 22 - i - 1);
        cout << D2_VERTICAL_FRAME;

    }

    for (int i = 0; i < 5; i++) {
        drawhcn(45, 16 + 4 * i);
        gotoxy(47, 17 + 4 * i);
        cout << loadName[i];
    }
    for (int i = 5; i < 10; i++) {
        drawhcn(88, 16 + 4 * (i - 5));
        gotoxy(88, 17 + 4 * (i - 5));
        cout << loadName[i];
    }
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

void Loading() {
    system("cls");
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    wstring loading[8];
    loading[0] = L"██╗      ██████╗  █████╗ ██████╗ ██╗███╗   ██╗ ██████╗  ";
    loading[1] = L"██║     ██╔═══██╗██╔══██╗██╔══██╗██║████╗  ██║██╔════╝  ";
    loading[2] = L"██║     ██║   ██║███████║██║  ██║██║██╔██╗ ██║██║  ███╗ ";
    loading[3] = L"██║     ██║   ██║██╔══██║██║  ██║██║██║╚██╗██║██║   ██║ ";
    loading[4] = L"███████╗╚██████╔╝██║  ██║██████╔╝██║██║ ╚████║╚██████╔╝ ";
    loading[5] = L"╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝  ";
    loading[6] = L" ██ ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(30 + 25, 15 + j);
            wcout << loading[j];
        }

    }
    for (int i = 0; i < 3; i++) {
        wcout << loading[6]; Sleep(300);
    }
    int CurrentMode = _setmode(_fileno(stdout), OldMode);
    system("cls");
}


void DrawScore(int i, int x, int y)
{
       
    wstring Zero[6];

    Zero[0] = L"┏━━━┓";
    Zero[1] = L"┃┏━┓┃";
    Zero[2] = L"┃┃ ┃┃";
    Zero[3] = L"┃┃ ┃┃";
    Zero[4] = L"┃┗━┛┃";
    Zero[5] = L"┗━━━┛";
       
    wstring One[6];
    One[0] = L" ┏┓ ";
    One[1] = L"┏┛┃ ";
    One[2] = L"┗┓┃ ";
    One[3] = L" ┃┃ ";
    One[4] = L"┏┛┗┓";
    One[5] = L"┗━━┛";

    wstring Two[6];




    Two[0] = L"██████╗ ";
    Two[1] = L"╚════██╗";
    Two[2] = L"█████╔╝ ";
    Two[3] = L"██╔═══╝ ";
    Two[4] = L"███████╗";
    Two[5] = L"╚══════╝";

    wstring Three[6];

    Three[0] = L"┏━━━┓";
    Three[1] = L"┃┏━┓┃";
    Three[2] = L"┗┛┏┛┃";
    Three[3] = L"┏┓┗┓┃";
    Three[4] = L"┃┗━┛┃";
    Three[5] = L"┗━━━┛";
      

    wstring Four[6];

    Four[0] = L"┏┓ ┏┓";
    Four[1] = L"┃┃ ┃┃";
    Four[2] = L"┃┗━┛┃"; 
    Four[3] = L"┗━━┓┃";
    Four[4] = L"   ┃┃";
    Four[5] = L"   ┗┛";
       
    wstring Five[6];

    Five[0] = L"┏━━━┓";
    Five[1] = L"┃┏━━┛";
    Five[2] = L"┃┗━━┓";
    Five[3] = L"┗━━┓┃";
    Five[4] = L"┏━━┛┃";
    Five[5] = L"┗━━━┛";

    wstring Six[6];

    Six[0] = L"┏━━━┓";
    Six[1] = L"┃┏━━┛";
    Six[2] = L"┃┗━━┓";
    Six[3] = L"┃┏━┓┃";
    Six[4] = L"┃┗━┛┃";
    Six[5] = L"┗━━━┛";
      
    wstring Seven[6];

    Seven[0] = L"┏━━━┓";
    Seven[1] = L"┃┏━┓┃";
    Seven[2] = L"┗┛┏┛┃";
    Seven[3] = L"  ┃┏┛";
    Seven[4] = L"  ┃┃ ";
    Seven[5] = L"  ┗┛ ";
      

    wstring Eight[6];

    Eight[0] = L"┏━━━┓";
    Eight[1] = L"┃┏━┓┃";
    Eight[2] = L"┃┗━┛┃";
    Eight[3] = L"┃┏━┓┃";
    Eight[4] = L"┃┗━┛┃";
    Eight[5] = L"┗━━━┛";
       

   
    wstring Nine[6];

    Nine[0] = L"┏━━━┓";
    Nine[1] = L"┃┏━┓┃";
    Nine[2] = L"┃┗━┛┃";
    Nine[3] = L"┗━━┓┃";
    Nine[4] = L"┏━━┛┃";
    Nine[5] = L"┗━━━┛";
      

    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    for (int j = 0; j < 6; j++)
    {
        gotoxy(x, y);
        if (i == 0)
            wcout << Zero[j];
        if (i == 1)
            wcout << One[j];
        if (i == 2)
            wcout << Two[j];
        if (i == 3)
            wcout << Three[j];
        if (i == 4)
            wcout << Four[j];
        if (i == 5)
            wcout << Five[j];
        if (i == 6)
            wcout << Six[j];
        if (i == 7)
            wcout << Seven[j];
        if (i == 8)
            wcout << Eight[j];
        if (i == 9)
            wcout << Nine[j];
        y++;
    }
    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void EraseScore(int x, int y) {
    gotoxy(x, y);
    cout << "        ";
    gotoxy(x, y + 1);
    cout << "        ";
    gotoxy(x, y + 2);
    cout << "        ";
    gotoxy(x, y + 3);
    cout << "        ";
    gotoxy(x, y + 4);
    cout << "        ";
    gotoxy(x, y + 5);
    cout << "        ";

}

void DrawWin(int n) {

    gotoxy(LLeft + 32, LTop + 11);
    cout << "                                         ";
	
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
    gotoxy(82 + 25, 25 + 4);
    color(116);
    cout << "Do you want to continue ? ";
    gotoxy(82 + 25, 25 + 6);
    cout << "  _ Press Y to continue";
    gotoxy(82 + 25, 25 + 8);
    cout << "  _ Press any key to go to Menu";
	
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
int PlayMenu()
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

void getcurrent() {
    ifstream inputFile("./save/list_of_names");
    string line;
    while (getline(inputFile, line)) {
        current_num_files++;
    }
    inputFile.close();
}

void DrawSelection(int counter,string loadName[]) {
    DrawListLoad(loadName);
    if (counter < 5 && counter >= 0)
    {
        color(117);
        drawhcn(45, 16 + 4 * counter);
        gotoxy(47, 17 + 4 * counter);
        cout << loadName[counter];
    }
    else if (counter < 10 && counter >= 5)
    {
        color(117);
        drawhcn(88, 16 + 4 * (counter - 5));
        gotoxy(88, 17 + 4 * (counter - 5));
        cout << loadName[counter];
    }
}

string getLoadName(string loadName[], bool &isLoad) {
    getcurrent();
    gotoxy(1, 1);
    cout << current_num_files;
    int counter = 0;
    isLoad = false;
    for (int i = 0;;) {            
        switch (toupper(_getch())) {
        case 'W': case 72:
            if (counter > 0) counter--;
            DrawSelection(counter, loadName);
            break;
        case 'S': case 80:
            if (counter < 5 || counter < 10) counter++;
            DrawSelection(counter, loadName);
            break;
        case 'A': case 75:
            if (counter - 5 >= 0) counter -= 5;
            DrawSelection(counter, loadName);
            break;
        case 'D': case 77:
            if (counter + 5 < 10) counter += 5;
            DrawSelection(counter, loadName);
            break;
        case '\r':
            if (counter < current_num_files)
            {
                isLoad = true;
                return loadName[counter];
            }
            else
            {
                isLoad = false;
                return "0";
            }
        case 27:
            isLoad = false;
            return "0";
        default:
            break;
        }
    }
}

int Pause()
{
    color(116);
    system("cls");
    DrawPause();
    string options[] = { "       RESUME        ", "      SETTINGS       ", "    SAVE AND EXIT    ", "     EXIT TO MENU    "};
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

        gotoxy(67, 33);
        cout << options[3];


        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 4))
        {
            select();
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 3))
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
            return 5;
        }

        options[0] = "       RESUME        ";
        options[1] = "      SETTINGS       ";
        options[2] = "    SAVE AND EXIT    ";
        options[3] = "     EXIT TO MENU    ";

        if (counter == 1)
        {
            select1();
            options[0] = "    >> RESUME <<     ";
        }
        if (counter == 2)
        {
            select1();
            options[1] = "   >> SETTINGS <<    ";
        }
        if (counter == 3)
        {
            select1();
            options[2] = " >> SAVE AND EXIT << ";
        }if (counter == 4)
        {
            select1();
            options[3] = "  >> EXIT TO MENU << ";
        }
    }
}

void drawGame(char PLAYER) {
    system("cls");
    drawBoard(PLAYER);
    DrawLogoFrame();
    DrawInforFrame();
    logo2();
}

