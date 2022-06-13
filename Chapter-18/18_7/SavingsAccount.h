#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

class SavingsAccount
{
public:
	SavingsAccount(double);
	void calculateMonthlyInterest();
	static void modifylInterestRate(double);
private:
	double savingBalance;
	static double annualInterestRate;
};

#endif // !SAVINGACCOUNT
