#define _WIN32_WINNT 0x0500
#include "console.h"

using namespace std;



//Close Console
void Exit() {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	int x = 81 - int(D3_EXIT_01.size() / 2.0f) + 5;
	gotoxy(x, 10);
	wcout << D3_EXIT_01;
	gotoxy(x, 11);
	wcout << D3_EXIT_02;
	gotoxy(x, 12);
	wcout << D3_EXIT_03;
	gotoxy(x, 13);
	wcout << D3_EXIT_04;
	gotoxy(x, 14);
	wcout << D3_EXIT_05;
	gotoxy(x, 15);
	wcout << D3_EXIT_06;
	for (int i = 0, j = 173 - int(D2_RUNANDGO_TEXT_01.size()); i <= 83 - int(D2_RUNANDGO_LOGO_01.size()) || (j >= 91); i += 3, j -= 3)
	{
		gotoxy(i, 25);
		wcout << D2_RUNANDGO_LOGO_01;
		gotoxy(i, 26);
		wcout << D2_RUNANDGO_LOGO_02;
		gotoxy(i, 27);
		wcout << D2_RUNANDGO_LOGO_03;
		gotoxy(i, 28);
		wcout << D2_RUNANDGO_LOGO_04;
		gotoxy(i, 29);
		wcout << D2_RUNANDGO_LOGO_05;
		gotoxy(i, 30);
		wcout << D2_RUNANDGO_LOGO_06;
		gotoxy(i, 31);
		wcout << D2_RUNANDGO_LOGO_07;
		gotoxy(i, 32);
		wcout << D2_RUNANDGO_LOGO_08;
		gotoxy(i, 33);
		wcout << D2_RUNANDGO_LOGO_09;
		gotoxy(i, 34);
		wcout << D2_RUNANDGO_LOGO_10;

		gotoxy(j, 27);
		wcout << D2_RUNANDGO_TEXT_01;
		gotoxy(j, 28);
		wcout << D2_RUNANDGO_TEXT_02;
		gotoxy(j, 29);
		wcout << D2_RUNANDGO_TEXT_03;
		gotoxy(j, 30);
		wcout << D2_RUNANDGO_TEXT_04;
		gotoxy(j, 31);
		wcout << D2_RUNANDGO_TEXT_05;
		gotoxy(j, 32);
		wcout << D2_RUNANDGO_TEXT_06;
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	Sleep(800);
	HWND hwnd = GetConsoleWindow();
	SendMessage(hwnd, WM_CLOSE, 0, 0);
}

void bgColor() {
    color(112);
    gotoxy(0, 0);
    for (int i = 0; i < 51; i++) {
        cout << " " << endl;
    }
}

void coloringPixel(int i, int a, int j, int b, COLORREF color) {
    HWND hWnd = GetConsoleWindow();
    HDC Dc = GetDC(hWnd);
    for (;;) {
        for (; i <= a; ++i) {
            for (; j <= b; ++j) {
                SetPixel(Dc, i, j, color);
            }
        }
    }
}

void HideCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void FixedConsoleWindow() {
     HWND consoleWindow = GetConsoleWindow();
     SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void color(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(double x, double y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void removeScroll() {
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
    COORD new_screen_buffer_size;
    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right-screenBufferInfo.srWindow.Left + 1; // Columns
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom-screenBufferInfo.srWindow.Top + 1; // Rows
    SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);
}

void setSize() {
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1280, 720, TRUE);
}

void setupConsole() {
    bgColor();
    HideCursor();
    setSize();
    FixedConsoleWindow();
    removeScroll();
    system("cls");
}

