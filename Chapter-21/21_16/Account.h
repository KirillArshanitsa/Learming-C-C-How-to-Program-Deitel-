#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double);
	virtual void credit(double);
	virtual void debit(double);
	double getBalance();
private:
	double balance;
};

#endif 
