//----------------------------------------------------------------------
// Bryan Crawley
// CS3123
// Spring 2026
//
// This header file declares the Parent and Child classes for the
// bare bones demonstration of virtual methods.
//----------------------------------------------------------------------

#ifndef VIRTUAL_H
#define VIRTUAL_H

//----------------------------------------------------------------------
// Parent
//----------------------------------------------------------------------

class Parent
{
   public: 
      virtual void someMethod();

   protected:
      int someInt {0};
};

//----------------------------------------------------------------------
// Child
//----------------------------------------------------------------------

class Child: public Parent
{
   public:
      void someMethod() override;
};

#endif
