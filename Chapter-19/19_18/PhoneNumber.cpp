#include <iomanip> 
using std::setw;

#include "PhoneNumber.h" 


ostream& operator<< (ostream & output, const PhoneNumber & number)
{
	output << "(" << number.areaCode << ") "
		<< number.exchange << "-" << number.line;
	return output; // допускает форму cout << a << b << c; 
} 


istream& operator>>(istream& input, PhoneNumber& number)
{
	input.ignore(); 

	input >> setw(3) >> number.areaCode; // ввести код региона 
	input.ignore(2); // пропустить ) и пробел 
	input >> setw(3) >> number.exchange; // ввести код АТС 
	input.ignore(); // пропустить дефис (-) 
	input >> setw(4) >> number.line; // ввести номер линии 
	return input; // допускает форму cin >> a >> b >> c; 
} 

