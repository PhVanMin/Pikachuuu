#pragma once
#ifndef _UTILITY_H_
#define _UTILITY_H_

#include<fstream>
#include<string>
#include "ConsoleSettings.h"
#include "Struct.h"
using namespace std;

void readLeaderBoard();
void writeLeaderBoard(player);
void getPlayerInfo(player&);
void displayStatus(bool);
void background();
int mainMenu();
#endif // !_UTILITY_H_
