//----------------------------------------------------------------------
// Bryan Crawley
// CS3123
// Spring 2026
//
// This file implements the classes for the bare bones demonstration
// of virtual methods.
//----------------------------------------------------------------------

#include "virtual.h"
#include <iostream>
using namespace std;

//----------------------------------------------------------------------
// Parent::someMethod
//----------------------------------------------------------------------

void Parent::someMethod()
{
   cout << "Parent's version of someMethod()" << endl;
   return;
}

//----------------------------------------------------------------------
// Child:someMethod
//----------------------------------------------------------------------

void Child::someMethod()
{
   cout << "Child's version of someMethod()" << endl;
   
   return;
}
