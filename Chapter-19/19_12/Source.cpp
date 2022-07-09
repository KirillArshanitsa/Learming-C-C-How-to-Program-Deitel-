#include "DoubleSubscriptedArray.h"

#include <iostream>
using namespace std;

int main()
{
    DoubleSubscriptedArray myDoubleArray(4,5);
    //cout << myDoubleArray;
    myDoubleArray(3,3) = 9;
    myDoubleArray(4, 4) = 3;
    myDoubleArray(1, 1) = 2;
    //cout << myDoubleArray(1,2) << endl;
    cout << myDoubleArray << endl;
    cout << myDoubleArray[2];
    return 0;
}