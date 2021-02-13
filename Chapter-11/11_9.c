#include <stdio.h>
#include <string.h>
#define SIZE_OF_CLIENT_NAME 23
#define SIZE_OF_ACOOUNT_INFO_STR 60

struct Account {
    int accountNum;
    char name[SIZE_OF_CLIENT_NAME];
    double dollarAmount;
};

struct Transaction {
    int accountNum;
    double dollarAmount;
};

void generateMainTestData(const char[], const struct Account[], unsigned );
void generateTransactionData(const char[], const struct Transaction[], unsigned);
void readTestData(const char[]);
void compareTransactions(const char[], const char[], const char[]);


int main(void)
{
    const char oldmast[] = "oldmast.dat";
    const char trans[] = "trans.dat";
    const char newmast[] = "newmast.dat";

    struct Account listMain[] = {{100, "Alan Jones", 348.17},{300, "Mary Smith",27.19},
            {500, "Sam Sharp",0.0},{700,"Suzy Green", -14.22} };
    struct Transaction listTransaction[] = {{100, 27.14}, {300, 62.11}, {400, 100.56},
                                            {900, 82.17}};

    puts("Generate test data");
    generateMainTestData(oldmast, listMain, sizeof(listMain) / sizeof(listMain[0]));
    puts("Generate test transactions");
    generateTransactionData(trans, listTransaction, sizeof(listTransaction) / sizeof(listTransaction[0]));

    puts("\nRead test data");
    readTestData(oldmast);
    puts("\nRead test transactions data");
    readTestData(trans);

    puts("\n\nCompare transactions");
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
    char firstNameOldMast[SIZE_OF_CLIENT_NAME];
    char lastNameOldMast[SIZE_OF_CLIENT_NAME];
    double currentBalanceOldMast;
    int accountNumTemp;
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

    fscanf(ofPtr, "%d%s%s%lf", &accountNumOldMast, firstNameOldMast, lastNameOldMast, &currentBalanceOldMast);
    while (!feof(ofPtr)) {
        fscanf(tfPtr, "%d%lf", &accountNumTemp, &dollarAmountTemp);
        while (!feof(tfPtr)) {
            if (accountNumOldMast == accountNumTemp)
                currentBalanceOldMast += dollarAmountTemp;
            fscanf(tfPtr, "%d%lf", &accountNumTemp, &dollarAmountTemp);
        }
        strcat(firstNameOldMast, " ");
        strcat(firstNameOldMast, lastNameOldMast);
        fprintf(nfPtr, "%d %s %lf\n", accountNumOldMast, firstNameOldMast, currentBalanceOldMast);
        rewind(tfPtr);

        fscanf(ofPtr, "%d%s%s%lf", &accountNumOldMast, firstNameOldMast, lastNameOldMast, &currentBalanceOldMast);
    }
    fclose(nfPtr);

    rewind(ofPtr);
    rewind(tfPtr);
    fscanf(tfPtr, "%d%lf", &accountNumTemp, &dollarAmountTemp);
    while (!feof(tfPtr)) {
        fscanf(ofPtr, "%d%s%s%lf", &accountNumOldMast, firstNameOldMast, lastNameOldMast, &currentBalanceOldMast);
        notHaveInTrans = 1;
        while (!feof(ofPtr)) {
            if (accountNumOldMast == accountNumTemp) {
                notHaveInTrans = 0;
                break;
            }
            fscanf(ofPtr, "%d%s%s%lf", &accountNumOldMast, firstNameOldMast, lastNameOldMast, &currentBalanceOldMast);
        }
        if (notHaveInTrans)
            printf("Unmatched transaction record for account nuber %d\n", accountNumTemp);

        rewind(ofPtr);
        fscanf(tfPtr, "%d%lf", &accountNumTemp, &dollarAmountTemp);
    }
    fclose(ofPtr);
    fclose(tfPtr);
}



void readTestData(const char fileName[])
{
    FILE *filePtr;
    char str[SIZE_OF_ACOOUNT_INFO_STR];
    filePtr = fopen( fileName, "r");

    if (filePtr == NULL) {
        printf("Error open file %s", fileName);
        return;
    }
    while (!feof(filePtr)) {
        if(fgets(str, SIZE_OF_ACOOUNT_INFO_STR, filePtr))
            printf("%s", str);
    }
    fclose(filePtr);
}


void generateMainTestData(const char fileName[], const struct Account acoountList[], unsigned int size)
{
    FILE *filePtr;
    filePtr= fopen(fileName, "w");

    if (filePtr == NULL) {
        printf("Error open file %s", fileName);
        return;
    }

    for (int i = 0; i < size; i++)
        fprintf(filePtr, "%d %s %lf\n", acoountList[i].accountNum, acoountList[i].name, acoountList[i].dollarAmount);

    fclose(filePtr);
}

void generateTransactionData(const char fileName[], const struct Transaction transactionList[], unsigned int size)
{
    FILE *filePtr;
    filePtr= fopen(fileName, "w");

    if (filePtr == NULL) {
        printf("Error open file %s", fileName);
        return;
    }

    for (int i = 0; i < size; i++)
        fprintf(filePtr, "%d %lf\n", transactionList[i].accountNum, transactionList[i].dollarAmount);

    fclose(filePtr);
}
