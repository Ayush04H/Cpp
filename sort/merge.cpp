#include <iostream>
#include <vector>
using namespace std;

// Merge function to merge two sorted halves
void merge(vector<int>& arr, int left, int mid, int right) {
    // Create temporary arrays for left and right halves
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    // Merge the two parts
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }

    // Copy remaining elements from leftPart
    while (i < leftPart.size()) {
        arr[k++] = leftPart[i++];
    }

    // Copy remaining elements from rightPart
    while (j < rightPart.size()) {
        arr[k++] = rightPart[j++];
    }
}

// MergeSort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Recursively sort both halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {10, 8, 20, 5, 110, 0, 63, 87, 12, 11};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
