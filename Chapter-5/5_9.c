#include <stdio.h>

double calculateCharges(double);
double allHouers;
double allCharges;

double calculateCharges(double houers) {
	double result;
	allHouers += houers;
	if (houers <= 3)
		result = 2.0;
	else {
		if (houers == 24)
			result = 10.00;
		else
			result = (houers - 3) * 0.50 + 2.0;
	}
	allCharges += result;
	return result;
}

int main() {
	printf_s("%3s%9s%12s\n", "Car", "Hours", "Charge");
	printf_s("%-3s%9s%12.2f\n", "1", "1.5", calculateCharges(1.5));
	printf_s("%-3s%9s%12.2f\n", "2", "4.0", calculateCharges(4.0));
	printf_s("%-3s%9s%12.2f\n", "3", "24.0", calculateCharges(24.0));
	printf_s("%-3s%7.1f%12.2f\n", "TOTAL", allHouers, allCharges);
	return 0;
}