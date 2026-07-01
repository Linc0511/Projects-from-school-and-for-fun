using namespace std;
#include <iostream>
void d()
{ 
    // here
    cout << "first1" << endl;
}

void c()
{
    cout << "first2" << endl;
}

void b()
{
    c();
    cout << "first3" << endl;
    d();
}

void a()
{
    b();
    cout << "first4" << endl;
    c();
}

int main()
{
    a();
    cout << "first5" << endl;
    a();
}