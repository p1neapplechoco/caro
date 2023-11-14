#include "Help.h"

//Handle key for the Help Menu


//
//  parts in Help
void DrawArrow() {
	int x = D3_Help_Box_Left + D3_Help_Max_i - D3_Help_Max_i / 4, y = D3_Help_Box_Top + 4;
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
	cout << D3_Up_Arrow;
	gotoxy(x, y + 2);
	cout << D3_Down_Arrow;
	gotoxy(x - 4, y + 2);
	cout << D3_Left_Arrow;
	gotoxy(x + 4, y + 2);
	cout << D3_Right_Arrow;

	x -= 5; y = D3_Help_Box_Top + 10;
	char Key[] = { D3_Up_Arrow , D3_Down_Arrow , D3_Right_Arrow , D3_Left_Arrow };
	string Instruction[] = { ": Go Up", ": Go Down", ": Go Right", ": Go Left" };
	for (int i = 0; i < 4; i++, y += 3)
	{
		gotoxy(x - 2, y - 1);
		cout << LEFT_TOP;
		cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
		gotoxy(x - 2, y);
		cout << D3_Help_Double_Horizontal_Line;
		gotoxy(x + 2, y - 1);
		cout << RIGHT_TOP;
		gotoxy(x + 2, y);
		cout << D3_Help_Double_Horizontal_Line;
		gotoxy(x - 2, y + 1);
		cout << LEFT_BOTTOM;
		cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
		gotoxy(x + 2, y + 1);
		cout << RIGHT_BOTTOM;

		gotoxy(x, y);
		cout << Key[i];

		gotoxy(x + 4, y);
		cout << Instruction[i];
	}
}

//In Help
void DrawKey() {
	int x = D3_Help_Box_Left + D3_Help_Max_i / 4, y = D3_Help_Box_Top + 4;
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

	x -= 5; y = D3_Help_Box_Top + 10;
	char Key[] = { 'W', 'S', 'D', 'A' };
	string Instruction[] = { ": Go Up", ": Go Down", ": Go Right", ": Go Left" };
	for (int i = 0; i < 4; i++, y += 3)
	{
		gotoxy(x - 2, y - 1);
		cout << LEFT_TOP;
		cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
		gotoxy(x - 2, y);
		cout << D3_Help_Double_Horizontal_Line;
		gotoxy(x + 2, y - 1);
		cout << RIGHT_TOP;
		gotoxy(x + 2, y);
		cout << D3_Help_Double_Horizontal_Line;
		gotoxy(x - 2, y + 1);
		cout << LEFT_BOTTOM;
		cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
		gotoxy(x + 2, y + 1);
		cout << RIGHT_BOTTOM;

		gotoxy(x, y);
		cout << Key[i];

		gotoxy(x + 4, y);
		cout << Instruction[i];
	}
}

//In Help
void DrawEnter()
{
	int x = (D3_Help_Box_Left + D3_Help_Max_i) / 2 + D3_Help_Max_i / 4 - 7, y = D3_Help_Max_j - 7;
	gotoxy(x - 2, y - 1);
	cout << LEFT_TOP;
	cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
	gotoxy(x - 2, y);
	cout << D3_Help_Double_Horizontal_Line;
	gotoxy(x + 6, y - 1);
	cout << RIGHT_TOP;
	gotoxy(x - 2, y + 1);
	cout << LEFT_BOTTOM;
	cout << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line << D3_Help_Double_Vertical_Line;
	gotoxy(x + 6, y + 1);
	cout << RIGHT_BOTTOM;
	gotoxy(x + 6, y);
	cout << D3_Help_Double_Horizontal_Line;

	gotoxy(x, y);
	cout << "Enter";

	gotoxy(x + 8, y);
	cout << ": Go / Select";
}

