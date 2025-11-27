#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tictactoe.h"

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void resetBoard() {
    char c = '1';
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = c++;
}

void displayBoard() {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

int checkWin() {
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return 1;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return 1;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return 1;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return 1;
    return 0;
}

int checkDraw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

void humanMove(char num) {
    int ch, r, c;
    while(1){
        printf("Player (%c), enter position 1-9: ", num);
        scanf("%d",&ch);
        if(ch>=1 && ch<=9){
            r=(ch-1)/3; c=(ch-1)%3;
            if(board[r][c] != 'X' && board[r][c] != 'O'){
                board[r][c]=num;
                break;
            }
        }
        printf("Invalid move! Try again.\n");
    }
}

void computerMove() {
    printf("Computer's turn (O):\n");
    int r,c,ch;
    while(1){
        ch=rand()%9 + 1;
        r=(ch-1)/3; c=(ch-1)%3;
        if(board[r][c] != 'X' && board[r][c] != 'O'){
            board[r][c]='O';
            break;
        }
    }
}

void playHumanVsHuman() {
    int t=0;
    resetBoard();
    while(1){
        displayBoard();
        if(t%2==0) humanMove('X');
        else       humanMove('O');

        if(checkWin()){
            displayBoard();
            printf("Player %d Wins!\n",(t%2)+1);
            break;
        }
        if(checkDraw()){
            displayBoard();
            printf("Game Draw!\n");
            break;
        }
        t++;
    }
}

void playHumanVsComputer() {
    int t=0;
    resetBoard();
    while(1){
        displayBoard();
        if(t%2==0) humanMove('X');
        else       computerMove();

        if(checkWin()){
            displayBoard();
            printf(t%2==0 ? "You Win!\n" : "Computer Wins!\n");
            break;
        }
        if(checkDraw()){
            displayBoard();
            printf("Game Draw!\n");
            break;
        }
        t++;
    }
}
