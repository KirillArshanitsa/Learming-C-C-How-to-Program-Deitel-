#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


void getString(int);
char* splitStr(char[], int);


//TODO No good solution
int main(void) {
	srand(time(NULL));
	// %5 5 world in noun[]
	int firstRifm = rand() % 5;
	int secondRifm = rand() % 5;
	getString(firstRifm);
	getString(firstRifm);
	getString(secondRifm);
	getString(secondRifm);
	getString(firstRifm);
	return 0;
}


void getString(int strNum) {
	char resultStr[100] = {""};

	char article[] = {"the a one some any"};
	char noun[] = {"boy girl dog toen car"};
	char verb[] = {"drove jumped ran walked skipped"};
	char preposition[] = {"to from over on"};

	char* world  = splitStr(article, -1);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, " ");

	world = splitStr(noun, strNum);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, " ");

	world = splitStr(verb, -1);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, " ");

	world = splitStr(preposition, -1);
	strcat_s(resultStr, 100, world);
	strcat_s(resultStr, 100, ".");

	resultStr[0] = toupper(resultStr[0]);
	printf("%s\n", resultStr);

}

char* splitStr(char str[], int strNum) {

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
	if (strNum == -1)
		randNum = rand() % (lenght + 1);
	else
		randNum = strNum;

	//printf("randNum = %d\n", randNum);
	tokenPtr = strtok_s(str, " ", &next_token);
	for (int i = 0; tokenPtr != NULL || next_token != NULL; i++) {
		if (randNum == i)
			return tokenPtr;
		tokenPtr = strtok_s(NULL, " ", &next_token);
	}
}