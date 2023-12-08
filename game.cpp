#include "graphic.h"
#include "game.h"
#include "console.h"
#include "data.h"
#include "settings.h"



#define MAX_CAP 10
#define EMPTY ' ' //when no one has marked the thing

using namespace std;

bool drew;
bool cpu_player = false;
unsigned int turn = 0;
bool win_state = false;
bool isExit = false;
int counter;

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY)); //storing the board
vector<vector<vector<char>>> board_states(1, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY))); //storing each universe of the board
string loadName[MAX_CAP]; //storing board names for loading

char PLAYER1 = 'X'; //player x
char PLAYER2 = 'O'; //player o
int _x = BOARD_SIZE / 2;
int _y = BOARD_SIZE / 2;
int _xmark;
int _ymark;
int turnx = 0;
int turno = 0;
int xscore = 0;
int oscore = 0;
int currentLoadNum;

bool isLoad = false;
bool undo = false;

char turnCheck(unsigned int turn) { //self explainatory
	if (turn % 2 == 0) {
		return PLAYER1;
	}
	else {
		return PLAYER2;
	}
}

void Save() { //saving
save:
	gotoxy(LLeft + 32, LTop + 11);
	cout << "                                                              ";
	string filename;
	gotoxy(85, 32);
	cout << "Nhap ten file de save: ";
	cin >> filename;
	gotoxy(85, 32);
	cout << "                                                             ";

	ifstream file;
	ofstream fileInput;
	ofstream fileName;
	
	file.open("./save/" + filename + ".txt");
	if (file) {
		gotoxy(85, 34);
		cout << "File da ton tai, co muon xoa file cu ko? Y/N ";
		switch (toupper(_getch())) {
		case 'Y':
			file.close();
			fileInput.open("./save/" + filename + ".txt", ios::out);
			fileInput << _x << " " << _y << " " << turnx << " " << turno << " " << turnCheck(turn) << " " << turnCheck(turn + 1);
			for (int j = 0; j < BOARD_SIZE; j++) {
				for (int k = 0; k < BOARD_SIZE; k++) {
					fileInput << board[k][j];
				}
			}
			fileInput.close();
			fileName.open("./save/list_of_names",ios::app);
			fileName << filename << endl;
			fileName.close();
			break;
		case 'N':
			goto save;
		}
		return;
	}
	else {
		file.close();
		fileInput.open("./save/" + filename + ".txt", ios::out);
		fileInput << _x << " " << _y << " " << turnx << " " << turno << " " << turnCheck(turn) << " " << turnCheck(turn + 1) << " " << xscore << " " << oscore << " ";
		for (int j = 0; j < BOARD_SIZE; j++) {
			for (int k = 0; k < BOARD_SIZE; k++) {
				fileInput << board[k][j];
			}
		}
		fileInput.close();
		fileName.open("./save/list_of_names", ios::app);
		fileName << filename << endl;
		fileName.close();
		return;
	}
}

void getLoad() {
	ifstream file;
	file.open("./save/list_of_names");
	for (int i = 0; i < MAX_CAP; i++)
		file >> loadName[i];
	file.close();
}

void Load() { //loading
	DrawListLoad(loadName);
	string filename;
	filename = getLoadName(loadName,isLoad);
	if (isLoad == true) {
		ifstream file;
		file.open("./save/" + filename + ".txt");
		file >> _x >> _y >> turnx >> turno >> PLAYER1 >> PLAYER2 >> xscore >> oscore;
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				file >> noskipws >> board[j][i];
			}
		}
		board_states.push_back(board);
		system("cls");
	}
	else
		system("cls");
}

void mark() {
	if (board[_x][_y] == EMPTY) {
		board[_x][_y] = turnCheck(turn);
		board_states.push_back(board);
		_xmark = _x;
		_ymark = _y;
		if (turn % 2 == 0) {
			turnx++;
		}
		else {
			turno++;
		}
		turn++;
		counter = 10;
		undo = false;
		DrawTurn((int)(turnCheck(turn) == PLAYER1));
	}
}

void Undo() {
	if (turn > 0) {
		board_states.pop_back();
		turn--;
		if (turn % 2 == 0) {
			turnx--;
		}
		else {
			turno--;
		}
		undo = true;
	}
}

