#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <direct.h>
#include <sys/stat.h>

#include "include/WARMENU_.h"
#include "include/MARKETMENU_.h"
#include "include/BLACKSMITHMENU_.h"
#include "include/INNMENU_.h"

int row=0;
int column=0;
char boardMain[4][20] = {"War","Market","Blacksmith", "The Inn"};

char viewLine[] = "=======================================================";

struct Player kheshig;

//Prototype
void FirstIntroductionMenu();
void hideCursor();
void gotoxy(int x, int y);
void PrintBoard();
void cursorControl();
int checkSave();
void gameSave();
void xpLevelCalc();
void initNewGame();

int main() 
{
	srand(time(NULL));
	hideCursor();
	gotoxy(0,0);
	
	if (checkSave() == 0)
	{
		initNewGame();
		gameSave();
	}
	FirstIntroductionMenu();
	return 0;
}

void initNewGame() 
{
    kheshig.attack = 10;
    kheshig.defense = 10;
    kheshig.gold = 0;
    kheshig.level = 0;
    kheshig.health = 100;
    kheshig.activeHealth = 100;
    kheshig.activeStamina = 100;
    kheshig.maxStamina = 100;
    kheshig.xp = 0;
    kheshig.currentDay = 1;
    kheshig.loopCount = 0;
    kheshig.currentTimePeriod = 0;
}

int checkSave()
{
	FILE *fp = fopen("data/save.dat","rb");
	if(fp == NULL) 
	{
		return 0;
	}
	fread(&kheshig, sizeof(struct Player), 1, fp);
	fclose(fp);
	return 1;
}

void gameSave() 
{
    struct stat st = {0};
    if (stat("data", &st) == -1) {
        _mkdir("data");
    }

    FILE *fp = fopen("data/save.dat","wb");
    if (fp != NULL) {
        fwrite(&kheshig, sizeof(struct Player), 1, fp);
        fclose(fp);
        // printf("Oyun kaydedildi.\n"); // Test
    }
    else {
        printf("\nCritical Error: Could not create log file! Check folder permissions.\n");
        getch();
    }
}