//Help Menu
int Help()
{
	system("cls");

	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	for (int i = 0; i < D2_HELP_1.size() - 1 - i; i += 2) {
		gotoxy(D3_Help_Box_Left + 27 + i, 3);
		wcout << D2_HELP_1[i] << D2_HELP_1[i + 1];
		gotoxy(D3_Help_Box_Left + 27 + i, 4);
		wcout << D2_HELP_2[i] << D2_HELP_2[i + 1];
		gotoxy(D3_Help_Box_Left + 27 + i, 5);
		wcout << D2_HELP_3[i] << D2_HELP_3[i + 1];
		gotoxy(D3_Help_Box_Left + 27 + i, 6);
		wcout << D2_HELP_4[i] << D2_HELP_4[i + 1];
		gotoxy(D3_Help_Box_Left + 27 + i, 7);
		wcout << D2_HELP_5[i] << D2_HELP_5[i + 1];
		gotoxy(D3_Help_Box_Left + 27 + i, 8);
		wcout << D2_HELP_6[i] << D2_HELP_6[i + 1];

		gotoxy(D3_Help_Box_Left + 27 + int(D2_HELP_1.size()) - i - 2, 3);
		wcout << D2_HELP_1[D2_HELP_1.size() - 2 - i] << D2_HELP_1[D2_HELP_1.size() - 1 - i];
		gotoxy(D3_Help_Box_Left + 27 + int(D2_HELP_1.size()) - i - 2, 4);
		wcout << D2_HELP_2[D2_HELP_1.size() - 2 - i] << D2_HELP_2[D2_HELP_1.size() - 1 - i];
		gotoxy(D3_Help_Box_Left + 27 + int(D2_HELP_1.size()) - i - 2, 5);
		wcout << D2_HELP_3[D2_HELP_1.size() - 2 - i] << D2_HELP_3[D2_HELP_1.size() - 1 - i];
		gotoxy(D3_Help_Box_Left + 27 + int(D2_HELP_1.size()) - i - 2, 6);
		wcout << D2_HELP_4[D2_HELP_1.size() - 2 - i] << D2_HELP_4[D2_HELP_1.size() - 1 - i];
		gotoxy(D3_Help_Box_Left + 27 + int(D2_HELP_1.size()) - i - 2, 7);
		wcout << D2_HELP_5[D2_HELP_1.size() - 2 - i] << D2_HELP_5[D2_HELP_1.size() - 1 - i];
		gotoxy(D3_Help_Box_Left + 27 + int(D2_HELP_1.size()) - i - 2, 8);
		wcout << D2_HELP_6[D2_HELP_1.size() - 2 - i] << D2_HELP_6[D2_HELP_1.size() - 1 - i];
		Sleep(10);
		
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	for (int i = 0; i <= D3_Help_Max_i; i += 2) {
		gotoxy(D3_Help_Box_Left + i, D3_Help_Box_Top);
		cout << Lower_Vertical << Lower_Vertical;
		gotoxy(D3_Help_Max_i + D3_Help_Box_Left - i, D3_Help_Max_j);
		cout << Upper_Vertical << Upper_Vertical;
		Sleep(5);
	
	}

	for (int i = 1; i < D3_Help_Max_j - D3_Help_Box_Top; i += 2) {
		gotoxy(D3_Help_Max_i + D3_Help_Box_Left + 1, D3_Help_Box_Top + i);
		cout << Horizontal_Line;
		gotoxy(D3_Help_Max_i + D3_Help_Box_Left + 1, D3_Help_Box_Top + i + 1);
		cout << Horizontal_Line;
		gotoxy(D3_Help_Box_Left, D3_Help_Max_j - i);
		cout << Horizontal_Line;
		gotoxy(D3_Help_Box_Left, D3_Help_Max_j - i - 1);
		cout << Horizontal_Line;
		Sleep(5);
	
	}
	gotoxy(68, D3_Help_Max_j - 2);
	cout << "Press Enter to return to Main Menu";
	DrawArrow();
	DrawKey();
	DrawEnter();

	return 0x0000;
}

