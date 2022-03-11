#include <iostream>

using std::cout;
using std::endl;

#include "Account.h"

Account::Account(int beginBalance)
{
	if (beginBalance <= 0) {
		balance = 0;
		cout << "Begin balance must be > 0 you enter "<< beginBalance << endl;
	}
	else 
		balance = beginBalance;
}

int Account::getBalance() 
{
	return balance;
}

void Account::credit(int money) 
{
	balance += money;
}


void Account::debit(int money)
{
	if (money > balance) {
		cout << "Requested money exceeds account balance." << endl;
		return;
	}
	else 
		balance -= money;
}