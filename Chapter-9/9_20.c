#include <stdio.h>

int main(void){
    double num = 9876.12345f;
    for (int i = 1 ; i < 10 ; i++)
        printf("%.*g\n",i, num);
}