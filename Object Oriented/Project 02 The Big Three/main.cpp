//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----02 Binary Search Tree
// Due Date----February 27, 2026
//
// // This is the implementation file for a Binary Search Tree class and a test 
// function called test 3 which tets all the operations for the class.
//-------------------------------------------------------------------------------

#include <iostream>
#include "SearchTree.h"

//-------------------------------------------------------------------------------
// test3
//
// Receives a SearchTree by value exercising the copy constructor, prints
// it, then returns exercising the destructor.
//-------------------------------------------------------------------------------
void test3(SearchTree gold) {
    std::cout << "Gold tree after test3: ";
    gold.print();
}

int main() 
{
    SearchTree purple, gold;

    for (int i = 0; i < 10; i++) 
    {
        int num;
        std::cout << "Enter integer " << (i + 1) << ": ";
        std::cin >> num;
        purple.insert(num);
    }

    std::cout << "Purple tree: ";
    purple.print();

    gold = purple;

    test3(gold);

    return 0;
}