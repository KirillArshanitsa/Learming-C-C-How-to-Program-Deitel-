#include <cctype> // прототип функции isdigit 
using std::isdigit;

#include <cstring> // прототип функции strlen 
using std::strlen;

#include "Hugeint.h" // определение класса Hugelnt 

#include <iostream> 
using std::cout;
using std::endl;

Hugelnt::Hugelnt(long value)
{
	// инициализировать массив нулем 
	for (int i = 0; i <= 29; i++)
		integer[i] = 0;

	// поместить в массив цифры аргумента 
	for (int j = 29; value != 0 && j >= 0; j--)
	{
		integer[j] = value % 10;
		value /= 10;
	} // end for 
} 

Hugelnt::Hugelnt(const char* string)
{
	// инициализировать массив нулем 
	for (int i = 0; i <= 29; i++)
		integer[i] = 0;

	// поместить в массив цифры аргумента 
	int length = strlen(string);

	for (int j = 30 - length, k = 0; j <= 29; j++, k++)
		if (isdigit(string[k]))
			integer[j] = string[k] - '0';
} 

Hugelnt Hugelnt::operator*(const Hugelnt& op2) const
{

	Hugelnt result;

	for (int e = 29, carry = 0, d = 1; e >= 0; e--, d *= 10) {
		Hugelnt temp; 
		for (int i = 29; i >= 0; i--){
			temp.integer[i] = integer[i] * op2.integer[e] + carry;
			if (temp.integer[i] > 9){
				carry = temp.integer[i] / 10;
				temp.integer[i] %= 10;
			}
			else
				carry = 0;
		}
		cout << "temp = " << temp << endl;
		if (temp.integer == 0)
			return result;

		if (e == 29)
			result = result + temp ;
		else
			result = result + (temp + d);

		cout << "result = " << result << endl;
	}
	return result;
}

Hugelnt Hugelnt::operator+(const Hugelnt& op2) const
{
	Hugelnt temp; // временный результат 
	int carry = 0;

	for (int i = 29; i >= 0; i--)
	{
		temp.integer[i] =
		integer[i] + op2.integer[i] + carry;

		// определить, нужен ли перенос 
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10; // редуцировать к 0-9 
			carry = 1;
		} // конец if 
		else // переноса нет 
			carry = 0;
	} // конец for 

	return temp; // возвратить копию временного объекта 
} 


Hugelnt Hugelnt::operator+(int op2) const
{

	return *this + Hugelnt(op2);
} 

Hugelnt Hugelnt::operator+(const char* op2) const
{

	return *this + Hugelnt(op2);
} 


ostream& operator<<(ostream &output, const Hugelnt& num)
{
	int i;

	for (i = 0; (num.integer[i] == 0) && (i <= 29); i++)
		;

	if (i == 30)
		 output << 0;
	else
		for (; i <= 29; i++)
			output << num.integer[i];

	return output;
}


bool Hugelnt::operator==(const Hugelnt& anotherHugelnt) const
{
	for (int i = 29; i < 0; i--) {
		if (integer[i] != anotherHugelnt.integer[i])
			return false;
	}
	return true;
}