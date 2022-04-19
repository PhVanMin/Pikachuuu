#pragma once
#include "Check2.h"
#include<conio.h>
#include<time.h>
#include "ConsoleSettings.h"
#include "Utility.h"

void push(CELL_2*&, CELL_2*);
void initList(CELL_2**);
void deleteList(CELL_2**);
void renderList(CELL_2**);
void move(CELL_2**, position&, int&, player&, position[], int&);
void difficultMode(player&);