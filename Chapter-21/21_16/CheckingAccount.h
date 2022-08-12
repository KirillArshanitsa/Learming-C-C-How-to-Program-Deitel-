#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount(double, double);
	void credit(double);
	void debit(double);

private:
	double transactionPrice;
};
#endif 
