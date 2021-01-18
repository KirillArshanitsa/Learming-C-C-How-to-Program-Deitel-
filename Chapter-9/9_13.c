#include <stdio.h>

#define STR_MAX_SIZE 100

int temperatureConversio(void);

int main(void)
{
	short farefahrenheitg;
	double celcius;
	temperatureConversio();
	return 0;
}

int temperatureConversio(void)
{
	short farefahrenheitg;
	double celcius;
	puts("Enter farengate val 0 - 212:");
	scanf_s("%hd", &farefahrenheitg);
	if ((farefahrenheitg > 212) || (farefahrenheitg < 0)) {
		printf("Error you enter %hd, need from 0 to 212\n", farefahrenheitg);
		return -1;
	}
	celcius = 5.0 / 9.0 * (farefahrenheitg - 32);
	puts("Result:");
	printf("%10hd%+10.3f\n", farefahrenheitg, celcius);
	return 0;
}