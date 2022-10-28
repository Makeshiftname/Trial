#define ROW 9
#define COL 9

#define ROWS 2+ROW
#define COLS 2+COL

#define QUA 10

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void IniBoard(char mine[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char mine[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
