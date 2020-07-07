#include <stdio.h>

void printGraph(int[][50]);
void parseComands(int[], int[][50], int[3]);
void drawLine(int, int[][50], int[3], int[2]);


void printGraph(int floor[][50]) {
	for (int ext = 0; ext < 50; ext++) {
		for (int in = 0; in < 50; in++) {
			//printf("%d", floor[ext][in]);
			if (floor[ext][in])
				printf("%s", "*");
			else
				printf("%s", " ");
		}
		puts("");
	}
}

void drawLine(int count, int floor[][50], int flagAndPosition[3], int changePoinst[2]) {
	// 00=UP 01=DOWN 10=LEFT 11=RIGHT
	int changedElement;
	if (changePoinst[0] == 0)
		changedElement = 1;
	else {
		changedElement = 2;
	}

	if (changePoinst[1] == 0) {
		while (count--) {
			++floor[flagAndPosition[1]][flagAndPosition[2]];
			--flagAndPosition[changedElement];
		}
	}
	else {
		while (count--) {
			++floor[flagAndPosition[1]][flagAndPosition[2]];
			++flagAndPosition[changedElement];
		}
	}
}

void parseComands(int comands[], int floor[][50], int flagAndPosition[3]) {
	int changePoinst[4] = { 0 };// changePoinst[2] UP/DOWN changePoinst[3] LEFT/RIGHT
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
			if (((changePoinst[0] == 0) && (changePoinst[1] == 0)) && ((changePoinst[2] == 0) && (changePoinst[3] == 0))) {//00=UP
				changePoinst[0] = 1;
				changePoinst[1] = 1;

				changePoinst[3] = 1; //TO RIGHT
			}
			else if (((changePoinst[0] == 1) && (changePoinst[1] == 1)) && ((changePoinst[2] == 0) && (changePoinst[3] == 1))) {//11=RIGHT
				changePoinst[0] = 0;
				changePoinst[1] = 1;

				changePoinst[2] = 1;//TO DOWN
			}
			else if (((changePoinst[0] == 0) && (changePoinst[1] == 1)) && ((changePoinst[2] == 1) && (changePoinst[3] == 1))) {//01=DOWN
				changePoinst[0] = 1;
				changePoinst[1] = 0;

				changePoinst[3] = 0;//TO LEFT
			}
			else if (((changePoinst[0] == 1) && (changePoinst[1] == 0)) && ((changePoinst[2] == 1) && (changePoinst[3] == 0))) {//10=LEFT 
				changePoinst[0] = 0;
				changePoinst[1] = 0;

				changePoinst[2] = 0;//TO UP
			}
			break;

		case 4:

			if (((changePoinst[0] == 0) && (changePoinst[1] == 0)) && ((changePoinst[2] == 0) && (changePoinst[3] == 0))) {//00=UP
				changePoinst[0] = 1;
				changePoinst[1] = 0;

				changePoinst[2] = 1;//TO LEFT
			}
			else if (((changePoinst[0] == 1) && (changePoinst[1] == 0)) && ((changePoinst[2] == 1) && (changePoinst[3] == 0)) ) {//10=LEFT
				changePoinst[0] = 0;
				changePoinst[1] = 1;

				changePoinst[3] = 1;//TO DOWN
			}
			else if (((changePoinst[0] == 0) && (changePoinst[1] == 1)) && ((changePoinst[2] == 1) && (changePoinst[3] == 1)) ) {//10=DOWN
				changePoinst[0] = 1;
				changePoinst[1] = 1;

				changePoinst[3] = 0;//TO LEFT
			}
			else if (((changePoinst[0] == 1) && (changePoinst[1] == 1)) && ((changePoinst[2] == 1) && (changePoinst[3] == 0)) ){//10=RIGHT
				changePoinst[0] = 1;
				changePoinst[1] = 1;

				changePoinst[3] = 0;//TO UP
			}


			else if (((changePoinst[0] == 1) && (changePoinst[1] == 1)) && ((changePoinst[2] == 0) && (changePoinst[3] == 1))) {//TO UP
				changePoinst[0] = 0;
				changePoinst[1] = 0;

				changePoinst[3] = 0;//TO UP
			}
			break;

		case 5:
			++e;
			// 00=UP 01=DOWN 10=LEFT 11=RIGHT
			//printf("\n\n%d %d %d %d\n\n", changePoinst[0], changePoinst[1], changePoinst[2], changePoinst[3]);

			if (flagAndPosition[0] == 0) {
				drawLine(comands[e], floor, flagAndPosition, changePoinst);
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
	int commands[30] = { 2, 5, 12, 3, 5, 12, 3, 5, 12, 3, 5, 12, 1, 6, 9 };
	parseComands(commands, floor, flagAndPosition);
	return 0;
}