#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define NUMBER_COMMAND_COUNT 5
#define COMMAND_BLOCK_SIZE 2

unsigned int accumulator;
unsigned int instructionCounter;
unsigned int instructionRegister;
unsigned int operationCode;
unsigned int operand;

void printDump(const int[]);
unsigned int loadCommands(int[]);
void clearMemory(int[]);
void runCommands(const int[], const int);
int hexCharToInt(const char[], int);
int charsToInt(const char[], const int, const int);


int charsToInt(const char symbols[], const int begin, const int finish) {
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
			printf("Error in %d %c\n", e, symbols[e]);
			return -1;
		}
		result += extent * number;
		printf("result %d extent %d number %d\n", result, extent, number);
	}
	puts("Finish");
	return result;
}


int hexCharToInt(const char list[], int size) {
	int result = 0;
	int multiplier = 1;
	int partCommad;
	int partAdress;
	int addresMaxCount = 1;
	int commandMaxCount = 1;

	for (int e = NUMBER_COMMAND_COUNT - COMMAND_BLOCK_SIZE; e > 0; e--)
		addresMaxCount *= 10;
	for (int e = COMMAND_BLOCK_SIZE; e > 0; e--)
		commandMaxCount *= 10;
	for (int e = size; e > size - COMMAND_BLOCK_SIZE; e--)
		multiplier *= 10;

	//printf("multiplier %d\n", multiplier);
	partCommad = charsToInt(list, 0, COMMAND_BLOCK_SIZE);
	//printf("partCommad %d\n", partCommad);
	partAdress = charsToInt(list, COMMAND_BLOCK_SIZE, size);
	//printf("partAdress %d\n", partAdress);

	if (partAdress / addresMaxCount > 0) {
		printf("Error you enter %d max coun num for adress is %d\n", partAdress, NUMBER_COMMAND_COUNT - COMMAND_BLOCK_SIZE);
		return -1;
	}
	if (partCommad / commandMaxCount > 0) {
		printf("Error you enter %d max coun num for command is %d\n", partAdress, partCommad - COMMAND_BLOCK_SIZE);
		return -1;
	}
	result = partCommad * multiplier + partAdress;
	//printf("result %d\n", result);
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
				printDump(memory);
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

void clearMemory(int memory[]) {
	for (int i = 0; i < SIZE; i++)
		memory[i] = 0;
}

unsigned int loadCommands(int memory[]) {
	// +2 - 1 \0 -2 - 
	char inputVal[NUMBER_COMMAND_COUNT + 2];
	int inputSize;
	char breakVal[] = "-99999";
	puts("*** Start load commands ***");
	printf("*** Enter %s for finish ***\n", breakVal);
	for (int i = 0; i < SIZE; i++) {
		do {
			inputSize = 0;
			for (int i = 0; i < NUMBER_COMMAND_COUNT + 2; i++)
				inputVal[i] = 0;

			i < 10 ? printf("0%d? ", i) : printf("%d? ", i);
			scanf("%s", inputVal);
			printf("You enter %s\n", inputVal);

			//TODO check all char to hex symbol
			if (inputVal[0] == 45)  {
				for (int i = 1; i <= NUMBER_COMMAND_COUNT; i++) {
					if (inputVal[i] != breakVal[i]) {
						printf("You enter negative number %s\n", inputVal);
						continue;
					}
				}
				puts("Enter finished -99999");
				return i;
			}

			for (int e = 0; inputVal[e] != '\0'; e++) {
				inputSize++;
			}
			if (inputSize > NUMBER_COMMAND_COUNT + 1 ) {
				printf("You enter %d, max count is %d with negative num\n", inputSize, NUMBER_COMMAND_COUNT + 1);
				continue;
			}
			memory[i] = hexCharToInt(inputVal, inputSize);

			//if (memory[i] == -99999) {//1869F
			//	puts("Enter finished");
			//	return i;
			//}
		} while ((memory[i] > 99999) || (memory[i] < -99999));
	}
	printf("*** Finish load commands ***\n***Starting begin your programm***\n");
}

void printDump(const int memory[]) {
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
	for (int i = 0; i < SIZE; i++) {
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
				printf("%3s%s%4d", " ", "+", memory[i]);
			else if (memory[i] == 0)
				printf("%3s%s0000", " ", "+");
			else
				printf("%8d", memory[i]);
		}
	}
	puts("");
}

int main(void) {
	int memory[SIZE] = { 0 };
	runCommands(memory, loadCommands(memory));
	//clearMemory(memory, SIZE);
	printDump(memory);
	return 0;
}