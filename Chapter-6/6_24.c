#include <stdio.h>

void printBoard(int[][8]);
int go(int[][8], int, int, int, int, int);

void printBoard(int board[][8]) {
	for (int e = 0; e < 8; e++) {
		for (int i = 0; i < 8; i++) {
			printf("%4d", board[e][i]);
		}
		puts("");
	}
}

int go(int board[][8], int currentColumn, int currentRow, int horizontal, int vertical, int count) {
	currentRow = currentRow + vertical; //currentRow - (-vertical)
	currentColumn = currentColumn + horizontal; //currentColumn - (-horizontal)

	if (! ((currentRow >= 0) && (currentRow < 8))) 
		return 0;
	if (! ((currentColumn >= 0) && (currentColumn < 8))) 
		return 0;

	//printf("localCurrentRow = %d, localurrentColumn = %d\n", currentRow, currentColumn);
	if (board[currentRow][currentColumn] == 0) {
		board[currentRow][currentColumn] = count;
		return 1;
	}
	else
		return 0;

}


int main(void) {
	int board[8][8] = { 0 };
	int horizontal[8] = { 0 };
	int vertical[8] = { 0 };

	horizontal[0] = 2;
	horizontal[1] = 1;
	horizontal[2] = -1;
	horizontal[3] = -2;
	horizontal[4] = -2;
	horizontal[5] = -1;
	horizontal[6] = 1;
	horizontal[7] = 2;
	vertical[0] = -1;
	vertical[1] = -2;
	vertical[2] = -2;
	vertical[3] = -1;
	vertical[4] = 1;
	vertical[5] = 2;
	vertical[6] = 2;
	vertical[7] = 1;

	int currentRow = 3;
	int currentColumn = 4;
	//Debug
	board[currentRow][currentColumn] = 65;
	//int moveNumber = 6;
	//int count = go(board, currentColumn, currentRow, horizontal[moveNumber], vertical[moveNumber], moveNumber);
	int count;
	for (count = 1; count <= 64; count++) {
		int goResult = 0;
		for (int moveNumber = 0; moveNumber <= 7; moveNumber++) {
			if (go(board, currentColumn, currentRow, horizontal[moveNumber], vertical[moveNumber], count)) {
				currentRow += vertical[moveNumber];
				currentColumn += horizontal[moveNumber];
				goResult = 1;
				break;
			}
		}
		if (goResult == 0)
			break;
	}
	printBoard(board);
	printf("\n\ncurrentRow = %d, currentColumn = %d, count = %d", currentRow, currentColumn, count - 1);
	return 0;
}