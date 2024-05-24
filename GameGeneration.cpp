#include"GameGeneration.h"

void GameGeneration:: ChangeBoard(int a,int b){
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


void GameGeneration:: GenerateBoard(int a, int b){
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





// class GameGeneration:public Mine{
//     public:

//     void ChangeBoard(int a,int b){
//             if(firstMove==true){
//                 GenerateBoard(a,b);
//                 firstMove=false;
//             }
//             if(a>-1&&a<size&&b>-1&&b<size&&board[a][b]=='X'){
//                 displayBoard[a][b]=board[a][b];
//             }else{
//             SetDisplayBoard(a,b);
//             }
//         }


//     void GenerateBoard(int a, int b){
//             unordered_set<int>xSet;
//             unordered_set<int>ySet;
//             srand(time(NULL));
//             while(xSet.size()<mines){
//                 int temp=rand()%10;
//                 while(temp==a){
//                     temp=rand()%10;
//                 }
//                 xSet.insert(temp);
//             }
//             while(ySet.size()<mines){
//                 int temp=rand()%10;
//                 while(temp==b){
//                     temp=rand()%10;
//                 }
//                 ySet.insert(temp);
//             }
//             vector<int>arr1;
//             vector<int>arr2;
//             int m=0;
//             int n=0;
//             for(auto i:xSet){
//                 arr1.push_back(i);
//                 m++;
//             }
//             for(auto i:ySet){
//                 arr2.push_back(i);
//                 n++;
//             }
//             for(int i=0;i<mines;i++){
//             int xR=arr1[i];
//             int yR=arr2[i];  
//             SetMinesOnBoard(xR,yR);  
//             SetAdjancy(xR+1,yR);
//             SetAdjancy(xR-1,yR);
//             SetAdjancy(xR,yR+1);
//             SetAdjancy(xR,yR-1);
//             SetAdjancy(xR+1,yR+1);
//             SetAdjancy(xR+1,yR-1);
//             SetAdjancy(xR-1,yR-1);
//             SetAdjancy(xR-1,yR+1);
//             }
//         }
// };



