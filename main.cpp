#include "console.h"
#include "menu.h"
#include "game.h"
#include <cstdlib> 

using namespace std;

int main() {
gomoku:
	setupConsole();
	switch (Menu())
	{
	case 1:
		gomoku();
		return 0;
	case 2:
		Option();
		goto gomoku;
	case 3:
		return 1;
	case 4:
		return 1;
	case 5:
		return 1;
	default:
		break;
	}
}