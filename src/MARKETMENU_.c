#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#include "../include/MARKETMENU_.h"

char boardMarket[4][32] = {"Buy Health Potion - 50G","Buy Damage Scroll(ATK+3) - 120G","Buy ARMOR (DEF+3) - 120G","Sell Items"};

void marketMenu()
{
	cursorControlMarket();
}

void cursorControlMarket()
{
	char selectedDirection = '\0';
	char viewLine[] = "=============================================================================================================";
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		printf("%s\n", viewLine);
		printf("\033[96m\033[3m                                                 MARKET MENU\033[0m");
		printf("\n%s\n", viewLine);
		printf("\033[91mHealth:\033[0m %d\n",kheshig.health);
		printf("\033[36m\033[1mLevel:\033[0m %d\n",kheshig.level);
		printf("\033[33m\033[1mGold:\033[0m %d\n",kheshig.gold);
		printf("\033[95m\033[3mAttack:\033[0m %d\n",kheshig.attack);
		printf("\033[33mDefense:\033[0m %d",kheshig.defense);
		printf("\n%s\n", viewLine);
		PrintBoardMarket();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("\n%s\n", viewLine);
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
				if(kheshig.gold<50)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLine);
					printf("Press any key to return to the main menu.");
					printf("\n%s\n", viewLine);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=50;
				kheshig.health+=10;
				gameSave();
				system("cls");
				cursorControlMarket();
			}
			else if(column==1)
			{
				if(kheshig.gold<120)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLine);
					printf("Press any key to return to the main menu.");
					printf("\n%s\n", viewLine);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=120;
				kheshig.attack+=3;
				gameSave();
				system("cls");
				cursorControlMarket();
			}
			else if(column==2)
			{
				if(kheshig.gold<120)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLine);
					printf("Press any key to return to the main menu.");
					printf("\n%s\n", viewLine);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=120;
				kheshig.defense+=3;
				gameSave();
				system("cls");
				cursorControlMarket();
			}
			else if(column==3)
			{
				printf("In process");
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
				printf("  \033[92m[%s]\033[0m  ",boardMarket[j]);
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