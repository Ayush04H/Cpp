#include <iostream>
#include <vector>
using namespace std;

// Hoare partition scheme
int hoarePartition(vector<int>& arr, int l, int h) {
    int pivot = arr[l];
    int i = l - 1;
    int j = h + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

// QuickSort function
void quickSort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int p = hoarePartition(arr, l, h);
        quickSort(arr, l, p);
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
