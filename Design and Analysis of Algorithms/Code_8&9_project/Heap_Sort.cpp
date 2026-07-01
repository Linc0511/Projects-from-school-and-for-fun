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

// Function to heapify a subtree rooted at index i
template <typename T>
void heapify(std::vector<T>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
template <typename T>
void heapSort(std::vector<T>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);

        // Print the array after each iteration
        std::cout << "Array after iteration " << n - i << ": ";
        printArray(arr);
    }
}

int main() {
    std::vector<int> arr = {4, 2, 7, 1, 9, 3};
    std::cout << "Original Array: ";
    printArray(arr);

    heapSort(arr);

    std::cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
