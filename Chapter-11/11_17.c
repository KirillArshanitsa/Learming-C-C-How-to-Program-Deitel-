#include <stdio.h>
#define SIZE 100
#define FILE_NAME_SIZE 71

//Example
//+ 1009
//+ 1010
//+ 2009
//+ 3110
//+ 4107
//+ 1109
//+ 4300
//+ 1110
//+ 4300
//+ 0000
//+ 0000
//- 99999

unsigned int accumulator;
unsigned int instructionCounter;
unsigned int instructionRegister;
unsigned int operationCode;
unsigned int operand;

void printDump(const int[], const int);
unsigned int loadCommands(int[], const int);
void clearMemory(int[], const int);
void runCommands(int[], const unsigned int);
unsigned int getCodeFromFile(int[]);
void saveDumpInFile(const int[], const int);

int main(void) {
	int memory[SIZE] = { 0 };

	runCommands(memory, getCodeFromFile(memory));
	//runCommands(memory, loadCommands(memory, SIZE));
	//clearMemory(memory, SIZE);
	printDump(memory, SIZE);
	saveDumpInFile(memory, SIZE);

	return 0;
}

void saveDumpInFile(const int memory[], const int size) {
	char fileName[FILE_NAME_SIZE];
	int countStr = 0;
	FILE* filePtr;

	puts("Saving data....");
	do {
		putchar('\n');
		printf("Enter file name for save memory dump, max name size - %d: ", FILE_NAME_SIZE);
		countStr = scanf_s("%s", fileName, FILE_NAME_SIZE);
	} while (countStr > FILE_NAME_SIZE || countStr == 0);

	fopen_s(&filePtr, fileName, "w");
	if (filePtr == NULL) {
		printf("Error open file %s\n", fileName);
		return;
	}

	fprintf_s(filePtr, "Print memory dump\n");
	fprintf_s(filePtr, "%s\n", "REGISTRY:");
	fprintf_s(filePtr, "%-21s%+d\n", "accumulator", accumulator);
	fprintf_s(filePtr, "%-22s%d\n", "instructionCounter", instructionCounter);
	fprintf_s(filePtr, "%-22s%d\n", "instructionRegister", instructionRegister);
	fprintf_s(filePtr, "%-22s%d\n", "operationCode", operationCode);
	fprintf_s(filePtr, "%-22s%d\n", "operand", operand);
	fprintf_s(filePtr, "%s", "\n\nMEMORY:\n");
	for (int i = 0; i < 10; i++)
		fprintf_s(filePtr, "%8d", i);
	for (int i = 0; i < size; i++) {
		if (i % 10 == 0) {
			fprintf_s(filePtr, "\n%2d", i);
			if (memory[i] > 0)
				fprintf_s(filePtr, "%2s%4d", "+", memory[i]);
			else if (memory[i] == 0)
				fprintf_s(filePtr, "%2s0000", "+");
			else
				fprintf_s(filePtr, "%6d", memory[i]);
		}
		else {
			if (memory[i] > 0)
				fprintf_s(filePtr, "%3s%s%4d", " ", "+", memory[i]);
			else if (memory[i] == 0)
				fprintf_s(filePtr, "%3s%s0000", " ", "+");
			else
				fprintf_s(filePtr, "%8d", memory[i]);
		}
	}
	fprintf_s(filePtr, "%s", "\n");
	fclose(filePtr);
	puts("Save done");
}


unsigned int getCodeFromFile(int memory[])
{
	FILE* filePtr;
	char fileName[FILE_NAME_SIZE];
	int countStr = 0;
	unsigned int i = 0;
	do {
		putchar('\n');
		printf("Enter file name, with max name size - %d:", FILE_NAME_SIZE);
		countStr = scanf_s("%s", fileName, FILE_NAME_SIZE);
	} while (countStr > FILE_NAME_SIZE || countStr == 0);

	fopen_s(&filePtr, fileName, "r");
	if (filePtr == NULL) {
		printf("Error open file %s\n", fileName);
		return -1;
	}

	fscanf_s(filePtr, "%d", &memory[i]);
	while (!feof(filePtr)) {
		fscanf_s(filePtr, "%d", &memory[++i]);
	}
	fclose(filePtr);
	return i;
}

void runCommands(int memory[], const unsigned int final) {
	for (instructionCounter = 0; instructionCounter < final; instructionCounter++) {
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		switch (operationCode) {
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
		case 22:
			memory[operand] < 0 ? accumulator = (memory[operand] * -1) : accumulator = memory[operand];
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
			if (memory[operand] > 0) {
				while (memory[operand]-- > 0)
					accumulator *= accumulator;
			}
			else if (memory[operand] == 0)
				accumulator = 0;
			else {
				//TODO fix 1/int
				while (memory[operand]++ < 0)
					accumulator *= accumulator;
				printf("!!! accumulator = %d\n", 1.0 / accumulator);
				accumulator = 1 / accumulator;
			}
			break;
		case 40:
			instructionCounter = operand;
			break;
		case 41:
			if (accumulator < 0)
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


unsigned int loadCommands(int memory[], const int size) {
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
	printf("%-21s%+d\n", "accumulator", accumulator);
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

