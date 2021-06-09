#include<stdio.h>
#include<stdarg.h>

void product(int, ...);


int main() {
    product(1, 1);
    product(3, 1, 2, 3);
    product(5,1,2,3,4,5);
    return 0;
}

void product(int i,...)
{
    int result = 0;
    va_list ap;
    va_start(ap, i);
    for(int count = 1;count <= i;count++)
        result += va_arg(ap, int);
    va_end(ap);
    printf("Result is %d\n", result);
}