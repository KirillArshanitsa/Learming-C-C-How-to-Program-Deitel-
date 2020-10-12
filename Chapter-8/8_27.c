#include<stdio.h>
#include<string.h>

double atof(const char*);
unsigned int charToInt(const char);

int main(void) {
    printf("%f\n", atof("-1234.123"));
    return 0;
}
unsigned int charToInt(const char s) {
    for (int ch = 48, i = 0; i <= 9; ch++, i++) {
        if (s == ch)
            return i;
    }
    return -1;
}

double atof(const char* nPtr) {
    double result = 0;
    unsigned int strSize = strlen(nPtr);
    unsigned int doublePartPtr = strcspn(nPtr, ".") + 1; // +1 or -1 for .
    int intPartPtr = strcspn(nPtr, ".") - 1;

    for (double doublePart = 0.1; doublePartPtr < strSize; ++doublePartPtr, doublePart *= 0.1) {
        //printf("%f %c %f\n",doublePart, nPtr[intPartPtr], doublePart * charToInt(nPtr[intPartPtr]));
        result += doublePart * charToInt(nPtr[doublePartPtr]);
    }
    if (nPtr[0] != '-') {
        for (double intPart = 1; intPartPtr >= 0; intPartPtr--, intPart *= 10) {
            //printf("%d %c %f\n",intPartPtr, nPtr[intPartPtr], result += intPart * charToInt(nPtr[intPartPtr]));
            result += intPart * charToInt(nPtr[intPartPtr]);
        }
    }
    else {
        for (double intPart = 1; intPartPtr >= 1; intPartPtr--, intPart *= 10) {
            //printf("%d %c %f\n",intPartPtr, nPtr[intPartPtr], result += intPart * charToInt(nPtr[intPartPtr]));
            result += intPart * charToInt(nPtr[intPartPtr]);
        }
        result *= -1;
    }

    return result;
}