/*
═══════════════════════════════════════════════
 TASK SET — SELF-REFERENTIAL STRUCTURE
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
A letter that carries the address of the next letter: each envelope holds a
message AND the location of the next envelope of the same kind. That one
"address inside its own kind" is the entire trick — a structure that refers
to itself, and the seed of every linked data structure you will ever meet.

 🧠 HOW TO SOLVE:
Write the struct with a pointer to its OWN type (struct Node { int data;
Node* next; }). Build chains by allocating with new, initialising next to
NULL, then linking one node into another's next field. Walk the chain with a
helper temp = temp->next until NULL. For harder tasks, hold two pointers or
move one faster than the other.

 ┌──────────────────────────────────────────────────────────────┐
 │ Task  Difficulty  What you practice                          │
 ├──────────────────────────────────────────────────────────────┤
 │ 1     EASY        declaring the struct + allocating one node │
 │ 2     EASY        3 nodes linked linearly, print each        │
 │ 3     MEDIUM      build a chain of n nodes from an array     │
 │ 4     MEDIUM      count nodes in the chain                   │
 │ 5     HARD        find the MIDDLE node (slow + fast pointer) │
 │ 6     HARD        find the Nth node from the END             │
 └──────────────────────────────────────────────────────────────┘

 TASK 1: Declare struct Node { int data; Node* next; }, allocate ONE node
         with data = 42, next = NULL, and print its data and next.
 💡 HINT:  Node* p = new Node;  p->data = 42;  p->next = NULL;
 ✏️ STARTER CODE:
         struct Node { int data; Node* next; };
         int main() {
             // TODO: ek node banao, data = 42, next = NULL
             // TODO: print data aur next == NULL ka check
             return 0;
         }

 TASK 2: Create three nodes (7, 8, 9), link them head → n2 → n3, and print
         their data by following next pointers.
 💡 HINT: head->next = n2;  n2->next = n3;  n3->next = NULL;
 ✏️ STARTER CODE:
         int main() {
             // TODO: 3 nodes banao aur link karo
             // TODO: temp = head; while(temp) print data
             return 0;
         }

 TASK 3: Write Node* buildChain(int arr[], int n) that builds a self-
         referential chain of n nodes carrying arr's values and returns head.
 💡 HINT: keep a tail pointer; for each arr[i] append a fresh node behind it.
 ✏️ STARTER CODE:
         Node* buildChain(int arr[], int n) {
             // TODO: link while loop — tail->next = naya
         }
         int main() {  // arr = {4,5,6,7} → chain 4,5,6,7 }

 TASK 4: Write int chainLength(Node* head) returning the number of nodes.
 💡 HINT: walk with temp; counter++ per non-NULL hop.
 ✏️ STARTER CODE:
         int chainLength(Node* head) {
             // TODO: walk and count
         }

 TASK 5: Write Node* findMiddle(Node* head) returning the middle node using
         the SLOW(1 step) + FAST(2 steps) technique. For {1,2,3,4,5} → 3.
 💡 HINT: slow = slow->next each loop; fast = fast->next->next each loop;
         when fast reaches NULL (or its next is NULL), slow is the middle.
 ✏️ STARTER CODE:
         Node* findMiddle(Node* head) {
             // TODO: slow/fast pointers, loop till fast finishes
         }

 TASK 6: Write Node* nthFromEnd(Node* head, int k) that returns the k-th
         node from the END (2nd from end of 1,2,3,4,5 → 4). Use a tail walk
         trick or two pointers kept k apart.
 💡 HINT: move `front` k steps ahead first, then walk front and `behind`
         together — when front hits NULL, behind is the answer.
 ✏️ STARTER CODE:
         Node* nthFromEnd(Node* head, int k) {
             // TODO: front ko k aage bhejo, phir dono saath chalao
         }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// self-referential struct — Node khud ko point karta hai
struct Node {
    int data;
    Node* next;
};

// chain print — har baar ka standard walk
void printChain(Node* head) {
    for (Node* t = head; t != NULL; t = t->next)
        cout << t->data << " -> ";
    cout << "NULL" << endl;
}

// ---- TASK 1: ek akele node ke saath khel ----
void task1() {
    Node* p = new Node;
    p->data = 42;
    p->next = NULL;                 // garbage nahi — "yahan chain khatam"
    cout << "data = " << p->data
         << " | next = " << (p->next == NULL ? "NULL ✓" : "NOT NULL ✗") << endl;
    delete p;
}

// ---- TASK 2: 3 nodes, links jodke print ----
void task2() {
    Node* n1 = new Node; n1->data = 7; n1->next = NULL;
    Node* n2 = new Node; n2->data = 8; n2->next = NULL;
    Node* n3 = new Node; n3->data = 9; n3->next = NULL;
    n1->next = n2;                  // self-reference ki kasam — 1 ko 2 ka address
    n2->next = n3;                  // 2 ko 3 ka address
    printChain(n1);
    delete n3; delete n2; delete n1;
}

// ---- TASK 3: array → chain — tail pointer rakho ----
Node* buildChain(int arr[], int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; ++i) {
        Node* naya = new Node;
        naya->data = arr[i];
        naya->next = NULL;
        if (head == NULL)
            head = naya;            // pehla element hi head
        else
            tail->next = naya;      // aakhri ke peeche jodo
        tail = naya;
    }
    return head;
}

// ---- TASK 4: length — har non-NULL hop pe count++ ----
int chainLength(Node* head) {
    int len = 0;
    for (Node* t = head; t != NULL; t = t->next)
        ++len;
    return len;
}

// ---- TASK 5: middle — slow 1 step, fast 2 steps ----
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // slow: 1 kadam
        fast = fast->next->next;    // fast: 2 kadam
    }
    return slow;                    // fast end pe pahucha → slow beech me
}

// ---- TASK 6: nth-from-end — front ko k aage bhejo, phir dono saath ----
Node* nthFromEnd(Node* head, int k) {
    Node* front = head;
    Node* behind = head;
    for (int i = 0; i < k; ++i) {
        if (front == NULL)          // k chain se lamba → galat input
            return NULL;
        front = front->next;        // pehle front ko k aage le jao
    }
    while (front != NULL) {         // ab dono ek-saath chalte hain
        front = front->next;
        behind = behind->next;
    }
    return behind;                  // front NULL → behind theek k-th from end
}

// memory safai
void freeChain(Node* head) {
    while (head != NULL) {
        Node* agla = head->next;
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
    int vals[] = {4, 5, 6, 7};
    Node* head = buildChain(vals, 4);
    printChain(head);
    cout << "chainLength = " << chainLength(head) << " (umeed: 4)" << endl;

    cout << "\n──────── TASK 5 ────────" << endl;
    int odd[] = {1, 2, 3, 4, 5};
    Node* h5 = buildChain(odd, 5);
    cout << "middle of {1,2,3,4,5} = " << findMiddle(h5)->data << " (umeed: 3)" << endl;

    cout << "\n──────── TASK 6 ────────" << endl;
    int six[] = {1, 2, 3, 4, 5};
    Node* h6 = buildChain(six, 5);
    Node* got = nthFromEnd(h6, 2);
    cout << "2nd from end of {1,2,3,4,5} = "
         << (got ? to_string(got->data) : "NULL") << " (umeed: 4)" << endl;

    freeChain(head);
    freeChain(h5);
    freeChain(h6);
    return 0;
}