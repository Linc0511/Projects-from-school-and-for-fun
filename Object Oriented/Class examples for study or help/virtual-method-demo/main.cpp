//---------------------------------------------------------------------
// Bryan Crawley
// CS3123
// Spring 2026
//
// This is a bare bones demonstration of virtual methods. See the
// accompanying files for the class declarations and implementations.
//---------------------------------------------------------------------

#include "virtual.h"
#include <iostream>
using namespace std;

int main()
{
   Parent robert;
   Child bobby;
   
   cout << endl;

   robert.someMethod();
   bobby.someMethod();
   cout << endl;

   robert = bobby;

   robert.someMethod();
   bobby.someMethod();
   cout << endl;

   Parent& robby {bobby};
   robby.someMethod();
   bobby.someMethod();
   cout << endl;

   return 0;
}
