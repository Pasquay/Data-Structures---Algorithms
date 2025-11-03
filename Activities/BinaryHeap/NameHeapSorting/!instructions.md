# Name Heap Sorting
by Edwin Bartlett

---

## Introduction

Write the code for heap sorting names from a given array. The following functions are required in `heapsort.c`:

---

## Function Specifications

### `void heapify(char *arr[], int n, int i)`
- The core heapify function. It maintains the max heap property in a subtree rooted at index `i`, comparing strings alphabetically. The alphabetically "larger" string is considered the maximum.
- **arr** – The array of string pointers.
- **n** – The size of the heap (the array portion being considered).
- **i** – The index of the root of the subtree to heapify.

### `void heapSort(char *arr[], int n)`
- The main function that implements Heap Sort for an array of strings. It sorts the strings in ascending alphabetical order (A-Z).
- **arr** – The array of string pointers to be sorted.
- **n** – The size of the array.

---

# TEST CASES

[#1] Sample Output 1
----------------------------------------------------
```
Original array of names: Charlie Alice Bob Eve David Frank
Sorted array of names:   Alice Bob Charlie David Eve Frank
```