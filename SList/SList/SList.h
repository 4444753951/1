#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySListNode(SLTDataType x);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPopFront(SLTNode** pphead);
