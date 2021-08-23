#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "toPostfix.cpp"

//TODO Bug in compiler - load type C in Simpletron memory
#include "simpletron.cpp"
extern int memory[];

void readSrcFile(const char[]);
void parseCodeStr(char[], size_t, char[]);
void printSMLCode(const int[], unsigned int);
void printSymbolTable(TableEntry*[], unsigned int);
int getLocationInTableEntry(TableEntry* const [], int, unsigned int, char);
void printFlags(int[]);
int strIsDigit(const char[]);
void insertInSymbolTable(char, int);
void fixEmptyLink(void);
void saveSmlCodeToFile(void);


unsigned int instrCounter;
unsigned int dataCounter = TABLE_ENTRY_COUNT - 1;
TableEntry* symbolTable[TABLE_ENTRY_COUNT];
int codeSML[TABLE_ENTRY_COUNT];
unsigned int sizeOfCodeSML;
unsigned int counterSymbolTable;
int flags[TABLE_ENTRY_COUNT];



int main(void)
{
    for(unsigned int i = 0 ; i < TABLE_ENTRY_COUNT ;i++)
        flags[i] = -1;

    char fileName[SRC_FILE_NAME_SIZE] = "Simple.txt";
    //First compiler pass
    readSrcFile(fileName);

/*    printSMLCode(codeSML, sizeOfCodeSML);
    puts("");
    printSymbolTable(symbolTable, counterSymbolTable);
    puts("");
    printFlags(flags);
    puts("");
    puts("Print finish code");*/

    //Second compiler pass
    fixEmptyLink();
    printSMLCode(codeSML, sizeOfCodeSML);
    saveSmlCodeToFile();


    puts("Run SML:");
    runCommands(memory, loadCommands(memory));
    return 0;
}


void saveSmlCodeToFile(void)
{
    FILE *cfPtr;
    errno_t err;


    err = fopen_s(&cfPtr, SML_CODE_FILE_NAME, "w");
    if( err == 0 ){
        for(int i = 0; i < sizeOfCodeSML;i++)
            fprintf(cfPtr,"%+d\n", codeSML[i]);
        fclose(cfPtr);
    }
    else{
        printf( "The file '%s' was not opened\n", SML_CODE_FILE_NAME);
    }
}

void fixEmptyLink(void)
{
    for(int i = 0; i < TABLE_ENTRY_COUNT; i++){
        if(flags[i] != -1){
            codeSML[i] = codeSML[i] + getLocationInTableEntry(symbolTable, flags[i], counterSymbolTable, 'L');
        }
    }
}

void insertInSymbolTable(char type, int symbol){
    symbolTable[counterSymbolTable] = (TableEntry*) malloc(sizeof(TableEntry));
    symbolTable[counterSymbolTable]->symbol = symbol;
    symbolTable[counterSymbolTable]->type = type;
    if(type == 'L')
        symbolTable[counterSymbolTable]->location = instrCounter;
    else{
        symbolTable[counterSymbolTable]->location = dataCounter;
        //TODO Bug in compiler - load type C in Simpletron memory
        if(type == 'C')
            memory[dataCounter] = symbol;
    }
    counterSymbolTable++;
}



int strIsDigit(const char string[]){
    for (int i = 0;string[i] != '\0' ;i++){
        if(isalpha(string[i]))
            return 0;
    }
    return 1;
}

void printFlags(int flags[])
{
    puts("Print flags:");
    for(unsigned int i = 0 ; i != TABLE_ENTRY_COUNT;i++)
        printf("%02d  %d\n",i, flags[i]);
}

int getLocationInTableEntry(TableEntry* const[], int symbol, unsigned int size, char type)
{
    for (unsigned int i = 0; i != size; i++){
        if(symbolTable[i]->type == type){
            if (symbolTable[i]->symbol == symbol)
                return symbolTable[i]->location;
        }
    }
    return 0;
}

void printSymbolTable(TableEntry* symbolTable[], unsigned int size)
{
    puts("Print symbolTable:");
    for (unsigned int i = 0; i != size; i++){
        if(symbolTable[i]->type =='V'){
            printf("'%-c' %c  %02d\n", symbolTable[i]->symbol, symbolTable[i]->type, symbolTable[i]->location);
        }
        else {
            printf("%-2d  %c  %02d\n", symbolTable[i]->symbol, symbolTable[i]->type, symbolTable[i]->location);
        }
    }
}

