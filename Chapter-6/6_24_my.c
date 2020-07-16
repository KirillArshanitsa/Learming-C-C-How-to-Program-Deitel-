#include <stdio.h>

void printFloor(int[][8]);
void go(int[][8], int[2]);

void printFloor(int floor[][8]) {
	for (int e = 0; e < 8; e++) {
		for (int i = 0; i < 8; i++) {
			printf("%d", floor[e][i]);
		}
		puts("");
	}
}

void go(int floor[][8], int currentPosition[2]) {
	//2 down 1 right or left
	if (currentPosition[0] + 2 < 8) {
		if ((floor[currentPosition[0] + 1][currentPosition[1]] == 0) && (floor[currentPosition[0] + 2][currentPosition[1]] == 0)) {
			//2 down 1 right
			if ((currentPosition[1] + 1) < 8) {
				if (floor[currentPosition[0] + 2][currentPosition[1] + 1] == 0) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] + 1][currentPosition[1]];
					++floor[currentPosition[0] + 2][currentPosition[1]];
					++floor[currentPosition[0] + 2][currentPosition[1] + 1];
					currentPosition[0] += 2;
					++currentPosition[1];
				}
			}
			//2 down 1 left
			else if ((currentPosition[1] - 1) >= 0) {
				if (floor[currentPosition[0] + 2][currentPosition[1] - 1] == 0) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] + 1][currentPosition[1]];
					++floor[currentPosition[0] + 2][currentPosition[1]];
					++floor[currentPosition[0] + 2][currentPosition[1] - 1];
					currentPosition[0] += 2;
					--currentPosition[1];
				}
			}
		}
	}

	//2 up 1 right or left
	if ((currentPosition[0] - 2) >= 0) {
		if ((floor[currentPosition[0] - 1][currentPosition[1]] == 0) && (floor[currentPosition[0] - 2][currentPosition[1]] == 0)) {
			//2 up 1 right
			if ((currentPosition[1] + 1) < 8) {
				if (floor[currentPosition[0] - 2][currentPosition[1] + 1] == 0) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] - 1][currentPosition[1]];
					++floor[currentPosition[0] - 2][currentPosition[1]];
					++floor[currentPosition[0] - 2][currentPosition[1] + 1];
					currentPosition[0] -= 2;
					++currentPosition[1];
				}
			}
			//2 up 1 left
			else if ((currentPosition[1] - 1) >= 0) {
				if (floor[currentPosition[0] - 2][currentPosition[1] - 1] == 0) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] - 1][currentPosition[1]];
					++floor[currentPosition[0] - 2][currentPosition[1]];
					++floor[currentPosition[0] - 2][currentPosition[1] - 1];
					currentPosition[0] -= 2;
					--currentPosition[1];
				}
			}
		}
	}

	//1 down 2 right or left
	if ((currentPosition[0] + 1) < 8) {
		if (floor[currentPosition[0] + 1][currentPosition[1]] == 0) {
			//1 down 2 right
			if ((currentPosition[1] + 2) < 8) {
				if ((floor[currentPosition[0] + 1][currentPosition[1] + 1] == 0) && (floor[currentPosition[0] + 1][currentPosition[1] + 2] == 0)) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] + 1][currentPosition[1]];
					++floor[currentPosition[0] + 1][currentPosition[1] + 1];
					++floor[currentPosition[0] + 1][currentPosition[1] + 2];
					currentPosition[1] += 2;
					++currentPosition[0];
				}
			}
			//1 down 2 left
			else if ((currentPosition[1] - 2) >= 0) {
				if ((floor[currentPosition[0] + 1][currentPosition[1] - 1] == 0) && (floor[currentPosition[0] + 1][currentPosition[1] - 2] == 0)) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] + 1][currentPosition[1]];
					++floor[currentPosition[0] + 1][currentPosition[1] - 1];
					++floor[currentPosition[0] + 1][currentPosition[1] - 2];
					currentPosition[1] -= 2;
					++currentPosition[0];
				}
			}
		}
	}

	//1 up 2 right or left
	if ((currentPosition[0] - 1) >= 0) {
		if (floor[currentPosition[0] - 1][currentPosition[1]] == 0) {
			//1 up 2 right
			if ((currentPosition[1] + 2) < 8) {
				if ((floor[currentPosition[0] - 1][currentPosition[1] + 1] == 0) && (floor[currentPosition[0] - 1][currentPosition[1] + 2] == 0)) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] - 1][currentPosition[1]];
					++floor[currentPosition[0] - 1][currentPosition[1] + 1];
					++floor[currentPosition[0] - 1][currentPosition[1] + 2];
					currentPosition[1] += 2;
					--currentPosition[0];
				}
			}
			//1 up 2 left
			else if ((currentPosition[1] - 2) >= 0) {
				if ((floor[currentPosition[0] - 1][currentPosition[1] - 1] == 0) && (floor[currentPosition[0] - 1][currentPosition[1] - 2] == 0)) {
					++floor[currentPosition[0]][currentPosition[1]];
					++floor[currentPosition[0] - 1][currentPosition[1]];
					++floor[currentPosition[0] - 1][currentPosition[1] - 1];
					++floor[currentPosition[0] - 1][currentPosition[1] - 2];
					currentPosition[1] -= 2;
					--currentPosition[0];
				}
			}
		}
	}

}

int main(void) {
	int floor[8][8] = { 0 };
	int currentPosition[2] = { 3,4 };//[0]- up, down [1] - right, left
	for (int i = 0; i <= 64; i++) {
		go(floor, currentPosition);
	}
	printFloor(floor);
	printf("\n\n%d %d", currentPosition[0], currentPosition[1]);
	return 0;
}