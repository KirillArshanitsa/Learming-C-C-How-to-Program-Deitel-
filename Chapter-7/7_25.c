#include <stdio.h>
#define LINE 12
#define COLUMN 12

int createLabyrinth(char[][COLUMN], const int[], const int);
void printLabyrinth(char[][COLUMN]);

void printLabyrinth(char labyrinthBoard[][COLUMN]) {
	puts("");
	for (int e = 0; e < LINE; e++) {
		for (int i = 0; i < COLUMN; i++) {
			printf("%c", labyrinthBoard[e][i]);
		}
		puts("");
	}
}

int createLabyrinth(char labyrinthBoard [][COLUMN], const int pointLabyrinth[], const int pointLabyrinthSize) {

	for (int e = 0; e < pointLabyrinthSize; e++) {
		labyrinthBoard[(pointLabyrinth[e] - 1) / LINE][(pointLabyrinth[e] - 1) % COLUMN] = '.';
	}

	for (int e = 0; e < LINE; e++) {
		for (int i = 0; i < COLUMN; i++) {
			if (labyrinthBoard[e][i] != '.')
				labyrinthBoard[e][i] = '#';
		}
	}
	return 0;
}

int main(void) {
	char labyrinthBoard[LINE][COLUMN] = {0};
	int pointLabyrinth[] = {14,15,16,18,19,20,21,22,23,
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

	int pointLabyrinthSize =  sizeof(pointLabyrinth) / sizeof(pointLabyrinth[0]);

	createLabyrinth(labyrinthBoard, pointLabyrinth, pointLabyrinthSize);
	printLabyrinth(labyrinthBoard);
	return 0;
}