#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <direct.h>
#include <errno.h>

#include "../include/INNMENU_.h"

char boardInn[3][60] = {"Rest(+25HP) - 5G (1 period passes)", "Work at Inn - Earn 5G (1 period passes)", "Gamble"};
char boardGambling[3][60] = {"Coin Flip - Bet 30G (50%% win chance, x2 reward)", "Dice Roll - Bet 50G (50%% win chance, x2 reward)", "High Stakes - Bet 100G (30%% win chance, x5 reward)"};
char viewLineInn[] = "========================================================";
int listRowInn = 0;
int listRowGambling = 0;
int rowSize = 3;

void innMenu()
{
	cursorControlInn();
}

void cursorControlInn()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f' && selectedDirection != 'Q' && selectedDirection != 'q' && selectedDirection != 13 && selectedDirection != 27)
	{
		system("cls");
		playerStats("THE INN", 7, sizeof(viewLineInn), viewLineInn);
		printInnList();
		printf("[W-S] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("%s\n",viewLineInn);
		selectedDirection = getch();
		
		if(selectedDirection == 'W' || selectedDirection == 'w' || selectedDirection == 72)
		{
			listRowInn--;
			if(listRowInn < 0) listRowInn = 2;
		}
		else if(selectedDirection == 'S' || selectedDirection == 's' || selectedDirection == 80)
		{
			listRowInn++;
			if(listRowInn > 2) listRowInn = 0;
		}
        else if(selectedDirection == 'F' || selectedDirection == 'f' || selectedDirection == 13)
        {
			if(listRowInn==0)
        	{
				if(kheshig.gold<10)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLineInn);
					printf("Press any key to return to the main menu.");
					printf("\n%s\n", viewLineInn);
					getch();
					cursorControlInn();
				}
				else
				{
					kheshig.gold-=5;
					kheshig.activeHealth+=25;
					if(kheshig.activeHealth>kheshig.health)
					{
						kheshig.activeHealth=kheshig.health;
					}
					advanceTimePeriod(1);
					gameSave();
					system("cls");
					cursorControlInn();
				}
			}
			else if(listRowInn==1)
			{
				kheshig.gold += 5;
				advanceTimePeriod(1);
				gameSave();
				system("cls");
				cursorControlInn();
			}
			else if(listRowInn==2)
			{
				playGambling();
			}
        }
        else if(selectedDirection == 'Q' || selectedDirection == 'q' || selectedDirection == 27)
        {
			listRowInn = 0;
            FirstIntroductionMenu();
        }
	}
}

void printInnList()
{
	for(int i=0;i<3;i++)
	{
		if(listRowInn==i)
		{
			printf("\033[32m%d.%s\033[0m\n", i+1, boardInn[i]);
		}
		else
		{
			printf("%d.%s\n", i+1, boardInn[i]);
		}
	}
	printf("%s\n", viewLineInn);
}

void noGoldGambling()
{
	printf("\n\033[31mYou don't have enough gold!\033[0m");
	printf("\n%s\n", viewLineInn);
	printf("Press any key to continue...");
	printf("\n%s\n", viewLineInn);
	getch();
	playGambling();
}

