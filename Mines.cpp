#include"Mines.h"

Mine:: Mine(){
    mines=9;
}
int Mine:: getMinesNumber(){
        return mines;
    }
bool Mine:: isItMine(int a, int b){
    if(displayBoard[a][b]=='X'){
                return false;
            }
            return true;
        }

int Mine:: BoxCount(){
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
