#include "console.h"
#include "menu.h"
#include <cstdlib> 

using namespace std;

int main() {
	setupConsole();
gomoku:
	switch (Menu())
	{
	case 1:
		return 1;
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