#include <iostream>
using namespace std;

// ─────────────────────────────────────────
// NODE STRUCTURE
// ─────────────────────────────────────────
struct Node {
    int data;
    Node* next;
};

// ─────────────────────────────────────────
// DISPLAY — traverse and print the list
// temp walks the list — head never moves
// ─────────────────────────────────────────
void display(Node* head) {
    if (head == NULL) {
        cout << "List: EMPTY" << endl;
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " → ";
        temp = temp->next;
    }
    cout << " → NULL" << endl;
}

// ─────────────────────────────────────────
// CASE 1 — Delete at Beginning
// Logic: head moves one step forward
//        old head node gets deleted from memory
// Time: O(1) — no traversal needed
// ─────────────────────────────────────────
Node* deleteAtBeginning(Node* head) {

    // edge case — nothing to delete
    if (head == NULL) {
        cout << "List is empty — nothing to delete!" << endl;
        return NULL;
    }

    Node* toDelete = head;  // save old head to free later
    head = head->next;      // head moves to second node
    delete toDelete;        // free old head from memory

    return head;
}

// ─────────────────────────────────────────
// CASE 2 — Delete at End
// Logic: traverse to second last node
//        make it point to NULL
//        delete the last node
// Time: O(n) — must reach the end
// ─────────────────────────────────────────
Node* deleteAtEnd(Node* head) {

    // edge case — empty list
    if (head == NULL) {
        cout << "List is empty — nothing to delete!" << endl;
        return NULL;
    }

    // edge case — only one node in list
    if (head->next == NULL) {
        delete head;   // free the only node
        return NULL;   // list is now empty
    }

    Node* temp = head;

    // traverse to the SECOND LAST node
    // stop when temp->next->next is NULL
    // meaning temp->next is the last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;   // free the last node from memory
    temp->next = NULL;   // second last node now becomes the last

    return head;
}

// ─────────────────────────────────────────
// CASE 3 — Delete at Specific Position
// Logic: traverse to node BEFORE target position
//        bypass target node — point to the one after it
//        free target node from memory
// Time: O(n) — traverse to position
// ─────────────────────────────────────────
Node* deleteAtPosition(Node* head, int position) {

    // edge case — empty list
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    // position 0 means delete first node
    if (position == 0) {
        return deleteAtBeginning(head);
    }

    Node* temp = head;

    // traverse to node just BEFORE the target position
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            // we ran out of nodes — position doesn't exist
            cout << "Position out of range!" << endl;
            return head;
        }
        temp = temp->next;
    }

    // temp is now at the node BEFORE target
    // temp->next is the node we want to delete
    if (temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return head;
    }

    Node* toDelete = temp->next;    // save target node
    temp->next     = toDelete->next; // bypass target — point to the node after it
    delete toDelete;                 // free target from memory

    return head;
}

// ─────────────────────────────────────────
// CASE 4 — Delete by Value
// Logic: search for node with matching value
//        keep track of the PREVIOUS node
//        previous node bypasses target
//        free target from memory
// Time: O(n) — search first
// ─────────────────────────────────────────
Node* deleteByValue(Node* head, int value) {

    // edge case — empty list
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    // edge case — value is in the first node
    if (head->data == value) {
        return deleteAtBeginning(head);
    }

    Node* temp = head;  // walks the list
    Node* prev = NULL;  // always one step behind temp

    // search for the node with matching value
    while (temp != NULL) {
        if (temp->data == value) {

            // found it — bypass this node
            prev->next = temp->next;  // previous node skips over target
            delete temp;              // free target from memory
            cout << "Deleted node with value " << value << endl;
            return head;
        }
        prev = temp;          // prev catches up to temp
        temp = temp->next;    // temp moves forward
    }

    // loop finished — value was never found
    cout << "Value " << value << " not found in list!" << endl;
    return head;
}

// ─────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────
int main() {

    // build the list manually
    Node* head = NULL;

    // create nodes
    Node* n1 = new Node(); n1->data = 10; n1->next = NULL;
    Node* n2 = new Node(); n2->data = 20; n2->next = NULL;
    Node* n3 = new Node(); n3->data = 30; n3->next = NULL;
    Node* n4 = new Node(); n4->data = 40; n4->next = NULL;
    Node* n5 = new Node(); n5->data = 50; n5->next = NULL;

    // connect them
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    head = n1;

    cout << "Original list:" << endl;
    display(head);

    // ── Case 1: Delete at Beginning ──
    cout << "\n[Case 1] Delete at beginning:" << endl;
    head = deleteAtBeginning(head);
    display(head);

    // ── Case 2: Delete at End ──
    cout << "\n[Case 2] Delete at end:" << endl;
    head = deleteAtEnd(head);
    display(head);

    // ── Case 3: Delete at Position ──
    cout << "\n[Case 3] Delete at position 1:" << endl;
    head = deleteAtPosition(head, 1);
    display(head);

    // ── Case 4: Delete by Value ──
    cout << "\n[Case 4] Delete node with value 40:" << endl;
    head = deleteByValue(head, 40);
    display(head);

    // ── Edge Case: Invalid Position ──
    cout << "\n[Edge Case] Delete at position 99:" << endl;
    head = deleteAtPosition(head, 99);
    display(head);

    // ── Edge Case: Value Not Found ──
    cout << "\n[Edge Case] Delete value 999:" << endl;
    head = deleteByValue(head, 999);
    display(head);

    // ── Edge Case: Delete until empty ──
    cout << "\n[Edge Case] Delete remaining nodes:" << endl;
    head = deleteAtBeginning(head);
    display(head);
    head = deleteAtBeginning(head);
    display(head);

    // ── Edge Case: Delete from empty list ──
    cout << "\n[Edge Case] Delete from empty list:" << endl;
    head = deleteAtBeginning(head);

    return 0;
}