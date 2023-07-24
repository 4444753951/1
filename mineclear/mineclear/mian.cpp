#define _CRT_SECURE_NO_WARNINGS

#include"mine.h"

void menu()
{
	printf("******************************\n");
	printf("******    1. play      *******\n");
	printf("******    0. exit      *******\n");
	printf("******************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ������
	InitBoard(mine,'0');//'0'
	InitBoard(show,'*');//'*'

	//��ӡһ������
	PrintBoard(show);

	//������
	SetMineBoard(mine);
	int win = 1;
	while (win)
	{
		//�Ų���
		SeekMine(mine, show);
		PrintBoard(show);
		win = Win(mine, show);
	}
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}