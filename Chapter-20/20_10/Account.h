#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double);
	void credit(double);
	void debit(double);
	double getBalance();
private:
	double balance;
};

#endif 
