#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <direct.h>
#include <errno.h>

#define WAR_LINE_SIZE 1024
#define MAX_VISIBLE_LOGS 5

#define NORTHERN_FORESTS_START 0
#define NORTHERN_FORESTS_END 9
#define ENCHANTED_GROVES_START 10
#define ENCHANTED_GROVES_END 19
#define SPIRIT_REALM_START 20

#include "../include/WARMENU_.h"

char boardWar[4][20] = {"Start War","War Training"};
int columnSize = 2;
int listRowWar = 0;
char places[3][20] = {"Northern Forests", "Hell", "Glacial Mountains"};

char viewLineWar[] = "===========================================================";

char warLogs[MAX_VISIBLE_LOGS][WAR_LINE_SIZE];
int currentLogCount = 0;

Enemy enemyPool[] = {
    // --- NORTHERN FORESTS (Level 0-9) - Early game, mostly winnable
    {"Northern Forests", "Grey Wolf",           35,  12,  1,  25, 0,  35},
    {"Northern Forests", "Wild Boar",           45,  13,  2,  30, 1,  38},
    {"Northern Forests", "Rabid Fox",           38,  14,  2,  28, 2,  40},
    {"Northern Forests", "Forest Bandit",       55,  15,  3,  35, 3,  42},
    {"Northern Forests", "Brown Bear",          75,  16,  4,  40, 4,  45},
    {"Northern Forests", "Outlaw Archer",       60,  17,  3,  38, 5,  43},
    {"Northern Forests", "Feral Lynx",          50,  18,  2,  36, 5,  41},
    {"Northern Forests", "Mountain Lion",       80,  19,  5,  42, 6,  46},
    {"Northern Forests", "Bandit Chief",        100, 20,  6,  50, 7,  48},
    {"Northern Forests", "Timber Wolf Pack",    110, 22,  7,  55, 9,  50},

    // --- ENCHANTED GROVES (Level 10-19) - Need some gear upgrades
    {"Enchanted Groves", "Glowing Stag",        120, 24,  6,  65, 10, 60},
    {"Enchanted Groves", "Thornback Badger",    130, 26,  8,  75, 11, 65},
    {"Enchanted Groves", "Whispering Owl",      110, 27,  7,  70, 12, 63},
    {"Enchanted Groves", "Moonlit Fox",         125, 28,  7,  75, 13, 65},
    {"Enchanted Groves", "Ancient Treant",      160, 30,  10, 90, 14, 70},
    {"Enchanted Groves", "Spore-Touched Bear",  145, 31,  9,  85, 15, 68},
    {"Enchanted Groves", "Vine Strangler",      135, 32,  9,  80, 16, 67},
    {"Enchanted Groves", "Fae-Touched Wolf",    130, 33,  8,  82, 17, 69},
    {"Enchanted Groves", "Crystal Beetle",      115, 35,  12, 78, 16, 66},
    {"Enchanted Groves", "Elder Dryad",         150, 38,  14, 105, 19, 74},

    // --- SPIRIT REALM (Level 20-32) - Dangerous, require solid upgrades
    {"Spirit Realm", "Lost Soul",               180, 40,  12, 120, 20, 85},
    {"Spirit Realm", "Phantom Hunter",          200, 42,  14, 135, 22, 90},
    {"Spirit Realm", "Ethereal Wisp",           165, 43,  11, 125, 21, 88},
    {"Spirit Realm", "Banshee Warden",          220, 45,  16, 150, 24, 95},
    {"Spirit Realm", "Spectral Knight",         250, 47,  18, 165, 26, 100},
    {"Spirit Realm", "Void Stalker",            230, 48,  16, 160, 25, 98},
    {"Spirit Realm", "Ancestral Guardian",      280, 50,  20, 180, 28, 105},
    {"Spirit Realm", "Shadow Wraith",           210, 51,  15, 155, 27, 102},
    {"Spirit Realm", "Soul Reaver",             300, 53,  22, 195, 29, 110},
    {"Spirit Realm", "Nightmare Manifestation", 350, 55,  25, 220, 30, 115},
    {"Spirit Realm", "Ancient Spirit Lord",     400, 57,  28, 250, 32, 120}
};

