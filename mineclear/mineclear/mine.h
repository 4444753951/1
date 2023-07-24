#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MineNumber 10

#define ROW 10
#define COL 10

#define ROWS ROW+2
#define COLS COL+2

//��ʼ������
void InitBoard(char board[ROWS][COLS],char set);
//��ӡ����
void PrintBoard(char board[ROWS][COLS]);
//������
void SetMineBoard(char mine[ROWS][COLS]);
//�Ų���
void SeekMine(char mine[ROWS][COLS], char show[ROWS][COLS]);
//�Ų�0�׼���Χ
void SeekMine1(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//�����
void FindMine(char show[ROWS][COLS]);
//�жϻ�ʤ
int Win(char mine[ROWS][COLS], char show[ROWS][COLS]);