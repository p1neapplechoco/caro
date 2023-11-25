#include "graphic.h"
#include "game.h"
#include "console.h"
#include "data.h"

#define BOARD_SIZE 15 //default size
#define EMPTY ' ' //when no one has marked the thing

using namespace std;

bool drew;
bool cpu_player = false;
unsigned int turn = 0;
bool win_state = false;
int counter;

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY)); //storing the board
vector<vector<vector<char>>> board_states(1, vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY))); //storing each universe of the board

char PLAYER1 = 'X'; //player x
char PLAYER2 = 'O'; //player o
int _x = BOARD_SIZE / 2;
int _y = BOARD_SIZE / 2;
int _xmark;
int _ymark;
int turnx = 0;
int turno = 0;

bool undo = false;

void DrawWin(int n) {
	
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	
	wstring XWin[6];
	XWin[0] = L"██╗  ██╗     ██╗    ██╗██╗███╗   ██╗";
	XWin[1] = L"╚██╗██╔╝     ██║    ██║██║████╗  ██║";
	XWin[2] = L" ╚███╔╝      ██║ █╗ ██║██║██╔██╗ ██║";
	XWin[3] = L" ██╔██╗      ██║███╗██║██║██║╚██╗██║";
	XWin[4] = L"██╔╝ ██╗     ╚███╔███╔╝██║██║ ╚████║";
	XWin[5] = L"╚═╝  ╚═╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	wstring Draw[6];
	Draw[0] = L"██████╗ ██████╗  █████╗ ██╗    ██╗";
	Draw[1] = L"██╔══██╗██╔══██╗██╔══██╗██║    ██║";
	Draw[2] = L"██║  ██║██████╔╝███████║██║ █╗ ██║";
	Draw[3] = L"██║  ██║██╔══██╗██╔══██║██║███╗██║";
	Draw[4] = L"██████╔╝██║  ██║██║  ██║╚███╔███╔╝";
	Draw[5] = L"╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ";

	wstring OWin[6];
	OWin[0] = L" ██████╗     ██╗    ██╗██╗███╗   ██╗";
	OWin[1] = L"██╔═══██╗    ██║    ██║██║████╗  ██║";
	OWin[2] = L"██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║";
	OWin[3] = L"██║   ██║    ██║███╗██║██║██║╚██╗██║";
	OWin[4] = L"╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║";
	OWin[5] = L" ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++)
		{
			
			gotoxy(82 + 25, 25 + 4 + j);
			if (n == -1) wcout << XWin[j];
			if (n == 0) wcout << Draw[j];
			if (n == 1) wcout << OWin[j];
			Sleep(200);

		}
		Sleep(200);
		for (int j = 0; j < 6; j++)
		{
			gotoxy(82 + 25, 25 + 4 + j);
			wcout << "                                    ";
			Sleep(100);

		}
	}
	
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	
	
}


char turnCheck(unsigned int turn) { //self explainatory
	if (turn % 2 == 0) {
		return PLAYER1;
	}
	else { 
		return PLAYER2;
	}
}

void Save() {
save:
	system("cls");
	string filename;
	gotoxy(79, 32);
	cout << "Nhap ten file de save: ";
	cin >> filename;
	gotoxy(79, 32);
	cout << "                                                             ";
	ifstream file;
	ofstream fileInput;
	file.open("./save/" + filename + ".txt");
	if (file) {
		system("cls");
		gotoxy(79, 32);
		cout << "File da ton tai, co muon xoa file cu ko? Y/N ";
		switch (_getch()) {
		case 'y':
			file.close();
			fileInput.open("./save/" + filename + ".txt", ios::out);
			fileInput << _x << " " << _y << " " << turnx << " " << turno << " " << turnCheck(turn) << " " << turnCheck(turn + 1);
			for (int j = 0; j < BOARD_SIZE; j++) {
				for (int k = 0; k < BOARD_SIZE; k++) {
					fileInput << board[k][j];
				}
			}
			fileInput.close();
			break;
		case 'n':
			goto save;
		}
		return;
	}
	else {
		file.close();
		fileInput.open("./save/" + filename + ".txt", ios::out);
		fileInput << _x << " " << _y << " " << turnx << " " << turno << " " << turnCheck(turn) << " " << turnCheck(turn + 1);
		for (int j = 0; j < BOARD_SIZE; j++) {
			for (int k = 0; k < BOARD_SIZE; k++) {
				fileInput << board[k][j];
			}
		}
		fileInput.close();
		return;
	}
}

