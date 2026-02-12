#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <direct.h>
#include <sys/stat.h>

#include "../include/BLACKSMITHMENU_.h"

char boardBlackSmith[4][40] = {"Sword Upgrade(ATK+(3-1)) - 90G","Armor Upgrade (DEF+(3-1)) - 90G"};

char viewLineBlackSmith[] = "========================================================";

int listRowBlackSmith = 0;

void blacksmithMenu()
{
	cursorControlBlackSmith();
}

void cursorControlBlackSmith()
{
	char selectedDirection = '\0';
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
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
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(listRowBlackSmith==0)
        	{
				if(kheshig.gold<90)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLineBlackSmith);
					printf("Press any key to continue...");
					printf("\n%s\n", viewLineBlackSmith);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=90;
				int chance = rand() % 100;
				if(chance<20)
				{
					kheshig.attack += 1;
				}
				else if(chance<80)
				{
					kheshig.attack +=2;
				}
				else if(chance<100)
				{
					kheshig.attack +=3;
				}
				gameSave();
				system("cls");
				cursorControlBlackSmith();
			}
			else if(listRowBlackSmith==1)
			{
				if(kheshig.gold<90)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLineBlackSmith);
					printf("Press any key to continue...");
					printf("\n%s\n", viewLineBlackSmith);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=90;
				int chanceDef = rand() % 100;
				if(chanceDef<20)
				{
					kheshig.attack += 1;
				}
				else if(chanceDef<80)
				{
					kheshig.attack +=2;
				}
				else if(chanceDef<100)
				{
					kheshig.attack +=3;
				}
				gameSave();
				system("cls");
				cursorControlBlackSmith();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
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