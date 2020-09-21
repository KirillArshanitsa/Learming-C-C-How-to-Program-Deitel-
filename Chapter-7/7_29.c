#include <stdio.h>
#define SIZE 1000
#define COUNT_NUM_MACHINEWORD 5

unsigned int accumulator;
unsigned int instructionCounter;
unsigned int instructionRegister;
unsigned int operationCode;
unsigned int operand;

void printDump(const int[], const int);
unsigned int loadCommands(int[], const int);
unsigned int loadCommandsHex(int[], const int);
void clearMemory(int[], const int);
void runCommands(const int[], const int);
int hexCharsToInt(const char[], const int, const int);


int hexCharsToInt(const char symbols[], const int begin, const int finish) {
	int result = 0;
	int number = 0;
	int check;

	for (int e = finish - 1, extent = 1; e >= begin; e--, extent *= 16) {
		check = 1;
		number = -1;
		for (int charInt = 48, num = 0; charInt <= 57; charInt++, num++) {
			if (symbols[e] == charInt) {
				number = num;
				check = 0;
				break;
			}
		}
		if (check) {
			//A-F
			for (int charInt = 65, num = 10; charInt <= 70; charInt++, num++) {
				if (symbols[e] == charInt) {
					number = num;
					check = 0;
					break;
				}
			}
		}
		if (check) {
			//a-f
			for (int charInt = 97, num = 10; charInt <= 102; charInt++, num++) {
				if (symbols[e] == charInt) {
					number = num;
					check = 0;
					break;
				}
			}
		}
		if ((check) || (number == -1)) {
			printf("Error in %d %c %s\n", e, symbols[e], symbols);
			return -1;
		}
		result += extent * number;
		//printf("result %d extent %d number %d\n", result, extent, number);
	}
	return result;
}


void runCommands(int memory[], const unsigned int final) {
	for (instructionCounter = 0; instructionCounter < final; instructionCounter++) {
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % SIZE;
		switch (operationCode) {
		case 10:
			puts("Enter number:");
			scanf_s("%d", &memory[operand]);
			break;
		case 11:
			printf("%d", memory[operand]);
			break;
		case 12:
			puts("");
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
	puts("*** Start load commands ***");
	puts("*** Enter -99999 for finish ***");
	for (int i = 0; i < size; i++) {
		do {
			i < 10 ? printf("0%d? ", i) : printf("%d? ", i);
			scanf_s("%d", &memory[i]);
			if (memory[i] == -99999) {
				puts("Enter finished");
				return i;
			}
		} while ((memory[i] > 99999) || (memory[i] < -99999));
	}
	printf("*** Finish load commands ***\n***Starting begin your programm***\n");
}


unsigned int loadCommandsHex(int memory[], const int size) {
	puts("*** Start load commands ***");
	puts("*** Enter -1869F for finish ***");
	// +2 1 \0 2 -
	char machineWord[COUNT_NUM_MACHINEWORD + 2];

	for (int i = 0, machineWordSize, machineWordBeginElem, intMachineWord; i < size; i++) {
		do {
			intMachineWord = -100000;
			for (int e = 0; e < COUNT_NUM_MACHINEWORD + 2; e++)
				machineWord[e] = 0;

			i < 10 ? printf("0%d? ", i) : printf("%d? ", i);
			scanf("%s", machineWord);

			for (machineWordSize = 0; machineWord[machineWordSize] != '\0'; machineWordSize++);
			if (machineWord[0] == 45) {
				machineWordBeginElem = 1;
				if (machineWordSize > COUNT_NUM_MACHINEWORD + 1) {
					printf("You enter %d symbols, max command size is %d without -", machineWordSize, COUNT_NUM_MACHINEWORD + 1);
					continue;
				}
			}
			else {
				machineWordBeginElem = 0;
				if (machineWordSize > COUNT_NUM_MACHINEWORD + 2) {
					printf("You enter %d symbols, max command size is %d", machineWordSize, COUNT_NUM_MACHINEWORD + 2);
					continue;
				}
			}
			intMachineWord = hexCharsToInt(machineWord, machineWordBeginElem, machineWordSize);
			//check
			if (intMachineWord == -100000) {
				printf("Error convert %s\n", machineWord);
				continue;
			}
			// if negative num entered
			if (machineWordBeginElem)
				intMachineWord *= -1;

			memory[i] = intMachineWord;
			if (memory[i] == -99999) {
				puts("Enter finished");
				return i;
			}
		} while ((memory[i] > 99999) || (memory[i] < -99999));
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
			printf("\n%3d", i);
			if (memory[i] > 0)
				printf("%-2s%4d", "+", memory[i]);
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

int main(void) {
	int memory[SIZE] = { 0 };
	//runCommands(memory, loadCommands(memory, SIZE));
	//runCommands(memory, loadCommandsHex(memory, SIZE));
	//clearMemory(memory, SIZE);
	printDump(memory, SIZE);

	return 0;
}