#include <stdio.h>

struct inventory {
	char partName[30];
	int partNumber;
	int price;
	int stock;
	int reorder;
};

union data {
	char s;
	short s;
	long l;
	float f;
	double d;
};

struct adress{
	char Adress[25];
	char city[20];
	char state[3];
	char zipCode[6];
};

struct student {
	char firstName[15];
	char lastName[15];
	struct adress homeAddress;
};

struct test {
	int a : 1;
	int b : 1;
	int c : 1;
	int d : 1;
	int e : 1;
	int f : 1;
	int g : 1;
	int h : 1;
	int i : 1;
	int j : 1;
	int k : 1;
	int l : 1;
	int m : 1;
	int n : 1;
	int o : 1;
	int p : 1;
};

int main(void)
{
	return 0;
}

