//#include "Date.h"
#include "Employee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector < Employee* > employees(4);

	employees[0] = new BasePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300);
	employees[1] = new CommissionEmployee(
		"Sue2", "Jones2", "111-1-111", 1000, .03);
	employees[2] = new CommissionEmployee(
		"Sue", "Jones", "333-33-3333", 10000, .06, 8, 28, 1988);
	employees[3] = new BasePlusCommissionEmployee(
		"Bob2", "Lewis2", "222-22-2222", 7000, .01, 200, 1, 16 , 1984);

	for (size_t i = 0; i < employees.size(); i++) {
		if (employees[i]->getBirthDate().getMonth() == 8)
			cout << employees[i]->earnings() + 100 << " BirthDate + 100$" << endl;
		else 
			cout << employees[i]->earnings() << endl;
	}

	return 0;
}