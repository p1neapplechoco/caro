#include "console.h"
#include "menu.h"
#include "game.h"
#include "about.h"
#include<conio.h>
#include "help.h"

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
		Help();
		while (1) {
			if (_getch() == 13) {
				goto Menu;
			}
		}
	case 4:
		About();
		while (1) {
			if (_getch() == 13) {
				goto Menu;
			}
		}
			
		
	case 5:
		return 1;
	default:
		break;
	}
}