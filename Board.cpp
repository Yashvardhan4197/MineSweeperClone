#include"Board.h"

Board::Board(){
    size=10;
    firstMove=true;
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    board[i][j]='0';
                    displayBoard[i][j]='B';
                }
            }
    }


void Board:: SetMinesOnBoard(int a, int b){
        board[a][b]='X';
    }

void Board:: SetDisplayBoard(int a, int b){
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

void Board:: SetAdjancy(int a, int b){
            int x=a;
            int y=b;
            if(board[x][y]!='X'&&x>-1&&x<size&&y>-1&&y<size){
                board[x][y]=board[x][y]+1;
            }
            }

void Board:: PrintBackBoard(){
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


void Board:: PrintBoard(){
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

