#include <iostream>
using namespace std;

// ------------------------------
// Node structure
// Each node has:
// 1. data
// 2. pointer to next node
// ------------------------------
struct Node {
    int data;
    Node* next;
};

int main() {

    // ------------------------------
    // Create three nodes dynamically
    // ------------------------------
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* forth = new Node();

    // ------------------------------
    // Store data in each node
    // ------------------------------
    first->data = 10;
    second->data = 20;
    third->data = 30;
    forth->data =  

    // ------------------------------
    // Connect the nodes
    // first → second → third → NULL
    // ------------------------------
    first->next = second;
    second->next = third;
    third->next = NULL;

    // ------------------------------
    // Traversal
    // temp starts from first node
    // Move until temp becomes NULL
    // ------------------------------
    Node* temp = first;

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;   // Move to next node
    }

    cout << endl;

    return 0;
}