#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHONE_NUMBER_SIZE 7

void getPhoneNumber(char[]);
void getWords(const char[]);

int main(void)
{
	char phoneNum[PHONE_NUMBER_SIZE + 1];

	getPhoneNumber(phoneNum);
	puts("Words result:");
	getWords(phoneNum);
	return 0;
}


void getWords(const char phoneNum[])
{
	const char phoneChars[8][3] = { {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'X', 'Y', 'Z'} };
	char word[PHONE_NUMBER_SIZE + 1];
	char tmpStr[] = { 0 };

	unsigned int totalCount = 0;

	// shift 0
	for (char line = 0; line < 3; line++) {
		for (char phoneLetter = 0, column = 0; phoneLetter <= PHONE_NUMBER_SIZE; phoneLetter++) {
			tmpStr[0] = phoneNum[phoneLetter];
			column = (char)atoi(tmpStr) - 2;  //phoneNum[phoneLetter] - 2   phone num 2-9 list phoneChars start wicth 0

			word[phoneLetter] = phoneChars[column][line];
		}
		totalCount++;
		word[PHONE_NUMBER_SIZE] = '\0';
		puts(word);
	}

	// shift 1
	for (char shiftPhoneDidgit = 0, shift = 1; shiftPhoneDidgit < PHONE_NUMBER_SIZE; shiftPhoneDidgit++) {
		for (char line = 0; line < 3; line += 2) {
			for (char phoneLetter = 0, column; phoneLetter < PHONE_NUMBER_SIZE; phoneLetter++) {
				tmpStr[0] = phoneNum[phoneLetter];
				column = (char)atoi(tmpStr) - 2;  //phoneNum[phoneLetter] - 2   phone num 2-9 list phoneChars start wicth 0

				if (shiftPhoneDidgit == phoneLetter)
					word[phoneLetter] = phoneChars[column][shift];
				else
					word[phoneLetter] = phoneChars[column][line];

			}
			totalCount++;
			word[PHONE_NUMBER_SIZE] = '\0';
			puts(word);
		}
	}

	// shift2 and line < 2
	for (char shiftPhoneDidgit = 0, shift = 2; shiftPhoneDidgit < PHONE_NUMBER_SIZE; shiftPhoneDidgit++) {
		for (char line = 0; line < 2; line++) {
			for (char phoneLetter = 0, column; phoneLetter < PHONE_NUMBER_SIZE; phoneLetter++) {
				tmpStr[0] = phoneNum[phoneLetter];
				column = (char)atoi(tmpStr) - 2;  //phoneNum[phoneLetter] - 2   phone num 2-9 list phoneChars start wicth 0

				if (shiftPhoneDidgit == phoneLetter)
					word[phoneLetter] = phoneChars[column][shift];
				else
					word[phoneLetter] = phoneChars[column][line];
			}

			totalCount++;
			word[PHONE_NUMBER_SIZE] = '\0';
			puts(word);
		}
	}


	// shift 1 and multiple shifts
	//генерировать номера цифр номера для пропуска
	char shiftPhoneDidgits[PHONE_NUMBER_SIZE];
	char shift = 1;


	for (char line = 0; line < 3; line += 2) {
		for (char phoneLetter = 0, column; phoneLetter < PHONE_NUMBER_SIZE; phoneLetter++) {
			tmpStr[0] = phoneNum[phoneLetter];
			column = (char)atoi(tmpStr) - 2;  //phoneNum[phoneLetter] - 2   phone num 2-9 list phoneChars start wicth 0

			//сравнение номеров из массива
			if (shiftPhoneDidgit == phoneLetter)
				word[phoneLetter] = phoneChars[column][shift];
			else
				word[phoneLetter] = phoneChars[column][line];

		}
		totalCount++;
		word[PHONE_NUMBER_SIZE] = '\0';
		puts(word);
	}



	printf("\n\ntotalCount = %u\n", totalCount);



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