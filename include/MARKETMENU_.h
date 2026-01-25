#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

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


void healthPotion();

void marketMenu();
void cursorControlMarket();
void PrintBoardMarket();