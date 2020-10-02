#include<stdio.h>
#include<string.h>

int main(void) {
	int intRegionCode;
	long longTelNum;
	char str[14];
	char resultStr[12] = {};
	char* regioneCode;
	char* firstPartNum;
	char* secondPartNum;
	char* nextToken = NULL;

	puts("Enter phone nun for example (555)555-5555:");
	gets_s(str);

	regioneCode = strtok_s(strtok_s(str, "(", &nextToken), ")", &nextToken);
	//puts(regioneCode);
	firstPartNum = strtok_s(NULL, "-", &nextToken);
	//puts(firstPartNum);
	secondPartNum = strtok_s(NULL, "-", &nextToken);
	//puts(secondPartNum);

	strcat_s(resultStr, 12, regioneCode);
	strcat_s(resultStr, 12, " ");
	strcat_s(resultStr, 12, firstPartNum);
	strcat_s(resultStr, 12, secondPartNum);
	printf("Numer - %s\n", resultStr);
	sscanf_s(resultStr, "%d%ld", &intRegionCode, &longTelNum);
	printf("RegionCode %d TelNum %ld\n",intRegionCode, longTelNum);
	//(812)123-4567
}