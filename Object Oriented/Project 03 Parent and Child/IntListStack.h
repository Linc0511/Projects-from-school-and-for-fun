//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----Program 03 Parent and Child
// Due---------March 18, 2026
//
// Header file for both the IntList base class and the IntStack derived
// class. IntList manages a dynamically allocated array of integers. IntStack's
// operations apply the values onto the IntList dynamic array.
//-------------------------------------------------------------------------------

#ifndef INTLIST_INTSTACK_H
#define INTLIST_INTSTACK_H

#include <iostream>
using namespace std;

class IntList 
{
protected:
    int  capacity;
    int* data;

public:
    IntList();
    IntList(int cap);
    IntList(const IntList& other);
    IntList& operator=(const IntList& other);
    ~IntList();
};

class IntStack : public IntList 
{
private:
    int size;

public:
    IntStack();
    IntStack(int cap);
    IntStack(const IntStack& other);
    IntStack& operator=(const IntStack& other);
    ~IntStack();
    bool push(int value);
    bool pop(int& value);
    void show() const;
};

#endif
