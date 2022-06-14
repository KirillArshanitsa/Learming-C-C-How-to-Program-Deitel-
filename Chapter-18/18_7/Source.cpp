#include "SavingsAccount.h"

#include<iostream>
using namespace std;


int main()
{
	SavingsAccount saver1(2000.00);
	SavingsAccount saver2(3000.00);

	SavingsAccount::modifylInterestRate(3);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	SavingsAccount::modifylInterestRate(4);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
}