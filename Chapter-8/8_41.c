#include <stdio.h>
#include <string.h>
#define LETTERS_COUNT 5
#define CLIENT_NAME_LEHGHT 20
#define CLIENT_ADRESS_LEHGHT 30
#define SIZE_OF_NUM 100
#define TEXT_LETTER_SIZE 500

void getCleientInfo(const char *[]);

int main(void) 
{
	const char *letters[LETTERS_COUNT] = {"According to our records, the sum of $[MONEY] is still outstanding on your account. We trust that our service was to your satisfaction, and we would appreciate your cooperation in resolving this matter as soon as possible.", 
	"I wrote to you regarding your company’s unpaid account, amounting to $[MONEY]. May we please remind you that this amount is still outstanding. We would be grateful to receive a bank transfer in full settlement without further delay.",
	"I wish to draw your attention to my previous emails about the overdue payment on your account. We are very concerned that the matter has not yet received your attention. Clearly, this situation cannot be allowed to continue, and we trust urge you to take immediate action to settle your account. Sum of $[MONEY]",
	"Following my emails. I must inform you that we have still not received payment for the outstanding sum of $[MONEY] . Unless we receive payment within seven days we shall have no alternative but to take legal action to recover the money. In the meantime, your existing credit facilities have been suspended."};
	getCleientInfo(letters);
	
	return 0;
}


void getCleientInfo(const char *letters[])
{
	char name[CLIENT_NAME_LEHGHT];
	char adress[CLIENT_ADRESS_LEHGHT];
	char strNum[SIZE_OF_NUM];
	char letterText[TEXT_LETTER_SIZE] = "Dear ";
	unsigned long int accountNumber;
	unsigned long int debt;
	short ageDebt;
	const char *replacedDebtPtr;

	puts("Enter client data.");
	puts("Enter client name:");
	gets_s(name);
	puts("Enter client adress:");
	gets_s(adress);
	puts("Enter account number:");
	scanf_s("%ul", &accountNumber);
	puts("Enter debt:");
	scanf_s("%ul", &debt);
	do {
		puts("Enter age of debt between 1-4:");
		scanf_s("%hd", &ageDebt);
	} while ((ageDebt <= 0) || (ageDebt > 4));
	--ageDebt;
	strcat_s(letterText, TEXT_LETTER_SIZE, name);
	strcat_s(letterText, TEXT_LETTER_SIZE, "\nAdress: ");
	strcat_s(letterText, TEXT_LETTER_SIZE, adress);
	strcat_s(letterText, TEXT_LETTER_SIZE, "\nAccount Number: ");
	sprintf_s(strNum, "%lu\n", accountNumber);
	strcat_s(letterText, TEXT_LETTER_SIZE, strNum);
	replacedDebtPtr = strstr(letters[ageDebt], "$[MONEY]");
	strncat_s(letterText, letters[ageDebt], replacedDebtPtr - letters[ageDebt]);
	sprintf_s(strNum, "%lu", debt);
	strcat_s(letterText, TEXT_LETTER_SIZE, strNum);
	strcat_s(letterText, TEXT_LETTER_SIZE, replacedDebtPtr + 8); // 8 - size of $[MONEY]
	puts("\nResult:");
	puts(letterText);
}