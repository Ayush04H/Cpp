#include <iostream>
#include <vector>
using namespace std;

// Selection Sort function
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minInd = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        swap(arr[minInd], arr[i]);
    }
}

int main() {
    vector<int> arr = {10, 8, 20, 5, 110, 0, 63, 87, 12, 11};

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
