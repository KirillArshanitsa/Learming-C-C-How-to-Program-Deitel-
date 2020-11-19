#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char * parseChar(char *);
char * getStr(long int, size_t);
char * getStrDecimalDegree(unsigned char);
char * getStrDoubleDegree(long int);

int main(void)
{
    //char num[SIZE];
    puts("Enter number:");
    //gets(num);
    //printf("You enter - %s\n", num);
    puts("Result:");
    puts(parseChar("21"));

    return 0;
}



char *getStrDoubleDegree(long int num)
{
    switch (num) {
        case 0:
            return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";

        case 20:
            return "twenty";

        default:
            return strcat(getStrDoubleDegree((num / 10) * 10), getStrDoubleDegree(num - (num / 10) * 10));
    }
}

char *getStrDecimalDegree(unsigned char num)
{
    switch (num) {
        case 2:
            return "hundred";
        case 3:
            return "thousand";
        case 6:
            return "million";
        case 9:
            return "billion";
        default:
            printf("Error in getStrDecimalDegree %d\n", num);
            return "Error";

    }
}

char * parseChar(char *strPtr)
{
    long int num;
    char *pointPtr =  strchr(strPtr, '.');
    size_t sizeNum= strlen(strPtr);
    if (pointPtr == NULL){
        num = atol(strPtr);
        return getStr(num, sizeNum - 1);
    }
}

char * getStr(long int num, size_t charNumCount)
{
    if(charNumCount > 2)
        ;
    else{
        return getStrDoubleDegree(num);
    }

}