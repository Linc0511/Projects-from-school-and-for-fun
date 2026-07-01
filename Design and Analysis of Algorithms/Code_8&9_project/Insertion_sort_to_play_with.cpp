#include <iostream>

// Forward declaration of printArray function
template <typename T>
void printArray(T *items, size_t n);

template <typename T>
void sort(T *items, size_t n) {
    for (size_t i = 0; i < n; i++) {
        size_t j = i; 
        while (j > 0 && items[j] < items[j-1]){
            std::swap(items[j], items[j - 1]);
            std::cout << "Array inside while loop: ";
            printArray(items, n);
            j--;
        }
    }
}

template <typename T>
void printArray(T *items, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int array[] = {4, 2, 7, 1, 9, 3};
    size_t array_size = sizeof(array) / sizeof(array[0]);

    std::cout << "Array before sorting: ";
    printArray(array, array_size);

    sort(array, array_size);

    std::cout << "Array after sorting: ";
    printArray(array, array_size);

    return 0;
}

