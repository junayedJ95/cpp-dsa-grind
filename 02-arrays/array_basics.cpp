#include <iostream>
using namespace std;

int main() {

    // ── DECLARING AN ARRAY ──
    int arr[6] = {17, 18, 19, 50, 0, 0};
    int size = 4; // only 4 elements filled

    // ── get(i) → O(1) ──
    cout << "First element: " << arr[0] << endl;
    cout << "Third element: " << arr[2] << endl;

    // ── set(i, num) → O(1) ──
    arr[2] = 99;
    cout << "After set(2, 99): " << arr[2] << endl;

    // ── print all → O(n) ──
    cout << "All elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ── insert at position → O(n) ──
    // insert 55 at index 1
    int insertPos = 1;
    int insertVal = 55;
    for (int i = size; i > insertPos; i--) {
        arr[i] = arr[i-1]; // shift right
    }
    arr[insertPos] = insertVal;
    size++;
    cout << "After insert 55 at index 1: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ── delete at position → O(n) ──
    int deletePos = 2;
    for (int i = deletePos; i < size - 1; i++) {
        arr[i] = arr[i+1]; // shift left
    }
    size--;
    cout << "After delete at index 2: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}