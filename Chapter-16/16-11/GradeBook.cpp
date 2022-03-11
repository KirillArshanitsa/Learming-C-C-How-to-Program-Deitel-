
#include <iostream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook( string courseName, string teacherName ) {
    setCourseName(courseName);
    setTeacherName(teacherName);
}

void GradeBook::setCourseName( string name)
{
    courseName = name;
}

void GradeBook::setTeacherName( string name)
{
    teacherName = name;
}

string GradeBook::getCourseName() const
{
    return courseName;
}

string GradeBook::getTeacherName() const
{
    return teacherName;
}


void GradeBook::displayMessage() const
{
    cout << "Welcome to the grade book for\n" << getCourseName()
         << "! This course is presented by " << getTeacherName() << endl;
}

