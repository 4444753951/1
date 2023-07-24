#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MineNumber 10

#define ROW 10
#define COL 10

#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘
void InitBoard(char board[ROWS][COLS],char set);
//打印棋盘
void PrintBoard(char board[ROWS][COLS]);
//布置雷
void SetMineBoard(char mine[ROWS][COLS]);
//排查雷
void SeekMine(char mine[ROWS][COLS], char show[ROWS][COLS]);
//排查0雷及周围
void SeekMine1(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//标记雷
void FindMine(char show[ROWS][COLS]);
//判断获胜
int Win(char mine[ROWS][COLS], char show[ROWS][COLS]);