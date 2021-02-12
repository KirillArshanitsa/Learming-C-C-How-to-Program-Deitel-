#include <stdio.h>
#include <string.h>
#define SIZE_OF_CLIENT_NAME 25

void generateTestData(const char[], int, int);
void readTestData(const char[]);
void clearFile(const char[]);
void compareTransactions(const char[], const char[], const char[]);

struct Account {
	int accountNum;
	//char name[SIZE_OF_CLIENT_NAME];
	char *name;
	double dollarAmount;
};

int main(void) 
{
	const char oldmast [] = "oldmast.dat";
	const char trans[] = "trans.dat";
	const char newmast[] = "newmast.dat";

	puts("Generate test data");
	clearFile(oldmast);
	generateTestData(oldmast, 1, 10);
	puts("Generate test transactions");
	clearFile(trans);
	generateTestData(trans, 1, 5);
	generateTestData(trans, 19, 21);

	puts("\nRead test data");
	readTestData(oldmast);
	puts("\nRead test transactions data");
	readTestData(trans);

	puts("\n\nComprae transactions");
	compareTransactions(oldmast, trans, newmast);
	puts("\nRead result data");
	readTestData(newmast);

	return 0;
}

void compareTransactions(const char oldmast[], const char trans[], const char newmast[])
{
	FILE* ofPtr;
	FILE* tfPtr;
	FILE* nfPtr;
	int accountNumOldMast;
	char nameOldMast[SIZE_OF_CLIENT_NAME];
	double currentBalanceOldMast;
	int accountNumTemp;
	char nameTemp[SIZE_OF_CLIENT_NAME];
	double dollarAmountTemp;
	int notHaveInTrans;
	errno_t erofPtr = fopen_s(&ofPtr, oldmast, "r");
	errno_t ertfPtr = fopen_s(&tfPtr, trans, "r");
	errno_t ernfPtr = fopen_s(&nfPtr, newmast, "w");

	if (ofPtr == NULL) {
		printf("Error open file %s", oldmast);
		return;
	}
	if (tfPtr == NULL) {
		printf("Error open file %s", trans);
		return;
	}
	if (nfPtr == NULL) {
		printf("Error open file %s", newmast);
		return;
	}

	fscanf_s(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, SIZE_OF_CLIENT_NAME, &currentBalanceOldMast);
	while (!feof(ofPtr)) {
		fscanf_s(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, SIZE_OF_CLIENT_NAME, &dollarAmountTemp);
		while (!feof(tfPtr)) {
			if (accountNumOldMast == accountNumTemp)
				currentBalanceOldMast += dollarAmountTemp;
			fscanf_s(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, SIZE_OF_CLIENT_NAME, &dollarAmountTemp);
		}
		fprintf_s(nfPtr, "%d %s %lf\n", accountNumOldMast, nameOldMast, currentBalanceOldMast);
		rewind(tfPtr);

		fscanf_s(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, SIZE_OF_CLIENT_NAME, &currentBalanceOldMast);
	}
	fclose(nfPtr);

	rewind(ofPtr);
	rewind(tfPtr);
	fscanf_s(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, SIZE_OF_CLIENT_NAME, &dollarAmountTemp);
	while (!feof(tfPtr)) {
		fscanf_s(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, SIZE_OF_CLIENT_NAME, &currentBalanceOldMast);
		notHaveInTrans = 1;
		while (!feof(ofPtr)) {
			if (accountNumOldMast == accountNumTemp) {
				notHaveInTrans = 0;
				break;
			}
			fscanf_s(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, SIZE_OF_CLIENT_NAME, &currentBalanceOldMast);
		}
		if (notHaveInTrans)
			printf("Unmatched transaction record for account nuber %d\n", accountNumTemp);

		rewind(ofPtr);
		fscanf_s(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, SIZE_OF_CLIENT_NAME, &dollarAmountTemp);
	}
	fclose(ofPtr);
	fclose(tfPtr);
}


void clearFile(const char fileName[]) 
{
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