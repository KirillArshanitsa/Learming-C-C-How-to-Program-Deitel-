#include "SavingAccount.h"

SavingAcoount::SavingAcoount(double balance, double interestRate)
	:Account(balance)
{
	this->interestRate = interestRate;
}

double SavingAcoount::calculateInterest()
{
	return interestRate * Account::getBalance();
}