#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	//¿Õ¼ä²»¹»
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity*sizeof(SLDataType));
		if (tmp = NULL)
		{
			printf("realloc fail\n");
			exit(1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	//¿Õ¼ä×ã¹»
	ps->a[ps->size] = x;
	ps->size++;
}
