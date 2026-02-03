#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "../include/INNMENU_.h"

char boardInn[3][40] = {"Rest - 50G", "Gamble", "Continue"};
char viewLineInn[] = "========================================================";
int innColumn = 0;

void innMenu()
{
	cursorControlInn();
}

void cursorControlInn()
{
	char selectedDirection = '\0';
	
	while((selectedDirection != 'F' && selectedDirection != 'f') && (selectedDirection != 'Q' && selectedDirection != 'q'))
	{
		system("cls");
		playerStats("THE INN", 7, sizeof(viewLineInn), viewLineInn);
		printInnList();
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Back to main menu");
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a' || selectedDirection == 75)
        {
            innColumn--;
            if(innColumn < 0) innColumn = 2;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd' || selectedDirection == 77)
        {
            innColumn++;
            if(innColumn > 2) innColumn = 0;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(innColumn==0)
        	{
				if(kheshig.gold<50)
				{
					printf("\033[31mYou don't have enough gold!\033[0m");
					printf("\n%s\n", viewLineInn);
					printf("Press any key to return to the main menu.");
					printf("\n%s\n", viewLineInn);
					getch();
					FirstIntroductionMenu();
				}
				kheshig.gold-=50;
				kheshig.activeHealth+=50;
				if(kheshig.activeHealth>kheshig.health)
				{
					kheshig.activeHealth=kheshig.health;
				}
				gameSave();
				system("cls");
				cursorControlInn();
			}
			else if(innColumn==1)
			{
				playGambling();
			}
			else if(innColumn==2)
			{
				FirstIntroductionMenu();
			}
        }
        else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
            FirstIntroductionMenu();
        }
	}
}

void printInnList()
{
	int i, j, m, n;
	int itemSize = 3;
	
	for(i=0;i<1;i++)
	{
		for(m=0;m<itemSize;m++)
		{
			printf(" ");
			for(n=0;n<strlen(boardInn[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m\n");
		for(m=0;m<itemSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardInn[m])+6;n++)
			{
				printf(" ");
			}
		}
		printf("|\n");
		for(j=0;j<itemSize;j++)
		{
			printf("|");
			if(j== innColumn)
			{
				printf("  \033[96m[%s]\033[0m  ", boardInn[j]);
			}
			else
			{
				printf("   %s   ", boardInn[j]);
			}
		}
		printf("|\n");
		for(m=0;m<itemSize;m++)
		{
			printf("|");
			for(n=0;n<strlen(boardInn[m])+6;n++)
			{
				printf("\033[4m ");
			}
		}
		printf("\033[0m|\n");
	}
}

void playGambling()
{
	system("cls");
	printf("%s\n", viewLineInn);
	printf("\033[96m\033[3m                         GAMBLING\033[0m\n");
	printf("%s\n", viewLineInn);
	printf("\033[33m\033[1mYour Gold:\033[0m %d\n\n", kheshig.gold);
	printf("1. Coin Flip - Bet 30G (50%% win chance, x2 reward)\n");
	printf("2. Dice Roll - Bet 50G (50%% win chance, x2 reward)\n");
	printf("3. High Stakes - Bet 100G (30%% win chance, x5 reward)\n");
	printf("\n[1-3] Select game or [Q] Back\n");
	printf("%s\n", viewLineInn);
	
	char choice = getch();
	
	if(choice == '1')
	{
		if(kheshig.gold < 30)
		{
			printf("\033[31mNot enough gold!\033[0m\n");
			printf("Press any key to continue...\n");
			getch();
			cursorControlInn();
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
			printf("\033[92m✓ YOU WIN!\033[0m\n");
			printf("Flipped Heads! You won 60 gold!\n");
			kheshig.gold += 60;
		}
		else
		{
			printf("\033[91m✗ YOU LOSE!\033[0m\n");
			printf("Flipped Tails! Better luck next time.\n");
		}
		
		printf("\nYour Gold: %d\n", kheshig.gold);
		printf("%s\n", viewLineInn);
		printf("Press any key to continue...\n");
		getch();
		gameSave();
		cursorControlInn();
	}
	else if(choice == '2')
	{
		if(kheshig.gold < 50)
		{
			printf("\033[31mNot enough gold!\033[0m\n");
			printf("Press any key to continue...\n");
			getch();
			cursorControlInn();
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
			printf("\033[92m✓ YOU WIN!\033[0m\n");
			printf("You rolled %d! You won 100 gold!\n", dice);
			kheshig.gold += 100;
		}
		else
		{
			printf("\033[91m✗ YOU LOSE!\033[0m\n");
			printf("You rolled %d. You needed 4 or higher.\n", dice);
		}
		
		printf("\nYour Gold: %d\n", kheshig.gold);
		printf("%s\n", viewLineInn);
		printf("Press any key to continue...\n");
		getch();
		gameSave();
		cursorControlInn();
	}
	else if(choice == '3')
	{
		if(kheshig.gold < 100)
		{
			printf("\033[31mNot enough gold!\033[0m\n");
			printf("Press any key to continue...\n");
			getch();
			cursorControlInn();
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
			printf("\033[92m✓ JACKPOT!\033[0m\n");
			printf("The gods favor the bold! You won 500 gold!\n");
			kheshig.gold += 500;
		}
		else
		{
			printf("\033[91m✗ BUSTED!\033[0m\n");
			printf("Lady Luck was not with you today...\n");
		}
		
		printf("\nYour Gold: %d\n", kheshig.gold);
		printf("%s\n", viewLineInn);
		printf("Press any key to continue...\n");
		getch();
		gameSave();
		cursorControlInn();
	}
	else if(choice == 'Q' || choice == 'q')
	{
		cursorControlInn();
	}
	else
	{
		cursorControlInn();
	}
}