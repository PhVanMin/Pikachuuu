#pragma once
#ifndef _CHECK2_H_
#define _CHECK2_H_

#include "Struct.h"

CELL_2* findTheNode(CELL_2**, int, int);
bool Icheck(CELL_2** , int, int, int, int);
bool Lcheck(CELL_2**, int, int, int, int);
bool UandZcheck(CELL_2**, int, int, int, int);
bool allCheck(CELL_2**, int, int, int, int);
void deleteNode(CELL_2**, int, int);
void DifMode(CELL_2**, int, int, int, int);
bool checkValidPairs(CELL_2**);

#endif