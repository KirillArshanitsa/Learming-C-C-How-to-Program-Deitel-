#include <stdio.h>
#include <string.h>
#define SIZE_OF_CLIENT_NAME 25

void generateTestData(const char[], int, int);
void readTestData(const char[]);
void clearFile(const char[]);

struct Account {
	int accountNum;
	//char name[SIZE_OF_CLIENT_NAME];
	char *name;
	double dollarAmount;
};

int main(void) 
{
	//FILE *ofPtr = fopen("oldmast.dat", "r");
	//FILE *tfPtr = fopen("trans.dat", "r");
	//FILE *nfPtr = fopen("newmast.dat", "w");
	const char oldmast [] = "oldmast.dat";
	const char trans[] = "trans.dat";
	const char newmast[] = "newmast.dat";

	puts("Generate test data");
	clearFile(oldmast);
	generateTestData(oldmast, 1, 10);
	puts("Generate test transactions");
	clearFile(trans);
	generateTestData(trans, 12, 15);
	generateTestData(trans, 19, 21);

	puts("\nRead test data");
	readTestData(oldmast);
	puts("\nRead test transactions data");
	readTestData(trans);

	return 0;
}

void clearFile(const char fileName[]) {
	FILE* filePtr;
	errno_t err = fopen_s(&filePtr, fileName, "w");
	if (filePtr == NULL) {
		printf("Error open file %s", fileName);
		return;
	}
	fclose(filePtr);
}

void readTestData(const char fileName[])
{
	FILE *filePtr;
	int accountNum;
	char name[SIZE_OF_CLIENT_NAME];
	double dollarAmount;
	errno_t err = fopen_s(&filePtr, fileName, "r");

	if (filePtr == NULL) {
		printf("Error open file %s", fileName);
		return;
	}

	printf("%-10s%-13s%s\n", "Account", "Name", "DollarAmount");
	fscanf_s(filePtr, "%d%s%lf", &accountNum, name, SIZE_OF_CLIENT_NAME, &dollarAmount);
	while (!feof(filePtr)) {
		printf("%-10d%-13s%-7.2lf\n", accountNum, name, dollarAmount);
		fscanf_s(filePtr, "%d%s%lf", &accountNum, name, SIZE_OF_CLIENT_NAME, &dollarAmount);
	}
	fclose(filePtr);
}


void generateTestData(const char fileName[], int beginVal, int endVal)
{
	FILE *filePtr;
	int accountNum;
	double dollarAmount;
	char userName[SIZE_OF_CLIENT_NAME];
	errno_t err = fopen_s(&filePtr, fileName, "a");

	if (filePtr == NULL) {
		printf("Error open file %s", fileName);
		return;
	}

	while (beginVal <= endVal) {
		sprintf_s(userName, "User_%d", beginVal);
		accountNum = beginVal;
		dollarAmount = beginVal * 1.0;
		fprintf_s(filePtr, "%d %s %lf\n", accountNum, userName, dollarAmount);
		beginVal++;
	}
	fclose(filePtr);
}