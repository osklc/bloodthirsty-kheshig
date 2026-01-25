#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct Player{
    int health;
    int gold;
    int level;
	int attack;
	int defense;
}Player;
extern struct Player kheshig;

typedef struct Enemy{
    char place[30];
    char name[30];
    int health;
    int attack;
    int defense;
    int goldReward;
    int difficulty;
    int minLevel;
}Enemy;

extern int row;
extern int column;
extern void FirstIntroductionMenu();
extern void gameSave();

void warMenu();
void warPanel(int currentHP, int currentEnemyHP);
void cursorControlWar();
void PrintBoardWar();

void quickAttack();
void heavyStrike();
void defense();
void retreat();