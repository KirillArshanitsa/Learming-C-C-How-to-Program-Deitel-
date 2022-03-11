#include <iostream>

using std::cout;
using std::endl;

#include "Account.h"

int main()
{
	Account account1(400);
	Account account2(-1);

	cout << "Begin balacnce from account1 = " << account1.getBalance() << endl;
	cout << "Begin balacnce from account2 = " << account2.getBalance() << endl;


	cout << "\nTest debit() for account1" << endl;
	account1.debit(300);
	cout << "Balacnce account1 after debit(300) = " << account1.getBalance() << endl;
	cout << "Test debit() for account2" << endl;
	account2.debit(100);
	cout << "Balacnce account2 after debit(100) = " << account2.getBalance() << endl;


	cout << "\nTest credit() for account1" << endl;
	account1.credit(100);
	cout << "Balacnce account1 after credit(100) = " << account1.getBalance() << endl;
	cout << "Test credit() for account2" << endl;
	account2.credit(10);
	cout << "Balacnce account2 after credit(10) = " << account2.getBalance() << endl;

}