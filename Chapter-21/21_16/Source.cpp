#include "SavingAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int main()
{
	vector <Account*> accounts(2);

	accounts[0] = new SavingAcoount (6, 2.05);
	accounts[1] = new CheckingAccount (6, 0.07);

	for (size_t i = 0; i < accounts.size(); i++) {
		SavingAcoount* derivedPtr = dynamic_cast<SavingAcoount*>(accounts[i]);
		if (derivedPtr != 0) 
			derivedPtr->credit(derivedPtr->calculateInterest());

		cout << accounts[i]->getBalance() << endl;
	}

	return 0;
}