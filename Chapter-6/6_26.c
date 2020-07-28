#include <stdio.h>

void printBoard(int[][8]);
int getNumExludedCels( int, int);

void printBoard(int board[][8]) {
    for (int e = 0; e < 8; e++) {
        for (int i = 0; i < 8; i++) {
            printf("%4d", board[e][i]);
        }
        puts("");
    }
}

int getNumExludedCels( int vertical, int horisontal){
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

    return cellCount + 15 ;

}

int main(void) {
    int board[8][8] = { 0 };
    int exludedCelsCount;
    //int vertical = 0;
    //int horisontal = 0;
    //printf("vertical = %d, horisontal = %d\n", vertical ,horisontal);

    for (int vertical = 0 ; vertical <= 7 ; vertical++){
        for (int horisontal = 0; horisontal <= 7 ; horisontal ++){
            exludedCelsCount = getNumExludedCels(vertical, horisontal);
            if (exludedCelsCount == -1){
                printf("Error in vertical = %d, horisontal = %d\n", vertical ,horisontal);
                break;
            }
            else{
                board[vertical][horisontal] = exludedCelsCount;
            }
        }

    }
    //printf("cellCount =  %d", getNumExludedCels(board, vertical, horisontal));
    puts("");
    printBoard(board);

    return 0;
}