#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 11
#define MAX_STRINGNUM_SIZE 100

const char* parseChar(const char*);
const char* getStrDecimalDegree(unsigned long int);
const char* getStrDoubleDegree(unsigned long int);

int main(void)
{
    char num[MAX_NUM_SIZE] = "100121";
    puts("Enter number:");
    //gets(num);
    printf("You enter - %s\n", num);
    puts("Result:");
    puts(parseChar(num));

    return 0;
}



const char * getStrDoubleDegree(unsigned long int num)
{
    static char str[MAX_STRINGNUM_SIZE];
    unsigned long int quotient = 1;
    switch (num) {
        case 0:
            return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 20:
            return "twenty";

        default:
            //return strcat(getStrDoubleDegree((num / 10) * 10), getStrDoubleDegree(num - (num / 10) * 10));
            for (unsigned long int sizeNum = num; sizeNum != 0; sizeNum /= 10)
                quotient *= 10;
            while (quotient > 10) {
                quotient /= 10;
                printf("s %lu\n", quotient);
                printf("num %lu\n", num);
                if (quotient >= 100) {
                    if (getStrDecimalDegree(quotient) == "-1") {
                        quotient /= 10;
                        printf("getStrDecimalDegree %lu\n", quotient);
                        unsigned long int partNum = num / quotient;
                        strcat_s(str, getStrDoubleDegree(partNum));
                        //gеt hundred thousand millon billion
                        strcat_s(str, " ");
                        puts(str);
                        strcat_s(str, getStrDecimalDegree(quotient));
                        strcat_s(str, " ");
                        puts(str);
                        printf("getStrDecimalDegree quotient %lu\n", quotient);
                        printf("getStrDecimalDegree num %lu\n", num);
      
                        num = num - (quotient * partNum);
                        printf("getStrDecimalDegree num -= quotient %lu\n", num);
                    }
                    else {
                        //get one two for hundred thousand millon billion
                        unsigned long int bigPart = num / quotient;
                        printf("bigPart %lu\n", bigPart);
                        strcat_s(str, getStrDoubleDegree(bigPart));
                        //gеt hundred thousand millon billion
                        strcat_s(str, " ");
                        strcat_s(str, getStrDecimalDegree(quotient));
                        strcat_s(str, " ");
                        num -= quotient;
                    }
                }
                else {
                    strcat_s(str, getStrDoubleDegree((num / quotient) * quotient));
                    strcat_s(str, " ");
                }
            }
            strcat_s(str, getStrDoubleDegree(num - (num / quotient) * quotient)); 
            return str;
        }
}

const char* getStrDecimalDegree(unsigned long int num)
{
    switch (num) {
        case 100:
            return "hundred";
        case 1000:
            return "thousand";
        case 1000000:
            return "million";
        case 1000000000:
            return "billion";
        default:
            printf("Error in getStrDecimalDegree %d\n", num);
            return "-1";
    }
}

const char* parseChar(const char * strPtr)
{
    unsigned long int num;
    char* pointPtr = strchr((char *)strPtr, '.');
    size_t sizeNum = strlen(strPtr);
    if (pointPtr == NULL) {
        num = atol(strPtr);
        return getStrDoubleDegree(num);
    }
}

