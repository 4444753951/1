#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




typedef int SLDataType;

typedef struct SeqLIist//��̬˳���
{
	SLDataType* a;
	int size;         //��ʾ�����д洢�˶��ٸ�����
	int capacity;     //����ʵ���ܴ洢�����ݵĿռ������Ƕ��
}SL;

//�ӿں���
void SeqListInit(SL* ps);
void SepListPrintf(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);



void SeqListDestory(SL* ps);
