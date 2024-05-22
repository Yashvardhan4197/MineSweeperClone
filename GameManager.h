#include<iostream>
#include "GameDescription.h"
#include "GameFunction.h"
using namespace std;
class GameManager{
    private:
    GameDescription gameDescription;   

    bool wannaPlay;

    void StartGame(){
        while(wannaPlay==true){
        GameStart *gameStart=new GameStart();
        wannaPlay=gameStart->WannaPlayAgain();
        delete gameStart;
        }
    }

    public:
    GameManager(){
        wannaPlay=ManageGame();
        if(wannaPlay==true){
            StartGame();
            
        }
    }

    bool ManageGame()
    {
        cout<<"DO YOU WANT TO PLAY (y/Y for Yes) OR (n/N for NO)\n";
        while(true){
        char play;
        cin>>play;
        if(play=='y'||play=='Y'){
            return true;
        }else if(play=='n'||play=='N'){
            return false;
        }else{
            cout<<"Enter Valid Input y/Y or n/N\n";
        }
        }
    }
    

};