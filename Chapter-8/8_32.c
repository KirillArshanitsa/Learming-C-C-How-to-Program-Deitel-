#include<stdio.h>
void *myMemcpy(void *, const void *, size_t);
void *myMemmove(void *, const void *, size_t);
void *myMemcmp(void *, const void *, size_t);
void *myMemchr(const void *, int , size_t);
void *myMemset(const void *, int , size_t);

int main(void){
//    char str[] ="Home Sweet Home";
//    char result[10];
//    myMemcpy(result, str, 4);
//    puts(result);
//
//    puts(myMemmove(str,&str[5],10));
//    printf("%d\n",myMemcmp("ABCDEFG","ABCDXYZ",7));
//    printf("%s\n",myMemchr("This is a string.",'r',16));
    printf("%s\n",myMemset("BBBBBBBBBBB",'b',5));
    return 0;
}

//TODO Not work in 28 string
void *myMemset(const void *s1, int c, size_t n) {
    unsigned int uc = (unsigned int) c;
    char *tmpPtr;
    void *beginStrPtr = (void*) s1;
    while(n-- > 0){
        tmpPtr = (char *)s1;
        *tmpPtr = uc;
        s1++;
    }

    return beginStrPtr;
}

void *myMemchr(const void *s1, int c, size_t n){
    unsigned int uc = (unsigned int) c;
    for (;n-- > 0; s1++){
        if( *(char *)s1 == uc)
            return s1;
    }
    return NULL;
}

//For demand in book return void * and int
void *myMemcmp(void *s1, const void *s2, size_t n){
    while(n-- > 0) {
        if(*(char *) s1 < *(char *) s2)
            return 1;
        else if(*(char *) s1 > *(char *) s2)
            return -1;
        ++s1;
        ++s2;
    }
    return 0;
}

void *myMemmove(void *s1, const void *s2, size_t n){
    char tmpStr[n];
    void *beginStr = s1;
    for (size_t i = 0; i < n ;i++, s2++)
        tmpStr[i] = * (char*)s2;

    for (size_t i = 0; i < n ;i++, s1++)
        *(char *) s1 = tmpStr[i];

    return beginStr;
}

void *myMemcpy(void *s1, const void *s2, size_t n){
    while(n-- > 0){
        *(char *)s1 = *(char * )s2;
        s2++;
        s1++;
    }
    *(char *)(++s1) = '\0';
    return s1;
}