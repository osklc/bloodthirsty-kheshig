#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <direct.h>
#include <errno.h>

#define WAR_LINE_SIZE 1024
#define MAX_VISIBLE_LOGS 5

#define SILENT_WOODS_START 0
#define SILENT_WOODS_END 9
#define ROTTING_GLADE_START 10
#define ROTTING_GLADE_END 19
#define VOID_HORIZON_START 20

#include "../include/WARMENU_.h"

static int rowSize = 3;
char boardWar[3][20] = {"Start War","War Training","to be continued"};

int listRowWar = 0;
char places[3][20] = {"Northern Forests", "Hell", "Glacial Mountains"};

char viewLineWar[] = "=======================================================";

char warLogs[MAX_VISIBLE_LOGS][WAR_LINE_SIZE];
int currentLogCount = 0;

Enemy enemyPool[] = {
    // --- THE SILENT WOODS (Level 0-9) - Reality starts to feel "Off"
    // "Grey Wolf" -> "Pale Wolf" (Rengi solmuş, hasta gibi)
    {"Silent Woods", "Dire Wolf",            35,  12,  5,  25, 0,  35, "paw","fur"},
    // "Wild Boar" -> "Staring Boar" (Saldırmıyor, sadece sana bakıyor... ta ki sen saldırana kadar)
    {"Silent Woods", "Giant Bear",           45,  13,  9,  30, 1,  38, "paw","fur"},
	// "Brown Bear" -> "Static Bear" (Bazen olduğu yerde donup kalıyor, glitch gibi)
    {"Silent Woods", "Knight of Ignisum",    38,  14,  7,  28, 2,  40, "attack scroll", "defense scroll"},
    // "Forest Bandit" -> "Hollow Wanderer" (Yüzü yok, sadece kıyafet)
    {"Silent Woods", "Lost Traveler",        55,  15,  6,  35, 3,  42, "attack scroll", "defense scroll"},
    // "Rabid Fox" -> "Mimic Fox" (Tilki sesi değil, çocuk sesi çıkarıyor)
    {"Silent Woods", "Imitative Fox",        75,  17,  10,  40, 4,  45, "paw", "fur"},
    // "Outlaw Archer" -> "Stuck Hunter" (Aynı cümleyi sürekli tekrar ediyor)
    {"Silent Woods", "Stuck Hunter",         60,  17,  12,  38, 5,  43, "attack scroll", "defense scroll"},
    // "Feral Lynx" -> "Shadowless Lynx" (Gölgesi yok)
    {"Silent Woods", "Shadowless Lynx",      50,  18,  10,  36, 5,  41, "paw", "fur"},
    // "Mountain Lion" -> "Twisted Lion" (Boynu imkansız bir açıda kırık ama yaşıyor)
    {"Silent Woods", "Twisted Lion",         80,  19,  14,  42, 6,  46, "paw", "fur"},
    // "Bandit Chief" -> "The Forgotton One" (Kim olduğunu unutmuş, sadece öldürüyor)
    {"Silent Woods", "The Forgotten One",    100, 20,  12,  50, 7,  48, "attack scroll", "defense scroll"},
    // "Timber Wolf Pack" -> "Merged Pack" (Birbirine yapışmış birden fazla kurt)
    {"Silent Woods", "Albasty",              110, 22,  22,  55, 9,  50, "evil spirit", "evil spirit"},

    // --- THE ROTTING GLADE (Level 10-19) - Flesh and nature fuse painfully
    // "Glowing Stag" -> "Mourner Stag" (Gözlerinden kan değil, siyah bir sıvı akıyor)
    {"Rotting Glade", "Mourner Stag",           120, 24,  6,  65, 10, 60},
    // "Thornback Badger" -> "Flesh-Bark Badger" (Deri yerine ağaç kabuğu, içinde et var)
    {"Rotting Glade", "Flesh-Bark Badger",      130, 26,  8,  75, 11, 65},
    // "Whispering Owl" -> "Observer Owl" (Tek bir devasa insan gözüne sahip)
    {"Rotting Glade", "Observer Owl",           110, 27,  7,  70, 12, 63},
    // "Moonlit Fox" -> "Displaced Fox" (Sürekli ışınlanıyor, gerçeklikten kopmuş)
    {"Rotting Glade", "Displaced Fox",          125, 28,  7,  75, 13, 65},
    // "Ancient Treant" -> "Gorged Root" (Kökleri insan cesetleriyle beslenmiş)
    {"Rotting Glade", "Gorged Root",            160, 30,  10, 90, 14, 70},
    // "Spore-Touched Bear" -> "Mold Host" (Ayı artık yok, sadece yürüyen küf)
    {"Rotting Glade", "What Was Bear",              145, 31,  9,  85, 15, 68},
    // "Vine Strangler" -> "Nerve Strangler" (Sarmaşık değil, devasa sinir sistemleri)
    {"Rotting Glade", "Nerve Strangler",        135, 32,  9,  80, 16, 67},
    // "Fae-Touched Wolf" -> "Many-Legged Wolf" (Lovecraftvari uzuv çoğalması)
    {"Rotting Glade", "Many-Legged Wolf",       130, 33,  8,  82, 17, 69},
    // "Crystal Beetle" -> "Fractal Beetle" (Baktıkça baş ağrıtan geometrik şekil)
    {"Rotting Glade", "Fractal Beetle",         115, 35,  12, 78, 16, 66},
    // "Elder Dryad" -> "Mother of Sorrows" (Doğa ana değil, acı anası)
    {"Rotting Glade", "Mother of Sorrows",      150, 38,  14, 105, 19, 74},

    // --- THE VOID HORIZON (Level 20-32) - Cosmic Horror & The Unknowable
    // "Lost Soul" -> "Silhouette of Kheshig" (Oyuncunun kendisine benziyor)
    {"Void Horizon", "Silhouette of Kheshig",       180, 40,  12, 120, 20, 85},
    // "Phantom Hunter" -> "The Gaze" (Sadece havada süzülen dev bir göz)
    {"Void Horizon", "The Gaze",                200, 42,  14, 135, 22, 90},
    // "Ethereal Wisp" -> "Color Out of Space" (Tarif edilemeyen bir renk)
    {"Void Horizon", "Color Out of Space",      165, 43,  11, 125, 21, 88},
    // "Banshee Warden" -> "Screaming Geometry" (Şekiller çığlık atıyor)
    {"Void Horizon", "Screaming Geometry",      220, 45,  16, 150, 24, 95},
    // "Spectral Knight" -> "Empty Armor" (İçinde hiçlik var)
    {"Void Horizon", "The Hollow Knight",             250, 47,  18, 165, 26, 100},
    // "Void Stalker" -> "The Whisperer" (Kulağına delice şeyler fısıldıyor)
    {"Void Horizon", "The Whisperer",           230, 48,  16, 160, 25, 98},
    // "Ancestral Guardian" -> "Faceless Idol" (Eski tanrıların yüzsüz heykeli)
    {"Void Horizon", "The Forgotten God",           280, 50,  20, 180, 28, 105},
    // "Shadow Wraith" -> "Crawling Chaos" (Kaosun vücut bulmuş hali)
    {"Void Horizon", "Crawling Chaos",          210, 51,  15, 155, 27, 102},
    // "Soul Reaver" -> "Mind Eater" (Canını değil, akıl sağlığını yiyor)
    {"Void Horizon", "Mind Eater",              300, 53,  22, 195, 29, 110},
    // "Nightmare Manifestation" -> "Eldritch Horror" (Klasik kozmik dehşet)
    {"Void Horizon", "That Which Waits",         350, 55,  25, 220, 30, 115},
    // BOSS: "Ancient Spirit Lord" -> "The Unspeakable" (İsimsiz Son)
    {"Void Horizon", "The Unspeakable",         400, 57,  28, 250, 32, 120}
};

