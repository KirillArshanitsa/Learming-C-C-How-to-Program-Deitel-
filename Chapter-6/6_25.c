#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int[][8]);
int checkStep(int[][8], int, int, int, int, int);

void printBoard(int board[][8]) {
    for (int e = 0; e < 8; e++) {
        for (int i = 0; i < 8; i++) {
            printf("%4d", board[e][i]);
        }
        puts("");
    }
}

//check all possible steps
int checkStep(int board[][8], int currentColumn, int currentRow, int horizontal, int vertical, int count) {

    currentRow = currentRow + vertical; //currentRow - (-vertical)
    currentColumn = currentColumn + horizontal; //currentColumn - (-horizontal)

    if (!((currentRow >= 0) && (currentRow < 8)))
        return 0;
    if (!((currentColumn >= 0) && (currentColumn < 8)))
        return 0;

    //printf("localCurrentRow = %d, localurrentColumn = %d\n", currentRow, currentColumn);
    if (board[currentRow][currentColumn] == 0) {
        board[currentRow][currentColumn] = count;
        return 1;
    }
    else
        return 0;

}

int main(void) {
    srand(time(NULL));
    //int board[8][8] = { 0 };
    int currentRow = 0;
    int currentColumn = 0;
    //board[currentRow][currentColumn] = 65; // for debug begin position
    int succStepCount = 1;

    int horizontal[8] = { 0 };
    int vertical[8] = { 0 };

    horizontal[0] = 2;
    horizontal[1] = 1;
    horizontal[2] = -1;
    horizontal[3] = -2;
    horizontal[4] = -2;
    horizontal[5] = -1;
    horizontal[6] = 1;
    horizontal[7] = 2;
    vertical[0] = -1;
    vertical[1] = -2;
    vertical[2] = -2;
    vertical[3] = -1;
    vertical[4] = 1;
    vertical[5] = 2;
    vertical[6] = 2;
    vertical[7] = 1;

    int randomNum;
    int maxsuccStepCount = 0;
    for (unsigned int i = 0; i < 10000; i++) {
        succStepCount = 0;
        int board[8][8] = { 0 };
        currentRow = 1;
        currentColumn = 1;
        board[currentRow][currentColumn] = 65; // for debug begin position

        for (int stepCount = 1; stepCount <= 64; stepCount++) {
            randomNum = rand() % 8;
            if (checkStep(board, currentColumn, currentRow, horizontal[randomNum], vertical[randomNum], succStepCount)) {
                ++succStepCount;
                currentRow += vertical[randomNum];
                currentColumn += horizontal[randomNum];
            }
        }
        if (maxsuccStepCount < succStepCount) {
            maxsuccStepCount = succStepCount;
            printBoard(board);
            printf("\nsuccStepCount = %d, currentRow = %d currentColumn = %d\n", succStepCount, currentRow, currentColumn);
        }

        if (succStepCount >= 64) {
            puts("\n\n\nSuccess!!");
            printBoard(board);
            printf("\nsuccStepCount = %d, currentRow = %d currentColumn = %d\n", succStepCount, currentRow, currentColumn);
            break;
        }
    }
    puts("\n\Finish!");
    printf("maxsuccStepCount = %d\n\n", maxsuccStepCount);
    return 0;
}