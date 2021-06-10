#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME_SIZE 25

void getFileNames(const char[], const char[]);
void copyFileRevert(FILE*, FILE*);

int main()
{
    char srcFileName[MAX_FILE_NAME_SIZE + 1];
    char copyFileName[MAX_FILE_NAME_SIZE + 1];
    FILE *srcFilePtr = NULL;
    FILE *copyFilePtr = NULL;

    getFileNames(srcFileName, copyFileName);

    if((srcFilePtr = fopen(srcFileName, "r")) != NULL){
        if((copyFilePtr = fopen(copyFileName, "w")) != NULL){
            copyFileRevert(srcFilePtr, copyFilePtr);
            fclose(srcFilePtr);
            fclose(copyFilePtr);
        }
        else{
            printf("Error open file %s\n", copyFilePtr);
            exit(EXIT_FAILURE);
        }
    }
    else{
        printf("Error open file %s\n", srcFileName);
        exit(EXIT_FAILURE);
    }

    return 0;
}

void copyFileRevert(FILE *srcFileName, FILE *copyFileName)
{
    if (feof(srcFileName))
        return;
    else {
        char tmpChar = NULL;
        fscanf(srcFileName, "%c", &tmpChar);
        copyFileRevert(srcFileName, copyFileName);
        if (tmpChar != NULL)
            fprintf(copyFileName,"%c",tmpChar);

    }
}

void getFileNames(const char srcFileName[], const char copyFileName[])
{
    int enterdVal = 0;
    do{
        puts("Enter source file and copy fli name:");
        enterdVal = scanf("%s %s", srcFileName, copyFileName);
    }
    while(enterdVal != 2);
}