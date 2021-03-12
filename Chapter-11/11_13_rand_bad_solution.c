#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_NUMBER_SIZE 7

void getPhoneNumber(char[]);
void getWords(const char[]);
void writeWords(const char[], FILE *);

int main(void)
{
		char phoneNum[PHONE_NUMBER_SIZE + 1];
	srand(time(NULL));
	getPhoneNumber(phoneNum);
	puts("Words result:");
	getWords(phoneNum);
	return 0;
}

void writeWords(const char word[], FILE *filePtr)
{
	fprintf_s(filePtr,"%s\n" ,word);
}


void getWords(const char phoneNum[])
{
	char fileName[] = "words.txt";
	FILE *filePtr;

	fopen_s(&filePtr, fileName, "w");
	if (filePtr == NULL) {
		printf("Error open file - %s\n", fileName);
	}

	const char phoneChars[8][3] = { {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'X', 'Y', 'Z'} };
	char word[PHONE_NUMBER_SIZE + 1];
	char tmpStr[] = { 0 };

	for (int i = 0; i < 6561; i++) { // 6561 = 2187 * 3, 2187 = 3^7
		for (char phoneLetter = 0, line = 0, column = 0; phoneLetter <= PHONE_NUMBER_SIZE; phoneLetter++) {
			line = rand() % 3;
			tmpStr[0] = phoneNum[phoneLetter];
			column = (char)atoi(tmpStr) - 2;  //phoneNum[phoneLetter] - 2   phone num 2-9 list phoneChars start wicth 0

			word[phoneLetter] = phoneChars[column][line];
		}

		word[PHONE_NUMBER_SIZE] = '\0';
		puts(word);
		writeWords(word, filePtr);
	}
	fclose(filePtr);
}

void getPhoneNumber(char phoneNum[])
{
	char secomdPartNum[5];

	puts("Enter phone number:");
	scanf_s("%3s-%4s", phoneNum, 4, secomdPartNum, 5);
	strcat_s(phoneNum, PHONE_NUMBER_SIZE + 1, secomdPartNum);

	while (strpbrk(phoneNum, "01")) {
		printf("You enter phone number - %s. Nubers 0 and 1 not allowed.\n", phoneNum);
		puts("Enter phone number:");
		scanf_s("%3s-%4s", phoneNum, 4, secomdPartNum, 5);
		strcat_s(phoneNum, PHONE_NUMBER_SIZE + 1, secomdPartNum);
	}

}