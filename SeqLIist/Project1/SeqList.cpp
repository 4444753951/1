#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SepListPrintf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\ncapacity:%d\n", ps->capacity);
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	//�ռ䲻��
	
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity*sizeof(SLDataType));
		if (NULL == tmp)
		{
			printf("realloc fail\n");
			exit(1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	//�ռ��㹻
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	if (ps->size>0)
	//assert(ps->size>0);
	ps->size--;
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
