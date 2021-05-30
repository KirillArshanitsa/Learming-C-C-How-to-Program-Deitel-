#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_COUNT 60

struct nodeTree {
    struct nodeTree* leftNode;
    int num;
    struct nodeTree* rightNode;
};

struct listNode{
    struct listNode* previousPtr;
    unsigned int value;
    struct listNode* nextPtr;
};

typedef struct nodeTree NodeTree;
typedef NodeTree* NodeTreePtr;
typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;

void insertNodeTree(NodeTreePtr*, int);
unsigned int depth(NodeTreePtr);
ListNodePtr depthNum(NodeTreePtr nodeTreePtr, unsigned int levelCount);
void outputTree(NodeTreePtr treePtr, unsigned int totalSpace);

int main(void)
{
    NodeTreePtr nodeTreePtr = NULL;
    srand(time(NULL));

    for (int i = 0, tmpNum; i < MAX_NUM_COUNT; i++) {
        tmpNum = rand() % 90;
        printf("Insert %d\n", tmpNum);
        insertNodeTree(&nodeTreePtr, tmpNum);
    }

    puts("\nPrint:");
    outputTree(nodeTreePtr ,0);
    printf("\nDepth node tree = %u\n", depth(nodeTreePtr));
    return 0;
}

void outputTree(NodeTreePtr treePtr, unsigned int totalSpace)
{
    while(treePtr != NULL){
        outputTree(treePtr->rightNode, totalSpace + 5);
        for (int i = 0 ;i < totalSpace ;i++)
            printf(" ");
        printf("%d\n", treePtr->num);
        treePtr = treePtr->leftNode;
        totalSpace += 5;
    }
}

void insertInList(ListNodePtr* listNodePtr, unsigned int value)
{
    ListNodePtr tmpPtr = NULL;
    ListNodePtr currentNodePtr = *listNodePtr;
    tmpPtr = (ListNodePtr) malloc(sizeof(NodeTree));

    if (tmpPtr != NULL) {
        tmpPtr->value = value;
        tmpPtr->nextPtr = NULL;
        if(currentNodePtr == NULL)
            *listNodePtr = tmpPtr;
        else {
            while(currentNodePtr->nextPtr != NULL)
                currentNodePtr = currentNodePtr->nextPtr;
            currentNodePtr->nextPtr = tmpPtr;
        }
    }
    else {
        printf("Error create nodeList with value = %d\n", value);
        return;
    }
}

unsigned int depth(NodeTreePtr nodeTreePtr)
{
    unsigned int maxLevelCount = 0;
    ListNodePtr listNodePtr = NULL;
    if(nodeTreePtr == NULL)
        return maxLevelCount;

    listNodePtr = depthNum(nodeTreePtr, 1);

    if(listNodePtr != NULL){
        printf("%u ", listNodePtr->value);
        maxLevelCount = listNodePtr->value;
        listNodePtr = listNodePtr->nextPtr;
        while(listNodePtr != NULL){
            printf("%u ", listNodePtr->value);
            if(maxLevelCount < listNodePtr->value)
                maxLevelCount = listNodePtr->value;
            listNodePtr = listNodePtr->nextPtr;
        }
    }

    return maxLevelCount;
}

ListNodePtr depthNum(NodeTreePtr nodeTreePtr, unsigned int levelCount)
{
    static ListNodePtr listNodePtr = NULL;

    printf("nodeTreePtr->num = %d levelCount = %u\n", nodeTreePtr->num, levelCount);
    if(nodeTreePtr->leftNode != NULL)
        depthNum(nodeTreePtr->leftNode, levelCount + 1);
    if(nodeTreePtr->rightNode != NULL)
        depthNum(nodeTreePtr->rightNode, levelCount + 1);

    if((nodeTreePtr->leftNode == NULL) && (nodeTreePtr->rightNode == NULL)) {
        printf("Insert %u\n", levelCount);
        insertInList(&listNodePtr, levelCount);
    }

    return listNodePtr;
}



void insertNodeTree(NodeTreePtr* nodeTreePtr, int val)
{
    NodeTreePtr tmpNodeTreePtr = NULL;

    if (*nodeTreePtr == NULL) {
        tmpNodeTreePtr = (NodeTreePtr)malloc(sizeof(NodeTree));
        if (tmpNodeTreePtr != NULL) {
            tmpNodeTreePtr->num = val;
            tmpNodeTreePtr->leftNode = NULL;
            tmpNodeTreePtr->rightNode = NULL;
            *nodeTreePtr = tmpNodeTreePtr;
        }
        else
            printf("Error create NodeTree for %d\n", val);
    }
    else {
        if ((*nodeTreePtr)->num > val) {
            insertNodeTree(&(*nodeTreePtr)->leftNode, val);
        }
        else if ((*nodeTreePtr)->num < val) {
            insertNodeTree(&(*nodeTreePtr)->rightNode, val);
        }
        else
            printf("Duplicate val %d\n", val);
    }

}