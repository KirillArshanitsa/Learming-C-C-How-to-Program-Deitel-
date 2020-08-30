#include <stdio.h>
#define SIZE 100

unsigned int accumulator;
unsigned int instructionCounter;
unsigned int instructionRegister;
unsigned int operationCode;
unsigned int operand;

void printDump(const int[], const int);
unsigned int loadCommands(int [], const int);
void clearMemory(int[], const int);
void runCommands(const int[], const int);

void runCommands(int memory[], const unsigned int final) {
	for (instructionCounter = 0; instructionCounter < final; instructionCounter++) {
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		switch (operationCode){
			case 10:
				puts("Enter number:");
				scanf_s("%d", &memory[operand]);
				break;
			case 11:
				printf("%d", memory[operand]);
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
				accumulator /= memory[operand];
				break;
			case 33:
				accumulator *= memory[operand];
				break;
			case 40:
				instructionCounter = operand;
				break;
			case 41:
				if(accumulator < 0)
					instructionCounter = operand;
				break;
			case 42:
				if (accumulator == 0)
					instructionCounter = operand;
				break;
			case 43:
				return;
			default:
				printf("Not corrcet command %d\n", operationCode);
				break;
		}
	}
}

void clearMemory(int memory[], const int size) {
	for (int i = 0; i < size; i++)
		memory[i] = 0;
}

unsigned int loadCommands(int memory [], const int size) {
	printf("*** Start load commands ***\n");
	for (int i = 0; i < size; i++) {
		do {
			i < 10 ? printf("0%d? ", i) : printf("%d? ", i);
			scanf_s("%d", &memory[i]);
			if (memory[i] == -99999) {
				puts("Enter finished");
				return i;
			}
		} while ((memory[i] > 9999) || (memory[i] < -9999));
	}
	printf("*** Finish load commands ***\n***Starting begin your programm***\n");
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
			printf("\n%2d", i);
			if (memory[i] > 0)
				printf("%-2s%4d", "+", memory[i]);
			else if (memory[i] == 0)
				printf("%2s0000", "+");
			else
				printf("%6d", memory[i]);
		}
		else {
			if (memory[i] > 0)
				printf("%3s%s%4d", " ","+", memory[i]);
			else if (memory[i] == 0)
				printf("%3s%s0000", " ","+");
			else
				printf("%8d", memory[i]);
		}
	}
}

int main(void) {
	int memory[SIZE] = {0};
	runCommands(memory, loadCommands(memory, SIZE));
	//clearMemory(memory, SIZE);
	printDump(memory, SIZE);

	return 0;
}