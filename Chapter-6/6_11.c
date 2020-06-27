// Fig. 6.15: fig06_15.c
// Sorting an array's values into ascending order.
#include <stdio.h>
#define SIZE 10

// function main begins program execution
int main(void)
{
    // initialize a
    int a[SIZE] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
    //int a[SIZE] = { 2, 6, 8, 10, 11, 12, 15, 68, 76, 157 };
    puts("Data items in original order");

    // output original array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    // bubble sort                                         
    // loop to control number of passes                    
    for (unsigned int pass = 1, isSorted = 0; pass < SIZE; ++pass, isSorted = 0) {

        // loop to control number of comparisons per pass   
        for (size_t i = 0; i < SIZE - pass; ++i) {
            // compare adjacent elements and swap them if first 
            // element is greater than second element           
            if (a[i] > a[i + 1]) {
                int hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
                isSorted = 1;
            }
        }
        if (isSorted == 0) {
            printf("\nArray is sorted!!! Count = %d\n", pass);
            break;
        }
        //printf("\nCount = %d\n", pass);

    }

    puts("\nData items in ascending order");

    // output sorted array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    puts("");
}

