#include<iostream>
#include<vector>
#include<unordered_set>
#include<time.h>
#include<cstdlib>
#include"Mines.h"
using namespace std;


class GameGeneration:public Mine{
    public:
    void ChangeBoard(int a,int b);
    void GenerateBoard(int a, int b);

};