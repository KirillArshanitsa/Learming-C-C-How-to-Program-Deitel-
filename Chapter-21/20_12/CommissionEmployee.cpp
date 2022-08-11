#include <iostream>
#include "CommissionEmployee.h" 

using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(const string & first,
	const string & last, const string & ssn, double sales, double rate, int m, int d, int y)
	: Employee(first, last, ssn, m,  d,  y)
{
	setGrossSales(sales);
	setCommissionRate(rate);
} 

// set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
	commissionRate = ((rate > 0.0 && rate < 1.0) ? rate : 0.0);
} // end function setCommissionRate

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
} // end function getCommissionRate

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
	grossSales = ((sales < 0.0) ? 0.0 : sales);
} // end function setGrossSales

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
	return grossSales;
} // end function getGrossSales

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
	return getCommissionRate() * getGrossSales();
} // end function earnings

// print CommissionEmployee's information
void CommissionEmployee::print() const
{
	cout << "commission employee: ";

	cout << "\ngross sales: " << getGrossSales()
		<< "; commission rate: " << getCommissionRate();
} // end function print