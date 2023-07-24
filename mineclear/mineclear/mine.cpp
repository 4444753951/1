#define _CRT_SECURE_NO_WARNINGS

#include"mine.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS],char set)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			board[row][col] = set;
		}
	}
}

//打印棋盘
void PrintBoard(char board[ROWS][COLS])
{
	printf("\n");
	for (int r = 0; r < ROWS-1; r++)
	{
		for (int c = 0; c < COLS-1; c++)
		{
			if (0 == r && 0 == c)
			{
				printf("%-2d ", r);
			}
			else if (0 == r)
			{
				printf("%d ",c);
			}
			else
			{
				if (0==c)
				{
					printf("%-2d ", r);
				}
				else
					printf("%c ", board[r][c]);
			}	
		}
		printf("\n");
	}
	printf("\n");
}

//布置雷
void SetMineBoard(char mine[ROWS][COLS])
{
	int count=0;
	while (MineNumber != count)
	{
		int r = rand() % ROW + 1, c = rand() % COL + 1;
		if ('0'==mine[r][c])
		{
			mine[r][c] = '1';
			count++;
		}
	}
}

//判断周围雷数
char Judge(char mine[ROWS][COLS], int row, int col)
{
	char count ='0';
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i != 0 || j != 0)
			{
				count += mine[row + i][col + j] - '0';
			}
		}
	}
	return count;
}
//排查周围
void SeekMine2(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i != 0 || j != 0)
			{
				SeekMine1(mine, show, row + i, col + j);
			}
		}
	}
}
//排查0雷及周围
void SeekMine1(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	if ('1' == mine[row][col] && '+' != show[row][col])
	{
		show[row][col] = '#';
		printf("\n你被炸死了\n");
		PrintBoard(mine);
	}
	else if ('*' == show[row][col] && row>0 && col>0 && row<ROW + 1 && col<COL + 1)
	{
		show[row][col] = Judge(mine, row, col);
		if ('0' == show[row][col])
		{
			SeekMine2(mine, show, row, col);
		}
	}
}

//排查雷
void SeekMine(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int row=0, col=0;
	while (true)
	{
		printf("\n请输入要排查的坐标:>");
		scanf("%d%d",&row,&col);
		if (0 == row && 0 == col)
			FindMine(show);
		else if (row<1 || col<1 || row>ROW || col>COL )
		{
			printf("输入超界\n");
		}
		else
		{
			if ('*'!= show[row][col])
			{
				int count = show[row][col] - '0';
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if (i != 0 || j != 0)
						{
							if ('+' == show[row + i][col+j])
							{
								count--;
							}
						}
					}
				}
				if (0 == count)
				{
					SeekMine2(mine, show, row, col);
					break;
				}
				else
				{
					printf("运用失败\n");
				}
			}
			if ('1'==mine[row][col])
			{
				show[row][col] = '#';
				printf("\n你被炸死了\n");
				PrintBoard(mine);
				break;
			}
			else
			{
				SeekMine1(mine, show, row, col);
				break;
			}	
		}
	}
}

//标记雷
void FindMine(char show[ROWS][COLS])
{
	int row = 0, col = 0;
	while (true)
	{
		printf("\n请输入要标记雷的坐标:>");
		scanf("%d%d", &row, &col);
		if (0 == row, 0 == col)
		{
			PrintBoard(show);
			break;
		}
		if ('*' != show[row][col] || row<1 || col<1 || row>ROW || col>COL)
		{
			printf("无法标记\n");
		}
		else
		{
			show[row][col] = '+';
		}
	}
}
//判断获胜
int Win(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int count1 = 0, count2 = 0, count3 = 0;
	for (int r = 1; r < ROWS - 1; r++)
	{
		for (int c = 1; c < COLS - 1; c++)
		{
			if ('#' == show[r][c])
				return 0;
			if ('*' == show[r][c] || '+' == show[r][c])
				count1++;
			if ('+' == show[r][c])
				count2++;
			if ('+' == show[r][c] && '1' == mine[r][c])
				count3++;
		}
	}
	if (10 == count1)
	{
		printf("你赢了\n");
		return 0;
	}
	if (10 == count2 && 10 == count3)
	{
		printf("你赢了\n");
		return 0;
	}
	return 1;
}