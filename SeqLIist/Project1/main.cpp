#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	int x = 0;
	scanf("%d", &x);
	while (x != -1)
	{
		SeqListPushBack(&s1, x);
//		scanf("%d", &x);
	}

	SepListPrintf(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	
	SepListPrintf(&s1);

	SeqListDestory(&s1);
}

int main()
{
	TestSeqList1();
	return 0;
}