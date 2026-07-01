#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        std::cout << "Gap = " << gap << ": ";
        for (int k = 0; k < n; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
        
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            std::cout << "array inside insertion sort: ";
        for (int k = 0; k < n; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<int> arr = {4, 2, 7, 1, 9, 3};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    shellSort(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

