#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_STR_SIZE 101 //100

struct stackNode
{
    char data;
    struct stackNode*dataPtr;
};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr;

void printStack(StackNodePtr);
int isEmpty(StackNodePtr);
char stackTop(StackNodePtr);
char pop(StackNodePtr);
void push(StackNodePtr*, char);
int isOperator(char);
int precendence(char, char);
void convertToPostFix(char[], char[]);

int main(void)
{
    char infix[MAX_STR_SIZE] = "3+4";//"(6 + 2) * 5 - 8 / 4";//{'3','+','4','\0'};
    char postfix[MAX_STR_SIZE] = { 0 };
    printf("Enter operators, max size = %d\n", MAX_STR_SIZE - 1);
    //gets_s(infix, MAX_STR_SIZE - 1);

    convertToPostFix(infix, postfix);
    puts("Result of convert:");
    puts(postfix);

    return 0;
}

void convertToPostFix(char infix[], char postfix[])
{
    StackNodePtr stackNodePtr = NULL;
    char currentOperator = NULL;
    size_t infixSize;
    size_t postfixSize = 0;
    int tmp = 0;

    push(&stackNodePtr, '(');
    for (infixSize = 0; infix[infixSize] != '\0'; infixSize++)
        printf("%c", infix[infixSize]);

    printf("\n infixSize = %zu\n", infixSize);
    infix[infixSize] = ')';
    infix[infixSize + 1] = '\0';
    puts(infix);
    puts("Gop");
    printf("postfixSize = %zu\n", postfixSize);

    while (!isEmpty(stackNodePtr) && (infix[postfixSize] != '\0')) {
        printf("%d, infix[postfixSize] = %c, postfixSize= %zu\n", tmp, infix[postfixSize], postfixSize);
        if (isdigit(infix[postfixSize])) {
            puts("Insert isdigit");
            postfix[postfixSize] = infix[postfixSize];
            printf("postfix[postfixSize] = %c\n", postfix[postfixSize]);
        }
        if (infix[postfixSize] == '(') {
            puts("Insert (");
            printf("Insert postfix[postfixSize] = %c\n", postfix[postfixSize]);
            push(&stackNodePtr, '(');
        }
        if (isOperator(infix[postfixSize])) {
            currentOperator = infix[postfixSize];
            printf("is operator %d\n", isOperator(stackTop(stackNodePtr)));
            while ( isOperator(stackTop(stackNodePtr)) && (precendence(currentOperator, stackTop(stackNodePtr)) >= 0) ) {
                postfix[postfixSize] = pop(stackNodePtr);
                postfixSize++;
            }
            push(&stackNodePtr, currentOperator);
        }

        if (infix[postfixSize] == ')') {
            printf("stackTop(stackNodePtr) %c\n", stackTop(stackNodePtr));
            //printf("is operator %d\n", isOperator(stackTop(stackNodePtr)));

            if (isOperator(stackTop(stackNodePtr))) {
                while (stackTop(stackNodePtr) == '(') {
                    postfix[postfixSize] = pop(stackNodePtr);
                }
            }
            printf("pop %c\n", pop(stackNodePtr));
        }
        ++postfixSize;

        ++tmp;

    }

    puts("add 0");
    postfix[postfixSize + 1] = '\0';
}

int precendence(char operator1, char operator2)
{
    if ( ((operator1 == '+') || (operator1 == '-')) && ((operator2 == '+') || (operator2 == '-')) )
        return 0;
    else if (((operator1 == '+') || (operator1 == '-')) && ((operator2 != '+') && (operator2 != '-')))
        return -1;
    else if (((operator1 != '+') && (operator1 != '-')) && ((operator2 == '+') || (operator2 == '-')))
        return 1;
    else {
        printf("Error in parse operator1 = %c  operator2 = %c\n", operator1, operator2);
        return -2;
    }
}


int isOperator(char c)
{
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^') || (c == '%'))
        return 1;
    else
        return 0;
}

void push(StackNodePtr *topPtr, char value)
{
    StackNodePtr nextPtr = (StackNodePtr) malloc(sizeof(StackNode));
    if (nextPtr != NULL) {
        nextPtr->data = value;
        if ((*topPtr) == NULL)
            nextPtr->dataPtr = NULL;
        else
            nextPtr->dataPtr = *topPtr;
        *topPtr = nextPtr;
    }
    else {
        printf("Error create node witch char %c\n", value);
    }
}

char pop(StackNodePtr topPtr)
{
    char returnChar = NULL;
    if (topPtr == NULL) {
        puts("Stack is empty.");
        return returnChar;
    }
    else {
        returnChar = topPtr->data;
        StackNodePtr tmpPtr = topPtr;
        topPtr = topPtr->dataPtr;
        free(tmpPtr);
        return returnChar;
    }
}


char stackTop(StackNodePtr topPtr)
{
    if (topPtr == NULL)
        return NULL;
    else
        return topPtr->data;
}

int isEmpty(StackNodePtr topPtr)
{
    if (topPtr == NULL)
        return 1;
    else
        return 0;
}

void printStack(StackNodePtr topPtr)
{
    while (topPtr != NULL) {
        printf("%c", topPtr->data);
        topPtr = topPtr->dataPtr;
    }
}