void xpLevelCalc()
{
	if(kheshig.xp < 100)
	{
		kheshig.level = 0;
	}
	else if(kheshig.xp < 200)
	{
		kheshig.level = 1;
	}
	else if(kheshig.xp < 350)
	{
		kheshig.level = 2;
	}
	else if(kheshig.xp < 550)
	{
		kheshig.level = 3;
	}
	else if(kheshig.xp < 800)
	{
		kheshig.level = 4;
	}
	else if(kheshig.xp < 1100)
	{
		kheshig.level = 5;
	}
	else if(kheshig.xp < 1450)
	{
		kheshig.level = 6;
	}
	else if(kheshig.xp < 1850)
	{
		kheshig.level = 7;
	}
	else if(kheshig.xp < 2300)
	{
		kheshig.level = 8;
	}
	else if(kheshig.xp < 2800)
	{
		kheshig.level = 9;
	}
	else if(kheshig.xp < 3350)
	{
		kheshig.level = 10;
	}
	else if(kheshig.xp < 3950)
	{
		kheshig.level = 11;
	}
	else if(kheshig.xp < 4600)
	{
		kheshig.level = 12;
	}
	else if(kheshig.xp < 5300)
	{
		kheshig.level = 13;
	}
	else if(kheshig.xp < 6050)
	{
		kheshig.level = 14;
	}
	else if(kheshig.xp < 6850)
	{
		kheshig.level = 15;
	}
	else if(kheshig.xp < 7700)
	{
		kheshig.level = 16;
	}
	else if(kheshig.xp < 8600)
	{
		kheshig.level = 17;
	}
	else if(kheshig.xp < 9550)
	{
		kheshig.level = 18;
	}
	else if(kheshig.xp < 10550)
	{
		kheshig.level = 19;
	}
	else if(kheshig.xp < 11600)
	{
		kheshig.level = 20;
	}
	else if(kheshig.xp < 12700)
	{
		kheshig.level = 21;
	}
	else if(kheshig.xp < 13850)
	{
		kheshig.level = 22;
	}
	else if(kheshig.xp < 15050)
	{
		kheshig.level = 23;
	}
	else if(kheshig.xp < 16300)
	{
		kheshig.level = 24;
	}
	else if(kheshig.xp < 17600)
	{
		kheshig.level = 25;
	}
	else if(kheshig.xp < 18950)
	{
		kheshig.level = 26;
	}
	else if(kheshig.xp < 20350)
	{
		kheshig.level = 27;
	}
	else if(kheshig.xp < 21800)
	{
		kheshig.level = 28;
	}
	else if(kheshig.xp < 23300)
	{
		kheshig.level = 29;
	}
	else
	{
		kheshig.level = 30;
	}
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void FirstIntroductionMenu()
{
	system("cls");
	kheshig.activeStamina = kheshig.maxStamina;
	cursorControl();
}

void advanceTimePeriod(int time)
{
	for(int i=0;i<time;i++)
	{
		kheshig.currentTimePeriod++;
	}
	advanceTime();
}

void advanceTime()
{
	if(kheshig.currentTimePeriod == 3)
	{
		kheshig.currentDay++;
		kheshig.currentTimePeriod = 0;
	}
}

void playerStats(char menuName[], int menuNameSize, int viewLineSize, char *viewLineVariable)
{
	if(viewLineSize<51)
	{
		viewLineSize=51;
		viewLineVariable = "==================================================="; 
	}
	int space = (viewLineSize-menuNameSize)/2;
	printf("%s\n", viewLineVariable);
	for(int i=0;i<space;i++)
	{
		printf(" ");
	}
	
	char *menuColor = "\033[92m";
	if(strcmp(menuName, "MAIN MENU") == 0) {
		menuColor = "\033[94m";
	} else if(strcmp(menuName, "WAR MENU") == 0) {
		menuColor = "\033[31m";
	} else if(strcmp(menuName, "MARKET MENU") == 0) {
		menuColor = "\033[95m";
	} else if(strcmp(menuName, "BLACKSMITH MENU") == 0) {
		menuColor = "\033[33m";
	} else if(strcmp(menuName, "THE INN") == 0) {
		menuColor = "\033[36m";
	}
	
	printf("%s%s\033[0m", menuColor, menuName);
	printf("\n%s\n", viewLineVariable);
	printf("\033[91mHP:\033[0m %d/%d ",kheshig.activeHealth ,kheshig.health);
	
	printf("[");
	int t = 0;
	float hpRatio = (float)kheshig.activeHealth / kheshig.health;
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
	printf("]\n");
	printf("\033[36m\033[1mLevel:\033[0m %d\n",kheshig.level);
	printf("\033[37m\033[1mCurrent Xp:\033[0m %d\n",kheshig.xp);
	printf("\033[33m\033[1mGold:\033[0m %d\n",kheshig.gold);
	printf("\033[95m\033[3mAttack:\033[0m %d\n",kheshig.attack);
	printf("\033[33mDefense:\033[0m %d\n",kheshig.defense);
	printf("\033[34mDay:\033[0m %d",kheshig.currentDay);
	if(kheshig.currentTimePeriod == 0)
	{
		printf(" Morning");
	}
	if(kheshig.currentTimePeriod == 1)
	{
		printf(" Noon");
	}
	if(kheshig.currentTimePeriod == 2)
	{
		printf(" Evening");
	}
	printf("\n%s\n", viewLineVariable);
}

void cursorControl()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f')
	{
		system("cls");
		playerStats("MAIN MENU", 9, sizeof(viewLine), viewLine);
		PrintBoard();
		printf("%s",viewLine);
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Quit\n");
		printf("%s\n",viewLine);
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a' || selectedDirection == 75)
        {
            column--;
            if(column < 0) column = 3;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd' || selectedDirection == 77)
        {
            column++;
            if(column > 3) column = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(column==0)
        	{
				column=0;
        		system("cls");
        		warMenu();
			}
			else if(column==1)
			{
				column=0;
				system("cls");
				marketMenu();
			}
			else if(column==2)
			{
				column=0;
				system("cls");
				blacksmithMenu();
			}
			else if(column==3)
			{
				column=0;
				system("cls");
				innMenu();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
        	break;
		}
		else
		{

		}
        
	}
}

void PrintBoard()
{
	int i,j,m,n;
	int columnSize = 4;
	
	for(i=0;i<1;i++)
	{
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardMain[m])+6;n++)
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
				printf("  \033[92m[%s]\033[0m  ",boardMain[j]);
			}
			else
			{
				printf("   %s   ",boardMain[j]);
			}
		}
		printf("|\n");
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardMain[m])+6;n++)
			{
				printf(" ");
			}
		}
		printf("\033[0m|\n");
	}
}