const char* retreatTexts[] = {
    "You chose survival over honor.",
	"The shadows were kinder to you than your own steel today.",
	"The Eternal Sky frowns upon your retreat, but your breath remains.",
	"You fled like a wounded dog alive, but broken.",
	"Coward's breath is sweeter than a warrior's death, is it not?",
	"Your ancestors spit at the mention of your name tonight.",
	"The crows will mock your retreat in their cawing.",
	"You chose the path of shame over the warrior's end.",
	"Your legs carried you faster than your courage could.",
	"The steppe remembers those who run and judges them.",
	"Survival tastes of ash when honor is the price."
};

const char* victoryTexts[] = {
    "The Eternal Blue Sky witnesses your glorious triumph!",
	"A new saga begins with the screams of your fallen foe.",
	"The spirits of the steppe howl in favor of your sharp steel.",
	"Victory belongs to the swift; the battlefield is yours!",
	"You stand victorious amidst the carnage.",
	"Another soul rides to the ancestors on your steel.",
	"The ravens gather; your enemy feeds them well.",
	"Swift as the wolf, fierce as the eagle victory is yours!",
	"Your foe's courage broke before your blade did.",
	"The steppe remembers this kill.",
	"Blood and glory the old way prevails!",
	"Your enemy's final breath joins the wind."
};

const char* defeatTexts[] = {
    "The dust of the steppe shall swallow your forgotten name.",
    "Fate is a cruel mistress, and today she chose your end.",
    "Your soul wanders into the cold mists of the afterlife.",
    "The crows gather for a feast you did not intend to provide.",
	"The steppe claims another forgotten warrior.",
	"Your ancestors turn their backs in silence.",
	"The Eternal Sky saw your last breath-and turned away.",
	"You rode into legend, but death rode faster.",
	"The wolves will scatter your bones by morning.",
	"Your story ends here, unsung and unremembered.",
	"Even the bravest fall when fate swings her blade.",
	"The spirits did not hear your final prayer."
};


void warMenu()
{
	cursorControlWar();
	kheshig.activePossession = 0;
	kheshig.maxPossession = 100;
}

void clearWarLog() 
{
    for(int t=0; t<MAX_VISIBLE_LOGS;t++)
	{
		warLogs[t][0] = '\0';
	}
    currentLogCount = 0;
}


