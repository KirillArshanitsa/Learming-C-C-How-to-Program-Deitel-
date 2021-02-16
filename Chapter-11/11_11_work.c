#include <stdio.h>
#include <string.h>

#define NAME_STR_SIZE 15
#define AGE_STR_SIZE 3

struct person {
	char lastName[NAME_STR_SIZE];
	char firstName[NAME_STR_SIZE];
	char age[AGE_STR_SIZE];
};

void readData(const char[], size_t);

int main(void)
{
	const char fileName[] = "nameage.dat";
	struct person templatePerson = { "unassigned", "", "0" };
	struct person updatePerson = { "UpdateUser", "UserUpdated", "50" };
	struct person delPerson = { "DelUser", "UserDel", "10" };
	struct person testPerson;
	char lastNameL[NAME_STR_SIZE];
	char firstNameL[NAME_STR_SIZE];
	char ageL[AGE_STR_SIZE];
	unsigned int updatePersonNum = 4;
	unsigned int deletedPersonNum = 5;

	size_t prsonSize = sizeof (struct person);
	FILE *filePtr;
	errno_t errorF = fopen_s(&filePtr, fileName, "wb");

	if (filePtr == NULL) {
		printf("Error open file %s\n", fileName);
		return -1;
	}

	//a
	for (int i = 0; i < 100; i++)
		fwrite(&templatePerson, prsonSize, 1, filePtr);
	rewind(filePtr);
	//b
	for (int i = 0; i < 10; i++) {
		sprintf_s(lastNameL, "Testovich_%d", i);
		sprintf_s(firstNameL, "Test_%d", i);
		sprintf_s(ageL, "%d", i);
		strcpy_s(testPerson.lastName, lastNameL);
		strcpy_s(testPerson.firstName, firstNameL);
		strcpy_s(testPerson.age, ageL);
		fwrite(&testPerson, prsonSize, 1, filePtr);
	}
	rewind(filePtr);
	//c
	fseek(filePtr, (updatePersonNum - 1) * prsonSize, SEEK_SET );
	fread(&templatePerson, prsonSize, 1, filePtr);
	if (strcmp(templatePerson.firstName, "") == 0)
		puts("No info");
	fseek(filePtr, (updatePersonNum - 1) * prsonSize, SEEK_SET);
	fwrite(&updatePerson, prsonSize, 1, filePtr);
	rewind(filePtr);
	//d
	fseek(filePtr, (deletedPersonNum - 1) * prsonSize, SEEK_SET);
	fwrite(&delPerson, prsonSize, 1, filePtr);

	fclose(filePtr);
	puts("\n\nRead data:");
	readData(fileName, prsonSize);

	return 0;
}



void readData(const char fileName[], size_t size) 
{
	struct person testPerson;
	FILE *filePtr;
	fopen_s(&filePtr, fileName, "r");
	if (filePtr == NULL) {
		printf("Error open file %s", fileName);
		return;
	}
	while (!feof(filePtr)) {
		fread(&testPerson, size, 1, filePtr);
		printf("%s %s %s\n", testPerson.lastName, testPerson.firstName, testPerson.age);
	}
	fclose(filePtr);

}

