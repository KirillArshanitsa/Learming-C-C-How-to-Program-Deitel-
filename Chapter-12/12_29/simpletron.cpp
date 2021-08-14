#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

#define SIZE 100

int accumulator;
unsigned int instructionCounter;
unsigned int instructionRegister;
unsigned int operationCode;
unsigned int operand;
//TODO Bug in compiler - load type C in Simpletron memory - extern memory[]
int memory[SIZE];
FILE *resultFilePtr;

void printDump(const int[], const int);
unsigned int loadCommands(int[]);
void clearMemory(int[], const int);
void runCommands(const int[], const int);


void runCommands(int memory[], const unsigned int final) {
    int tmpNum;
    for (instructionCounter = 0; instructionCounter < final; instructionCounter++) {
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;
        switch (operationCode) {
            case 10:
                puts("Enter number:");
                fprintf(resultFilePtr, "%s\n", "Enter number:");
                scanf_s("%d", &memory[operand]);
                fprintf(resultFilePtr, "%d\n", memory[operand]);
                break;
            case 11:
                printf("%d\n", memory[operand]);
                fprintf(resultFilePtr, "%d\n", memory[operand]);
                break;
            case 20:
                accumulator = memory[operand];
                break;
            case 21:
                memory[operand] = accumulator;
                break;
             case 30:
                accumulator += memory[operand];
                break;
            case 31:
                accumulator -= memory[operand];
                break;
            case 32:
                if (memory[operand] == 0) {
                    puts("Error / 0");
                    printDump(memory, SIZE);
                    return;
                }
                else
                    accumulator /= memory[operand];
                break;
            case 33:
                accumulator *= memory[operand];
                break;
            case 34:
                accumulator %= memory[operand];
                break;
            case 35:
                tmpNum = memory[operand];
                while(tmpNum--)
                    accumulator *= accumulator;
                break;
            case 40:
                instructionCounter = operand - 1;
                break;
            case 41:
                if (accumulator < 0)
                    instructionCounter = operand - 1;
                break;
            case 42:
                if (accumulator == 0)
                    instructionCounter = operand - 1;
                break;
            case 43:
                return;
            default:
                printf("Not valid command %d\n", operationCode);
                break;
        }
    }

    fclose(resultFilePtr);
}

void clearMemory(int memory[], const int size) {
    for (int i = 0; i < size; i++)
        memory[i] = 0;
}

unsigned int loadCommands(int memory[]) {
    FILE *cfPtr;
    errno_t err;
    errno_t errResultFile;
    unsigned int count = 0;
    char tmpStrSMLCode[CODE_STR_SIZE];

    errResultFile = fopen_s(&resultFilePtr, RESULT_FILE_NAME, "w");
    if(errResultFile == 0){
        printf("*** Start load commands from file %s***\n", SML_CODE_FILE_NAME);
        fprintf(resultFilePtr, "*** Start load commands from file %s***\n", SML_CODE_FILE_NAME);
        err = fopen_s(&cfPtr, SML_CODE_FILE_NAME, "r");
        if( err == 0 ){
            while(!feof(cfPtr)){
                fscanf_s(cfPtr, "%s", &tmpStrSMLCode, CODE_STR_SIZE - 1);
                memory[count] = atoi(tmpStrSMLCode);
                count++;
            }
            fclose(cfPtr);
        }
        else{
            printf( "The file '%s' was not opened\n", SML_CODE_FILE_NAME);
        }

    }
    else{
        printf( "The file '%s' was not opened\n", RESULT_FILE_NAME);
    }
    printf("*** Finish load commands ***\n***Starting begin your program***\n");
    fprintf(resultFilePtr, "%s","*** Finish load commands ***\n***Starting begin your program***\n" );

    return count;
}


void printDump(const int memory[], const int size) {
    puts("\n\nPrint memory dump");
    puts("REGISTRY:");
    printf("%-22s%d\n", "accumulator", accumulator);
    printf("%-22s%d\n", "instructionCounter", instructionCounter);
    printf("%-22s%d\n", "instructionRegister", instructionRegister);
    printf("%-22s%d\n", "operationCode", operationCode);
    printf("%-22s%d\n", "operand", operand);
    puts("\n\nMEMORY:");
    for (int i = 0; i < 10; i++)
        printf("%8d", i);
    for (int i = 0; i < size; i++) {
        if (i % 10 == 0) {
            printf("\n%3d", i);
            if (memory[i] > 0)
                printf("%2s%4d", "+", memory[i]);
            else if (memory[i] == 0)
                printf("%2s0000", "+");
            else
                printf("%6d", memory[i]);
        }
        else {
            if (memory[i] > 0)
                printf("%3s%s%4d", " ", "+", memory[i]);
            else if (memory[i] == 0)
                printf("%3s%s0000", " ", "+");
            else
                printf("%8d", memory[i]);
        }
    }
    puts("\n");
}

/*int main(void) {
    int memory[SIZE] = { 0 };
    loadCommands(memory);
    //runCommands(memory, loadCommands(memory));
    //clearMemory(memory, SIZE);
    //printDump(memory, SIZE);
    return 0;
}*/
