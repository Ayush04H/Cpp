#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::swap (optional, can be manual)

// Global test array content to be used for each sort
const std::vector<int> TEST_ARRAY_CONTENT = {2, 5, 6, 3, 1};

// Helper method to print arrays
void printArray(const std::string& prefix, const std::vector<int>& arr) {
    std::cout << prefix;
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Helper method to swap elements in an array (std::swap is also available)
void swapElements(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    // Or using std::swap: std::swap(arr[i], arr[j]);
}

// --- 1. Bubble Sort ---
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Last i elements are already in place
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapElements(arr, j, j + 1);
                swapped = true;
            }
        }
        // If no two elements were swapped in inner loop, array is sorted
        if (!swapped) {
            break;
        }
    }
}

// --- 2. Selection Sort ---
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (minIdx != i) {
            swapElements(arr, i, minIdx);
        }
    }
}

// --- 3. Insertion Sort ---
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// --- 4. Merge Sort ---
// Forward declaration for the merge helper function
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);

// This version returns a new sorted vector.
std::vector<int> mergeSort(const std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    std::vector<int> lHalf(arr.begin(), arr.begin() + mid);
    std::vector<int> rHalf(arr.begin() + mid, arr.end());

    std::vector<int> lSorted = mergeSort(lHalf); // Recursively sort left half
    std::vector<int> rSorted = mergeSort(rHalf); // Recursively sort right half

    // Merge the two sorted halves
    return merge(lSorted, rSorted);
}

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> mergedArray;
    mergedArray.reserve(left.size() + right.size()); // Optional: pre-allocate memory
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            mergedArray.push_back(left[i++]);
        } else {
            mergedArray.push_back(right[j++]);
        }
    }

    // Copy remaining elements of left (if any)
    while (i < left.size()) {
        mergedArray.push_back(left[i++]);
    }

    // Copy remaining elements of right (if any)
    while (j < right.size()) {
        mergedArray.push_back(right[j++]);
    }
    return mergedArray;
}

// --- 5. Quick Sort (Lomuto Partition Scheme) ---
int partitionLomuto(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Pointer for the element smaller than pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swapElements(arr, i, j);
        }
    }
    swapElements(arr, i + 1, high); // Place pivot in correct position
    return i + 1;                  // Return the partitioning index
}

void quickSortLomutoRecursive(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionLomuto(arr, low, high);
        quickSortLomutoRecursive(arr, low, pi - 1);  // Sort left of pivot
        quickSortLomutoRecursive(arr, pi + 1, high); // Sort right of pivot
    }
}

void quickSortLomuto(std::vector<int>& arr) {
    if (arr.empty()) return;
    quickSortLomutoRecursive(arr, 0, arr.size() - 1);
}

// --- 6. Quick Sort (Hoare Partition Scheme) ---
int partitionHoare(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // Choose the first element as pivot
    int i = low - 1;      // Left pointer
    int j = high + 1;     // Right pointer

    while (true) {
        // Move left pointer to the right while element is less than pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Move right pointer to the left while element is greater than pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If pointers have crossed or met, partition is done
        if (i >= j) {
            return j; // j is the partition point (last index of the left partition)
        }

        // Swap elements at i and j
        swapElements(arr, i, j);
    }
}

void quickSortHoareRecursive(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[low...pi] <= arr[pi+1...high]
        int pi = partitionHoare(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSortHoareRecursive(arr, low, pi);      // Sort the left partition (including pi)
        quickSortHoareRecursive(arr, pi + 1, high); // Sort the right partition
    }
}

void quickSortHoare(std::vector<int>& arr) {
    if (arr.empty()) return;
    quickSortHoareRecursive(arr, 0, arr.size() - 1);
}

