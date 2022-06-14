#include "IntegerSet.h"
#include<iostream>
//#include<string.h>

using namespace std;

IntegerSet::IntegerSet(bool b[], int size)
{
    if (size > SET_SIZE) {
        memcpy(a, b, SET_SIZE);
        //size = SET_SIZE;
        cout << "Copy SET_SIZE without " << size << endl;
    }
    else {
        memcpy(a, b, size);
    }
//    while(--size > -1){
//        a[size] = b[size];
//    }
    isEmpty = false;
}

IntegerSet::IntegerSet()
{
    for (int i = 0; i < SET_SIZE; i++)
        a[i] = false;
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
    a[k - 1] = true;
}

void IntegerSet::deleteElement(int k)
{
    a[k - 1] = false;
}


void IntegerSet::printSet()
{
    if (isEmpty)
        cout << "---" << endl;
    else {
        for (int i = 0; i < SET_SIZE; i++) {
            if (a[i])
                cout << i + 1 << " ";
        }
        cout << endl;
    }
}

IntegerSet IntegerSet::unionOfSets(IntegerSet &anotherSetPtr)
{
    IntegerSet result;
    if ((isEmpty) && (anotherSetPtr.isEmpty)){
        return result;
    }
    else if ((isEmpty) && (!anotherSetPtr.isEmpty)){
        memcpy(result.a, anotherSetPtr.a, SET_SIZE);
    }
    else if ((!isEmpty) && (anotherSetPtr.isEmpty)){
        memcpy(result.a, a, SET_SIZE);
    }
    else {
        for (int i = 0; i < SET_SIZE; i++) {
            if ((a[i]) || (anotherSetPtr.a[i]))
                result.a[i] = 1;
        }
    }
    result.isEmpty = false;
    return result;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet &anotherSetPtr)
{
    IntegerSet result;
    if ((isEmpty) && (anotherSetPtr.isEmpty)){
        return result;
    }
    else if ((isEmpty) && (!anotherSetPtr.isEmpty)){
        memcpy(result.a, anotherSetPtr.a, SET_SIZE);
    }
    else if ((!isEmpty) && (anotherSetPtr.isEmpty)){
        memcpy(result.a, a, SET_SIZE);
    }
    else {
        for (int i = 0; i < SET_SIZE; i++) {
            if ((a[i]) && (anotherSetPtr.a[i]))
                result.a[i] = 1;
        }
    }
    result.isEmpty = false;
    return result;
}