#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
    explicit GradeBook( std::string, std::string ); // constructor initialize courseName
    void setCourseName( std::string ); // sets the course name
    void setTeacherName( std::string );
    std::string getCourseName() const; // gets the course name
    std::string getTeacherName() const;
    void displayMessage() const; // displays a welcome message
private:
    std::string courseName; // course name for this GradeBook
    std::string teacherName;
}; // end class GradeBook



