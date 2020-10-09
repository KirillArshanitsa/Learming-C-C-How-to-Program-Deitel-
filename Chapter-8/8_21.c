#include <stdio.h>
#include <string.h>
#define SIZE 5

void boubleSort(char* []);
void printStr(char* const[]);

int main(void){
    char* strPtr[SIZE] ={"MSK","SPB","Barcelone","London","MSK"};
    puts("Before sort");
    printStr(strPtr);
    boubleSort(strPtr);
    puts("After sort");
    printStr(strPtr);
    return 0;
}

void printStr(char* const strPtr[]){
    for (int e = 0; e < SIZE;e++)
        printf("%s ", strPtr[e]);
    puts("");
}

void boubleSort(char* strPrt[]){
    char* tmpStrPtr;
    for (int e = 0; e < SIZE ;e++){
        for(int i = e + 1; i < SIZE; i++){
            if (strcmp(strPrt[e],strPrt[i]) > 0 ){
                tmpStrPtr = strPrt[e];
                strPrt[e] = strPrt[i];
                strPrt[i] = tmpStrPtr;
            }
        }
    }
}