#include "HugeInteger.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    HugeInteger hInt1;
    hInt1.input();

    HugeInteger hInt2;
    hInt2.input();

//    cout << "Subtract:" << endl;
//    hInt1.subtract(hInt2);
//    hInt1.output();
//    hInt2.output();

    cout << "Sum:" << endl;
    hInt1.add(hInt2);
    hInt1.output();
    hInt2.output();


    return 0;
}