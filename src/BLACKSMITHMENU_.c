#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "../include/BLACKSMITHMENU_.h"

char boardBlacksmith[3][40] = {"Upgrade Sword (+5 DMG) - 200G","Repair Armor - 100G","Forge New Weapon"};

void blacksmithMenu()
{
	cursorControlBlacksmith();
}

void cursorControlBlacksmith()
{
	char selectedDirection = '\0';
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		printf("\033[33m\033[3mBLACKSMITH MENU\033[0m\n");
		printf("\033[91mHealth:\033[0m %d\n",kheshig.health);
		printf("\033[36m\033[1mLevel:\033[0m %d\n",kheshig.level);
		printf("\033[33m\033[1mGold:\033[0m %d\n",kheshig.gold);
		printf("\033[95m\033[3mAttack:\033[0m %d\n",kheshig.attack);
		printf("\033[33mDefense:\033[0m %d\n",kheshig.defense);
		PrintBoardBlacksmith();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu");
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

void PrintBoardBlacksmith()
{
	int i,j,m,n;
	
	for(i=0;i<1;i++)
	{
		for(m=0;m<3;m++)
		{
			printf(" ");
			for(n=0;n<strlen(boardBlacksmith[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m\n");
		for(m=0;m<3;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardBlacksmith[m])+6;n++)
			{
				printf(" ");
			}
		}
		printf("|\n");
		for(j=0;j<3;j++)
		{
			printf("|");
			if(i==row && j== column)
			{
				printf("  \033[92m[%s]\033[0m  ",boardBlacksmith[j]);
			}
			else
			{
				printf("   %s   ",boardBlacksmith[j]);
			}
		}
		printf("|\n");
		for(m=0;m<3;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardBlacksmith[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m|\n");
	}
}