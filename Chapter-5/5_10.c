#include <stdio.h>
#include <math.h>

int main() {
	double x;
	for (int i = 0; i < 3; i++) {
		puts("Enter nuber");
		scanf_s("%lf", &x);
		printf("You enter x = %.2f, value floor(x + .5) = %f\n", x, floor(x + .5));
	}
	return 0;
}