#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(double balance)
{

	if (balance >= 0)
		this->balance = balance;
	else {
		this->balance = 0.0;
		cout << "Error - invalid begin balance." << endl;
	}
}
 
double Account::getBalance()
{
	return balance;
}

void Account::credit(double m)
{
	balance += m;
}

void Account::debit(double m)
{
	if (balance > m)
		balance -= m;
	else 
		cout << "Debit amount exceeds acoount balance." << endl;
}