const char* retreatTexts[] = {
    "You chose survival over honor.",
	"The shadows were kinder to you than your own steel today.",
	"The Eternal Sky frowns upon your retreat, but your breath remains.",
	"You fled like a wounded dog alive, but broken.",
	"Coward's breath is sweeter than a warrior's death, is it not?",
	"Your ancestors spit at the mention of your name tonight.",
	"The crows will mock your retreat in their cawing.",
	"You chose the path of shame over the warrior's end.",
	"Your legs carried you faster than your courage could.",
	"The steppe remembers those who run and judges them.",
	"Survival tastes of ash when honor is the price."
};

const char* victoryTexts[] = {
    "The Eternal Blue Sky witnesses your glorious triumph!",
	"A new saga begins with the screams of your fallen foe.",
	"The spirits of the steppe howl in favor of your sharp steel.",
	"Victory belongs to the swift; the battlefield is yours!",
	"You stand victorious amidst the carnage.",
	"Another soul rides to the ancestors on your steel.",
	"The ravens gather; your enemy feeds them well.",
	"Swift as the wolf, fierce as the eagle victory is yours!",
	"Your foe's courage broke before your blade did.",
	"The steppe remembers this kill.",
	"Blood and glory the old way prevails!",
	"Your enemy's final breath joins the wind."
};

const char* defeatTexts[] = {
    "The dust of the steppe shall swallow your forgotten name.",
    "Fate is a cruel mistress, and today she chose your end.",
    "Your soul wanders into the cold mists of the afterlife.",
    "The crows gather for a feast you did not intend to provide.",
	"The steppe claims another forgotten warrior.",
	"Your ancestors turn their backs in silence.",
	"The Eternal Sky saw your last breath-and turned away.",
	"You rode into legend, but death rode faster.",
	"The wolves will scatter your bones by morning.",
	"Your story ends here, unsung and unremembered.",
	"Even the bravest fall when fate swings her blade.",
	"The spirits did not hear your final prayer."
};


void warMenu()
{
	cursorControlWar();
}

void clearWarLog() 
{
    for(int t=0; t<MAX_VISIBLE_LOGS;t++)
	{
		warLogs[t][0] = '\0';
	}
    currentLogCount = 0;
}


void appendWarLog(const char *line) {
    if (currentLogCount < MAX_VISIBLE_LOGS) {
        snprintf(warLogs[currentLogCount], WAR_LINE_SIZE, "  %s", line);
        currentLogCount++;
    } else {
        for (int i = 0; i < MAX_VISIBLE_LOGS - 1; i++) {
            strcpy(warLogs[i], warLogs[i + 1]);
        }
        snprintf(warLogs[MAX_VISIBLE_LOGS - 1], WAR_LINE_SIZE, "  %s", line);
    }
}

void makeAttackLogEnemy(char *out, size_t size,const char *attacker,const char *target,int damage)
{
    snprintf(out, size,"%s attacks %s for \033[31m%d\033[0m damage\n",attacker, target, damage);
}

void makeAttackLogPlayer(char *out, size_t size,const char *attacker,const char *target,int damage)
{
    snprintf(out, size,"%s attacks %s for \033[32m%d\033[0m damage\n",attacker, target, damage);
}

void makeDefendLog(char *out, size_t size, const char *defender, int totalDamage, int reducedDamage)
{
    snprintf(out, size, "%s defends! (\033[31m%d\033[0m -> \033[33m%d\033[0m damage)\n", defender, totalDamage, reducedDamage);
}

void makeCounterStrikeLog(char *out, size_t size, const char *defender, char *attacker, int counterDamage)
{
	snprintf(out, size, "\033[33m%s\033[0m counters! Strikes %s for \033[31m%d\033[0m damage\n", defender, attacker, counterDamage);
}

