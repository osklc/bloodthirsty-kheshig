#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#define WAR_LINE_SIZE 1024
#define MAX_VISIBLE_LOGS 5

#include "../include/WARMENU_.h"

char boardWar[4][20] = {"Start War","War Training"};
int columnSize = 2;
char places[3][20] = {"Northern Forests", "Hell", "Glacial Mountains"};

char viewLineWar[] = "========================================================";

char warLogs[MAX_VISIBLE_LOGS][WAR_LINE_SIZE];
int currentLogCount = 0;

Enemy enemyPool[] = {
	//IS NOT BALANCED IN PROCESS (numbers are representation)
    // --- NORTHERN FORESTS (Level 1 - 10)
    {"Northern Forests", "Shadow-Paw Warg",     45,  12,  2,  15, 1, 0, 50},
    {"Northern Forests", "Forest Outcast",      60,  15,  4,  25, 1, 3, 12},
    {"Northern Forests", "Blind Ravager",       85,  22,  8,  45, 2, 6, 15},
    {"Northern Forests", "Moss-Skin Troll",     150, 20,  15, 80, 3, 9, 20},

    // --- HELL (Level 10 - 20)
    {"Hell", "Soul Burner Imp",                 100, 35,  10, 100, 2, 10, 20},
    {"Hell", "Inferno Reaver",                  130, 42,  15, 150, 3, 13, 22},
    {"Hell", "Cursed Soul Eater",               160, 48,  20, 200, 4, 16, 25},
    {"Hell", "Molten Behemoth",                 250, 55,  35, 350, 5, 19, 28},

    // --- GLACIAL MOUNTAINS (Level 20 - 30+)
    {"Glacial Mountains", "Snow Stalker Drake", 200, 60,  25, 400, 4, 20, 30},
    {"Glacial Mountains", "Glacier Wraith",     220, 65,  30, 500, 4, 23, 33},
    {"Glacial Mountains", "Ice Clad Berserker", 280, 75,  40, 650, 5, 26, 38},
    {"Glacial Mountains", "Ice Golem",          450, 70,  60, 900, 6, 30, 42}
};

const char* retreatTexts[] = {
    "You chose survival over honor.",
	"The shadows were kinder to you than your own steel today.",
	"The Eternal Sky frowns upon your retreat, but your breath remains.",
	"You fled like a wounded dog—alive, but broken.",
	"Coward's breath is sweeter than a warrior's death, is it not?",
	"Your ancestors spit at the mention of your name tonight.",
	"The crows will mock your retreat in their cawing.",
	"You chose the path of shame over the warrior's end.",
	"Your legs carried you faster than your courage could.",
	"The steppe remembers those who run—and judges them.",
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
	"Swift as the wolf, fierce as the eagle—victory is yours!",
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
	"The Eternal Sky saw your last breath—and turned away.",
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
	snprintf(kheshigHPStr, 25, "  HP: %d/%d", currentHP, kheshig.health);

	char enemyHPStr[25];
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
	printf("                 [");

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
		advanceTime();

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
	char viewLineBattle[] = "===========================================================";
	if(eHP <= 0)
	{
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
        
        printf("\n    \033[33m[LOOT COLLECTED]\033[0m\n");
		printf("    + %d Gold Coins\n", enemyPool[enemyIdx].goldReward);
		printf("    + %d Xp Earned\n", enemyPool[enemyIdx].xpReward);
        
		kheshig.gold += enemyPool[enemyIdx].goldReward;
		kheshig.xp += enemyPool[enemyIdx].xpReward;
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
			int nextPlayerHP = pHP - enemyDmg;

			if(nextPlayerHP <= 0)
			{
				checkBattleStatus(0,eHP,enemyIdx, 1);
			}
			else
			{
				warPanel(nextPlayerHP, eHP, enemyIdx);
			}
		}
		else
		{
			warPanel(pHP,eHP,enemyIdx);
		}
		
	}
}

void defense(int pHP, int eHP, int enemyIdx)
{
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
			checkBattleStatus(pHP-def, eHP, enemyIdx, 0);
		}
	}
	else
	{
		char counterLine[128];
		makeCounterStrikeLog(counterLine, sizeof(counterLine), "Kheshig", enemyPool[enemyIdx].name, def);
		appendWarLog(counterLine);
		checkBattleStatus(pHP, eHP-def, enemyIdx, 0);
	}
}

