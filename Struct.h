#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_		

#include<string>
using namespace std;

#define BOARDWIDTH 8
#define BOARDHEIGTH 5

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 13

struct position {
	int x, y;
};

struct player {
	string name = "";
	int point, life;
};

struct CELL_1 {
	int i, j;
	char c = ' ';
	bool isValid = 1, isSelected = 0;

	void drawBox(int);
	void deleteBox();
};

struct CELL_2 {
	int i, j;
	char c = ' ';
	bool isSelected = 0;
	CELL_2* next;

	void drawBox(int);
	void deleteBox();
};
#endif