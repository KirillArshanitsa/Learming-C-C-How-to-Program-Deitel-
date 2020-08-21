// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define COUNTCARDS 5
#define COUNTCHECK 6

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[], int[][2]); // dealing doesn't modify the arrays
int haveOnePair(int[][2]);
int haveTwoPairs(int[][2]);
int haveThreePairs(int[][2]);
int haveCare(int[][2]);
int haveFlush(int[][2]);
int haveStraight(int[][2]);
void parseDeal(int[][2], int(*[])(int[][2]), int[]);

int main(void)
{
    // initialize deck array
    unsigned int deck[SUITS][FACES] = { 0 };
    unsigned int deck2[SUITS][FACES] = { 0 };
    int firstGamerCards[COUNTCARDS][2];
    int secondGamerCards[COUNTCARDS][2];
    int(*checkCards[COUNTCHECK])(int[][2]) = { haveOnePair, haveTwoPairs, haveThreePairs, haveCare, haveFlush, haveStraight};
    int firstGamerResults[COUNTCARDS];
    int secondGamerResults[COUNTCARDS];

    srand(time(NULL)); // seed random-number generator

    shuffle(deck); // shuffle the deck

    // initialize suit array
    const char* suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    // initialize face array
    const char* face[FACES] =
    { "Ace", "Deuce", "Three", "Four",
      "Five", "Six", "Seven", "Eight",
      "Nine", "Ten", "Jack", "Queen", "King" };
    deal(deck, face, suit, firstGamerCards);

    shuffle(deck2);
    deal(deck2, face, suit, secondGamerCards);

    parseDeal(firstGamerCards, checkCards, firstGamerResults);
    parseDeal(secondGamerCards, checkCards, secondGamerResults);

    puts("\nGame results:");
    for (int e = COUNTCHECK - 1; e >= 0; e--) {
        printf("Game check num %d: first gamer %d second gamer %d\n", e, firstGamerResults[e], secondGamerResults[e]);
        if (firstGamerResults[e] > secondGamerResults[e]) {
            printf("First gamer wins\n");
            return 0;
        }      
        else if (firstGamerResults[e] < secondGamerResults[e]) {
            printf("Second gamer wins\n");
            return 0;
        }
    }
    puts("Draw");
    return 0;
}



void parseDeal(int gamerCards[][2], int(*checkCards[COUNTCHECK])(int[][2]), int results[]) {
    //puts("Gamer Cards");
    //for (int i = 0; i < COUNTCARDS; i++)
    //    printf("row = %d column = %d\n", gamerCards[i][0], gamerCards[i][1]);

    for (int i = 0; i < COUNTCHECK; i++) {
        results[i] = (*checkCards[i])(gamerCards);
    }
}


// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
    // for each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) {
        size_t row; // row number
        size_t column; // column number

        // choose new random location until unoccupied slot found
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0); // end do...while

        // place card number in chosen slot of deck
        wDeck[row][column] = card;
    }
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char* wFace[],
    const char* wSuit[], int result[][2])
{
    // deal each of the cards
    int done;
    puts("Gamer cards");
    for (size_t card = 1; card <= COUNTCARDS; ++card) {
        done = 1;
        // loop through rows of wDeck
        for (size_t row = 0; row < SUITS; ++row) {
            if (done) {
                // loop through columns of wDeck for current row
                for (size_t column = 0; column < FACES; ++column) {
                    // if slot contains current card, display card
                    if (wDeck[row][column] == card) {
                        printf("%s %d of %s %d %3s", wFace[column], column, wSuit[row], row, " "); 
                        result[card - 1][0] = row;
                        result[card - 1][1] = column;
                        done = 0;
                        break;
                    }
                }
            }
        }
    }
    puts("");
}
int haveOnePair(int listCards[][2]) {
    int pairCount = 0;
    for (int i = 0; i < COUNTCARDS - 1; i++) {
        for (int e = i + 1; e < COUNTCARDS; e++) {
            if (listCards[i][1] == listCards[e][1])
                ++pairCount;
            if (pairCount > 1)
                return 0;
        }
    }
    if (pairCount == 1)
        return 1;
    else
        return 0;
}

int haveTwoPairs(int listCards[][2]) {
    int countPairs = 0;
    for (int i = 0, cardPair; i < COUNTCARDS - 1; i++) {
        cardPair = 0;
        for (int e = i + 1; e < COUNTCARDS; e++) {
            if (listCards[i][1] == listCards[e][1]) {
                ++cardPair;
            }
        }
        //TODO change it
        if (cardPair > 1)
            return 0;
        if (cardPair == 1)
            ++countPairs;
    }
    if (countPairs == 2)
        return 1;
    else
        return 0;

}

int haveThreePairs(int listCards[][2]) {
    int countPairs = 0;
    for (int i = 0, cardPair; i < COUNTCARDS - 1; i++) {
        cardPair = 0;
        for (int e = i + 1; e < COUNTCARDS; e++) {
            if (listCards[i][1] == listCards[e][1]) {
                ++cardPair;
            }
        }
        //TODO change it
        if (cardPair > 3)
            return 0;
        if (cardPair == 1)
            ++countPairs;
    }
    if (countPairs == 3)
        return 1;
    else
        return 0;

}

int haveCare(int listCards[][2]) {
    int countPairs = 0;
    for (int i = 0, cardPair; i < COUNTCARDS - 1; i++) {
        cardPair = 0;
        for (int e = i + 1; e < COUNTCARDS; e++) {
            if (listCards[i][1] == listCards[e][1]) {
                ++cardPair;
            }
        }
        //TODO change it

        if (cardPair == 1)
            ++countPairs;
    }
    if (countPairs == 4)
        return 1;
    else
        return 0;
}

int haveFlush(int listCards[][2]) {
    int countPairs = 0;
    for (int i = 0, cardPair; i < COUNTCARDS - 1; i++) {
        cardPair = 0;
        for (int e = i + 1; e < COUNTCARDS; e++) {
            if (listCards[i][0] == listCards[e][0]) {
                ++cardPair;
            }
        }

        if (cardPair == 1)
            ++countPairs;
    }
    if (countPairs == 4)
        return 1;
    else
        return 0;
}

int haveStraight(int listCards[][2]) {
    int sortedListCards[COUNTCARDS];
    for (int i = 0; i < COUNTCARDS; i++) {
        sortedListCards[i] = listCards[i][1];
    }

    for (int e = 0, minVal; e < COUNTCARDS - 1; e++) {
        minVal = sortedListCards[e];
        for (int i = e + 1; i < COUNTCARDS; i++) {
            if (minVal > sortedListCards[i]) {
                sortedListCards[e] = sortedListCards[i];
                sortedListCards[i] = minVal;
                minVal = sortedListCards[e];
            }
        }
    }

    for (int i = 0; i < COUNTCARDS - 1; i++) {
        if (sortedListCards[i] != sortedListCards[i + 1])
            return 0;
    }
    return 1;
}