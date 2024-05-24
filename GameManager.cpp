#include"GameManager.h"

void GameManager:: StartGame(){
        while(wannaPlay==true){
        GameStart *gameStart=new GameStart();
        wannaPlay=gameStart->WannaPlayAgain();
        delete gameStart;
        }
    }

GameManager:: GameManager(){
        wannaPlay=ManageGame();
        if(wannaPlay==true){
            StartGame();
            
        }
    }

bool GameManager:: ManageGame()
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
    