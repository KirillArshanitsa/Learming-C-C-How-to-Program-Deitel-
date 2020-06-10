#include <stdio.h>

int even(int);
int even(int num){
    return num % 2 > 0 ? 0 : 1;
}

int main(void) {
    int a,b,c;
    puts("Enter 3 numbers");
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", even(a));
    printf("%d\n", even(b));
    printf("%d\n", even(c));
    return 0;
}