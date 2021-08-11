#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//#include <string.h>
//#include<math.h>
#include "structs.h"



void printStack(StackNodePtr);
int isEmpty(StackNodePtr);
char stackTop(StackNodePtr);
char pop(StackNodePtr*);
void push(StackNodePtr*, char);
int isOperator(char);
int precendence(char, char);
void convertToPostFix(char[], char[]);

int isEmpty2(StackNodeIntPtr);
void push2(StackNodeIntPtr*, int);
void calculate(int, int, char);
int evaluatePostfixExpression(char*);
int pop2(StackNodeIntPtr*);


extern unsigned int counterSymbolTable;
extern int strIsDigit(const char[]);
extern TableEntry* symbolTable[];
extern int getLocationInTableEntry(TableEntry* const [], int, unsigned int, char);
extern unsigned int instrCounter;
extern unsigned int dataCounter;
extern unsigned int sizeOfCodeSML;
extern int codeSML[TABLE_ENTRY_COUNT];


void convertToPostFix(char infix[], char postfix[])
{
    StackNodePtr stackNodePtr = NULL;
    char currentOperator = NULL;
    size_t infixSize;
    size_t postfixSize = 0;

    push(&stackNodePtr, '(');
    for (infixSize = 0; infix[infixSize] != '\0'; infixSize++)
        ;

    infix[infixSize] = ')';
    infix[infixSize + 1] = '\0';
    infixSize = 0;

    while (!isEmpty(stackNodePtr) && (infix[infixSize] != '\0')) {
        //while (!isEmpty(stackNodePtr)){
        if (isdigit(infix[infixSize]) || isalpha(infix[infixSize])) {
            postfix[postfixSize] = infix[infixSize];
            postfixSize++;
        }
        if (infix[infixSize] == '(') {
            push(&stackNodePtr, '(');
        }
        if (isOperator(infix[infixSize])) {
            currentOperator = infix[infixSize];
            while ( isOperator(stackTop(stackNodePtr)) && (precendence(stackTop(stackNodePtr), currentOperator) >= 0) ) {
                postfix[postfixSize] = pop(&stackNodePtr);
                postfixSize++;
            }
            push(&stackNodePtr, currentOperator);
        }

        if (infix[infixSize] == ')') {
            while ( isOperator(stackTop(stackNodePtr)) ) {
                postfix[postfixSize] = pop(&stackNodePtr);
                postfixSize++;
                if (stackTop(stackNodePtr) == ')') {
                    pop(&stackNodePtr);
                    break;
                }
            }

        }
        ++infixSize;
    }
    postfix[postfixSize] = '\0';
}

int precendence(char operator1, char operator2)
{
    if ( ((operator1 == '+') || (operator1 == '-')) && ((operator2 == '+') || (operator2 == '-')) )
        return 0;
    else if (((operator1 == '+') || (operator1 == '-')) && ((operator2 != '+') && (operator2 != '-')))
        return -1;
    else if (((operator1 != '+') && (operator1 != '-')) && ((operator2 == '+') || (operator2 == '-')))
        return 1;
    else if(((operator1 != '+') && (operator1 != '-')) && ((operator2 != '+') || (operator2 != '-')))
        return 0;
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

char pop(StackNodePtr *topPtr)
{
    char returnChar = NULL;
    StackNodePtr tmpPtr = NULL;
    if (*topPtr == NULL) {
        puts("Stack is empty.");
        return returnChar;
    }
    else {
        returnChar = (*topPtr)->data;
        tmpPtr = *topPtr;
        *topPtr = (*topPtr)->dataPtr;
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


int evaluatePostfixExpression(char* expr)
{
    StackNodeIntPtr stackNodePtr = NULL;
    int x, y, locationInTableEntry;
    char strNum[CODE_STR_SIZE];

    for (size_t i = 0, strSize = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])){
            strNum[strSize] = expr[i];
            strSize++;
            while(isdigit(expr[i + 1])){
                strNum[strSize] = expr[i + 1];
                i++;
                strSize++;
            }
            strNum[strSize+ 1 ] = '\0';
            locationInTableEntry = getLocationInTableEntry(symbolTable, atoi(strNum), counterSymbolTable, 'C');
            push2(&stackNodePtr, locationInTableEntry);
            strNum[0] = '\0';
            strSize = 0;
        }
        else if(isalnum(expr[i])){
            locationInTableEntry = getLocationInTableEntry(symbolTable, expr[i] ,counterSymbolTable, 'V');
            push2(&stackNodePtr, locationInTableEntry);
        }
        else {
            x = pop2(&stackNodePtr);
            y = pop2(&stackNodePtr);
            calculate(x, y, expr[i]);
            //push(&stackNodePtr, calculate(x, y, next_token[0]));
        }

    }
    return pop2(&stackNodePtr);
}

void calculate(int op1, int op2, char operatorChar)
{
    if (operatorChar == '/') {
        if (op1 >= op2)
            //return op1 / op2;
            ;
        else
            //return op2 / op1;
            ;
    }
    else if (operatorChar == '-') {
        if (op1 >= op2)
            //return op1 - op2;
            ;
        else
            //return op2 - op1;
            ;
    }
    else if (operatorChar == '*')
        //return op1 * op2;
        ;
    else if (operatorChar == '+'){
        codeSML[sizeOfCodeSML] = 2000 + op2;
        sizeOfCodeSML++;
        instrCounter++;
        codeSML[sizeOfCodeSML] = 3000 + op1;
        sizeOfCodeSML++;
        instrCounter++;

        codeSML[sizeOfCodeSML] = 2100 + dataCounter;
        instrCounter++;
        sizeOfCodeSML++;

        codeSML[sizeOfCodeSML] = 2000 + dataCounter;
        instrCounter++;
        sizeOfCodeSML++;

        dataCounter--;

        codeSML[sizeOfCodeSML] = 2100 + op2;
        instrCounter++;
        sizeOfCodeSML++;
    }

    else if (operatorChar == '%')
        ;
        //return op1 % op2;
    else if (operatorChar == '^')
        ;
        //return pow(op1, op2);
    else
        printf("Error operation %c\n", operatorChar);
}

int pop2(StackNodeIntPtr* topPtr)
{
    StackNodeIntPtr tmpPtr = NULL;
    int returnedVal;
    if (*topPtr == NULL) {
        //puts("Stack is empty.");
        return -1;
    }
    tmpPtr = *topPtr;
    returnedVal = tmpPtr->data;
    *topPtr = (*topPtr)->StackNodeIntPtr;
    free(tmpPtr);
    return returnedVal;
}



void push2(StackNodeIntPtr* topPtr, int value)
{
    StackNodeIntPtr tmpPtr;
    if ((*topPtr) == NULL) {
        tmpPtr = (StackNodeIntPtr)malloc(sizeof(StackNode));
        tmpPtr->data = value;
        tmpPtr->StackNodeIntPtr = NULL;
        *topPtr = tmpPtr;
    }
    else {
        tmpPtr = (StackNodeIntPtr)malloc(sizeof(StackNode));
        tmpPtr->data = value;
        tmpPtr->StackNodeIntPtr = (*topPtr);
        *topPtr = tmpPtr;

    }
}

int isEmpty2(StackNodeIntPtr topPtr)
{
    if (topPtr == NULL)
        return 1;
    else
        return 0;
}
