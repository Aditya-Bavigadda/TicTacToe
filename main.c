#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void resetBoard();
void playerMove();
void computerMove();
void checkForWinner();
void printBoard();
void checkForEmptySpaces();

char userSymbol;
char computerSymbol;
char board[2][2];
int emptySpaces;
char winner;

int main(){
    printf("WELCOME TO TICTACTOE, ARE YOU READY TO PLAY!!!, press Y for yes and N for no: ");
    char userInput[255];
    fgets(userInput, 255, stdin);
    if (strcmp(userInput, "Y\n") != 0 && strcmp(userInput, "y\n") != 0){ //no
        printf("Really dude?\n");
        exit(0);
    }
    while (true) {
        printf("Would you like to be X or O: ");
        fgets(userInput, 255, stdin);
        if (strncmp(userInput, "X", 1) == 0 || strncmp(userInput, "x", 1) == 0){ //no
            userSymbol = 'X';
            computerSymbol = 'O';
            break;
        }
        else if (strncmp(userInput, "O", 1) == 0 || strncmp(userInput, "o", 1) == 0){ //no
            userSymbol = 'O';
            computerSymbol = 'X';
            break;
        }
        else{
            printf("This is not a correct input, try again\n");
        }
    }
    resetBoard();
    printBoard();
    checkForEmptySpaces();
    while (emptySpaces != 0 && winner == ' '){
        if(userSymbol == "O"){
            playerMove();
            printBoard();
            checkForWinner();
            checkForEmptySpaces();
        }
        else{
            computerMove();
        }
    }
}

void resetBoard(){
    for(int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            board[i][j] = ' '; //resets board
        }
    }    
}
void printBoard(){
    printf("------------\n");
    for (int i = 0; i < 3; i++){
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        printf("\n------------\n");
    }
}
void checkForEmptySpaces(){
    emptySpaces = 0;
    for(int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if(board[i][j] = ' '){
                emptySpaces++;
            }
        }
    } 
}
void playerMove(){

}
void computerMove(){

}
void checkForWinner(){
    if(winning condition){
        winner = userSymbol;
    }
}