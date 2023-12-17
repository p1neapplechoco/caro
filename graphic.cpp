#include "graphic.h"
#include "d2data.h"
#include "game.h"
#include "data.h"
#include "settings.h"
#include "help.h"

using namespace std;

int current_num_files = 0;

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
    color(112);
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
    color(116);
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


    DrawBox(D2_X_SETTING, D2_Y_SETTING, 82,22);
   
    for (int i = 0; i < 5; i++) {
        DrawHcn(45, 16 + 4 * i);
        gotoxy(47, 17 + 4 * i);
        cout << loadName[i];
    }
    for (int i = 5; i < 10; i++) {
        DrawHcn(88, 16 + 4 * (i - 5));
        gotoxy(90, 17 + 4 * (i - 5));
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


        int x = LLeft+15 , y = LTop + 3;
        gotoxy(x - 2, y - 1);
        cout << LEFT_TOP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x - 2, y);
        cout << D3_Help_Double_Horizontal_Line;

        gotoxy(x + 2, y - 1);
        cout << RIGHT_TOP;
        gotoxy(x - 2, y + 1);
        cout << CROSS;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x - 2, y + 2);
        cout << D3_Help_Double_Horizontal_Line;
        gotoxy(x + 2, y);
        cout << D3_Help_Double_Horizontal_Line;
        gotoxy(x + 2, y + 1);
        cout << CROSS;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x + 2, y + 2);
        cout << D3_Help_Double_Horizontal_Line;


        gotoxy(x - 2, y + 3);
        cout << T_SHAPE_UP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x + 2, y + 3);
        cout << T_SHAPE_UP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;

        gotoxy(x - 6, y + 1);
        cout << LEFT_TOP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x - 6, y + 2);
        cout << D3_Help_Double_Horizontal_Line;
        gotoxy(x - 6, y + 3);
        cout << LEFT_BOTTOM;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;

        gotoxy(x + 6, y + 1);
        cout << RIGHT_TOP;
        gotoxy(x + 6, y + 3);
        cout << RIGHT_BOTTOM;
        gotoxy(x + 6, y + 2);
        cout << D3_Help_Double_Horizontal_Line;

        gotoxy(x, y);
        cout << "W";
        gotoxy(x, y + 2);
        cout << "S";
        gotoxy(x - 4, y + 2);
        cout << "A";
        gotoxy(x + 4, y + 2);
        cout << "D";

        int g = 25;
        gotoxy(x  - 2+g, y - 1);
        cout << LEFT_TOP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x - 2+g, y);
        cout << D3_Help_Double_Horizontal_Line;

        gotoxy(x + 2+g, y - 1);
        cout << RIGHT_TOP;
        gotoxy(x - 2+g, y + 1);
        cout << CROSS;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x - 2 +g, y + 2);
        cout << D3_Help_Double_Horizontal_Line;
        gotoxy(x + 2+g, y);
        cout << D3_Help_Double_Horizontal_Line;
        gotoxy(x + 2+g, y + 1);
        cout << CROSS;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x + 2+g, y + 2);
        cout << D3_Help_Double_Horizontal_Line;


        gotoxy(x - 2 +g, y + 3);
        cout << T_SHAPE_UP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x + 2 +g, y + 3);
        cout << T_SHAPE_UP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;

        gotoxy(x - 6+g, y + 1);
        cout << LEFT_TOP;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
        gotoxy(x - 6+g, y + 2);
        cout << D3_Help_Double_Horizontal_Line;
        gotoxy(x - 6+g, y + 3);
        cout << LEFT_BOTTOM;
        cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;

        gotoxy(x + 6 + g, y + 1);
        cout << RIGHT_TOP;
        gotoxy(x + 6+g, y + 3);
        cout << RIGHT_BOTTOM;
        gotoxy(x + 6+g, y + 2);
        cout << D3_Help_Double_Horizontal_Line;

        gotoxy(x +g, y);
        cout << D3_Up_Arrow;
        gotoxy(x +g, y + 2);
        cout << D3_Down_Arrow;
        gotoxy(x - 4 +g, y + 2);
        cout << D3_Left_Arrow;
        gotoxy(x + 4 +g, y + 2);
        cout << D3_Right_Arrow;

        gotoxy(x + 12, y + 2);
        cout << "OR";
        gotoxy(x + 4 + g + 9, y + 2);
        cout << " : TO GO";
        gotoxy(x - 12, y + 5);
        cout << "The winner is the first player to form a horizontal, vertical, or "; 
        gotoxy(x - 12, y + 6);
        cout << "diagonal line of five game pieces in a row.";
        gotoxy(x + 40, y + 8);
        cout << "GOOD LUCK PLAYERS !";
            
    }

    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
   
    gotoxy(10, 38); wcout << L"╔═════╗";
    gotoxy(10, 39); wcout << L"║ Esc ║ : PAUSE";
    gotoxy(10, 40); wcout << L"╚═════╝";



    gotoxy(30, 38); wcout << L"╔═════╗";
    gotoxy(30, 39); wcout << L"║  U  ║ : UNDO";
    gotoxy(30, 40); wcout << L"╚═════╝";

    gotoxy(50, 38); wcout << L"╔═════════════════╗";
    gotoxy(50, 39); wcout << L"║  SPACE / ENTER  ║ : MARK";
    gotoxy(50, 40); wcout << L"╚═════════════════╝";
    int CurrentMode = _setmode(_fileno(stdout), OldMode);

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
       
    wstring Zero[3];

    Zero[0] = L"█▀▀█";
    Zero[1] = L"█▄▀█";
    Zero[2] = L"█▄▄█";
       
    wstring One[3];
    One[0] = L"▄█ ";
    One[1] = L" █ ";
    One[2] = L"▄█▄";

    wstring Two[3];
    Two[0] = L"█▀█";
    Two[1] = L" ▄▀";
    Two[2] = L"█▄▄";


    wstring Three[3];

    Three[0] = L"█▀▀█";
    Three[1] = L"  ▀▄";
    Three[2] = L"█▄▄█";
      

    wstring Four[3];

    Four[0] = L" █▀█";
    Four[1] = L"█▄▄█▄";
    Four[2] = L"   █";

       
    wstring Five[3];

    Five[0] = L"█▀▀";
    Five[1] = L"▀▀▄";
    Five[2] = L"▄▄▀";


    wstring Six[3];
    Six[0] = L"▄▀▀▄";
    Six[1] = L"█▄▄ ";
    Six[2] = L"▀▄▄▀";
      
    wstring Seven[3];
    Seven[0] = L"▀▀▀█";
    Seven[1] = L"  █";
    Seven[2] = L" ▐▌";


    wstring Eight[3];

    Eight[0] = L"▄▀▀▄";
    Eight[1] = L"▄▀▀▄";
    Eight[2] = L"▀▄▄▀";

       

   
    wstring Nine[3];

    Nine[0] = L"▄▀▀▄";
    Nine[1] = L"▀▄▄█";
    Nine[2] = L" ▄▄▀";
      

    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    for (int j = 0; j < 3; j++)
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
    gotoxy(82 + 25, 25 + 4);
    color(116);
    wcout << L"Do you want to continue ? ";
    gotoxy(82+25, 31); wcout << L"╔═════╗";
    gotoxy(82+25, 32); wcout << L"║  Y  ║ : CONTINUE";
    gotoxy(82+25, 33); wcout << L"╚═════╝";
    int CurrentMode = _setmode(_fileno(stdout), OldMode);

   
    gotoxy(82 + 20, 27 + 9);
    cout << " Press any key to go to Menu";
	
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
    MenuLogo(30, 18);
    animal(100, 18);
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

