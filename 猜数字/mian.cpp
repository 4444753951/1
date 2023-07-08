#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mean()
{
	printf("########  1.start  ##########\n");
	printf("########  0.exit   ##########\n");
}

void num()
{
	srand((unsigned int)time(NULL));
	int tmp = rand()%100, num = 0;
	while (true)
	{
		printf("guess->");
		scanf("%d", &num);
		if (tmp > num)printf("you small\n");
		if (tmp<num)printf("you big\n");
		if (tmp == num)
		{
			printf("you right\n");
			break;
		}
	}
}

int  main()
{
	mean();
	int star = 0;
	scanf("%d", &star);
	while (star)
	{
		if (1 == star)
		{
			num();
			break;
	    }
		else
		{
			if (0 != star)
			{
				printf("reselect\n");
				scanf("%d", &star);
			}
		}
	}
	return 0;
}