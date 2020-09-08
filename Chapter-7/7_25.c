#include <stdio.h>
#define LINE 12
#define COLUMN 12

void createLabyrinth(char[][COLUMN], const int[], const int);
void printLabyrinth(char[][COLUMN]);
void mazeTraverse(char[][COLUMN], const int[]);

void printLabyrinth(char labyrinthBoard[][COLUMN]) {
	puts("");
	for (int e = 0; e < LINE; e++) {
		for (int i = 0; i < COLUMN; i++) {
			printf("%c", labyrinthBoard[e][i]);
		}
		puts("");
	}
}

void createLabyrinth(char labyrinthBoard[][COLUMN], const int pointLabyrinth[], const int pointLabyrinthSize) {

	for (int e = 0; e < pointLabyrinthSize; e++) {
		labyrinthBoard[(pointLabyrinth[e] - 1) / LINE][(pointLabyrinth[e] - 1) % COLUMN] = '.';
	}

	for (int e = 0; e < LINE; e++) {
		for (int i = 0; i < COLUMN; i++) {
			if (labyrinthBoard[e][i] != '.')
				labyrinthBoard[e][i] = '#';
		}
	}
}

void mazeTraverse(char labyrinthBoard[][COLUMN], const int enterPoint[2]) {
	static int beforePosition[2] = { -1,-1 };
	printLabyrinth(labyrinthBoard);

	//check up down
	if ((enterPoint[0] > 0) && (enterPoint[0] < LINE)) {
		if ((labyrinthBoard[enterPoint[0] + 1][enterPoint[1]] == '.')) {
		//check go right
			if (enterPoint[1] - beforePosition[1] == 1){
				labyrinthBoard[enterPoint[0] + 1][enterPoint[1]] = 'X';
				beforePosition[0] = enterPoint[0];
			}
		}
		if (labyrinthBoard[enterPoint[0] - 1][enterPoint[1]] == '.') {
			//check go right
			if (beforePosition[1] - enterPoint[1] == 1) {
				labyrinthBoard[enterPoint[0] - 1][enterPoint[1]] = 'X';
				beforePosition[0] = enterPoint[0];
			}
		}
	}
	else if ((enterPoint[0] == 0) && (enterPoint[0] < LINE)) {
		if ((labyrinthBoard[enterPoint[0] + 1][enterPoint[1]] == '.')) {
			//check go right
			if (enterPoint[1] - beforePosition[1] == 1) {
				labyrinthBoard[enterPoint[0] + 1][enterPoint[1]] = 'X';
				beforePosition[0] = enterPoint[0];
			}
		}
	}
	else if ((enterPoint[0] > 0) && (enterPoint[0] == LINE)) {
		if (labyrinthBoard[enterPoint[0] - 1][enterPoint[1]] == '.') {
			//check go right
			if (beforePosition[1] - enterPoint[1] == 1) {
				labyrinthBoard[enterPoint[0] - 1][enterPoint[1]] = 'X';
				beforePosition[0] = enterPoint[0];
			}
		}
	}
	else {
		printf("Error in enterPoint[0] %d\n", enterPoint[0]);
	}

	//check right left
	if ((enterPoint[1] > 0) && (enterPoint[1] < COLUMN)) {
		if ((labyrinthBoard[enterPoint[0]][enterPoint[1] + 1] == '.')) {
			//check go right
			if (beforePosition[1] - enterPoint[1] == 1) {
				labyrinthBoard[enterPoint[0]][enterPoint[1] + 1] = 'X';
				beforePosition[1] = enterPoint[1];
			}
		}
		if (labyrinthBoard[enterPoint[0]][enterPoint[1] - 1] == '.') {
			//check go right
			if (enterPoint[1] - beforePosition[1] == 1) {
				labyrinthBoard[enterPoint[0]][enterPoint[1] - 1] = 'X';
				beforePosition[1] = enterPoint[1];
			}
		}
	}
	else if ((enterPoint[1] == 0) && (enterPoint[1] < COLUMN)) {
		if ((labyrinthBoard[enterPoint[0]][enterPoint[1] + 1] == '.')) {
			//check go right
			if (beforePosition[1] - enterPoint[1] == 1) {
				labyrinthBoard[enterPoint[0]][enterPoint[1] + 1] = 'X';
				beforePosition[1] = enterPoint[1];
			}
		}
	}
	else if ((enterPoint[0] > 0) && (enterPoint[0] == COLUMN)) {
		if (labyrinthBoard[enterPoint[0]][enterPoint[1] - 1] == '.') {
			//check go right
			if (enterPoint[1] - beforePosition[1] == 1) {
				labyrinthBoard[enterPoint[0]][enterPoint[1] - 1] = 'X';
				beforePosition[1] = enterPoint[1];
			}
		}
	}
	else {
		printf("Error in enterPoint[1] %d\n", enterPoint[1]);
	}
}

int main(void) {
	int enterPoint[2] = { 2,0 };
	char labyrinthBoard[LINE][COLUMN] = { 0 };
	int pointLabyrinth[] = { 14,15,16,18,19,20,21,22,23,
		25,26,28,30,35,
		40,42,43,44,45,47,
		50,51,52,53,57,59,60,
		65,67,69,71,
		74,75,77,79,81,83,
		87,89,91,93,95,
		98,99,100,101,102,103,104,105,107,
		116,119,
		122,123,124,125,126,127,129,130,131,
	};

	int pointLabyrinthSize = sizeof(pointLabyrinth) / sizeof(pointLabyrinth[0]);

	createLabyrinth(labyrinthBoard, pointLabyrinth, pointLabyrinthSize);
	printLabyrinth(labyrinthBoard);
	labyrinthBoard[enterPoint[0]][enterPoint[1]] = 'X';

	mazeTraverse(labyrinthBoard, enterPoint);
	printLabyrinth(labyrinthBoard);
	return 0;
}