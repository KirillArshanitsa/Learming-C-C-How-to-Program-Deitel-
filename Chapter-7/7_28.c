// Fig. 6.22: fig06_22.c
// Two-dimensional array manipulations.
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// function prototypes
void minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
void average(const int grades[][EXAMS], size_t pupils, size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);

// function main begins program execution
int main(void)
{
    // initialize student grades for three students (rows)
    int studentGrades[STUDENTS][EXAMS] =
    { { 77, 68, 86, 73 },
      { 96, 87, 89, 78 },
      { 70, 90, 86, 81 } };

    void (*processGrades[4])(const int grades[][EXAMS], size_t pupils, size_t tests) = { printArray, minimum, maximum, average};
    int chosieNum;
    while (1) {
        puts("Enter number:\n0 for print array student grades\n1 for min grade\n2 for max grade\n3 for average grade\n4 for exit");
        scanf_s("%d", &chosieNum);
        if ((chosieNum < 0) || (chosieNum > 4)) {
            printf("Please enter value from 0 to 4, you enter %d\n\n", chosieNum);
            continue;
        }
        if (chosieNum == 4) 
            return 0;
        (*processGrades[chosieNum])(studentGrades, STUDENTS, EXAMS);
    }
}

// Find the minimum grade
void minimum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int lowGrade = 100; // initialize to highest possible grade

    // loop through rows of grades
    for (size_t i = 0; i < pupils; ++i) {

        // loop through columns of grades
        for (size_t j = 0; j < tests; ++j) {
            if (grades[i][j] < lowGrade) {
                lowGrade = grades[i][j];
            }
        }
    }
    printf("Minimum = %d\n\n", lowGrade); // return minimum grade 
}

// Find the maximum grade
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int highGrade = 0; // initialize to lowest possible grade

    // loop through rows of grades
    for (size_t i = 0; i < pupils; ++i) {

        // loop through columns of grades
        for (size_t j = 0; j < tests; ++j) {

            if (grades[i][j] > highGrade) {
                highGrade = grades[i][j];
            }
        }
    }
    printf("Maximum = %d\n\n", highGrade);
    // return maximum grade
}

// Determine the average grade for a particular student
void average(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    // calculate average grade for each student
    int total;
    for (size_t student = 0; student < STUDENTS; ++student) {
        total = 0; // sum of test grades                

        // total all grades for one student                 
        for (size_t i = 0; i < tests; ++i) {
            total += grades[student][i];
        }
        printf("The average grade for student %u is %.2f\n", student,  (double) total/ tests);
        //return (double)total / tests; // average    
    }
    puts("\n");
}

// Print the array
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    // output column heads
    printf("\n%s", "                 [0]  [1]  [2]  [3]");
    // output grades in tabular format
    for (size_t i = 0; i < pupils; ++i) {
        // output label for row
        printf("\nstudentGrades[%u] ", i);

        // output grades for one student
        for (size_t j = 0; j < tests; ++j) {
            printf("%-5d", grades[i][j]);
        }
    }
    puts("\n");
}



