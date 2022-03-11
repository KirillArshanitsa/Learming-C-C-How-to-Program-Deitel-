#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

int main()
{
    GradeBook gradeBook1( "CS101 Introduction to C++ Programming", "Teacher1");
    GradeBook gradeBook2( "CS102 Data Structures in C++", "Teacher1" );

    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << endl;

    gradeBook1.displayMessage();
    gradeBook2.displayMessage();
}
