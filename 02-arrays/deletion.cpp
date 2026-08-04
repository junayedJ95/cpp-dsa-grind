#include<iostream>
using namespace std;

// ─────────────────────────────────────────
// display — print all current elements
// same helper as insertion, reused here
// ─────────────────────────────────────────
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ─────────────────────────────────────────
// search — find the index of a value
// used inside deletion to find element by value
// returns index if found, -1 if not found
// Time: O(n) — linear search
// ─────────────────────────────────────────
int search(int arr[], int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i; // found — return its index
        }
    }
    return -1; // not found
}

// ─────────────────────────────────────────
// indexDeletion — delete element at a specific index
// Logic: shift everything LEFT from that position
//        each element pulls the next one into its place
//        size shrinks by 1 — last duplicate becomes invisible
// Returns: 1 = success, -1 = invalid index
// Time: O(n) — shifting takes time
// ─────────────────────────────────────────
int indexDeletion(int arr[], int &size, int index_){

    // guard clause — index must be within valid range
    if(index_ < 0 || index_ >= size){
        return -1; // invalid index, stop immediately
    }

    // shift elements left starting from deleted position
    // opposite of insertion — we go forward not backward
    for(int i = index_; i < size - 1; i++){
        arr[i] = arr[i + 1]; // pull next element into current position
    }

    size--; // one less element now — last duplicate is hidden
    return 1;
}

// ─────────────────────────────────────────
// valueDeletion — delete element by its value
// Logic: first FIND the index using search()
//        then delete at that index using indexDeletion()
//        two step process — search then delete
// Returns: 1 = success, -1 = value not found
// ─────────────────────────────────────────
int valueDeletion(int arr[], int &size, int value){

    // step 1 — find where this value lives
    int index_ = search(arr, size, value);

    // guard clause — if value doesn't exist, stop
    if(index_ == -1){
        return -1; // value not in array
    }

    // step 2 — delete at that found index
    return indexDeletion(arr, size, index_);
}

// ─────────────────────────────────────────
// firstDeletion — delete the very first element
// Logic: index 0 is always the first — just call indexDeletion
// ─────────────────────────────────────────
int firstDeletion(int arr[], int &size){
    return indexDeletion(arr, size, 0);
}

// ─────────────────────────────────────────
// lastDeletion — delete the very last element
// Logic: no shifting needed at all — just shrink size
//        last element becomes invisible immediately
// Time: O(1) — fastest deletion possible
// ─────────────────────────────────────────
int lastDeletion(int arr[], int &size){
    if(size <= 0){
        return -1; // nothing to delete
    }
    size--; // last element is now out of bounds — hidden
    return 1;
}

// ─────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────
int main(){

    int arr[100] = {7, 8, 12, 27, 45, 88};
    int size = 6;

    cout << "Original array: ";
    display(arr, size);

    // ── Case 1: Delete by index ──
    cout << "\n[Case 1] Delete at index 2:" << endl;
    int r1 = indexDeletion(arr, size, 2);
    if(r1 == 1){
        cout << "Deletion successful: ";
        display(arr, size);
    } else {
        cout << "Deletion failed — invalid index" << endl;
    }

    // ── Case 2: Delete by value ──
    cout << "\n[Case 2] Delete element with value 45:" << endl;
    int r2 = valueDeletion(arr, size, 45);
    if(r2 == 1){
        cout << "Deletion successful: ";
        display(arr, size);
    } else {
        cout << "Deletion failed — value not found" << endl;
    }

    // ── Case 3: Delete first element ──
    cout << "\n[Case 3] Delete first element:" << endl;
    int r3 = firstDeletion(arr, size);
    if(r3 == 1){
        cout << "Deletion successful: ";
        display(arr, size);
    } else {
        cout << "Deletion failed" << endl;
    }

    // ── Case 4: Delete last element ──
    cout << "\n[Case 4] Delete last element:" << endl;
    int r4 = lastDeletion(arr, size);
    if(r4 == 1){
        cout << "Deletion successful: ";
        display(arr, size);
    } else {
        cout << "Deletion failed" << endl;
    }

    // ── Case 5: Try invalid index ──
    cout << "\n[Case 5] Try deleting at invalid index 99:" << endl;
    int r5 = indexDeletion(arr, size, 99);
    if(r5 == 1){
        cout << "Deletion successful: ";
        display(arr, size);
    } else {
        cout << "Deletion failed — invalid index" << endl;
    }

    // ── Case 6: Try deleting value that doesn't exist ──
    cout << "\n[Case 6] Try deleting value 999 (not in array):" << endl;
    int r6 = valueDeletion(arr, size, 999);
    if(r6 == 1){
        cout << "Deletion successful: ";
        display(arr, size);
    } else {
        cout << "Deletion failed — value not found" << endl;
    }

    return 0;
}