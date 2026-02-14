#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <direct.h>
#include <errno.h>

#include "../include/MARKETMENU_.h"

static int rowSize = 5;
char boardMarket[5][40] = {"Buy Health Potion(+50H) - 20G","Buy Damage Scroll(+3ATK) - 50G","Buy ARMOR (+3DEF) - 50G","Buy XP Potion(100XP) - 50G","to be continued"};

char viewLineMarket[] = "=======================================================";

int listRow = 0;

void marketMenu()
{
	cursorControlMarket();
}

void noGoldMarket()
{
	printf("\033[31mYou don't have enough gold!\033[0m");
	printf("\n%s\n", viewLineMarket);
	printf("Press any key to continue...");
	printf("\n%s\n", viewLineMarket);
	getch();
	marketMenu();
}

void cursorControlMarket()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f' && selectedDirection != 'Q' && selectedDirection != 'q' && selectedDirection != 13 && selectedDirection != 27)
	{
		system("cls");
		playerStats("MARKET MENU", 11, sizeof(viewLineMarket), viewLineMarket);
		printMarketList();	
		printf("[W-S] Move  |  [F] Select  |  [Q] Back to main menu");
		printf("\n%s\n", viewLineMarket);
		selectedDirection = getch();
		
		if(selectedDirection == '1')
		{
			listRow = 0;
		}
		else if(selectedDirection == '2')
		{
			listRow = 1;
		}
		else if(selectedDirection == '3')
		{
			listRow = 2;
		}
		else if(selectedDirection == '4')
		{
			listRow = 3;
		}

        if(selectedDirection == 'W' || selectedDirection == 'w' || selectedDirection == 72)
        {
            listRow--;
            if(listRow < 0) listRow = rowSize-2;
        }
        else if(selectedDirection == 'S' || selectedDirection == 's' || selectedDirection == 80)
        {
            listRow++;
            if(listRow > rowSize-2) listRow = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f' || selectedDirection == 13)
        {
        	if(listRow==0)
        	{
				if(kheshig.gold<20)
				{
					noGoldMarket();
				}
				else
				{
					kheshig.gold-=20;
					kheshig.activeHealth+=50;
					if(kheshig.activeHealth>kheshig.health)
					{
						kheshig.activeHealth=kheshig.health;
					}
					gameSave();
					system("cls");
					marketMenu();
				}
			}
			else if(listRow==1)
			{
				if(kheshig.gold<50)
				{
					noGoldMarket();
				}
				else
				{
					kheshig.gold-=50;
					kheshig.attack+=3;
					gameSave();
					system("cls");
					marketMenu();
				}
			}
			else if(listRow==2)
			{
				if(kheshig.gold<50)
				{
					noGoldMarket();
				}
				else
				{
					kheshig.gold-=50;
					kheshig.defense+=3;
					gameSave();
					system("cls");
					marketMenu();
				}
			}
			else if(listRow==3)
			{
				if(kheshig.gold<50)
				{
					noGoldMarket();
				}
				else
				{
					kheshig.gold -= 50;
					kheshig.xp += 100;
					xpLevelCalc();
					gameSave();
					system("cls");
					marketMenu();
				}
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q' || selectedDirection == 27)
        {
			listRow=0;
        	FirstIntroductionMenu();
		}
		else
		{

		}
	}
}

void printMarketList()
{
	for(int i=0;i<rowSize;i++)
	{
		if(listRow==i)
		{
			printf("\033[32m%d.%s\033[0m\n",i+1,boardMarket[i]);
		}
		else
		{
			printf("%d.%s\n",i+1,boardMarket[i]);
		}
	}
	printf("%s\n", viewLineMarket);
}