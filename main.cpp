#include "console.h"
#include "menu.h"
#include "game.h"
#include "about.h"
#include <conio.h>
#include "help.h"
#include "settings.h"

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
		Setting();
		goto Menu;
	case 3:
		select();
		Help();
		while (1) {
			if (_getch() == 27) {
				
				goto Menu;
			}
		}
	case 4:
		select();
		About();
		while (1) {
			if (_getch() == 27) {
				
				goto Menu;
			}
		}
	case 5:
		select();
		Exit();
		return 1;
	default:
		break;
	}
}