#include <iostream>
using namespace std;

// ─────────────────────────────────────────
// LINEAR SEARCH
// Logic: check every element one by one
//        works on ANY array — sorted or not
//        stop the moment you find the target
// Time: O(n) — worst case, target is at the end
// ─────────────────────────────────────────
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // found — return index immediately, no need to go further
        }
    }
    return -1;  // looped through everything, target was never found
}

// ─────────────────────────────────────────
// BINARY SEARCH
// Logic: ONLY works on SORTED arrays
//        each step — check the middle element
//        if target is smaller → ignore right half, search left
//        if target is bigger  → ignore left half, search right
//        each step cuts the problem in HALF
// Time: O(log n) — far faster than linear on large arrays
// ─────────────────────────────────────────
int binarySearch(int arr[], int size, int target) {
    int low  = 0;         // left boundary of search range
    int high = size - 1;  // right boundary of search range

    while (low <= high) {
        int mid = (low + high) / 2;  // middle index of current range

        if (arr[mid] == target) {
            return mid;              // found exactly at middle
        }
        else if (arr[mid] < target) {
            low = mid + 1;           // target is bigger — move to right half
        }
        else {
            high = mid - 1;          // target is smaller — move to left half
        }
    }
    return -1;  // search range collapsed, target not in array
}

int main() {

    // ── Linear Search — works on unsorted ──
    int arr[] = {1, 2, 3, 4, 5, 22, 42, 33, 43, 2, 45, 333};
    int size   = sizeof(arr) / sizeof(arr[0]);  // calculate size automatically

    cout << "Array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    int li = linearSearch(arr, size, 42);
    if (li != -1)
        cout << "Linear Search: 42 found at index " << li << endl;
    else
        cout << "Linear Search: 42 not found" << endl;

    // ── Binary Search — must be sorted ──
    int sortedArr[] = {1, 2, 3, 4, 5, 22, 33, 42, 43, 45, 333};
    int sortedSize   = sizeof(sortedArr) / sizeof(sortedArr[0]);

    cout << "\nSorted Array: ";
    for (int i = 0; i < sortedSize; i++) cout << sortedArr[i] << " ";
    cout << endl;

    int bi = binarySearch(sortedArr, sortedSize, 42);
    if (bi != -1)
        cout << "Binary Search: 42 found at index " << bi << endl;
    else
        cout << "Binary Search: 42 not found" << endl;

    return 0;
}