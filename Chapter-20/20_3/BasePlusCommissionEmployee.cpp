#include <iostream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	CommissionEmployee& const commissionEmpl, double salary)
	: commissionEmployee(commissionEmpl)
{
	setBaseSalary(salary); 
} 

 // set base salary
 void BasePlusCommissionEmployee::setBaseSalary(double salary)
 {
	 baseSalary = (salary < 0.0) ? 0.0 : salary;
 } // end function setBaseSalary

 // return base salary
 double BasePlusCommissionEmployee::getBaseSalary() const
 {
	 return baseSalary;
 } // end function getBaseSalary

 // calculate earnings
 double BasePlusCommissionEmployee::earnings() const
 {
	 return getBaseSalary() + commissionEmployee.earnings();
 } // end function earnings

 // print BasePlusCommissionEmployee object
 void BasePlusCommissionEmployee::print() const
 {
	 cout << "base-salaried ";
	 commissionEmployee.print();
	 cout << "\nbase salary: " << getBaseSalary();
 }

 const CommissionEmployee& const BasePlusCommissionEmployee::getCommissionEmployee() const
 {
	 return commissionEmployee;
 }

 //const CommissionEmployee& const BasePlusCommissionEmployee::getCommissionEmployee()
 //{
	// return commissionEmployee;
 //}
