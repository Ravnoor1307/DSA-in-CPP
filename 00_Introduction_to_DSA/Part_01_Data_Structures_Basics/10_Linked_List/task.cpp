/*
═══════════════════════════════════════════════
 TASK SET — LINKED LIST — INTRO
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
Treasure hunt: every clue card carries the prize and the hiding spot of the
NEXT clue card. The first card (HEAD) starts the chain, the last card points
to "KHATAM" (NULL). To count the clues or find a particular prize you must
follow the trail card by card — there is no skipping ahead.

 🧠 HOW TO SOLVE:
Every operation starts at head and walks next pointers using a helper
pointer (temp = temp->next). For each task, decide: do I just read (print,
count, search) or do I change links (insert at front)? Changing links means
connecting the new node FIRST, then fixing head.

 ┌──────────────────────────────────────────────────────────────┐
 │ Task  Difficulty  What you practice                          │
 ├──────────────────────────────────────────────────────────────┤
 │ 1     EASY        creating ONE node and reading its fields   │
 │ 2     EASY        traversing and printing the whole list     │
 │ 3     MEDIUM      counting nodes                             │
 │ 4     MEDIUM      searching a value, returning its position  │
 │ 5     MEDIUM      inserting a new node at the FRONT          │
 │ 6     HARD        building a list of n nodes from an array   │
 └──────────────────────────────────────────────────────────────┘

 TASK 1: Create a single node whose data is 100. Print its data and print
         whether its next is NULL ("last node hai").
 💡 HINT: struct Node { int data; Node* next; };  then  Node* n = new Node;
 ✏️ STARTER CODE:
         struct Node { int data; Node* next; };
         int main() {
             // TODO: new Node, data = 100, next = NULL
             // TODO: print data, check next == NULL
             return 0;
         }

 TASK 2: Given a head pointer to the list 10 → 20 → 30, print each node's
         data separated by " -> " and end with "NULL".
 💡 HINT: walk with  Node* temp = head;  while (temp != NULL) { ... }.
 ✏️ STARTER CODE:
         int main() {
             // TODO: create the 3-node list
             // TODO: traverse and print
             return 0;
         }

 TASK 3: Write int countNodes(Node* head) that returns how many nodes are in
         the list.
 💡 HINT: count = 0; walk with temp; count++ per node; stop at NULL.
 ✏️ STARTER CODE:
         int countNodes(Node* head) {
             // TODO: walk and count
         }
         int main() {  // build 10,20,30 → count should be 3 }

 TASK 4: Write int search(Node* head, int target) that returns the 0-based
         position of target, or -1 if absent.
 💡 HINT: keep an index counter that increments on every hop.
 ✏️ STARTER CODE:
         int search(Node* head, int target) {
             // TODO: temp walk + index counter
         }
         int main() {  // search 20 in 10,20,30 → 1; search 99 → -1 }

 TASK 5: Write Node* insertAtFront(Node* head, int val) that creates a new
         node and makes it the new head. Print the list after inserting 5
         into 10 → 20 → 30.
 💡 HINT: naya->next = head FIRST; then head = naya. Galti se ulat kiya →
         list gum ya khud ka loop!
 ✏️ STARTER CODE:
         Node* insertAtFront(Node* head, int val) {
             // TODO: new node, naya->next = head, head = naya
         }
         int main() {  // insert 5 → 5,10,20,30 }

 TASK 6: Write Node* buildFromArray(int arr[], int n) that builds a linked
         list of n nodes carrying arr's values in the same order and returns
         head.
 💡 HINT: grow the list from the BACK: keep a tail pointer and append each
         new node behind it.
 ✏️ STARTER CODE:
         Node* buildFromArray(int arr[], int n) {
             // TODO: head = NULL; create nodes; link tail->next = naya
         }
         int main() {  // arr = {5,7,9} → list 5,7,9, count=3 }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// list print karo — har baar same pattern
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ---- TASK 1: ek akele node ka jeevan ----
void task1() {
    Node* n = new Node;              // heap pe jagah
    n->data = 100;
    n->next = NULL;                  // kachre ki jagah NULL — zaroori
    cout << "data = " << n->data
         << " | next is " << (n->next == NULL ? "NULL (aakhri node)" : "not NULL")
         << endl;
    delete n;
}

// ---- TASK 2: 3-node list banao aur print karo ----
void task2() {
    Node* head = new Node;
    head->data = 10; head->next = new Node;   // node2 seedha chain me
    head->next->data = 20; head->next->next = new Node;
    head->next->next->data = 30; head->next->next->next = NULL;
    printList(head);
}

// ---- TASK 3: count — har hop pe ek ++ ----
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {           // jab tak node exist karta hai
        ++count;
        temp = temp->next;
    }
    return count;
}

// ---- TASK 4: search — position wapas, mila nahi to -1 ----
int search(Node* head, int target) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target)    // mil gaya target
            return index;
        temp = temp->next;
        ++index;                     // har hop pe position badhti hai
    }
    return -1;                       // poori list ghum li, nahi mila
}

// ---- TASK 5: insert at front — ORDER bachao ----
Node* insertAtFront(Node* head, int val) {
    Node* naya = new Node;
    naya->data = val;
    naya->next = head;               // PEHLE purani list ko naya->next pe bandho
    return naya;                     // ab naya head hai
}

// ---- TASK 6: array → list — tail ka dhyan rakho ----
Node* buildFromArray(int arr[], int n) {
    Node* head = NULL;
    Node* tail = NULL;               // aakhri node ka pata — append ke liye
    for (int i = 0; i < n; ++i) {
        Node* naya = new Node;
        naya->data = arr[i];
        naya->next = NULL;
        if (head == NULL) {          // pehla node hi head bhi hai
            head = naya;
        } else {
            tail->next = naya;       // purane last ke peeche jodo
        }
        tail = naya;                 // naya node ab latest tail
    }
    return head;
}

// memory safai — poori list delete
void freeList(Node* head) {
    while (head != NULL) {
        Node* agla = head->next;     // pehle next bacha lo
        delete head;
        head = agla;
    }
}

int main() {
    cout << "──────── TASK 1 ────────" << endl;
    task1();

    cout << "\n──────── TASK 2 ────────" << endl;
    task2();

    cout << "\n──────── TASK 3 + 4 ────────" << endl;
    int vals[] = {10, 20, 30};
    Node* head = buildFromArray(vals, 3);
    printList(head);
    cout << "countNodes = " << countNodes(head) << endl;
    cout << "search(20) = " << search(head, 20) << " (umeed: 1)" << endl;
    cout << "search(99) = " << search(head, 99) << " (umeed: -1)" << endl;

    cout << "\n──────── TASK 5 ────────" << endl;
    head = insertAtFront(head, 5);
    printList(head);                 // 5 -> 10 -> 20 -> 30 -> NULL

    cout << "\n──────── TASK 6 ────────" << endl;
    int arr[] = {5, 7, 9};
    Node* other = buildFromArray(arr, 3);
    printList(other);                // 5 -> 7 -> 9 -> NULL

    freeList(head);
    freeList(other);
    return 0;
}