//-------------------------------------------------------------------------------
// Programmer--Bryan Crawley
// Course------CS3123
// Project-----class demo
//
// This is the header file for a simple rational number class.
//-------------------------------------------------------------------------------
#include <vector>
#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int numerator;
	int denominator;
public:
	Rational(int n, int d);
	void show();
	friend Rational operator+(const Rational& a, const Rational& b);
private:
	void normalize();
	int gcd(int a, int b);
};

#endif
