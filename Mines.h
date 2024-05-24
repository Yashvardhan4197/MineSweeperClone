#include<iostream>
#include"Board.h"
using namespace std;

class Mine:public Board{
    public:
    int mines;
    Mine();
    int getMinesNumber();
    bool isItMine(int a,int b);
    int BoxCount();

};