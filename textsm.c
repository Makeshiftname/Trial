#include "Sweeping_mine.h"



void game()
{
	printf("* Minesweeping started *\n\n");
	//Arrange the mines's positions
	char mine[ROWS][COLS] = {0};
	//Informations of checking the mines
	char show[ROWS][COLS] = {0};
	//Initialize 
	IniBoard(mine, ROWS, COLS, '0');
	IniBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	//Arrange mine 
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//Search mine
	FindMine(mine, show, ROW, COL);
	
	
	
} 

void menu()
{
	printf("_______________________\n");
	printf("	1.play\n");
	printf("	0.exit\n");
	printf("_______________________\n");
}

void test()
{
	int n;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please choose£º> \n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit the game.\n");
			break;
		default:
			printf("There seems to be wrong with your choice, please rechoose!\n");
			break; 
		} 
	}while(n);
}

int main()
{
	test();
	return 0;
}
