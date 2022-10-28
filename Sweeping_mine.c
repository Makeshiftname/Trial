#include "Sweeping_mine.h"

int GetMine(char mine[ROWS][COLS], int x, int y)
{
	int i, j;
	int count = 0;
	for(i=x-1; i<=x+1;i++)
		for(j=y-1; j<=y+1; j++)
		{
			count += mine[i][j] - '0';
		}
	return count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	while(win < row*col - QUA)
	{
		printf("Please input the coordinate:> ");
		scanf("%d%d", &x, &y);
		//Determine coordinate legitimacy
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			//1.Stepping on the mine
			if(mine[x][y] == '1')
			{
				printf("Unfortunately, you stepped on the mine!\n\t^-^\n\tGame over!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//2.Not a mine
			else
			{
				//Caculate the number of mines
				int count = GetMine(mine, x, y); 
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("The coordinate is illegal, please input again!\n ");
		}
	}
	if(win == row* col - QUA)
	{
		printf("Congratulations! You win!\n");
		DisplayBoard(mine, row, col);
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = QUA;
	while(count)
	{
		int x = rand()%row + 1;
		int y = rand()%col + 1;
		if(mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void IniBoard(char mine[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for(i=0; i< rows; i++)
	{
		for(j=0; j< cols; j++)
		{
			mine[i][j] = set;
		}
	}
}

void DisplayBoard(char mine[ROWS][COLS], int row, int col)
{
	int i,j;
	for(i=0; i<=row; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=1; i<=row; i++)
	{
		printf("%d ",i);
		for(j=1; j<=col; j++)
		{
			printf("%c ",mine[i][j]);
		}
		printf("\n");
	}
	printf("\n"); 
}
