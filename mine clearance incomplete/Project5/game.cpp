#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------ɨ����Ϸ-----------\n");
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------ɨ����Ϸ-----------\n");
}


void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//����10����
	int count = EASY_COUNT;
	while (count)
	{
		//����������±�
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//static
//1. ���ξֲ�����
//2. ����ȫ�ֱ���
//3. ���κ���

static void get_mine_count(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
{
	if (show[x][y] == '*'&&x>0 && x<10 && y>0 && y<10)
	{
		int tmp = 0;
		tmp = mine[x - 1][y] +
			mine[x - 1][y - 1] +
			mine[x][y - 1] +
			mine[x + 1][y - 1] +
			mine[x + 1][y] +
			mine[x + 1][y + 1] +
			mine[x][y + 1] +
			mine[x - 1][y + 1] - 8 * '0';
		   show[x][y] = tmp + '0';
		   if (tmp == 0)
		{
			get_mine_count(mine, show, x - 1, y);
			get_mine_count(mine, show, x - 1, y - 1);
			get_mine_count(mine, show, x, y - 1);
			get_mine_count(mine, show, x + 1, y - 1);
			get_mine_count(mine, show, x + 1, y );
			get_mine_count(mine, show, x + 1, y + 1);
			get_mine_count(mine, show, x, y + 1);
			get_mine_count(mine, show, x - 1, y + 1);
		}
		   show[x][y] = tmp + '0';

	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1. �����Ų������
	//2. ������괦�ǲ�����
	// (1) ����   - ���ź�ը���� - ��Ϸ����
	// (2) ������  - ͳ��������Χ�м����� - �洢�Ų��׵���Ϣ��show���飬��Ϸ����

	int x = 0;
	int y = 0;
	int win = 0;

	while (win<row*col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d%d", &x, &y);//x--(1,9)  y--(1,9)

		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				system("PAUSE");
				system("cls");
				break;
			}
			else
			{
				//����������£�ͳ��x,y������Χ�м�����
				get_mine_count(mine,show, x, y);
				//��ʾ�Ų������Ϣ
				system("cls");
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("���겻�Ϸ�������������\n");
		}
	}

	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, row, col);
	}
}

