#include <stdio.h>
#include <string.h>

#define NUM_STR_MAX_SIZE 100

int main(void)
{

    double num = 100.453627;

    long fractionSize;
    unsigned int e = 0;
    char strNum[NUM_STR_MAX_SIZE];
    sprintf(strNum,"%f", num);
    fractionSize = strlen(strNum) - strlen(strtok(strNum,".")) - 1;
    while(fractionSize-- > 0){
        printf("%.*f\n", e,num);
        ++e;
    }
}