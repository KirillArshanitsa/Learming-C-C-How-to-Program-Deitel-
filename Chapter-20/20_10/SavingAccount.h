#ifndef SAVINGACOOUNT_H
#define SAVINGACOOUNT_H
#include "Account.h"

class SavingAcoount : public Account
{
public:
	SavingAcoount(double, double);
	double calculateInterest();

private:
	double interestRate;
};
#endif 
