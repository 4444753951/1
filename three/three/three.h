#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define ROW 3
#define COL 3

//��ʼ��
void InitBoard(char arr[ROW][COL], int row, int col);
//��ӡ
void PrintBoard(char arr[ROW][COL], int row, int col);
//�������
void PlayerMove(char arr[ROW][COL], int row, int col);
//��������
void ComputerMove(char arr[ROW][COL], int row, int col);
//�ж�ʤƽ
char Win(char arr[ROW][COL], int row, int col);

