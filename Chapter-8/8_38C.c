#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 11
#define MAX_STRINGNUM_SIZE 1000

const char* parseChar(const char*);
const char* getStrDecimalDegree(unsigned int);
const char* getStrDoubleDegree(unsigned long int);
unsigned int getNumSize(unsigned long int);
unsigned long int parseNum(unsigned long int, char*);

int main(void)
{
    char num[MAX_NUM_SIZE] = "9500600761";
    puts("Enter number:");
    //gets(num);
    printf("You enter - %s\n", num);
    puts("Result:");
    puts(parseChar(num));

    return 0;
}

unsigned int getNumSize(unsigned long int num) {
    unsigned long int sizeNum;
    for (sizeNum = 0; num != 0; sizeNum++) {
        num /= 10;
    }
    return sizeNum;
}


const char* getStrDoubleDegree(unsigned long int num)
{
    static char strNum[MAX_STRINGNUM_SIZE];
    switch (num) {
        //case 0:
        //    return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        case 20:
            return "twenty";
        case 30:
            return "thirty";
        case 40:
            return "forty";
        case 50:
            return "fifty";
        case 60:
            return "sixty";
        case 70:
            return "seventy";
        case 80:
            return "eighty";
        case 90:
            return "ninety";
        default:
            printf("Error in num %lu\n", num);
            printf("strNum - %s\n", strNum);
            //TODO change it
            size_t strNumSize = strlen(strNum);
            for (size_t a = 0; a < strNumSize; a++)
                strNum[a] = 0;

            strcat(strNum, getStrDoubleDegree((num / 10) * 10));
            strcat(strNum, " ");
            strcat(strNum, getStrDoubleDegree(num - (num / 10) * 10));
            printf("strNum - %s\n", strNum);

            return strNum;
    }
}


const char* getStrDecimalDegree(unsigned int num)
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


unsigned long int parseNum(unsigned long int num, char* resultPtr) {
    unsigned long int divider;
    unsigned long int partOFNum;
    unsigned long int remainderDivision = 0;

    // TODO change it to list
    if (num / 1000000000 > 0) {
        divider = 1000000000;
    }
    else if (num / 1000000 > 0) {
        divider = 1000000;
    }
    else if (num / 1000 > 0) {
        divider = 1000;
    }
    else if (num / 100 > 0) {
        divider = 100;
    }
    else {
        divider = 1;
    }

    partOFNum = num / divider;

    printf("divider - %u\n", divider);
    printf("partOFNum - %lu\n", partOFNum);

    if (partOFNum < 100) {
        strcat(resultPtr, getStrDoubleDegree(partOFNum));
        strcat(resultPtr, " ");
        strcat(resultPtr, getStrDecimalDegree(divider));
        strcat(resultPtr, " ");
        return num - partOFNum * divider;
    }
    else if ((partOFNum >= 100) & (divider >= 100)) {

        remainderDivision = parseNum(partOFNum, resultPtr);

        printf("remainderDivision - %lu\n", remainderDivision);

        if (remainderDivision) {
            strcat(resultPtr, getStrDoubleDegree(remainderDivision));
        }
        strcat(resultPtr, " ");
        strcat(resultPtr, getStrDecimalDegree(divider));
        strcat(resultPtr, " ");
        return num - partOFNum * divider;
    }
    else {
        parseNum(num - partOFNum * divider, resultPtr);
    }


}


const char* parseChar(const char* strPtr)
{
    unsigned long int num;
    static char result[MAX_STRINGNUM_SIZE];
    unsigned int sizeNum;
    char* remainderPtr;
    char* pointPtr = strchr((char*)strPtr, '.');

    if (pointPtr == NULL) {
        num = strtoul(strPtr, &remainderPtr, 0);

        printf("Num - %ul\n", num);

        while (num != 0) {
            sizeNum = getNumSize(num);
            if (sizeNum > 2) {
                num = parseNum(num, result);
            }
            else {
                strcat(result, getStrDoubleDegree(num));
                num = 0;
            }
        }
    }
    else {
        char* nextTokenPtr = NULL;
        char* numericPartPtr;
        char divisorPart[MAX_STRINGNUM_SIZE - 1];
        unsigned int divisor = 1;

        parseChar(strtok((char*)strPtr, "." ));
        strcat(result, " and ");
        numericPartPtr = strtok(NULL, ".");
        for (size_t size = strlen(numericPartPtr); size != 0; size--)
            divisor *= 10;
        strcat(result, numericPartPtr);
        strcat(result, "/");
        sprintf(divisorPart, "%u", divisor);
        strcat(result, divisorPart);
    }

    return result;
}