void appendWarLog(const char *line) {
    if (currentLogCount < MAX_VISIBLE_LOGS) {
        snprintf(warLogs[currentLogCount], WAR_LINE_SIZE, "  %s", line);
        currentLogCount++;
    } else {
        for (int i = 0; i < MAX_VISIBLE_LOGS - 1; i++) {
            strcpy(warLogs[i], warLogs[i + 1]);
        }
        snprintf(warLogs[MAX_VISIBLE_LOGS - 1], WAR_LINE_SIZE, "  %s", line);
    }
}

void makeAttackLogEnemy(char *out, size_t size,const char *attacker,const char *target,int damage)
{
    snprintf(out, size,"%s attacks %s for \033[31m%d\033[0m damage\n",attacker, target, damage);
}

void makeAttackLogPlayer(char *out, size_t size,const char *attacker,const char *target,int damage)
{
    snprintf(out, size,"%s attacks %s for \033[32m%d\033[0m damage\n",attacker, target, damage);
}

void makeDefendLog(char *out, size_t size, const char *defender, int totalDamage, int reducedDamage)
{
    snprintf(out, size, "%s defends! (\033[31m%d\033[0m -> \033[33m%d\033[0m damage)\n", defender, totalDamage, reducedDamage);
}

void makeCounterStrikeLog(char *out, size_t size, const char *defender, char *attacker, int counterDamage)
{
	snprintf(out, size, "\033[33m%s\033[0m counters! Strikes %s for \033[31m%d\033[0m damage\n", defender, attacker, counterDamage);
}

static int applyDamageVariance(int baseDamage, int variance)
{
	int roll = rand() % (variance * 2 + 1);
	int dmg = baseDamage + (roll - variance);
	if(dmg < 1) dmg = 1;
	return dmg;
}

static int clampPossession(int possession)
{
	if(possession < 0) return 0;
	if(possession > kheshig.maxPossession) return kheshig.maxPossession;
	return possession;
}

static int getMageFormAttackPower()
{
	if(kheshig.mageForm == 1)
	{
		return kheshig.attack + (kheshig.attack * 35) / 100;
	}
	return kheshig.attack;
}

static int getMageFormDefensePower()
{
	if(kheshig.mageForm == 1)
	{
		return kheshig.defense + (kheshig.defense * 25) / 100;
	}
	return kheshig.defense;
}

static void checkMageFormState(int currentPossession)
{
	if(kheshig.mageForm == 0 && currentPossession >= kheshig.maxPossession)
	{
		kheshig.mageForm = 1;
		appendWarLog("Demonic Possession awakened! Mage Form is active.\n");
	}
}

static void resetMageFormForNextBattle()
{
	kheshig.mageForm = 0;
	kheshig.activePossession = 0;
}

