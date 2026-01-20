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
int charHealth = 100;
int charDurability = 100;
int charGold = 0;

//Prototype
void FirstIntroductionMenu();
void hideCursor();
void gotoxy(int x, int y);
void PrintBoard();
void cursorControl();

int main() 
{
	hideCursor();
	gotoxy(0,0);
	printf("\033[31m\033[3mBLOODTHIRSTY KHESHIG\033[0m\n");
	Sleep(1000);
	FirstIntroductionMenu();
	return 0;
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
		printf("\033[94m\033[3mMAIN MENU\033[0m\n");
		printf("\033[31m\033[1mHealth:\033[0m %d\n",charHealth);
		printf("\033[36m\033[1mDurability:\033[0m %d\n",charDurability);
		printf("\033[33m\033[1mGold:\033[0m %d\n",charGold);
		PrintBoard();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Quit");
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a')
        {
            column--;
            if(column < 0) column = 3;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd')
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
			printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
			Sleep(1000);
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
				printf("  [%s]  ",boardMain[j]);
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
