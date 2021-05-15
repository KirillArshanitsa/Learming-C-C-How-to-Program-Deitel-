// Fig. 12.19: fig12_19.c
// Creating and traversing a binary tree
// preorder, inorder, and postorder
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

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
TreeNodePtr binaryTreeSearch(TreeNodePtr *, int);

// function main begins program execution
int main(void)
{
    TreeNodePtr rootPtr = NULL; // tree initially empty

    srand(time(NULL));
    puts("The numbers being placed in the tree are:");

    int serachVal = 0;

    // insert random values between 0 and 14 in the tree
    for (unsigned int i = 1; i <= 15; ++i) {
        int item = rand() % 25;
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


    printf("\n\nSearch value - %d\n", serachVal);
    binaryTreeSearch(&rootPtr, serachVal) != NULL ? printf("Find node with %d", serachVal) :puts("Not found");
}

TreeNodePtr binaryTreeSearch(TreeNodePtr *treeNodePtr, int searchVal)
{
    TreeNodePtr currentNode = *treeNodePtr;
    while(currentNode != NULL){
        if (currentNode->data == searchVal)
            return currentNode;
        else if(currentNode->data > searchVal)
            currentNode = currentNode->leftPtr;
        else if(currentNode->data < searchVal)
            currentNode = currentNode->rightPtr;
    }
    printf("Node with value %d not found", searchVal);
    return NULL;
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


