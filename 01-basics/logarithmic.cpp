#include <iostream>
using namespace std;

// Binary Search - O(log n)

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2; // find middle

        if (arr[mid] == target)
            return mid;          // found it!
        else if (arr[mid] < target)
            left = mid + 1;      // go right half
        else
            right = mid - 1;     // go left half
    }
    return -1;     // not found
}

int main() {
    int arr[] = {1, 2, 3, 9, 24, 27}; // sorted array
    int size = 6;
    int target = 24;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}