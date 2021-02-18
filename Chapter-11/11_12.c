#include <stdio.h>
#include <string.h>

#define INSTRUMENT_NAME_SIZE 25
#define INSTRUMENT_COUNT 100 
#define RESPONSE_SIZE 4 

struct instrument {
	unsigned int id;
	char name[INSTRUMENT_NAME_SIZE];
	unsigned int count;
	long double price;
};

void initFile(const char[]);
void readData(FILE*, size_t);
void enterData(FILE*, size_t);
void deleteData(FILE*, size_t);
void updateData(FILE*, size_t);

int main(void) {
	unsigned int menuChoise;
	const char file[] = "hardware.dat";
	size_t sizeInstrument = sizeof(struct instrument);
	FILE *fPtr;

	initFile(file);
	fopen_s(&fPtr, file, "rb+");
	if (fPtr == NULL) {
		printf("Error open file %s\n", file);
		return -1;
	}

	while (1) {
		puts("\nEnter action:\n1 for enter data\n2 for delete data\n3 for update data\n4 for read data\n5 for exit");
		scanf_s("%u", &menuChoise);
		switch (menuChoise) {
			case 1:
				enterData(fPtr, sizeInstrument);
				break;
			case 2:
				deleteData(fPtr, sizeInstrument);
				break;
			case 3:
				updateData(fPtr, sizeInstrument);
				break;
			case 4:
				readData(fPtr, sizeInstrument);
				break;
			case 5:
				fclose(fPtr);
				return 0;
			default:
				printf("You enter not correct info - %u\n", menuChoise);
				break;
		}
	}

}


void updateData(FILE* fPtr, size_t sizeStruct)
{
	struct instrument tempStructInstrument;
	unsigned int updateId = 0;
	char response[RESPONSE_SIZE];

	while (1) {
		puts("Enter id for update:");
		scanf_s("%u", &updateId);
		fseek(fPtr, (updateId - 1) * sizeStruct, SEEK_SET);
		fread(&tempStructInstrument, sizeStruct, 1, fPtr);
		printf("You try update - %u %s %u %Lf\n", tempStructInstrument.id, tempStructInstrument.name, tempStructInstrument.count, tempStructInstrument.price);
		printf_s("Enter Yes / No for update:");
		scanf_s("%s", response, RESPONSE_SIZE);
		if (strcmp(response, "Yes") == 0) {
			tempStructInstrument = { 0, "", 0, 0.0 };
			printf("Enter data for id %u: ", updateId);
			tempStructInstrument.id = updateId;

			scanf_s("%s %u %Lf",  tempStructInstrument.name, INSTRUMENT_NAME_SIZE, &tempStructInstrument.count, &tempStructInstrument.price);
			printf("You enter: - %u %s %u %Lf\n", tempStructInstrument.id, tempStructInstrument.name, tempStructInstrument.count, tempStructInstrument.price);
			printf_s("Enter Yes / No for write:");
			scanf_s("%s", response, RESPONSE_SIZE);
			fseek(fPtr, (tempStructInstrument.id - 1) * sizeStruct, SEEK_SET);
			fwrite(&tempStructInstrument, sizeStruct, 1, fPtr);
			break;
		}
		else
			printf("Yor enter response - %s, begin now\n", response);
	}
}

void deleteData(FILE *fPtr, size_t sizeStruct)
{
	struct instrument tempStructInstrument;
	unsigned int deleteId = 0;
	char response[RESPONSE_SIZE];

	while (1) {
		puts("Enter id for delete:");
		scanf_s("%u", &deleteId);
		fseek(fPtr, (deleteId - 1) * sizeStruct, SEEK_SET);
		fread(&tempStructInstrument, sizeStruct, 1, fPtr);
		printf("You try delete - %u %s %u %Lf\n", tempStructInstrument.id, tempStructInstrument.name, tempStructInstrument.count, tempStructInstrument.price);
		printf_s("Enter Yes / No for delete:");
		scanf_s("%s", response, RESPONSE_SIZE);
		if (strcmp(response, "Yes") == 0) {
			tempStructInstrument = { 0, "", 0, 0.0 };
			fseek(fPtr, (deleteId - 1) * sizeStruct, SEEK_SET);
			fwrite(&tempStructInstrument, sizeStruct, 1, fPtr);
			break;
		}
		else
			printf("Yor enter response - %s, begin now\n", response);
	}
}

