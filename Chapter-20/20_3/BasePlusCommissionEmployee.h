
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ standard string class
#include "CommissionEmployee.h" // CommissionEmployee class declaration
using namespace std;

//class BasePlusCommissionEmployee : public CommissionEmployee
class BasePlusCommissionEmployee
{
public:
	BasePlusCommissionEmployee(CommissionEmployee& const, double = 0.0);

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary
	double earnings() const; // calculate earnings
	void print() const; // print BasePlusCommissionEmployee object
	const CommissionEmployee& const getCommissionEmployee() const;

private:
	const CommissionEmployee& const commissionEmployee;
	double baseSalary;
}; 

#endif