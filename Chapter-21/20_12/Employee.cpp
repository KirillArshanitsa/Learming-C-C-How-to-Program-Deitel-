#include <iostream>
#include "Employee.h"
#include "Date.h"

using namespace std;

// constructor
Employee::Employee(const string& first, const string& last, const string& ssn, int m, int d, int y)
	: firstName(first), lastName(last), socialSecurityNumber(ssn), birthDate(m, d, y)
	{		
	} 

void Employee::setFirstName(const string& first)
{
	firstName = first;
}

string Employee::getFirstName() const
{
	return firstName;
} 


void Employee::setLastName(const string& last)
{
	lastName = last;
} 

string Employee::getLastName()const
{
	return lastName;
} 

void Employee::setSocialSecurityNumber(const string& ssn)
{
	socialSecurityNumber = ssn;
} 

string Employee::getSocialSecurityNumber() const
{
	return socialSecurityNumber;
} 

void Employee::print() const
{
	cout << getFirstName() << ' ' << getLastName()
		<< "\nsocial security number: " << getSocialSecurityNumber();
} 

Date Employee::getBirthDate() const
{
	return birthDate;
}