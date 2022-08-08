#include "Package.h"

Package::Package(string psNane, string psAdress, string psCity, string psState, unsigned int psZipCode, string prNane, string prAdress, 
	string prCity, string prState, unsigned int prZipCode, double weight, double price)
{
	parcelSenderName = psNane;
	parcelSenderAdress = psAdress;
	parcelSenderCity = psCity;
	parcelSenderState = psState;
	parcelSenderZipCode = psZipCode;

	parcelRecipientName = prNane;
	parcelRecipientAdress = prAdress;
	parcelRecipientCity = prCity;
	parcelRecipientState = prState;
	parcelRecipientZipCode = prZipCode;

	weightOunce = weight > 0 ? weight : 0;
	pricePerOunce = price > 0 ? price : 0;
}

double Package::calculateCost()
{
	return weightOunce * pricePerOunce;
}

double Package::getWightOunce()
{
	return weightOunce;
}


double Package::getPricePerOunce()
{
	return pricePerOunce;
}
