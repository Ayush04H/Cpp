#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at node i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Swap the root with the largest element

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    cout << "Sorted array is: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
