#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


void getString(void);
char* splitStr(char[]);

int main(void) {
	srand(time(NULL));
	for (int i = 0 ; i <20 ; i ++)
		getString();
	return 0;
}


void getString(void) {
	char resultStr[100] = {""};

	char article[] = {"the a one some any"};
	char noun[] = {"boy girl dog toen car"};
	char verb[] = {"drove jumped ran walked skipped"};
	char preposition[] = {"to from over on"};

	char* world  = splitStr(article);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, " ");

	world = splitStr(noun);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, " ");

	world = splitStr(verb);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, " ");

	world = splitStr(preposition);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, ".");

	resultStr[0] = toupper(resultStr[0]);
	printf("%s\n", resultStr);

}

char* splitStr(char str[]) {
	int lenght = 0;
	int randNum;
	char* tokenPtr;
	char* next_token = NULL;
	
	//Get count for random num
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ')
			lenght++;
	}

	if (lenght == 0) {
		printf("Error in search space in string %s\n", str);
		return NULL;
	}

	randNum = rand() % (lenght + 1);
	//printf("randNum = %d\n", randNum);
	tokenPtr = strtok_s(str, " ", &next_token);
	for (int i = 0; tokenPtr != NULL || next_token != NULL; i++) {
		if (randNum == i)
			return tokenPtr;
		tokenPtr = strtok_s(NULL, " ", &next_token);
	}
}