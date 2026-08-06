#include <iostream>
using namespace std;

// ─────────────────────────────────────────
// NODE STRUCTURE
// Every node holds data + address of next node
// next = NULL means it is the last node
// ─────────────────────────────────────────
struct Node {
    int data;    // the actual value stored
    Node* next;  // pointer to the next node in chain
};

// ─────────────────────────────────────────
// TRAVERSAL — print all nodes
// Logic: start from head, keep moving to next
//        stop when you hit NULL (end of list)
// ─────────────────────────────────────────
void display(Node* head) {
    Node* temp = head;  // temp pointer to walk the list — never move head itself
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " → ";  // arrow between nodes
        temp = temp->next;                       // move to next node
    }
    cout << " → NULL" << endl;
}

// ─────────────────────────────────────────
// CASE 1 — Insert at Beginning
// Logic: new node's next points to current head
//        then head becomes the new node
//        no traversal needed — O(1)
// ─────────────────────────────────────────
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node();  // create new node in heap memory
    newNode->data  = value;      // store the value
    newNode->next  = head;       // new node points to old first node
    head = newNode;              // head now points to new node
    return head;                 // return updated head
}

// ─────────────────────────────────────────
// CASE 2 — Insert at End
// Logic: traverse to the last node (where next == NULL)
//        make last node's next point to new node
//        new node's next = NULL (it is now the last)
// Time: O(n) — must reach the end first
// ─────────────────────────────────────────
Node* insertAtEnd(Node* head, int value) {
    Node* newNode  = new Node();  // create new node
    newNode->data  = value;
    newNode->next  = NULL;        // this will be the last node

    // edge case — if list is empty, new node becomes head
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {  // walk until last node
        temp = temp->next;
    }
    temp->next = newNode;  // last node now points to new node
    return head;
}

// ─────────────────────────────────────────
// CASE 3 — Insert at a Specific Position
// Logic: traverse to node BEFORE the target position
//        new node's next = that node's current next
//        that node's next = new node
//        order matters — if reversed, you lose the chain
// Time: O(n) — traverse to position
// ─────────────────────────────────────────
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    // if inserting at position 0 — same as insert at beginning
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    // traverse to node just BEFORE the target position
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            // position is out of range
            cout << "Position out of range!" << endl;
            delete newNode;  // free memory — no memory leak
            return head;
        }
        temp = temp->next;
    }

    // rewire pointers — ORDER IS CRITICAL here
    newNode->next = temp->next;  // step 1: new node points forward first
    temp->next    = newNode;     // step 2: previous node points to new node
    // if reversed: step 2 first — you lose access to the rest of the list

    return head;
}

// ─────────────────────────────────────────
// CASE 4 — Insert After a Specific Node Value
// Logic: find the node with matching value
//        insert new node right after it
//        if value not found — report and exit
// Time: O(n) — search first
// ─────────────────────────────────────────
Node* insertAfterValue(Node* head, int afterValue, int newValue) {
    Node* temp = head;

    // search for the node with matching value
    while (temp != NULL) {
        if (temp->data == afterValue) {
            // found the node — insert after it
            Node* newNode  = new Node();
            newNode->data  = newValue;
            newNode->next  = temp->next;  // new node takes over what came after
            temp->next     = newNode;     // target node now points to new node
            return head;
        }
        temp = temp->next;
    }

    // if we reach here — value was not found in list
    cout << "Value " << afterValue << " not found in list!" << endl;
    return head;
}

// ─────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────
int main() {

    Node* head = NULL;  // empty list to start

    // ── Case 1: Insert at End (building the base list) ──
    cout << "[Building list using insertAtEnd]" << endl;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    display(head);

    // ── Case 2: Insert at Beginning ──
    cout << "\n[Case 1] Insert 99 at beginning:" << endl;
    head = insertAtBeginning(head, 99);
    display(head);

    // ── Case 3: Insert at Position ──
    cout << "\n[Case 2] Insert 55 at position 2:" << endl;
    head = insertAtPosition(head, 55, 2);
    display(head);

    // ── Case 4: Insert After a Value ──
    cout << "\n[Case 3] Insert 77 after node with value 20:" << endl;
    head = insertAfterValue(head, 20, 77);
    display(head);

    // ── Edge Case: Invalid Position ──
    cout << "\n[Edge Case] Insert at position 999:" << endl;
    head = insertAtPosition(head, 11, 999);
    display(head);

    // ── Edge Case: Value Not Found ──
    cout << "\n[Edge Case] Insert after value 888 (not in list):" << endl;
    head = insertAfterValue(head, 888, 22);
    display(head);

    return 0;
}