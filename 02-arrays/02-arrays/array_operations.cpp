#include <iostream>
using namespace std;

// ─────────────────────────────────────────
// TRAVERSAL — visit every element one by one
// Logic: start from index 0, go till last index
// Time: O(n) — depends on array size
// ─────────────────────────────────────────
void traversal(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        // i is the index, arr[i] is the value at that index
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ─────────────────────────────────────────
// INSERTION — insert a value at a given position
// Logic: shift all elements right from that position
//        then place the new value in the empty spot
// Time: O(n) — because shifting takes time
// ─────────────────────────────────────────
void insertion(int arr[], int &size, int pos, int value) {
    // shift elements to the right starting from the end
    // we go backwards so we don't overwrite anything
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1]; // move each element one step right
    }
    arr[pos] = value; // now the spot is empty, place the value
    size++;           // array has one more element now
    cout << "After inserting " << value << " at index " << pos << ": ";
    traversal(arr, size);
}

// ─────────────────────────────────────────
// DELETION — remove element at a given position
// Logic: shift all elements left from that position
//        this overwrites the deleted element naturally
// Time: O(n) — shifting again
// ─────────────────────────────────────────
void deletion(int arr[], int &size, int pos) {
    cout << "Deleting element " << arr[pos] << " at index " << pos << endl;
    // shift elements to the left starting from deleted position
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1]; // each element pulls the next one into its place
    }
    size--; // array has one less element now
    cout << "After deletion: ";
    traversal(arr, size);
}

// ─────────────────────────────────────────
// LINEAR SEARCH — find a value by checking one by one
// Logic: go through every element, compare with target
//        stop when found or reach the end
// Time: O(n) worst case — target might be at the end
// ─────────────────────────────────────────
void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            // found it — print index and stop
            cout << "Linear Search: " << target << " found at index " << i << endl;
            return; // no need to check further
        }
    }
    // if loop finishes without returning, element was not found
    cout << "Linear Search: " << target << " not found" << endl;
}

// ─────────────────────────────────────────
// BINARY SEARCH — find a value by halving the search space
// Logic: only works on SORTED arrays
//        check the middle element each time
//        if target is smaller → search left half
//        if target is bigger  → search right half
//        keep halving until found or nothing left
// Time: O(log n) — much faster than linear
// ─────────────────────────────────────────
void binarySearch(int arr[], int size, int target) {
    int left = 0;          // start of search range
    int right = size - 1;  // end of search range

    while (left <= right) {
        int mid = (left + right) / 2; // find the middle index

        if (arr[mid] == target) {
            // middle element is the target — done
            cout << "Binary Search: " << target << " found at index " << mid << endl;
            return;
        }
        else if (arr[mid] < target) {
            // target is in the RIGHT half — move left boundary up
            left = mid + 1;
        }
        else {
            // target is in the LEFT half — move right boundary down
            right = mid - 1;
        }
    }
    cout << "Binary Search: " << target << " not found" << endl;
}

// ─────────────────────────────────────────
// MAIN — where everything runs
// ─────────────────────────────────────────
int main() {

    // we give extra space (10) because insertion needs room
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5; // only 5 elements filled right now

    cout << "── TRAVERSAL ──" << endl;
    traversal(arr, size);

    cout << "\n── INSERTION ──" << endl;
    insertion(arr, size, 2, 99); // insert 99 at index 2

    cout << "\n── DELETION ──" << endl;
    deletion(arr, size, 3); // delete element at index 3

    cout << "\n── LINEAR SEARCH ──" << endl;
    linearSearch(arr, size, 40); // search for 40
    linearSearch(arr, size, 99); // search for 99

    cout << "\n── BINARY SEARCH ──" << endl;
    // binary search needs sorted array
    int sortedArr[] = {10, 20, 30, 40, 50, 60, 70};
    int sortedSize = 7;
    binarySearch(sortedArr, sortedSize, 40); // should find it
    binarySearch(sortedArr, sortedSize, 55); // should not find it

    return 0;
}