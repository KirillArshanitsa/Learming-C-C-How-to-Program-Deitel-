#include "IntegerSet.h"
#include<iostream>

using namespace std;

int main()
{
    IntegerSet set1;
    set1.printSet();
    bool i[5] = { 1,1,0,1,1 };
    IntegerSet set2(i, 5);
    set2.printSet();
    IntegerSet set3(i, 5);
    set3.printSet();
    cout << set1.isEqualTo(set2) << endl;
    cout << set3.isEqualTo(set2) << endl;
    cout << endl;

    IntegerSet set4(i, 5);
    set4.printSet();
    set4.insertElement(3);
    set4.printSet();
    set4.deleteElement(1);
    set4.printSet();
    cout << endl;

    set1.intersectionOfSets(set2).printSet();
    set2.intersectionOfSets(set4).printSet();
    cout << endl;

    set1.unionOfSets(set2).printSet();
    set2.unionOfSets(set4).printSet();
    return 0;
}