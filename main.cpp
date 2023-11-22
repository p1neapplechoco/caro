#include "console.h"
#include "menu.h"
#include "game.h"
#include "about.h"
#include <conio.h>
#include "help.h"
#include "settings.h"



using namespace std;

int main() {
Menu:
	backgroundmusic();
	setupConsole();
	switch (Menu())
	{
	case 1:
		select();
		Loading();
		gomoku();
		goto Menu;
	case 2:
		select();
		Loading();
		Setting();
		goto Menu;
	case 3:
		select();
		Loading();
		Help();
		while (1) {
			if (_getch() == 13) {
				Loading();
				goto Menu;
			}
		}
	case 4:
		select();
		Loading();
		About();
		while (1) {
			if (_getch() == 13) {
				Loading();
				goto Menu;
			}
		}
	case 5:
		select();
		return 1;
	default:
		break;
	}
}