#include <stdio.h>

void printBoard(int[][8]);
int check(int[][8], int, int, int, int, int);

void printBoard(int board[][8]) {
    for (int e = 0; e < 8; e++) {
        for (int i = 0; i < 8; i++) {
            printf("%4d", board[e][i]);
        }
        puts("");
    }
}

//check all possible steps
int check(int board[][8], int currentColumn, int currentRow, int horizontal, int vertical, int count) {
    currentRow = currentRow + vertical; //currentRow - (-vertical)
    currentColumn = currentColumn + horizontal; //currentColumn - (-horizontal)

    if (!((currentRow >= 0) && (currentRow < 8)))
        return 0;
    if (!((currentColumn >= 0) && (currentColumn < 8)))
        return 0;

    //printf("localCurrentRow = %d, localurrentColumn = %d\n", currentRow, currentColumn);
    if (board[currentRow][currentColumn] == 0) {
        //board[currentRow][currentColumn] = count;
        return 1;
    }
    else
        return 0;

}

int main(void) {

    //int board[8][8] = { 0 };

    //CopyPast from book)
    int accessibility[8][8] = { 2
            ,3
            ,4
            ,4
            ,4
            ,4
            ,3
            ,2
            ,3
            ,4
            ,6
            ,6
            ,6
            ,6
            ,4
            ,3
            ,4
            ,6
            ,8
            ,8
            ,8
            ,8
            ,6
            ,4
            ,4
            ,6
            ,8
            ,8
            ,8
            ,8
            ,6
            ,4
            ,4
            ,6
            ,8
            ,8
            ,8
            ,8
            ,6
            ,4
            ,4
            ,6
            ,8
            ,8
            ,8
            ,8
            ,6
            ,4
            ,3
            ,4
            ,6
            ,6
            ,6
            ,6
            ,4
            ,3
            ,2
            ,3
            ,4
            ,4
            ,4
            ,4
            ,3
            ,2
    };

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

    //int currentRow = 0;
    //int currentColumn = 0;
    //board[currentRow][currentColumn] = 65; // for debug begin position

    int count;
    //int resultList[8] = {0};
    int goMoveNumber;
    int minVal;

    int localCurrentRow;
    int localCurrentColumn;

 //   for (unsigned long int i = 0, c = 0; i < 3; i++) {
        for (int out = 0, allCount = 0; out < 8; out++) {
            for (int in = 0; in < 8; in++) {
                allCount++;
                int currentRow = out;
                int currentColumn = in;
                int board[8][8] = {0};
                board[currentRow][currentColumn] = 65; // begin position for debug

                for (count = 1; count <= 64; count++) {
                    int resultList[8] = {0};
                    int checkResult = 0;
                    for (int moveNumber = 0; moveNumber <= 7; moveNumber++) {
                        if (check(board, currentColumn, currentRow, horizontal[moveNumber], vertical[moveNumber],
                                  count)) {
                            resultList[moveNumber] = 1;
                            //currentRow += vertical[moveNumber];
                            //currentColumn += horizontal[moveNumber];
                            checkResult = 1;
                            //break;
                        }
                    }
                    if (checkResult == 0)
                        break;

                    minVal = 8;// max val in accessibility
                    goMoveNumber = 8; // array from 0 to 7 if 8 to exit
                    for (int moveNumber = 0; moveNumber <= 7; moveNumber++) {
                        if (resultList[moveNumber]) {
                            localCurrentRow = currentRow;
                            localCurrentColumn = currentColumn;
                            localCurrentRow += vertical[moveNumber];
                            localCurrentColumn += horizontal[moveNumber];
                            if (minVal >= accessibility[localCurrentRow][localCurrentColumn]) {
                                minVal = accessibility[localCurrentRow][localCurrentColumn];
                                goMoveNumber = moveNumber;
                            }
                        }
                    }
                    //check max val in accessibility
                    if (goMoveNumber == 8)
                        continue;

                    currentRow += vertical[goMoveNumber];
                    currentColumn += horizontal[goMoveNumber];
                    board[currentRow][currentColumn] = count;
                    // printf("\ncurrentRow = %d, currentColumn = %d, goMoveNumber = %d\n", currentRow, currentColumn, goMoveNumber);
                }

                if (count == 64) {
                    printBoard(board);
                    printf("currentRow = %d, currentColumn = %d, step count= %d allCount = %d begintRow = %d beginColumn = %d\n", currentRow, currentColumn,
                           count - 1, allCount, out, in);
                }
            }
        }
    return 0;
}