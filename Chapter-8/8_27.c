#include<stdio.h>
//#include<stdlib.h>
#include<string.h>

double atof(const char*);
unsigned int charToInt(const char);
int atoi(const char*);
long int atol(const char*);
double strtod(const char*, char **);

int main(void) {
    char* strPtr;
    //printf("%f\n", atof("-1234.123"));
    //printf("%d\n", atoi("1230123"));
    //printf("%ld\n", atol("-1000000010"));
    printf("%f %p %s\n", strtod("52.1% are ammitted.", &strPtr), strPtr, strPtr);
    return 0;
}

double strtod(const char* nPtr, char** strPtr){
    int beginStrPtr;
    
    for (int i = 0; nPtr[i] != '\0'; i++) {
        if (nPtr[i] == '.') {
            if (nPtr[i + 1] != '\0') {
                strPtr = &nPtr[i + 1];
            }
        }
    }
 }

long int atol(const char* nPtr) {
    long int result = 0;
    long int strSize = strlen(nPtr) - 1;
    if (nPtr[0] == '-') {
        for (long int intPart = 1; strSize >= 1; strSize--, intPart *= 10) {
            result += intPart * charToInt(nPtr[strSize]);
        }
    }
    else {
        for (long int intPart = 1; strSize >= 0; strSize--, intPart *= 10) {
            result += intPart * charToInt(nPtr[strSize]);
        }
    }
    return result;
}

int atoi(const char* nPtr) {
    int result = 0;
    int strSize = strlen(nPtr) - 1;
    if (nPtr[0] == '-') {
        for (int intPart = 1; strSize >= 1; strSize--, intPart *= 10) {
            result += intPart * charToInt(nPtr[strSize]);
        }
    }
    else {
        for ( int intPart = 1; strSize >= 0; strSize--, intPart *= 10) {
            result += intPart * charToInt(nPtr[strSize]);
        }
    }
    return result;
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