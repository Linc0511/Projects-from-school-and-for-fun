#include <iostream>

template <typename T>
void printArray(T *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void selectionSort(T *array, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        size_t k = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (array[j] > array[k]) {
                k = j;
            }
        }
        std::swap(array[k], array[i]);

        // Print the array at each iteration
        std::cout << "Array inside selection sort: ";
        printArray(array, size);
    }
}

int main() {
    int array[] = {4, 2, 7, 1, 9, 3};
    size_t array_size = sizeof(array) / sizeof(array[0]);

    std::cout << "Array before sorting: ";
    printArray(array, array_size);

    selectionSort(array, array_size);

    std::cout << "Array after sorting: ";
    printArray(array, array_size);

    return 0;
}
