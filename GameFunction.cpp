#include"GameFunction.h"



GameStart:: GameStart(){
        cout<<"\n\t---GAME STARTS---\n";
        generateGame.PrintBoard();
        GameContinue();
    }   

bool GameStart:: WannaPlayAgain(){
            cin>>playAgain;
            if(playAgain=='y'||playAgain=='Y'){
                return true;
            }
            return false;
        }

void GameStart:: GameContinue(){
            bool notMine=true;
            int a,b;
            while(notMine==true&&generateGame.BoxCount()>0){
                cout<<"\nEnter Your Dimensions: \n";
                cin>>a>>b;
            if(a<10&&a>-1&&b<10&&b>-1){
                generateGame.ChangeBoard(a,b);
                generateGame.PrintBoard();
                notMine=generateGame.isItMine(a,b);
            } 
            else 
            {   
                cout<<"\n---Enter Valid Dimensions---\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            }
            if(notMine==false){
                cout<<"\n\t     ---YOU LOSER---\n";
                cout<<"\t These were the Locations: \n";
                generateGame.PrintBackBoard();
            }else{
                cout<<"\n\t\t  ---DEMNN YOU WON---\n";
            }

            cout<<"\nWANNA GO AGAIN? (y/Y twice or anything twice to quit): ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            WannaPlayAgain();
        }
 