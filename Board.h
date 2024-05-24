#include<iostream>
using namespace std;

class Board{
protected:
    char displayBoard[10][10];
    char board[10][10];
    int size;
    bool firstMove;

public:
Board();
void SetMinesOnBoard(int a, int b);
void SetDisplayBoard(int a, int b);
void SetAdjancy(int a, int b);
void PrintBackBoard();
void PrintBoard();
};