#include <iostream>

template <typename T>
void printArray(T *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void bubbleSort(T *array, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 1; j < size - i; ++j) {
            if (array[j - 1] > array[j]) {
                std::swap(array[j - 1], array[j]);
            }
            std::cout << "Array inside while loop: ";
            printArray(array, size);
        }
    }
}


int main() {
    int array[] = {4, 2, 7, 1, 9, 3};
    size_t array_size = sizeof(array) / sizeof(array[0]);

    std::cout << "Array before sorting: ";
    printArray(array, array_size);

    bubbleSort(array, array_size);

    std::cout << "Array after sorting: ";
    printArray(array, array_size);

    return 0;
}
