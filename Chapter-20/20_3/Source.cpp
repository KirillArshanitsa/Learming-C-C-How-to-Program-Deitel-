#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"
#include "CommissionEmployee.h"
using namespace std;

int main()
{
	CommissionEmployee commissionEmployee("Bob", "Lewis", "333-33-3333", 5000, .04);
	BasePlusCommissionEmployee employee(commissionEmployee, 200);

	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// get commission employee data
	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getCommissionEmployee().getFirstName()
		<< "\nLast name is " << employee.getCommissionEmployee().getLastName()
		<< "\nSocial security number is "
		<< employee.getCommissionEmployee().getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getCommissionEmployee().getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionEmployee().getCommissionRate()
		<< "\nBase salary is " << employee.getBaseSalary() << endl;


	employee.setBaseSalary(1000);
	cout << "\nUpdated employee information output by print function: \n"
		<< endl;

	employee.print();
	// display the employee's earnings
	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;

	//CommissionEmployee commissionEmployee2("Bob2", "Lewis2", "333-33-3333", 5000, .04);
	//employee.getCommissionEmployee() = commissionEmployee2;
	//cout << "Employee information obtained by get functions: \n"
	//	<< "\nFirst name is " << employee.getCommissionEmployee().getFirstName() << endl;
}