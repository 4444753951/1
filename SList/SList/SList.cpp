#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPrint(SLTNode* phead)
{
	//if (NULL != phead->next)
	//{
	//	printf("%d ", phead->data);
	//	SListPrint(phead->next);
	//}

	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	/*SLTNode* tail = phead;
	while (tail != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;*/
	
	if (NULL == *pphead)
	{ 
		*pphead = newnode; 
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next!= NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
