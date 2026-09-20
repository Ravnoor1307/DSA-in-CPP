/*
 * ══════════════════════════════════════════════════
 *  TASKS — 05_Doubly_Linked_List
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
using namespace std;

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

/* TASK 1 — pushFront (EASY)
   Push 5, 6, 7 at front of empty list. Expected print 7 -> 6 -> 5
   and backward 5 -> 6 -> 7 (via tail). */
void task1_pushFront(DLLNode*& head, DLLNode*& tail, int v) {
    DLLNode* n = new DLLNode(v);
    if (!head) { head = tail = n; return; }
    n->next = head;
    head->prev = n;
    head = n;
}

/* TASK 2 — append (EASY)
   Append 1, 2, 3 to list {8, 9}. Expected 8 -> 9 -> 1 -> 2 -> 3.
   Implement your own append with a tail pointer (O(1)). */
void task2_append(DLLNode*& head, DLLNode*& tail, int v) {
    DLLNode* n = new DLLNode(v);
    if (!head) { head = tail = n; return; }
    n->prev = tail;
    tail->next = n;
    tail = n;
}

/* TASK 3 — delete the LAST node (MEDIUM)
   Input {10, 20, 30}. Result 10 -> 20 and tail must be node 20.
   Uses O(1) via prev pointer (no walk). Return true if deleted. */
bool task3_deleteTail(DLLNode*& head, DLLNode*& tail) {
    if (!tail) return false;
    if (head == tail) { delete head; head = tail = nullptr; return true; }
    DLLNode* old = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete old;
    return true;
}

/* TASK 4 — insert at a POSITION (MEDIUM-HARD)
   Input {3,6,9}, insert 7 at 0-based index 2.
   Expected 3 -> 6 -> 7 -> 9. */
void task4_insertAt(DLLNode*& head, DLLNode*& tail, int v, int pos) {
    DLLNode* n = new DLLNode(v);
    if (pos <= 0 || !head) {
        n->next = head;
        if (head) head->prev = n; else tail = n;
        head = n;
        return;
    }
    DLLNode* cur = head;
    for (int i = 1; cur && i < pos; i++) cur = cur->next;
    if (!cur) {                     // position beyond end -> append
        n->prev = tail;
        tail->next = n;
        tail = n;
        return;
    }
    n->prev = cur;                  // insert AFTER cur
    n->next = cur->next;
    if (cur->next) cur->next->prev = n; else tail = n;
    cur->next = n;
}

/* TASK 5 — reverse USING prev/next swap (HARD)
   Single O(n) pass by swapping each node's prev/next, then swap head/tail.
   Input {1,2,3,4} -> 4 -> 3 -> 2 -> 1 (and tail = old head). */
void task5_reverseDLL(DLLNode*& head, DLLNode*& tail) {
    DLLNode* cur = head;
    while (cur) {
        swap(cur->prev, cur->next);   // dono pointers ulta do
        cur = cur->prev;              // prev ab asli next hai — usse aage badho
    }
    swap(head, tail);
}

// helpers --------------------------------------------------------------
DLLNode* build(initializer_list<int> vals, DLLNode*& tail) {
    DLLNode* head = nullptr; tail = nullptr;
    for (int v : vals) {
        DLLNode* n = new DLLNode(v);
        if (!head) { head = tail = n; }
        else { n->prev = tail; tail->next = n; tail = n; }
    }
    return head;
}
void printF(DLLNode* h) {
    while (h) { cout << h->data << (h->next ? " -> " : ""); h = h->next; }
    cout << endl;
}
void printB(DLLNode* t) {
    while (t) { cout << t->data << (t->prev ? " -> " : ""); t = t->prev; }
    cout << endl;
}
void destroy(DLLNode*& head) { while (head) { DLLNode* nxt = head->next; delete head; head = nxt; } }

int main() {
    cout << "---- TASK 1 ----" << endl;
    DLLNode *h = nullptr, *t = nullptr;
    for (int v : {5, 6, 7}) task1_pushFront(h, t, v);
    printF(h); printB(t);           // 7 -> 6 -> 5 / 5 -> 6 -> 7

    cout << "---- TASK 2 ----" << endl;
    DLLNode* h2 = build({8, 9}, t);
    for (int v : {1, 2, 3}) task2_append(h2, t, v);
    printF(h2);                      // 8 -> 9 -> 1 -> 2 -> 3
    destroy(h2);

    cout << "---- TASK 3 ----" << endl;
    DLLNode* h3 = build({10, 20, 30}, t);
    bool del = task3_deleteTail(h3, t);
    cout << "deleted = " << (del ? "true" : "false") << "  ";
    printF(h3);                      // 10 -> 20
    destroy(h3);

    cout << "---- TASK 4 ----" << endl;
    DLLNode* h4 = build({3, 6, 9}, t);
    task4_insertAt(h4, t, 7, 2);
    printF(h4);                      // 3 -> 6 -> 7 -> 9
    destroy(h4);

    cout << "---- TASK 5 ----" << endl;
    DLLNode* h5 = build({1, 2, 3, 4}, t);
    task5_reverseDLL(h5, t);
    printF(h5); printB(t);           // 4 -> 3 -> 2 -> 1 (backward too)
    destroy(h5);
    return 0;
}