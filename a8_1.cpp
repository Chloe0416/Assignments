#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction();

	void set(int num1, int num2);
	Fraction addTo(Fraction num);
	Fraction subtract(Fraction num);
	Fraction multipliedBy(Fraction num);
	Fraction divideBy(Fraction num);
	bool isEqualTo(Fraction num);
	void print();

private:
	int numerator;
	int denominator;
};

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}


void Fraction::set(int num1, int num2) {
	numerator = num1;
	denominator = num2;
}

Fraction Fraction::addTo(Fraction num) {
	Fraction temp;
	if (denominator == num.denominator) {
		temp.denominator = denominator;
		temp.numerator = numerator + num.numerator;
	}
	else {
		temp.denominator = denominator * num.denominator;
		temp.numerator = numerator * num.denominator + denominator * num.denominator;
	}
	return temp;
}

Fraction Fraction::subtract(Fraction num) {
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

Fraction Fraction::multipliedBy(Fraction num) {
	Fraction temp;
	temp.denominator = denominator * num.denominator;
	temp.numerator = numerator * num.numerator;
	return temp;

}

Fraction Fraction::divideBy(Fraction num) {
	Fraction temp;
	temp.denominator = denominator * num.numerator;
	temp.numerator = numerator * num.denominator;
	return temp;

}

bool Fraction::isEqualTo(Fraction num)
{
	if (numerator * num.denominator == denominator * num.numerator)
		return true;
	return false;
}

void Fraction::print()
{
	cout << numerator << "/" << denominator;
}


int main()
{
	Fraction f1;
	Fraction f2;
	Fraction result;

	f1.set(9, 8);
	f2.set(2, 3);

	cout << "The product of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.multipliedBy(f2);
	result.print();
	cout << endl;

	cout << "The quotient of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.divideBy(f2);
	result.print();
	cout << endl;

	cout << "The sum of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.addTo(f2);
	result.print();
	cout << endl;

	cout << "The difference of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.subtract(f2);
	result.print();
	cout << endl;

	if (f1.isEqualTo(f2)) {
		cout << "The two Fraction are equal." << endl;
	}
	else {
		cout << "The two Fraction are not equal." << endl;
	}
	

	system("pause");
	return 0;
}