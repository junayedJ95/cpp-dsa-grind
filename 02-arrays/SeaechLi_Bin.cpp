#include <iostream>
using namespace std;

// Function Prototypes
int searchlinear(int arr[], int size, int element);
int binarySearch(int arr[], int size, int element);

int main() {

    // Unsorted array for Linear Search
    int arr[] = {1, 2, 3, 4, 5, 22, 42, 33, 43, 2, 2, 45, 333};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // ---------- Linear Search ----------
    int linearIndex = searchlinear(arr, size, 42);

    if(linearIndex != -1)
        cout << "Linear Search: Element found at index " << linearIndex << endl;
    else
        cout << "Linear Search: Element not found!" << endl;

    cout << endl;

    // ---------- Sorted Array for Binary Search ----------
    int sortedArr[] = {1, 2, 3, 4, 5, 22, 33, 42, 43, 45, 333};
    int sortedSize = sizeof(sortedArr) / sizeof(sortedArr[0]);

    cout << "Sorted Array: ";
    for(int i = 0; i < sortedSize; i++){
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    int binaryIndex = binarySearch(sortedArr, sortedSize, 42);

    if(binaryIndex != -1)
        cout << "Binary Search: Element found at index " << binaryIndex << endl;
    else
        cout << "Binary Search: Element not found!" << endl;

    return 0;
}


// ---------- Linear Search ----------
int searchlinear(int arr[], int size, int element){

    for(int i = 0; i < size; i++){

        if(arr[i] == element){
            return i;
        }
    }

    return -1;
}


// ---------- Binary Search ----------
int binarySearch(int arr[], int size, int element){

    int low = 0;
    int high = size - 1;

    while(low <= high){

        int mid = (low + high) / 2;

        if(arr[mid] == element){
            return mid;
        }

        else if(arr[mid] < element){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }

    return -1;
}