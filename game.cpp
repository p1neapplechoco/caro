#include "console.h"
#include <conio.h>
#include <iostream>
#include <vector>

#define BOARD_SIZE 15
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY 'K'

using namespace std;

bool EndGame = false;
vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));
int _x = BOARD_SIZE / 2;
int _y = BOARD_SIZE / 2;

void drawBoard() {
	for (int i = 0; i <= BOARD_SIZE; i++) {
		for (int j = 0; j <= BOARD_SIZE; j++) {
			gotoxy(3 + 4 * i, 1 + 2 * j);
			cout << ".";
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (i == _x && j == _y) {
				gotoxy(4 + 4 * i, 2 + 2 * j);
				cout << "(" << board[i][j] << ")";
			}
			else {
				gotoxy(5 + 4 * i, 2 + 2 * j);
				cout << board[i][j];
			}

		}
	}
}

void input() {
	char key = _getch();
	switch (key) {
	case 'w':
		_y--;
		break;
	case 's':
		_y++;
		break;
	case 'a':
		_x--;
		break;
	case 'd':
		_x++;
		break;
	default:
		break;
	}
}

void checkWin() {

}

void checkDraw() {

}

void twosideblocked() {

}

void gomoku() {
	system("cls");
	EndGame = false;
	while (EndGame != true) {
		input();
		drawBoard();
	}
	return;
}

