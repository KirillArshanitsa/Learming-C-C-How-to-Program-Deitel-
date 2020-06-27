#include <stdio.h>

int main(void) {
	int counts[10] = { 0 };
	int bonus[15];
	double monthlyTemperatures[12];
	int bestScores[5];

	for (int e = 0; e < 15; e++)
		++bonus[e];

	for (int e = 0; e < 12; e++) {
		puts("Enter value in array:");
		scanf_s("%lf", &monthlyTemperatures[e]);
	}
	//for (int e = 0; e < 12; e++) {
	//	printf("%f\n", monthlyTemperatures[e]);
	//}
	puts("");
	for (int e = 0; e < 5; e++) {
		printf("%d\n", bestScores[e]);
	}

	return 0;
}#include <stdio.h>

int main(void) {
	int counts[10] = { 0 };
	int bonus[15];
	double monthlyTemperatures[12];
	int bestScores[5];

	for (int e = 0; e < 15; e++)
		++bonus[e];

	for (int e = 0; e < 12; e++) {
		puts("Enter value in array:");
		scanf_s("%lf", &monthlyTemperatures[e]);
	}
	//for (int e = 0; e < 12; e++) {
	//	printf("%f\n", monthlyTemperatures[e]);
	//}
	puts("");
	for (int e = 0; e < 5; e++) {
		printf("%d\n", bestScores[e]);
	}

	return 0;
}