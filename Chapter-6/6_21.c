#include <stdio.h>

void seatReservation(int passengeSeats[]);

void seatReservation(int passengeSeats[]) {
	int enteredVal;
	int response;
	puts("Please enter 1 for smoking\nPlease enter 2 for non smoking");
	scanf_s("%d", &enteredVal);

	if (enteredVal == 1) {
		for (int e = 0; e < 5; e++) {
			if (passengeSeats[e] == 0) {
				passengeSeats[e] = 1;
				printf("Reserved place %d in smoking\n", e + 1);
				return;
			}
		}
		puts("No free places in smoking");
		puts("Would you like reserved place in non smoking? Enter 1 for Yes or any number for No");
		scanf_s("%d", &response);
		if (response == 1)
			seatReservation(passengeSeats);
		else
			puts("The next flight will be in 3 hours");

	}
	else if (enteredVal == 2) {
		for (int e = 5; e < 10; e++) {
			if (passengeSeats[e] == 0) {
				passengeSeats[e] = 1;
				printf("Reserved place %d in non smoking\n", e + 1);
				return;
			}
		}
		puts("No free places in non smoking");
		puts("Would you like reserved place in non smoking? Enter 1 for Yes or any number for No");
		scanf_s("%d", &response);
		if (response == 1)
			seatReservation(passengeSeats);
		else
			puts("The next flight will be in 3 hours");
	}
	else {
		puts("Please enter 1 or 2.");
		return;
	}
}

int main(void) {
	int passengeSeats[10] = { 0 };
	while (1) {
		seatReservation(passengeSeats);
	}
	return 0;
}