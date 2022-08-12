#include "CheckingAccount.h"
#include <iostream>

using namespace std;


CheckingAccount::CheckingAccount(double balance, double transactionPrice)
	:Account(balance)
{
	this->transactionPrice = transactionPrice;
}


void CheckingAccount::credit(double m)
{
	Account::credit(m - transactionPrice);
}

void CheckingAccount::debit(double m)
{
	Account::debit(m + transactionPrice);
}