#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "menus/WARMENU_.h"
#include "menus/MARKETMENU_.h"
#include "menus/GAMBLINGMENU_.h"
#include "menus/BLACKSMITHMENU_.h"
#include "menus/CURSORCONTROL_.h"

int row=0;
int column=0;
char board[4][20] = {"War","Market","Blacksmith","Gambling"};
int charHealth = 100;
int charDurability = 100;
int charGold = 0;

//Prototype
void FirstIntroductionMenu();
void hideCursor();
void gotoxy(int x, int y);
void PrintBoard();

int main() 
{
	hideCursor();
	gotoxy(0,0);
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
	cursorControl("Bloodthirsty Kheshig");
}

void PrintBoard()
{
	int i,j;
	
	for(i=0;i<1;i++)
	{
		printf("--------------------------------------------------------\n");
		printf("|         |            |                |              |\n");
		for(j=0;j<4;j++)
		{
			printf("|");
			if(i==row && j== column)
			{
				printf("  [%s]  ",board[j]);
			}
			else
			{
				printf("   %s   ",board[j]);
			}
		}
		printf("|");
		printf("\n");
		printf("|_________|____________|________________|______________|\n");
	}
}
