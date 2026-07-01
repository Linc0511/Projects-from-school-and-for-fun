//-------------------------------------------------------------------------------
// Programmer--Bryan Crawley
// Course------CS3123
// Project-----class demo
//
// This file contains the main program to demonstrate a simple rational number
// class.
//-------------------------------------------------------------------------------

#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
	Rational a(1,4);
	Rational b(2,5);
	Rational sum(1,1);

	sum = a + b;
	sum.show();
	cout << endl;

	return 0;
}