void input() {
	if (_kbhit())
		switch (toupper(_getch())) { //keyboard input

		case 'W': case 72: //up
			goXO();
			_y--;
			if (_y < 0) { _y++; }
			break;

		case 'S': case 80: //down
			goXO();
			_y++;
			if (_y >= BOARD_SIZE) { _y--; }
			break;

		case 'A': case 75: //left
			goXO();
			_x--;
			if (_x < 0) { _x++; }
			break;

		case 'D':case 77: //right
			goXO();
			_x++;
			if (_x >= BOARD_SIZE) { _x--; }
			break;

		case '\r':case 32: //marking the spot
			enterXO();
			mark();
			break;

		case 'U': //undo button
			Undo();
			break;

		case 'T': //save button
			Save();
			drew = false;
			break;

		case 27: //escape quit
			switch (Pause()) {
			case 1:
				drawGame(turnCheck(turn + +1));
				DrawTurn((int)(turnCheck(turn) == PLAYER1));
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				break;
			case 2:
				Setting();
				drawGame(turnCheck(turn + +1));
				DrawTurn((int)(turnCheck(turn) == PLAYER1));
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				break;
			case 3:
				Save();
				isExit = true;
				break;
			case 4:
				isExit = true;
				break;
			case 5:
				drawGame(turnCheck(turn + +1));
				DrawTurn((int)(turnCheck(turn) == PLAYER1));
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				break;
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


void drawMarks() {
	board = board_states.back();
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (i == _x && j == _y) {
				gotoxy(LEFT + 1 + 4 * i, TOP + 1 + 2 * j);
				if (board[i][j] == PLAYER1) {
					cout << "(";
					color(113);
					cout << board[i][j];
					color(116);
					cout << ")";
				}
				else if (board[i][j] == PLAYER2) {
					cout << "(";
					color(114);
					cout << board[i][j];
					color(116);
					cout << ")";
				}
				else cout << "(" << board[i][j] << ")";
			}
			else {
				gotoxy(LEFT + 1 + 4 * i, TOP + 1 + 2 * j);
				if (board[i][j] == PLAYER1) {
					cout << " ";
					color(113);
					cout << board[i][j];
					color(116);
					cout << " ";
				}
				else if (board[i][j] == PLAYER2) {
					cout << " ";
					color(114);
					cout << board[i][j];
					color(116);
					cout << " ";;
				}
				else cout << " " << board[i][j] << " ";
			}

		}
	}
}

bool checkDraw() {
	if (turnx + turno == 225 && win_state != true) {
		return true;
	}
	return false;
}

void resetData() {
	getLoad();
	system("cls");
	while (board_states.size() > 1) {
		board_states.pop_back();
	}
	PLAYER1 = 'X';
	PLAYER2 = 'O';
	turn = 0;
	turnx = 0;
	turno = 0;
	win_state = false;
	_x = BOARD_SIZE / 2;
	_y = BOARD_SIZE / 2;
	isLoad = false;
	undo = false;
	isExit = false;
}

void game() {
gomoku:
	drawGame(turnCheck(turn + +1));
	DrawTurn((int)(turnCheck(turn) == PLAYER1));
	DrawScore(xscore, FLeft + 30, FTop + 13);
	DrawScore(oscore, FLeft + 50, FTop + 13);
	wstring Line = L"▀▀▀";
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	gotoxy(96 + 27, 18);
	wcout << Line;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	drew = true;
	while (win_state != true && checkDraw() != true && isExit != true) {
		if (drew == false) goto gomoku;
		input();
		drawMarks();
		turnCheck(turn);
		checkWin();
	}
	if (win_state == true) {
		if (turnCheck(turn + 1) == 'X') {
			xscore++;
			EraseScore(FLeft + 30, FTop + 13);
			DrawScore(xscore, FLeft + 30, FTop + 13);
			DrawScore(oscore, FLeft + 50, FTop + 13);
			winsound();
			color(113);
			DrawWin(-1);
			
		}

		else {
			oscore++;
			winsound();
			EraseScore(FLeft + 50, FTop + 13);
			DrawScore(xscore, FLeft + 30, FTop + 13);
			DrawScore(oscore, FLeft + 50, FTop + 13);
			color(114);
			DrawWin(1);
			
		}
	}
	else if (checkDraw() == true) {
		winsound();
		DrawWin(0);
	}
	else if (isExit == true) {
		return;
	}
	_kbhit() = 0;
	Sleep(4000);
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
GameMode:
	system("cls");
	switch (GameMode()) {
	case 1:
		resetData();
		xscore = 0;
		oscore = 0;
		game();
		break;
	case 2:
		resetData();
		Load();
		if (isLoad == false) goto GameMode;
		else {
			game();
			break;
		}
	case 3:
		return;
		break;
	default:
		break;
	}
}