int getcurrent() {
    int filesnum = 0;
    ifstream inputFile("./save/list_of_names");
    string line;
    while (getline(inputFile, line)) {
        filesnum++;
    }
    inputFile.close();
    return filesnum;
}

void DrawSelection(int counter,string loadName[]) {
    DrawListLoad(loadName);
    if (counter < 5 && counter >= 0)
    {
        color(117);
        DrawHcn(45, 16 + 4 * counter);
        gotoxy(47, 17 + 4 * counter);
        cout << loadName[counter];
    }
    else if (counter < 10 && counter >= 5)
    {
        color(117);
        DrawHcn(88, 16 + 4 * (counter - 5));
        gotoxy(90, 17 + 4 * (counter - 5));
        cout << loadName[counter];
    }
}

string getLoadName(string loadName[], bool &isLoad) {
    current_num_files = getcurrent();
    gotoxy(1, 1);
    cout << current_num_files;
    int counter = 0;
    isLoad = false;
    for (int i = 0;;) {
        DrawSelection(counter, loadName);            
        switch (toupper(_getch())) {
        case 'W': case 72:
            if (counter > 0) counter--;
            break;
        case 'S': case 80:
            if (counter < 5 || counter < 10) counter++;
            break;
        case 'A': case 75:
            if (counter - 5 >= 0) counter -= 5;
            break;
        case 'D': case 77:
            if (counter + 5 < 10) counter += 5;
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

void DrawPvP() {

    gotoxy(96 + 27, 17);
    wcout << Line;
    wstring pvp[6];
    pvp[0] = L"  ██████╗     ██╗   ██╗███████╗     ██████╗ ";
    pvp[1] = L"  ██╔══██╗    ██║   ██║██╔════╝     ██╔══██╗";
    pvp[2] = L"  ██████╔╝    ██║   ██║███████╗     ██████╔╝";
    pvp[3] = L"  ██╔═══╝     ╚██╗ ██╔╝╚════██║     ██╔═══╝ ";
    pvp[4] = L"  ██║          ╚████╔╝ ███████║     ██║     ";
    pvp[5] = L"  ╚═╝           ╚═══╝  ╚══════╝     ╚═╝     ";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(23, j + 1);
            wcout << pvp[j];
        }
    }

    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void DrawPvC() {
    wstring Line = L"▀▀▀";
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    gotoxy(96 + 27, 16);
    wcout << Line;

               
                                                                     

    wstring pvc[3];
    pvc[0] = L" ░▒█▀▀█░░░▄░░░▄░█▀▀░░░▒█▀▀▄░▒█▀▀█░▒█░▒█";
    pvc[1] = L" ░▒█▄▄█░░░░█▄█░░▀▀▄░░░▒█░░░░▒█▄▄█░▒█░▒█";
    pvc[2] = L" ░▒█░░░░░░░░▀░░░▀▀▀░░░▒█▄▄▀░▒█░░░░░▀▄▄▀";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(10, j + 1);
            wcout << pvc[j];
        }
    }
    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void drawGame(char PLAYER, int cpu_player) {
    system("cls");
    drawBoard(PLAYER);
    if (cpu_player != 0) DrawPvC();
    else DrawPvP();
    DrawLogoFrame();
    DrawInforFrame();
    logo2();
}



void SetColor(int backgound_color, int text_color) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void HighLight(int x, int y, int w, int h, int Color) {
    SetColor(Color, Color);
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            gotoxy(i, j);
            cout << " ";
        }
    }
    SetColor(128, 113);
}


