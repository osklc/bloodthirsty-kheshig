#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

struct Player{
    int health;
    int gold;
    int level;
	int attack;
	int defense;
};
extern struct Player kheshig;

extern int row;
extern int column;
extern void FirstIntroductionMenu();
extern void gameSave();

void gamblingMenu();
void cursorControlGambling();
void PrintBoardGambling();