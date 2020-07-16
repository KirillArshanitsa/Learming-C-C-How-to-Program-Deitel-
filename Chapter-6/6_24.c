#include <stdio.h>

void printBoard(int[][8]);
int go(int[][8], int, int, int, int, int);

void printBoard(int board[][8]) {
	for (int e = 0; e < 8; e++) {
		for (int i = 0; i < 8; i++) {
			printf("%d", board[e][i]);
		}
		puts("");
	}
}
int go(int board[][8], int currentColumn, int currentRow, int horizontal, int vertical, int count) {

	if (! (((currentRow + vertical) >= 0) && ((currentRow + vertical) < 8)) ) //currentRow - (-vertical) >= 0
		return 0;
	if (! (((currentColumn + horizontal) >= 0) && ((currentColumn + horizontal) < 8)) ) //currentColumn - (-horizontal) >= 0
		return 0;


	if (vertical < 0) {
		for (int e = vertical, mCurrentRow = currentRow; e; e++) {
			if (board[--mCurrentRow][currentColumn] != 0)
				return 0;
		}
	}
	else {
		for (int e = vertical, mCurrentRow = currentRow; e; e--) {
			if (board[++mCurrentRow][currentColumn] != 0)
				return 0;
		}
	}

	if (horizontal < 0) {
		for (int e = horizontal, mCurrentColumn = currentColumn; e; e++) {
			if (board[currentRow][--mCurrentColumn] != 0)
				return 0;
		}
	}
	else {
		for (int e = horizontal, mCurrentColumn = currentColumn; e; e--) {
			if ((board[currentRow][++mCurrentColumn ]) != 0) {
				return 0;
			}
		}
	}

	//board[currentRow][currentColumn] = 9;

	if (vertical < 0) {
		while (vertical++) {//(-vertical) -1
			board[--currentRow][currentColumn] = count;
		}
	}
	else {
		while (vertical--) {
			board[++currentRow][currentColumn] = count;
		}
	}

	if (horizontal < 0) {
		while (horizontal++) {//(-horizontal) -1
			board[currentRow][--currentColumn] = count;
		}
	}
	else {
		while (horizontal--) {
			board[currentRow][++currentColumn] = count;
		}
	}
	printf("localCurrentRow = %d, localurrentColumn = %d\n", currentRow, currentColumn);
	return 1;

}


int main(void) {
	//horizont left and vertical hight = -
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
	int currentColumn = 3;
	//int moveNumber = 6;
	//int count = go(board, currentColumn, currentRow, horizontal[moveNumber], vertical[moveNumber], moveNumber);
	int count;
	for (count = 1; count <= 64; count++) {
		for (int moveNumber = 0; moveNumber < 8; moveNumber++) {
			if (go(board, currentColumn, currentRow, horizontal[moveNumber], vertical[moveNumber], count)) {
				currentColumn += vertical[moveNumber];
				currentRow += horizontal[moveNumber];
				break;
			}
		}
	}
	printBoard(board);
	printf("\n\ncurrentRow = %d, currentColumn = %d, count = %d", currentRow, currentColumn, count);
	return 0;
}