#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <direct.h>
#include <errno.h>

typedef struct Player{
    int health;
    int activeHealth;
    int activeStamina;
    int maxStamina;
    int activePossession;
    int maxPossession;
    int gold;
    int level;
	int attack;
	int defense;
    int xp;
    int currentDay;
    int loopCount;
    int currentTimePeriod;
    int mageForm;
}Player;
extern struct Player kheshig;

extern void FirstIntroductionMenu();
extern void gameSave();
extern void advanceTime();
extern void advanceTimePeriod(int time);

void playerStats(char menuName[], int menuNameSize, int viewLineSize, char *viewLineVariable);

void noGoldGambling();
void innMenu();
void cursorControlInn();
void printInnList();
void playGambling();
void printGamblingList();