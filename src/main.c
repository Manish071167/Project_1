#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tictactoe.h"

int main() {
    srand(time(0));
    int mode;

    printf("TIC TAC TOE GAME\n");
    printf("1. Human vs Human\n");
    printf("2. Human vs Computer\n");
    printf("Choose mode: ");
    scanf("%d",&mode);

    if(mode==1) playHumanVsHuman();
    else if(mode==2) playHumanVsComputer();
    else printf("Invalid choice!");

    return 0;
}
