#include "View.h"

//Don't allow user to select in console window
static void DisableSelection()
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

//Fix the size of the console window
static void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//Set the console's buffer
static void SetScreenBufferSize(SHORT width, SHORT height) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;
	SetConsoleScreenBufferSize(hStdout, NewSize);
}

//Set the size of the console window
static void SetWindowSize(int width, int height) {
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, width, height, TRUE);
}

//Hide scrollbar of the console window
static void ShowScrollbar(bool Show) {
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

//Create the console window
void CreateConsoleWindow(int width, int height) {
	system("color 70");
	SetConsoleTitle(L"Caro Game");
	SetWindowSize(width, height);
	SetScreenBufferSize(172, 42);
	ShowScrollbar(0);
	FixConsoleWindow();
	DisableSelection();
}

//Go to position (x, y)
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Show/Hide Cursor on the console window
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;
	SetConsoleCursorInfo(handle, &ConCurInf);
}

//Change color of Text since this function is called
void TextColor(int color)
{
	static int __BACKGROUND = 7;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		color + (__BACKGROUND << 4));
}

//Print color text USAGE: PrintTextColor(L"example", <color>);
void PrintTextColor(const wstring& s, const int& color) {
	TextColor(color);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wcout << s;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	TextColor(0);
}

//Print color text USAGE: PrintTextColor("example", <color>);
void PrintTextColor(const string& s, const int& color) {
	TextColor(color);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	cout << s;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	TextColor(0);
}

void PrintTextColor_Char(const char& s, const int& color) {
	TextColor(color);
	cout << s;
	TextColor(0);
}

//Close Console
void Exit() {
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	int x = 81 - int(D3_EXIT_01.size() / 2.0f) + 5;
	GotoXY(x, 10);
	wcout << D3_EXIT_01;
	GotoXY(x, 11);
	wcout << D3_EXIT_02;
	GotoXY(x, 12);
	wcout << D3_EXIT_03;
	GotoXY(x, 13);
	wcout << D3_EXIT_04;
	GotoXY(x, 14);
	wcout << D3_EXIT_05;
	GotoXY(x, 15);
	wcout << D3_EXIT_06;
	for (int i = 0, j = 173 - int(D2_RUNANDGO_TEXT_01.size()); i <= 83 - int(D2_RUNANDGO_LOGO_01.size()) || (j >= 91); i += 3, j -= 3)
	{
		GotoXY(i, 25);
		wcout << D2_RUNANDGO_LOGO_01;
		GotoXY(i, 26);
		wcout << D2_RUNANDGO_LOGO_02;
		GotoXY(i, 27);
		wcout << D2_RUNANDGO_LOGO_03;
		GotoXY(i, 28);
		wcout << D2_RUNANDGO_LOGO_04;
		GotoXY(i, 29);
		wcout << D2_RUNANDGO_LOGO_05;
		GotoXY(i, 30);
		wcout << D2_RUNANDGO_LOGO_06;
		GotoXY(i, 31);
		wcout << D2_RUNANDGO_LOGO_07;
		GotoXY(i, 32);
		wcout << D2_RUNANDGO_LOGO_08;
		GotoXY(i, 33);
		wcout << D2_RUNANDGO_LOGO_09;
		GotoXY(i, 34);
		wcout << D2_RUNANDGO_LOGO_10;

		GotoXY(j, 27);
		wcout << D2_RUNANDGO_TEXT_01;
		GotoXY(j, 28);
		wcout << D2_RUNANDGO_TEXT_02;
		GotoXY(j, 29);
		wcout << D2_RUNANDGO_TEXT_03;
		GotoXY(j, 30);
		wcout << D2_RUNANDGO_TEXT_04;
		GotoXY(j, 31);
		wcout << D2_RUNANDGO_TEXT_05;
		GotoXY(j, 32);
		wcout << D2_RUNANDGO_TEXT_06;
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	Sleep(800);
	HWND hwnd = GetConsoleWindow();
	SendMessage(hwnd, WM_CLOSE, 0, 0);
}