void playGambling()
{
	char choiceGambling = '\0';
	while((choiceGambling != 'F' && choiceGambling != 'f') && (choiceGambling != 'Q' && choiceGambling != 'q'))
	{
		system("cls");
		printf("%s\n", viewLineInn);
		printf("\033[33m                         GAMBLING\033[0m\n");
		printf("%s\n", viewLineInn);
		printf("\033[33m\033[1mYour Gold:\033[0m %d\n\n", kheshig.gold);
		printGamblingList();
		printf("\n[W-S] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("%s", viewLineInn);
		
		choiceGambling = getch();

		if(choiceGambling == 'W' || choiceGambling == 'w' || choiceGambling == 72)
		{
			listRowGambling--;
			if(listRowGambling < 0) listRowGambling = rowSize-1;
		}
		else if(choiceGambling == 'S' || choiceGambling == 's' || choiceGambling == 80)
		{
			listRowGambling++;
			if(listRowGambling > rowSize-1) listRowGambling = 0;
		}

		else if(choiceGambling == 'F' || choiceGambling == 'f')
		{
			if(listRowGambling == 0)
			{
				if(kheshig.gold < 30)
				{
					printf("\n\033[31mNot enough gold!\033[0m\n");
					printf("Press any key to continue...\n");
					getch();
					playGambling();
					return;
				}
				
				kheshig.gold -= 30;
				int result = rand() % 2;
				
				system("cls");
				printf("%s\n", viewLineInn);
				printf("\033[96m\033[3m                    COIN FLIP\033[0m\n");
				printf("%s\n", viewLineInn);
				
				if(result == 0)
				{
					printf("\033[92mYOU WIN!\033[0m\n");
					printf("Flipped Heads! You won 60 gold!\n");
					kheshig.gold += 60;
				}
				else
				{
					printf("\033[91mYOU LOSE!\033[0m\n");
					printf("Flipped Tails! Better luck next time.\n");
				}
				
				printf("\nYour Gold: %d\n", kheshig.gold);
				printf("%s\n", viewLineInn);
				printf("Press any key to continue...\n");
				getch();
				gameSave();
				playGambling();
			}
			else if(listRowGambling == 1)
			{
				if(kheshig.gold < 50)
				{
					printf("\n\033[31mNot enough gold!\033[0m\n");
					printf("Press any key to continue...\n");
					getch();
					playGambling();
					return;
				}
				
				kheshig.gold -= 50;
				int dice = (rand() % 6) + 1;
				
				system("cls");
				printf("%s\n", viewLineInn);
				printf("\033[96m\033[3m                     DICE ROLL\033[0m\n");
				printf("%s\n", viewLineInn);
				printf("You rolled: %d\n\n", dice);
				
				if(dice >= 4)
				{
					printf("\033[92mYOU WIN!\033[0m\n");
					printf("You rolled %d! You won 100 gold!\n", dice);
					kheshig.gold += 100;
				}
				else
				{
					printf("\033[91mYOU LOSE!\033[0m\n");
					printf("You rolled %d. You needed 4 or higher.\n", dice);
				}
				
				printf("\nYour Gold: %d\n", kheshig.gold);
				printf("%s\n", viewLineInn);
				printf("Press any key to continue...\n");
				getch();
				gameSave();
				playGambling();
			}
			else if(listRowGambling == 2)
			{
				if(kheshig.gold < 100)
				{
					printf("\n\033[31mNot enough gold!\033[0m\n");
					printf("Press any key to continue...\n");
					getch();
					playGambling();
					return;
				}
				
				kheshig.gold -= 100;
				int result = rand() % 100;
				
				system("cls");
				printf("%s\n", viewLineInn);
				printf("\033[95m\033[3m                   HIGH STAKES\033[0m\n");
				printf("%s\n", viewLineInn);
				
				if(result < 30)
				{
					printf("\033[92mJACKPOT!\033[0m\n");
					printf("The gods favor the bold! You won 500 gold!\n");
					kheshig.gold += 500;
				}
				else
				{
					printf("\033[91mBUSTED!\033[0m\n");
					printf("Lady Luck was not with you today...\n");
				}
				
				printf("\nYour Gold: %d\n", kheshig.gold);
				printf("%s\n", viewLineInn);
				printf("Press any key to continue...\n");
				getch();
				gameSave();
				playGambling();
			}
		}

		else if(choiceGambling == 'Q' || choiceGambling == 'q')
		{
			listRowGambling=0;
			cursorControlInn();
		}
		else
		{

		}
	}
}

void printGamblingList()
{
	for(int i=0;i<rowSize;i++)
	{
		if(listRowGambling==i)
		{
			printf("\033[32m%d.%s\033[0m\n",i+1,boardGambling[i]);
		}
		else
		{
			printf("%d.%s\n",i+1,boardGambling[i]);
		}
	}
	printf("%s\n", viewLineInn);
}