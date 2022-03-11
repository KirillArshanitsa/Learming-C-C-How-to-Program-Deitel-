#include "Employee.h"

Employee::Employee(string emplName, string emplLastname, int emplSalary)
{
	name = emplName;
	lastname = emplLastname;
	salary = emplSalary;
}

string Employee::getLastName()
{
	return lastname;
}

string Employee::getName()
{
	return name;
}

int Employee::getSalary()
{
	return salary;
}

void Employee::setLastName(string emplLastname)
{
	lastname = emplLastname;
}

void Employee::setName(string emplName)
{
	name = emplName;
}

void Employee::setSalary(int emplSalary)
{	
	salary = emplSalary;
	if (salary < 0)
		salary = 0;

}