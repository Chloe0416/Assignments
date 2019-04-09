#include <iostream>
#include <cstdlib>
#include <cassert>
#include "a11_fraction.h"
using namespace std;

namespace cs_fraction {
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
		int intPart = num.numerator / num.denominator;
		if (intPart == 0) {
			if (num.numerator == 0) {
				outputStream << 0;
			}
			else {
				outputStream << num.numerator << "/" << num.denominator;
			}
		}
		else if (intPart < 0) {
			if (num.numerator % num.denominator == 0) {
				outputStream << intPart;
			}
			else {
				outputStream << intPart << "+" << -(num.numerator % num.denominator) << "/" << num.denominator;

			}
		}
		else {
			if (num.numerator % num.denominator == 0) {
				outputStream << intPart;
			}
			else {
				outputStream << intPart << "+" << num.numerator % num.denominator << "/" << num.denominator;
			}
		}
		return outputStream;
	}

	istream& operator>> (istream& inputStream, Fraction& num)
	{
		int intPart = 0;
		inputStream >> num.numerator;
		if (inputStream.peek() == '+') {
			inputStream.ignore();
			intPart = num.numerator;
			inputStream >> num.numerator;
		}
		if (inputStream.peek() == '/') {
			inputStream.ignore();
			inputStream >> num.denominator;
		}
		if (intPart < 0) {
			num.numerator = intPart * num.denominator - num.numerator;
		}
		else {
			num.numerator = num.numerator + intPart * num.denominator;
		}
		return inputStream;
	}


	void Fraction::simplify()
	{
		if (numerator == 0) {
			denominator = 1;
		}
		else if (numerator%denominator == 0)
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
				for (int i = denominator; i >= 2; i--)
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
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}
}

