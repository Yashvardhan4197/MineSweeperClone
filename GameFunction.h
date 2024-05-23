#include<iostream>
#include<cstdlib>
#include<String>
#include<unordered_set>
#include<time.h>
#include <limits>
#include<vector>
using namespace std;


class Board{
    protected:
    char displayBoard[10][10];
    char board[10][10];
    int size=10;
    bool firstMove=true;
    public:
    Board(){
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    board[i][j]='0';
                    displayBoard[i][j]='B';
                }
            }
    }
    public:
    void SetMinesOnBoard(int a, int b){
        board[a][b]='X';
    }

        void SetDisplayBoard(int a, int b){
            if(a>-1&&a<size&&b>-1&&b<size&&displayBoard[a][b]=='B'){
                displayBoard[a][b]=board[a][b];
                if(board[a][b]=='0'&&board[a][b]!='X'){
                    SetDisplayBoard(a+1,b);
                    SetDisplayBoard(a-1,b);
                    SetDisplayBoard(a,b+1);
                    SetDisplayBoard(a,b-1);
                    SetDisplayBoard(a+1,b+1);
                    SetDisplayBoard(a+1,b-1);
                    SetDisplayBoard(a-1,b-1);
                    SetDisplayBoard(a-1,b+1);
                }
            }
        }

        void SetAdjancy(int a, int b){
            int x=a;
            int y=b;
            if(board[x][y]!='X'&&x>-1&&x<size&&y>-1&&y<size){
                board[x][y]=board[x][y]+1;
            }
            }


        void PrintBackBoard(){
            cout<<endl;
            cout<<"    ";
            for(int i=0;i<10;i++){
                cout<<i<<"   ";
            }
            cout<<endl;
            for(int i=0;i<3;i++){
                    cout<<" ";
            }
            for(int i=0;i<size+30;i++){
                cout<<"-";
            }
            cout<<endl;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(j==0){
                        cout<<i<<" | ";
                    }
                    cout<<board[i][j];
                    cout<<" | ";
                }
                cout<<endl;
                for(int i=0;i<3;i++){
                    cout<<" ";
                }
                for(int i=0;i<size+30;i++){
                cout<<"-";
                }
                cout<<endl;
            }


        }


        void PrintBoard(){
            cout<<endl;
            cout<<"    ";
            for(int i=0;i<10;i++){
                cout<<i<<"   ";
            }
            cout<<endl;
            for(int i=0;i<3;i++){
                    cout<<" ";
            }
            for(int i=0;i<size+30;i++){
                cout<<"-";
            }
            cout<<endl;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(j==0){
                        cout<<i<<" | ";
                    }
                    if(displayBoard[i][j]=='B'){
                        cout<<" ";
                    }else{
                    cout<<displayBoard[i][j];
                    }
                    cout<<" | ";
                }
                cout<<endl;
                for(int i=0;i<3;i++){
                    cout<<" ";
                }
                for(int i=0;i<size+30;i++){
                cout<<"-";
                }
                cout<<endl;
            }
        }

};







class Mine:public Board{
    public:
    int mines=9;
    int getMinesNumber(){
        return mines;
    }

    public:
    bool isItMine(int a,int b){
            if(displayBoard[a][b]=='X'){
                return false;
            }
            return true;
        }

    int BoxCount(){
            int total=0;
            int count=0;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(displayBoard[i][j]=='B'){
                        count++;
                    }
                }
            }
            total=count-mines;
            return total;
        }
};


class GameGeneration:public Mine{
    public:

    void ChangeBoard(int a,int b){
            if(firstMove==true){
                GenerateBoard(a,b);
                firstMove=false;
            }
            if(a>-1&&a<size&&b>-1&&b<size&&board[a][b]=='X'){
                displayBoard[a][b]=board[a][b];
            }else{
            SetDisplayBoard(a,b);
            }
        }


    void GenerateBoard(int a, int b){
            unordered_set<int>xSet;
            unordered_set<int>ySet;
            srand(time(NULL));
            while(xSet.size()<mines){
                int temp=rand()%10;
                while(temp==a){
                    temp=rand()%10;
                }
                xSet.insert(temp);
            }
            while(ySet.size()<mines){
                int temp=rand()%10;
                while(temp==b){
                    temp=rand()%10;
                }
                ySet.insert(temp);
            }
            vector<int>arr1;
            vector<int>arr2;
            int m=0;
            int n=0;
            for(auto i:xSet){
                arr1.push_back(i);
                m++;
            }
            for(auto i:ySet){
                arr2.push_back(i);
                n++;
            }
            for(int i=0;i<mines;i++){
            int xR=arr1[i];
            int yR=arr2[i];  
            SetMinesOnBoard(xR,yR);  
            SetAdjancy(xR+1,yR);
            SetAdjancy(xR-1,yR);
            SetAdjancy(xR,yR+1);
            SetAdjancy(xR,yR-1);
            SetAdjancy(xR+1,yR+1);
            SetAdjancy(xR+1,yR-1);
            SetAdjancy(xR-1,yR-1);
            SetAdjancy(xR-1,yR+1);
            }
        }
};



class GameStart{
    private:
    char playAgain;
    GameGeneration generateGame;
    public:
    GameStart(){
        cout<<"\n\t---GAME STARTS---\n";
        generateGame.PrintBoard();
        GameContinue();
    }    

    bool WannaPlayAgain(){
            cin>>playAgain;
            if(playAgain=='y'||playAgain=='Y'){
                return true;
            }
            return false;
        }
    void GameContinue(){
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

};
