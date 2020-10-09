#include<stdio.h>
#include<string.h>
#define DELIMITERS_COUNT 2
#define WORD_SIZE 100

int getWordCount(const char[], const char[]);

int main(void) {
    int wordCountFirstStr = 0;
    char delimiters[DELIMITERS_COUNT] = { '.',',' }; //delimiter char size = 1
    char strFirstText[WORD_SIZE];
    char strSecondText[WORD_SIZE];

    puts("Enter string wiht delimiters:");
    for (int i = 0; i < DELIMITERS_COUNT; i++)
        printf("%d) %c ", i + 1, delimiters[i]);

    puts("\n\nEnter first string:");
    gets_s(strFirstText);
    puts("Enter second string:");
    gets_s(strSecondText);

    wordCountFirstStr += getWordCount(strFirstText, delimiters);
    wordCountFirstStr += getWordCount(strSecondText, delimiters);

    puts("\nResult:");
    printf("Word count = %d in string wiht delimiters:", wordCountFirstStr);
    for (int i = 0; i < DELIMITERS_COUNT; i++) 
        printf(" %d = %c", i + 1, delimiters[i]);

    puts("");
    return 0;
}

int getWordCount(const char str[], const char delimeters[]) {
    int wordCount = 0;
    char* tokenPtr;
    char* nextTokenPtr;
    char copyStr[WORD_SIZE];
    char delimeterStr[2];

    for (int i = 0; i < DELIMITERS_COUNT; i++) {
        nextTokenPtr = NULL;
        tokenPtr = NULL;
        strcpy_s(copyStr, WORD_SIZE, str);

        if (strchr(copyStr, delimeters[i]) == NULL)
            continue;

        delimeterStr[0] = delimeters[i];
        delimeterStr[1] = '\0';

        tokenPtr = strtok_s(copyStr, delimeterStr, &nextTokenPtr);
        while (tokenPtr != NULL) {
            ++wordCount;
            tokenPtr = strtok_s(NULL, delimeterStr, &nextTokenPtr);
        }
    }
    return wordCount;
}