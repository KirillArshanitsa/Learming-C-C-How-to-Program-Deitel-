#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CLIENT_TIME 3

struct queueNode{
    unsigned int customerServiceTime;
    struct nodeQueue* nodeQueuePtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr* ,QueueNodePtr*, unsigned int);
unsigned int dequeue(QueueNodePtr* ,QueueNodePtr*);
void printQueue(QueueNodePtr);
unsigned int getMaxCountClientinQueue(QueueNodePtr);

int main (void)
{
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;

    int allWokTime = 720;

    unsigned int timeClientEmergence = 1 + rand() % MAX_CLIENT_TIME;
    unsigned int timeServiceClient = 1 + rand() % MAX_CLIENT_TIME;
    unsigned int timeNextClientEmergence = 0;

    unsigned int maxCountClientinQueue = 0;
    unsigned int tmpCountClientinQueue;
    unsigned int maxTimeWaitService = timeClientEmergence + timeServiceClient;
    unsigned int tmpTimeWaitService;

    srand(time(NULL));

    while(--allWokTime){
        if(timeNextClientEmergence != 0) {
            enqueue(&headPtr, &tailPtr, NULL);
            tmpCountClientinQueue = getMaxCountClientinQueue(headPtr);
            if (tmpCountClientinQueue > maxCountClientinQueue)
                maxCountClientinQueue = tmpCountClientinQueue;
            timeNextClientEmergence = 0;
        }
        timeNextClientEmergence = 1 + rand() % MAX_CLIENT_TIME;

        if (timeClientEmergence != 0) {
            --timeClientEmergence;
            continue;
        }

        if(timeServiceClient !=0) {
            --timeServiceClient;
            continue;
        }
        timeServiceClient = dequeue(&headPtr, &tailPtr);
        timeClientEmergence = 1 + rand() % 4;

        tmpTimeWaitService = timeClientEmergence + timeServiceClient + timeNextClientEmergence;
        if (tmpTimeWaitService > maxTimeWaitService)
            maxTimeWaitService = tmpTimeWaitService;

    }

    printf("Max client count = %u\n", maxCountClientinQueue);
    printf("Max client wait time = %u\n", maxTimeWaitService);
    return 0;
}

unsigned int getMaxCountClientinQueue(QueueNodePtr headPtr)
{
    unsigned int maxCount = 0;
    while(headPtr != NULL) {
        maxCount++;
        headPtr = headPtr->nodeQueuePtr;
    }
    return maxCount;
}

void printQueue(QueueNodePtr headPtr)
{
    while(headPtr != NULL) {
        printf("%u\n", headPtr->customerServiceTime);
        headPtr = headPtr->nodeQueuePtr;
    }

}

unsigned int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
    QueueNodePtr tmpPtr;
    unsigned int returnedVal;

    tmpPtr = *headPtr;
    returnedVal = tmpPtr->customerServiceTime;
    *headPtr = tmpPtr->nodeQueuePtr;

    //if(*headPtr == NULL)
    if(tmpPtr == NULL)
        *tailPtr = NULL;
    free(tmpPtr);

    return returnedVal;
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, unsigned int serviceCustomerTime)
{
    QueueNodePtr newPtr;
    newPtr = malloc(sizeof(QueueNode));
    if (newPtr != NULL){
        newPtr->customerServiceTime = serviceCustomerTime;
        newPtr->nodeQueuePtr = NULL;

        if ((*headPtr) == NULL)
            *headPtr = newPtr;
        else
            (*tailPtr)->nodeQueuePtr = newPtr;
        *tailPtr = newPtr;

    }
    else
        printf("Error create node with %u\n", serviceCustomerTime);
}