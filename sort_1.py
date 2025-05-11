# Global test array content to be used for each sort
TEST_ARRAY_CONTENT = [2, 5, 6, 3, 1]

# --- 1. Bubble Sort ---
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        # Last i elements are already in place
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # If no two elements were swapped in inner loop, array is sorted
        if not swapped:
            break

print(f"\n--- Testing Bubble Sort ---")
arr_to_sort_bubble = TEST_ARRAY_CONTENT.copy()
print("Original array:", arr_to_sort_bubble)
bubble_sort(arr_to_sort_bubble)
print("Sorted array:  ", arr_to_sort_bubble)
print("-" * 30)


# --- 2. Selection Sort ---
def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        # Swap the found minimum element with the first element of the unsorted part
        if min_idx != i:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]

print(f"\n--- Testing Selection Sort ---")
arr_to_sort_selection = TEST_ARRAY_CONTENT.copy()
print("Original array:", arr_to_sort_selection)
selection_sort(arr_to_sort_selection)
print("Sorted array:  ", arr_to_sort_selection)
print("-" * 30)


# --- 3. Insertion Sort ---
def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

print(f"\n--- Testing Insertion Sort ---")
arr_to_sort_insertion = TEST_ARRAY_CONTENT.copy()
print("Original array:", arr_to_sort_insertion)
insertion_sort(arr_to_sort_insertion)
print("Sorted array:  ", arr_to_sort_insertion)
print("-" * 30)


# --- 4. Merge Sort ---
# This version returns a new sorted list.
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    L_half = arr[:mid]
    R_half = arr[mid:]

    L_sorted = merge_sort(L_half) # Recursively sort left half
    R_sorted = merge_sort(R_half) # Recursively sort right half

    # Merge the two sorted halves
    merged_array = []
    i = j = 0
    while i < len(L_sorted) and j < len(R_sorted):
        if L_sorted[i] < R_sorted[j]:
            merged_array.append(L_sorted[i])
            i += 1
        else:
            merged_array.append(R_sorted[j])
            j += 1
    
    # Append remaining elements (if any)
    merged_array.extend(L_sorted[i:])
    merged_array.extend(R_sorted[j:])
    
    return merged_array

print(f"\n--- Testing Merge Sort ---")
arr_to_sort_merge = TEST_ARRAY_CONTENT.copy()
print("Original array:", arr_to_sort_merge)
# Merge sort returns a new list, so we assign it back if we want the original variable to hold the sorted list
arr_to_sort_merge = merge_sort(arr_to_sort_merge)
print("Sorted array:  ", arr_to_sort_merge)
print("-" * 30)


# --- 5. Quick Sort (Lomuto Partition Scheme) ---
def _partition_lomuto(arr, low, high):
    pivot = arr[high]  # Choose the last element as pivot
    i = low - 1        # Pointer for the greater element

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            
    arr[i + 1], arr[high] = arr[high], arr[i + 1] # Place pivot in correct position
    return i + 1  # Return the partitioning index

def _quick_sort_lomuto_recursive(arr, low, high):
    if low < high:
        pi = _partition_lomuto(arr, low, high)
        _quick_sort_lomuto_recursive(arr, low, pi - 1)  # Sort left of pivot
        _quick_sort_lomuto_recursive(arr, pi + 1, high) # Sort right of pivot

def quick_sort_lomuto(arr):
    _quick_sort_lomuto_recursive(arr, 0, len(arr) - 1)

print(f"\n--- Testing Quick Sort (Lomuto Partition) ---")
arr_to_sort_q_lomuto = TEST_ARRAY_CONTENT.copy()
print("Original array:", arr_to_sort_q_lomuto)
quick_sort_lomuto(arr_to_sort_q_lomuto)
print("Sorted array:  ", arr_to_sort_q_lomuto)
print("-" * 30)


# --- 6. Quick Sort (Hoare Partition Scheme) ---
def _partition_hoare(arr, low, high):
    pivot = arr[low]  # Choose the first element as pivot
    i = low - 1       # Left pointer
    j = high + 1      # Right pointer

    while True:
        # Move left pointer to the right while element is less than pivot
        i += 1
        while arr[i] < pivot:
            i += 1
        
        # Move right pointer to the left while element is greater than pivot
        j -= 1
        while arr[j] > pivot:
            j -= 1

        # If pointers have crossed or met, partition is done
        if i >= j:
            return j # j is the partition point (last index of the left partition)
        
        # Swap elements at i and j
        arr[i], arr[j] = arr[j], arr[i]

def _quick_sort_hoare_recursive(arr, low, high):
    if low < high:
        # pi is partitioning index, arr[low...pi] <= arr[pi+1...high]
        pi = _partition_hoare(arr, low, high)
        
        # Recursively sort elements before partition and after partition
        _quick_sort_hoare_recursive(arr, low, pi)      # Sort the left partition (including pi)
        _quick_sort_hoare_recursive(arr, pi + 1, high) # Sort the right partition

def quick_sort_hoare(arr):
    if len(arr) > 0: # Handle empty array case, though recursive base case also handles it
      _quick_sort_hoare_recursive(arr, 0, len(arr) - 1)

print(f"\n--- Testing Quick Sort (Hoare Partition) ---")
arr_to_sort_q_hoare = TEST_ARRAY_CONTENT.copy()
print("Original array:", arr_to_sort_q_hoare)
quick_sort_hoare(arr_to_sort_q_hoare)
print("Sorted array:  ", arr_to_sort_q_hoare)
print("-" * 30)


# --- 7. Heap Sort ---
def _heapify(arr, n, i): # n is size of heap, i is index of root of subtree
    largest = i          # Initialize largest as root
    left_child = 2 * i + 1
    right_child = 2 * i + 2

    # See if left child of root exists and is greater than root
    if left_child < n and arr[left_child] > arr[largest]:
        largest = left_child

    # See if right child of root exists and is greater than the current largest
    if right_child < n and arr[right_child] > arr[largest]:
        largest = right_child

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap
        # Heapify the root of the affected sub-tree
        _heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # 1. Build a maxheap.
    # For a 0-indexed array, the last non-leaf node is at index (n // 2 - 1).
    # We build the heap in a bottom-up manner.
    for i in range(n // 2 - 1, -1, -1):
        _heapify(arr, n, i)

    # 2. One by one extract elements from heap
    for i in range(n - 1, 0, -1):
        # Move current root (max element in the current heap) to end
        arr[i], arr[0] = arr[0], arr[i]
        
        # Call max heapify on the reduced heap (size is i)
        _heapify(arr, i, 0)

print(f"\n--- Testing Heap Sort ---")
arr_to_sort_heap = TEST_ARRAY_CONTENT.copy()
print("Original array:", arr_to_sort_heap)
heap_sort(arr_to_sort_heap)
print("Sorted array:  ", arr_to_sort_heap)
print("-" * 30)