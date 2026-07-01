#include <iostream>
#include <vector>

// Function to merge two sorted subarrays
template <typename T>
void merge(std::vector<T>& a, std::vector<T>& b, int i, int m, int j) {
    int p = i; // Pointer for the first subarray
    int q = m + 1; // Pointer for the second subarray

    // Copy elements from a to b
    for (int k = i; k <= j; ++k) {
        b[k] = a[k];
    }

    // Merge the two subarrays back into a
    for (int k = i; k <= j; ++k) {
        if (p == m + 1) {
            a[k] = b[q++];
        } else if (q > j || b[p] <= b[q]) {
            a[k] = b[p++];
        } else {
            a[k] = b[q++];
        }
    }
    
    // Print the array after merging
    std::cout << "Merged: ";
    for (int k = i; k <= j; ++k) {
        std::cout << a[k] << " ";
    }
    std::cout << std::endl;
}

// Recursive function to perform merge sort
template <typename T>
void mergeSort(std::vector<T>& a, std::vector<T>& b, int i, int j) {
    if (j - i < 1) {
        return;
    }
    
    int m = (i + j) / 2; // Calculate the midpoint
    std::cout << "midpoint: " << m << std::endl;

    // Recursively sort the first and second halves
    mergeSort(a, b, i, m);
    mergeSort(a, b, m + 1, j);

    // Merge the sorted halves
    merge(a, b, i, m, j);
}

// Function to perform Merge Sort
template <typename T>
void mergeSort(std::vector<T>& arr) {
    int n = arr.size();
    std::vector<T> aux(n); // Auxiliary array for merging

    // Call the recursive mergeSort function
    mergeSort(arr, aux, 0, n - 1);
}

// Function to print the array
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {4, 2, 7, 1, 9, 3};
    std::cout << "Original Array: ";
    printArray(arr);

    mergeSort(arr);

    std::cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
