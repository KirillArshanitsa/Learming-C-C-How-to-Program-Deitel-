#include<stdio.h>

void insertSpaceInFile(const char[]);

int main(){
    char sourceFile[] ="source.txt";
    insertSpaceInFile(sourceFile);
    return 0;
}

void insertSpaceInFile(const char sourceFileName[])
{
    char tempFile[] ="tmpFile.txt";
    char tmpChar;
    char space = ' ';

    int sizeOfChar = sizeof(char);
    FILE *srcFilePtr;
    FILE *tmpFilePtr;

    if((srcFilePtr = fopen(sourceFileName, "rb+")) == NULL){
        printf("Error open file %s\n", sourceFileName);
        return;
    }
    else{
        if((tmpFilePtr = fopen(tempFile, "wb+")) != NULL){
            while(!feof(srcFilePtr)) {
                fread(&tmpChar, sizeOfChar, 1, srcFilePtr);
                fwrite(&tmpChar, sizeOfChar, 1,tmpFilePtr);
                fwrite(&space, sizeOfChar, 1,tmpFilePtr);
            }
            rewind(srcFilePtr);
            rewind(tmpFilePtr);
            while(!feof(tmpFilePtr)) {
                fread(&tmpChar, sizeOfChar, 1, tmpFilePtr);
                fwrite(&tmpChar, sizeOfChar, 1,srcFilePtr);
            }
            fclose(srcFilePtr);
            fclose(tmpFilePtr);

        }
        else{
            puts("Error open temp file.");
            return;
        }
    }
}