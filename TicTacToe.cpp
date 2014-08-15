#include <iostream>
#include <stdlib.h>
using namespace std;


void alternatePlayer(int cRound, char cTable[3][3]){
    char cChoice, cPlayer;
    if (cRound%2==0) {cPlayer='X';}
    else if (cRound%2!=0) {cPlayer='O';}
    cout << "Player's " << cPlayer << " choice: "; cin >> cChoice;
    int i, j;
    i=(cChoice-'1'-j)/3;
    j=cChoice-'1'-3*i;
    cTable[i][j]=cPlayer;
}

bool finishGame(char cTable[3][3]){
    if (cTable[0][0]==cTable[0][1] && cTable[0][1]==cTable[0][2]) {return true;}
    else if (cTable[1][0]==cTable[1][1] && cTable[1][1]==cTable[1][2]) {return true;}
    else if (cTable[2][0]==cTable[2][1] && cTable[2][1]==cTable[2][2]) {return true;}
    else if (cTable[0][0]==cTable[1][0] && cTable[1][0]==cTable[2][0]) {return true;}
    else if (cTable[0][1]==cTable[1][1] && cTable[1][1]==cTable[2][1]) {return true;}
    else if (cTable[0][2]==cTable[1][2] && cTable[1][2]==cTable[2][2]) {return true;}
    else if (cTable[0][0]==cTable[1][1] && cTable[1][1]==cTable[2][2]) {return true;}
    else if (cTable[0][2]==cTable[1][1] && cTable[1][1]==cTable[2][0]) {return true;}
    else {return false;}
}

void table (char cTable[3][3]){
    system("cls");
    cout << cTable[0][0] << "|" << cTable[0][1] << "|" << cTable[0][2] << endl;
    cout << "-+-+-" << endl;
    cout << cTable[1][0] << "|" << cTable[1][1] << "|" << cTable[1][2] << endl;
    cout << "-+-+-" << endl;
    cout << cTable[2][0] << "|" << cTable[2][1] << "|" << cTable[2][2] << endl;
}

void checkPlayer(int cRound){
    if ((cRound-1)%2==0) {cout << "Player X win";}
    else if ((cRound-1)%2!=0) {cout << "Player O win";}
}

void introduction(){
    cout << "<-----Tic Tac Toe----->       Board Game";
    cout << endl << endl;
    cout << "To put X or O you need to enter the square's number and press Enter." << endl;
    cout << "First player who will get 3 symbols on a row,, column or a diagonal win." << endl;;
    cout << "Good luck!" << endl;
    system("PAUSE");
}

int main(){
    introduction();
    char cSquare[3][3];
    int round=0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cSquare[i][j]=3*i+j+'1';}}
    table(cSquare);
    do {
        alternatePlayer(round, cSquare);
        table(cSquare);
        round++;
    }while(finishGame(cSquare)==false);

    if (finishGame(cSquare)==true){
        {checkPlayer(round);}
    }
    return 0;
}
