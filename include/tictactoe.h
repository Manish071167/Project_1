#ifndef TICTACTOE_H
#define TICTACTOE_H

void resetBoard();
void displayBoard();
int checkWin();
int checkDraw();
void humanMove(char num);
void computerMove();
void playHumanVsHuman();
void playHumanVsComputer();

#endif
