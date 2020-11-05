#include<stdio.h>

void* myMemcpy(void*, const void*, size_t);
void* myMemmove(void*, const void*, size_t);
void* myMemcmp(void*, const void*, size_t);
void* myMemchr(const void*, int, size_t);
void* myMemset(const void*, int, size_t);

int main(void) {
    char str[] ="Home Sweet Home";
    char myMemcmpStr[] = "ABCDYFG";
    char result[10];
    myMemcpy(result, str, 4);
    puts(result);
    printf_s("%s\n", myMemmove(str, &str[5], 10));
    printf_s("%d\n",myMemcmp(myMemcmpStr,"ABCDXYZ",6));
    printf_s("%s\n",myMemchr("This is a string.",'r',16));
    char b [15] = "BBBBBBBBBBB";
    printf_s("%s\n", myMemset(b, 'b', 5));

    return 0;
}

void* myMemset(const void* s1, int c, size_t n) {
    unsigned int uc = (unsigned int)c;
    char* tmpPtr = (char*)s1;
    void* beginStrPtr = (void*)s1;
  
    while (n-- > 0) {
        *tmpPtr = uc;
        tmpPtr++;
    }

    return beginStrPtr;
}

void* myMemchr(const void* s1, int c, size_t n) {
    unsigned int uc = (unsigned int)c;
    char *tmpChar = (char*)s1;
    for (; n-- > 0; tmpChar++) {
        if (*(char*)tmpChar == uc)
            return tmpChar;
    }
    return NULL;
}

//For demand in book return void * and int
void* myMemcmp(void* s1, const void* s2, size_t n) {
    char* tmpChar1 = (char*)s1;
    char* tmpChar2 = (char*)s2;
    while (n-- > 0) {
        if (*tmpChar1 < *tmpChar2)
            return (void *) 1;
        else if (*tmpChar1 > * tmpChar2)
            return (void*) -1;
        ++tmpChar1;
        ++tmpChar2;
    }
    return 0;
}

void* myMemmove(void* s1, const void* s2, size_t n) {
    char* tmpChar1 = (char*)s1;
    char* tmpChar2 = (char*)s2;
    //TODO chage it char tmpStr[n + 1]
    char tmpStr[100000];

    void* beginStr = s1;
    for (size_t i = 0; i < n; i++, tmpChar2++)
        tmpStr[i] = *tmpChar2;

    for (size_t i = 0; i < n; i++, tmpChar1++)
        *tmpChar1 = tmpStr[i];

    return beginStr;
}

void* myMemcpy(void* s1, const void* s2, size_t n) {
    char* tmpChar1 = (char*)s1;
    char* tmpChar2 = (char*)s2;
    while (n-- > 0) {
        *tmpChar1 = *tmpChar2;
        ++tmpChar1;
        ++tmpChar2;
    }
    *tmpChar1 = '\0';
    return s1;
}