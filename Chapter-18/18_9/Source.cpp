#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    Time t; // create Time object
    t.setHour( 18 ).setMinute( 30 ).setSecond( 22 );
    cout << "Universal time: ";
    t.printUniversal();

    cout << "\nStandard time: ";
    t.printStandard();

    cout << "\n\nNew standard time: ";
    t.setTime( 20, 20, 20 ).printStandard();

    cout << "\n\nNew standard time: ";
    t.setTime( 0, 0, 21 ).printStandard();
    cout << endl;
    cout << "Universal time: ";
    t.printUniversal();
}