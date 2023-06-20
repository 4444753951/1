#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




typedef int SLDataType;

typedef struct SeqLIist//动态顺序表
{
	SLDataType* a;
	int size;         //表示数组中存储了多少个数据
	int capacity;     //数组实际能存储的数据的空间容量是多大
}SL;

//接口函数
void SeqListInit(SL* ps);
void SepListPrintf(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);



void SeqListDestory(SL* ps);
