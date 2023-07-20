#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define ROW 3
#define COL 3

//初始化
void InitBoard(char arr[ROW][COL], int row, int col);
//打印
void PrintBoard(char arr[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char arr[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char arr[ROW][COL], int row, int col);
//判断胜平
char Win(char arr[ROW][COL], int row, int col);

