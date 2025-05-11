def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search_iterative(arr, target):
    if not arr:
        return -1
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def _binary_search_recursive_helper(arr, target, low, high):
    if high < low:
        return -1
    mid = (low + high) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return _binary_search_recursive_helper(arr, target, mid + 1, high)
    else:
        return _binary_search_recursive_helper(arr, target, low, mid - 1)

def binary_search_recursive(arr, target):
    if not arr:
        return -1
    return _binary_search_recursive_helper(arr, target, 0, len(arr) - 1)

def run_search_tests():
    unsorted_list = [2, 5, 1, 8, 3, 9, 4, 7, 6]
    sorted_list = sorted(unsorted_list.copy())
    empty_list = []

    targets_to_test = [
        {"value": 5, "desc": "element present in middle"},
        {"value": 1, "desc": "element present at beginning (for sorted)"},
        {"value": 9, "desc": "element present at end (for sorted)"},
        {"value": 10, "desc": "element not present"},
        {"value": 0, "desc": "element not present (smaller than all)"},
        {"value": 100, "desc": "element not present (larger than all)"},
    ]

    print("--- Testing Linear Search ---")
    for t_info in targets_to_test:
        target = t_info["value"]
        result = linear_search(unsorted_list, target)
        print(f"Searching for {target} in {unsorted_list}: Index = {result} ({t_info['desc']})")
    result_empty = linear_search(empty_list, 5)
    print(f"Searching for 5 in {empty_list}: Index = {result_empty} (empty list)")
    print("-" * 30)

    print("\n--- Testing Binary Search (Iterative) ---")
    print(f"(Using sorted list: {sorted_list})")
    for t_info in targets_to_test:
        target = t_info["value"]
        result = binary_search_iterative(sorted_list, target)
        print(f"Searching for {target}: Index = {result} ({t_info['desc']})")
    result_empty = binary_search_iterative(empty_list, 5)
    print(f"Searching for 5 in {empty_list}: Index = {result_empty} (empty list)")
    print("-" * 30)

    print("\n--- Testing Binary Search (Recursive) ---")
    print(f"(Using sorted list: {sorted_list})")
    for t_info in targets_to_test:
        target = t_info["value"]
        result = binary_search_recursive(sorted_list, target)
        print(f"Searching for {target}: Index = {result} ({t_info['desc']})")
    result_empty = binary_search_recursive(empty_list, 5)
    print(f"Searching for 5 in {empty_list}: Index = {result_empty} (empty list)")
    print("-" * 30)

    another_list = [67, 23, 90, 11, 54, 33]
    target_val = 54
    print(f"\n--- Example: Binary Search on an initially unsorted list ---")
    print(f"Original list: {another_list}, target: {target_val}")
    another_list_sorted = sorted(another_list)
    print(f"Sorted list:   {another_list_sorted}")
    result = binary_search_iterative(another_list_sorted, target_val)
    print(f"Result of binary search for {target_val}: Index = {result}")
    print("-" * 30)

if __name__ == "__main__":
    run_search_tests()