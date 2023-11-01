#include "console.h"
#include <conio.h>
#include <iostream>
#include <vector>

#define BOARD_SIZE 15 //default size
#define PLAYER1 'X' //player x
#define PLAYER2 'O' //player o
#define EMPTY ' ' //when no one is marking the thing

using namespace std;


unsigned int turn = 0;
bool EndGame = false;
vector<vector<char>> temp(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY)); //temporary for storing the board
vector<vector<char>> board; //storing the main board
vector<vector<vector<char>>> moves(turn + 1, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY))); //storing each universe of the board -> making undo possible
int _x = BOARD_SIZE / 2;
int _y = BOARD_SIZE / 2;

void drawBoard() { //drawing the board and setting up the board
	temp = moves.back();
	board = moves.back();
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

bool turnCheck(){ //self explainatory
	return (turn % 2 == 0);
} 

void input() {
	if (_kbhit())
		switch (_getch()) { //keyboard input

		case 'w': //up
			_y--;
			if (_y < 0) { _y++; }
			break;

		case 's': //down
			_y++;
			if (_y >= BOARD_SIZE) { _y--; }
			break;

		case 'a': //left
			_x--;
			if (_x < 0) { _x++; }
			break;

		case 'd': //right
			_x++;
			if (_x >= BOARD_SIZE) { _x--; }
			break;

		case '\r': //marking the spot
			while (true) {
				if (temp[_x][_y] == EMPTY) {
					if (turnCheck())
						temp[_x][_y] = PLAYER1;
					else
						temp[_x][_y] = PLAYER2;
					moves.push_back(temp);
					turn++;
					break;
				}
				else break;
			}
			break;

		case 'u': //undo button
			if (turn > 0) {
				moves.pop_back();
				turn--;
				break;
			}
			else break;

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
		turnCheck();
		input();
		drawBoard();
	}
	return;
}