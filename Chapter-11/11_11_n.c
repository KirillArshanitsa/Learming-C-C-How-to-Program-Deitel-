#include <stdio.h>
#include <string.h>

#define NAME_STR_SIZE 15
#define AGE_STR_SIZE 3

struct person {
	char lastName[NAME_STR_SIZE];
	char firstName[NAME_STR_SIZE];
	char age[AGE_STR_SIZE];
};

void a(const char[]);
void b(const char[]);
void c(const char[], const char[], unsigned int);
void d(const char[], struct person *, unsigned int);
void readData(const char[]);

int main(void)
{
	const char fileName[] = "nameage.dat";
	struct person testPerson = { "Testovich", "Test", "35" };
	a(fileName);
	b(fileName);
	puts("Read data");
	readData(fileName);

	c(fileName, "Tom", 2);
	puts("\n\nRead data");
	readData(fileName);

	d(fileName, &testPerson, 3);
	puts("\n\nRead data");
	readData(fileName);
	return 0;
}

void d(const char fileName[], struct person *personPtr, unsigned int id)
{
	FILE *filePtr;
	char lastNameL[NAME_STR_SIZE];
	char firstNameL[NAME_STR_SIZE];
	char ageL[AGE_STR_SIZE];

    filePtr = fopen( fileName, "r+");
	if (filePtr == NULL) {
		printf("Error open file %s", fileName);
		return;
	}

	for (unsigned int i = 0; !feof(filePtr); i++) {
		fscanf(filePtr, "%s %s %s", lastNameL, firstNameL, ageL);
		printf("%d %s %s %s\n",i, lastNameL, firstNameL, ageL);
		if (i == id) {
			//fprintf(filePtr, "%s %s %s\n", personPtr->lastName, personPtr->firstName, personPtr->age);
            fprintf(filePtr, "%s %s %s\n", personPtr->lastName, personPtr->firstName, personPtr->age);
            break;
		}
	}

	fclose(filePtr);
}

void c(const char fileName[], const char lastNameM[], unsigned int id)
{
	FILE *filePtr;
	char str[55];
	unsigned int fileId;
	char lastName[NAME_STR_SIZE];
	char firstName[NAME_STR_SIZE];
	char age[AGE_STR_SIZE];
	unsigned int currentId = 0;

    filePtr = fopen(fileName, "r+");
	if (filePtr == NULL) {
		printf("Error open file %s", fileName);
		return;
	}

	while (!feof(filePtr)) {
		fscanf(filePtr, "%s %s %s", lastName,  firstName, age);
		if (currentId == id) {
			if (strcmp(lastName, "Userovich_2") == 0)
				puts("No info");
			fprintf(filePtr, "%s %s %s\n", lastNameM, firstName, age);
			break;
		}
		currentId++;
	}
	fclose(filePtr);
}

void readData(const char fileName[])
{
	FILE *filePtr;
	char str[55];
    filePtr = fopen(fileName, "r");
	if (filePtr == NULL) {
		printf("Error open file %s", fileName);
		return;
	}
	while (!feof(filePtr)) {
		if (fgets(str, 55, filePtr))
			printf(str);
	}
	fclose(filePtr);

}

void a(const char fileName[])
{
	FILE* filePtr;
	struct person tmpPerson = { "unassigned", "","0" };
    filePtr = fopen(fileName, "w");

	if (filePtr == NULL) {
		puts("Error open file nameage.dat");
		return;
	}
	for (int i = 0; i < 100; i++)
		fprintf(filePtr, "%s %s %s\n", tmpPerson.lastName, tmpPerson.firstName, tmpPerson.age);
	fclose(filePtr);
}


void b(const char fileName[])
{
	FILE* filePtr;
	char lastName[NAME_STR_SIZE];
	char firstName[NAME_STR_SIZE];
	char age[AGE_STR_SIZE];

    filePtr = fopen(fileName, "w");
	if (filePtr == NULL) {
		puts("Error open file nameage.dat");
		return;
	}
	for (int i = 0; i < 10; i++) {
		sprintf(lastName, "Userovich_%d", i);
		sprintf(firstName, "User_%d", i);
		sprintf(age, "%d", i);
		fprintf(filePtr, "%s %s %s\n", lastName, firstName, age);
	}

	fclose(filePtr);
}
