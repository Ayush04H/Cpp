#include <iostream>
using namespace std;

int getElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return arr[index];
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    try {
        cout << "Element: " << getElement(arr, 5, 7) << endl;
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
