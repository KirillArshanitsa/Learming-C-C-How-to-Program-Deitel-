#include <stdio.h>

float distance(float, float, float, float);

float distance(float x1, float y1, float x2, float y2) {
	float maxX, minX, maxY, minY, catetX, catetY;
	if (x1 == x2) {
		if (y1 > y2) {
			maxY = y1;
			minY = y2;
		}
		else if (y1 < y2) {
			maxY = y2;
			minY = y1;
		}
		else {
			return 0;
		}
		return maxY - minY;
	}

	if (y1 == y2) {
		if (x1 > x2) {
			maxX = x1;
			minX = x2;
		}
		else if (x1 < x2) {
			maxX = x2;
			minX = x1;
		}
		else {
			return 0;
		}
		return maxX - minX;
	}

	if (x1 > x2) {
		maxX = x1;
		minX = x2;
	}
	else if (x1 < x2) {
		maxX = x2;
		minX = x1;
	}
	catetX = maxX - minX;
	if (y1 > y2) {
		maxY = y1;
		minY = y2;
	}
	else if (y1 < y2) {
		maxY = y2;
		minY = y1;
	}
	catetY = maxY - minY;
	return catetX * catetX + catetY * catetY;
}

int main(void) {
	printf("Distance is %.1f", distance(2,3 , 4,2));
	return 0;
}