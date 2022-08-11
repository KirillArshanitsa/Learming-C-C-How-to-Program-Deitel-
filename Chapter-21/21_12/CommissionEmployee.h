#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h" // Employee class definition

class CommissionEmployee : public Employee
{
public:
	CommissionEmployee(const string&, const string&,
		const string&, double = 0.0, double = 0.0, int m = 1, int d = 1, int y = 1900);

	void setCommissionRate(double); // set commission rate
	double getCommissionRate() const; // return commission rate

	void setGrossSales(double); // set gross sales amount
	double getGrossSales() const; // return gross sales amount

	virtual double earnings() const; // calculate earnings
	virtual void print() const; // print CommissionEmployee object


private:
	double grossSales; // gross weekly sales
	double commissionRate; // commission percentage
 }; // end class CommissionEmployee

#endif // COMMISSION_H
