#include <stdio.h>
#include <ctype.h>

void procesSymbol(const char);


int main(void) {
	while (1) {
		puts("Enter keyboard symbol:");
		procesSymbol(getchar());
	}
	return 0;
}


void procesSymbol(const char ch) {
	printf("Check isdigit(%c) - %s\n", ch, isdigit(ch)? "is a":"is not");
	printf("Check isalpha(%c) - %s\n", ch, isalpha(ch) ? "is a" : "is not");
	printf("Check isalnum(%c) - %s\n", ch, isalnum(ch) ? "is a" : "is not");
	printf("Check isxdigit(%c) - %s\n", ch, isxdigit(ch) ? "is a" : "is not");
	printf("Check islower(%c) - %s\n", ch, islower(ch) ? "is a" : "is not");
	printf("Check isupper(%c) - %s\n", ch, isupper(ch) ? "is a" : "is not");
	printf("Check tolower(%c) - %c\n", ch, tolower(ch));
	printf("Check toupper(%c) - %c\n", ch, toupper(ch));
	printf("Check isspace(%c) - %s\n", ch, isspace(ch) ? "is a" : "is not");
	printf("Check iscntrl(%c) - %s\n", ch, iscntrl(ch) ? "is a" : "is not");
	printf("Check ispunct(%c) - %s\n", ch, ispunct(ch) ? "is a" : "is not");
	printf("Check isprint(%c) - %s\n", ch, isprint(ch) ? "is a" : "is not");
	printf("Check isgraph(%c) - %s\n", ch, isgraph(ch) ? "is a" : "is not");
	puts("");
}