static void renderBattleScreen(int currentHP, int currentEnemyHP, int enemyIdx, int showActions)
{
	system("cls");
	char viewLineRenderBattle[] = "=================================================================";
	char viewHeader[150];
	snprintf(viewHeader, sizeof(viewHeader), "  \033[31mBLOODTHIRSTY KHESHIG\033[0m - \033[32m%s\033[0m", enemyPool[enemyIdx].place);

	int visibleLen = strlen("     BLOODTHIRSTY KHESHIG - ") + strlen(enemyPool[enemyIdx].place);
	int viewDiff = (int)strlen(viewLineRenderBattle) - visibleLen;

	printf("%s\n",viewLineRenderBattle);
	for(int i=0;i<viewDiff/2;i++)
	{
		printf(" ");
	}
	printf("%s", viewHeader);
	printf("\n%s\n", viewLineRenderBattle);
	
	char choicedEnemiesName[30];
	strcpy(choicedEnemiesName, enemyPool[enemyIdx].name);

	printf("  ");
	printf("[Kheshig]");
	for(int j=0;j<35-strlen(choicedEnemiesName);j++)
	{
		printf(" ");
	}
	printf("[%s]\n",choicedEnemiesName);

	char kheshigHPStr[25];
	if(currentHP<0) currentHP=0;
	snprintf(kheshigHPStr, 25, "  HP: %d/%d", currentHP, kheshig.health);

	char enemyHPStr[25];
	if(currentEnemyHP<0) currentEnemyHP=0;
	snprintf(enemyHPStr, 25, "  HP: %d/%d", currentEnemyHP, enemyPool[enemyIdx].health);

	printf("%s", kheshigHPStr);

	for(int j=0;j<44-strlen(choicedEnemiesName)-strlen(kheshigHPStr);j++)
	{
		printf(" ");
	}

	printf("%s", enemyHPStr);

	printf("\n  [");
	int t = 0;
	float hpRatio = (float)currentHP / kheshig.health;
	if (hpRatio < 0) hpRatio = 0;
	int kheshigHealthBar = (int)(10 * hpRatio);
	while(t<10)
	{
		for(int a=0;a<kheshigHealthBar;a++)
		{
			t++;
			printf("|");
		}
		while(t<10)
		{
			t++;
			printf(".");
		}
	}
	printf("]");

	for(int j=0;j<32-strlen(choicedEnemiesName);j++)
	{
		printf(" ");
	}

	printf("[");

	int d = 0;
	float enemyHpRatio = (float)currentEnemyHP / enemyPool[enemyIdx].health;
	if (enemyHpRatio < 0) enemyHpRatio = 0;
	int enemyHealthBar = (int)(10 * enemyHpRatio);
	while(d<10)
	{
		for(int a=0;a<enemyHealthBar;a++)
		{
			d++;
			printf("|");
		}
		while(d<10)
		{
			d++;
			printf(".");
		}
	}
	printf("]");

	if(kheshig.mageForm == 1)
	{
		printf("\n\033[31m  Rage:\033[0m %d/%d \n  ",kheshig.activeStamina ,kheshig.maxStamina);
	}
	else
	{
		printf("\n\033[33m  Stamina:\033[0m %d/%d \n  ",kheshig.activeStamina ,kheshig.maxStamina);
	}
	printf("[");
	int k = 0;
	float staminaRatio = (float)kheshig.activeStamina / kheshig.maxStamina;
	if (staminaRatio < 0) staminaRatio = 0;
	int kheshigStaminaBar = (int)(10 * staminaRatio);
	while(k<10)
	{
		for(int a=0;a<kheshigStaminaBar;a++)
		{
			k++;
			printf("|");
		}
		while(k<10)
		{
			k++;
			printf(".");
		}
	}
	printf("]");

	printf("\n\033[31m  Bar of demonic possession:\033[0m %d/%d \n  ",kheshig.activePossession, kheshig.maxPossession);
	printf("[");
	int l = 0;
	float possessionRatio = (float)kheshig.activePossession/ kheshig.maxPossession;
	if (possessionRatio < 0) possessionRatio = 0;
	int kheshigPossessionBar = (int)(10 * possessionRatio);
	while(l<10)
	{
		for(int a=0;a<kheshigPossessionBar;a++)
		{
			l++;
			printf("|");
		}
		while(l<10)
		{
			l++;
			printf(".");
		}
	}
	printf("]");

	printf("\n%s\n", viewLineRenderBattle);
	printf("                   --- BATTLE LOG ---\n");
	for(int i=0;i<currentLogCount;i++)
	{
		printf("%s", warLogs[i]);
	}
	for(int i=currentLogCount;i<MAX_VISIBLE_LOGS;i++)
	{
		printf("\n");
	}
	printf("%s\n", viewLineRenderBattle);

	if(showActions)
	{
		printf("  1. Quick Attack  | 2. Normal Attack | 3. Heavy Attack\n");
		printf("  4. Defense       | 5. Escape - Lose Gold\n");
		printf("%s\n", viewLineRenderBattle);
	}
}

void warPanel(int currentHP, int currentEnemyHP, int currentPossession, int enemyIdx, int triggerEnemyAttack)
{
	currentPossession = clampPossession(currentPossession);
	kheshig.activePossession = currentPossession;
	checkMageFormState(currentPossession);

	if(currentHP <= 0 || currentEnemyHP <= 0)
	{
		checkBattleStatus(currentHP, currentEnemyHP, currentPossession, enemyIdx, triggerEnemyAttack);
		return;
	}
	if(triggerEnemyAttack == 1)
	{
		checkBattleStatus(currentHP, currentEnemyHP, currentPossession, enemyIdx, 1);
	}

	renderBattleScreen(currentHP, currentEnemyHP, enemyIdx, 1);

	char choice;
	do {
		choice = getch();
		if(choice == '1') quickAttack(currentHP, currentEnemyHP, enemyIdx);
		else if(choice == '2') normalAttack(currentHP, currentEnemyHP, enemyIdx);
		else if(choice == '3') heavyAttack(currentHP, currentEnemyHP, enemyIdx);
		else if(choice == '4') defense(currentHP, currentEnemyHP, enemyIdx); 
		else if(choice == '5') { escapeWar(enemyIdx); }
	} while(choice < '1' || choice > '5');
}

void escapeWar(int enemyIdx)
{
	char viewLineEscape[] = "=====================================================================";
	resetMageFormForNextBattle();
	system("cls");
		int loss = (kheshig.gold * 15) / 100;
        printf("%s\n", viewLineEscape);
		printf("                      \033[33m\033[1m<<< KHESHIG RETREATED >>>\033[0m\n");
        printf("%s\n", viewLineEscape);
		advanceTimePeriod(1);

		int retreatCount = sizeof(retreatTexts) / sizeof(retreatTexts[0]);
        int idx = rand() % retreatCount;
        printf("\n    %s\n",retreatTexts[idx]);
        printf("    The %s remains behind as you flee into the shadows...\n", enemyPool[enemyIdx].name);
        
        printf("\n    \033[33m[CONSEQUENCES]\033[0m\n");
		printf("    - %d Gold Coins (Lost while escaping in haste)\n", loss);
        
		kheshig.gold -= loss;
		gameSave();

		printf("\n%s\n", viewLineEscape);
		printf("    Press any key to recover at the camp...");
		printf("\n%s\n", viewLineEscape);
		getch();
		clearWarLog();
		FirstIntroductionMenu();
}

