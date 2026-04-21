#include <iostream>
using namespace std;

// O(1) - Constant time
void constantTime(int arr[], int size) {
    cout << "First element: " << arr[0] << endl;
}

// O(n) - Linear time
void linearTime(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "O(1) Example: " << endl;
    constantTime(arr, size);

    cout << "O(n) Example: " << endl;
    linearTime(arr, size);

    return 0;
}