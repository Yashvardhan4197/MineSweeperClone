#include<iostream>
#include "GameDescription.h"
#include "GameFunction.h"
using namespace std;
class GameManager{
    private:
    GameDescription gameDescription;   

    bool wannaPlay;

    void StartGame();

    public:
    GameManager();

    bool ManageGame();

};