// --- 7. Heap Sort ---
void heapify(std::vector<int>& arr, int n, int i) { // n is size of heap, i is index of root of subtree
    int largest = i;         // Initialize largest as root
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    // See if left child of root exists and is greater than root
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    // See if right child of root exists and is greater than the current largest
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    // Change root, if needed
    if (largest != i) {
        swapElements(arr, i, largest);
        // Heapify the root of the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // 1. Build a maxheap.
    // For a 0-indexed array, the last non-leaf node is at index (n / 2 - 1).
    // We build the heap in a bottom-up manner.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 2. One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max element in the current heap) to end
        swapElements(arr, 0, i);

        // Call max heapify on the reduced heap (size is i)
        heapify(arr, i, 0);
    }
}


int main() {
    std::cout << "Original Test Array Content: ";
    printArray("", TEST_ARRAY_CONTENT); // Print the global constant vector
    std::cout << "==================================================\n" << std::endl;

    // --- Test Bubble Sort ---
    std::cout << "--- Testing Bubble Sort ---" << std::endl;
    std::vector<int> arrToSortBubble = TEST_ARRAY_CONTENT; // Creates a copy
    printArray("Original array:", arrToSortBubble);
    bubbleSort(arrToSortBubble);
    printArray("Sorted array:  ", arrToSortBubble);
    std::cout << "--------------------------------------------------\n" << std::endl;

    // --- Test Selection Sort ---
    std::cout << "--- Testing Selection Sort ---" << std::endl;
    std::vector<int> arrToSortSelection = TEST_ARRAY_CONTENT;
    printArray("Original array:", arrToSortSelection);
    selectionSort(arrToSortSelection);
    printArray("Sorted array:  ", arrToSortSelection);
    std::cout << "--------------------------------------------------\n" << std::endl;

    // --- Test Insertion Sort ---
    std::cout << "--- Testing Insertion Sort ---" << std::endl;
    std::vector<int> arrToSortInsertion = TEST_ARRAY_CONTENT;
    printArray("Original array:", arrToSortInsertion);
    insertionSort(arrToSortInsertion);
    printArray("Sorted array:  ", arrToSortInsertion);
    std::cout << "--------------------------------------------------\n" << std::endl;

    // --- Test Merge Sort ---
    std::cout << "--- Testing Merge Sort ---" << std::endl;
    std::vector<int> arrToSortMerge = TEST_ARRAY_CONTENT;
    printArray("Original array:", arrToSortMerge);
    // Merge sort returns a new vector
    arrToSortMerge = mergeSort(arrToSortMerge);
    printArray("Sorted array:  ", arrToSortMerge);
    std::cout << "--------------------------------------------------\n" << std::endl;

    // --- Test Quick Sort (Lomuto) ---
    std::cout << "--- Testing Quick Sort (Lomuto Partition) ---" << std::endl;
    std::vector<int> arrToSortQLomuto = TEST_ARRAY_CONTENT;
    printArray("Original array:", arrToSortQLomuto);
    quickSortLomuto(arrToSortQLomuto);
    printArray("Sorted array:  ", arrToSortQLomuto);
    std::cout << "--------------------------------------------------\n" << std::endl;

    // --- Test Quick Sort (Hoare) ---
    std::cout << "--- Testing Quick Sort (Hoare Partition) ---" << std::endl;
    std::vector<int> arrToSortQHoare = TEST_ARRAY_CONTENT;
    printArray("Original array:", arrToSortQHoare);
    quickSortHoare(arrToSortQHoare);
    printArray("Sorted array:  ", arrToSortQHoare);
    std::cout << "--------------------------------------------------\n" << std::endl;

    // --- Test Heap Sort ---
    std::cout << "--- Testing Heap Sort ---" << std::endl;
    std::vector<int> arrToSortHeap = TEST_ARRAY_CONTENT;
    printArray("Original array:", arrToSortHeap);
    heapSort(arrToSortHeap);
    printArray("Sorted array:  ", arrToSortHeap);
    std::cout << "--------------------------------------------------\n" << std::endl;

    return 0;
}