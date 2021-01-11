#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STR_SIZE 50
#define UNIT_MAX_SIZE 15
#define SYSTEMS_ELEM_COUNT 5


void getUnitsInfo(const char[], char[], char[], unsigned long int *);
char getMeasuringSystem(const char*[], const char*[], const char[], char*, char*);

//https://infotables.ru/fizika/42-edinitsy-izmereniya/136-edinitsy-izmereniya-anglo-amerikanskaya-sistema-mer-ves-ploshchad-ob-em
//TODO rewrite this. Bad solution!!!!!!!

int main(void)
{
	char unitToTransfer[UNIT_MAX_SIZE];
	char transferedUnit[UNIT_MAX_SIZE];
	char metric = 0;
	char eng = 0;
	unsigned long int numOfTransferedUnit = 1;
	char unitToTransferListNum; //save val of number list  system. get in getMeasuringSystem() 
	char transferedUnitListNum; //save val of number list  system. get in getMeasuringSystem() 
	//char questStr[STR_SIZE] = "How many inches are in 2 centimeters";
	char questStr[STR_SIZE];

	const char *engSystem[SYSTEMS_ELEM_COUNT] = { "inches", "inches", "inches", "quart", "feet" };
	const char *metricSystem[SYSTEMS_ELEM_COUNT] = {"millimeters", "centimeters", "meters", "liters", "kilograms" };
	double engToMetric[SYSTEMS_ELEM_COUNT] = { 0.00254, 0.0254, 2.54, 1.05669, 1365 };
	double metricToEng[SYSTEMS_ELEM_COUNT] = { 0.03937, 0.3937, 39.37 };
	const char checkMatchingUnits[SYSTEMS_ELEM_COUNT] = {1,1,1,0,0};


	puts("Enter query. For example - How many inches are in 2 meters");
	gets_s(questStr);

	getUnitsInfo(questStr, unitToTransfer, transferedUnit, &numOfTransferedUnit);
	unitToTransferListNum = getMeasuringSystem(engSystem, metricSystem, unitToTransfer, &metric, &eng);
	transferedUnitListNum = getMeasuringSystem(engSystem, metricSystem, transferedUnit, &metric, &eng);

	puts("Result:");
	if ((unitToTransferListNum == 0) && (transferedUnitListNum)){
		if (checkMatchingUnits[metric]) {
			printf("%f\n", engToMetric[metric] * numOfTransferedUnit);
			return 0;
		}
	}
	else if ((unitToTransferListNum) && (transferedUnitListNum ==0)) {
		if (checkMatchingUnits[eng]) {
			printf("%f\n", metricToEng[eng] * numOfTransferedUnit);
			return 0;
		}
	}
	printf("Error parse string - %s. Find %s and %s\n", questStr, unitToTransfer, transferedUnit);
	return -1;
}


// return list number 0 - eng 1 -metric
char getMeasuringSystem(const char *engSystem[], const char *metricSystem[], const char unit[], char *metricPtr, char *engPtr)
{
	for (unsigned int e = 0; e < SYSTEMS_ELEM_COUNT; e++) {
		if (strcmp(engSystem[e], unit))
			continue;
		else {
			*engPtr = e;
			return 0;
		}
	}

	for (unsigned int e = 0; e < SYSTEMS_ELEM_COUNT; e++) {
		if (strcmp(metricSystem[e], unit))
			continue;
		else {
			*metricPtr = e;
			return 1;
		}
	}
	return -1;	
}

void getUnitsInfo(const char questStr[], char unitToTransfer[], char transferedUnit[], unsigned long int *numOfTransferedUnit)
{
	const char *unitToTransferPtr = questStr + 9;// + 9 size of - How many + space
	const char *transferedUnitPtr = strrchr(questStr, ' ') + 1;
	unsigned long int tmpNum;
	char num[UNIT_MAX_SIZE];
	size_t sizeList = UNIT_MAX_SIZE - 1;

	strncpy_s(unitToTransfer, UNIT_MAX_SIZE, unitToTransferPtr, strstr(unitToTransferPtr, " ") - unitToTransferPtr);
	strcpy_s(transferedUnit, UNIT_MAX_SIZE, transferedUnitPtr);
	for (size_t transferedUnitSize = strlen(transferedUnit) + 1, strSize = strlen(questStr) - 1; isdigit(questStr[strSize - transferedUnitSize]); transferedUnitSize++) // + - - space
		num[--sizeList] = questStr[strSize - transferedUnitSize];

	num[UNIT_MAX_SIZE - 1] = '\0';
	strncpy_s(num, UNIT_MAX_SIZE, num + sizeList, sizeList);
	tmpNum = strtoul(num, NULL, 10);
	if (tmpNum)
		*numOfTransferedUnit = tmpNum;
}
