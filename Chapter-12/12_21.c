#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct linkedList{
   int num;
   linkedList *listPtr;
};

typedef linkedList LinkedList;
typedef LinkedList * LinkedListPtr;

void printLinkedList(LinkedListPtr);
void insertLinkedList(LinkedListPtr*, int);
int* searchList(LinkedListPtr, int);


int main(void)
{
    LinkedListPtr linkedListPtr = NULL;
    int searchVal;
    int *resultPtr;

    srand(time(NULL));
    puts("Enter value for search:");
    scanf_s("%d", &searchVal);

    for (int i = 0 ; i < 10 ;i++)
        insertLinkedList(&linkedListPtr, rand());
    puts("Search value in list:");
    resultPtr = searchList(linkedListPtr, searchVal);
    resultPtr != NULL ? printf("Pointer = %p num = %d\n", resultPtr, *resultPtr) :printf("Result Null\n");
    puts("\nPrint list:");
    printLinkedList(linkedListPtr);

    return 0;
}

int* searchList(LinkedListPtr linkedListPtr, int value)
{
    if(linkedListPtr == NULL)
        return NULL;
    else if(linkedListPtr->num == value)
        return &linkedListPtr->num;

    searchList(linkedListPtr->listPtr, value);
}

void insertLinkedList(LinkedListPtr *linkedListPtr, int value)
{
    LinkedListPtr newNode = NULL;
    LinkedListPtr nextPtr = NULL;
    newNode = (LinkedListPtr) malloc(sizeof(LinkedList));
    if(newNode != NULL){
        if(*linkedListPtr == NULL){
            *linkedListPtr = newNode;
        }
        else{
            nextPtr = (*linkedListPtr);
            while(nextPtr->listPtr != NULL)
                nextPtr = nextPtr->listPtr;
            nextPtr->listPtr = newNode;
        }
        newNode->num = value;
        newNode->listPtr = NULL;
    }
    else
        printf("Error create node for value = %d\n", value);
}

void printLinkedList(LinkedListPtr linkedListPtr)
{
    while(linkedListPtr != NULL){
        printf("%d ", linkedListPtr->num);
        linkedListPtr = linkedListPtr->listPtr;
    }
}