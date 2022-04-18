#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include<Windows.h>
void goToXY(int, int);
void resizeWindow(int, int);
void setCursor(bool);
void hideScrollBar();
void initWindow(int, int);

#endif