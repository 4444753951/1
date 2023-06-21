#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a = 0, b = 0, c = 0,d=0;
	a = sizeof(int);
	b = sizeof(int*);
	c = sizeof(char*);
	d = sizeof(float*);
	printf("%d %d %d %d\n", a, b, c, d);

}