/*
═══════════════════════════════════════════════
 TASK SET — DOUBLY LINKED LIST — INTRO
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
A two-way street: every house knows which house is to its left (prev) and
which is to its right (next). Delivery can start from either end — walk
right from the first house, or walk left from the last house. The trick is
that BOTH arrows must be updated whenever a new house is placed in the row,
otherwise one direction breaks.

 🧠 HOW TO SOLVE:
Every DLL operation touches TWO chains. When linking node B after node A,
set BOTH A->next = B AND B->prev = A. For forward output walk next from
head; for backward output walk prev from tail. For insert-at-front, link
the new node to old head FIRST, then repair old head's prev.

 ┌──────────────────────────────────────────────────────────────┐
 │ Task  Difficulty  What you practice                          │
 ├──────────────────────────────────────────────────────────────┤
 │ 1     EASY        newNode() helper that wires prev + next    │
 │ 2     EASY        build a 3-node DLL and print forward       │
 │ 3     MEDIUM      traverse backward from tail                │
 │ 4     MEDIUM      count nodes in the DLL                     │
 │ 5     MEDIUM      insert a node at the FRONT                │
 │ 6     HARD        build a DLL from an array (both chains)    │
 └──────────────────────────────────────────────────────────────┘

 TASK 1: Write Node* newNode(int val) that creates a node with data = val,
         prev = NULL and next = NULL, and returns it.
 💡 HINT: Node* n = new Node; set the three fields, return n.
 ✏️ STARTER CODE:
         struct Node { Node* prev; int data; Node* next; };
         Node* newNode(int val) {
             // TODO: allocate, set data/prev/next
         }
         int main() {  // create one node with 7, print its data }

 TASK 2: Build a 3-node DLL (10, 20, 30) using newNode() and print it FORWARD
         exactly like: NULL <- 10 <-> 20 <-> 30 -> NULL.
 💡 HINT: link node2 after node1 with BOTH arrows; repeat for node3.
 ✏️ STARTER CODE:
         int main() {
             Node* a = newNode(10);
             Node* b = newNode(20);
             // TODO: a->next = b; b->prev = a;  (same for c)
             // TODO: forward print from a
             return 0;
         }

 TASK 3: Given the tail, print the list BACKWARD (30 <- 20 <- 10 <- NULL).
 💡 HINT: walk with temp = tail; while (temp != NULL) print temp->prev chain.
 ✏️ STARTER CODE:
         int main() {
             // TODO: tail tak build karo (reuse Task 2)
             // TODO: backward print from tail
             return 0;
         }

 TASK 4: Write int countNodes(Node* head) for a DLL.
 💡 HINT: identical to a singly list — walk next from head, count per hop.
 ✏️ STARTER CODE:
         int countNodes(Node* head) {
             // TODO: count while walking next pointers
         }

 TASK 5: Write Node* insertAtFront(Node* head, int val) for a DLL and print
         forward + backward after inserting 5 into 10,20,30.
 💡 HINT: naya->next = head; THEN head->prev = naya; THEN head = naya.
         Order matters — old head link pehle use karo.
 ✏️ STARTER CODE:
         Node* insertAtFront(Node* head, int val) {
             // TODO: 3 steps, sahi ORDER me
         }

 TASK 6: Write Node* buildFromArray(int arr[], int n) for a DLL — return
         head; BOTH prev and next chains must be correct.
 💡 HINT: keep a tail pointer; when appending do tail->next = naya AND
         naya->prev = tail, then move tail.
 ✏️ STARTER CODE:
         Node* buildFromArray(int arr[], int n) {
             // TODO: loop, append with both links, return head
         }
         int main() {  // {1,2,3,4} → forward 1,2,3,4; backward 4,3,2,1 }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
};

// ---- TASK 1: helper — teeno fields set karo, garbage NULL karo ----
Node* newNode(int val) {
    Node* n = new Node;
    n->data = val;
    n->prev = NULL;                 // abhi koi padosi nahi
    n->next = NULL;
    return n;
}

// forward print — next chain
void printForward(Node* head) {
    cout << "NULL <- ";
    for (Node* t = head; t != NULL; t = t->next)
        cout << t->data << " <-> ";
    cout << "-> NULL" << endl;
}

// backward print — prev chain
void printBackward(Node* tail) {
    for (Node* t = tail; t != NULL; t = t->prev)
        cout << t->data << " <- ";
    cout << "NULL" << endl;
}

// ---- TASK 2 + 3 combined: 3-node DLL, dono direction ----
void task2and3() {
    Node* a = newNode(10);
    Node* b = newNode(20);
    Node* c = newNode(30);

    a->next = b;  b->prev = a;      // link 1 — dono taraf
    b->next = c;  c->prev = b;      // link 2 — dono taraf

    printForward(a);                // 10,20,30
    printBackward(c);               // 30,20,10  ← ek singly list kabhi nahi karti
}

// ---- TASK 4: count — exactly singly list jaisa ----
int countNodes(Node* head) {
    int count = 0;
    for (Node* t = head; t != NULL; t = t->next)
        ++count;
    return count;
}

// ---- TASK 5: insert at front — ORDER = pehle old head ka link, phir swap ----
Node* insertAtFront(Node* head, int val) {
    Node* naya = newNode(val);
    naya->next = head;              // 1: nayi node ko purane head se jodo
    if (head != NULL)
        head->prev = naya;          // 2: purane head ka prev nayi node pe
    // naya is now new head — bahar return karte hi mil jayega
    return naya;
}

// ---- TASK 6: array → DLL donor chains ----
Node* buildFromArray(int arr[], int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; ++i) {
        Node* naya = newNode(arr[i]);
        if (head == NULL) {
            head = naya;            // pehla node — head hi hai
        } else {
            tail->next = naya;      // forward link
            naya->prev = tail;      // backward link — dono zaroori
        }
        tail = naya;                // tail update
    }
    return head;
}

// memory safai — next chain follow karke delete
void freeList(Node* head) {
    while (head != NULL) {
        Node* agla = head->next;
        delete head;
        head = agla;
    }
}

int main() {
    cout << "──────── TASK 1 ────────" << endl;
    Node* single = newNode(7);
    cout << "single node data = " << single->data
         << " | prev = " << (single->prev == NULL ? "NULL" : "?")
         << " | next = " << (single->next == NULL ? "NULL" : "?") << endl;
    delete single;

    cout << "\n──────── TASK 2 + 3 ────────" << endl;
    task2and3();

    cout << "\n──────── TASK 4 ────────" << endl;
    int arr[] = {10, 20, 30};
    Node* head = buildFromArray(arr, 3);
    cout << "countNodes = " << countNodes(head) << " (umeed: 3)" << endl;

    cout << "\n──────── TASK 5 ────────" << endl;
    head = insertAtFront(head, 5);
    printForward(head);             // 5,10,20,30
    Node* tail = head;
    while (tail->next != NULL) tail = tail->next;   // tail dhundho
    printBackward(tail);            // 30,20,10,5  ← sabse pakka DLL test

    cout << "\n──────── TASK 6 ────────" << endl;
    int b[] = {1, 2, 3, 4};
    Node* h2 = buildFromArray(b, 4);
    printForward(h2);               // 1,2,3,4
    Node* t2 = h2;
    while (t2->next != NULL) t2 = t2->next;
    printBackward(t2);              // 4,3,2,1

    freeList(head);
    freeList(h2);
    return 0;
}