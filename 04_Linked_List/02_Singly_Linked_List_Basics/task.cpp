/*
 * ══════════════════════════════════════════════════
 *  TASKS — 02_Singly_Linked_List_Basics
 *  6 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// helpers --------------------------------------------------------------
Node* buildFromArray(const int a[], int n) {   // a[0] becomes head
    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) { Node* t = new Node(a[i]); t->next = head; head = t; }
    return head;
}
void print(Node* h) {
    while (h) { cout << h->data << (h->next ? " -> " : ""); h = h->next; }
    cout << endl;
}
void destroy(Node*& h) { while (h) { Node* t = h->next; delete h; h = t; } }

/* TASK 1 — insert at head (EASY)
   Push 9, then 4, then 1 onto an empty list (front insert each time).
   Expected final print: 1 -> 4 -> 9 */
Node* task1_pushFront() {
    Node* head = nullptr;
    for (int v : {9, 4, 1}) { Node* n = new Node(v); n->next = head; head = n; }
    return head;
}

/* TASK 2 — insert at tail (EASY)
   Append 6, then 7, then 8 to list {2,3}.
   Expected print: 2 -> 3 -> 6 -> 7 -> 8 */
void task2_appendTail(Node*& head, int v) {
    Node* n = new Node(v);
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

/* TASK 3 — delete ALL nodes that hold value v (MEDIUM)
   Input: 1 -> 2 -> 1 -> 3 -> 1 , delete v=1.
   Expected print: 2 -> 3 */
void task3_deleteAll(Node*& head, int v) {
    while (head && head->data == v) { Node* t = head; head = head->next; delete t; }
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == v) { Node* t = cur->next; cur->next = t->next; delete t; }
        else cur = cur->next;
    }
}

/* TASK 4 — insert into a sorted list (MEDIUM-HARD)
   Sorted list {1, 3, 5} , insert 4 so order stays.
   Expected print: 1 -> 3 -> 4 -> 5 */
void task4_insertSorted(Node*& head, int v) {
    Node* n = new Node(v);
    if (!head || head->data >= v) { n->next = head; head = n; return; }
    Node* cur = head;
    while (cur->next && cur->next->data < v) cur = cur->next;
    n->next = cur->next;
    cur->next = n;
}

/* TASK 5 — middle insert only if length is even (HARD-ish)
   Insert v at the MIDDLE (0-based floor(length/2)) if length is even;
   otherwise leave the list unchanged. Return true if inserted.
   Input {1,2,3,4} (len 4 even), insert 9 → 1 -> 2 -> 9 -> 3 -> 4 ; true.
   Input {1,2,3}   (len 3 odd),  insert 9 → unchanged; false. */
bool task5_insertMiddleIfEven(Node*& head, int v) {
    int len = 0;
    for (Node* t = head; t; t = t->next) len++;
    if (len % 2 != 0) return false;
    int mid = len / 2;                       // 0-based middle position
    Node* prev = head;
    for (int i = 1; i < mid && prev; i++) prev = prev->next;
    Node* n = new Node(v);
    if (mid == 0) { n->next = head; head = n; return true; }
    n->next = prev->next;
    prev->next = n;
    return true;
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    Node* h1 = task1_pushFront();
    print(h1);                               // 1 -> 4 -> 9

    cout << "---- TASK 2 ----" << endl;
    Node* h2 = buildFromArray(new int[3]{2, 3, 0}, 2);
    for (int v : {6, 7, 8}) task2_appendTail(h2, v);
    print(h2);                               // 2 -> 3 -> 6 -> 7 -> 8

    cout << "---- TASK 3 ----" << endl;
    Node* h3 = buildFromArray(new int[5]{1, 2, 1, 3, 1}, 5);
    task3_deleteAll(h3, 1);
    print(h3);                               // 2 -> 3

    cout << "---- TASK 4 ----" << endl;
    Node* h4 = buildFromArray(new int[3]{1, 3, 5}, 3);
    task4_insertSorted(h4, 4);
    print(h4);                               // 1 -> 3 -> 4 -> 5

    cout << "---- TASK 5 ----" << endl;
    Node* h5 = buildFromArray(new int[4]{1, 2, 3, 4}, 4);
    cout << "inserted(even)? " << (task5_insertMiddleIfEven(h5, 9) ? "true" : "false") << endl;
    print(h5);                               // 1 -> 2 -> 9 -> 3 -> 4
    Node* h5b = buildFromArray(new int[3]{1, 2, 3}, 3);
    cout << "inserted(odd) ? " << (task5_insertMiddleIfEven(h5b, 9) ? "true" : "false") << endl;
    print(h5b);                              // 1 -> 2 -> 3

    destroy(h1); destroy(h2); destroy(h3); destroy(h4); destroy(h5); destroy(h5b);
    return 0;
}