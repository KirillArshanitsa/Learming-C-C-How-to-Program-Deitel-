#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_NUMBER_SIZE 7 + 1
#define TOTAL_RAND_GENERATION 26244 + 1//6561 = 2187 * 12, 2187 = 3^7

void getPhoneNumber(char[]);
void getWords(const char[], char[][PHONE_NUMBER_SIZE]);
void writeWords(const char[][PHONE_NUMBER_SIZE], const char[]);
void deleteEqualsWord(char[][PHONE_NUMBER_SIZE]);
void printDisplay(const char[][PHONE_NUMBER_SIZE]);


int main(void)
{
	char allWords[TOTAL_RAND_GENERATION][PHONE_NUMBER_SIZE];
	char phoneNum[PHONE_NUMBER_SIZE];
	srand(time(NULL));
	getPhoneNumber(phoneNum);
	puts("Words result:");
	getWords(phoneNum, allWords);

	deleteEqualsWord(allWords);
	writeWords(allWords, phoneNum);
	//printDisplay(allWords);
	return 0;
}

void deleteEqualsWord(char allWords[][PHONE_NUMBER_SIZE])
{
	for (unsigned short e = 0, i = 1; e < TOTAL_RAND_GENERATION - 1; e++, i = e + 1) {
		for (; i < TOTAL_RAND_GENERATION; i++)
			if (strcmp(allWords[e], allWords[i]) == 0)
				allWords[e][0] = NULL;
	}
}

void printDisplay(const char allWords[][PHONE_NUMBER_SIZE])
{
	for (int i = 0; i < TOTAL_RAND_GENERATION; i++)
		puts(allWords[i]);
}


void writeWords(const char allWords[][PHONE_NUMBER_SIZE], const char phoneNum[])
{
	char fileName[] = "words.txt";
	FILE* filePtr;

	fopen_s(&filePtr, fileName, "w");
	if (filePtr == NULL) {
		printf("Error open file - %s\n", fileName);
		return;
	}

	printf("Write results in file %s\n", fileName);
	fprintf_s(filePtr, "Words for num - %s\n", phoneNum);

	for (unsigned short e = 0; e < TOTAL_RAND_GENERATION; e++) {
		if (allWords[e][0] != NULL)
			fprintf_s(filePtr, "%s\n", allWords[e]);
	}

	fclose(filePtr);
}


void getWords(const char phoneNum[], char allWords[][PHONE_NUMBER_SIZE])
{
	const char phoneChars[8][3] = { {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'X', 'Y', 'Z'} };
	char word[PHONE_NUMBER_SIZE];
	char tmpStr[] = { 0 };

	for (unsigned short i = 0; i < TOTAL_RAND_GENERATION; i++) {
		for (char phoneLetter = 0, line = 0, column = 0; phoneLetter < PHONE_NUMBER_SIZE; phoneLetter++) {
			line = rand() % 3;
			tmpStr[0] = phoneNum[phoneLetter];
			column = (char)atoi(tmpStr) - 2;  //phoneNum[phoneLetter] - 2   phone num 2-9 list phoneChars start wicth 0

			word[phoneLetter] = phoneChars[column][line];
		}

		word[PHONE_NUMBER_SIZE - 1] = '\0';
		for (char e = 0; e < PHONE_NUMBER_SIZE; e++)
			allWords[i][e] = word[e];
	}

}

void getPhoneNumber(char phoneNum[])
{
	char secomdPartNum[5];

	puts("Enter phone number:");
	scanf_s("%3s-%4s", phoneNum, 4, secomdPartNum, 5);
	strcat_s(phoneNum, PHONE_NUMBER_SIZE, secomdPartNum);

	while (strpbrk(phoneNum, "01")) {
		printf("You enter phone number - %s. Nubers 0 and 1 not allowed.\n", phoneNum);
		puts("Enter phone number:");
		scanf_s("%3s-%4s", phoneNum, 4, secomdPartNum, 5);
		strcat_s(phoneNum, PHONE_NUMBER_SIZE, secomdPartNum);
	}

}