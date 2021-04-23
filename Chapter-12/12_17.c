#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 100

struct treeNode {
    struct treeNode* leftPtr;
    char str[MAX_STR_SIZE];
    struct treeNode* rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;

void insertNode(TreeNodePtr*, const char[]);
void inOrder(TreeNodePtr);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);

int main(void)
{
    char str[MAX_STR_SIZE + 1];
    char* next_token = NULL;
    TreeNodePtr treeNodePtr = NULL;
    printf("Enter string, max size = %d\n", MAX_STR_SIZE);

    gets_s(str, MAX_STR_SIZE);

    char* tokenPtr = strtok_s(str, " ", &next_token);
    while (tokenPtr != NULL) {
        insertNode(&treeNodePtr, tokenPtr);
        tokenPtr = strtok_s(NULL, " ", &next_token);
    }

    puts("Print result inOrder:");
    inOrder(treeNodePtr);
    puts("Print result postOrder:");
    postOrder(treeNodePtr);
    puts("Print result preOrder:");
    preOrder(treeNodePtr);
    
    return 0;
}

void postOrder(TreeNodePtr treeNodePtr)
{
    if (treeNodePtr != NULL){
        postOrder(treeNodePtr->leftPtr);
        postOrder(treeNodePtr->rightPtr);
        puts(treeNodePtr->str);
    }
}

void preOrder(TreeNodePtr treeNodePtr)
{
    if (treeNodePtr != NULL){
        puts(treeNodePtr->str);
        preOrder(treeNodePtr->leftPtr);
        preOrder(treeNodePtr->rightPtr);
    }
}

void inOrder(TreeNodePtr treeNodePtr)
{
    if (treeNodePtr != NULL){
        inOrder(treeNodePtr->leftPtr);
        puts(treeNodePtr->str);
        inOrder(treeNodePtr->rightPtr);
    }
}

void insertNode(TreeNodePtr *treeNodePtr, const char str[])
{
    TreeNodePtr tmpTreeNodePtr = NULL;
    if (*treeNodePtr == NULL) {
        tmpTreeNodePtr = (TreeNodePtr)malloc(sizeof(TreeNode));
        if (tmpTreeNodePtr != NULL) {
            tmpTreeNodePtr->leftPtr = NULL;
            strcpy_s(tmpTreeNodePtr->str, str);
            tmpTreeNodePtr->rightPtr = NULL;
            *treeNodePtr = tmpTreeNodePtr;
        }
        else
            printf("Error create node for str %s\n", str);
    }
    else {
        if (strcmp((*treeNodePtr)->str, str) < 0) {
            insertNode(&((*treeNodePtr)->rightPtr), str);
        }
        else if (strcmp((*treeNodePtr)->str, str) > 0)
            insertNode(&((*treeNodePtr)->leftPtr), str);
        else {
            printf("Duplicate %s\n", str);
        }
    }
}