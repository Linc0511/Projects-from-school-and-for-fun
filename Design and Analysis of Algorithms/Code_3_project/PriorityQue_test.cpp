#include <iostream>
#include <cassert>
#include "Priority_Queue.h"
using namespace std;

int main()
{
    PriorityQueue<int,string> pq;
    initialize(pq,10);
    assert(size(pq) == 0);
    std::string stringValue = "hi";
    
    // Use the converted string in the insert call
    insert(pq, 42, stringValue);
    assert(size(pq) == 1);
    auto x = pop(pq);
    assert(x == "hi");
    assert(size(pq) == 0);
    destroy(pq);
}