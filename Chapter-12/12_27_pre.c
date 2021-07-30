#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SRC_FILE_NAME_SIZE 100
#define CODE_STR_SIZE 40
#define TABLE_ENTRY_COUNT 100

struct tableEntry{
    int symbol;
    char type;
    int location;
};

typedef tableEntry TableEntry;

void readSrcFile(const char[]);
void parseCodeStr(char[]);
int findInTableEntry(const TableEntry* symbolTable[], int, unsigned int);
void printSMLCode(const int[], unsigned int);
void printSymbolTable(TableEntry*[], unsigned int);
int getLocationInTableEntry(TableEntry* const [], int, unsigned int, char);
void printFlags(int[]);

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
    readSrcFile(fileName);
    printSMLCode(codeSML, sizeOfCodeSML);
    puts("");
    printSymbolTable(symbolTable, counterSymbolTable);
    puts("");
    printFlags(flags);
    return 0;
}

void printFlags(int flags[])
{
    puts("Print flags:");
    for(unsigned int i = 0 ; i != TABLE_ENTRY_COUNT;i++)
        printf("%d\n", flags[i]);
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
            printf("%c %c %d\n", symbolTable[i]->symbol, symbolTable[i]->type, symbolTable[i]->location);
        }
        else {
            printf("%d %c %d\n", symbolTable[i]->symbol, symbolTable[i]->type, symbolTable[i]->location);
        }
    }
}

void printSMLCode(const int codeSML[], unsigned int sizeOfCodeSML)
{
    puts("Print SML code:");
    for (unsigned int i = 0 ; i != sizeOfCodeSML; i++)
        printf("%+d\n",codeSML[i]);
}

int findInTableEntry(TableEntry* const symbolTable[], int symbol, unsigned int size)
{
    for (unsigned int i = 0; i != size ;i++){
        if(symbolTable[i]->type == 'V')
            if(symbolTable[i]->symbol == symbol)
                return 1;
    }
    return 0;
}

void parseCodeStr(char codeStr[])
{
    char *next_token = NULL;
    char *tokenPtr;
    tokenPtr = strtok_s(codeStr, " ", &next_token);

    symbolTable[counterSymbolTable] = (TableEntry*) malloc(sizeof(TableEntry));
    symbolTable[counterSymbolTable]->symbol = atoi(tokenPtr);
    symbolTable[counterSymbolTable]->type = 'L';
    symbolTable[counterSymbolTable]->location = instrCounter;
    counterSymbolTable++;
    
    while (tokenPtr != NULL){
        //printf("%s\n", tokenPtr);
        if(strcmp(tokenPtr, "rem") == 0)
            break;
        else if(strcmp(tokenPtr, "input") == 0){
            tokenPtr = strtok_s(NULL, " ", &next_token);
            if(findInTableEntry(symbolTable, atoi(tokenPtr) ,counterSymbolTable) == 0){
                symbolTable[counterSymbolTable] = (TableEntry*) malloc(sizeof(TableEntry));
                symbolTable[counterSymbolTable]->symbol = tokenPtr[0];
                symbolTable[counterSymbolTable]->type = 'V';
                symbolTable[counterSymbolTable]->location = dataCounter;
                counterSymbolTable++;

                codeSML[sizeOfCodeSML] = 1000 + dataCounter;
                sizeOfCodeSML++;

                dataCounter--;
            }
            instrCounter++;
            break;
        }
        else if(strcmp(tokenPtr, "if") == 0){
            tokenPtr = strtok_s(NULL, " ", &next_token);
            //Var in if
            if (findInTableEntry(symbolTable, atoi(tokenPtr), counterSymbolTable) == 0) {
                symbolTable[counterSymbolTable] = (TableEntry *) malloc(sizeof(TableEntry));
                symbolTable[counterSymbolTable]->symbol = tokenPtr[0];
                symbolTable[counterSymbolTable]->type = 'V';
                symbolTable[counterSymbolTable]->location = dataCounter;

                counterSymbolTable++;
                dataCounter--;
            }
            //chek condition in if
            tokenPtr = strtok_s(NULL, " ", &next_token);
            if(strcmp(tokenPtr, "==") == 0){
                codeSML[sizeOfCodeSML] = 2000 + dataCounter + 1;// +1
                sizeOfCodeSML++;
                instrCounter++;
                //check second var in if
                tokenPtr = strtok_s(NULL, " ", &next_token);
                if (findInTableEntry(symbolTable, tokenPtr[0], counterSymbolTable) == 0) {
                    symbolTable[counterSymbolTable] = (TableEntry *) malloc(sizeof(TableEntry));
                    symbolTable[counterSymbolTable]->symbol = tokenPtr[0];
                    symbolTable[counterSymbolTable]->type = 'V';
                    symbolTable[counterSymbolTable]->location = dataCounter;

                    counterSymbolTable++;
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
            break;
        }

        tokenPtr = strtok_s(NULL, " ", &next_token);
    }

}

void readSrcFile(const char fileName[])
{
    FILE *cfPtr;
    errno_t err;
    char codeStr[CODE_STR_SIZE];
    char symbol;
    int i = 0;

    err = fopen_s(&cfPtr, fileName, "r");
    if( err == 0 ){
        fscanf_s(cfPtr, "%c", &symbol, 1);
        while(!feof(cfPtr)){
            if (symbol == '\n'){
                codeStr[i] = '\0';
                //printf("%s\n", codeStr);
                parseCodeStr(codeStr);

                codeStr[0] = '\0';
                i = 0;
            }
            else{
                codeStr[i] = symbol;
                i++;
            }
            fscanf_s(cfPtr, "%c", &symbol, 1);
        }
        fclose(cfPtr);
    }
    else{
        printf( "The file '%s' was not opened\n", fileName);
    }
}