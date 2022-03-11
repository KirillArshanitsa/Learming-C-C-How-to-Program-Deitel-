#include <iostream>
#include "Employee.h"

using std::cout;
using std::endl;

int main()
{
	Employee empl1("NameEmpl1", "LastNmeEmpl1", 20);
	Employee empl2("NameEmpl2", "LastNmeEmpl2", 15);

	cout << "Year salary Employee1 = " << empl1.getSalary() * 12 << endl;
	cout << "Year salary Employee2 = " << empl2.getSalary() * 12 << endl;

	cout << "+ 10%" << endl;
	empl1.setSalary(empl1.getSalary() * 1.1);
	empl2.setSalary(empl2.getSalary() * 1.1);

	cout << "Salary after + 10%" << endl;
	cout << "Year salary Employee1 = " << empl1.getSalary() * 12 << endl;
	cout << "Year salary Employee2 = " << empl2.getSalary() * 12 << endl;

	return 0;
}