void quickAttack(int pHP, int eHP, int enemyIdx)
{
	int chance = rand() % 100;
	if(chance < 90)
	{
		int dmg = kheshig.attack - enemyPool[enemyIdx].defense;
        if(dmg < 1) dmg = 1;
		char line[128];
		makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
		appendWarLog(line);
		checkBattleStatus(pHP, eHP - dmg, enemyIdx, 1);
	}
	else
	{
		appendWarLog("Kheshig missed their Quick Attack!\n");
		checkBattleStatus(pHP, eHP, enemyIdx, 1);
	}
}

void normalAttack(int pHP, int eHP, int enemyIdx)
{
	int chance = rand() % 100;
	if(chance < 75)
	{
		int dmg = (int)(1.2 * (kheshig.attack - enemyPool[enemyIdx].defense));
        if(dmg < 1) dmg = 1;
		char line[128];
		makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
		appendWarLog(line);
		checkBattleStatus(pHP, eHP - dmg, enemyIdx, 1);
	}
	else
	{
		appendWarLog("Kheshig missed their Normal Attack!\n");
		checkBattleStatus(pHP, eHP, enemyIdx, 1);
	}
}

void heavyAttack(int pHP, int eHP, int enemyIdx)
{
	int chance = rand() % 100;
	if(chance < 40)
	{
		int dmg = 2 * (kheshig.attack - enemyPool[enemyIdx].defense);
        if(dmg < 1) dmg = 1;
		char line[128];
		makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
		appendWarLog(line);
		checkBattleStatus(pHP, eHP - dmg, enemyIdx, 1);
	}
	else
	{
		appendWarLog("Kheshig missed their Heavy Attack!\n");
		checkBattleStatus(pHP, eHP, enemyIdx, 1);
	}
}

int getRandomEnemyIndex(int playerLevel)
{
	int validIndices[20];
	int validCount = 0;

	for (int i = 0; i < sizeof(enemyPool) / sizeof(Enemy); i++)
	{
		if(playerLevel >= enemyPool[i].minLevel)
		{
			validIndices[validCount] = i;
			validCount++;
		}
	}
	if (validCount == 0) return 0;

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
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("%s",viewLineWar);
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("%s\n",viewLineWar);
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a' || selectedDirection == 75)
        {
            column--;
            if(column < 0) column = columnSize-1;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd' || selectedDirection == 77)
        {
            column++;
            if(column > columnSize-1) column = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(column==0)
        	{
				clearWarLog();
				int selectedEnemyIdx = getRandomEnemyIndex(kheshig.level);
				char startMsg[150];
    			sprintf(startMsg, "A wild %s appeared in the %s!\n  Battle started in %s!\n",enemyPool[selectedEnemyIdx].name, enemyPool[selectedEnemyIdx].place,enemyPool[selectedEnemyIdx].place);
				appendWarLog(startMsg);
				warPanel(kheshig.activeHealth, enemyPool[selectedEnemyIdx].health, selectedEnemyIdx);
			}
			else if(column==1)
			{
				system("cls");
				printf("Training mode coming soon...");
				getch();
				FirstIntroductionMenu();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
			column=0;
        	FirstIntroductionMenu();
		}
		else
		{
			//printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
		}
        
	}
}

void PrintBoardWar()
{
	int i,j,m,n;
	
	for(i=0;i<1;i++)
	{
		/*for(m=0;m<columnSize;m++)
		{
			printf(" ");
			for(n=0;n<strlen(boardWar[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m\n");*/
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardWar[m])+6;n++)
			{
				printf(" ");
			}
		}
		printf("|\n");
		for(j=0;j<columnSize;j++)
		{
			printf("|");
			if(i==row && j== column)
			{
				printf("  \033[92m[%s]\033[0m  ",boardWar[j]);
			}
			else
			{
				printf("   %s   ",boardWar[j]);
			}
		}
		printf("|\n");
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardWar[m])+6;n++)
			{
				printf(" ");
			}
		}
		printf("\033[0m|\n");
	}
}