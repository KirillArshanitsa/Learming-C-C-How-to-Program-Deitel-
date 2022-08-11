#ifndef BASEPLUS_H
#define BASEPLUS_H

#include "CommissionEmployee.h" // CommissionEmployee class definition

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string&, const string&,
		const string&, double = 0.0, double = 0.0, double = 0.0, int m = 1, int d = 1, int y = 1900);

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary


	virtual double earnings() const; // calculate earnings
	virtual void print() const; // print BasePlusCommissionEmployee object

private:
	double baseSalary; // base salary per week
 }; // end class BasePlusCommissionEmployee

#endif // BASEPLUS_H