void checkBattleStatus(int pHP, int eHP, int currentPossession, int enemyIdx, int triggerEnemyAttack)
{
	kheshig.activePossession = clampPossession(currentPossession);
	checkMageFormState(kheshig.activePossession);

	char viewLineBattle[] = "============================================================";
	if(eHP <= 0)
	{
		char line[76];
		snprintf(line, sizeof(line),"Kheshig delivered the finishing blow to the %s.\n", enemyPool[enemyIdx].name);
		appendWarLog(line);

		renderBattleScreen(pHP, eHP, enemyIdx, 1);

		printf("Press any key to continue...");
		getch();
		system("cls");
        printf("%s\n", viewLineBattle);
		printf("                \033[32m\033[1m!!! BATTLE VICTORIOUS !!!\033[0m\n");
        printf("%s\n", viewLineBattle);
		advanceTimePeriod(1);
		advanceTime();
        
        printf("\n    Kheshig has defeated the %s!\n", enemyPool[enemyIdx].name);
		int victoryCount = sizeof(victoryTexts) / sizeof(victoryTexts[0]);
        int idx = rand() % victoryCount;
        printf("    %s\n",victoryTexts[idx]);
        
        
		int randEndGold = enemyPool[enemyIdx].goldReward * 0.8;
		int randStartGold = enemyPool[enemyIdx].goldReward * 1.2;
		int randGold = rand() % randStartGold + randEndGold;

		kheshig.gold += randGold;

		printf("\n    \033[33m[LOOT COLLECTED]\033[0m\n");
		printf("    + %d Gold Coins\n", randGold);

		int randEndXp = enemyPool[enemyIdx].xpReward * 0.8;
		int randStartXp = enemyPool[enemyIdx].xpReward * 1.2;
		int randXp = rand() % randStartXp + randEndXp; 

		kheshig.xp += randXp;
		xpLevelCalc();
		printf("    + %d Xp Earned\n", enemyPool[enemyIdx].xpReward);

		int randItem = rand() % 60;
		if(randItem<10)
		{
			int randFifty = rand() % 2;
			int itemLevel = 3;
			if(randFifty == 0)
			{
				kheshig.attack += itemLevel;
				printf("    The %s dropped a basic %s item.\n", enemyPool[enemyIdx].name, enemyPool[enemyIdx].itemNameAtk);
				printf("    + %d Attack scroll\n", itemLevel);
			}
			else
			{
				kheshig.defense += itemLevel;
				printf("    The %s dropped a basic %s item.\n", enemyPool[enemyIdx].name, enemyPool[enemyIdx].itemNameDef);
				printf("    + %d Defense scroll\n", itemLevel);
			}
		}
		else if(randItem<15)
		{
			int randFifty = rand() % 2;
			int itemLevel = 5;
			if(randFifty == 0)
			{
				kheshig.attack += itemLevel;
				printf("    The %s dropped a enchanted %s item.\n", enemyPool[enemyIdx].name, enemyPool[enemyIdx].itemNameAtk);
				printf("    + %d Attack scroll\n", itemLevel);
			}
			else
			{
				kheshig.defense += itemLevel;
				printf("    The %s dropped a enchanted %s item.\n", enemyPool[enemyIdx].name, enemyPool[enemyIdx].itemNameDef);
				printf("    + %d Defense scroll\n", itemLevel);
			}
		}

		else if(randItem<17)
		{
			int randFifty = rand() % 2;
			int itemLevel = 5;
			if(randFifty == 0)
			{
				kheshig.attack += itemLevel;
				printf("    The %s dropped a cursed %s item.\n", enemyPool[enemyIdx].name, enemyPool[enemyIdx].itemNameAtk);
				printf("    + %d Attack scroll\n", itemLevel);
			}
			else
			{
				kheshig.defense += itemLevel;
				printf("    The %s dropped a cursed %s item.\n", enemyPool[enemyIdx].name, enemyPool[enemyIdx].itemNameDef);
				printf("    + %d Defense scroll\n", itemLevel);
			}
		}

		kheshig.activeHealth = pHP;
		resetMageFormForNextBattle();
		gameSave();

		printf("\n%s\n", viewLineBattle);
		printf("    Press any key to return to the camp...");
		printf("\n%s\n", viewLineBattle);
		getch();
		clearWarLog();
		FirstIntroductionMenu();
	}
	else if(pHP <= 0)
	{
		char line[76];
		snprintf(line, sizeof(line),"Kheshig was sent to oblivion by the %s.\n", enemyPool[enemyIdx].name);
		appendWarLog(line);

		renderBattleScreen(pHP, eHP, enemyIdx, 1);

		printf("Press any key to continue...");
		getch();
		system("cls");
		int loss;
		if(enemyPool[enemyIdx].goldReward<100)
		{
			loss = (kheshig.gold * 10) / 100;
		}
		else if(enemyPool[enemyIdx].goldReward<1000)
		{
			loss = (kheshig.gold * 25) / 100;
		}
		else
		{
			loss = (kheshig.gold * 30) / 100;
		}

		if(loss<10)
		{
			loss = 10;
		}
		if(loss>1000)
		{
			loss = 1000;
		}

        printf("%s\n", viewLineBattle);
		printf("                \033[31m\033[1mXXX KHESHIG HAS FALLEN XXX\033[0m\n");
        printf("%s\n", viewLineBattle);
		advanceTimePeriod(1);
		advanceTime();
        
        printf("\n    You were bested by the %s.\n", enemyPool[enemyIdx].name);
        
		if(strcmp(enemyPool[enemyIdx].place, "The Silent Woods") == 0)
		{
			printf("    Death is a cold companion in the %s...\n", enemyPool[enemyIdx].place);
		}
		/*
		else if(strcmp(enemyPool[enemyIdx].place, "sdasdsadadasdsadsad") == 0)
		{
			printf("    Death is a cold companion in the %s...\n", enemyPool[enemyIdx].place);
		}
		*/

		int defeatCount = sizeof(defeatTexts) / sizeof(defeatTexts[0]);
        int idx = rand() % defeatCount;
        printf("    %s\n",defeatTexts[idx]);
        
        printf("\n    \033[31m[PENALTIES]\033[0m\n");
		if(kheshig.gold<=0)
		{
			printf("Your body yielded no gold only the cold truth of a warrior with nothing left to lose.\n");
		}
		else
		{
			printf("    - %d Gold Coins (Scavengers took their share)\n", loss);
			kheshig.gold -= loss;
		}
		kheshig.activeHealth = pHP;
		resetMageFormForNextBattle();
		gameSave();

		printf("\n%s\n", viewLineBattle);
		printf("    Press any key to recover at the camp...");
		printf("\n%s\n", viewLineBattle);
		getch();
		clearWarLog();
		FirstIntroductionMenu();
	}
	else
	{
		if(triggerEnemyAttack == 1)
		{
			int playerDefense = getMageFormDefensePower();
			int baseEnemyDmg = enemyPool[enemyIdx].attack - playerDefense;
			if(baseEnemyDmg < 1) baseEnemyDmg = 1;
			int chanceFactor = 10 + rand() % 10;
			int scaledEnemyDmg = (chanceFactor * baseEnemyDmg) / 10;
			if(scaledEnemyDmg < 1) scaledEnemyDmg = 1;
			int variance = scaledEnemyDmg / 6;
			if(variance < 1) variance = 1;
			int enemyDmg = applyDamageVariance(scaledEnemyDmg, variance);
			
			char line[128];
			makeAttackLogEnemy(line, sizeof(line), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
			appendWarLog(line);

		}
	}
}

void defense(int pHP, int eHP, int enemyIdx)
{
	int defenseStaminaEarn = 10;

	kheshig.activeStamina += defenseStaminaEarn;
	if(kheshig.activeStamina > kheshig.maxStamina)
	{
		kheshig.activeStamina = kheshig.maxStamina;
	}

	int chance = rand() % 100;
	int playerDefense = getMageFormDefensePower();
	int defDamage = enemyPool[enemyIdx].attack - playerDefense;
	if(defDamage < 1) defDamage = 0;
	if(chance<50)
	{
		if(defDamage == 0)
		{
			appendWarLog("Enemy missed their Attack!\n");
		}
		else
		{
			char line[128];
			makeDefendLog(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].attack, defDamage);
			appendWarLog(line);
		}
		int nextPossession = kheshig.activePossession;
		if(defDamage > 0)
		{
			nextPossession = clampPossession(nextPossession + 10);
		}
		warPanel(pHP-defDamage, eHP, nextPossession, enemyIdx, 1);
	}
	else
	{
		int playerAttack = getMageFormAttackPower();
		int counterBase = playerAttack - enemyPool[enemyIdx].defense;
		if(counterBase < 1)
		{
			int heal = 1 + rand() % 2;
			int healedEnemyHP = eHP + heal;
			if(healedEnemyHP > enemyPool[enemyIdx].health)
			{
				healedEnemyHP = enemyPool[enemyIdx].health;
			}
			char healLine[128];
			snprintf(healLine, sizeof(healLine), "%s regains %d HP while you fail to counter!\n", enemyPool[enemyIdx].name, heal);
			appendWarLog(healLine);
			warPanel(pHP, healedEnemyHP, kheshig.activePossession, enemyIdx, 1);
		}
		else
		{
			int variance = counterBase / 6;
			if(variance < 1) variance = 1;
			int counterDmg = applyDamageVariance(counterBase, variance);
			int nextPossession = clampPossession(kheshig.activePossession + 5);
			char counterLine[128];
			makeCounterStrikeLog(counterLine, sizeof(counterLine), "Kheshig", enemyPool[enemyIdx].name, counterDmg);
			appendWarLog(counterLine);
			warPanel(pHP, eHP-counterDmg, nextPossession, enemyIdx, 1);
		}
	}
}

