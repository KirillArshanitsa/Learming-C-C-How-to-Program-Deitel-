#include <stdio.h>

enum Position { RIGHT, LEFT, UP, DOWN };
void printGraph(int[][50]);
void parseComands(int[], int[][50], int[3]);
void drawLine(int, int[][50], int[3], enum Position);



void printGraph(int floor [][50] ) {
	for (int ext = 0; ext < 50; ext++) {
		for (int in = 0; in < 50; in++) {
			printf("%d", floor[ext][in]);
			//if (floor[ext][in])
			//	printf("%s", "*");
			//else
			//	printf("%s", " ");
		}
		puts("");
	}
}

void drawLine(int count, int floor[][50], int flagAndPosition[3], enum Position currentStatus) {

	if (RIGHT == currentStatus) {
		while (count--) {
			++floor[flagAndPosition[1]][flagAndPosition[2]];
			++flagAndPosition[2];
		}
	}
	else if (LEFT == currentStatus) {
		while (count--) {
			++floor[flagAndPosition[1]][flagAndPosition[2]];
			--flagAndPosition[2];
		}
	}
	else if (UP == currentStatus) {
		while (count--) {
			++floor[flagAndPosition[1]][flagAndPosition[2]];
			--flagAndPosition[1];
		}
	}
	else if (DOWN == currentStatus) {
		while (count--) {
			++floor[flagAndPosition[1]][flagAndPosition[2]];
			++flagAndPosition[1];
		}
	}
}

void parseComands(int comands[], int floor[][50], int flagAndPosition[3]) {
	enum Position curPosition = UP;
	for (int e = 0; comands[e] != 9; e++)
	{
		switch (comands[e]) {
			case 1:
				flagAndPosition[0] = 1;
				break;
			case 2:
				flagAndPosition[0] = 0;
				break;
			case 3:
				curPosition = RIGHT;
				break;
			case 4:
				curPosition = LEFT;
				break;
			case 5:
				++e;
				if (flagAndPosition[0] == 0) {
					drawLine(comands[e], floor, flagAndPosition, curPosition);

						//for (int i = comands[e]; i > 0; i--) {
						//	++floor[flagAndPosition[1]][flagAndPosition[2]];
						//	--flagAndPosition[1];
						//}
						//for (int i = comands[e]; i > 0; i--) {
						//	++floor[flagAndPosition[1]][flagAndPosition[2]];
						//	++flagAndPosition[2];
						//}
						//for (int i = comands[e]; i > 0; i--) {
						//	++floor[flagAndPosition[1]][flagAndPosition[2]];
						//	++flagAndPosition[1];
						//}
						//for (int i = comands[e]; i > 0; i--) {
						//	++floor[flagAndPosition[1]][flagAndPosition[2]];
						//	--flagAndPosition[2];
						//}
				}	
				break;
			case 6:
				printGraph(floor);
				break;
		}
	}


	
}

int main(void) {
	int floor[50][50] = { 0 };
	int flagAndPosition[3] = { 0, 20, 20 };
	int commands [30]= {2, 5, 12, 3, 5 ,12,  3, 5 ,12, 6, 9};

	parseComands(commands, floor, flagAndPosition);

	//printf("\n\n%d %d", flagAndPosition[1], flagAndPosition[2]);
	return 0;
}