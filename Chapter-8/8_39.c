#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_STR_SIZE 100
#define STR_SYMBOLS_COUNT 37
#define MORSE_SYMBOLS_COUNT 36
#define MORSE_SYMBOLS_DELIMITER_SIZE 3

void getMorseCode(const char[], const char[], const char*[]);
void getStrCode(const char[], const char[], const char* []);
void getWordFromMorse(const char[], const char[], const char* []);

int main(void)
{
	char strSymbols[STR_SYMBOLS_COUNT] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
	const char *morseSymbols[MORSE_SYMBOLS_COUNT] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----" };
	char str[MAX_STR_SIZE];

	puts("Enter string:");
	gets_s(str);
	puts("Morze code:");
	getMorseCode(str, strSymbols, morseSymbols);
	puts("\n\nEnter Morze code:");
	gets_s(str);
	puts("String:");
	getStrCode(str, strSymbols, morseSymbols);

}

void getMorseCode(const char str[], const char strSymbols[], const char *morseSymbolsPtr[])
{
	size_t strSize = strlen(str);
	for (size_t e = 0; e < strSize; e++) {
		if (str[e] == ' ') {
			printf("   ");
			continue;
		}
		for (size_t i = 0; i < STR_SYMBOLS_COUNT - 1; i++) {
			if (toupper(str[e]) == strSymbols[i])
				printf("%s ", morseSymbolsPtr[i]);
		}
	}
}


void getWordFromMorse(const char str[], const char strSymbols[], const char* morseSymbolsPtr[])
{
	char* tmpPtr = NULL;
	char* tokenPtr;
	char copyStr[MAX_STR_SIZE];
	strcpy_s(copyStr, str);
	tokenPtr = strtok_s(copyStr, " ", &tmpPtr);
	while (tokenPtr != NULL) {
		for (int e = 0; e < MORSE_SYMBOLS_COUNT; e++) {
			if (strcmp(tokenPtr, morseSymbolsPtr[e]) == 0) {
				printf("%c", strSymbols[e]);
				break;
			}
		}
		tokenPtr = strtok_s(NULL, " ", &tmpPtr);
	}
}
void getStrCode(const char str[], const char strSymbols[], const char *morseSymbolsPtr[])
{	
	const char *wordPtr = strstr(str, "   ");

	if (wordPtr == NULL) {
		getWordFromMorse(str, strSymbols, morseSymbolsPtr);
	}

	else {
		char wordMorseCode[MAX_STR_SIZE];
		const char *strPtr = str;
		size_t partStrsize;
		while (wordPtr != NULL) {
			partStrsize = (wordPtr - strPtr) / sizeof(char);
			strncpy_s(wordMorseCode, strPtr, partStrsize);
			//wordMorseCode[partStrsize + 1] = '\0';
			strPtr = wordPtr + MORSE_SYMBOLS_DELIMITER_SIZE;
			getWordFromMorse(wordMorseCode, strSymbols, morseSymbolsPtr);
			wordMorseCode[0] = '\0';
			wordPtr = strstr(strPtr, "   ");
			printf(" ");
		}
		getWordFromMorse(strPtr, strSymbols, morseSymbolsPtr);

	}
	
}
