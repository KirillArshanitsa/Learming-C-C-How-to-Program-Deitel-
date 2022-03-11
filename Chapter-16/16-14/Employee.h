#include <string>

using std::string;

class Employee
{
public:
	Employee(string, string, int);
	string getName();
	string getLastName();
	int getSalary();
	void setName(string);
	void setLastName(string);
	void setSalary(int);

private:
	string name;
	string lastname;
	int salary;
	Employee();
};