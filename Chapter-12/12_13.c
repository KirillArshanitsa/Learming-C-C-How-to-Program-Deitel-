#include <stdio.h>
#include <stdlib.h>

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
    char expression[MAX_SIZE_EXPRESSION +1] = "62+5*84/-";
    printf("Result = %d",evaluatePostfixExpression(expression));
    return 0;
}

int evaluatePostfixExpression(char *expr)
{
    StackNodePtr stackNodePtr = NULL;
    int x, y, result;
    for(size_t i = 0; expr[i] != '\0'; i++){
        printf("expr[i] = %c\n", expr[i]);
        printf("%d\n", expr[i]);
        if(expr[i] - '0' == expr[i])
            push(&stackNodePtr, expr[i]);
        else{
            x = pop(&stackNodePtr);
            y = pop(&stackNodePtr);
            if (expr[i] == '/'){
                if (x >= y)
                    result = x / y;
                else
                    result = y / x;
            }
            else if (expr[i] == '-'){
                if (x >= y)
                    result = x - y;
                else
                    result = y - x;
            }
            else if(expr[i] == '*')
                result = x * y;
            else if(expr[i] == '+')
                result = x + y;
            else if(expr[i] == '%')
                result = x % y;
            else if(expr[i] == '^')
                result = x ^ y;
            else
                printf("Error operation %c\n", expr[i]);

            push(&stackNodePtr, result);
        }
        return pop(&stackNodePtr);
    }
}

int calculate(int op1, int op2, char operator)
{

}

void push(StackNodePtr *topPtr, int value)
{
    StackNodePtr tmpPtr;
    if((*topPtr) == NULL){
        tmpPtr = malloc(sizeof(StackNode));
        tmpPtr->data = value;
        tmpPtr->stackNodePtr = NULL;
        *topPtr = tmpPtr;
    }
    else{
        tmpPtr = malloc(sizeof(StackNode));
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