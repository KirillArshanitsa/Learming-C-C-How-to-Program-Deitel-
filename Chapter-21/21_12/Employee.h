#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // C++ standard string class
#include "Date.h"

using namespace std;

class Employee
{
public:
	Employee(const string&, const string&, const string&, int m = 1, int d = 1, int y = 1900);

	void setFirstName(const string&); // set first name
	string getFirstName() const; // return first name

	void setLastName(const string&); // set last name
	string getLastName() const; // return last name

	void setSocialSecurityNumber(const string&); // set SSN
	string getSocialSecurityNumber() const; // return SSN
	Date getBirthDate() const;

	virtual double earnings() const = 0; // pure virtual
	virtual void print() const; // virtual

private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	Date birthDate;
}; 

#endif 