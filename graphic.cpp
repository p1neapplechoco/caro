#include "console.h"
#include "graphic.h"
#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
void drawBoard(vector<vector<vector<char>>> board_states, vector<vector<char>> board, int BOARD_SIZE, int _x, int _y) {
	board = board_states.back();
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
				gotoxy(4 + 4 * i, 2 + 2 * j);
				cout << " " << board[i][j] << " ";
			}
		}
	}
}
*/