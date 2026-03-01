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

typedef struct Enemy{
    char place[30];
    char name[30];
    int health;
    int attack;
    int defense;
    int goldReward;
    int minLevel;
    int xpReward;
    char itemNameAtk[30];
    char itemNameDef[30];
}Enemy;

extern int row;
extern int column;
extern void FirstIntroductionMenu();
extern void gameSave();
extern void xpLevelCalc();
extern void advanceTime();
extern void advanceTimePeriod(int time);

void playerStats(char menuName[], int menuNameSize, int viewLineSize, char *viewLineVariable);

void warMenu();
void warPanel(int currentHP, int currentEnemyHP, int currentPossession, int enemyIdx, int triggerEnemyAttack);
void cursorControlWar();
void PrintBoardWar();
void escapeWar(int enemyIdx);

void clearWarLog();
void makeAttackLogEnemy(char *out, size_t size,const char *attacker,const char *target,int damage);
void makeAttackLogPlayer(char *out, size_t size,const char *attacker,const char *target,int damage);
void makeDefendLog(char *out, size_t size, const char *defender, int totalDamage, int reducedDamage);
void makeCounterStrikeLog(char *out, size_t size, const char *defender, char *attacker, int counterDamage);
void appendWarLog(const char *line);

void checkBattleStatus(int pHP, int eHP, int currentPossession, int enemyIdx, int triggerEnemyAttack);
void quickAttack(int pHP, int eHP, int enemyIdx);
void normalAttack(int pHP, int eHP, int enemyIdx);
void heavyAttack(int pHP, int eHP, int enemyIdx);
void defense(int pHP, int eHP, int enemyIdx);
int getRandomEnemyIndex(int playerLevel);
