#include "graphic.h"
#include "game.h"
#include "console.h"
#include "data.h"
#include "settings.h"

#define MAX_CAP 10
#define EMPTY ' ' //when no one has marked the thing

using namespace std;

bool drew = false;
int cpu_player = false;
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
	getline(cin, filename);
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
			fileInput << cpu_player << " " << _x << " " << _y << " " << turnx << " " << turno << " " << turnCheck(turn) << " " << turnCheck(turn + 1);
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
		fileInput << cpu_player << " " << _x << " " << _y << " " << turnx << " " << turno << " " << turnCheck(turn) << " " << turnCheck(turn + 1) << " " << xscore << " " << oscore << " ";
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
		getline(file, loadName[i]);
	file.close();
}

void Load() { //loading
	DrawListLoad(loadName);
	string filename;
	filename = getLoadName(loadName,isLoad);
	if (isLoad == true) {
		ifstream file;
		file.open("./save/" + filename + ".txt");
		file >> cpu_player >> _x >> _y >> turnx >> turno >> PLAYER1 >> PLAYER2 >> xscore >> oscore;
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
	if (cpu_player == 0) {
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
	else {
		if (turn > 2) {
			board_states.pop_back();
			board_states.pop_back();
			turn -= 2;
			turnx--;
			turno--;
			undo = true;
		}
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
				drawGame(turnCheck(turn + +1), cpu_player);
				DrawTurn((int)(turnCheck(turn) == PLAYER1));
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				break;
			case 2:
				Setting();
				drawGame(turnCheck(turn + +1), cpu_player);
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
				drawGame(turnCheck(turn + +1), cpu_player);
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
	cpu_player = 0;
	drawGame(turnCheck(turn + +1), cpu_player);
	DrawTurn((int)(turnCheck(turn) == PLAYER1));
	gotoxy(FLeft + 13, FTop + 11);
	cout << "PLAYER 1";
	gotoxy(FLeft + 65, FTop + 11);
	cout << "PLAYER 2";
	DrawScore(xscore, FLeft + 30, FTop + 13);
	DrawScore(oscore, FLeft + 50, FTop + 13);
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

	while (!isExit) {
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


// Phan choi che do hard
int AttackArr[10] = { 0, 3, 24, 192, 1536, 12288, 98304, 531441, 4782969, 500000000 };
int DefendArr[10] = { 0, 2, 18, 140, 800, 8000, 70569, 350000, 30000000, 300000000 };

bool ischan(int x, int y) {
	return ((x < 0) || (x > BOARD_SIZE - 1) || (y < 0) || (y > BOARD_SIZE - 1));
}

int AttackPoint(int x, int y) {

	int tX[8] = { 1,0,1,1,-1,0,-1,-1 };
	int tY[8] = { 0,1,1,-1,0,-1,-1,1 };
	int Ally[4]{}, Enemy[4]{}, Block[4]{};
	for (int k = 0; k < 8; k++) {
		for (int i = 1; i < 6; i++) {

			if (ischan(x + i * tX[k], y + i * tY[k])) {
				Block[k % 4]++;
				break;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == EMPTY) break;

			if (board[x + i * tX[k]][y + i * tY[k]] == 'O') {
				Ally[k % 4]++;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == 'X') {
				Enemy[k % 4]++;
				break;
			}
		}
	}

	int SumPoint = 0;
	for (int i = 0; i < 4; i++) {
		int Point = AttackArr[Ally[i]];

		//Mình có 4 con, ưu tiên đánh
		if (Ally[i] == 4) Point = AttackArr[9];
		else Point = AttackArr[Ally[i] * 2];
		//Bị chặn thì giảm điểm
		if (Enemy[i] == 1 || Block[i] == 1) Point /= 2;

		//Bị chặn hai đầu thì không đánh
		if (
			Enemy[i] == 1 &&
			Ally[i] < 4 &&
			Block[i] == 1
			) Point = 0;
		if (Enemy[i] == 2) Point = 0;
		SumPoint += Point;
	}

	return SumPoint;
}

int DefendPoint(int x, int y) {
	int tX[8] = { 1,0,1,1,-1,0,-1,-1 };
	int tY[8] = { 0,1,1,-1,0,-1,-1,1 };
	int Ally[4]{}, Enemy[4]{}, Block[4]{};

	for (int k = 0; k < 8; k++) {
		for (int i = 1; i < 6; i++) {
			if (ischan(x + i * tX[k], y + i * tY[k])) {
				Block[k % 4]++;
				break;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == EMPTY) break;

			if (board[x + i * tX[k]][y + i * tY[k]] == 'X') {
				Enemy[k % 4]++;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == 'O') {
				Ally[k % 4]++;
				break;
			}
		}
	}

	int SumPoint = 0;
	for (int i = 0; i < 4; i++) {
		int Point = DefendArr[Enemy[i]];

		//Địch có 4 con, ưu tiên chặn
		if (Enemy[i] == 4) Point = DefendArr[9];
		else Point = DefendArr[Enemy[i] * 2];
		//Bị chặn thì giảm điểm
		if ((Ally[i] == 1) || (Block[i] == 1)) Point /= 2;

		//Bị chặn hai đầu thì điểm bằng 0
		if (
			Ally[i] == 1 &&
			Enemy[i] < 4 &&
			Block[i] == 1
			) Point = 0;
		if (Ally[i] == 2) Point = 0;
		SumPoint += Point;
	}

	return SumPoint;
}

_POINT computer_Turn() {

	_POINT result;

	result = { 0,0, EMPTY };
	int thisMakeCPNotStupid = 0;
	int MaxPoint = -DefendArr[9];
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == EMPTY)
			{
				thisMakeCPNotStupid++;
				//Chọn r ngẫu nhiên, tăng tính ngẫu nhiên
				int r = rand() % 2;
				int Point = AttackPoint(i, j) + DefendPoint(i, j);

				//Lấy tổng điểm lớn nhất (MaxPoint), đánh vào đó
				if (
					MaxPoint < Point ||
					(
						MaxPoint == Point &&
						r == 0
						)
					) {
					MaxPoint = Point;
					result.x = i;
					result.y = j;
					result.c = 'O';
				}
			}
		}
	}
	if (thisMakeCPNotStupid == BOARD_SIZE * BOARD_SIZE) {
		result.x = 5;
		result.y = 6;
		result.c = 'O';
	}
	return result;
}
struct cpu {
	int x;
	int y;
};
cpu maydanhhard()
{
	_POINT id = computer_Turn();
	return { id.x, id.y };

}
void computer_mark() {
	if (board[_x][_y] == EMPTY) {
		if (turnCheck(turn) == PLAYER1)
		{
			board[_x][_y] = 'X';
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
			drawMarks();
			turnCheck(turn);
			checkWin();
			if (win_state == true) 
			{
				board[_x][_y] = 'X';
					xscore++;
					EraseScore(FLeft + 30, FTop + 13);
					DrawScore(xscore, FLeft + 30, FTop + 13);
					DrawScore(oscore, FLeft + 50, FTop + 13);
					winsound();
					color(113);
					DrawWin(-1);
					return;

			}
			else if (checkDraw() == true) {
				winsound();
				DrawWin(0);
				return;
			}
			else if (isExit == true) {
				return;
			}
			cpu toado = maydanhhard();
			_x = toado.x;
			_y = toado.y;
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
			drawMarks();
			turnCheck(turn);
			checkWin();
			if (win_state == true) 
			{
					oscore++;
					winsound();
					EraseScore(FLeft + 50, FTop + 13);
					DrawScore(xscore, FLeft + 30, FTop + 13);
					DrawScore(oscore, FLeft + 50, FTop + 13);
					color(114);
					DrawWin(1);
					return;
			}
			else if (checkDraw() == true) {
				winsound();
				DrawWin(0);
				return;
			}
			else if (isExit == true) {
				return;
			}
		}
	}
}
void computer_input() {
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
			computer_mark();
			break;

		case 'U': //undo button
			Undo();
			break;

		case 27: //escape quit
			switch (Pause()) {
			case 1:
				drawGame(turnCheck(turn + +1), cpu_player);
				DrawTurn((int)(turnCheck(turn) == PLAYER1));
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				break;
			case 2:
				Setting();
				drawGame(turnCheck(turn + +1), cpu_player);
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
				drawGame(turnCheck(turn + +1), cpu_player);
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
void hard() {
gomoku:
	cpu_player = 1;
	drawGame(turnCheck(turn + +1), cpu_player);
	DrawTurn((int)(turnCheck(turn) == PLAYER1));
	gotoxy(FLeft + 13, FTop + 11);
	cout << "PLAYER";
	gotoxy(FLeft + 65, FTop + 11);
	cout << "COMPUTER";
	DrawScore(xscore, FLeft + 30, FTop + 13);
	DrawScore(oscore, FLeft + 50, FTop + 13);
	drew = true;
	while (win_state != true && checkDraw() != true && isExit != true) {
		if (drew == false) goto gomoku;
		computer_input();
		drawMarks();
		turnCheck(turn);
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
// Phan choi che do easy
int AttackArr2[10] = { 0, 3, 5, 75, 479, 7500, 50, 1011, 10069, 20000 };
int DefendArr2[10] = { 0, 2, 18, 100, 500, 800, 350, 1000, 20000, 1000 };

int AttackPoint2(int x, int y) {

	int tX[8] = { 1,0,1,1,-1,0,-1,-1 };
	int tY[8] = { 0,1,1,-1,0,-1,-1,1 };
	int Ally[4]{}, Enemy[4]{}, Block[4]{};
	for (int k = 0; k < 8; k++) {
		for (int i = 1; i < 6; i++) {

			if (ischan(x + i * tX[k], y + i * tY[k])) {
				Block[k % 4]++;
				break;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == EMPTY) break;

			if (board[x + i * tX[k]][y + i * tY[k]] == 'O') {
				Ally[k % 4]++;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == 'X') {
				Enemy[k % 4]++;
				break;
			}
		}
	}

	int SumPoint = 0;
	for (int i = 0; i < 4; i++) {
		int Point = AttackArr2[Ally[i]];

		//Mình có 4 con, ưu tiên đánh
		if (Ally[i] == 4) Point = AttackArr2[9];
		else Point = AttackArr2[Ally[i] * 2];
		//Bị chặn thì giảm điểm
		if (Enemy[i] == 1 || Block[i] == 1) Point /= 2;

		//Bị chặn hai đầu thì không đánh
		if (
			Enemy[i] == 1 &&
			Ally[i] < 4 &&
			Block[i] == 1
			) Point = 0;
		if (Enemy[i] == 2) Point = 0;
		SumPoint += Point;
	}

	return SumPoint;
}

int DefendPoint2(int x, int y) {
	int tX[8] = { 1,0,1,1,-1,0,-1,-1 };
	int tY[8] = { 0,1,1,-1,0,-1,-1,1 };
	int Ally[4]{}, Enemy[4]{}, Block[4]{};

	for (int k = 0; k < 8; k++) {
		for (int i = 1; i < 6; i++) {
			if (ischan(x + i * tX[k], y + i * tY[k])) {
				Block[k % 4]++;
				break;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == EMPTY) break;

			if (board[x + i * tX[k]][y + i * tY[k]] == 'X') {
				Enemy[k % 4]++;
			}

			if (board[x + i * tX[k]][y + i * tY[k]] == 'O') {
				Ally[k % 4]++;
				break;
			}
		}
	}

	int SumPoint = 0;
	for (int i = 0; i < 4; i++) {
		int Point = DefendArr2[Enemy[i]];

		//Địch có 4 con, ưu tiên chặn
		if (Enemy[i] == 4) Point = DefendArr2[9];
		else Point = DefendArr2[Enemy[i] * 2];
		//Bị chặn thì giảm điểm
		if ((Ally[i] == 1) || (Block[i] == 1)) Point /= 2;

		//Bị chặn hai đầu thì điểm bằng 0
		if (
			Ally[i] == 1 &&
			Enemy[i] < 4 &&
			Block[i] == 1
			) Point = 0;
		if (Ally[i] == 2) Point = 0;
		SumPoint += Point;
	}

	return SumPoint;
}

_POINT computer_Turn2() {

	_POINT result;

	result = { 0,0, EMPTY };
	int thisMakeCPNotStupid = 0;
	int MaxPoint = -DefendArr2[9];
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == EMPTY)
			{
				thisMakeCPNotStupid++;
				//Chọn r ngẫu nhiên, tăng tính ngẫu nhiên
				int r = rand() % 2;
				int Point = AttackPoint2(i, j) + DefendPoint2(i, j);

				//Lấy tổng điểm lớn nhất (MaxPoint), đánh vào đó
				if (
					MaxPoint < Point ||
					(
						MaxPoint == Point &&
						r == 0
						)
					) {
					MaxPoint = Point;
					result.x = i;
					result.y = j;
					result.c = 'O';
				}
			}
		}
	}
	if (thisMakeCPNotStupid == BOARD_SIZE * BOARD_SIZE) {
		result.x = 5;
		result.y = 6;
		result.c = 'O';
	}
	return result;
}
cpu maydanheasy()
{
	_POINT id = computer_Turn2();
	return { id.x, id.y };

}
void computer_mark2() {
	if (board[_x][_y] == EMPTY) {
		if (turnCheck(turn) == PLAYER1)
		{
			board[_x][_y] = 'X';
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
			drawMarks();
			turnCheck(turn);
			checkWin();
			if (win_state == true)
			{
				board[_x][_y] = 'X';
				xscore++;
				EraseScore(FLeft + 30, FTop + 13);
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				winsound();
				color(113);
				DrawWin(-1);
				return;

			}
			else if (checkDraw() == true) {
				winsound();
				DrawWin(0);
				return;
			}
			else if (isExit == true) {
				return;
			}
			cpu toado = maydanheasy();
			_x = toado.x;
			_y = toado.y;
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
			drawMarks();
			turnCheck(turn);
			checkWin();
			if (win_state == true)
			{
				oscore++;
				winsound();
				EraseScore(FLeft + 50, FTop + 13);
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				color(114);
				DrawWin(1);
				return;
			}
			else if (checkDraw() == true) {
				winsound();
				DrawWin(0);
				return;
			}
			else if (isExit == true) {
				return;
			}
		}
	}
}
void computer_input2() {
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
			computer_mark2();
			break;

		case 'U': //undo button
			Undo();
			break;

		case 27: //escape quit
			switch (Pause()) {
			case 1:
				drawGame(turnCheck(turn + +1), cpu_player);
				DrawTurn((int)(turnCheck(turn) == PLAYER1));
				DrawScore(xscore, FLeft + 30, FTop + 13);
				DrawScore(oscore, FLeft + 50, FTop + 13);
				break;
			case 2:
				Setting();
				drawGame(turnCheck(turn + +1), cpu_player);
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
				drawGame(turnCheck(turn + +1), cpu_player);
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
void easy() {
gomoku:
	cpu_player = -1;
	drawGame(turnCheck(turn + +1), cpu_player);
	gotoxy(FLeft + 13, FTop + 11);
	cout << "PLAYER";
	gotoxy(FLeft + 65, FTop + 11);
	cout << "COMPUTER";
	DrawTurn((int)(turnCheck(turn) == PLAYER1));
	DrawScore(xscore, FLeft + 30, FTop + 13);
	DrawScore(oscore, FLeft + 50, FTop + 13);
	drew = true;
	while (win_state != true && checkDraw() != true && isExit != true) {
		if (drew == false) goto gomoku;
		computer_input2();
		drawMarks();
		turnCheck(turn);
	}


	while (!isExit) {
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
	switch (PlayMenu()) {
	case 1:
		resetData();
		xscore = 0;
		oscore = 0;
		switch (GameMode()) {
		case 1:
			easy();
			break;
		case 2:
			hard();
			break;
		case 3:
			game();
			break;
		default:
			break;
		}
		break;
	case 2:
		resetData();
		Load();
		if (isLoad == false) goto GameMode;
		if (cpu_player == 1) hard();
		else if (cpu_player == -1) easy();
		else
		{
			game();
		}
		break;
	case 3:
		return;
		break;
	default:
		break;
	}
}
