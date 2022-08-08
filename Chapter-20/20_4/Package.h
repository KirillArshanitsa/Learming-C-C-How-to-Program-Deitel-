#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using std::string;

class Package
{

public:
	Package(string, string, string, string, unsigned int, string, string, string, string, unsigned int, double, double);
	double calculateCost();
	double getWightOunce();
	double getPricePerOunce();

private:
	string parcelSenderName;
	string parcelSenderAdress;
	string parcelSenderCity;
	string parcelSenderState;
	unsigned int parcelSenderZipCode;

	string parcelRecipientName;
	string parcelRecipientAdress;
	string parcelRecipientCity;
	string parcelRecipientState;
	unsigned int parcelRecipientZipCode;

	double weightOunce;
	double pricePerOunce;
};

#endif 

