#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "CURSORCONTROL_.h"

void cursorControl()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f')
	{
		system("cls");
		printf("\033[31m\033[3mBloodthirsty Kheshig\033[0m\n");
		PrintBoard();
		//printf("\nActive Cell: [%d , %d]", row, column); // For Debug
		printf("\n[A-D] Move  |  [F] Select  |  [Q] Quit");
		selectedDirection = getch();
		
        if(selectedDirection == 'A' || selectedDirection == 'a')
        {
            column--;
            if(column < 0) column = 0;
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd')
        {
            column++;
            if(column > 3) column = 3;
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(column==0)
        	{
        		system("cls");
        		warMenu();
			}
			else if(column==1)
			{
				system("cls");
				marketMenu();
			}
			else if(column==2)
			{
				system("cls");
				blacksmithMenu();
			}
			else if(column==3)
			{
				system("cls");
				gamblingMenu();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
        	printf("\nProgram is closed.");
        	Sleep(200);
        	break;
		}
		else
		{
			printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
			Sleep(1000);
		}
        
	}
}