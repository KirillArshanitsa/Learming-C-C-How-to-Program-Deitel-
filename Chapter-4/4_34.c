#include <stdio.h>
#include <math.h>

int main() {
	int decimalNum;
	int n;
	int maxN;

	//puts("Enter decimal number:");
	//scanf_s("%d", &decimalNum);

	printf_s("%s - %s %s %s\n","Decimal","Double","Octal","Hex");
	for (int i = 1; i <= 256; i++) {
		printf("%d - ", i);
		decimalNum = i;
		for (n = 0; decimalNum >= pow(2, n); n++) {
			maxN = pow(2, n);
		}
		while (n--) {
			printf("%d", decimalNum / maxN);
			if (decimalNum / maxN)
				decimalNum %= maxN;
			maxN /= 2;
		}

		printf(" ");
		decimalNum = i;
		for (n = 0; decimalNum >= pow(8, n); n++) {
			maxN = pow(8, n);
		}
		while (n--) {
			printf("%d", decimalNum / maxN);
			if (decimalNum / maxN > 7)
				printf("\n\n\n%d\n\n\n", decimalNum);
			if (decimalNum / maxN)
				decimalNum %= maxN;
			maxN /= 8;
		}

		printf(" ");
		decimalNum = i;
		for (n = 0; decimalNum >= pow(16, n); n++) {
			maxN = pow(16, n);
		}
		while (n--) {
			if (decimalNum / maxN > 9)
				switch (decimalNum / maxN) {
				case 10:
					printf("A");
					break;
				case 11:
					printf("B");
					break;
				case 12:
					printf("C");
					break;
				case 13:
					printf("D");
					break;
				case 14:
					printf("E");
					break;
				case 15:
					printf("F");
					break;
				}
			else
				printf("%d", decimalNum / maxN);
			if (decimalNum / maxN)
				decimalNum %= maxN;
			maxN /= 16;
		}
		printf("\n");
	}

	return 0;
}