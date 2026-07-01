//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123
// Project-----01 Days of Our Lives
//
// This is the header file for a calander class
//-------------------------------------------------------------------------------

#ifndef CALENDER_H
#define CALENDER_H
class Calender 
{
private:
    int month;
    int year;
    
public:
    Calender(int m, int y);
    void increment_month(int increment);
    void increment_year(int increment);
    void display_calender();           
};

#endif