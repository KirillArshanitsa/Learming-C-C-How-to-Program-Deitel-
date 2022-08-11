#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package
{

public:
	TwoDayPackage(string, string, string, string, unsigned int, string, string, string, string, unsigned int, double, double, double);
	double calculateCost();

private:
	double margin;
};
#endif 

