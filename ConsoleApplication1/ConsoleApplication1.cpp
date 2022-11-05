// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Windows.h>
#include<conio.h>
#include "gamemap.h"
#include "snake.h"

using namespace std;
void setup() {
    

}
void clear_screen(char fill = ' ') {
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}
void input(snake &mysnk) {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (mysnk.MYDIR == snake::direction::WEST) {
                //invalid move
                break;
            }
            mysnk.MYDIR = snake::direction::EAST;
            break;
        case 'd':
            if (mysnk.MYDIR == snake::direction::EAST) {
                //invalid move
                break;
            }
            mysnk.MYDIR = snake::direction::WEST;
            break;
        case 'w':
            if (mysnk.MYDIR == snake::direction::SOUTH) {
                //invalid move
                break;
            }
            mysnk.MYDIR = snake::direction::NORTH;
            break;
        case 's':
            if (mysnk.MYDIR == snake::direction::NORTH) {
                //invalid move
                break;
            }
            mysnk.MYDIR = snake::direction::SOUTH;
            break;
        default:
            break;
         }
    }
}
int main()
{
    gamemap recmap(30, 30);
    snake mysnk(recmap.height, recmap.width);
    while (true) {
        //clear_screen();
        system("cls");
        recmap.printMap(mysnk.coordinates,mysnk.length,mysnk.score);
        input(mysnk);
        mysnk.updateCoordinates(recmap);
        if (mysnk.bittenSelf) {
            return 0;
        }
        Sleep(200);
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
