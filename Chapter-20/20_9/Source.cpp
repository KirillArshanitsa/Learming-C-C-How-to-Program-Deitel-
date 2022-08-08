#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>

using namespace::std;

int main()
{
	Package package("NameS","AdressS", "CityS", "StateS", 1, "NameR", "AdressR", "CityR", "StateR", 2, 3,4);
	cout << package.calculateCost() << endl;

	TwoDayPackage twoDayPackage("NameS", "AdressS", "CityS", "StateS", 1, "NameR", "AdressR", "CityR", "StateR", 2, 3, 4, 4);
	cout << twoDayPackage.calculateCost() << endl;

	OvernightPackage overnightPackage("NameS", "AdressS", "CityS", "StateS", 1, "NameR", "AdressR", "CityR", "StateR", 2, 3, 4, 4);
	cout << overnightPackage.calculateCost() << endl;
	return 0;
}