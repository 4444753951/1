#include"List.h"

LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

LTNode* LTInit()
{
	LTNode* phead = BuyLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("guard<==>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTInsert(phead, x);

	//LTNode* tail = phead->prev;
	//LTNode* newnode = BuyLTNode(x);

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
}

//void LTPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//	LTNode* newnode = BuyLTNode(x);
//
//	newnode->next = phead->next;
//	phead->next->prev = newnode;
//
//	phead->next = newnode;
//	newnode->prev = phead;
//}

void LTPushFront(LTNode* phead, LTDataType x)
{
	/*assert(phead);
	LTNode* newnode = BuyLTNode(x);
	LTNode* first = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;*/

	LTInsert(phead->next, x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	LTErase(phead->prev);

	/*LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	free(tail);
	tailPrev->next = phead;
	phead->prev = tailPrev;*/

}

//void LTPopFront(LTNode* phead)
//{
//	assert(phead);
//	assert(!LTEmpty(phead));
//
//	LTNode* next = phead->next;
//
//	/*phead->next = next->next;
//	phead->next->prev = phead;
//	free(next);*/
//
//	phead->next = next->next;
//	next->next->prev = phead;
//	free(next);
//}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTErase(phead->next);

	//LTNode* first = phead->next;
	//LTNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;

	//free(first);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// 在pos之前插入
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* newnode = BuyLTNode(x);

	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

// 删除pos位置的值
void LTErase(LTNode* pos)
{
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}


	free(phead);
}