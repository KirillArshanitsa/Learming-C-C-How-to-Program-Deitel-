#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define LIST_SIZE 10

void sortAsc(int[]);
void sortDesc(int[]);
void printList(const int[]);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int myList[LIST_SIZE];

    if (argc < 2){
        printf("Enter one argument. Yoe enter %d\n", argc);
        return -1;
    }

    for (int i = 0 ;i < LIST_SIZE; i++)
        myList[i] = rand();

    if (argv[1][0] == 'a')
        sortAsc(myList);
    else if(argv[1][0] == 'd')
        sortDesc(myList);
    else{
        printf("You enter %s, need a or d\n", argv[0]);
        return -1;
    }

    printList(myList);

    return 0;
}

void printList(const int list[])
{
    for (int i = 0; i < LIST_SIZE; i++)
        printf("%d ", list[i]);
    puts("");
}

void sortAsc(int list[])
{
    int tmp;
    for (int i = 0; i < LIST_SIZE; i++){
        for(int e = i + 1; e < LIST_SIZE ; e++){
            if(list[i] > list[e]){
                tmp = list[i];
                list[i] = list[e];
                list[e] = tmp;
            }
        }
    }
}

void sortDesc(int list[])
{
    int tmp;
    for (int i = 0; i < LIST_SIZE; i++){
        for(int e = i + 1; e < LIST_SIZE ; e++){
            if(list[i] < list[e]){
                tmp = list[i];
                list[i] = list[e];
                list[e] = tmp;
            }
        }
    }
}