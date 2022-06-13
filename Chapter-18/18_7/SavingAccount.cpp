#include "SavingsAccount.h"

#include<iostream>
using std::cout;
using std::endl;

double SavingsAccount::annualInterestRate = 1;

SavingsAccount::SavingsAccount(double balance)
{
	savingBalance = balance;
}

void SavingsAccount::modifylInterestRate(double newVal)
{
	annualInterestRate = newVal;
	cout << "annualInterestRate set " << newVal  <<  endl;
}

void SavingsAccount::calculateMonthlyInterest()
{
	cout << savingBalance * annualInterestRate / 12 + savingBalance << endl;
}