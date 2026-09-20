/*
 * ══════════════════════════════════════════════════
 *  TASKS — 03_Queue_Implementation_LL
 *  5 tasks EASY → HARD. Every task self-contained.
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

// shared linked queue used by tasks
struct LQ {
    Node* head = nullptr;
    Node* tail = nullptr;
    int sz = 0;
    void enq(int v) {
        Node* n = new Node(v);
        if (!tail) head = tail = n; else { tail->next = n; tail = n; }
        sz++;
    }
    int deq() {
        if (!head) return -1;
        Node* old = head; head = head->next;
        if (!head) tail = nullptr;
        int v = old->data; delete old; sz--;
        return v;
    }
    int front() { return head ? head->data : -1; }
    int size() { return sz; }
    bool empty() { return head == nullptr; }
    ~LQ() { while (head) { Node* t = head; head = head->next; delete t; } }
};

/* TASK 1 — enqueue 3, size (EASY) */
int task1_size() {
    LQ q;
    q.enq(7); q.enq(8); q.enq(9);
    return q.size();                     // 3
}

/* TASK 2 — interleave push/remove (EASY)
   enq 1, deq 1, enq 2, enq 3 → final front = 2 */
int task2_front() {
    LQ q;
    q.enq(1); q.deq();
    q.enq(2); q.enq(3);
    return q.front();                    // 2
}

/* TASK 3 — drain queue order (MEDIUM) */
void task3_drain() {
    LQ q;
    for (int i = 1; i <= 4; i++) q.enq(i * 5);
    while (!q.empty()) cout << q.deq() << " ";
    cout << endl;                        // 5 10 15 20
}

/* TASK 4 — copy via enqueue to another (MEDIUM)
   Duplicate queue A into B preserving order. Return B's rear value. */
int task4_copyRear() {
    LQ a, b;
    a.enq(3); a.enq(1); a.enq(4);
    while (!a.empty()) b.enq(a.deq());
    return b.tail->data;                 // 4
}

/* TASK 5 — front after moving front to back (HARD)
   Rotate queue once: [1,2,3] → [2,3,1]; return new front. */
int task5_rotate() {
    LQ q;
    for (int i = 1; i <= 3; i++) q.enq(i);
    int f = q.deq();                     // 1
    q.enq(f);                            // back me daal do
    return q.front();                    // 2
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    cout << "size = " << task1_size() << endl;          // 3

    cout << "---- TASK 2 ----" << endl;
    cout << "front = " << task2_front() << endl;        // 2

    cout << "---- TASK 3 ----" << endl;
    task3_drain();                                      // 5 10 15 20

    cout << "---- TASK 4 ----" << endl;
    cout << "copy rear = " << task4_copyRear() << endl; // 4

    cout << "---- TASK 5 ----" << endl;
    cout << "after rotate front = " << task5_rotate() << endl;  // 2
    return 0;
}