#include <iostream>
#include "a10_fraction.h"
using namespace std;


int main()
{
	// Just some simple test cases
	Fraction f1;
	cout << f1;

	if (0 == f1) {
		cout << "true." << endl;
	}

	Fraction f2(2, 5);
	Fraction f3(3, 5);
	cout << f2 + f3 << endl;
	cout << f2/3 << endl;
	f2 += 1;
	cout << f2 << endl;
	f3++;
	cout << f3 << endl;
	--f3;
	cout << f3 << endl;

	system("pause");
	return 0;
}
