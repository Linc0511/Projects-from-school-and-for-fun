//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----Program 03 Parent and Child
// Due---------March 18, 2026
//
// Implementation file for both the IntList base class and the IntStack derived
// class. IntList handles dynamic memory management while IntStack implements 
// stack operations (push, pop, show) in the Intlist.
//-------------------------------------------------------------------------------

#include "IntListStack.h"



//-------------------------------------------------------------------------------
// IntList()
//
// Default constructor sets capacity to zero and data pointer to null.
//-------------------------------------------------------------------------------
IntList::IntList() 
{
    capacity = 0;
    data     = nullptr;
}

//-------------------------------------------------------------------------------
// IntList(int cap)
//
// Capacity constructor creates a dynamic array of the size given by the user.
//-------------------------------------------------------------------------------
IntList::IntList(int cap) 
{
    capacity = cap;
    data     = new int[capacity];
}

//-------------------------------------------------------------------------------
// IntList(const IntList& other)
//
// Copy constructor. Allocates a new array and copies all elements from other.
//-------------------------------------------------------------------------------
IntList::IntList(const IntList& other) 
{
    capacity = other.capacity;
    if (capacity > 0) 
    {
        data = new int[capacity];
        for (int i = 0; i < capacity; i++)
            data[i] = other.data[i];
    } 
    else 
    {
        data = nullptr;
    }
}

//-------------------------------------------------------------------------------
// operator=(const IntList& other)
//
// Assignment operator. Frees existing memory then performs a deep copy.
//-------------------------------------------------------------------------------
IntList& IntList::operator=(const IntList& other) 
{
    if (this != &other) 
    {
        delete[] data;
        capacity = other.capacity;
        if (capacity > 0) 
        {
            data = new int[capacity];
            for (int i = 0; i < capacity; i++)
                data[i] = other.data[i];
        } 
        else 
        {
            data = nullptr;
        }
    }
    return *this;
}

//-------------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------------
IntList::~IntList() 
{
    delete[] data;
    data = nullptr;
}

//-------------------------------------------------------------------------------
// IntStack()
//
// Default constructor calls IntList default constructor and sets size to zero.
//-------------------------------------------------------------------------------
IntStack::IntStack() : IntList() 
{
    size = 0;
}

//-------------------------------------------------------------------------------
// IntStack(int cap)
//
// Capicity constructor calls IntList capacity constructor and sets size to zero.
//-------------------------------------------------------------------------------
IntStack::IntStack(int cap) : IntList(cap) 
{
    size = 0;
}

//-------------------------------------------------------------------------------
// IntStack(const IntStack& other)
//
// Copy constructor. Deep copies base class data then copies size.
//-------------------------------------------------------------------------------
IntStack::IntStack(const IntStack& other) : IntList(other) 
{
    size = other.size;
}

//-------------------------------------------------------------------------------
// operator=(const IntStack& other)
//
// Assignment operator. Delegates base copy to IntList::operator= then copies size.
//-------------------------------------------------------------------------------
IntStack& IntStack::operator=(const IntStack& other) 
{
    if (this != &other) 
    {
        IntList::operator=(other);
        size = other.size;
    }
    return *this;
}

//-------------------------------------------------------------------------------
// Destructor the parent class handles the deletion of the data.
//-------------------------------------------------------------------------------
IntStack::~IntStack() 
{
}

//-------------------------------------------------------------------------------
// push(int value)
//
// Pushes value onto the stack and returns an error if the stack is full.
//-------------------------------------------------------------------------------
bool IntStack::push(int value) 
{
    if (size >= capacity) 
    {
        cout << "  Error: Stack is full. Cannot push " << value << "." << endl;
        return false;
    }
    data[size] = value;
    size++;
    return true;
}

//-------------------------------------------------------------------------------
// pop(int& value)
//
// Removes and returns the top element and gives an error message 
// if the stack is empty.
//-------------------------------------------------------------------------------
bool IntStack::pop(int& value) 
{
    if (size <= 0) 
    {
        cout << "  Error: Stack is empty. Nothing to pop." << endl;
        return false;
    }
    size--;
    value = data[size];
    return true;
}

//-------------------------------------------------------------------------------
// show()
//
// Prints the stack contents bottom is on the left and gives a message 
// if the stack is empty.
//-------------------------------------------------------------------------------
void IntStack::show() const 
{
    if (size == 0) 
    {
        cout << "  (stack is empty)" << endl;
        return;
    }
    cout << "  Stack (bottom -> top): ";
    for (int i = 0; i < size; i++) 
    {
        cout << data[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}
