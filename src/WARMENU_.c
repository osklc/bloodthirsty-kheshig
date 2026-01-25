#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "../include/WARMENU_.h"

char boardWar[4][20] = {"Start War","War Training"};
int columnSize = 2;

char places[3][20] = {"Northern Forests", "Hell", "Glacial Mountains"};


Enemy enemyPool[] = {
    // --- NORTHERN FORESTS (Level 1 - 10)
    {"Northern Forests", "Shadow-Paw Warg",     45,  12,  2,  15, 1, 1},
    {"Northern Forests", "Forest Outcast",      60,  15,  4,  25, 1, 3},
    {"Northern Forests", "Blind Ravager",       85,  22,  8,  45, 2, 6},
    {"Northern Forests", "Moss-Skin Troll",     150, 20,  15, 80, 3, 9},

    // --- HELL (Level 10 - 20)
    {"Hell", "Soul Burner Imp",                 100, 35,  10, 100, 2, 10},
    {"Hell", "Inferno Reaver",                  130, 42,  15, 150, 3, 13},
    {"Hell", "Cursed Soul Eater",               160, 48,  20, 200, 4, 16},
    {"Hell", "Molten Behemoth",                 250, 55,  35, 350, 5, 19},

    // --- GLACIAL MOUNTAINS (Level 20 - 30+)
    {"Glacial Mountains", "Snow Stalker Drake", 200, 60,  25, 400, 4, 20},
    {"Glacial Mountains", "Glacier Wraith",     220, 65,  30, 500, 4, 23},
    {"Glacial Mountains", "Ice Clad Berserker", 280, 75,  40, 650, 5, 26},
    {"Glacial Mountains", "Ice Golem",          450, 70,  60, 900, 6, 30}
};


void warMenu()
{
	cursorControlWar();
}

void warPanel(int currentHP, int currentEnemyHP)
{
	char viewPlace[1][20];
	strcpy(viewPlace[0], places[0]);
	char viewLine[] = "==================================================";
	char viewHeader[100];
	sprintf(viewHeader, "     \033[31mBLOODTHIRSTY KHESHIG\033[0m - \033[32m%s\033[0m", viewPlace[0]);

	int viewDiff = strlen(viewLine) - strlen(viewHeader);

	printf("%s\n",viewLine);
	for(int i=0;i<viewDiff/2;i++)
	{
		printf(" ");
	}
	printf("%s", viewHeader);
	printf("\n%s\n", viewLine);
	
	char choicedEnemiesName[1][20];
	strcpy(choicedEnemiesName[0], enemyPool[0].name);

	
	printf("  ");
	printf("[KHESHIG]");
	for(int j=0;j<35-strlen(choicedEnemiesName[0]);j++)
	{
		printf(" ");
	}
	printf("[%s]",choicedEnemiesName[0]);
	printf("\n  ");

	int kheshigActiveHP = currentHP;
	char kheshigHP[20];
	snprintf(kheshigHP, 20,"HP: %d/%d", kheshigActiveHP, kheshig.health);

	int enemyActiveHP = currentEnemyHP;
	char enemyHP[20];
	snprintf(enemyHP, 20, "HP: %d/%d", enemyActiveHP, currentEnemyHP);

	printf("%s", kheshigHP);

	for(int j=0;j<44-strlen(choicedEnemiesName[0])-strlen(kheshigHP);j++)
	{
		printf(" ");
	}

	printf("%s", enemyHP);

	printf("\n  [");
	int t = 0;
	float hpRatio = (float)kheshigActiveHP / kheshig.health;
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
	float enemyHpRatio = (float)enemyActiveHP / enemyPool[0].health;
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

	printf("\n%s\n", viewLine);
	printf("  In production(LOG)");
	printf("\n%s\n", viewLine);

	printf("  1. Quick Attack (90%% Accuracy - Low Damage)\n");
	printf("  2. Heavy Strike (50%% Accuracy - High Damage)\n");
	printf("  3. Defense (50%% Damage Reduction)\n");
	printf("  4. Retreat (Escape Battle - Lose Gold)\n");

	printf("%s\n", viewLine);

	char selectedPreference;

	do
	{
		selectedPreference = getch();
		if(selectedPreference == '1')
        {
			system("cls");
			quickAttack();
			break;
        }
		else if(selectedPreference == '2')
        {
			system("cls");
			heavyStrike();
			break;
        }
		else if(selectedPreference == '3')
        {
			system("cls");
			defense();
			break;
        }
		else if(selectedPreference == '4')
        {
			system("cls");
			retreat();
			break;
        }
	} while(selectedPreference != '1' && selectedPreference != '2' && selectedPreference != '3' && selectedPreference != '4');
}


void quickAttack()
{
	getch();
}
void heavyStrike()
{
	getch();
}
void defense()
{
	getch();
}
void retreat()
{
	getch();
}

void cursorControlWar()
{
	char selectedDirection = '\0';
	char viewLine[] = "========================================================";
	
	while(selectedDirection != 'F' && selectedDirection != 'f' && selectedDirection != 'Q' && selectedDirection != 'q')
	{
		system("cls");
		printf("%s\n", viewLine);
		printf("\033[35m\033[3m                       WAR MENU\033[0m");
		printf("\n%s\n", viewLine);
		printf("\033[91mHealth:\033[0m %d\n",kheshig.health);
		printf("\033[36m\033[1mLevel:\033[0m %d\n",kheshig.level);
		printf("\033[33m\033[1mGold:\033[0m %d\n",kheshig.gold);
		printf("\033[95m\033[3mAttack:\033[0m %d\n",kheshig.attack);
		printf("\033[33mDefense:\033[0m %d",kheshig.defense);
		printf("\n%s\n", viewLine);
		PrintBoardWar();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("\n%s\n", viewLine);
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
        		system("cls");
				warPanel(kheshig.health, enemyPool[0].health);
			}
			else if(column==1)
			{
				system("cls");
				printf("Training mode coming soon...");
				getch();
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
			//Sleep(1000);
		}
        
	}
}

void PrintBoardWar()
{
	int i,j,m,n;
	
	for(i=0;i<1;i++)
	{
		for(m=0;m<columnSize;m++)
		{
			printf(" ");
			for(n=0;n<strlen(boardWar[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m\n");
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
				printf("\033[4m ");
			}
		}
		printf("\033[0m|\n");
	}
}