#include <iostream>
template <typename T> void sort(T *items, size_t n) {
    for (size_t i = 0; i < n; i++) {
        size_t j = i; 
        while (j > 0 && items[j] < items[j-1]){
            std::swap(items[j], items[j - 1]);
            j--;
        }
    }
}