void quickAttack(int pHP, int eHP, int enemyIdx)
{
	int quickStaminaLose = 15;
	if(kheshig.activeStamina<quickStaminaLose)
	{
		appendWarLog("You ran out of breath! Try to defend.\n");
		warPanel(pHP, eHP, kheshig.activePossession, enemyIdx, 0);
		return;
	}
	else
	{
		kheshig.activeStamina -= quickStaminaLose;
		int chance = rand() % 100;
		if(chance < 90)
		{
			int playerAttack = getMageFormAttackPower();
			int baseDmg = playerAttack - enemyPool[enemyIdx].defense;
			if(baseDmg < 1) baseDmg = 1;
			int variance = baseDmg / 6;
			if(variance < 1) variance = 1;
			int dmg = applyDamageVariance(baseDmg, variance);
			int nextPossession = clampPossession(kheshig.activePossession + 8);
			char line[128];
			makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
			appendWarLog(line);
			
			if(eHP - dmg > 0)
			{
				int playerDefense = getMageFormDefensePower();
				int baseEnemyDmg = enemyPool[enemyIdx].attack - playerDefense;
				if(baseEnemyDmg < 1) baseEnemyDmg = 1;
				int chanceFactor = 10 + rand() % 10;
				int scaledEnemyDmg = (chanceFactor * baseEnemyDmg) / 10;
				if(scaledEnemyDmg < 1) scaledEnemyDmg = 1;
				int varianceEnemy = scaledEnemyDmg / 6;
				if(varianceEnemy < 1) varianceEnemy = 1;
				int enemyDmg = applyDamageVariance(scaledEnemyDmg, varianceEnemy);
				nextPossession = clampPossession(nextPossession + 10);
				char eLine[128];
				makeAttackLogEnemy(eLine, sizeof(eLine), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
				appendWarLog(eLine);
				warPanel(pHP - enemyDmg, eHP - dmg, nextPossession, enemyIdx, 0);
			}
			else
			{
				warPanel(pHP, eHP - dmg, nextPossession, enemyIdx, 0);
			}
		}
		else
		{
			appendWarLog("Kheshig missed their Quick Attack!\n");
			warPanel(pHP, eHP, kheshig.activePossession, enemyIdx, 0);
		}
	}
}

void normalAttack(int pHP, int eHP, int enemyIdx)
{
	int normalStaminaLose = 25;
	if(kheshig.activeStamina<normalStaminaLose)
	{
		appendWarLog("You ran out of breath! Try a lighter move.\n");
		warPanel(pHP, eHP, kheshig.activePossession, enemyIdx, 0);
		return;
	}

	else
	{
		kheshig.activeStamina -= normalStaminaLose;
		int chance = rand() % 100;
		if(chance < 85)
		{
			int playerAttack = getMageFormAttackPower();
			int baseDmg = playerAttack - enemyPool[enemyIdx].defense;
			if(baseDmg < 1) baseDmg = 1;
			int scaledDmg = (int)(1.2 * baseDmg);
			if(scaledDmg < 1) scaledDmg = 1;
			int variance = scaledDmg / 6;
			if(variance < 1) variance = 1;
			int dmg = applyDamageVariance(scaledDmg, variance);
			int quickVariance = baseDmg / 6;
			if(quickVariance < 1) quickVariance = 1;
			int quickEquivalent = applyDamageVariance(baseDmg, quickVariance);
			if(dmg < quickEquivalent) dmg = quickEquivalent;
			int nextPossession = clampPossession(kheshig.activePossession + 15);
			char line[128];
			makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
			appendWarLog(line);
			
			if(eHP - dmg > 0)
			{
				int playerDefense = getMageFormDefensePower();
				int baseEnemyDmg = enemyPool[enemyIdx].attack - playerDefense;
				if(baseEnemyDmg < 1) baseEnemyDmg = 1;
				int chanceFactor = 10 + rand() % 10;
				int scaledEnemyDmg = (chanceFactor * baseEnemyDmg) / 10;
				if(scaledEnemyDmg < 1) scaledEnemyDmg = 1;
				int varianceEnemy = scaledEnemyDmg / 6;
				if(varianceEnemy < 1) varianceEnemy = 1;
				int enemyDmg = applyDamageVariance(scaledEnemyDmg, varianceEnemy);
				nextPossession = clampPossession(nextPossession + 10);
				char eLine[128];
				makeAttackLogEnemy(eLine, sizeof(eLine), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
				appendWarLog(eLine);
				warPanel(pHP - enemyDmg, eHP - dmg, nextPossession, enemyIdx, 0);
			}
			else
			{
				warPanel(pHP, eHP - dmg, nextPossession, enemyIdx, 0);
			}
		}
		else
		{
			appendWarLog("Kheshig missed their Normal Attack!\n");
			warPanel(pHP, eHP, kheshig.activePossession, enemyIdx, 0);
		}
	}
}

void heavyAttack(int pHP, int eHP, int enemyIdx)
{
	int heavyStaminaLose = 35;
	if(kheshig.activeStamina<heavyStaminaLose)
	{
		appendWarLog("You ran out of breath! Try a lighter move.\n");
		warPanel(pHP, eHP, kheshig.activePossession, enemyIdx, 0);
		return;
	}

	else
	{
		kheshig.activeStamina -= heavyStaminaLose;
		int chance = rand() % 100;
		if(chance < 70)
		{
			int playerAttack = getMageFormAttackPower();
			int baseDmg = playerAttack - enemyPool[enemyIdx].defense;
			if(baseDmg < 1) baseDmg = 1;
			int scaledDmg = 2 * baseDmg;
			if(scaledDmg < 1) scaledDmg = 1;
			int variance = scaledDmg / 6;
			if(variance < 1) variance = 1;
			int dmg = applyDamageVariance(scaledDmg, variance);
			int nextPossession = clampPossession(kheshig.activePossession + 25);
			char line[128];
			makeAttackLogPlayer(line, sizeof(line), "Kheshig", enemyPool[enemyIdx].name, dmg);
			appendWarLog(line);
			
			if(eHP - dmg > 0)
			{
				int playerDefense = getMageFormDefensePower();
				int baseEnemyDmg = enemyPool[enemyIdx].attack - playerDefense;
				if(baseEnemyDmg < 1) baseEnemyDmg = 1;
				int chanceFactor = 10 + rand() % 10;
				int scaledEnemyDmg = (chanceFactor * baseEnemyDmg) / 10;
				if(scaledEnemyDmg < 1) scaledEnemyDmg = 1;
				int varianceEnemy = scaledEnemyDmg / 6;
				if(varianceEnemy < 1) varianceEnemy = 1;
				int enemyDmg = applyDamageVariance(scaledEnemyDmg, varianceEnemy);
				nextPossession = clampPossession(nextPossession + 10);
				char eLine[128];
				makeAttackLogEnemy(eLine, sizeof(eLine), enemyPool[enemyIdx].name, "Kheshig", enemyDmg);
				appendWarLog(eLine);
				warPanel(pHP - enemyDmg, eHP - dmg, nextPossession, enemyIdx, 0);
			}
			else
			{
				warPanel(pHP, eHP - dmg, nextPossession, enemyIdx, 0);
			}
		}
		else
		{
			appendWarLog("Kheshig missed their Heavy Attack!\n");
			warPanel(pHP, eHP, kheshig.activePossession, enemyIdx, 0);
		}
	}
}

int getRandomEnemyIndex(int playerLevel)
{
	int validIndices[20];
	int validCount = 0;
	int startIdx, endIdx;

	if (playerLevel <= 10)
	{
		startIdx = SILENT_WOODS_START;
		endIdx = SILENT_WOODS_END;
	}
	else if (playerLevel <= 20)
	{
		startIdx = ROTTING_GLADE_START;
		endIdx = ROTTING_GLADE_END;
	}
	else
	{
		startIdx = VOID_HORIZON_START;
		endIdx = 31;
	}

	for (int i = startIdx; i <= endIdx; i++)
	{
		if(playerLevel >= enemyPool[i].minLevel)
		{
			validIndices[validCount] = i;
			validCount++;
		}
	}

	if (validCount == 0) return startIdx;

	return validIndices[rand() % validCount];
}

void cursorControlWar()
{
	char selectedDirection = '\0';
	
	while(selectedDirection != 'F' && selectedDirection != 'f' && selectedDirection != 13 && selectedDirection != 'Q' && selectedDirection != 'q' && selectedDirection != 27)
	{
		system("cls");
		playerStats("WAR MENU", 8, sizeof(viewLineWar), viewLineWar);
		PrintBoardWar();
		printf("[W-S] Move  |  [F] Select  |  [Q] Back to main menu\n");
		printf("%s\n",viewLineWar);
		selectedDirection = getch();
		
		if(selectedDirection == '1')
		{
			listRowWar = 0;
		}
		else if(selectedDirection == '2')
		{
			listRowWar = 1;
		}

		if(selectedDirection == 'W' || selectedDirection == 'w' || selectedDirection == 72)
		{
			listRowWar--;
			if(listRowWar < 0) listRowWar = rowSize-2;
		}
		else if(selectedDirection == 'S' || selectedDirection == 's' || selectedDirection == 80)
		{
			listRowWar++;
			if(listRowWar > rowSize-2) listRowWar = 0;
		}
        else if(selectedDirection == 'F' || selectedDirection == 'f' || selectedDirection == 13)
        {
			if(listRowWar==0)
        	{
				clearWarLog();
				resetMageFormForNextBattle();
				int selectedEnemyIdx = getRandomEnemyIndex(kheshig.level);
				char startMsg[150];
    			sprintf(startMsg, "A wild %s appeared in the %s!\n",enemyPool[selectedEnemyIdx].name, enemyPool[selectedEnemyIdx].place);
				appendWarLog(startMsg);
				warPanel(kheshig.activeHealth, enemyPool[selectedEnemyIdx].health, kheshig.activePossession, selectedEnemyIdx, 0);
			}
			else if(listRowWar==1)
			{
				system("cls");
				printf("Training mode coming soon...");
				getch();
				FirstIntroductionMenu();
			}
		}
		else if(selectedDirection == 'Q' || selectedDirection == 'q' || selectedDirection == 27)
        {
			listRowWar=0;
        	FirstIntroductionMenu();
		}
		else
		{
		}
        
	}
}

void PrintBoardWar()
{
	for(int i=0;i<rowSize;i++)
	{
		if(listRowWar==i)
		{
			printf("\033[32m%d.%s\033[0m\n", i+1, boardWar[i]);
		}
		else
		{
			printf("%d.%s\n", i+1, boardWar[i]);
		}
	}
	printf("%s\n", viewLineWar);
}