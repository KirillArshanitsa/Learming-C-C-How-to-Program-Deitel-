#include <stdio.h>
#include <stdlib.h>

struct linkedList{
   int num;
   linkedList *listPtr;
};

typedef linkedList LinkedList;
typedef LinkedList * LinkedListPtr;

void printLinkedList(LinkedListPtr);
void insertLinkedList(LinkedListPtr*, int);
void printListBackwards(LinkedListPtr);


int main(void)
{
    LinkedListPtr linkedListPtr = NULL;
    for (int i = 0 ; i < 10 ;i++)
        insertLinkedList(&linkedListPtr, i);

    puts("Print in original order:");
    printLinkedList(linkedListPtr);
    puts("\nPrint in backwards:");
    printListBackwards(linkedListPtr);
    
    return 0;
}

void printListBackwards(LinkedListPtr linkedListPtr)
{
    if(linkedListPtr == NULL)
        return;
    printListBackwards(linkedListPtr->listPtr);
    printf("%d ", linkedListPtr->num);
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