#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : protected Package
{
public:
	OvernightPackage(string, string, string, string, unsigned int, string, string, string, string, unsigned int, double, double, double);
	double calculateCost();
private:
	double margin;
};

#endif 

