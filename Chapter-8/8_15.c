#include <stdio.h>
#include <string.h>
void revertPrint( char*);

int main(void){
    char str [100];
    puts("Enter f few words with space:");
    gets(str);
    revertPrint(str);
    return 0;
}

void revertPrint( char* strPtr){
    static int i;
    char * partStrPtr;
    if (i)
        partStrPtr = strtok(NULL, " ");
    else
        partStrPtr = strtok(strPtr, " ");
    ++i;
    if(partStrPtr == NULL)
        return;
    revertPrint(strPtr);
    puts(partStrPtr);
}