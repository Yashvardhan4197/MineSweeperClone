#include<iostream>
using namespace std;
class GameDescription{
    public:
    GameDescription(){
        WelcomeText();
        GameDesc();
    }
    void WelcomeText(){
        //TOP
        for(int i=0;i<50;i++){
            cout<<"-";
        }

        //MIDDLE
        cout<<endl<<"|";
        for(int i=0;i<49;i++){
            cout<<" ";
        }
        cout<<"|"<<endl;
        cout<<"|";
        for(int i=0;i<12;i++){
            cout<<" ";
        }
        cout<<"WELCOME TO MINESWEEPER GAME";
        for(int i=0;i<10;i++){
            cout<<" ";
        }
        cout<<"|"<<endl<<"|";
        for(int i=0;i<49;i++){
            cout<<" ";
        }
        cout<<"|"<<endl;

        //BOTTOM
        for(int i=0;i<50;i++){
            cout<<"-";
        }
        cout<<endl<<endl<<endl;
    }

    void GameDesc(){
        cout<<"RULES:\n";
        cout<<"1: The board is divided into cells, with mines randomly distributed.\n"
        <<"2: To win, you need to open all the cells.\n"
        <<"3: The number on a cell shows the number of mines adjacent to it." 
        <<"\n   (Using this information, you can determine cells that are safe, and cells that contain mines.)\n"
        <<"4: Interact, evolve and enjoy!\n"; 

        cout<<endl<<endl;
        cout<<"HOW TO PLAY: "<<endl;
        cout<<"1: User must input x and y coordinates where they want to click\n"
            <<"2: ENJOY YOUR TIME.\n";
        cout<<endl<<endl;
    }
};