void enterData(FILE *fPtr, size_t sizeStruct)
{
	struct instrument tempStructInstrument;
	char response[RESPONSE_SIZE];
	while (1) {
		tempStructInstrument = { 0, "", 0, 0.0 };
		puts("Enter data:");
		scanf_s("%u %s %u %Lf", &tempStructInstrument.id, tempStructInstrument.name, INSTRUMENT_NAME_SIZE, &tempStructInstrument.count, &tempStructInstrument.price);
		printf("You enter: - %u %s %u %Lf\n", tempStructInstrument.id, tempStructInstrument.name, tempStructInstrument.count, tempStructInstrument.price);
		printf_s("Enter Yes / No for write:");
		scanf_s("%s", response, RESPONSE_SIZE);
		if (strcmp(response, "Yes") == 0) 
			break;
		else
			printf("Yor enter response - %s, begin now\n", response);
	}
	fseek(fPtr, (tempStructInstrument.id - 1) * sizeStruct, SEEK_SET);
	fwrite(&tempStructInstrument, sizeStruct, 1, fPtr);
}

void readData(FILE *fPtr, size_t sizeStruct)
{
	struct instrument tempStructInstrument;
	int i = 1;
	rewind(fPtr);
	while (!feof(fPtr)) {
		fread(&tempStructInstrument, sizeStruct, 1, fPtr);
		printf("%d  %u %s %u %Lf\n",i, tempStructInstrument.id, tempStructInstrument.name, tempStructInstrument.count, tempStructInstrument.price);
		i++;
	}
}


void initFile(const char file[])
{
	FILE *fPtr;
	fopen_s(&fPtr, file, "wb+");
	if (fPtr == NULL) {
		printf("Error open file %s\n", file);
		return;
	}

	struct instrument templateStruct = { 0, "", 0, 0.0 };
	struct instrument beginInstruments[] = { {3,"Electric sander", 7, 57.98}, {17,"Hammer", 16, 11.99}, {24, "Jig saw", 21, 11.00}, {39, "Lawn mower", 3, 79.50}, {56, "Power saw", 18, 99.99},
		{68, "Screwdriver", 106, 6.99}, {77, "Sledge hammer", 11, 21.50}, {83, "Wrench", 34, 7.50} };
	size_t sizeStruct =  sizeof(beginInstruments[0]);
	size_t countBeginStruct = sizeof(beginInstruments) / sizeStruct;

	//for (unsigned int i = 0, elemBeginStruct = 0, templWrite = 1; i < 100; templWrite = 1, i++) {
	//	for (unsigned int e = elemBeginStruct; e < countBeginStruct; e++) {
	//		if (beginStruct[e].id == i) {
	//			fwrite(&beginStruct[i], sizeStruct, 1, fPtr);
	//			printf("elemBeginStruct - %d\n", elemBeginStruct);
	//			printf("e - %d\n", e);
	//			elemBeginStruct = e;
	//			templWrite = 0;
	//			printf("Write elem %d\n", elemBeginStruct);
	//			break;
	//		}
	//		else if (i < beginStruct[e].id) {
	//			printf("Break %d\n", i);
	//			break;
	//		}
	//	}
	//	if (templWrite) {
	//		printf("Write template %d\n", i);
	//		fwrite(templateStruct, sizeStruct, 1, fPtr);
	//	}
	//}

	for (int i = 1; i < INSTRUMENT_COUNT; i++)
		fwrite(&templateStruct, sizeStruct, 1, fPtr);

	for (size_t s = 0; s < countBeginStruct; s++) {
		fseek(fPtr, (beginInstruments[s].id - 1)* sizeStruct, SEEK_SET);
		fwrite(&beginInstruments[s], sizeStruct, 1, fPtr);
	}
	fclose(fPtr);
}