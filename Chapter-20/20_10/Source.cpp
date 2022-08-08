#include"SavingAccount.h"
#include"CheckingAccount.h"
#include<iostream>

using namespace std;

int main()
{

	SavingAcoount savingAccount(6, 2.05);
	cout << savingAccount.getBalance() << endl;
	savingAccount.credit(savingAccount.calculateInterest());
	cout << savingAccount.getBalance() << endl;

	CheckingAccount checkingAccount(6, 0.07);
	cout << checkingAccount.getBalance() << endl;
	checkingAccount.debit(6);
	cout << checkingAccount.getBalance() << endl;

	return 0;
}