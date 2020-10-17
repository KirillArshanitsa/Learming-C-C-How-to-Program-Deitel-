#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

double atof(const char*);
unsigned int charToInt(const char);
int atoi(const char*);
long int atol(const char*);
double strtod(const char*, const char **);
long strtol(const char *, const char **, int);
int checkStrIsDigit(const char*);
long numeralTranslation(const char*, const int scaleOfNotation);

int main(void) {
    const char *strPtr = NULL;
    const char* strStrtolPtr = NULL;

    printf("%f\n", atof("-1234.123"));
    printf("%d\n", atoi("1230123"));
    printf("%ld\n", atol("-1000000010"));
    printf("%f %s\n", strtod("12.1234 are ammitted.", &strPtr), strPtr);

    printf("%ld %s\n", strtol(" f5 _are ammitted.", &strStrtolPtr, 16), strStrtolPtr);

    return 0;
}

long numeralTranslation(const char* nPtr, const int scaleOfNotation) {
    //TODO add check for scaleOfNotation 
    long result = 0;
    size_t strSize = strlen(nPtr);

    if (strSize == 0) {
        printf("You enter empty string.\n");
        return -1;
    }
    --strSize;
    if ((scaleOfNotation < 0) && (scaleOfNotation > 36)) {
        printf("Enter base 0-36, you enter %d\n", scaleOfNotation);
        return -1;
    }

    for (size_t elemInStr = 0; nPtr[elemInStr] != '\0' ; elemInStr++) {
        if ((nPtr[elemInStr] >= 48) && (nPtr[elemInStr] <= 57)) {
            for (int i = 48, e = 0; i <= 57; i++, e++) {
                if (nPtr[elemInStr] == i) {
                    result += e * pow(scaleOfNotation, strSize--);
                    break;
                }
            }
        }
        else if ((nPtr[elemInStr] >= 65) && (nPtr[elemInStr] <= 90)) {
            for (int i = 65, e = 10; i <= 90; i++, e++) {
                if (nPtr[elemInStr] == i) {
                    result += e * pow(scaleOfNotation, strSize--);
                    break;
                }
            }
        }
        else if ((nPtr[elemInStr] >= 97) && (nPtr[elemInStr] <= 122)) {
            for (int i = 97, e = 10; i <= 122; i++, e++) {
                if (nPtr[elemInStr] == i) {
                    result += e * pow(scaleOfNotation, strSize--);
                    break;
                }
            }
        }
        else {
            printf("Error translate char %c num %d in str %s.", nPtr[elemInStr], elemInStr, nPtr);
            return -1;
        }
        
    }
    return result;
}

long strtol(const char* nPtr, const char** endPtr, int base) {
    long result;
    char longStr[20] = {};//20 - max num count in long
    int isNegative = 0;
    int checkSpace = 0;
    size_t i = 0;

    size_t strSize = strlen(nPtr);
    if (strSize == 0) {
        printf("You enter empty string.\n");
        return -1;
    }
    if ((base < 0) && (base > 36)) {
        printf("Enter base 0-36, you enter %d\n", base);
        return -1;
    }

    if (base < 11) {
        for (; nPtr[i] != '\0'; i++) {
            if (i > 20) {
                printf("Error - max num count in long. %s", nPtr);
                return -1;
            }
            //check space in string after find num
            if (checkSpace) {
                if (nPtr[i] == ' ')
                    break;
            }
            if (isdigit(nPtr[i])) {
                longStr[i] = nPtr[i];
                checkSpace = 1;
            }
        }
    }
    else {
        for (size_t e = 0; nPtr[i] != '\0'; i++) {
            if (i > 20) {
                printf("Error - max num count in long. %s", nPtr);
                return -1;
            }
            //check space in string after find num
            if (checkSpace) {
                if (nPtr[i] == ' ')
                    break;
            }
            if (isdigit(nPtr[i])) {
                longStr[e++] = nPtr[i];
                checkSpace = 1;
            }
            else if (isalpha(nPtr[i])) {
                for (int charNUm = 65, scaleOfNotation = 36 - base; scaleOfNotation <= 25; charNUm++, scaleOfNotation++) { // 25 = 36 - 11 from A to Z 
                    if ((nPtr[i] == charNUm) || (nPtr[i] == charNUm + 32)) {
                        longStr[e++] = nPtr[i];
                        checkSpace = 1;
                    }
                }
            }
        }
    }
    longStr[i + 1] = '\0';

    result = numeralTranslation(longStr, base);
    if (nPtr[strcspn(nPtr, longStr) - 1] == '-')
        result *= -1;
    return result;
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
    size_t strSize = strlen(nPtr);
    if (strSize == 0)
        printf("You enter empty string.\n");

    --strSize;//for use in []
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
    size_t strSize = strlen(nPtr);
    if (strSize == 0)
        printf("You enter empty string.\n");
    --strSize;//for use in []

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