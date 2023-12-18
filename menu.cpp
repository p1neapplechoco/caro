#include "menu.h"
#include "game.h"
#include "settings.h"


using namespace std;

int Menu() 
    {
   
        system("cls");
        logo();
        drawMenu();
        int Set[] = { 116,116,116,116,116 };
        string options[] = { "        PLAY         ", "       OPTION        ", "        HELP         ", "       CREDIT        ", "        EXIT         " };
        int counter = 1;
        char key;
     
        for (int i = 0;;)
        {
            
            gotoxy(67, 18);
            cout << options[0];
           
            gotoxy(67, 23);
            cout << options[1];
            
            gotoxy(67, 28);
            cout << options[2];
            
            gotoxy(67, 33);
            cout << options[3];
            
            gotoxy(67, 38);
            
            cout << options[4];
            

            key = _getch();

            if ((key == 72 || key == 'w' || key == 'W') && (counter >= 2 && counter <= 5))
            {
               
                counter--;
            }
            if ((key == 80 || key == 's' || key == 'S') && (counter >= 1 && counter <= 4))
            {
               
                counter++;
            }
            if (key == '\r' || key == ' ')
            {
               
                return counter;
            }

            Set[0] = 116;
            Set[1] = 116;
            Set[2] = 116;
            Set[3] = 116;
            Set[4] = 116;

            options[0] = "        PLAY         ";
            options[1] = "       OPTION        ";
            options[2] = "        HELP         ";
            options[3] = "       CREDIT        ";
            options[4] = "        EXIT         ";

            if (counter == 1)
            {
                Set[0] = 117;
                select1();
                options[0] = "     >> PLAY <<      ";
            }
            if (counter == 2)
            {
                Set[1] = 117;
                select1();
                options[1] = "    >> OPTION <<     ";
            }
            if (counter == 3)
            {
                Set[2] = 117;
                select1();
                options[2] = "     >> HELP <<      ";
            }
            if (counter == 4)
            {
                Set[3] = 117;
                select1();
                options[3] = "    >> CREDIT <<     ";
            }
            if (counter == 5)
            {
                Set[4] = 117;
                select1();
                options[4] = "     >> EXIT <<      ";
            }
        }
    }

