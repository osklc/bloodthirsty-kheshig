#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/WARMENU_.h"
#include "include/MARKETMENU_.h"
#include "include/GAMBLINGMENU_.h"
#include "include/BLACKSMITHMENU_.h"

int row=0;
int column=0;
char boardMain[4][20] = {"War","Market","Blacksmith","Gambling"};

char viewLine[] = "\n==================================================\n";

struct Player kheshig;

//Prototype
void FirstIntroductionMenu();
void hideCursor();
void gotoxy(int x, int y);
void PrintBoard();
void cursorControl();
int checkSave();
void gameSave();

int main() 
{
	hideCursor();
	gotoxy(0,0);
	printf("\033[31m\033[3mBLOODTHIRSTY KHESHIG\033[0m\n");
	//Sleep(1000);

	if (checkSave() == 0)
	{
		//printf("New game");

		kheshig.attack=1;
		kheshig.defense=1;
		kheshig.gold=0;
		kheshig.level=0;
		kheshig.health=100;
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

	cursorControl();
}

void cursorControl()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f')
	{
		system("cls");
		printf("\033[94m\033[3mMAIN MENU\033[0m");
		printf("%s",viewLine);
		printf("\033[91mHealth:\033[0m %d\n",kheshig.health);
		printf("\033[36m\033[1mLevel:\033[0m %d\n",kheshig.level);
		printf("\033[33m\033[1mGold:\033[0m %d\n",kheshig.gold);
		printf("\033[95m\033[3mAttack:\033[0m %d\n",kheshig.attack);
		printf("\033[33mDefense:\033[0m %d\n",kheshig.defense);
		PrintBoard();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Quit");
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
        	printf("\nProgram is closed.");
        	Sleep(200);
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
