#include<stdio.h>

void stringReverse(char[]);

void stringReverse(char Array[]){
	static int stringLength;
	if (Array[stringLength] == '\0')
		return;
	++stringLength;
	stringReverse(Array);

	printf("%c", Array[--stringLength]);
}

int main(void) {
	char myString[] = "HelloMyFriend";
	stringReverse(myString);
	return 0;
}