#include <iostream>
#include <vector>
using namespace std;

// Lomuto partition scheme
int lomutoPartition(vector<int>& arr, int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[h]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int p = lomutoPartition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

int main() {
    vector<int> arr = {8, 4, 7, 9, 3, 10, 5};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
