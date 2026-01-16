#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int row=0;
int column=0;
char board[4][20] = {"War","Market","Blacksmith","Gambling"};

//Prototype
void FirstIntroductionMenu();
void hideCursor();
void gotoxy(int x, int y);
void cursorControl();
void PrintBoard();
void warMenu();
void marketMenu();
void blacksmithMenu();
void gamblingMenu();

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
	cursorControl();
	
	
}


void cursorControl()
{
	char selectedDirection;
	
	while(selectedDirection != 'F' && selectedDirection != 'f')
	{
		system("cls");
		printf("\033[31m\033[3mBloodthirsty Kheshig\033[0m\n");
		PrintBoard();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Quit");
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a')
        {
            column--;
            if(column < 0) column = 0;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd')
        {
            column++;
            if(column > 3) column = 3;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(column==0)
        	{
        		system("cls");
        		warMenu();
			}
			else if(column==1)
			{
				system("cls");
			}
			else if(column==2)
			{
				system("cls");
			}
			else if(column==3)
			{
				system("cls");
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

void warMenu()
{
	
}

void marketMenu()
{
	
}

void blacksmithMenu()
{
	
}

void gamblingMenu()
{
	
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
