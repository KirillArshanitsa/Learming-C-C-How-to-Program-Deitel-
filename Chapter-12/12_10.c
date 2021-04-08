#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 100

struct stackNode 
{
	char symbol;
	stackNode* stackNodePtr;
};

typedef stackNode StackNode;
typedef StackNode *StackNodePtr;

void getStr(char[]);
void push(StackNodePtr*, char);
void pop(StackNodePtr*);
void printStack(StackNodePtr);
void revertStr(const char[], StackNodePtr*);

int main(void) 
{
	StackNodePtr stackNodePtr = NULL;
	char str[MAX_WORD_SIZE];

	getStr(str);
	puts("Run revert:");
	revertStr(str, &stackNodePtr);
	printStack(stackNodePtr);

	return 0;
}

void revertStr(const char str[], StackNodePtr *stackNodePtr)
{
	for (int i = 0; str[i] != '\0'; i++) {
		push(stackNodePtr, str[i]);
	}
}

void printStack(StackNodePtr stackNodePtr) 
{
	while (stackNodePtr != NULL) {
		printf("%c", stackNodePtr->symbol);
		stackNodePtr = stackNodePtr->stackNodePtr;
	}
}

void pop(StackNodePtr *stackNodePtr)
{
	StackNodePtr tmpPtr;
	if (*stackNodePtr != NULL) {
		tmpPtr = *stackNodePtr;
		*stackNodePtr = (*stackNodePtr)->stackNodePtr;
		free(tmpPtr);
	}
	else {
		puts("Stack is empty.");
	}
}

void push(StackNodePtr *stackNodePtr, char symbol)
{
	StackNodePtr nextNode = NULL;
	if ((nextNode = (StackNodePtr)malloc(sizeof(StackNode))) != NULL) {
		nextNode->symbol = symbol;
		nextNode->stackNodePtr = *stackNodePtr;
		*stackNodePtr = nextNode;
	}
	else {
		printf("Error create node %c\n", symbol);
		return;
	}

}


void getStr(char str[]) {
	printf("Enter string, max size %d\n", MAX_WORD_SIZE);
	gets_s(str, MAX_WORD_SIZE -1);
}