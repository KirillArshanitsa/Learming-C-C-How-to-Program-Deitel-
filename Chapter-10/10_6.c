#include <stdio.h>

struct customer{
    char lastName[15];
    char firstName[15];
    int customerNumber;
    struct {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord = {"Kirill", "A", 4, {"123-456", "3", "SPB",
                                       "N/A", "192283"}}, *customerPtr;

int main(void) {

    customerPtr = &customerRecord;

    printf("%s\n", customerRecord.lastName);
    printf("%s\n", customerPtr -> lastName);
    printf("%s\n", customerRecord.firstName);
    printf("%s\n", customerPtr -> firstName);
    printf("%d\n", customerRecord.customerNumber);
    printf("%d\n", customerPtr -> customerNumber);
    printf("%s\n", customerRecord.personal.phoneNumber);
    printf("%s\n", customerPtr -> personal.phoneNumber);
    printf("%s\n", customerRecord.personal.address);
    printf("%s\n", customerPtr -> personal.address);
    printf("%s\n", customerRecord.personal.city);
    printf("%s\n", customerPtr -> personal.city);
    printf("%s\n", customerRecord.personal.state);
    printf("%s\n", customerPtr -> personal.state);
    printf("%s\n", customerRecord.personal.zipCode);
    printf("%s\n", customerPtr -> personal.zipCode);

    return 0;
}

