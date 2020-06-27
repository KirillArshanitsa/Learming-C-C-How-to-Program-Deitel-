#include <stdio.h>

int main(void) {
	int sales[3][5];

	for (int row = 0; row <= 2; row++) {
		for (int column = 0; column <= 4; column++) {
			printf("[%d] [%d] = 0\n", row, column);
			sales[row][column] = 0;
		}
	}
	return 0;
}