void warPanel(int currentHP, int currentEnemyHP, int enemyIdx)
{
	system("cls");
	char viewHeader[150];
	snprintf(viewHeader, sizeof(viewHeader), "  \033[31mBLOODTHIRSTY KHESHIG\033[0m - \033[32m%s\033[0m", enemyPool[enemyIdx].place);

	int visibleLen = strlen("     BLOODTHIRSTY KHESHIG - ") + strlen(enemyPool[enemyIdx].place);
    int viewDiff = (int)strlen(viewLineWar) - visibleLen;

	printf("%s\n",viewLineWar);
	for(int i=0;i<viewDiff/2;i++)
	{
		printf(" ");
	}
	printf("%s", viewHeader);
	printf("\n%s\n", viewLineWar);
	
	char choicedEnemiesName[30];
	strcpy(choicedEnemiesName, enemyPool[enemyIdx].name);

	
	printf("  ");
	printf("[Kheshig]");
	for(int j=0;j<35-strlen(choicedEnemiesName);j++)
	{
		printf(" ");
	}
	printf("[%s]\n",choicedEnemiesName);

	char kheshigHPStr[25];
	if(currentHP<0) currentHP=0;
	snprintf(kheshigHPStr, 25, "  HP: %d/%d", currentHP, kheshig.health);

	char enemyHPStr[25];
	if(currentEnemyHP<0) currentEnemyHP=0;
	snprintf(enemyHPStr, 25, "  HP: %d/%d", currentEnemyHP, enemyPool[enemyIdx].health);

	printf("%s", kheshigHPStr);

	for(int j=0;j<44-strlen(choicedEnemiesName)-strlen(kheshigHPStr);j++)
	{
		printf(" ");
	}

	printf("%s", enemyHPStr);

	printf("\n  [");
	int t = 0;
	float hpRatio = (float)currentHP / kheshig.health;
	if (hpRatio < 0) hpRatio = 0;
	int kheshigHealthBar = (int)(10 * hpRatio);
	while(t<10)
	{
		for(int a=0;a<kheshigHealthBar;a++)
		{
			t++;
			printf("|");
		}
		while(t<10)
		{
			t++;
			printf(".");
		}
	}
	printf("]");

	for(int j=0;j<32-strlen(choicedEnemiesName);j++)
	{
		printf(" ");
	}

	printf("[");

	int d = 0;
	float enemyHpRatio = (float)currentEnemyHP / enemyPool[enemyIdx].health;
	if (enemyHpRatio < 0) enemyHpRatio = 0;
	int enemyHealthBar = (int)(10 * enemyHpRatio);
	while(d<10)
	{
		for(int a=0;a<enemyHealthBar;a++)
		{
			d++;
			printf("|");
		}
		while(d<10)
		{
			d++;
			printf(".");
		}
	}
	printf("]");

	printf("\n\033[33m  Stamina:\033[0m %d/%d \n  ",kheshig.activeStamina ,kheshig.maxStamina);
	printf("[");
	int k = 0;
	float staminaRatio = (float)kheshig.activeStamina / kheshig.maxStamina;
	if (staminaRatio < 0) staminaRatio = 0;
	int kheshigStaminaBar = (int)(10 * staminaRatio);
	while(k<10)
	{
		for(int a=0;a<kheshigStaminaBar;a++)
		{
			k++;
			printf("|");
		}
		while(k<10)
		{
			k++;
			printf(".");
		}
	}
	printf("]\n");

	printf("\n%s\n", viewLineWar);
	printf("                   --- BATTLE LOG ---\n");
	for(int i=0;i<currentLogCount;i++)
	{
		printf("%s", warLogs[i]);
	}
	for(int i=currentLogCount;i<MAX_VISIBLE_LOGS;i++)
	{
		printf("\n");
	}
	printf("%s\n", viewLineWar);

	printf("  1. Quick Attack  | 2. Normal Attack | 3. Heavy Attack\n");
	printf("  4. Defense       | 5. Escape - Lose Gold\n");
	printf("%s\n", viewLineWar);

	if(currentHP <= 0 || currentEnemyHP <= 0)
	{
		checkBattleStatus(currentHP, currentEnemyHP, enemyIdx, 0);
		return;
	}

	char choice;
	do {
		choice = getch();
		if(choice == '1') quickAttack(currentHP, currentEnemyHP, enemyIdx);
		else if(choice == '2') normalAttack(currentHP, currentEnemyHP, enemyIdx);
		else if(choice == '3') heavyAttack(currentHP, currentEnemyHP, enemyIdx);
		else if(choice == '4') defense(currentHP, currentEnemyHP, enemyIdx); 
		else if(choice == '5') { escapeWar(enemyIdx); }
	} while(choice < '1' || choice > '5');
}

