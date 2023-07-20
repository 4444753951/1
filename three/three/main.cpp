#define _CRT_SECURE_NO_WARNINGS

#include"three.h"

void mean()
{
	printf("**********************\n");
	printf("******** 1.play ******\n");
	printf("******** 0.exit ******\n");
	printf("**********************\n");
}



void game()
{
	int input = 0;
	do
	{
		mean();
		printf("请选择->");
		scanf("%d",&input);
		char arr[ROW][COL];
		InitBoard(arr, ROW, COL);
		char win = '\0';
		switch (input)
		{
		case 0:
			break;
		case 1:
			while ('w' != win||'t'!=win)
			{
				printf("player move->");
				PlayerMove(arr, ROW, COL);
				printf("\n");
				PrintBoard(arr, ROW, COL);
				win=Win(arr, ROW, COL);
				if ('w' == win)
				{
					printf("player win\n");
					break;
				}
				if ('t' == win)
				{
					printf("平局\n");
					break;
				}
				printf("computer move");
				ComputerMove(arr, ROW, COL);
				printf("\n");
				PrintBoard(arr, ROW, COL);
				win = Win(arr, ROW, COL);
				if ('w' == win)
				{
					printf("computer win\n");
					break;
				}
				if ('t' == win)
				{
					printf("平局\n");
					break;
				}
			}
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	
}

int main()
{
	game();
	return 0;
}