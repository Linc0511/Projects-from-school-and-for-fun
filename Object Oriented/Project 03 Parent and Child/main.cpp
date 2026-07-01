//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----Program 03 Parent and Child
// Due---------March 18, 2026
//
// Main program that demonstrates the IntStack class. The user selects a stack
// capacity, then can push, pop, show, and exit the program. The menu allows 
// users to manipualte the stack using the above functions.
//-------------------------------------------------------------------------------

#include <iostream>
#include "IntListStack.h"

using namespace std;

int main() 
{
    int capacity;

    cout << "Enter the stack capacity: ";
    cin  >> capacity;

    IntStack stack(capacity);

    int choice;

    while (choice != 4)
    {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "  1. Push a value" << endl;
        cout << "  2. Pop a value"  << endl;
        cout << "  3. Show stack"   << endl;
        cout << "  4. Quit"         << endl;
        cout << "Choice: ";
        cin  >> choice;

        if (choice == 1) 
        {
            cout << "  Enter positive integers to push (0 to stop):" << endl;
            int value;
            while (true) 
            {
                cout << "    Value: ";
                cin  >> value;
                if (value == 0)
                    break;
                else if (value < 0)
                    cout << "    Please enter a positive integer or 0 to stop." << endl;
                else
                    stack.push(value);
            }
            cout << "\n  After pushing:" << endl;
            stack.show();

        } 
        else if (choice == 2) 
        {
            int popCount;
            cout << "  How many entries to pop? ";
            cin  >> popCount;

            int popped;
            for (int i = 0; i < popCount; i++) {
                if (!stack.pop(popped))
                    break;
                cout << "  Popped: " << popped << endl;
            }
            cout << "\n  After popping:" << endl;
            stack.show();

        } 
        else if (choice == 3) 
        {
            stack.show();
        }
        else if (choice == 4)
        {
            break;
        }
        else 
        {
            cout << "  Invalid choice. Please enter 1-4." << endl;
        }

    }

    return 0;
}
