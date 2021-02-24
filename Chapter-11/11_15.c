#include <stdio.h>
#define SIZE 80
#define FILE_SIZE 40

void stdioRun(void);
int fileIoRun(void);

int main(void)
{
    int choise = 0;
    while (1) {
        puts("Enter:\n1 for choise stdin/stdout\n2 for use file io:");
        scanf_s("%d", &choise);
        if (choise == 1) {
            stdioRun();
            break;
        }
        else if (choise == 2) {
            return fileIoRun();
        }
        else {
            printf("You enter %d, need only 1 or 2\n", choise);
        }
    }

    return 0;

}

int fileIoRun(void) 
{
    int c;
    char sentence[SIZE];
    char fileName[FILE_SIZE];
    int i = 0;
    FILE *fPtr;

    //for cath in main func \n
    fgetc(stdin);

    puts("Enter filename:");
    gets_s(fileName);

    fopen_s(&fPtr, fileName, "w");
    if (fPtr == NULL) {
        printf("Error open file %s", fileName);
        return -1;
    }

    puts("Enter a line of text for write:");
    while ((i < SIZE - 1) && (c = fgetc(stdin)) != '\n') {
        sentence[i++] = c;
    }
    sentence[i] = '\0';
    fputs(sentence, fPtr);
    fclose(fPtr);

    printf("\nReader data from file %s:\n", fileName);
    fopen_s(&fPtr, fileName, "r");
    i = 0;
    while ((i < SIZE - 1) && (c = fgetc(fPtr)) != '\n') {
        sentence[i++] = c;
    }
    fclose(fPtr);
    sentence[i] = '\0';
    fputs(sentence, stdout);

    return 0;
}

void stdioRun(void)
{
    int c; 
    char sentence[SIZE]; 
    int i = 0; 
    
    //for cath in main func \n
    fgetc(stdin);

    puts("Enter a line of text:");              
    while ((i < SIZE - 1) && (c = fgetc(stdin)) != '\n') {
        sentence[i++] = c;
    }
    sentence[i] = '\0'; 

    puts("\nThe line entered was:");
    fputs(sentence, stdout);
}