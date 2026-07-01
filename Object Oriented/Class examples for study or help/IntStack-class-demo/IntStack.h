//----------------------------------------------------------------
// Programmer -- Bryan Crawley
// Course ------ CS3123
// Project ----- Class demo
//
// This file contains the declaration of the IntStack
// class. See the IntStack.cpp file for the implementation
// of the functions.
//----------------------------------------------------------------

#ifndef INTSTACK_H
#define INTSTACK_H

//----------------------------------------------------------------
// struct Node
//----------------------------------------------------------------

struct Node {
	int data;
	Node *link;
};

//----------------------------------------------------------------
// class IntStack
//----------------------------------------------------------------

class IntStack {
   private:
	   Node *top;

   public:
	  // Constructors
	  IntStack();
	  IntStack(const IntStack &original);

	  // Destructor
	  ~IntStack();

	  // Overloaded operators
	  void operator=(const IntStack &original);

	  // Stack operations
     void push(int newValue);
	  int pop();
	  int peek();
	  bool isEmpty();
	  int size();

   private:
     // Assistants
     void deleteList();
     Node *duplicateList() const;
};

#endif
