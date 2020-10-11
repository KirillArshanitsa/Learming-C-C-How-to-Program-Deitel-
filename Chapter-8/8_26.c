#include <stdio.h>

int isdigit(const int);
int isalpha(const int);
int isalnum(const int);
int isxehdigit(const int);
int islower(const int);
int isupper(const int);
int tolower(const int);
int toupper(const int);
int iscpace(const int);
int iscntrl(const int);
int ispunct(const int);
int isprint(const int);
int isgraph(const int);

int main(void) {
	char testChar = '$';

	printf("Test for char %c:\n", testChar);
	printf("isdigit %d\n", isdigit(testChar));
	printf("isalpha %d\n", isalpha(testChar));
	printf("isalnum %d\n", isalnum(testChar));
	printf("isxehdigit %d\n", isxehdigit(testChar));
	printf("islower %d\n", islower(testChar));
	printf("isupper %d\n", isupper(testChar));
	printf("tolower %c\n", tolower(testChar));
	printf("toupper %c\n", toupper(testChar));
	printf("iscpace %d\n", iscpace(testChar));
	printf("ispunct %d\n", ispunct(testChar));
	printf("isprint %d\n", isprint(testChar));
	printf("isgraph %d\n", isgraph(testChar));

	puts("\nFinish.");
	return 0;
}
int isgraph(const int ch) {
	return !iscntrl(ch);
}

int isprint(const int ch) {
	if (ch == 32)
		return 1;
	return !iscntrl(ch);
}

int ispunct(const int ch) {
	if (isdigit(ch))
		return 0;
	else if (isalpha(ch))
		return 0;
	else if (iscntrl(ch))
		return 0;
	else
		return 1;
}

int iscntrl(const int ch) {
	if(ch <= 32)
		return ch;
	else
		return 0;
}

int iscpace(const int ch) {
	if ((ch >= 9) && (ch <= 13))
		return ch;
	else if (ch == 32)
		return ch;
	else
		return 0;
}

int toupper(const int ch) {
	if (islower(ch))
		return ch - 32;
	else
		return ch;
}

int tolower(const int ch) {
	if (isupper(ch))
		return ch + 32;
	else
		return ch;
}

int isupper(const int ch) {
	if ((ch >= 65) && (ch <= 90))
		return ch;
	else
		return 0;
}

int islower(const int ch) {
	if ((ch >= 97) && (ch <= 102))
		return ch;
	else 
		return 0;
}

int isxehdigit(const int ch) {
	if (isdigit(ch))
		return ch;
	else if ((ch >= 65) && (ch <= 70))
		return ch;
	else if ((ch >= 97) && (ch <= 102))
		return ch;
	else
		return 0;
}

int isalnum(const int ch) {
	if (isdigit(ch) || isalpha(ch))
		return ch;
	else
		return 0;
}

int isdigit(const int ch) {
	if ((ch >= 48) && (ch <= 57))
		return ch;
	else
		return 0;
}

int isalpha(const int ch) {
	if ((ch >= 65) && (ch <= 90))
		return ch;
	else if ((ch >= 97) && (ch <= 122))
		return ch;
	else
		return 0;
}