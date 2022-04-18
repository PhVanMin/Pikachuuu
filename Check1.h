#pragma once
#ifndef _CHECK1_H_
#define _CHECK1_H_

#include "Struct.h"
bool nextcheck(CELL_1**, int p1, int p2, int q1, int q2);
bool linecheck(CELL_1**, int p1, int p2, int q1, int q2);
bool Icheck_1(CELL_1**, int p1, int p2, int q1, int q2);
bool Lcheck(CELL_1**, int p1, int p2, int q1, int q2);
bool Zcheck(CELL_1**, int p1, int p2, int q1, int q2);
bool Ucheck(CELL_1**, int p1, int p2, int q1, int q2);
bool allcheck(CELL_1**, int p1, int p2, int q1, int q2);
bool checkValidPairs(CELL_1**);

#endif