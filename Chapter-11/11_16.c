#include <stdio.h>
#include <string.h>

int main(void) 
{
	FILE *fPtr;
	const char fileName[] = "datasize.dat";

	fopen_s(&fPtr, fileName, "w");
	if (fPtr == NULL) {
		printf("Error open file %s\n", fileName);
		return -1;
	};

	fprintf_s(fPtr, "%-20s%s\n","Data type", "Size");

	fprintf_s(fPtr, "%-23s%zu\n", "char", sizeof(char));
	fprintf_s(fPtr, "%-23s%zu\n", "unsigned char", sizeof(unsigned char));
	fprintf_s(fPtr, "%-23s%zu\n", "short int", sizeof(short int));
	fprintf_s(fPtr, "%-23s%zu\n", "unsigned short int", sizeof(unsigned short int));
	fprintf_s(fPtr, "%-23s%zu\n", "int", sizeof(int));
	fprintf_s(fPtr, "%-23s%zu\n", "unsigned int", sizeof(unsigned int));
	fprintf_s(fPtr, "%-23s%zu\n", "long int", sizeof(long int));
	fprintf_s(fPtr, "%-23s%zu\n", "unsigned long int", sizeof(unsigned long int));
	fprintf_s(fPtr, "%-23s%zu\n", "float", sizeof(float));
	fprintf_s(fPtr, "%-23s%zu\n", "double", sizeof(double));
	fprintf_s(fPtr, "%-23s%zu\n", "long double", sizeof(long double));

	fclose(fPtr);

	return 0;
}