#include<stdio.h>
#include<string.h>

double atof(const char*);
int charToInt(const char);

int main(void){
    printf("%f\n", atof("1234.123"));
    return 0;
}
int charToInt(const char s){
    for(int ch = 48, i = 0; i <= 9 ;ch++, i++){
        if (s == ch)
            return i;
    }
    return -1;
}

double atof(const char *nPtr){
    double result = 0;
    unsigned int strSize = strlen(nPtr);
    unsigned int doublePartPtr = strcspn(nPtr, ".") + 1; // +1 or -1 for .
    unsigned int intPartPtr = strcspn(nPtr, ".") - 1;
    printf("%u\n",intPartPtr);
    for(double doublePart = 0.1; doublePartPtr < strSize ;++doublePartPtr,  doublePart *= 0.1){
        //printf("%f %c %f\n",doublePart, nPtr[intPartPtr], doublePart * charToInt(nPtr[intPartPtr]));
        result += doublePart * charToInt(nPtr[doublePartPtr]);
    }
    printf("%f\n",result );
    for (int intPart = 1 ; intPartPtr >= 0; intPartPtr--, intPart *= 10){
        //printf("%u %c %f\n",intPartPtr, nPtr[intPartPtr], result + intPart * charToInt(nPtr[intPartPtr]));
        result += intPart * charToInt(nPtr[intPartPtr]);
    }

    return result;
}