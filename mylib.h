#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

 void setColor(int color) {
    SetConsoleTextAttribute(h, color);
}

 void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

 void drawBox(int x, int y, string content, int color = 7) {
    setColor(color);
    gotoxy(x, y);     cout << "+---+";
    gotoxy(x, y + 1); cout << "| " << setw(2) << content << " |";
    gotoxy(x, y + 2); cout << "+---+";
    setColor(7);
}

#endif
