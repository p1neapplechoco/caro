#include "menu.h"

using namespace std;

int Menu() 
    {
        system("cls");
        logo();
        int Set[] = { 116,116,116,116,116 };
        string options[] = { "|        PLAY         |", "|       OPTION        |", "|        HELP         |", "|       CREDIT        |", "|        EXIT         |" };
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

            gotoxy(67, 31);
            color(Set[3]);
            cout << " _____________________ ";
            gotoxy(67, 32);
            cout << "|                     |";
            gotoxy(67, 33);
            cout << options[3];
            gotoxy(67, 34);
            cout << "|_____________________|";

            gotoxy(67, 36);
            color(Set[4]);
            cout << " _____________________ ";
            gotoxy(67, 37);
            cout << "|                     |";
            gotoxy(67, 38);
            cout << options[4];
            gotoxy(67, 39);
            cout << "|_____________________|";

            key = _getch();

            if (key == 72 && (counter >= 2 && counter <= 5))
            {
                counter--;
            }
            if (key == 80 && (counter >= 1 && counter <= 4))
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
            Set[3] = 116;
            Set[4] = 116;

            options[0] = "|        PLAY         |";
            options[1] = "|       OPTION        |";
            options[2] = "|        HELP         |";
            options[3] = "|       CREDIT        |";
            options[4] = "|        EXIT         |";

            if (counter == 1)
            {
                Set[0] = 117;
                options[0] = "|     >> PLAY <<      |";
            }
            if (counter == 2)
            {
                Set[1] = 117;
                options[1] = "|    >> OPTION <<     |";
            }
            if (counter == 3)
            {
                Set[2] = 117;
                options[2] = "|     >> HELP <<      |";
            }
            if (counter == 4)
            {
                Set[3] = 117;
                options[3] = "|    >> CREDIT <<     |";
            }
            if (counter == 5)
            {
                Set[4] = 117;
                options[4] = "|     >> EXIT <<      |";
            }


        }
    }

int Option() {
    system("cls");

    int Set[] = { 2,2,2,2,2 };
    int counter = 1;
    char key;

    for (int i = 0;;)
    {


        gotoxy(10, 5);
        color(Set[0]);
        cout << "Sound: ";

        gotoxy(10, 6);
        color(Set[1]);
        cout << "Music: ";

        gotoxy(10, 7);
        color(Set[2]);
        cout << "Two-side-blocked mode: ";


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

        Set[0] = 2;
        Set[1] = 2;
        Set[2] = 2;
        Set[3] = 2;
        Set[4] = 2;

        if (counter == 1)
        {
            Set[0] = 11;
        }
        if (counter == 2)
        {
            Set[1] = 11;
        }
        if (counter == 3)
        {
            Set[2] = 11;

        }
    }
}

