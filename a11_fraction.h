#include <iostream>
using namespace std;

namespace cs_fraction {
	class Fraction
	{
	public:
		Fraction();
		Fraction(int num);
		Fraction(int num1, int num2);

		friend const bool operator <(const Fraction& num1, const Fraction& num2);
		friend const bool operator <=(const Fraction& num1, const Fraction& num2);
		friend const bool operator >(const Fraction& num1, const Fraction& num2);
		friend const bool operator >=(const Fraction& num1, const Fraction& num2);
		friend const bool operator ==(const Fraction& num1, const Fraction& num2);
		friend const bool operator !=(const Fraction& num1, const Fraction& num2);

		friend const Fraction operator +(const Fraction& num1, const Fraction& num2);
		friend const Fraction operator -(const Fraction& num1, const Fraction& num2);
		friend const Fraction operator *(const Fraction& num1, const Fraction& num2);
		friend const Fraction operator /(const Fraction& num1, const Fraction& num2);

		friend Fraction operator +=(Fraction& num1, const Fraction& num2);
		friend Fraction operator -=(Fraction& num1, const Fraction& num2);
		friend Fraction operator *=(Fraction& num1, const Fraction& num2);
		friend Fraction operator /=(Fraction& num1, const Fraction& num2);


		Fraction operator ++(int num);
		Fraction operator --(int num);
		Fraction operator ++();
		Fraction operator --();


		friend ostream& operator<< (ostream& outputStream, const Fraction& num);
		friend istream& operator>> (istream& inputStream, Fraction& num);

		Fraction addTo(const Fraction num)const;
		Fraction subtract(const Fraction num)const;
		Fraction multipliedBy(const Fraction num)const;
		Fraction divideBy(const Fraction num)const;
		bool isEqualTo(const Fraction num)const;
		void print()const;

	private:
		int numerator;
		int denominator;
		void simplify();
	};
}
