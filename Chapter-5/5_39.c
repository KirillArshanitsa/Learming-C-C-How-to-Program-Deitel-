#include <stdio.h>

void getHanoiTower(int, int, int, int);

void getHanoiTower(int discCount, int beginRack, int moveRack, int tempRack) {
	if (discCount == 0)
		return;
	printf("%d > %d\n", beginRack, tempRack);
	printf("%d > %d\n", beginRack, moveRack);
	printf("%d > %d\n", tempRack, moveRack);

	printf("%d > %d\n", beginRack, tempRack);

	printf("%d > %d\n", moveRack, beginRack);
	printf("%d > %d\n", moveRack, tempRack);
	printf("%d > %d\n", beginRack, tempRack);

	getHanoiTower(--discCount, beginRack, moveRack, tempRack);
}

int main(void) {
	
	return 0;
}