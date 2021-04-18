#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE_EXPRESSION 100

struct stackNode{
    int data;
    struct stackNode *stackNodePtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void printStack(StackNodePtr);
int isEmpty(StackNodePtr);
int pop(StackNodePtr*);
void push(StackNodePtr*, int);
int calculate(int, int, char);
int evaluatePostfixExpression(char *);

int main(void)
{
    char expression[MAX_SIZE_EXPRESSION +1] = "6 2 + 5 * 8 4 / -";

    //puts("Enter data:");
    //gets(expression);
    printf("Result = %d\n",evaluatePostfixExpression(expression));
    return 0;
}

int evaluatePostfixExpression(char *expr)
{
    StackNodePtr stackNodePtr = NULL;
    char tmpNumStr[MAX_SIZE_EXPRESSION];
    int x, y, tmpNum;
    for(size_t i = 0, e; expr[i] != '\0'; i++){
       if (isdigit(expr[i])){
           for (e = i; expr[e + 1] != '\0' && isdigit(expr[e + 1]); e++)
               ;
           if (e > i){
               tmpNum = 0;
               for(size_t tmpChar = i ;tmpChar <= e;tmpChar++, tmpNum++){
                   tmpNumStr[tmpNum] = expr[tmpChar];
               }
               tmpNumStr[e + 1] = '\0';
               printf("\ntmpNumStr = %s\n", tmpNumStr);
               tmpNum = atoi(tmpNumStr);
               if(tmpNum != 0){
                   push(&stackNodePtr, tmpNum);
               }
               else{
                   printf("Error transfer str to int %s\n", tmpNumStr);
                   return 0;
               }
           }
           else
               push(&stackNodePtr, expr[i] - 48);
       }
       else if(expr[i] == ' '){
           continue;
       }
       else{
            x = pop(&stackNodePtr);
            y = pop(&stackNodePtr);
            calculate(x, y, expr[i] );
            push(&stackNodePtr, calculate(x, y, expr[i]));
       }

    }
    return pop(&stackNodePtr);
}

int calculate(int op1, int op2, char operatorChar)
{
    if (operatorChar == '/'){
        if (op1 >= op2)
            return op1 / op2;
        else
            return op2 / op1;
    }
    else if (operatorChar == '-'){
        if (op1 >= op2)
            return op1 - op2;
        else
            return op2 - op1;
    }
    else if(operatorChar == '*')
        return op1 * op2;
    else if(operatorChar == '+')
        return op1 + op2;
    else if(operatorChar == '%')
        return op1 % op2;
    else if(operatorChar == '^')
        return pow(op1,op2);
    else
        printf("Error operation %c\n", operatorChar);
}

void push(StackNodePtr *topPtr, int value)
{
    StackNodePtr tmpPtr;
    if((*topPtr) == NULL){
        tmpPtr = (StackNodePtr) malloc(sizeof(StackNode));
        tmpPtr->data = value;
        tmpPtr->stackNodePtr = NULL;
        *topPtr = tmpPtr;
    }
    else{
        tmpPtr = (StackNodePtr) malloc(sizeof(StackNode));
        tmpPtr->data = value;
        tmpPtr->stackNodePtr = (*topPtr);
        *topPtr = tmpPtr;

    }
}

int pop(StackNodePtr *topPtr)
{
    StackNodePtr tmpPtr = NULL;
    int returnedVal;
    if (*topPtr == NULL){
        puts("Stack is empty.");
        return -1;
    }
    tmpPtr = *topPtr;
    returnedVal = tmpPtr->data;
    *topPtr = (*topPtr)->stackNodePtr;
    free(tmpPtr);
    return returnedVal;
}

int isEmpty(StackNodePtr topPtr)
{
    if(topPtr == NULL)
        return 1;
    else
        return 0;
}

void printStack(StackNodePtr topPtr)
{
    while(topPtr != NULL) {
        printf("%d", topPtr->data);
        topPtr = topPtr->stackNodePtr;
    }
}