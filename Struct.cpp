#include"Struct.h"
#include "ConsoleSettings.h"
#include<iostream>
using namespace std;

char box[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
};

void CELL_1::drawBox(int color) {
    if (!isValid)
        return;

    int x = j + 1, y = i + 1;

    for (int i = 0; i < 5; i++) {
        goToXY(x * 10, y * 4 + i);
        cout << box[i];
    }

    if (isSelected) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (c % 6 + 1)); // white background
        for (int i = 1; i < 4; i++) {
            goToXY(x * 10 + 1, y * 4 + i);
            cout << "         ";
        }

        goToXY(x * 10 + 5, y * 4 + 2);
        cout << c;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        goToXY(x * 10 + 5, y * 4 + 2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c % 6 + 1);
        cout << c;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void CELL_1::deleteBox() {
    int x = j + 1, y = i + 1;

    for (int i = 0; i < 5; i++) {
        goToXY(x * 10, y * 4 + i);
        cout << "           ";
    }
}

void CELL_2::drawBox(int color) {
    int x = j + 1, y = i + 1;

    for (int i = 0; i < 5; i++) {
        goToXY(x * 10, y * 4 + i);
        cout << box[i];
    }

    if (isSelected) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (c % 6 + 1)); // white background
        for (int i = 1; i < 4; i++) {
            goToXY(x * 10 + 1, y * 4 + i);
            cout << "         ";
        }

        goToXY(x * 10 + 5, y * 4 + 2);
        cout << c;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        goToXY(x * 10 + 5, y * 4 + 2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c % 6 + 1);
        cout << c;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void CELL_2::deleteBox() {
    int x = j + 1, y = i + 1;

    for (int i = 0; i < 5; i++) {
        goToXY(x * 10, y * 4 + i);
        cout << "           ";
    }
}