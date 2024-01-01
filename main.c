#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void resetBoard();
void playerMove();
void computerMove();
void checkForWinner();
void printBoard();
void checkForEmptySpaces();

char pUserSymbol; //tried using pointesr but did not solve wint 
char pComputerSymbol;
char board[3][3];
int emptySpaces;
char winner = ' ';
   
int main(){
    printf("WELCOME TO TICTACTOE, ARE YOU READY TO PLAY!!!, press Y for yes and N for no: ");
    char userInput[255];

    fgets(userInput, 255, stdin);
    if (strcmp(userInput, "Y\n") != 0 && strcmp(userInput, "y\n") != 0){ //no
        printf("Really dude?\n");
        exit(0);
    }
    resetBoard();
    while (true) {
        printf("Would you like to be X or O: ");
        fgets(userInput, 255, stdin);
        if (strncmp(userInput, "X", 1) == 0 || strncmp(userInput, "x", 1) == 0){ //no
            pUserSymbol = 'X';
            pComputerSymbol = 'O';
            break;
        }
        else if (strncmp(userInput, "O", 1) == 0 || strncmp(userInput, "o", 1) == 0){ //no
            pUserSymbol = 'O';
            pComputerSymbol = 'X';
            printBoard();
            break;
        }
        else{
            printf("This is not a correct input, try again\n");
        }
    }
    checkForEmptySpaces();
    int turnCount = 0;
    while (emptySpaces != 0 && winner == ' '){
        //if((strncmp(pUserSymbol, 'O', 1) == 0 && turnCount%2 == 0) || (strncmp(pUserSymbol, 'X', 1) == 0 && turnCount%2 != 0)){ //player move as O will go first in tictactoe
        if((pUserSymbol == 'O' && turnCount%2 == 0) || (pUserSymbol == 'X' && turnCount%2 != 0)){ //player move as O will go first in tictactoe
            playerMove();
            printBoard();
            checkForWinner();
            checkForEmptySpaces();
            turnCount++;
        }
        else {
            computerMove();
            printBoard();
            checkForWinner();
            checkForEmptySpaces();
            turnCount++;
        }
       
    }
    if(winner == pUserSymbol){
        printf("You have won!\n");
    }
    else if (winner == pComputerSymbol){
        printf("You have lost!\n");
    }
    else if (emptySpaces == 0){ //check for winner before empty spaces
        printf("Tie!");
    }
}

void resetBoard(){
    for(int i = 0; i<4; i++){
        for (int j = 0; j<4; j++){
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
            if(board[i][j] == ' '){
                emptySpaces++;
            }
        }
    } 
}
void playerMove(){
    int row;
    int column; //row and column for player entering stuff
    while (true){
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);
        //if(strncmp(board[row-1][column-1], " ", 1) != 0){
        if(board[row-1][column-1] != ' '){
            printf("This space is taken, try again\n");
        }
        else if (row > 3 || column > 3){
            printf("This space doesn't exist, try again\n");
        }
        else{
            break;
        }
    }
    board[row-1][column-1] = pUserSymbol; 
}
void computerMove(){
    srand(time(0)); //seed
    while (true){
        int row = rand()%3;
        int column = rand()%3; //random row and column
        if(board[row][column] == ' '){ //empty space
            board[row][column] = pComputerSymbol; 
            break;
        }
    }
}
void checkForWinner(){
    for(int i = 0; i<3; i++){
        if(board[i][1] == board[i][2] && board[i][0] == board[i][1]){ //horizontal
            winner = board[i][1];
        }
        else if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){ //vertical
            winner = board[0][i];
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){ //diagonal
        winner = board[0][0];
    } 
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        winner = board[0][2];
    }
}