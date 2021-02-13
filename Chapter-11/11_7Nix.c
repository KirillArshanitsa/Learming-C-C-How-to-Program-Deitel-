#include <stdio.h>
#include <string.h>
#define SIZE_OF_CLIENT_NAME 25

void generateTestData(const char[], int, int);
void readTestData(const char[]);
void clearFile(const char[]);
void compareTransactions(const char[], const char[], const char[]);


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

    ofPtr = fopen(oldmast, "r");
    tfPtr = fopen(trans, "r");
    nfPtr = fopen(newmast, "w");

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

    fscanf(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, &currentBalanceOldMast);
    while (!feof(ofPtr)) {
        fscanf(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, &dollarAmountTemp);
        while (!feof(tfPtr)) {
            if (accountNumOldMast == accountNumTemp)
                currentBalanceOldMast += dollarAmountTemp;
            fscanf(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, &dollarAmountTemp);
        }
        fprintf(nfPtr, "%d %s %lf\n", accountNumOldMast, nameOldMast, currentBalanceOldMast);
        rewind(tfPtr);

        fscanf(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, &currentBalanceOldMast);
    }
    fclose(nfPtr);

    rewind(ofPtr);
    rewind(tfPtr);
    fscanf(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, &dollarAmountTemp);
    while (!feof(tfPtr)) {
        fscanf(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, &currentBalanceOldMast);
        notHaveInTrans = 1;
        while (!feof(ofPtr)) {
            if (accountNumOldMast == accountNumTemp) {
                notHaveInTrans = 0;
                break;
            }
            fscanf(ofPtr, "%d%s%lf", &accountNumOldMast, nameOldMast, &currentBalanceOldMast);
        }
        if (notHaveInTrans)
            printf("Unmatched transaction record for account nuber %d\n", accountNumTemp);

        rewind(ofPtr);
        fscanf(tfPtr, "%d%s%lf", &accountNumTemp, nameTemp, &dollarAmountTemp);
    }
    fclose(ofPtr);
    fclose(tfPtr);
}


void clearFile(const char fileName[])
{
    FILE* filePtr;
    filePtr = fopen(fileName, "w");
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
    filePtr = fopen( fileName, "r");

    if (filePtr == NULL) {
        printf("Error open file %s", fileName);
        return;
    }

    printf("%-10s%-13s%s\n", "Account", "Name", "DollarAmount");
    fscanf(filePtr, "%d%s%lf", &accountNum, name, &dollarAmount);
    while (!feof(filePtr)) {
        printf("%-10d%-13s%-7.2lf\n", accountNum, name, dollarAmount);
        fscanf(filePtr, "%d%s%lf", &accountNum, name, &dollarAmount);
    }
    fclose(filePtr);
}


void generateTestData(const char fileName[], int beginVal, int endVal)
{
    FILE *filePtr;
    int accountNum;
    double dollarAmount;
    char userName[SIZE_OF_CLIENT_NAME];
    filePtr= fopen(fileName, "a");

    if (filePtr == NULL) {
        printf("Error open file %s", fileName);
        return;
    }

    while (beginVal <= endVal) {
        sprintf(userName, "User_%d", beginVal);
        accountNum = beginVal;
        dollarAmount = beginVal * 1.0;
        fprintf(filePtr, "%d %s %lf\n", accountNum, userName, dollarAmount);
        beginVal++;
    }
    fclose(filePtr);
}