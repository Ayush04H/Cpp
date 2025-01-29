#include <iostream>
#include <vector>
using namespace std;

// Regular Bubble Sort
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Optimized Bubble Sort
void optimizedBubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) { // If no elements were swapped, break early
            break;
        }
    }
}

int main() {
    // First test with basic Bubble Sort
    vector<int> arr1 = {1, 4, 7, 9, 7, 6, 5, 0, 100};
    bubbleSort(arr1);
    cout << "Sorted using regular Bubble Sort: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Second test with Optimized Bubble Sort
    vector<int> arr2 = {10, 8, 20, 5, 110, 0, 63, 87, 12, 11};
    optimizedBubbleSort(arr2);
    cout << "Sorted using Optimized Bubble Sort: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
