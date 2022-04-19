#include "Utility.h"
#include <iostream>
#include<conio.h>

void readLeaderBoard() {
    goToXY(60, 5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "LEADERBOARD";
    goToXY(30, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "NAME";
    goToXY(100, 6);
    cout << "POINT";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    goToXY(30, 7);
    for (int i = 0; i < 75; i++) {
        cout << "=";
    }

    ifstream f;
    f.open("leaderboard.txt");
    if (f) {
        player p;

        int i = 0;
        while (getline(f, p.name, ' ')) {
            f >> p.point;
            f.get();
            goToXY(30, 7 + i);
            for (int j = 0; j < 75; j++) {
                cout << "=";
            }
            if (i <= 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 - i / 2);
            goToXY(30, 8 + i);
            cout << p.name;
            goToXY(100, 8 + i);
            cout << p.point;
            if (i <= 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            i += 2;
        }
        f.close();
    }
    _getch();
    system("cls");
}

void writeLeaderBoard(player p) {
    ifstream fin("leaderboard.txt");
    if (fin) {
        player* list = new player[10];
        int no_player = 0;
        string s;

        while (getline(fin, s, ' ')) {
            list[no_player].name = s;
            fin >> list[no_player].point;
            fin.get();
            no_player++;
        }

        int index = no_player - 1;
        for (index; index >= 0; index--) {
            if (p.point <= list[index].point) {
                break;
            }
        }

        if (no_player < 10) {
            for (int i = no_player; i > index + 1; i--) {
                list[i] = list[i - 1];
            }
            list[index + 1] = p;
            no_player++;
        }
        else {
            if (index != no_player - 1) {
                for (int i = no_player - 1; i > index + 1; i--) {
                    list[i] = list[i - 1];
                }
                list[index + 1] = p;
            }
        }
        fin.close();


        ofstream fout("leaderboard.txt");

        for (int i = 0; i < no_player; i++) {
            fout << list[i].name << " " << list[i].point << endl;
        }

        fout.close();

        delete[]list;
    }
    else {
        ofstream fout("leaderboard.txt");
        fout << p.name << " " << p.point << endl;
        fout.close();
    }
}

void getPlayerInfo(player& p) {
    goToXY(50, 12);
    cout << "Enter player name: ";
    cin >> p.name;
    cin.ignore();
    p.life = 3;
    p.point = 0;
}

void displayStatus(bool win) {
    if (win) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        goToXY(50, 10);
        cout << "__  ______  __  __  _      ______  _  __";
        goToXY(50, 11);
        cout << "\\ \\/ / __ \\/ / / / | | /| / / __ \\/ |/ /";
        goToXY(50, 12);
        cout << " \\  / /_/ / /_/ /  | |/ |/ / /_/ /    /";
        goToXY(50, 13);
        cout << " /_/\\____/\\____/   |__/|__/\\____/_/|_/";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        goToXY(50, 10);
        cout << "__  ______  __  __  __   ____  ________";
        goToXY(50, 11);
        cout << "\\ \\/ / __ \\/ / / / / /  / __ \\/ __/ __/";
        goToXY(50, 12);
        cout << " \\  / /_/ / /_/ / / /__/ /_/ /\\ \\/ _/";
        goToXY(50, 13);
        cout << " /_/\\____/\\____/ /____/\\____/___/___/";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void getBackground(char bg[][41]) {
    ifstream fin("pika.txt");
    if (fin) {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                bg[i][j] = fin.get();
            }
            fin.ignore();
        }
        fin.close();
    }
    else {
        memset(bg, ' ', sizeof(bg));
    }
}

void displayBackground(char bg[][41], int x, int y) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            goToXY((x + 1) * 10 + j, (y + 1) * 4 + i);
            cout << bg[y * 4 + i][x * 10 + j];
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int mainMenu() {
    int choice[4] = { 0,0,0,0 }, temp, key, curChoice = 0;

    goToXY(35, 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << " ______    __   __  ___      ___       ______  __    __   __    __";
    goToXY(35, 3);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |";
    goToXY(35, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |";
    goToXY(35, 5);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |";
    goToXY(35, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |";
    goToXY(35, 7);
    cout << "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/";

    while (1) {

        choice[curChoice] = 1;

        if (choice[0]) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                goToXY(60, 11 + i);
                cout << "             ";
            }

            goToXY(64, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "NORMAL";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                goToXY(60, 11 + i);
                cout << "             ";
            }

            goToXY(64, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "NORMAL";
        }

        if (choice[1]) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                goToXY(60, 14 + i);
                cout << "             ";
            }

            goToXY(62, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
            cout << "DIFFICULT";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                goToXY(60, 14 + i);
                cout << "             ";
            }

            goToXY(62, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "DIFFICULT";
        }

        if (choice[2]) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                goToXY(60, 17 + i);
                cout << "             ";
            }

            goToXY(61, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 2);
            cout << "LEADERBOARD";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                goToXY(60, 17 + i);
                cout << "             ";
            }

            goToXY(61, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "LEADERBOARD";
        }

        if (choice[3]) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                goToXY(60, 20 + i);
                cout << "             ";
            }

            goToXY(64, 21);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 6);
            cout << "EXIT";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 3; i++) {
                goToXY(60, 20 + i);
                cout << "             ";
            }

            goToXY(64, 21);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            cout << "EXIT";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        if (temp = _getch()) {
            if (temp != 224 && temp)
            {
                if (temp == ENTER_KEY) {
                    system("cls");
                    return curChoice;
                }
            }
            else {
                key = _getch();
                switch (key)
                {
                case KEY_UP:
                    choice[curChoice] = 0;
                    if (curChoice > 0) curChoice--;
                    else curChoice = 3;
                    break;
                case KEY_DOWN:
                    choice[curChoice] = 0;
                    if (curChoice < 3) curChoice++;
                    else curChoice = 0;
                default:
                    break;
                }
            }
        }
    }
}