#include <stdio.h>

void getHanoiTower(int, int, int, int);

void getHanoiTower(int discCount, int beginRack, int moveRack, int tempRack) {
	if (discCount == 1) {
		printf("%d > %d\n", beginRack, moveRack);
		return;
	}
	else if (discCount == 2){
		printf("%d > %d\n", beginRack, moveRack);
		printf("%d > %d\n", beginRack, tempRack);
		printf("%d > %d\n", moveRack, tempRack);
		return;
	}
	getHanoiTower(discCount - 1, beginRack, moveRack, tempRack);
	getHanoiTower(1, beginRack, moveRack, tempRack);
	getHanoiTower(discCount - 1, tempRack, beginRack, moveRack);//TODO fix error getHanoiTower(discCount - 1, tempRack, moveRack, beginRack)

}

int main(void) {
	getHanoiTower(3,1,3,2);
	return 0;
}