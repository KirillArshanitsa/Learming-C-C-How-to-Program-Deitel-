#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define STRING_SIZE 151

struct nodeStack
{
	char symbol;
	nodeStack* nodeStackPtr;
};

typedef nodeStack NodeStack;
typedef NodeStack *NodeStackPtr;

void getStr(char[]);
void push(NodeStackPtr*, char);
char pop(NodeStackPtr*);
int strIsPalindrome(const char[], NodeStackPtr*);
void printStack(NodeStackPtr);


int main(void)
{
	char str[STRING_SIZE];
	NodeStackPtr nodeStackPtr = NULL;
	printf("Enter sting. Max size - %d\n", STRING_SIZE - 1); //I did, did I? | red rum, sir, is murder
	gets_s(str, STRING_SIZE -1);

	if (strIsPalindrome(str, &nodeStackPtr))
		puts("String is palindrome.");
	else
		puts("String is not palindrome.");

	return 0;
}


void printStack(NodeStackPtr nodeStackPtr) 
{	
	puts("Print Stack:");
	while (nodeStackPtr != NULL) {
		printf("%c", nodeStackPtr->symbol);
		nodeStackPtr = nodeStackPtr->nodeStackPtr;
	}
	puts("");
}

char pop(NodeStackPtr *nodeStackPtr)
{
	char deletedChar = NULL;
	NodeStackPtr tmpPtr;
	if ((*nodeStackPtr) == NULL){
		puts("Stack is empty");
		return NULL;
	}
	else {
		tmpPtr = *nodeStackPtr;
		deletedChar = tmpPtr->symbol;
		*nodeStackPtr = (*nodeStackPtr)->nodeStackPtr;
		free(tmpPtr);
		return deletedChar;
	}

}

void push(NodeStackPtr *nodeStackPtr, char symbol)
{
	NodeStackPtr tmpPtr;
	NodeStackPtr nextPtr = (NodeStackPtr) malloc(sizeof(NodeStack));
	if (nextPtr != NULL){
		nextPtr->symbol = symbol;
		nextPtr->nodeStackPtr = NULL;

		if ((*nodeStackPtr) == NULL)
			*nodeStackPtr = nextPtr;
		else {
			tmpPtr = *nodeStackPtr;
			*nodeStackPtr = nextPtr;
			nextPtr->nodeStackPtr = tmpPtr;
		}
	}
	else {
		printf("Error create node for char %c\n", symbol);
	}

}


int strIsPalindrome(const char str[], NodeStackPtr *nodeStackPtr)
{
	size_t copyStrSize = 0;
	char copyStr[STRING_SIZE];

	for (size_t i = 0; str[i] != '\0'; i++) {
		if (isspace(str[i]) || ispunct(str[i]))
			continue;
		copyStr[copyStrSize] = str[i];
		push(nodeStackPtr, copyStr[copyStrSize]);
		copyStrSize++;
	}
	copyStr[copyStrSize] = '\0';
	puts(copyStr);
	printStack(*nodeStackPtr);

	for (size_t i = 0; copyStr[i] != '\0'; i++){
		if (copyStr[i] != pop(nodeStackPtr))
			return 0;
	}

	return 1;
}

