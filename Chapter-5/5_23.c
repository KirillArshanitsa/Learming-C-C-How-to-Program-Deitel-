#include <stdio.h>
unsigned int getSeconds(int, int, int);

unsigned int getSeconds(int h, int m, int s) {
    unsigned int totalSec = 0;
    int currentSec = 12 * 3600;
    if (s)
        totalSec = s;
    if (m)
        totalSec = totalSec + m * 60;
    if (h)
        totalSec = totalSec + h * 3600;
    if (totalSec > currentSec)
        return totalSec - currentSec;
    else if (totalSec < currentSec)
        return currentSec;
    else
        return 0;

}

int main(void) {
    int hh, mm, sec;
    puts("Enter time HH mm sec");
    scanf_s("%d %d %d", &hh, &mm, &sec);
    printf("Secondse after 12:00 is %d seconds", getSeconds(hh, mm, sec));

    return 0;
}