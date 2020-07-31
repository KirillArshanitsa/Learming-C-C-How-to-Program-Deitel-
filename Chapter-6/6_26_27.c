#include <stdio.h>
#include <stdlib.h>

void printBoard(int[][8]);
void clearBoard(int[][8]);
int getNumExludedCels(int, int);
int setAccessibilityBoard(int[][8]);
int makeMove(int[][8], int, int, int);

void printBoard(int board[][8]) {
    for (int e = 0; e < 8; e++) {
        for (int i = 0; i < 8; i++) {
            printf("%4d", board[e][i]);
        }
        puts("");
    }
}

void clearBoard(int board[][8]) {
    for (int e = 0; e < 8; e++) {
        for (int i = 0; i < 8; i++) {
            board[e][i] = 0;
        }
    }
}

int getNumExludedCels(int vertical, int horisontal){
    int cellCount = 0;
    int localVertical;
    int localHorisontal;

    if ((vertical < 0) || (vertical > 8))
        return -1;
    if ((horisontal < 0) || (horisontal > 8))
        return -1;

    //up to left
    localVertical = vertical;
    localHorisontal = horisontal;
    while (localVertical > 0 && localHorisontal > 0){
        --localVertical;
        --localHorisontal;
        ++cellCount;
    }

//    printf("up to left cellCount =  %d\n", cellCount);
//    cellCount = 0;

    //up to right
    localVertical = vertical;
    localHorisontal = horisontal;
    while (localVertical < 7 && localHorisontal > 0){
        ++localVertical;
        --localHorisontal;
        ++cellCount;
    }

//    printf("up to right cellCount =  %d\n", cellCount);
//    cellCount = 0;

    //down to right
    localVertical = vertical;
    localHorisontal = horisontal;

    while (localVertical < 7 && localHorisontal < 7){
        ++localVertical;
        ++localHorisontal;
        ++cellCount;
    }

//    printf("down to right cellCount =  %d\n", cellCount);
//    cellCount = 0;

    //down to left
    localVertical = vertical;
    localHorisontal = horisontal;
    while (localVertical > 0 && localHorisontal < 7){
        --localVertical;
        ++localHorisontal;
        ++cellCount;
    }

    //printf("down to left cellCount =  %d\n", cellCount);
    // + 15 horisontal and vertical;
    return cellCount + 15 ;
}


int setAccessibilityBoard(int accessibilityBoard[][8]){
    int exludedCelsCount;
    for (int vertical = 0 ; vertical <= 7 ; vertical++){
        for (int horisontal = 0; horisontal <= 7 ; horisontal ++){
            exludedCelsCount = getNumExludedCels(vertical, horisontal);
            if (exludedCelsCount == -1){
                printf("Error in vertical = %d, horisontal = %d\n", vertical ,horisontal);
                return 1;
            }
            else{
                accessibilityBoard[vertical][horisontal] = exludedCelsCount;
            }
        }
    }
    return 0;
}

int makeMove(int board[][8], int vertical, int horisontal, int moveNum){
    int localVertical;
    int localHorisontal;

    if ((vertical < 0) || (vertical > 8))
        return -1;
    if ((horisontal < 0) || (horisontal > 8))
        return -1;


    //up to left
    localVertical = vertical;
    localHorisontal = horisontal;
    while (localVertical >= 0 && localHorisontal >= 0){
        if ( (board[localVertical][localHorisontal] == 0) || (board[localVertical][localHorisontal] > moveNum) ){
            //board[localVertical][localHorisontal] = moveNum;
            --localVertical;
            --localHorisontal;
        }
        else {
            //printf("Error move %d in board[%d][%d] = %d\n", moveNum,localVertical , localHorisontal, board[localVertical][localHorisontal]);
            return -1;
        }
    }

    //up to right
    localVertical = vertical;
    localHorisontal = horisontal;
    while (localVertical < 8 && localHorisontal >= 0){
        if ( (board[localVertical][localHorisontal] == 0) || (board[localVertical][localHorisontal] > moveNum) ) {
            //board[localVertical][localHorisontal] = moveNum;
            ++localVertical;
            --localHorisontal;
        }
        else {
            //printf("Error move %d in board[%d][%d] = %d\n", moveNum,localVertical , localHorisontal, board[localVertical][localHorisontal]);
            return -1;
        }
    }

    //down to right
    localVertical = vertical;
    localHorisontal = horisontal;

    while (localVertical < 8 && localHorisontal < 8){
        if ( (board[localVertical][localHorisontal] == 0) || (board[localVertical][localHorisontal] > moveNum) ) {
            //board[localVertical][localHorisontal] = moveNum;
            ++localVertical;
            ++localHorisontal;
        }
        else {
            //printf("Error move %d in board[%d][%d] = %d\n", moveNum,localVertical , localHorisontal, board[localVertical][localHorisontal]);
            return -1;
        }
    }

    //down to left
    localVertical = vertical;
    localHorisontal = horisontal;
    while (localVertical >= 0 && localHorisontal < 8){
        if ( (board[localVertical][localHorisontal] == 0) || (board[localVertical][localHorisontal] > moveNum) ) {
            //board[localVertical][localHorisontal] = moveNum;
            --localVertical;
            ++localHorisontal;
        }
        else {
            //printf("Error move %d in board[%d][%d] = %d\n", moveNum,localVertical , localHorisontal, board[localVertical][localHorisontal]);
            return -1;
        }
    }
    // vertical and horisontal
    for (int e = 0 ; e < 8 ; e++) {
        if ((board[vertical][e] == 0) || (board[vertical][e] > moveNum)) {
            if((board[e][horisontal]== 0) || (board[e][horisontal] > moveNum)){
                //board[vertical][e] = moveNum;
                //board[e][horisontal] = moveNum;
            }
            else {
                //printf("Error move %d in board[%d][%d] = %d\n", moveNum, e, horisontal, board[e][horisontal] );
                return -1;
            }
        }
        else {
            //printf("Error move %d in board[%d][%d] = %d\n", moveNum, vertical, e, board[vertical][e] );
            return -1;
        }
    }

    board[vertical][horisontal] = moveNum;
    return 0 ;
}

int main(void) {
    int board[8][8] = { 0 };
    //int accessibilityBoard[8][8] = { 0 };

    int allCount;
    int count;
    int successCount= 0;
    for (allCount = 0; allCount < 10000; allCount++) {
        count = 1;
        for (int ext = rand() % 8; ext < 8; ext++) {
            for (int in = rand() % 8; in < 8; in++) {
                if (makeMove(board, ext, in, count) == 0) {
                    ++count;
                    break;
                }
            }
        }
        if (--count == 8) {
            ++successCount;
            printf("Count = %d\n", count);
            printBoard(board);
        }
        clearBoard(board);
    }

//    if (setAccessibilityBoard(accessibilityBoard))
//        return 1;
    printf("\n\nTotal count = %d successCount = %d", allCount, successCount);

    return 0;
}