#include <iostream>
#include <vector>

// Function to print the array
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Function to find the pivot index
template <typename T>
int findPivot(std::vector<T>& arr, int i, int j) {
    return (i + j) / 2; // Choosing the middle element as pivot
}

// Function to partition the array
template <typename T>
int partition(std::vector<T>& arr, int i, int j, int p) {
    int pivot = arr[p]; // Pivot element
    int left = i; // Left pointer
    int right = j - 1; // Right pointer

    // Print the pivot
    std::cout << "Pivot: " << pivot << std::endl;

    // Partitioning step
    while (left <= right) {
        // Find element on the left side that is greater than or equal to the pivot
        while (left <= right && arr[left] < pivot) {
            left++;
        }

        // Find element on the right side that is less than or equal to the pivot
        while (left <= right && arr[right] >= pivot) {
            right--;
        }

        // Swap the elements if they are out of place
        if (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    // Swap the pivot element to its correct position
    std::swap(arr[left], arr[j]);

    // Print the array after partitioning
    std::cout << "Partitioned Array: ";
    printArray(arr);

    return left; // Return the pivot index
}

// Recursive function to perform Quicksort
template <typename T>
void quickSort(std::vector<T>& arr, int i, int j) {
    if (i < j) {
        int p = findPivot(arr, i, j); // Find the pivot index
        std::swap(arr[p], arr[j]); // Move the pivot to the end
        int k = partition(arr, i, j, j); // Partition the array
        quickSort(arr, i, k - 1); // Recursively sort the left subarray
        quickSort(arr, k + 1, j); // Recursively sort the right subarray
    }
}

// Function to perform Quicksort
template <typename T>
void quickSort(std::vector<T>& arr) {
    int n = arr.size();
    quickSort(arr, 0, n - 1);
}

int main() {
    std::vector<int> arr = {4, 2, 7, 1, 9, 3};
    std::cout << "Original Array: ";
    printArray(arr);

    quickSort(arr);

    std::cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
