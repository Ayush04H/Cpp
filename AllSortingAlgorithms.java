import java.util.Arrays;

public class AllSortingAlgorithms {

    // Global test array content to be used for each sort
    private static final int[] TEST_ARRAY_CONTENT = {2, 5, 6, 3, 1};

    // Helper method to print arrays
    public static void printArray(String prefix, int[] arr) {
        System.out.println(prefix + Arrays.toString(arr));
    }

    // Helper method to swap elements in an array
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // --- 1. Bubble Sort ---
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            // Last i elements are already in place
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
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
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            // Swap the found minimum element with the first element of the unsorted part
            if (minIdx != i) {
                swap(arr, i, minIdx);
            }
        }
    }

    // --- 3. Insertion Sort ---
    public static void insertionSort(int[] arr) {
        int n = arr.length;
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
    // This version returns a new sorted array.
    public static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) {
            return arr;
        }

        int mid = arr.length / 2;
        int[] lHalf = Arrays.copyOfRange(arr, 0, mid);
        int[] rHalf = Arrays.copyOfRange(arr, mid, arr.length);

        int[] lSorted = mergeSort(lHalf); // Recursively sort left half
        int[] rSorted = mergeSort(rHalf); // Recursively sort right half

        // Merge the two sorted halves
        return merge(lSorted, rSorted);
    }

    private static int[] merge(int[] left, int[] right) {
        int[] mergedArray = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                mergedArray[k++] = left[i++];
            } else {
                mergedArray[k++] = right[j++];
            }
        }

        // Copy remaining elements of left (if any)
        while (i < left.length) {
            mergedArray[k++] = left[i++];
        }

        // Copy remaining elements of right (if any)
        while (j < right.length) {
            mergedArray[k++] = right[j++];
        }
        return mergedArray;
    }

    // --- 5. Quick Sort (Lomuto Partition Scheme) ---
    private static int partitionLomuto(int[] arr, int low, int high) {
        int pivot = arr[high]; // Choose the last element as pivot
        int i = low - 1;       // Pointer for the greater element

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high); // Place pivot in correct position
        return i + 1;          // Return the partitioning index
    }

    private static void quickSortLomutoRecursive(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partitionLomuto(arr, low, high);
            quickSortLomutoRecursive(arr, low, pi - 1);  // Sort left of pivot
            quickSortLomutoRecursive(arr, pi + 1, high); // Sort right of pivot
        }
    }

    public static void quickSortLomuto(int[] arr) {
        if (arr == null || arr.length == 0) return;
        quickSortLomutoRecursive(arr, 0, arr.length - 1);
    }

    // --- 6. Quick Sort (Hoare Partition Scheme) ---
    private static int partitionHoare(int[] arr, int low, int high) {
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
            swap(arr, i, j);
        }
    }

    private static void quickSortHoareRecursive(int[] arr, int low, int high) {
        if (low < high) {
            // pi is partitioning index, arr[low...pi] <= arr[pi+1...high]
            int pi = partitionHoare(arr, low, high);

            // Recursively sort elements before partition and after partition
            quickSortHoareRecursive(arr, low, pi);      // Sort the left partition (including pi)
            quickSortHoareRecursive(arr, pi + 1, high); // Sort the right partition
        }
    }

    public static void quickSortHoare(int[] arr) {
        if (arr == null || arr.length == 0) return;
        quickSortHoareRecursive(arr, 0, arr.length - 1);
    }

    // --- 7. Heap Sort ---
    private static void heapify(int[] arr, int n, int i) { // n is size of heap, i is index of root of subtree
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
            swap(arr, i, largest);
            // Heapify the root of the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    public static void heapSort(int[] arr) {
        int n = arr.length;

        // 1. Build a maxheap.
        // For a 0-indexed array, the last non-leaf node is at index (n / 2 - 1).
        // We build the heap in a bottom-up manner.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // 2. One by one extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root (max element in the current heap) to end
            swap(arr, 0, i);

            // Call max heapify on the reduced heap (size is i)
            heapify(arr, i, 0);
        }
    }


    public static void main(String[] args) {
        System.out.println("Original Test Array Content: " + Arrays.toString(TEST_ARRAY_CONTENT));
        System.out.println("==================================================\n");

        // --- Test Bubble Sort ---
        System.out.println("--- Testing Bubble Sort ---");
        int[] arrToSortBubble = Arrays.copyOf(TEST_ARRAY_CONTENT, TEST_ARRAY_CONTENT.length);
        printArray("Original array:", arrToSortBubble);
        bubbleSort(arrToSortBubble);
        printArray("Sorted array:  ", arrToSortBubble);
        System.out.println("--------------------------------------------------\n");

        // --- Test Selection Sort ---
        System.out.println("--- Testing Selection Sort ---");
        int[] arrToSortSelection = Arrays.copyOf(TEST_ARRAY_CONTENT, TEST_ARRAY_CONTENT.length);
        printArray("Original array:", arrToSortSelection);
        selectionSort(arrToSortSelection);
        printArray("Sorted array:  ", arrToSortSelection);
        System.out.println("--------------------------------------------------\n");

        // --- Test Insertion Sort ---
        System.out.println("--- Testing Insertion Sort ---");
        int[] arrToSortInsertion = Arrays.copyOf(TEST_ARRAY_CONTENT, TEST_ARRAY_CONTENT.length);
        printArray("Original array:", arrToSortInsertion);
        insertionSort(arrToSortInsertion);
        printArray("Sorted array:  ", arrToSortInsertion);
        System.out.println("--------------------------------------------------\n");

        // --- Test Merge Sort ---
        System.out.println("--- Testing Merge Sort ---");
        int[] arrToSortMerge = Arrays.copyOf(TEST_ARRAY_CONTENT, TEST_ARRAY_CONTENT.length);
        printArray("Original array:", arrToSortMerge);
        // Merge sort returns a new array
        arrToSortMerge = mergeSort(arrToSortMerge);
        printArray("Sorted array:  ", arrToSortMerge);
        System.out.println("--------------------------------------------------\n");

        // --- Test Quick Sort (Lomuto) ---
        System.out.println("--- Testing Quick Sort (Lomuto Partition) ---");
        int[] arrToSortQLomuto = Arrays.copyOf(TEST_ARRAY_CONTENT, TEST_ARRAY_CONTENT.length);
        printArray("Original array:", arrToSortQLomuto);
        quickSortLomuto(arrToSortQLomuto);
        printArray("Sorted array:  ", arrToSortQLomuto);
        System.out.println("--------------------------------------------------\n");

        // --- Test Quick Sort (Hoare) ---
        System.out.println("--- Testing Quick Sort (Hoare Partition) ---");
        int[] arrToSortQHoare = Arrays.copyOf(TEST_ARRAY_CONTENT, TEST_ARRAY_CONTENT.length);
        printArray("Original array:", arrToSortQHoare);
        quickSortHoare(arrToSortQHoare);
        printArray("Sorted array:  ", arrToSortQHoare);
        System.out.println("--------------------------------------------------\n");

        // --- Test Heap Sort ---
        System.out.println("--- Testing Heap Sort ---");
        int[] arrToSortHeap = Arrays.copyOf(TEST_ARRAY_CONTENT, TEST_ARRAY_CONTENT.length);
        printArray("Original array:", arrToSortHeap);
        heapSort(arrToSortHeap);
        printArray("Sorted array:  ", arrToSortHeap);
        System.out.println("--------------------------------------------------\n");
    }
}