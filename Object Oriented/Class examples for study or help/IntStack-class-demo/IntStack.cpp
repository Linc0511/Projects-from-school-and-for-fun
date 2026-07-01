//-------------------------------------------------------------------
// Programmer-- Bryan Crawley
// Course ----- CS3123
// Project----- Class demo
//
// This file contains the implementation of the IntStack
// class. See also the IntStack.h header file.
//-------------------------------------------------------------------

#include <cstdlib>    // For exit(), EXIT_FAILURE
#include <iostream>   // For cerr and endl
#include "IntStack.h" // For the class declaration

using namespace std;

//-------------------------------------------------------------------
// Default constructor
//-------------------------------------------------------------------

IntStack::IntStack()
{
	top = NULL;
	return;
}

//-------------------------------------------------------------------
// Copy constructor
//-------------------------------------------------------------------

IntStack::IntStack(const IntStack &original)
{
	top = original.duplicateList();
	return;
}

//-------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------

IntStack::~IntStack()
{
	deleteList();
	return;
}

//-------------------------------------------------------------------
// Overloaded assignment operator
//-------------------------------------------------------------------

void IntStack::operator=(const IntStack &original)
{
	if (this == &original)
		return;

	if (top != NULL)
		deleteList();

	top = original.duplicateList();
	return;
}

//-------------------------------------------------------------------
// push
//-------------------------------------------------------------------

void IntStack::push(int newValue)
{
	Node *p;
	
	p = new Node;
	if (p == NULL) {
		cerr << "Error: Insufficient memory" << endl;
		exit(EXIT_FAILURE);
	}
	p->data = newValue;
	p->link = top;
	top = p;

	return;
}

//-------------------------------------------------------------------
// pop
//-------------------------------------------------------------------

int IntStack::pop()
{
	int value;
	Node *p;

	if (top == NULL) {
		cerr << "Error: stack underflow" << endl;
		exit(EXIT_FAILURE);
	}

	value = top->data;
	p = top;
	top = top->link;
	delete p;
	return value;
}

//-------------------------------------------------------------------
// peek
//-------------------------------------------------------------------

int IntStack::peek()
{
	if (top == NULL) {
		cerr << "Error: peeking at an empty stack" << endl;
		exit(EXIT_FAILURE);
	}

	return top->data;
}

//-------------------------------------------------------------------
// isEmpty
//-------------------------------------------------------------------

bool IntStack::isEmpty()
{
	return (top == NULL);
}

//-------------------------------------------------------------------
// size
//-------------------------------------------------------------------

int IntStack::size()
{
	int count;
	Node *p;

	count = 0;
	p = top;

	while (p != NULL) {
		p = p->link;
		count++;
	}

	return count;
}

//-------------------------------------------------------------------
// deleteList
//-------------------------------------------------------------------

void IntStack::deleteList()
{
	Node *p;

	while (top != NULL) {
		p = top;
		top = top->link;
		delete p;
	}

	return;
}

//-------------------------------------------------------------------
// duplicateList
//-------------------------------------------------------------------

Node *IntStack::duplicateList() const
{
	Node *p;
	Node *newNode;
	Node *previousNode;
	Node *newTop;

	p = top;

	while (p != NULL) {
		newNode = new Node;
		if (newNode == NULL) {
			cerr << "Error: Insufficient memory" << endl;
			exit(EXIT_FAILURE);
		}
		if (p == top)
			newTop = newNode;
		else
			previousNode->link = newNode;
		newNode->data = p->data;
		previousNode = newNode;
		p = p->link;
	}

	if (top == NULL)
		newTop = NULL;
	else
		newNode->link = NULL;

	return newTop;
}
