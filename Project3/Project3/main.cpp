#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 0;

//	scanf("%d",&a);
	printf("%d\n", a);
	while (-1 != a)
	{
		printf("%d", a);
		scanf("%d",&a);
	}
	printf("\n");
	return 0;
}