#include "Hash_Table.h"
int main() {
    Set<int> s;
    initialize(s);
    int values[] = {-1,3,-5,7,-9,11,-13,12,-10,8,-6,4,-2,0};
    for (int i=0; i<14; i++)
        insert(s,values[i]);
    assert(!contains(s,15));
}