
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
void deleteNode(TreeNodePtr *treePtr, int value);

// function main begins program execution
int main(void)
{
    TreeNodePtr delParrentPtr = NULL; // tree initially empty
    //srand(time(NULL));
    int delVal = 4;
    puts("The numbers being placed in the tree are:");

    // insert random values between 0 and 14 in the tree
    for (unsigned int i = 1; i <= 21; ++i) {
        int item = rand() % 30;
        printf("%3d", item);
        insertNode(&delParrentPtr, item);
    }

    // traverse the tree preOrder
    puts("\n\nThe preOrder traversal is:");
    preOrder(delParrentPtr);

    // traverse the tree inOrder
    puts("\n\nThe inOrder traversal is:");
    inOrder(delParrentPtr);

    // traverse the tree postOrder
    puts("\n\nThe postOrder traversal is:");
    postOrder(delParrentPtr);

    printf("\n\n\nDelete node in tree with %d\n", delVal);
    deleteNode(&delParrentPtr, delVal);
    puts("Print tree after delete:");

    if(delParrentPtr != NULL) {

        puts("\nThe preOrder traversal is:");
        preOrder(delParrentPtr);

        puts("\n\nThe inOrder traversal is:");
        inOrder(delParrentPtr);

        puts("\n\nThe postOrder traversal is:");
        postOrder(delParrentPtr);
    }
    else{
        printf("Delete root node with %d", delVal);
    }


}


void deleteNode(TreeNodePtr *treePtr, int value)
{
    TreeNodePtr currentPtr = *treePtr;
    TreeNodePtr prevousPtr = NULL;
    TreeNodePtr delParrentPtr;
    TreeNodePtr delTmpPtr;

    while (currentPtr != NULL){

/*        printf("currentPtr->data = %d\n", currentPtr->data);
        if (prevousPtr != NULL)
            printf("prevousPtr->data = %d\n", prevousPtr->data);
        else
            puts("prevousPtr = NULL");
        if (currentPtr->rightPtr != NULL)
            printf("currentPtr->rightPtr->data = %d\n", currentPtr->rightPtr->data );
        if (currentPtr->leftPtr != NULL)
            printf("currentPtr->leftPtr->data = %d\n", currentPtr->leftPtr->data );
        puts("");*/

        if (currentPtr->data == value) {
            
            if((currentPtr->rightPtr == NULL) && (currentPtr->leftPtr == NULL)) {
                if (prevousPtr != NULL){
                    if (prevousPtr->leftPtr == currentPtr)
                        prevousPtr->leftPtr = NULL;
                    else
                        prevousPtr->rightPtr = NULL;
                }
                else
                    *treePtr = NULL;
            }
            else if((currentPtr->rightPtr != NULL) && (currentPtr->leftPtr == NULL)) {
                if (prevousPtr->leftPtr == currentPtr)
                    prevousPtr->leftPtr = currentPtr->rightPtr;
                else
                    prevousPtr->rightPtr = currentPtr->rightPtr;
            }
            else if((currentPtr->rightPtr == NULL) && (currentPtr->leftPtr != NULL)) {
                if (prevousPtr->leftPtr == currentPtr)
                    prevousPtr->leftPtr = currentPtr->leftPtr;
                else
                    prevousPtr->rightPtr = currentPtr->leftPtr;

            }
            else {
                delTmpPtr = currentPtr;
                delParrentPtr = prevousPtr;

                //chek if root node
//                if(prevousPtr != NULL)
//                    delParrentPtr = prevousPtr;
//                else
//                    delParrentPtr = currentPtr;

                prevousPtr = currentPtr;
                currentPtr = currentPtr->leftPtr;
                while (currentPtr->rightPtr != NULL) {
                    prevousPtr = currentPtr;
                    currentPtr = currentPtr->rightPtr;
                }

                printf("currentPtr->data = %d\n", currentPtr->data );
                printf("prevousPtr->data = %d\n", prevousPtr->data );
                printf("delTmpPtr->data = %d\n", delTmpPtr->data );
                printf("delParrentPtr->data = %d\n", delParrentPtr->data );

                delParrentPtr->rightPtr = currentPtr;
                currentPtr->rightPtr = delTmpPtr->rightPtr;

                if (currentPtr->leftPtr != NULL) {
                    prevousPtr->rightPtr = currentPtr->leftPtr;
                }
                else {
                    prevousPtr->rightPtr = NULL;
                }

                //currentPtr->rightPtr = delTmpPtr->rightPtr;


                free(delTmpPtr);
                return;
            }

            free(currentPtr);
            return;
        }

        else if (currentPtr->data > value) {
            prevousPtr = currentPtr;
            currentPtr = currentPtr->leftPtr;
        }

        else if(currentPtr->data < value) {
            prevousPtr = currentPtr;
            currentPtr = currentPtr->rightPtr;
        }

    }

    printf("Node with value %d not found\n", value);
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



