#include <stdio.h>
int main() {
 
    int year;
    int leapYear;
    int beginDay;
 
    int daysInMounth;
    int currentDay;
    int printedDays;
 
    puts("Please enter year and begin day:");
    scanf_s("%d %d", &year, &beginDay);
    if (year % 400 == 0)
        leapYear = 1;
    else if (year % 100 == 0)
        leapYear = 0;
    else if(year % 4 == 0)
        leapYear = 1;
    else
        leapYear = 0;
    printf_s("year %d is leapyear = %d\n\n", year, leapYear);
 
    for (int mounthYear = 1; mounthYear <= 12; mounthYear++) {
        switch (mounthYear) {
            case 1:
                daysInMounth = 31;
                break;
            case 2:
                if (leapYear)
                    daysInMounth = 29;
                else
                    daysInMounth = 28;
                break;
            case 3:
                daysInMounth = 31;
                break;
            case 4:
                daysInMounth = 30;
                break;
            case 5:
                daysInMounth = 31;
                break;
            case 6:
                daysInMounth = 30;
                break;
            case 7:
                daysInMounth = 31;
                break;
            case 8:
                daysInMounth = 31;
                break;
            case 9:
                daysInMounth = 30;
                break;
            case 10:
                daysInMounth = 31;
                break;
            case 11:
                daysInMounth = 30;
                break;
            case 12:
                daysInMounth = 31;
                break;
        }
        currentDay = 0;
        printedDays = 0;
        printf_s("Mounth is %d\n", mounthYear);
        printf_s("%2s %2s %2s %2s %2s %2s %2s\n", "Monday", "Tuesday", "Wednesday", "Yhursday", "Friday", "Saturday", "Sunday");
        for (int d = 1; d < beginDay; d++) {
            printf_s("%8s", " ");
            ++printedDays;
        }
        for (++currentDay; currentDay <= daysInMounth; currentDay++) {
            printf_s("%8d", currentDay);
            ++printedDays;
            if ((printedDays >= 7) & !(printedDays % 7))
                printf_s("\n");
        }
        beginDay = ((daysInMounth - (7 - beginDay + 1)) % 7) + 1;
        printf("\n\n");
    }
    return 0;
}