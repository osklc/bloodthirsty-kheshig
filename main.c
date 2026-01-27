#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "include/WARMENU_.h"
#include "include/MARKETMENU_.h"
#include "include/GAMBLINGMENU_.h"
#include "include/BLACKSMITHMENU_.h"

int row=0;
int column=0;
char boardMain[4][20] = {"War","Market","Blacksmith","Gambling"};

char viewLine[] = "========================================================";

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

int main() 
{
	srand(time(NULL));
	hideCursor();
	gotoxy(0,0);
	printf("\033[31m\033[3mBLOODTHIRSTY KHESHIG\033[0m\n");
	//Sleep(1000);	
	
	if (checkSave() == 0)
	{
		//printf("New game");

		kheshig.attack=10;
		kheshig.defense=10;
		kheshig.gold=0;
		kheshig.level=0;
		kheshig.health=100;
		kheshig.xp=0;
		gameSave();
	}
	FirstIntroductionMenu();
	return 0;
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
    FILE *fp = fopen("data/save.dat","wb");
    if (fp != NULL) {
        fwrite(&kheshig, sizeof(struct Player), 1, fp);
        fclose(fp);
		//Sleep(1000);
        //printf(">> Game Saved <<\n");
    }
	else {
		//Sleep(1000);
        //printf("ERROR: Save file cant open!\n");
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
	cursorControl();
}

void cursorControl()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f')
	{
		system("cls");
		printf("%s\n", viewLine);
		printf("\033[94m\033[3m                       MAIN MENU\033[0m");
		printf("\n%s\n", viewLine);
		printf("\033[91mHealth:\033[0m %d\n",kheshig.health);
		printf("\033[36m\033[1mLevel:\033[0m %d\n",kheshig.level);
		printf("\033[33m\033[1mGold:\033[0m %d\n",kheshig.gold);
		printf("\033[95m\033[3mAttack:\033[0m %d\n",kheshig.attack);
		printf("\033[33mDefense:\033[0m %d",kheshig.defense);
		printf("\n%s\n",viewLine);
		PrintBoard();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Quit\n");
		printf("\n%s\n",viewLine);
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
				gamblingMenu();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
        	//printf("\nProgram is closed.");
        	//Sleep(200);
        	break;
		}
		else
		{
			//printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
			//Sleep(1000);
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
			printf(" ");
			for(n=0;n<strlen(boardMain[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m\n");
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
				printf("\033[4m ");
			}
		}
		printf("\033[0m|\n");
	}
}
