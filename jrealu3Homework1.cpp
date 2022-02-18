#include <iostream>
#include <string>
#include <fstream>
#define SPOTS 81 //number of total spots on board
using namespace std;

int store[SPOTS]; //array used to store data from file
int board[9][9] = {0}; //blank board



//used to convert input to ints
int inputToInt(char v){
    switch(v)
    {

        case '0': return 0;
        case '1': return 1;
        break;
        case '2': return 2;
        break;
        case '3': return 3;
        break;
        case '4': return 4;
        break;
        case '5': return 5;
        break;
        case '6': return 6;
        break;
        case '7': return 7;
        break;
        case '8': return 8;
        break;
        case '9': return 9;
        break;
        default : return 0;                             
    }

 


}


bool isPresentRow(int r, int num){ //checks if number is present in row
    for(int c = 0; c < 9 ; c++){
        if(board[r][c] == num){
            return true;
        }
    }
    return false;

}

bool isPresentCol(int c, int num){ //checks if number is present in column
    for(int r = 0; r < 9 ; r++){
        if(board[r][c] == num){
            return true;
        }
    }
    return false;

}

bool isPresentSubBoard(int subBeginR, int subBeginC, int num){ //checks if number is in 3x3 section of board
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3 ; c++){
            if(board[subBeginR + r][subBeginC + c] == num){
                return true;
            }
        }
    }
    return false;

}
bool findEmpty(int &r, int &c){ //finds empty space on board
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(board[r][c] == 0){
                return true;
            }
        }
    }
    return false;

}
bool isValid(int r, int c, int num){ //checks to see if a number can be placed in an empty spot
    int subR = r % 3;
    int subC = c % 3;
    if((isPresentRow(r,num) == false) &&
       (isPresentCol(c,num) == false) &&
       (isPresentSubBoard(r - subR,c - subC, num) == false)){
            return true;           
       }
    return false;

}

bool solve(){ //backtracking algorithm to find solution
    int r, c;
    if(findEmpty(r,c) == false){
        return true;
    }
    for(int num = 1; num <= 9; num++){
        if(isValid(r,c,num) == true){
            board[r][c] = num;
            if(solve() == true){
                return true;
            }
            board[r][c] = 0;
        }
    }
    return false;
}

void printBoard(){
    for(int r = 0; r < 9; r++){
        cout << "|";
        for(int c = 0; c < 9; c++){
            cout << board[r][c] << "|";      
        }
        cout << endl;
    }

}
int main(){

    ifstream file("textfile.txt");
    if(file.fail()){
        cout << "Error";
    }
    else{
        char v;
        int i = 0;
        while(file.get(v)){ //extract data from file
                if(v != '|' && v != '\n'){
                    store[i] = inputToInt(v);
                    i++;
                }

        }
        file.close();
    }

    for(int r = 0; r < 9; r++){ //place stored data into board spots
        for(int c = 0; c < 9; c++){
        board[r][c] = store[(r*10)+c];
        }
    }

    if(solve() == true){
        printBoard();
    }


}