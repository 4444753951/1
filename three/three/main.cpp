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
		printf("��ѡ��->");
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
					printf("ƽ��\n");
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
					printf("ƽ��\n");
					break;
				}
			}
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
	
}

int main()
{
	game();
	return 0;
}