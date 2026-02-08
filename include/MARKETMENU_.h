#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

struct Player{
    int health;
    int activeHealth;
    int gold;
    int level;
	int attack;
	int defense;
    int xp;
    int currentDay;
    int loopCount;
    int currentTimePeriod;
};
extern struct Player kheshig;

extern void FirstIntroductionMenu();
extern void gameSave();
void playerStats(char menuName[], int menuNameSize, int viewLineSize, char *viewLineVariable);

void noGoldMarket();
void marketMenu();
void cursorControlMarket();
void printMarketList();