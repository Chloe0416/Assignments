class Fraction
{
public:
	Fraction();
	Fraction(int num1, int num2);

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