void DrawBox(int x, int y, int w, int h) {
    gotoxy(x, y);
    cout << char(201); //Góc trái trên
    gotoxy(x, y + h);
    cout << char(200); //Góc phải trên
    for (int i = 1; i < w; i++) //vẽ 2 cạnh bên
    {
        gotoxy(x + i, y);
        cout << char(205);
        gotoxy(x + i, y + h);
        cout << char(205);
    }
    gotoxy(x + w, y); //Góc trái dưới
    cout << char(187);
    gotoxy(x + w, y + h); //Góc phải dưới
    cout << char(188);
    for (int j = 1; j < h; j++) //Vẽ 2 cạnh trên dưới {
    {
        gotoxy(x, y + j);
        cout << char(186);
        gotoxy(x + w, y + j);
        cout << char(186);
    }
}

void DrawHcn(int x, int y) {
    DrawBox(x, y, 21, 3);
}

void MenuLogo(int x, int y)
{
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    gotoxy(x, y);
    wcout << D1_MENULOGO_1;
    gotoxy(x, y + 1);
    wcout << D1_MENULOGO_2;
    gotoxy(x, y + 2);
    wcout << D1_MENULOGO_3;
    gotoxy(x, y + 3);
    wcout << D1_MENULOGO_4;
    gotoxy(x, y + 4);
    wcout << D1_MENULOGO_5;
    gotoxy(x, y + 5);
    wcout << D1_MENULOGO_6;
    gotoxy(x, y + 6);
    wcout << D1_MENULOGO_7;
    gotoxy(x, y + 7);
    wcout << D1_MENULOGO_8;
    gotoxy(x, y + 8);
    wcout << D1_MENULOGO_9;
    gotoxy(x, y + 9);
    wcout << D1_MENULOGO_10;
    gotoxy(x, y + 10);
    wcout << D1_MENULOGO_11;
    gotoxy(x, y + 11);
    wcout << D1_MENULOGO_12;
    gotoxy(x, y + 12);
    wcout << D1_MENULOGO_13;
    gotoxy(x, y + 13);
    wcout << D1_MENULOGO_14;
    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}


void animal(int x, int y) {
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
    gotoxy(x, y);
    wcout << D2_BEAR_1;
    gotoxy(x, y + 1);
    wcout << D2_BEAR_2;
    gotoxy(x, y + 2);
    wcout << D2_BEAR_3;
    gotoxy(x, y + 3);
    wcout << D2_BEAR_4;
    gotoxy(x, y + 4);
    wcout << D2_BEAR_5;

    gotoxy(x, y);
    wcout << D2_CAT_1;
    gotoxy(x, y + 7);
    wcout << D2_CAT_2;
    gotoxy(x, y + 8);
    wcout << D2_CAT_3;
    gotoxy(x, y + 9);
    wcout << D2_CAT_4;
    gotoxy(x, y + 10);
    wcout << D2_CAT_5;



    gotoxy(x, y+13);
    wcout << D2_WHALE_1;
    gotoxy(x, y + 14);
    wcout << D2_WHALE_2;
    gotoxy(x, y + 15);
    wcout << D2_WHALE_3;
    gotoxy(x, y + 16);
    wcout << D2_WHALE_4;
    gotoxy(x, y + 17);
    wcout << D2_WHALE_5;

    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

