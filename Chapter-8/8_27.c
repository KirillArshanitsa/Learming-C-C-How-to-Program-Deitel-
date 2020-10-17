#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
#include<ctype.h>

double atof(const char*);
unsigned int charToInt(const char);
int atoi(const char*);
long int atol(const char*);
double strtod(const char*, const char **);
long strtol(const char *, char **, int);
int checkStrIsDigit(const char*);

int main(void) {
    const char *strPtr = NULL;

    printf("%f\n", atof("-1234.123"));
    printf("%d\n", atoi("1230123"));
    printf("%ld\n", atol("-1000000010"));
    printf("%f %s\n", strtod("12.1234 are ammitted.", &strPtr), strPtr);

    return 0;
}


long strtol(const char* nPtr, char** endPtr, int base) {
    return 0;
}

int checkStrIsDigit(const char *strPtr) {
    for (size_t i = 0; strPtr[i] != '\0'; i++)
        if (isdigit(strPtr[i] == 0)) {
            printf("It's not a digigits - %s\n", strPtr);
            return 0;
        }
    return 1;
}

double strtod(const char* nPtr, const char** endPtr) {
    double result = NULL;
    char strPart = NULL;
    
    sscanf_s(nPtr, "%lf%c", &result, &strPart);
    if (strPart != NULL)
        *endPtr = strchr(nPtr, strPart); 

    return result;
}


long int atol(const char* nPtr) {
    long int result = 0;
    size_t strSize = strlen(nPtr) - 1;
    if (strSize == 0)
        printf("You enter empty string.\n");

    if (checkStrIsDigit(nPtr)) {
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
    }

    return result;
}
int atoi(const char* nPtr) {
    int result = 0;
    size_t strSize = strlen(nPtr) - 1;
    if (strSize == 0)
        printf("You enter empty string.\n");
    
    if (checkStrIsDigit(nPtr)) {
        if (nPtr[0] == '-') {
            for (int intPart = 1; strSize >= 1; strSize--, intPart *= 10) {
                result += intPart * charToInt(nPtr[strSize]);
            }
        }
        else {
            for (int intPart = 1; strSize != 0; strSize--, intPart *= 10) {
                result += intPart * charToInt(nPtr[strSize]);
            }
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
    size_t strSize = strlen(nPtr);

    if (strSize == 0)
        printf("You enter empty string.\n");

    size_t doublePartPtr = strcspn(nPtr, ".") + 1; // +1 or -1 for .
    size_t intPartPtr = strcspn(nPtr, ".") - 1;

    for (double doublePart = 0.1; doublePartPtr < strSize; ++doublePartPtr, doublePart *= 0.1) {
        //printf("%f %c %f\n",doublePart, nPtr[intPartPtr], doublePart * charToInt(nPtr[intPartPtr]));
        result += doublePart * charToInt(nPtr[doublePartPtr]);
    }
    if (nPtr[0] != '-') {
        for (double intPart = 1; intPartPtr != 0; intPartPtr--, intPart *= 10) {
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