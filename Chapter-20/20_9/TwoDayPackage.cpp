#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(string psNane, string psAdress, string psCity, string psState, unsigned int psZipCode, string prNane, string prAdress,
	string prCity, string prState, unsigned int prZipCode, double weight, double price, double margin)
	:Package(psNane,  psAdress,  psCity,  psState,  psZipCode,  prNane,  prAdress, prCity, prState,  prZipCode,  weight, price)
{
	this->margin = margin;
}

double TwoDayPackage::calculateCost()
{
	return Package::calculateCost() + margin;
}