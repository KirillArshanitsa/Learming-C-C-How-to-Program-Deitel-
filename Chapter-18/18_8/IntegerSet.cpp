#include "IntegerSet.h"
#include<iostream>
#include<string.h>

using namespace std;

IntegerSet::IntegerSet(bool b[], int size)
{
	if (size > SET_SIZE) {
		memcpy(a, b, SET_SIZE);
		cout << "Copy SET_SIZE without " << size << endl;
	}
	else
		memcpy(a, b, size);
	isEmpty = false;
}

IntegerSet::IntegerSet()
{
	for (int i = 0; i < SET_SIZE; i++)
		a[i] = 0;
	isEmpty = true;
}


bool IntegerSet::isEqualTo(IntegerSet &anotherSetRef)
{
	if (memcmp(a, anotherSetRef.a, SET_SIZE) == 0)
		return true;
	else
		return false;
}

void IntegerSet::insertElement(int k) 
{
	a[k - 1] = 1;
}

void IntegerSet::deleteElement(int k)
{
	a[k - 1] = 0;
}


void IntegerSet::printSet()
{
	if (isEmpty)
		cout << "---" << endl;
	else {
		for (int i = 0; i < SET_SIZE; i++) {
			if (a[i] == 1)
				cout << i + 1 << " ";
		}
		cout << endl;
	}
}