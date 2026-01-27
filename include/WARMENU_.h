#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

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

void clearWarLog();
void makeAttackLog(char *out, size_t size,const char *attacker,const char *target,int damage);
void appendWarLog(const char *line);

void checkBattleStatus(int pHP, int eHP);
void quickAttack(int pHP, int eHP);
void normalAttack(int pHP, int eHP);
void heavyAttack(int pHP, int eHP);
