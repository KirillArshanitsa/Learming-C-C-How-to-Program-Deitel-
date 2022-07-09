#include "DoubleSubscriptedArray.h"

#include <iostream>
using namespace std;

int main()
{
    DoubleSubscriptedArray myDoubleArray(4,5);
    //cout << myDoubleArray;
    myDoubleArray(3,3) = 1;
    //cout << myDoubleArray(1,2) << endl;
    cout << myDoubleArray;
    return 0;
}