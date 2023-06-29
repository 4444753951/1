#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void tmp1()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	for (int i = 0; i<sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	
	
	HeapPrint(&hp);
}

int main()
{
	tmp1();
	return 0;
}