#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertDataSlash(char *);

int main(void) {
	char dataStr[] = "07/21/55";
	convertDataSlash(dataStr);
	return 0;
}

//add chek dataStrPtr
void convertDataSlash(char* dataStrPtr) {
	char* tPtr = NULL;
	char *toketnPtr = strtok_s(dataStrPtr, "/", &tPtr);
	switch (atoi(toketnPtr)){
		case 1:
			printf("January");
			break;
		case 2:
			printf("February");
			break;
		case 3:
			printf("March");
			break;
		case 4:
			printf("April");
			break;
		case 5:
			printf("May");
			break;
		case 6:
			printf("June");
			break;
		case 7:
			printf("July");
			break;
		case 8:
			printf("August");
			break;
		case 9:
			printf("September");
			break;
		case 10:
			printf("October");
			break;
		case 11:
			printf("November");
			break;
		case 12:
			printf("December");
			break;
		default:
			puts("Error parse month!");
			break;
	}

	printf(" %s, ", strtok_s(NULL, "/", &tPtr));
	printf("19%s\n", strtok_s(NULL, "/", &tPtr));

}