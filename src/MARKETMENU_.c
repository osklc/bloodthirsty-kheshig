#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#include "../include/MARKETMENU_.h"

char boardMarket[4][40] = {"Buy Health Potion(HEALTH+50) - 20G","Buy Damage Scroll(ATK+3) - 120G","Buy ARMOR (DEF+3) - 120G","Sell Items"};

char viewLineMarket[] = "========================================================";

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
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		playerStats("MARKET MENU", 11, sizeof(viewLineMarket), viewLineMarket);
		printMarketList();	
		printf("[W-S] Move  |  [F] Select  |  [Q] Back to main menu");
		printf("\n%s\n", viewLineMarket);
		selectedDirection = getch();
		
        if(selectedDirection == 'W' || selectedDirection == 'w' || selectedDirection == 72)
        {
            listRow--;
            if(listRow < 0) listRow = 3;
        }
        else if(selectedDirection == 'S' || selectedDirection == 's' || selectedDirection == 80)
        {
            listRow++;
            if(listRow > 3) listRow = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(listRow==0)
        	{
				if(kheshig.gold<20)
				{
					noGoldMarket();
				}
				kheshig.gold-=20;
				kheshig.activeHealth+=50;
				if(kheshig.activeHealth>kheshig.health)
				{
					kheshig.activeHealth=kheshig.health;
				}
				gameSave();
				system("cls");
				cursorControlMarket();
			}
			else if(listRow==1)
			{
				if(kheshig.gold<120)
				{
					noGoldMarket();
				}
				kheshig.gold-=120;
				kheshig.attack+=3;
				gameSave();
				system("cls");
				cursorControlMarket();
			}
			else if(listRow==2)
			{
				if(kheshig.gold<120)
				{
					noGoldMarket();
				}
				kheshig.gold-=120;
				kheshig.defense+=3;
				gameSave();
				system("cls");
				cursorControlMarket();
			}
			else if(listRow==3)
			{
				printf("In process");
				marketMenu();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
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
	for(int i=0;i<4;i++)
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