#define _CRT_SECURE_NO_WARNINGS
#include"three.h"

void InitBoard(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void PrintBoard(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ",arr[i][j]);
			if (j<col - 1)printf("|");
		}
		printf("\n");
		if (i<row - 1)
		{
			int ii = row;
			while (ii)
			{
				if (ii>1)printf("---|");
				else printf("---");
				ii--;
			}
		}
		printf("\n");
	}
}

void PlayerMove(char arr[ROW][COL], int row, int col)
{
	while (true)
	{
		int i = 0, j = 0;
		scanf("%d%d",&i,&j);
		if (i > row || j > col || i < 0 || j < 0)
			printf("move err\n");
		else if (' ' == arr[i][j])
		{
			arr[i][j] = '*';
			break;
		}
		else 
			printf("move err\n");
	}
}

void ComputerMove(char arr[ROW][COL], int row, int col)
{
	while (true)
	{
		srand((unsigned)time(NULL));
		int i = rand() % ROW;
		srand((unsigned)time(NULL));
		int j = rand() % COL;
		if (' ' == arr[i][j])
		{
			arr[i][j] = '#';
			break;
		}
	}
}

char Win(char arr[ROW][COL], int row, int col)
{
	//判断行
	for (int col = 0; col < COL-1; col++)
	{
		int countrow = 0;
		for (int row = 0; row < ROW-1; row++)
		{
			if (arr[row][col] == arr[row + 1][col] && ' ' != arr[row][col]);
			else countrow++;
		}
		if (countrow == 0)
			return 'w';
	}
	//判断列
	for (int row = 0; row < ROW-1; row++)
	{
		int countcol = 0;
		for (int col = 0; col < COL - 1; col++)
		{
			if (arr[row][col] == arr[row][col + 1] && ' ' != arr[row][col]);
			else countcol++;
		}
		if (countcol == 0)
			return 'w';
	}
	//判断斜(仅3*3格)
	int count = 0;
	for (int row = 0, col = 0; row< ROW - 1 && col< COL - 1; row++, col++)
	{
		if (arr[row][col] == arr[row + 1][col + 1] && ' ' != arr[row][col]);
		else count++;
	}
	if (count == 0)
		return 'w';

	count = 0;
	for (int row = ROW - 1, col = 0; row> 0 && col< COL - 1; row--, col++)
	{
		if (arr[row][col] == arr[row - 1][col + 1] && ' ' != arr[row][col]);
		else count++;
	}
	if (count == 0)
		return 'w';

	//平局
	count = 0;
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (arr[row][col] == ' ')
				count++;
		}
	}
	if (count == 0)
		return 't';
}