//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123
// Project-----01 Days of Our Lives
//
// This is the implementation file for a calender class.
//-------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include "calender.h"
using namespace std;

//-------------------------------------------------------------------------------
// getDaysInMonth(int, int)
//
// Uses the Zeller's congruence formula to calcualte the day of the week a given
// month in a given year starts on.
//-------------------------------------------------------------------------------
int zellersCongruence(int month, int year)
{
    int m = month;
    int y = year;
    
    if (m < 3)
    {
        m += 12;
        y -= 1;
    }
    
    int q = 1;
    int k = y % 100;
    int j = y / 100;
    
    int h = (q + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    
    int dayOfWeek = (h + 6) % 7;
    
    return dayOfWeek;
}

//-------------------------------------------------------------------------------
// isLeapYear(int)
//
// Tests a given year to see if it is a leap year, returns true or false.
//-------------------------------------------------------------------------------
bool isLeapYear(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    if (year % 100 == 0)
    {
        return false;
    }
    if (year % 4 == 0)
    {
        return true;
    }
    return false;
}

//-------------------------------------------------------------------------------
// getDaysInMonth(int, int)
//
// Returns the number of days for a specific month of the year.
//-------------------------------------------------------------------------------
int getDaysInMonth(int month, int year)
{
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

//-------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------

Calender::Calender(int m, int y)
{
	month = m;
	year = y;
	return;
}

//-------------------------------------------------------------------------------
// increment_month(int)
//
// Adds an integer to the month and increment the year if needed.
//-------------------------------------------------------------------------------

void Calender::increment_month(int increment)
{
    month += increment;

	while (month > 12)
	{
		month -= 12;
		year++;
	}

	while (month < 1)
	{
		month += 12;
		year--;
	}
}

//-------------------------------------------------------------------------------
// increment_year(int)
// 
// Add an integer number of the user's choice to the year.
//-------------------------------------------------------------------------------
void Calender::increment_year(int increment)
{
    year += increment;
}

//-------------------------------------------------------------------------------
// display_calender()
// 
// Print the calander to the consul output in the standard calender format.
//-------------------------------------------------------------------------------
void Calender::display_calender()
{
    cout << "\n";
	string months[] = {"", "January", "February", "March", "April", "May", 
                       "June", "July", "August", "September", "October", 
                       "November", "December"};

    int start_day = zellersCongruence(month, year);
	int days_in_month = getDaysInMonth(month, year);

	string month_year = months[month] + " " + to_string(year);
    cout << std::setw((20 + month_year.length()) / 2) << month_year << endl;
    cout << "Su Mo Tu We Th Fr Sa" << endl;

	for (int i = 0; i < start_day; i++)
	{
		cout << "   ";
	}

	int current_column = start_day;
	for (int day = 1; day <= days_in_month; day++)
	{
		if (day < 10)
        {
            cout << " " << day << " ";
        }
        else
        {
            cout << day << " ";
        }
        
        current_column++;
        
        if (current_column == 7)
        {
            cout << endl;
            current_column = 0;
        }
    }
    
    if (current_column != 0)
    {
        cout << endl;
    }
    cout << "\n"; 
}

