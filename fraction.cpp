#include <iostream>
#include <cstdlib>
#include <cassert>
#include "fraction.h"

using namespace std;

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int num) {
	numerator = num;
	denominator = 1;
}

Fraction::Fraction(int num1, int num2) {
	assert(num2 != 0);
	Fraction temp;
	temp.numerator = num1;
	temp.denominator = num2;
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
	return temp;
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
	return temp;

}

Fraction Fraction::multipliedBy(const Fraction num) const
{
	Fraction temp(numerator * num.numerator, denominator * num.denominator);
	return temp;
}

Fraction Fraction::divideBy(const Fraction num)const
{
	Fraction temp(numerator * num.denominator, denominator * num.numerator);
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

const bool operator <(const Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		if (num1.numerator < num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (num1.numerator*num2.denominator < num1.denominator*num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
}


const bool operator <=(const Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		if (num1.numerator <= num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (num1.numerator*num2.denominator <= num1.denominator*num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
}


const bool operator >(const Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		if (num1.numerator > num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (num1.numerator*num2.denominator > num1.denominator*num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
}


const bool operator >=(const Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		if (num1.numerator >= num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (num1.numerator*num2.denominator >= num1.denominator*num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
}


const bool operator ==(const Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		if (num1.numerator == num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (num1.numerator*num2.denominator == num1.denominator*num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
}


const bool operator !=(const Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		if (num1.numerator != num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (num1.numerator*num2.denominator != num1.denominator*num2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
}

const Fraction operator +(const Fraction& num1, const Fraction& num2)
{
	Fraction temp;
	if (num1.denominator == num2.denominator) {
		temp.denominator = num1.denominator;
		temp.numerator = num1.numerator + num2.numerator;
	}
	else {
		temp.denominator = num1.denominator * num2.denominator;
		temp.numerator = num1.numerator * num2.denominator + num1.denominator * num2.numerator;
	}
	return temp;
}

const Fraction operator -(const Fraction& num1, const Fraction& num2)
{
	Fraction temp;
	if (num1.denominator == num2.denominator) {
		temp.denominator = num1.denominator;
		temp.numerator = num1.numerator - num2.numerator;
	}
	else {
		temp.denominator = num1.denominator * num2.denominator;
		temp.numerator = num1.numerator * num2.denominator - num1.denominator * num2.denominator;
	}
	return temp;
}

const Fraction operator *(const Fraction& num1, const Fraction& num2)
{
	Fraction temp(num1.numerator * num2.numerator, num1.denominator * num2.denominator);
	return temp;
}

const Fraction operator /(const Fraction& num1, const Fraction& num2)
{
	Fraction temp(num1.numerator * num2.denominator, num1.denominator * num2.numerator);
	return temp;
}

Fraction operator +=(Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		num1.numerator = num1.numerator + num2.numerator;
	}
	else {
		num1.denominator = num1.denominator * num2.denominator;
		num1.numerator = num1.numerator * num2.denominator + num1.denominator * num2.numerator;
	}
	return num1;
}

Fraction operator -=(Fraction& num1, const Fraction& num2)
{
	if (num1.denominator == num2.denominator) {
		num1.numerator = num1.numerator - num2.numerator;
	}
	else {
		num1.denominator = num1.denominator * num2.denominator;
		num1.numerator = num1.numerator * num2.denominator - num1.denominator * num2.denominator;
	}
	return num1;
}

Fraction operator *=(Fraction& num1, const Fraction& num2)
{
	num1.numerator = num1.numerator * num2.numerator;
	num1.denominator = num1.denominator * num2.denominator;
	return num1;
}

Fraction operator /=(Fraction& num1, const Fraction& num2)
{
	num1.numerator = num1.numerator * num2.denominator;
	num1.denominator = num1.denominator * num2.numerator;
	return num1;
}

Fraction Fraction::operator ++(int num)
{
	numerator += denominator;
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator --(int num)
{
	numerator -= denominator;
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator ++()
{
	numerator += denominator;
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator --()
{
	numerator -= denominator;
	return Fraction(numerator, denominator);
}

ostream& operator<< (ostream& outputStream, const Fraction& num)
{
	outputStream << num.numerator << "/" << num.denominator;

	return outputStream;
}