void escapeWar(int enemyIdx)
{
	char viewLineEscape[] = "======================================================================";
	system("cls");
		int loss = (kheshig.gold * 15) / 100;
        printf("%s\n", viewLineEscape);
		printf("                      \033[33m\033[1m<<< KHESHIG RETREATED >>>\033[0m\n");
        printf("%s\n", viewLineEscape);
		advanceTimePeriod(1);

		int retreatCount = sizeof(retreatTexts) / sizeof(retreatTexts[0]);
        int idx = rand() % retreatCount;
        printf("\n    %s\n",retreatTexts[idx]);
        printf("    The %s remains behind as you flee into the shadows...\n", enemyPool[enemyIdx].name);
        
        printf("\n    \033[33m[CONSEQUENCES]\033[0m\n");
		printf("    - %d Gold Coins (Lost while escaping in haste)\n", loss);
        
		kheshig.gold -= loss;
		gameSave();

		printf("\n%s\n", viewLineEscape);
		printf("    Press any key to recover at the camp...");
		printf("\n%s\n", viewLineEscape);
		getch();
		clearWarLog();
		FirstIntroductionMenu();
}

void checkBattleStatus(int pHP, int eHP, int enemyIdx, int triggerEnemyAttack)
{
	char viewLineBattle[] = "======================================================================";
	if(eHP <= 0)
	{
		printf("Press any key to continue...");
		getch();
		system("cls");
        printf("%s\n", viewLineBattle);
		printf("                \033[32m\033[1m!!! BATTLE VICTORIOUS !!!\033[0m\n");
        printf("%s\n", viewLineBattle);
		advanceTimePeriod(1);
		advanceTime();
        
        printf("\n    Kheshig has defeated the %s!\n", enemyPool[enemyIdx].name);
		int victoryCount = sizeof(victoryTexts) / sizeof(victoryTexts[0]);
        int idx = rand() % victoryCount;
        printf("    %s\n",victoryTexts[idx]);
        
        
		int randEndGold = enemyPool[enemyIdx].goldReward * 0.8;
		int randStartGold = enemyPool[enemyIdx].goldReward * 1.2;
		int randGold = rand() % randStartGold + randEndGold; 

		kheshig.gold += randGold;

		printf("\n    \033[33m[LOOT COLLECTED]\033[0m\n");
		printf("    + %d Gold Coins\n", randGold);

		int randEndXp = enemyPool[enemyIdx].xpReward * 0.8;
		int randStartXp = enemyPool[enemyIdx].xpReward * 1.2;
		int randXp = rand() % randStartXp + randEndXp; 

		kheshig.xp += randXp;

		printf("    + %d Xp Earned\n", enemyPool[enemyIdx].xpReward);

		kheshig.activeHealth = pHP;
		xpLevelCalc();
		gameSave();

		printf("\n%s\n", viewLineBattle);
		printf("    Press any key to return to the camp...");
		printf("\n%s\n", viewLineBattle);
		getch();
		clearWarLog();
		FirstIntroductionMenu();
	}
	else if(pHP <= 0)
	{
		printf("Press any key to continue...");
		getch();
		system("cls");
		int loss;
		if(enemyPool[enemyIdx].goldReward<100)
		{
			loss = (kheshig.gold * 10) / 100;
		}
		else if(enemyPool[enemyIdx].goldReward<1000)
		{
			loss = (kheshig.gold * 25) / 100;
		}
		else
		{
			loss = (kheshig.gold * 30) / 100;
		}

		if(loss<10)
		{
			loss = 10;
		}
		if(loss>1000)
		{
			loss = 1000;
		}

        printf("%s\n", viewLineBattle);
		printf("                \033[31m\033[1mXXX KHESHIG HAS FALLEN XXX\033[0m\n");
        printf("%s\n", viewLineBattle);
		advanceTimePeriod(1);
		advanceTime();
        
        printf("\n    You were bested by the %s.\n", enemyPool[enemyIdx].name);
        
		if(strcmp(enemyPool[enemyIdx].place, "Northern Forests") == 0)
		{
			printf("    Death is a cold companion in the %s...\n", enemyPool[enemyIdx].place);
		}
		/*
		else if(strcmp(enemyPool[enemyIdx].place, "sdasdsadadasdsadsad") == 0)
		{
			printf("    Death is a cold companion in the %s...\n", enemyPool[enemyIdx].place);
		}
		*/

		int defeatCount = sizeof(defeatTexts) / sizeof(defeatTexts[0]);
        int idx = rand() % defeatCount;
        printf("    %s\n",defeatTexts[idx]);
        
        printf("\n    \033[31m[PENALTIES]\033[0m\n");
		if(kheshig.gold<=0)
		{
			printf("Your body yielded no gold only the cold truth of a warrior with nothing left to lose.\n");
		}
		else
		{
			printf("    - %d Gold Coins (Scavengers took their share)\n", loss);
			kheshig.gold -= loss;
		}
		kheshig.activeHealth = pHP;
		gameSave();

		printf("\n%s\n", viewLineBattle);
		printf("    Press any key to recover at the camp...");
		printf("\n%s\n", viewLineBattle);
		getch();
		clearWarLog();
		FirstIntroductionMenu();
	}
	else
	{
		if(triggerEnemyAttack == 1)
		{
			int chanceFactor = 10 + rand() % 10;
			int enemyDmg = (chanceFactor*(enemyPool[enemyIdx].attack - kheshig.defense))/10;
			if(enemyDmg < 1) enemyDmg = 1;
			
			char line[128];
			makeAttackLogEnemy(line, sizeof(line), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
			appendWarLog(line);

		}
		else
		{
		}
		
	}
}

void defense(int pHP, int eHP, int enemyIdx)
{
	int defenseStaminaEarn = 10;

	kheshig.activeStamina += defenseStaminaEarn;
	if(kheshig.activeStamina > kheshig.maxStamina)
	{
		kheshig.activeStamina = kheshig.maxStamina;
	}

	int chance = rand() % 100;
	int def = enemyPool[enemyIdx].attack - kheshig.defense;
	if(chance<50)
	{
		if(def<0)
		{
			appendWarLog("Enemy missed their Attack!\n");
		}
		else
		{
			char line[128];
			makeDefendLog(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].attack, def);
			appendWarLog(line);
		}
		warPanel(pHP-def, eHP, enemyIdx);
	}
	else
	{
		char counterLine[128];
		makeCounterStrikeLog(counterLine, sizeof(counterLine), "Kheshig", enemyPool[enemyIdx].name, def);
		appendWarLog(counterLine);
		warPanel(pHP, eHP-def, enemyIdx);
	}
}

