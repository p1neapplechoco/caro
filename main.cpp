#include "console.h"
#include "menu.h"
#include "game.h"

using namespace std;

int main() {
Menu:
	setupConsole();
	switch (Menu())
	{
	case 1:
		gomoku();
		goto Menu;
	case 2:
		Option();
		goto Menu;
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