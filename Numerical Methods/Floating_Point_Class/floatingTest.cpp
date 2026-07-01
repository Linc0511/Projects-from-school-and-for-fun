#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    double x = 1.0;
    while (x+1.0 != x) { 
        x*=2;
        printf("%f\n", x);
        //if (x >= INFINITY) break;
    }
        
}