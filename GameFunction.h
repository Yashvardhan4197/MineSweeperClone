#include<iostream>
#include<String>
#include <limits>
#include"GameGeneration.h"
using namespace std;


class GameStart{
    private:
    char playAgain;
    GameGeneration generateGame;
    public:
    GameStart(); 
    bool WannaPlayAgain();
    void GameContinue();

};
