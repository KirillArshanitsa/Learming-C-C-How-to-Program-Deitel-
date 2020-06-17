#include <stdio.h>

int mystery(int, int);

int main() {
	int x, y;
	printf("Enter two integers: ");
	scanf_s("%d %d", &x, &y);
	printf("The result is %d\n", mystery(x, y));
	return 0;
}

int mystery(int a, int b) {
	if (b < 0) {
		a = -a;
		b = -b;
	}
	if (b == 1)
		return a;
	else
		return a + mystery(a, b - 1);
}
