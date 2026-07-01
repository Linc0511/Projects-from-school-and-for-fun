#include <iostream>
#include <cassert>
#include "AVL_Tree.h"
using namespace std;

int main()
{
    Set<int> s;
    initialize(s);
    assert(size(s) == 0);
    insert(s,42);
    assert(size(s) == 1);
    assert(!contains(s,1));
    assert(contains(s,42));
    for (int i=0; i<50; i++)
        insert(s,i);
    assert(size(s) == 50);
    for (int i=0; i<100; i+=3)
        remove(s,i);
    assert(contains(s,1));
    destroy(s);
    //Set<int> s;
    initialize(s);

    // Test 1: Empty set
    assert(size(s) == 0);

    // Test 2: Insert one element
    insert(s, 42);
    assert(size(s) == 1);
    assert(contains(s, 42));
    assert(!contains(s, 1));

    // Test 3: Insert multiple elements
    for (int i = 0; i < 50; i++)
        insert(s, i);
    std::cout << size(s) << std::endl; // Print the size for debugging
    assert(size(s) == 51); // Assuming 1 element is already inserted
    std::cout << size(s) << std::endl; // Print the size for debugging

    for (int i = 0; i < 50; i++)
        assert(contains(s, i));

    // Test 4: Remove some elements
    for (int i = 0; i < 100; i += 3)
        remove(s, i);
    assert(size(s) == 34); // 51 - 17 removed
    assert(contains(s, 1));
    assert(!contains(s, 9));
    assert(!contains(s, 15));
    assert(!contains(s, 18));
    assert(!contains(s, 21));
    assert(!contains(s, 24));
    assert(!contains(s, 27));
    assert(!contains(s, 30));
    assert(!contains(s, 33));
    assert(!contains(s, 36));
    assert(!contains(s, 39));
    assert(!contains(s, 42));
    assert(!contains(s, 45));
    assert(!contains(s, 48));

    // Test 5: Destroy the set
    destroy(s);
    assert(size(s) == 0);
}