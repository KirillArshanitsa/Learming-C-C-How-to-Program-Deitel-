#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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
    char expression[MAX_SIZE_EXPRESSION +1];// = "62+5*84/-";

    puts("Enter data:");
    gets_s(expression, MAX_SIZE_EXPRESSION);
    printf("Result = %d\n",evaluatePostfixExpression(expression));
    return 0;
}

int evaluatePostfixExpression(char *expr)
{
    StackNodePtr stackNodePtr = NULL;
    int x, y;
    for(size_t i = 0; expr[i] != '\0'; i++){
       //if(expr[i] - '0' == expr[i] - 48)
       if (isdigit(expr[i]))
            push(&stackNodePtr, expr[i] - 48);
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