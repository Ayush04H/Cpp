#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort function
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int x = arr[i];  // Element to be inserted
        int j = i - 1;

        // Move elements that are greater than x one position ahead
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = x;
    }
}

int main() {
    vector<int> arr = {10, 8, 20, 5, 110, 0, 63, 87, 12, 11};

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
