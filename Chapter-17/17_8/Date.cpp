#include <iostream>
#include "Date.h" 

using std::cout;
using std::endl;


Date::Date(int mn, int dy, int yr)
{
    setDay(dy);
    setMonth(mn);
    setYear(yr);
}

void Date::setDay(int dy) {
    if ((dy >= 1) && (dy <= 31)) 
        day = dy;
    else 
        if ((day < 1) || (day > 31)) //check old avlue
            day = 1;
}

void Date::setMonth(int mn) {
    if ((mn >= 1) && (mn <= 12))
        month = mn;
    else
        if ((month < 1) || (month > 12)) //check old avlue
            month = 1;
}

void Date::setYear(int yr) {
    if (yr >= 0) {
        year = yr;
        if (((yr % 4 == 0) && (yr % 100 > 0)) || (yr % 400 == 0))
            daysOfMonth[1] = 29;
        else
            daysOfMonth[1] = 28;
    }
    else
        if (year < 0)
            year = 0;
}

void Date::nextDay()
{
    if (day + 1 > daysOfMonth[month - 1]) {
        day = 1;
        if (month + 1 == 13) {
            month = 1;
            setYear(year + 1);
        }
        else
            month++;
        cout << endl;
    }
    else 
        day++;
    
}

void Date::print() const
{
    cout << month << '/' << day << '/' << year << endl;;
} 