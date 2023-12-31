﻿#include "About.h"
#include "d2data.h"

int About() {
	system("cls");
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	int _pos_x = D2_X_ABOUT + 20;
	for (int i = 0; i < D2_ABOUT_1.size() - 1 - i; i += 2) {
		gotoxy(_pos_x + i, D2_Y_ABOUT - 7);
		wcout << D2_ABOUT_1[i] << D2_ABOUT_1[i + 1];
		gotoxy(_pos_x + i, D2_Y_ABOUT - 6);
		wcout << D2_ABOUT_2[i] << D2_ABOUT_2[i + 1];
		gotoxy(_pos_x + i, D2_Y_ABOUT - 5);
		wcout << D2_ABOUT_3[i] << D2_ABOUT_3[i + 1];
		gotoxy(_pos_x + i, D2_Y_ABOUT - 4);
		wcout << D2_ABOUT_4[i] << D2_ABOUT_4[i + 1];
		gotoxy(_pos_x + i, D2_Y_ABOUT - 3);
		wcout << D2_ABOUT_5[i] << D2_ABOUT_5[i + 1];
		gotoxy(_pos_x + i, D2_Y_ABOUT - 2);
		wcout << D2_ABOUT_6[i] << D2_ABOUT_6[i + 1];

		gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 7);
		wcout << D2_ABOUT_1[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_1[D2_ABOUT_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 6);
		wcout << D2_ABOUT_2[int(D2_ABOUT_1.size()) - 2 - i] << D2_ABOUT_2[D2_ABOUT_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 5);
		wcout << D2_ABOUT_3[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_3[D2_ABOUT_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 4);
		wcout << D2_ABOUT_4[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_4[D2_ABOUT_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 3);
		wcout << D2_ABOUT_5[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_5[D2_ABOUT_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 2);
		wcout << D2_ABOUT_6[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_6[D2_ABOUT_1.size() - 1 - i];

		Sleep(10);
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	for (int i = 0; i < 82; i += 2) {
		gotoxy(D2_X_ABOUT + i, D2_Y_ABOUT);
		cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
		gotoxy(D2_X_ABOUT + 80 - i, D2_Y_ABOUT + 31);
		cout << D2_UPPER_FRAME << D2_UPPER_FRAME;
		Sleep(10);
	}

	for (int i = 1; i < 31; i += 2) {
		gotoxy(D2_X_ABOUT + 81, D2_Y_ABOUT + i);
		cout << D2_VERTICAL_FRAME;
		gotoxy(D2_X_ABOUT + 81, D2_Y_ABOUT + i + 1);
		cout << D2_VERTICAL_FRAME;
		gotoxy(D2_X_ABOUT, D2_Y_ABOUT + 31 - i);
		cout << D2_VERTICAL_FRAME;
		gotoxy(D2_X_ABOUT, D2_Y_ABOUT + 31 - i - 1);
		cout << D2_VERTICAL_FRAME;
		Sleep(10);
		
	}

	OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	gotoxy(D2_X_ABOUT + 28, D2_Y_ABOUT + 3);
	wcout << L"INTRODUCTION TO PROGRAMMING";

	gotoxy(D2_X_ABOUT + 35, D2_Y_ABOUT + 4);
	wcout << L"CARO PROJECT";

	gotoxy(D2_X_ABOUT + 5, D2_Y_ABOUT + 6);
	wcout << L"───────────────────────═══════ Instructor ═══════───────────────────────";
	gotoxy(D2_X_ABOUT + 30, D2_Y_ABOUT + 8);
	wcout << L"PhD. Trương Toàn Thịnh";
	gotoxy(D2_X_ABOUT + 5, D2_Y_ABOUT + 10);
	wcout << L"─────────────────────────────────────────────────────────────────────────";

	gotoxy(D2_X_ABOUT + 10, D2_Y_ABOUT + 11);
	wcout << D2_HCMUS_1;
	gotoxy(D2_X_ABOUT + 10, D2_Y_ABOUT + 12);
	wcout << D2_HCMUS_2;
	gotoxy(D2_X_ABOUT + 10, D2_Y_ABOUT + 13);
	wcout << D2_HCMUS_3;
	gotoxy(D2_X_ABOUT + 10, D2_Y_ABOUT + 14);
	wcout << D2_HCMUS_4;
	gotoxy(D2_X_ABOUT + 10, D2_Y_ABOUT + 15);
	wcout << D2_HCMUS_5;
	gotoxy(D2_X_ABOUT + 10, D2_Y_ABOUT + 16);
	wcout << D2_HCMUS_6;

	gotoxy(D2_X_ABOUT + 5, D2_Y_ABOUT + 18);
	wcout << L"──────────────────────═══════ Group Members ═══════─────────────────────";

	gotoxy(D2_X_ABOUT + 25, D2_Y_ABOUT + 20);
	wcout << L"Nguyễn Gia Bảo";
	gotoxy(D2_X_ABOUT + 49, D2_Y_ABOUT + 20);
	wcout << L"23122015";

	gotoxy(D2_X_ABOUT + 25, D2_Y_ABOUT + 22);
	wcout << L"Nguyễn Văn Khoa";
	gotoxy(D2_X_ABOUT + 49, D2_Y_ABOUT + 22);
	wcout << L"23122016";

	gotoxy(D2_X_ABOUT + 25, D2_Y_ABOUT + 24);
	wcout << L"Lại Nguyễn Hồng Thanh";
	gotoxy(D2_X_ABOUT + 49, D2_Y_ABOUT + 24);
	wcout << L"23122018";

	gotoxy(D2_X_ABOUT + 25, D2_Y_ABOUT + 26);
	wcout << L"Nguyễn Thiên Ấn";
	gotoxy(D2_X_ABOUT + 49, D2_Y_ABOUT + 26);
	wcout << L"23122020";

	gotoxy(D2_X_ABOUT + 5, D2_Y_ABOUT + 28);
	wcout << L"─────────────────────────────────────────────────────────────────────────";
	



	CurrentMode = _setmode(_fileno(stdout), OldMode);
	

	gotoxy(D2_X_ABOUT + 25, D2_Y_ABOUT + 29);
	cout << "Press ESC to return to Main Menu";

	return 0x0000;
}

