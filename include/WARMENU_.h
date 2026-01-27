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
    int xp;
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
    int xpReward;
}Enemy;

extern int row;
extern int column;
extern void FirstIntroductionMenu();
extern void gameSave();
extern void xpLevelCalc();

void warMenu();
void warPanel(int currentHP, int currentEnemyHP, int enemyIdx);
void cursorControlWar();
void PrintBoardWar();
void escapeWar(int enemyIdx);

void clearWarLog();
void makeAttackLog(char *out, size_t size,const char *attacker,const char *target,int damage);
void appendWarLog(const char *line);

void checkBattleStatus(int pHP, int eHP, int enemyIdx);
void quickAttack(int pHP, int eHP, int enemyIdx);
void normalAttack(int pHP, int eHP, int enemyIdx);
void heavyAttack(int pHP, int eHP, int enemyIdx);
