#include "console.h"

void select() {
	PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void gamemusic() {
	PlaySound(TEXT("Sounds//gamemusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void goXO() {
	PlaySound(TEXT("Sounds//goXO.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void enterXO() {
	PlaySound(TEXT("Sounds//enterXO.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void select1() {
	PlaySound(TEXT("Sounds//select1.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void winsound() {
	PlaySound(TEXT("Sounds//win.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