void printSMLCode(const int codeSML[], unsigned int sizeOfCodeSML)
{
    puts("Print SML code:");
    for (unsigned int i = 0 ; i != sizeOfCodeSML; i++)
        printf("%02d  %+d\n",i, codeSML[i]);
}


void parseCodeStr(char codeStr[], size_t strNum, char originalCodeStr[])
{
    char *next_token = NULL;
    char *tokenPtr;
    char copyCodeInLet[CODE_STR_SIZE];
    char postfix[CODE_STR_SIZE];
    int arraySize = 0;
    char arrayStrSize[20];

    tokenPtr = strtok_s(codeStr, " ", &next_token);
    if(strIsDigit(tokenPtr))
        insertInSymbolTable('L', atoi(tokenPtr));
    else{
        printf("Error parse - %s\nIn %u string %s. First word is not a digit.\n", tokenPtr, strNum, originalCodeStr);
        exit(EXIT_FAILURE);
    }

    insertInSymbolTable('L', atoi(tokenPtr));

    tokenPtr = strtok_s(NULL, " ", &next_token);
    while (tokenPtr != NULL){
        if(strcmp(tokenPtr, "rem") == 0)
            break;
        else if(strcmp(tokenPtr, "input") == 0){
            tokenPtr = strtok_s(NULL, " ", &next_token);
            while (tokenPtr != NULL){
                if (strrchr(tokenPtr, ',') != NULL)
                    tokenPtr[strlen(tokenPtr) - 1] = '\0' ;
                if(getLocationInTableEntry(symbolTable, tokenPtr[0] ,counterSymbolTable, 'V') == 0){
                    insertInSymbolTable('V',  tokenPtr[0]);
                    codeSML[sizeOfCodeSML] = 1000 + dataCounter;
                    sizeOfCodeSML++;
                    dataCounter--;
                    instrCounter++;
                }
                tokenPtr = strtok_s(NULL, " ", &next_token);
            }
            break;
        }
        else if(strcmp(tokenPtr, "if") == 0){
            tokenPtr = strtok_s(NULL, " ", &next_token);
            while(tokenPtr != NULL){
                //Var in if
                if (getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V') == 0) {
                    insertInSymbolTable('V',  tokenPtr[0]);
                    dataCounter--;
                }
                //chek condition in if
                tokenPtr = strtok_s(NULL, " ", &next_token);
                if(strcmp(tokenPtr, "==") == 0){
                    codeSML[sizeOfCodeSML] = 2000 + dataCounter + 1;
                    sizeOfCodeSML++;
                    instrCounter++;
                    //check second var in if
                    tokenPtr = strtok_s(NULL, " ", &next_token);
                    if (getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V') == 0) {
                        insertInSymbolTable('V',  tokenPtr[0]);
                        dataCounter--;
                    }
                    codeSML[sizeOfCodeSML] = 3100 + getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V');
                    sizeOfCodeSML++;
                    instrCounter++;
                    // goto ***
                    tokenPtr = strtok_s(NULL, " ", &next_token);
                    tokenPtr = strtok_s(NULL, " ", &next_token);

                    if (getLocationInTableEntry(symbolTable, atoi(tokenPtr), counterSymbolTable, 'L'))
                        ;
                    else{
                        flags[sizeOfCodeSML] = atoi(tokenPtr);
                        codeSML[sizeOfCodeSML] = 4200;
                        sizeOfCodeSML++;
                        instrCounter++;
                    }
                }
                else{
                    printf("Error parse - %s\nIn %u string - %s\n", tokenPtr, strNum, originalCodeStr);
                    exit(EXIT_FAILURE);;
                }
                tokenPtr = strtok_s(NULL, " ", &next_token);
            }
        }

        else if(strcmp(tokenPtr, "let") == 0){
            tokenPtr = strtok_s(NULL, " ", &next_token);
            if (getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V') == 0) {
                insertInSymbolTable('V',  tokenPtr[0]);
                dataCounter--;
            }
            // ==
            tokenPtr = strtok_s(NULL, " ", &next_token);
            //copy math express
            strcpy(copyCodeInLet, next_token);

            tokenPtr = strtok_s(NULL, " ", &next_token);
            while (tokenPtr != NULL){
                if(strIsDigit(tokenPtr)){
                    if (getLocationInTableEntry(symbolTable, atoi(tokenPtr), counterSymbolTable, 'C') == 0) {
                        insertInSymbolTable('C',  atoi(tokenPtr));
                        dataCounter--;
                    }
                }
                else{
                    if (getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V') == 0) {
                        insertInSymbolTable('V',  tokenPtr[0]);
                        dataCounter--;
                    }
                }
                tokenPtr = strtok_s(NULL, " ", &next_token);
                tokenPtr = strtok_s(NULL, " ", &next_token);
            }
            //convert to postfix
            convertToPostFix(copyCodeInLet, postfix);
            evaluatePostfixExpression(postfix);

        }
        else if(strcmp(tokenPtr, "print") == 0){
            //get var for print
            tokenPtr = strtok_s(NULL, " ", &next_token);
            while(tokenPtr != NULL){
                if (strrchr(tokenPtr, ',') != NULL)
                    tokenPtr[strlen(tokenPtr) - 1] = '\0' ;

                if(getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V'))
                    codeSML[sizeOfCodeSML] = 1100 + getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V');
                else
                    codeSML[sizeOfCodeSML] = 1100 + getLocationInTableEntry(symbolTable, atoi(tokenPtr), counterSymbolTable, 'C');
                sizeOfCodeSML++;
                instrCounter++;
                tokenPtr = strtok_s(NULL, " ", &next_token);
            }


        }
        else if(strcmp(tokenPtr, "goto") == 0){
            //get cell for goto
            tokenPtr = strtok_s(NULL, " ", &next_token);
            codeSML[sizeOfCodeSML]  = 4000 + getLocationInTableEntry(symbolTable, atoi(tokenPtr), counterSymbolTable, 'L');
            sizeOfCodeSML++;
            instrCounter++;
            tokenPtr = strtok_s(NULL, " ", &next_token);
        }
        else if(strcmp(tokenPtr, "end") == 0){
            //99 to end
            codeSML[sizeOfCodeSML] = 4300;
            sizeOfCodeSML++;
            instrCounter++;
            tokenPtr = strtok_s(NULL, " ", &next_token);
        }
        //parse varName[int]
/*        else if((isalpha(tokenPtr[0]) != 0) && (strlen(tokenPtr) > 1)){
            if((tokenPtr[1] == '[') && (tokenPtr[strlen(tokenPtr) - 1] =']')){
                //new array
                if (getLocationInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable, 'V') == 0) {
                    insertInSymbolTable('V',  tokenPtr[0]);
                    dataCounter--;

                    arraySize = 0;
                    for(int e = 2; e < strlen(tokenPtr) - 1; e++){
                        if(isdigit(tokenPtr[e]))
                            arraySize++;
                        else{
                            printf("Error parse - %s\nIn %u string %s. Not exist array size, get - %c\n", tokenPtr, strNum, originalCodeStr, tokenPtr[2]);
                            exit(EXIT_FAILURE);
                        }
                    }
                    strncpy(&tokenPtr[2], arrayStrSize, arraySize);
                    arraySize = atoi(arrayStrSize);
                    while(arraySize--){

                    }
                }
                //get elem from array
                else{

                }
            }
            else{
                printf("Error parse - %s\nIn %u string %s. This is not a array.\n", tokenPtr, strNum, originalCodeStr);
                exit(EXIT_FAILURE);
            }

        }*/

        else{
            printf("Error parse - %s\nIn %u string - %s\n", tokenPtr, strNum, originalCodeStr);
            exit(EXIT_FAILURE);
        }
    }


}

void readSrcFile(const char fileName[])
{
    FILE *cfPtr;
    errno_t err;
    char codeStr[CODE_STR_SIZE];
    char originalCodeStr[CODE_STR_SIZE];
    char symbol;
    size_t i = 0;
    size_t strNum = 0;

    err = fopen_s(&cfPtr, fileName, "r");
    if( err == 0 ){
        fscanf_s(cfPtr, "%c", &symbol, 1);
        while(!feof(cfPtr)){
            if (symbol == '\n'){
                strNum++;
                codeStr[i] = '\0';
                originalCodeStr[i] = '\0';
                parseCodeStr(codeStr, strNum, originalCodeStr);
                originalCodeStr[0] = '\0';
                codeStr[0] = '\0';
                i = 0;
            }
            else{
                codeStr[i] = tolower(symbol);
                originalCodeStr[i] = symbol;
                i++;
            }
            fscanf_s(cfPtr, "%c", &symbol, 1);
            if(feof(cfPtr)){
                strNum++;
                codeStr[i] = '\0';
                originalCodeStr[i] = '\0';
                parseCodeStr(codeStr, strNum, originalCodeStr);
            }
        }
        fclose(cfPtr);

    }
    else{
        printf( "The file '%s' was not opened\n", fileName);
    }
}
