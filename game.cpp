#include "graphic.h"
#include "game.h"

#define BOARD_SIZE 15 //default size
#define PLAYER1 'X' //player _xmark
#define PLAYER2 'O' //player o
#define EMPTY ' ' //when no one has marked the thing

using namespace std;

bool cpu_player = false;
unsigned int turn = 0;
bool win_state = false;
int counter;

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY)); //storing the board
vector<vector<vector<char>>> board_states(1, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY))); //storing each universe of the board

int _x = BOARD_SIZE / 2;
int _xmark;
int _ymark;
int _y = BOARD_SIZE / 2;
bool undo = false;

void timer() {
	counter = 10;
	Sleep(1000);
	while (counter >= 1) {
		counter--;
	}
}

void Save() {
	string filename, name;
	gotoxy(79, 32);
	cout << "Nhap ten file de save: ";
	cin >> filename;
	gotoxy(79, 32);
	cout << "                                                             ";
	ofstream fileInput(filename + ".txt");
	fileInput << _x << " " << _y << " " << turn << " " << endl;
	for (int j = 0; j < BOARD_SIZE; j++) {
		for (int k = 0; k < BOARD_SIZE; k++) {
			fileInput << board[k][j] << " ";
		}
		fileInput << endl;
	}
	fileInput.close();
}

void Load() {
	/*string filename, name;
	cin >> filename;
	ifstream infile;
	infile.open(filename + ".txt");
	while (!infile.eof()) {

	}
	*/
}

void drawBoard() {
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
					board[_x][_y] = turnCheck(turn);
					board_states.push_back(board);
					_xmark = _x;
					_ymark = _y;
					turn++;
					counter = 10;
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

		case 32: //spacebar for marking
			while (true) {
				if (board[_x][_y] == EMPTY) {
					board[_x][_y] = turnCheck(turn);
					board_states.push_back(board);
					_xmark = _x;
					_ymark = _y;
					turn++;
					counter = 10;
					undo = false;
					break;
				}
				else break;
			}
			break;

		case 'p': //save button
			Save();
			break;

		case 27: //escape quit
			win_state = true;
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
	while (board_states.size() > 1){
		board_states.pop_back();
	}
	turn = 0;
	win_state = false;
	_x = BOARD_SIZE / 2;
	_y = BOARD_SIZE / 2;
	undo = false;
}

void game() {
gomoku:
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
	while (true) {
		if (_kbhit()) {
			if (_getch() == 'y') {
				resetData();
				goto gomoku;
			}
			else
				resetData();
				return;;
		}
	}
}

void gomoku() {
	switch (GameMode()) {
	case 1:
		resetData();
		game();
		break;
	case 2:
		resetData();
		cpu_player = true;
		game();
		break;
	case 3:
		resetData();
		Load();
		game();
		break;
	}
	
}