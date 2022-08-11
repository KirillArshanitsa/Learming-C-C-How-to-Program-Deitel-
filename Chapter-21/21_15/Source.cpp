#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>
#include <vector>

using namespace::std;

int main()
{

	vector<Package*> packages(3);

	packages[0] = new Package("NameS","AdressS", "CityS", "StateS", 1, "NameR", "AdressR", "CityR", "StateR", 2, 3,4);
	packages[1] = new TwoDayPackage ("NameS", "AdressS", "CityS", "StateS", 1, "NameR", "AdressR", "CityR", "StateR", 2, 3, 4, 4);
	packages[2] = new OvernightPackage ("NameS", "AdressS", "CityS", "StateS", 1, "NameR", "AdressR", "CityR", "StateR", 2, 3, 4, 4);
	size_t sum = 0;

	for (size_t i = 0, e; i < packages.size(); i++) {
		packages[i]->getSenderAndRecipientAddress();
		e = packages[i]->calculateCost();
		sum += e;
		cout <<"price = "<< e << "\n" << endl;
	}
	
	cout << "All sum = " << sum << endl;
	return 0;
}