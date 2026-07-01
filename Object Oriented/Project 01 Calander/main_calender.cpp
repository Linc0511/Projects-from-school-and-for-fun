//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123
// Project-----01 Days of Our Lives
//
// This is the implementation file for a clander class that displays a classic 
// calender and supports users changing the month and date to display the 
// correct date.
//-------------------------------------------------------------------------------
#include <iostream>
#include "calender.h"
#include <string>
#include <limits>
using namespace std;


int main()
{
    int month, year;
    string operation;
    
    cout << "Month .... ";
    cin >> month;
    cout << "Year ..... ";
    cin >> year;
    cout << "\n";
    cin.ignore();
    
    Calender cal(month, year);

    while (true) 
    {
        cout << "Operation (d, im, iy) ... ";
        std::getline(cin, operation);
        
        if (operation == "d") 
        {
            cal.display_calender();
        }
        else if (operation == "im") 
        {
            int increment;
            cout << "...Increment ............ ";
            cin >> increment;
            cin.ignore();
            cal.increment_month(increment);
        }
        else if (operation == "iy") 
        {
            int increment;
            cout << "...Increment ............ ";
            cin >> increment;
            cin.ignore();
            cal.increment_year(increment); 
        }
        else if (operation.empty()) 
        {
            break;
        }
    }
    return 0;
}