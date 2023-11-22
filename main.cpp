#include "console.h"
#include "menu.h"
#include "game.h"
#include "about.h"
#include <conio.h>
#include "help.h"

using namespace std;

int main() {
Menu:
	setupConsole();
	switch (Menu())
	{
	case 1:
		Loading();
		gomoku();
		goto Menu;
	case 2:
		Loading();
		Option();
		goto Menu;
	case 3:
		Loading();
		Help();
		while (1) {
			if (_getch() == 13) {
				Loading();
				goto Menu;
			}
		}
	case 4:
		Loading();
		About();
		while (1) {
			if (_getch() == 13) {
				Loading();
				goto Menu;
			}
		}
			
		
	case 5:
		return 1;
	default:
		break;
	}
}