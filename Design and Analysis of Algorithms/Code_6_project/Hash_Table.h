#include <iostream>
#include <cassert>

enum Status { UNUSED, USED, TOMBSTONE };

template <typename T>
struct Bucket {
    Status status;
    T value;
};

template <typename T>
struct Set {
    Bucket<T> *table;
    int keys;
    int size;
};

template <typename T>
int hashKey(T value) {
    return static_cast<int>(value);
}

template <typename T>
void initialize(Set<T> &set) {
    set.table = new Bucket<T>[10];
    set.keys = 0;
    set.size = 10;
    for (int i = 0; i < set.size; ++i) {
        set.table[i].status = UNUSED;
    }
}

template <typename T>
void destroy(Set<T> &set) {
    delete[] set.table;
    set.keys = 0;
    set.size = 0;
    set.table = nullptr;
}

// Helper function to find the next available slot during insertion or resizing
template <typename T>
int findNextSlot(Bucket<T> *table, int size, T value) {
    int index = hashKey(value) % size;
    while (table[index].status == USED || table[index].status == TOMBSTONE)
        index = (index + 1) % size;
        
    return index;
}

template <typename T>
void insert(Set<T> &set, T item) {
    if (!contains(set, item)) {
        if (set.keys > set.size / 2) {
            int newSize = set.size * 2;
            Bucket<T> *newTable = new Bucket<T>[newSize];
            
            for (int i = 0; i < newSize; ++i)
                newTable[i].status = UNUSED;
            
            for (int i = 0; i < set.size; ++i) {
                if (set.table[i].status == USED) {
                    int index = findNextSlot(newTable, newSize, set.table[i].value);
                    newTable[index].status = USED;
                    newTable[index].value = set.table[i].value;
                }
            }
            
            delete[] set.table;
            set.table = newTable;
            set.size = newSize;
        }
        
        int index = findNextSlot(set.table, set.size, item);
        set.table[index].status = USED;
        set.table[index].value = item;
        set.keys++;
    }
}

template <typename T>
void remove(Set<T> &set, T item) {
    int index = hashKey(item) % set.size;
    while (set.table[index].status != UNUSED) {
        if (set.table[index].status == USED && set.table[index].value == item) {
            set.table[index].status = TOMBSTONE;
            set.keys--;
            return;
        }
        index = (index + 1) % set.size;
    }
}

template <typename T>
bool contains(Set<T> &set, T item) {
    int index = hashKey(item) % set.size;
    while (set.table[index].status != UNUSED) {
        if (set.table[index].status == USED && set.table[index].value == item)
            return true;

        index = (index + 1) % set.size;
    }
    return false;
}

template <typename T>
int size(Set<T> &set) {
    return set.keys;
}
