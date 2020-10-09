#include <stdio.h>
#include <string.h>
#define STR_COUNT 2
#define STR_SIZE 50

void enterStr(char* []);
void printStr(char* const[]);

int main(void){
    char* strPtr[STR_COUNT];
    enterStr(strPtr);
    printStr(strPtr);
    return 0;
}

void enterStr(char* strPtr[]){
    printf("Enter %d %s:\n", STR_COUNT, STR_COUNT > 1?"strings":"string" );
    for(int i = 0; i < STR_COUNT; i++){
        printf("Enter string №%d:\n", i + 1);
        char tmpStr[STR_SIZE];
        gets(tmpStr);
        strPtr[i] = tmpStr;
        printf("%d\n",strlen(strPtr[i]));
        printf("%p\n", &strPtr[i]);
        printf("%p\n", &strPtr[i][strlen(strPtr[i])]);
    }
}

void printStr(char* const strPtr[]){
    puts("Result:");
    for(int i = 0; i < STR_COUNT; i++) {
        printf("%p\n", &strPtr[i]);
        printf("%d\n",strlen(strPtr[i]));
        printf("%s\n",strPtr[i]);
//        if (strPtr[i][0] == 'b')
//            puts(strPtr[i]);
    }
}