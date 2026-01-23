#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "../include/GAMBLINGMENU_.h"

char boardGambling[3][40] = {"Coin Flip - 50G","Dice Roll - 100G","Underground Arena - 300G"};

void gamblingMenu()
{
	cursorControlGambling();
}

void cursorControlGambling()
{
	char selectedDirection = '\0';
	char viewLine[] = "=============================================================================";
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		printf("%s\n", viewLine);
		printf("\033[92m\033[3m                                GAMBLING MENU\033[0m");
		printf("\n%s\n", viewLine);
		printf("\033[91mHealth:\033[0m %d\n",kheshig.health);
		printf("\033[36m\033[1mLevel:\033[0m %d\n",kheshig.level);
		printf("\033[33m\033[1mGold:\033[0m %d\n",kheshig.gold);
		printf("\033[95m\033[3mAttack:\033[0m %d\n",kheshig.attack);
		printf("\033[33mDefense:\033[0m %d",kheshig.defense);
		printf("\n%s\n", viewLine);
		PrintBoardGambling();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("\n%s\n", viewLine);
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a' || selectedDirection == 75)
        {
            column--;
            if(column < 0) column = 2;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd' || selectedDirection == 77)
        {
            column++;
            if(column > 2) column = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(column==0)
        	{
        		system("cls");

			}
			else if(column==1)
			{
				system("cls");

			}
			else if(column==2)
			{
				system("cls");

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

void PrintBoardGambling()
{
	int i,j,m,n;
	int columnSize = 3;
	
	for(i=0;i<1;i++)
	{
		for(m=0;m<columnSize;m++)
		{
			printf(" ");
			for(n=0;n<strlen(boardGambling[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m\n");
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardGambling[m])+6;n++)
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
				printf("  \033[92m[%s]\033[0m  ",boardGambling[j]);
			}
			else
			{
				printf("   %s   ",boardGambling[j]);
			}
		}
		printf("|\n");
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardGambling[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m|\n");
	}
}