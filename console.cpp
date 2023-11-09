#define _WIN32_WINNT 0x0500
#include "console.h"

using namespace std;

void bgColor() {
    color(112);
    gotoxy(0, 0);
    for (int i = 0; i < 50; i++) {
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

