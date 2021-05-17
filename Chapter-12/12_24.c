
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// self-referential structure
struct treeNode {
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value
    struct treeNode *rightPtr; // pointer to right subtree
};

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// self-referential structure
struct queueNode {
    TreeNodePtr data; // define data as a char
    struct queueNode *nextPtr; // queueNode pointer
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr value);

void levelOrder(TreeNodePtr *);

// function main begins program execution
int main(void)
{
    TreeNodePtr rootPtr = NULL; // tree initially empty


    srand(time(NULL));
    puts("The numbers being placed in the tree are:");

    // insert random values between 0 and 14 in the tree
    for (unsigned int i = 1; i <= 10; ++i) {
        int item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    // traverse the tree preOrder
    puts("\n\nThe preOrder traversal is:");
    preOrder(rootPtr);

    // traverse the tree inOrder
    puts("\n\nThe inOrder traversal is:");
    inOrder(rootPtr);

    // traverse the tree postOrder
    puts("\n\nThe postOrder traversal is:");
    postOrder(rootPtr);

    puts("\n\n\nThe levelOrder traversal is:");
    levelOrder(&rootPtr);
}

void levelOrder(TreeNodePtr *treePtr)
{
    TreeNodePtr currentPtr = NULL;
    QueueNodePtr headPtr = NULL; // initialize headPtr
    QueueNodePtr tailPtr = NULL; // initialize tailPtr

    enqueue(&headPtr, &tailPtr, *treePtr);
    while(isEmpty(headPtr) == 0){
        currentPtr = dequeue(&headPtr, &tailPtr);
        printf("%d ", currentPtr->data);
        if (currentPtr->leftPtr != NULL)
            enqueue(&headPtr, &tailPtr, currentPtr->leftPtr);
        if (currentPtr->rightPtr != NULL)
            enqueue(&headPtr, &tailPtr, currentPtr->rightPtr);
    }

}


// insert a node at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr value)
{
    QueueNodePtr newPtr = (QueueNodePtr) malloc(sizeof(QueueNode));

    if (newPtr != NULL) { // is space available
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        // if empty, insert node at head
        if (isEmpty(*headPtr)) {
            *headPtr = newPtr;
        }
        else {
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    }
    else {
        printf("%c not inserted. No memory available.\n", value);
    }
}

// remove node from queue head
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
    TreeNodePtr value = (*headPtr)->data;
    QueueNodePtr tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    // if queue is empty
    if (*headPtr == NULL) {
        *tailPtr = NULL;
    }

    free(tempPtr);
    return value;
}

// return 1 if the queue is empty, 0 otherwise
int isEmpty(QueueNodePtr headPtr)
{
    return headPtr == NULL;
}

// print the queue
void printQueue(QueueNodePtr currentPtr)
{
    // if queue is empty
    if (currentPtr == NULL) {
        puts("Queue is empty.\n");
    }
    else {
        puts("The queue is:");

        // while not end of queue
        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}

// insert node into tree
void insertNode(TreeNodePtr *treePtr, int value)
{
    // if tree is empty
    if (*treePtr == NULL) {
        *treePtr = (TreeNodePtr) malloc(sizeof(TreeNode));

        // if memory was allocated, then assign data
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else { // tree is not empty
        // data to insert is less than data in current node
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }

            // data to insert is greater than data in current node
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else { // duplicate data value ignored
            printf("%s", "dup");
        }
    }
}

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{
    // if tree is not empty, then traverse
    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

// begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{
    // if tree is not empty, then traverse
    if (treePtr != NULL) {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

// begin postorder traversal of tree
void postOrder(TreeNodePtr treePtr)
{
    // if tree is not empty, then traverse
    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}


