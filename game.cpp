#include "console.h"
#include <conio.h>
#include <iostream>
#include <vector>

#define BOARD_SIZE 15 //default size
#define PLAYER1 'X' //player _xmark
#define PLAYER2 'O' //player o
#define EMPTY ' ' //when no one has marked the thing

using namespace std;

unsigned int turn = 0;
bool win_state;
vector<vector<char>> temp(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY)); //temporary for storing the board
vector<vector<char>> board; //storing the main board
vector<vector<vector<char>>> board_states(turn + 1, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY))); //storing each universe of the board
int _x = BOARD_SIZE / 2;
int _xmark;
int _ymark;
int _y = BOARD_SIZE / 2;
bool undo = false;

void drawBoard() { //drawing the board and setting up the board
	board = board_states.back();
	temp = board_states.back();
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

char turnCheck(unsigned int turn){ //self explainatory
	if (turn % 2 == 0) return PLAYER1;
	else return PLAYER2;
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
				if (board[_x][_y] == EMPTY) {
					temp[_x][_y] = turnCheck(turn);
					board_states.push_back(temp);
					_xmark = _x;
					_ymark = _y;
					turn++;
					undo = false;
					break;
				}
				else break;
			}
			break;

		case 'u': //undo button
			if (turn > 0) {
				board_states.pop_back();
				turn--;
				undo = true;
				break;				
			}
			else break;

		case 72:
			_y--;
			if (_y < 0) { _y++; }
			break;

		case 80:
			_y++;
			if (_y >= BOARD_SIZE) { _y--; }
			break;

		case 75:
			_x--;
			if (_x < 0) { _x++; }
			break;

		case 77:
			_x++;
			if (_x >= BOARD_SIZE) { _x--; }
			break;

		case 32:
			while (true) {
				if (board[_x][_y] == EMPTY) {
					temp[_x][_y] = turnCheck(turn);
					board_states.push_back(temp);
					_xmark = _x;
					_ymark = _y;
					turn++;
					break;
				}
				else break;
			}
			break;

		default:
			break;
		}
}

void checkWin() {
	if (undo == false) {
		//check ver
		int count = 1;
		for (int i = 1; i < 5; i++) {
			if (_xmark + i >= BOARD_SIZE || _xmark + i < 0) {
				break;
			}
			else if (board[_xmark + i][_ymark] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		for (int i = -1; i > -5; i--) {
			if (_xmark - 1 + i >= BOARD_SIZE || _xmark - 1 + i < 0) {
				break;
			}
			else if (board[_xmark + i][_ymark] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		if (count >= 5) {
			win_state = true;
			return;
		}
		//check hor
		count = 1;
		for (int i = 1; i < 5; i++) {
			if (_ymark + i >= BOARD_SIZE || _ymark + i < 0) {
				break;
			}
			else if (board[_xmark][_ymark + i] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		for (int i = -1; i > -5; i--) {
			if (_ymark + i >= BOARD_SIZE || _ymark + i < 0) {
				break;
			}
			else if (board[_xmark][_ymark + i] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		if (count >= 5) {
			win_state = true;
			return;
		}
		//check -45
		count = 1;
		for (int i = 1; i < 5; i++) {
			if (_ymark + i >= BOARD_SIZE || _ymark + i < 0 || _xmark + i < 0 || _xmark + i >= BOARD_SIZE) {
				break;
			}
			else if (board[_xmark + i][_ymark + i] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		for (int i = -1; i > -5; i--) {
			if (_ymark + i >= BOARD_SIZE || _ymark + i < 0 || _xmark + i < 0 || _xmark + i >= BOARD_SIZE) {
				break;
			}
			else if (board[_xmark + i][_ymark + i] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		if (count >= 5) {
			win_state = true;
			return;
		}
		//check 45
		count = 1;
		for (int i = 1; i < 5; i++) {
			if (_ymark + i >= BOARD_SIZE || _ymark + i < 0 || _xmark - i < 0 || _xmark - i >= BOARD_SIZE) {
				break;
			}
			else if (board[_xmark - i][_ymark + i] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		for (int i = -1; i > -5; i--) {
			if (_ymark + i >= BOARD_SIZE || _ymark + i < 0 || _xmark - i < 0 || _xmark - i >= BOARD_SIZE) {
				break;
			}
			else if (board[_xmark - i][_ymark + i] != turnCheck(turn + 1)) {
				break;
			}
			count++;
		}
		if (count >= 5) {
			win_state = true;
			return;
		}
	}
}

bool checkDraw() {
	if (turn == 225 && win_state != true) {
		return true;
	}
	return false;
}

void resetData() {
	system("cls");
	win_state = false;
}

void gomoku() {
	resetData();
	while (win_state != true && checkDraw() != true) {
		input();
		drawBoard();
		turnCheck(turn);
		checkWin();
	}
	if (win_state == true) {
		gotoxy(79, 32);
		cout << turnCheck(turn + 1);
	}
	else if (checkDraw() == true) {
		gotoxy(79, 32);
		cout << "Draw";
	}
	return;
}