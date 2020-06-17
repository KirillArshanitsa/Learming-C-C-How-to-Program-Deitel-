#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
	double num;
	double num2;
	//srand(time(NULL));
	int maxCount = 10;

	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("sqrt(%f)=%f\n", num, sqrt(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("exp(%f)=%f\n", num, exp(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("log(%f)=%f\n", num, log(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("log10(%f)=%f\n", num, log10(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("fabs(%f)=%f\n", num, fabs(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("ceil(%f)=%f\n", num, ceil(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("floor(%f)=%f\n", num, floor(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		num2 = rand();
		printf("pow(%f)=%f\n", num, pow(num, num2));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		num2 = rand();
		printf("fmod(%f)=%f\n", num, fmod(num, num2));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("sin(%f)=%f\n", num, sin(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("cos(%f)=%f\n", num, cos(num));
	}
	puts("");
	for (int i = 0; i < maxCount; i++) {
		num = rand();
		printf("tan(%f)=%f\n", num, tan(num));
	}
	return 0;
}
