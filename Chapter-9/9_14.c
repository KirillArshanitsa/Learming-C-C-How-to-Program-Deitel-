#include <stdio.h>
#include <ctype.h>


void checkEscSymb(const char[]);

int main(void)
{
	char str[] = { '\'','\"','\?','\\','\a','\b','\f','\n','\r','\t','\v','\0' };
	checkEscSymb(str);
	return 0;
}

void checkEscSymb(const char str[]) 
{
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\a') 
			continue;
		if (iscntrl(str[i])) {
			printf("B%cE", str[i]);
		}
	}
}