void quickAttack(int pHP, int eHP, int enemyIdx)
{
	int quickStaminaLose = 15;
	if(kheshig.activeStamina<quickStaminaLose)
	{
		appendWarLog("You ran out of breath! Try to defend.\n");
		warPanel(pHP, eHP, enemyIdx);
		return;
	}
	else
	{
		kheshig.activeStamina -= quickStaminaLose;
		int chance = rand() % 100;
		if(chance < 90)
		{
			int dmg = kheshig.attack - enemyPool[enemyIdx].defense;
			if(dmg < 1) dmg = 1;
			char line[128];
			makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
			appendWarLog(line);
			
			if(eHP - dmg > 0)
			{
				int chanceFactor = 10 + rand() % 10;
				int enemyDmg = (chanceFactor*(enemyPool[enemyIdx].attack - kheshig.defense))/10;
				if(enemyDmg < 1) enemyDmg = 1;
				char eLine[128];
				makeAttackLogEnemy(eLine, sizeof(eLine), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
				appendWarLog(eLine);
				warPanel(pHP - enemyDmg, eHP - dmg, enemyIdx);
			}
			else
			{
				warPanel(pHP, eHP - dmg, enemyIdx);
			}
		}
		else
		{
			appendWarLog("Kheshig missed their Quick Attack!\n");
			warPanel(pHP, eHP, enemyIdx);
		}
	}
}

void normalAttack(int pHP, int eHP, int enemyIdx)
{
	int normalStaminaLose = 25;
	if(kheshig.activeStamina<normalStaminaLose)
	{
		appendWarLog("You ran out of breath! Try a lighter move.\n");
		warPanel(pHP, eHP, enemyIdx);
		return;
	}

	else
	{
		kheshig.activeStamina -= normalStaminaLose;
		int chance = rand() % 100;
		if(chance < 75)
		{
			int dmg = (int)(1.2 * (kheshig.attack - enemyPool[enemyIdx].defense));
			if(dmg < 1) dmg = 1;
			char line[128];
			makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
			appendWarLog(line);
			
			if(eHP - dmg > 0)
			{
				int chanceFactor = 10 + rand() % 10;
				int enemyDmg = (chanceFactor*(enemyPool[enemyIdx].attack - kheshig.defense))/10;
				if(enemyDmg < 1) enemyDmg = 1;
				char eLine[128];
				makeAttackLogEnemy(eLine, sizeof(eLine), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
				appendWarLog(eLine);
				warPanel(pHP - enemyDmg, eHP - dmg, enemyIdx);
			}
			else
			{
				warPanel(pHP, eHP - dmg, enemyIdx);
			}
		}
		else
		{
			appendWarLog("Kheshig missed their Normal Attack!\n");
			warPanel(pHP, eHP, enemyIdx);
		}
	}
}

void heavyAttack(int pHP, int eHP, int enemyIdx)
{
	int heavyStaminaLose = 35;
	if(kheshig.activeStamina<heavyStaminaLose)
	{
		appendWarLog("You ran out of breath! Try a lighter move.\n");
		warPanel(pHP, eHP, enemyIdx);
		return;
	}

	else
	{
		kheshig.activeStamina -= heavyStaminaLose;
		int chance = rand() % 100;
		if(chance < 70)
		{
			int dmg = 2 * (kheshig.attack - enemyPool[enemyIdx].defense);
			if(dmg < 1) dmg = 1;
			char line[128];
			makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
			appendWarLog(line);
			
			if(eHP - dmg > 0)
			{
				int chanceFactor = 10 + rand() % 10;
				int enemyDmg = (chanceFactor*(enemyPool[enemyIdx].attack - kheshig.defense))/10;
				if(enemyDmg < 1) enemyDmg = 1;
				char eLine[128];
				makeAttackLogEnemy(eLine, sizeof(eLine), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
				appendWarLog(eLine);
				warPanel(pHP - enemyDmg, eHP - dmg, enemyIdx);
			}
			else
			{
				warPanel(pHP, eHP - dmg, enemyIdx);
			}
		}
		else
		{
			appendWarLog("Kheshig missed their Heavy Attack!\n");
			warPanel(pHP, eHP, enemyIdx);
		}
	}
}

int getRandomEnemyIndex(int playerLevel)
{
	int validIndices[20];
	int validCount = 0;
	int startIdx, endIdx;

	if (playerLevel <= 10)
	{
		startIdx = NORTHERN_FORESTS_START;
		endIdx = NORTHERN_FORESTS_END;
	}
	else if (playerLevel <= 20)
	{
		startIdx = ENCHANTED_GROVES_START;
		endIdx = ENCHANTED_GROVES_END;
	}
	else
	{
		startIdx = SPIRIT_REALM_START;
		endIdx = 31;
	}

	for (int i = startIdx; i <= endIdx; i++)
	{
		if(playerLevel >= enemyPool[i].minLevel)
		{
			validIndices[validCount] = i;
			validCount++;
		}
	}

	if (validCount == 0) return startIdx;

	return validIndices[rand() % validCount];
}

void cursorControlWar()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f' && selectedDirection != 'Q' && selectedDirection != 'q')
	{
		system("cls");
		playerStats("WAR MENU", 8, sizeof(viewLineWar), viewLineWar);
		PrintBoardWar();
		printf("[W-S] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("%s\n",viewLineWar);
		selectedDirection = getch();
		
		if(selectedDirection == 'W' || selectedDirection == 'w' || selectedDirection == 72)
		{
			listRowWar--;
			if(listRowWar < 0) listRowWar = columnSize-1;
		}
		else if(selectedDirection == 'S' || selectedDirection == 's' || selectedDirection == 80)
		{
			listRowWar++;
			if(listRowWar > columnSize-1) listRowWar = 0;
		}
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
			if(listRowWar==0)
        	{
				clearWarLog();
				int selectedEnemyIdx = getRandomEnemyIndex(kheshig.level);
				char startMsg[150];
    			sprintf(startMsg, "A wild %s appeared in the %s!\n  Battle started in %s!\n",enemyPool[selectedEnemyIdx].name, enemyPool[selectedEnemyIdx].place,enemyPool[selectedEnemyIdx].place);
				appendWarLog(startMsg);
				warPanel(kheshig.activeHealth, enemyPool[selectedEnemyIdx].health, selectedEnemyIdx);
			}
			else if(listRowWar==1)
			{
				system("cls");
				printf("Training mode coming soon...");
				getch();
				FirstIntroductionMenu();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
			listRowWar=0;
        	FirstIntroductionMenu();
		}
		else
		{
		}
        
	}
}

void PrintBoardWar()
{
	for(int i=0;i<columnSize;i++)
	{
		if(listRowWar==i)
		{
			printf("\033[32m%d.%s\033[0m\n", i+1, boardWar[i]);
		}
		else
		{
			printf("%d.%s\n", i+1, boardWar[i]);
		}
	}
	printf("%s\n", viewLineWar);
}