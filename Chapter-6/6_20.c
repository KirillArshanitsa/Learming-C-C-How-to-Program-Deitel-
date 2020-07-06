// Fig. 5.14: fig05_14.c
// Simulating the game of craps.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice(void); // function prototype
void startGane(int[], int[]);
void printArray(int[], int);
double probabilityOfWinning(int[], int);

void startGane(int successGames[], int failGames[]) {
    int myPoint; // player must make this point to win
    enum Status gameStatus; // can contain CONTINUE, WON, or LOST
    int sum = rollDice(); // first roll of the dice
    int gameCount = 0;

    // determine game status based on sum of dice
    switch (sum) {

        // win on first roll
    case 7: // 7 is a winner
    case 11: // 11 is a winner          
        gameStatus = WON;
        ++successGames[gameCount++];
        break;

        // lose on first roll
    case 2: // 2 is a loser
    case 3: // 3 is a loser
    case 12: // 12 is a loser
        gameStatus = LOST;
        ++failGames[gameCount++];
        break;

        // remember point
    default:
        gameStatus = CONTINUE; // player should keep rolling
        myPoint = sum; // remember the point
        printf("Point is %d\n", myPoint);
        break; // optional
    }

    // while game not complete
    while (CONTINUE == gameStatus) { // player should keep rolling
        sum = rollDice(); // roll dice again
        ++gameCount;
        // determine game status
        if (sum == myPoint) { // win by making point
            gameStatus = WON;
            if(gameCount > 20)
                ++successGames[20];
            else
                ++successGames[gameCount];
        }
        else {
            if (7 == sum) { // lose by rolling 7
                gameStatus = LOST;
                gameStatus = WON;
                if (gameCount > 20)
                    ++failGames[20];
                else
                    ++failGames[gameCount];
            }
        }
    }

    // display won or lost message
    if (WON == gameStatus) { // did player win?
        puts("Player wins");
    }
    else { // player lost
        puts("Player loses");
    }
}


// roll dice, calculate sum and display results
int rollDice(void)
{
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value

    // display results of this roll
    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    return die1 + die2; // return sum of dice
}

void printArray(int array[], int arraySize) {
    for (int e = 0; e < arraySize; e++)
        printf("%4d ", array[e]);
    puts("");
}

double probabilityOfWinning(int gamesResult[], int gameCount) {
    int succesCount = 0;
    for (int e = 0; e < 21; e++)
        succesCount += gamesResult[e];
    return (succesCount / ((double)gameCount / 100)) ;
}

int main(void)
{
    unsigned long int allTime = 0;
    // randomize random number generator using current time
    srand(time(NULL));
    int successGames[21] = { 0 };
    int failGames[21] = { 0 };
    int gamesCount = 300;
    int check = 0;

    for (unsigned int beginTime, finishTime, count = gamesCount; count > 0; count--) {
        beginTime = time(NULL);
        printf("%u\n", beginTime);
        startGane(successGames, failGames);
        finishTime = time(NULL);
        printf("%u\n", finishTime);
        allTime = allTime + (finishTime - beginTime);
    }
    puts("\nGames results");
    puts("Game throw:");
    for (int e = 1; e < 22; e++)
        printf("%4d ", e);
    puts("\nSuccess throws games:");
    printArray(successGames, 21);
    puts("Fail throws games:");
    printArray(failGames, 21);
    printf("\n\nProbability of winning is %.0f%s\n", probabilityOfWinning(successGames, gamesCount), "%");
    printf("Average game duration is %.3f sec\n\n", (double)allTime / 1000);
    return 0;
     
}



