#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <direct.h>
#include <errno.h>

#include "../include/BLACKSMITHMENU_.h"

char boardBlackSmith[4][40] = {"Sword Upgrade(ATK+(5-3)) - 80G","Armor Upgrade (DEF+(5-3)) - 80G"};

char viewLineBlackSmith[] = "========================================================";

int listRowBlackSmith = 0;

void blacksmithMenu()
{
	cursorControlBlackSmith();
}

void cursorControlBlackSmith()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f' && selectedDirection != 'Q' && selectedDirection != 'q' && selectedDirection != 13 && selectedDirection != 27)
	{
		system("cls");
		playerStats("BLACKSMITH MENU", 15, sizeof(viewLineBlackSmith), viewLineBlackSmith);
		printBlackSmithList();
		printf("[W-S] Move  |  [F] Select  |  [Q] Back to main menu");
		printf("\n%s\n", viewLineBlackSmith);
		selectedDirection = getch();
		
        if(selectedDirection == 'W' || selectedDirection == 'w' || selectedDirection == 72)
        {
            listRowBlackSmith--;
            if(listRowBlackSmith < 0) listRowBlackSmith = 1;
        }
        else if(selectedDirection == 'S' || selectedDirection == 's' || selectedDirection == 80)
        {
            listRowBlackSmith++;
            if(listRowBlackSmith > 1) listRowBlackSmith = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f' || selectedDirection == 13)
        {
        	if(listRowBlackSmith==0)
        	{
				if(kheshig.gold<80)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLineBlackSmith);
					printf("Press any key to continue...");
					printf("\n%s\n", viewLineBlackSmith);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=80;
				int chance = rand() % 100;
				if(chance<20)
				{
					kheshig.attack += 3;
				}
				else if(chance<80)
				{
					kheshig.attack +=4;
				}
				else if(chance<100)
				{
					kheshig.attack +=5;
				}
				gameSave();
				system("cls");
				cursorControlBlackSmith();
			}
			else if(listRowBlackSmith==1)
			{
				if(kheshig.gold<80)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLineBlackSmith);
					printf("Press any key to continue...");
					printf("\n%s\n", viewLineBlackSmith);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=80;
				int chanceDef = rand() % 100;
				if(chanceDef<20)
				{
					kheshig.attack += 3;
				}
				else if(chanceDef<80)
				{
					kheshig.attack +=4;
				}
				else if(chanceDef<100)
				{
					kheshig.attack +=5;
				}
				gameSave();
				system("cls");
				cursorControlBlackSmith();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q' || selectedDirection == 27)
        {
			listRowBlackSmith=0;
        	FirstIntroductionMenu();
		}
		else
		{
			//printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
			//Sleep(1000);
		}
        
	}
}

void printBlackSmithList()
{
	for(int i=0;i<2;i++)
	{
		if(listRowBlackSmith==i)
		{
			printf("\033[32m%d.%s\033[0m\n",i+1,boardBlackSmith[i]);
		}
		else
		{
			printf("%d.%s\n",i+1,boardBlackSmith[i]);
		}
	}
	printf("%s\n", viewLineBlackSmith);
}