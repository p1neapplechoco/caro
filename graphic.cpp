#include "graphic.h"

using namespace std;

void logo() {
    color(112);
    gotoxy(42, 5);
    cout << "   мллллллм   мллллллм    ммммлллмммм    мллллллм     мл   млм ллл    лм  ";
    gotoxy(42, 6);
    cout << "  ллл    ллл ллл    ллл мллппплллпппллм ллл    ллл   ллл млллп ллл    ллл ";
    gotoxy(42, 7);
    cout << "  ллл    лп  ллл    ллл ллл   ллл   ллл ллл    ллл   лллоллп   ллл    ллл ";
    gotoxy(42, 8);
    cout << " мллл        ллл    ллл ллл   ллл   ллл ллл    ллл  млллллп    ллл    ллл ";
    gotoxy(42, 9);
    cout << "ппллл ллллм  ллл    ллл ллл   ллл   ллл ллл    ллл пплллллм    ллл    ллл ";
    gotoxy(42, 10);
    cout << "  ллл    ллл ллл    ллл ллл   ллл   ллл ллл    ллл   лллоллм   ллл    ллл ";
    gotoxy(42, 11);
    cout << "  ллл    ллл ллл    ллл ллл   ллл   ллл ллл    ллл   ллл плллм ллл    ллл ";
    gotoxy(42, 12);
    cout << "  ллллллллп   пллллллп   пл   ллл   лп   пллллллп    ллл   плп ллллллллп  ";
    gotoxy(42, 13);
    cout << "                                                     п                    ";
}

int GameMode()
{
    system("cls");
    logo();
    int Set[] = { 116,116,116,116,116 };
    string options[] = { "|      NEW GAME       |", "|        LOAD         |", "|        EXIT         |" };
    int counter = 1;
    char key;

    for (int i = 0;;)
    {
        gotoxy(67, 16);
        color(Set[0]);
        cout << " _____________________ ";
        gotoxy(67, 17);
        cout << "|                     |";
        gotoxy(67, 18);
        cout << options[0];
        gotoxy(67, 19);
        cout << "|_____________________|";

        gotoxy(67, 21);
        color(Set[1]);
        cout << " _____________________ ";
        gotoxy(67, 22);
        cout << "|                     |";
        gotoxy(67, 23);
        cout << options[1];
        gotoxy(67, 24);
        cout << "|_____________________|";

        gotoxy(67, 26);
        color(Set[2]);
        cout << " _____________________ ";
        gotoxy(67, 27);
        cout << "|                     |";
        gotoxy(67, 28);
        cout << options[2];
        gotoxy(67, 29);
        cout << "|_____________________|";

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2))
        {
            counter++;
        }
        if (key == '\r')
        {
            return counter;
        }

        Set[0] = 116;
        Set[1] = 116;
        Set[2] = 116;

        options[0] = "|      NEW GAME       |";
        options[1] = "|        LOAD         |";
        options[2] = "|        EXIT         |";

        if (counter == 1)
        {
            Set[0] = 117;
            options[0] = "|   >> NEW GAME <<    |";
        }
        if (counter == 2)
        {
            Set[1] = 117;
            options[1] = "|     >> LOAD <<      |";
        }
        if (counter == 3)
        {
            Set[2] = 117;
            options[2] = "|     >> EXIT <<      |";
        }
    }
}