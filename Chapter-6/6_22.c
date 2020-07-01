#include <stdio.h>
#include <stdlib.h>

void getStatistics(int[][4]);
void printArray(int[][4]);
void insertData(int[][4]);

void getStatistics(int sales[][4]) {
	int sumIn;
	int sumEx[4] = {0};
	printf("  ");
	for (int ext = 0; ext < 4; ext++) {
		printf("%7d ", ext + 1);
	}
	puts("");
	for (int ext = 0; ext < 5; ext++) {
		printf("%d ", ext +1);
		sumIn = 0;
		for (int in = 0; in < 4; in++) {
			printf(" %6d ",sales[ext][in]);
			sumIn += sales[ext][in];
			sumEx[in] += sales[ext][in];
		}
		printf("%10d\n", sumIn);	
	}
	printf("\n  ");
	for (int ext = 0; ext < 4; ext++) {
		printf("%7d ", sumEx[ext]);
	}
}

void printArray(int sales[][4]) {
	for (int ext = 0; ext < 5; ext++) {
		for (int in = 0; in < 4; in++) {
			printf("Product %d  sales %d  momey %d\n", ext, in, sales[ext][in]);
		}
		puts("");
	}
}

void insertData(int sales[][4]) {
	for (int ext = 0; ext < 5; ext++) {
		for (int in = 0; in < 4; in++) {
			sales[ext][in] = rand();
		}
	}
}

int main(void) {
	int sales[5][4] = { 0 };
	insertData(sales);
	//printArray(sales);
	getStatistics(sales);
	return 0;
}