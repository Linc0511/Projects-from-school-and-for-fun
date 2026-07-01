//-----------------------------------------------------------------
// Programmer -- Bryan Crawley
// Project ----- Class demo
// Course ------ CS3123
// Semester ---- Spring 2025
//
// This file contains the main program to drive a demonstration
// of a stack of integers.
//-----------------------------------------------------------------


#include <iostream>     // For cin, cout, and endl
#include "IntStack.h"
using namespace std;

int main()
{
	IntStack s;
	IntStack r;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	r = s;

	cout << r.pop() << endl;
	cout << r.pop() << endl;
	cout << r.pop() << endl;
	cout << r.pop() << endl;

	return 0;
}
