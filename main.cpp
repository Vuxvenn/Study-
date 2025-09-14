#include <iostream>
#include <conio.h>
#include "mylib.h"
using namespace std;

int MAX_SIZE;
int *arr;
int top1 = -1;
int top2;

void drawStacks() {
    int y = 15;
    int x = 5;

    for (int i = 0; i < MAX_SIZE; i++) {
        drawBox(x + i * 6, y, " ");
    }

    for (int i = 0; i <= top1; i++) {
        drawBox(x + i * 6, y, to_string(arr[i]), 10);
    }

    for (int i = MAX_SIZE - 1; i >= top2; i--) {
        drawBox(x + i * 6, y, to_string(arr[i]), 12);
    }
}

void printMenu(const char* menuItems[], int menuSize, int selected) {
    gotoxy(0, 0);
    setColor(14);
    cout << "===== MENU 2 STACK CHUNG MANG =====\n";
    setColor(7);

    for (int i = 0; i < menuSize; i++) {
        if (i == selected) {
            setColor(11);
            cout << " > " << menuItems[i] << endl;
            setColor(7);
        } else {
            cout << "   " << menuItems[i] << endl;
        }
    }
    
    cout << "==================================" << endl;
}

bool push1(int val) {
    if (top1 + 1 == top2) return false;
    arr[++top1] = val;
    return true;
}

bool push2(int val) {
    if (top2 - 1 == top1) return false;
    arr[--top2] = val;
    return true;
}

bool pop1() {
    if (top1 >= 0) { top1--; return true; }
    return false;
}

bool pop2() {
    if (top2 < MAX_SIZE) { top2++; return true; }
    return false;
}

int main() {
    system("cls");
    cout << "Nhap kich thuoc stack: ";
    cin >> MAX_SIZE;

    arr = new int [MAX_SIZE];
    top2 = MAX_SIZE;

    const char* menuItems[] = {
        "Push Stack1",
        "Push Stack2",
        "Pop  Stack1",
        "Pop  Stack2",
        "Thoat"
    };
    const int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);

    int selected = 0;
    bool running = true;

    while (running) {
        printMenu(menuItems, menuSize, selected);
        drawStacks();

        int key = getch();
        if (key == 224) { 
            key = getch();
            if (key == 72) selected = (selected - 1 + menuSize) % menuSize; 
            if (key == 80) selected = (selected + 1) % menuSize; 
        } 
        else if (key == 13) { 
            gotoxy(0, 10);
            cout << string(50, ' ') << "\r";
            if (selected == 0) {
                cout << "Nhap so: ";
                int x; cin >> x;
                if (!push1(x)) cout << "Het bo nho!";
            } else if (selected == 1) {
                cout << "Nhap so: ";
                int x; cin >> x;
                if (!push2(x)) cout << "Het bo nho!";
            } else if (selected == 2) {
                if (!pop1()) cout << "Stack1 rong!";
            } else if (selected == 3) {
                if (!pop2()) cout << "Stack2 rong!";
            } else if (selected == 4) {
                running = false;
            }
        }
    }
    delete[] arr;
    return 0;
}
