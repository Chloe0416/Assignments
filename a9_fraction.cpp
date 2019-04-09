#include <iostream>
#include <cassert>
#include "a9_fraction.h"
using namespace std;

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int num1, int num2) {
	assert(num2 != 0);
	Fraction temp;
	temp.numerator = num1;
	temp.denominator = num2;
	temp.simplify();
	numerator = temp.numerator;
	denominator = temp.denominator;

}

Fraction Fraction::addTo(const Fraction num) const 
{
	Fraction temp;
	if (denominator == num.denominator) {
		temp.denominator = denominator;
		temp.numerator = numerator + num.numerator;
	}
	else {
		temp.denominator = denominator * num.denominator;
		temp.numerator = numerator * num.denominator + denominator * num.numerator;
	}
	temp.simplify();
	return temp;
;
}

Fraction Fraction::subtract(const Fraction num) const 
{
	Fraction temp;
	if (denominator == num.denominator) {
		temp.denominator = denominator;
		temp.numerator = numerator - num.numerator;
	}
	else {
		temp.denominator = denominator * num.denominator;
		temp.numerator = numerator * num.denominator - denominator * num.denominator;
	}
	temp.simplify();
	return temp;

}

Fraction Fraction:: multipliedBy(const Fraction num) const 
{
	Fraction temp(numerator * num.numerator, denominator * num.denominator);
	temp.simplify();
	return temp;
}

Fraction Fraction::divideBy(const Fraction num)const
{
	Fraction temp(numerator * num.denominator, denominator * num.numerator);
	temp.simplify();
	return temp;

}

bool Fraction::isEqualTo(const Fraction num)const
{
	if (numerator * num.denominator == denominator * num.numerator)
		return true;
	return false;
}

void Fraction::print()const
{
	cout << numerator << "/" << denominator;
}

void Fraction::simplify()
{
	if (numerator%denominator == 0)
	{
		numerator = numerator / denominator;
		denominator = 1;
	}
	else if (denominator%numerator == 0)
	{
		denominator = denominator / numerator;
		numerator = 1;
	}
	else
	{
		if (numerator > denominator) {
			for (int i = denominator; i >=2; i--)
			{
				if (numerator%i == 0 && denominator%i == 0)
				{
					numerator = numerator / i;
					denominator = denominator / i;
				}
			}
		}
		else if (numerator < denominator) {
			for (int i = numerator; i >= 2; i--)
			{
				if (numerator%i == 0 && denominator%i == 0)
				{
					numerator = numerator / i;
					denominator = denominator / i;
				}
			}
		}
	}
}
