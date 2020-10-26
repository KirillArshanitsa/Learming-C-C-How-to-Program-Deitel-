#include <string.h>
#include <stdio.h>

int myStrcmp(const char*, const char*);
int myStrncmp(const char*, const char*, size_t);
int myStrcmpPtr(const char*, const char*);
int myStrncmpPtr(const char*, const char*, size_t);

int main(void){
    printf("Result - %d\n", myStrcmp("String1","String"));
    printf("Result - %d\n", strcmp("String1","String"));
    printf("Result - %d\n", myStrcmpPtr("String","String"));
    printf("Result - %d\n", myStrncmp("STring","String", 3));
    printf("Result - %d\n", myStrncmpPtr("String","String", 1));
    return 0;
}

int myStrncmpPtr(const char *str1, const char *str2, size_t n)
{
    if(n <= 0){
        printf("You enter number for compare count - %zu\n", n);
        return -1;
    }
    size_t sizeStr1 = strlen(str1);
    size_t sizeStr2 = strlen(str2);
    if ((sizeStr1 >= n) && (sizeStr2 >= n))
    {
        for (; n > 0; str1++,str2++, n--) {
            if (*str1 > *str2)
                return 1;
            else if (*str1 < *str2)
                return -1;
        }
        return 0;
    }
    else if(n > sizeStr2)
    {
        printf("Second string size = %zu, less than compare size = %zu\n", sizeStr2, n);
        return -1;
    }
    else if(n > sizeStr1) {
        printf("First string size = %zu, less than compare size = %zu\n", sizeStr1, n);
        return -1;
    }
}

int myStrncmp(const char *str1, const char *str2, size_t n)
{
    if(n <= 0){
        printf("You enter number for compare count - %zu\n", n);
        return -1;
    }

    size_t sizeStr1 = strlen(str1);
    size_t sizeStr2 = strlen(str2);
    if ((sizeStr1 >= n) && (sizeStr2 >= n))
    {
        for (int e = 0; e != n; e++) {
            if (str1[e] > str2[e])
                return 1;
            else if (str1[e] < str2[e])
                return -1;
        }
        return 0;
    }
    else if(n > sizeStr2)
    {
        printf("Second string size = %zu, less than compare size = %zu\n", sizeStr2, n);
        return -1;
    }
    else if(n > sizeStr1) {
        printf("First string size = %zu, less than compare size = %zu\n", sizeStr1, n);
        return -1;
    }
}

int myStrcmpPtr(const char *str1, const char *str2)
{
    size_t sizeStr1 = strlen(str1);
    size_t sizeStr2 = strlen(str2);
    if (sizeStr1 == sizeStr2)
    {
        for (; *str1 != '\0'; str1++,str2++) {
            if (*str1 > *str2)
                return 1;
            else if (*str1 < *str2)
                return -1;
        }
        return 0;
    }
    else if(sizeStr1 > sizeStr2)
        return 1;
    else
        return -1;
}

int myStrcmp(const char *str1, const char *str2)
{
    size_t sizeStr1 = strlen(str1);
    size_t sizeStr2 = strlen(str2);
    if (sizeStr1 == sizeStr2)
    {
        for (int e = 0; str1[e] != '\0'; e++) {
            if (str1[e] > str2[e])
                return 1;
            else if (str1[e] < str2[e])
                return -1;
        }
        return 0;
    }
    else if(sizeStr1 > sizeStr2)
        return 1;
    else
        return -1;
}