//-------------------------------------------------------------------------------
// Programmer--Bryan Crawley
// Course------CS3123
// Project-----class demo
//
// This is the implementation file for a simple rational number class.
//-------------------------------------------------------------------------------

#include <iostream>
#include "Rational.h"
using namespace std;

//-------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------

Rational::Rational(int n, int d)
	{
		numerator = n;
		denominator = d;
		return;
	}

//-------------------------------------------------------------------------------
// show
//-------------------------------------------------------------------------------

void Rational::show()
{
	cout << numerator << "/" << denominator;
	return;
}


//-------------------------------------------------------------------------------
// gcd
//-------------------------------------------------------------------------------

int Rational::gcd(int a, int b)
{
	int d;
	int temp;

	while (a != b) {
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}
		d = a - b;
		a = b;
		b = d;
	}

	return a;
}

//-------------------------------------------------------------------------------
// normalize
//-------------------------------------------------------------------------------

void Rational::normalize()
{
	int divisor;

	divisor = gcd(numerator, denominator);
	numerator = numerator/divisor;
	denominator = denominator/divisor;

	return;
}


//-------------------------------------------------------------------------------
// Overloaded + operator
//
// Notice that this function isn't a method of the Rational class.
//-------------------------------------------------------------------------------

Rational operator+(const Rational& a, const Rational& b)
{
	int num;
	int denom;

	denom = b.denominator * a.denominator;
	num = b.numerator * a.denominator + a.numerator * b.denominator;

	Rational result(num, denom);
	result.normalize();
	return result;
}

