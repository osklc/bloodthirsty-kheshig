#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "WARMENU_.h"

void warMenu()
{
	printf("\033[35m\033[3mWar Menu\033[0m\n");
	printf("\n\033[31m\033[3mHealth:\033[0m %d",charHealth);
	printf("\n\033[36m\033[3mDurability:\033[0m %d",charDurability);
	printf("\n\033[33m\033[3mGold:\033[0m %d",charGold);
	printf("\n[A-D] Move  |  [F] Select  |  [Q] Quit");
}
