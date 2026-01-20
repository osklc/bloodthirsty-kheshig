#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "../include/MARKETMENU_.h"

char boardMarket[4][30] = {"Buy Health Potion - 50G","Buy Damage Scroll - 120G","Buy Revive Token - 300G","Sell Items"};

void marketMenu()
{
	cursorControlMarket();
}

void cursorControlMarket()
{
	char selectedDirection = '\0';
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		printf("\033[96m\033[3mMARKET MENU\033[0m\n");
		printf("\033[31m\033[1mHealth:\033[0m %d",charHealth);
		printf("\n\033[36m\033[1mDurability:\033[0m %d",charDurability);
		printf("\n\033[33m\033[1mGold:\033[0m %d\n",charGold);
		PrintBoardMarket();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu");
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
			else if(column==3)
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
			printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
			Sleep(1000);
		}
        
	}
}

void PrintBoardMarket()
{
	int i,j,m,n;
	int columnSize = 4;
	
	for(i=0;i<1;i++)
	{
		for(m=0;m<columnSize;m++)
		{
			printf(" ");
			for(n=0;n<strlen(boardMarket[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m\n");
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardMarket[m])+6;n++)
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
				printf("  [%s]  ",boardMarket[j]);
			}
			else
			{
				printf("   %s   ",boardMarket[j]);
			}
		}
		printf("|\n");
		for(m=0;m<columnSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardMarket[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m|\n");
	}
}