void Load() {
	string filename;
	gotoxy(79, 32);
	cout << "Nhap ten de load: ";
	cin >> filename;
	ifstream file;
	file.open("./save/" + filename + ".txt");

	while (true) {
		if (!file) {
			system("cls");
			gotoxy(79, 32);
			cout << "File khong ton tai, vui long nhap lai:";
			cin >> filename;
			file.open("./save/" + filename + ".txt");
		}
		else
		{
			file >> _x >> _y >> turnx >> turno >> PLAYER1 >> PLAYER2;
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					file >> noskipws >> board[j][i];
				}
			}
			board_states.push_back(board);
			break;
		}
	}
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
		switch (_getch()) { //keyboard input

		case 'w': //up
			goXO();
			_y--;
			if (_y < 0) { _y++; }
			break;

		case 's': //down
			goXO();
			_y++;
			if (_y >= BOARD_SIZE) { _y--; }
			break;

		case 'a': //left
			goXO();
			_x--;
			if (_x < 0) { _x++; }
			break;

		case 'd': //right
			goXO();
			_x++;
			if (_x >= BOARD_SIZE) { _x--; }
			break;

		case '\r': //marking the spot
			enterXO();
			mark();
			break;

		case 'u': //undo button
			Undo();
			break;

		case 72:
			goXO();
			_y--;
			if (_y < 0) { _y++; }
			break;

		case 80:
			goXO();
			_y++;
			if (_y >= BOARD_SIZE) { _y--; }
			break;

		case 75:
			goXO();
			_x--;
			if (_x < 0) { _x++; }
			break;

		case 77:
			goXO();
			_x++;
			if (_x >= BOARD_SIZE) { _x--; }
			break;

		case 32: //spacebar for marking
			enterXO();
			mark();
			break;

		case 'p': //save button
			Save();
			drew = false;
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

void drawBoard() {
	color(116);
	int Max_i = BOARD_SIZE * 2;
	int Max_j = BOARD_SIZE * 4;
	//Effect
	gotoxy(LEFT, TOP);
	cout << LEFT_TOP << HORIZONTAL_LINE;
	gotoxy(LEFT + Max_j, TOP + Max_i);
	cout << RIGHT_BOTTOM;
	int j = 1;
	for (int i = 1; j < Max_j / 2; i++, j++) {

		gotoxy(LEFT + 2 * j, TOP);
		cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
		gotoxy(LEFT, TOP + i);
		cout << VERTICAL_LINE;

		gotoxy(LEFT + Max_j - 2 * j, TOP + Max_i);
		cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
		gotoxy(LEFT + Max_j, TOP + Max_i - i);
		cout << VERTICAL_LINE;

		Sleep(25);
	}
	//Draw board
	for (int i = 0; i <= Max_i; i++) {
		gotoxy(LEFT, TOP + i);
		for (int j = 0; j <= Max_j; j++) {
			if (i == 0) {
				if (j == 0) cout << LEFT_TOP;
				else if (j == Max_j) cout << RIGHT_TOP;
				else if (j % 4 == 0) cout << T_SHAPE_DOWN;
				else cout << HORIZONTAL_LINE;
			}
			else if (i == Max_i) {
				if (j == 0) cout << LEFT_BOTTOM;
				else if (j == Max_j) cout << RIGHT_BOTTOM;
				else if (j % 4 == 0) cout << T_SHAPE_UP;
				else cout << HORIZONTAL_LINE;
			}
			else if (i % 2 == 0) {
				if (j == 0) cout << T_SHAPE_RIGHT;
				else if (j == Max_j) cout << T_SHAPE_LEFT;
				else if (j % 4 == 0) cout << CROSS;
				else cout << HORIZONTAL_LINE;
			}
			else {
				if (j % 4 == 0) cout << VERTICAL_LINE;
				else cout << " ";
			}
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

void Loading() {
	system("cls");
	gotoxy(42, 14); cout << "LOADING ";
	for (int i = 0; i < 3; i++) {
		cout << ". "; Sleep(300);
	}
	system("cls");

}

bool checkDraw() {
	if (turnx + turno == 225 && win_state != true) {
		return true;
	}
	return false;
}

void resetData() {
	system("cls");
	while (board_states.size() > 1){
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
	undo = false;
}
void game() {
gomoku:
	system("cls");
	drawBoard();
	drew = true;
	while (win_state != true && checkDraw() != true) {
		if (drew == false) goto gomoku;
		input();
		drawMarks();
		turnCheck(turn);
		checkWin();
	}
	if (win_state == true) {
		if (turnCheck(turn + 1) == 'X') {
			winsound();
			DrawWin(-1);
		}
		else {
			winsound();
			DrawWin(1);
		}
	}
	else if (checkDraw() == true) {
		winsound();
		DrawWin(0);
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
	system("cls");
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