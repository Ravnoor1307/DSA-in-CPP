/*
 * ══════════════════════════════════════════════════
 *  TASKS — 02_Queue_Implementation_Array
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
using namespace std;

/* TASK 1 — circular count formula sanity (EASY)
   f=4, r=1, cap=6 → (1-4+6)%6 = 3. Return that count. */
int task1_count(int f, int r, int cap) {
    return (r - f + cap) % cap;
}

/* TASK 2 — is a ring state "full" ? (EASY)
   f=3, r=2, cap=5 → (2+1)%5==3 → yes. Return 1/false. */
bool task2_full(int f, int r, int cap) {
    return (r + 1) % cap == f;
}

/* TASK 3 — circular rotator helper (MEDIUM)
   Move front forward (dequeue-style) n times; return resulting front idx. */
int task3_advanceFront(int f, int n, int cap) {
    for (int i = 0; i < n; i++) f = (f + 1) % cap;
    return f;
}

/* TASK 4 — emulate dequeue-then-enqueue (MEDIUM)
   On ring f=1,r=4,cap=6 with contents slots [0..5], rotating: pop front
   and push it at rear. Return front AFTER the move (walk the array). */
int task4_rotate(int a[], int f, int r, int cap) {
    int t = a[f];                     // front element
    a[r] = t;                          // park at rear
    r = (r + 1) % cap;
    f = (f + 1) % cap;
    return f;                          // caller sees new front index
}

/* TASK 5 — build-your-own circular queue class (HARD)
   Implement enq/deq on cap 5, do the sequence enq1,2,3 deq1 enq4,5,6 and
   report final count + front. */
void task5_buildQueue() {
    int cap = 5;
    int a[5]; int f = 0, r = 0;
    auto enq = [&](int v) {
        if ((r + 1) % cap == f) { cout << "enq " << v << " rejected (full)\n"; return; }
        a[r] = v; r = (r + 1) % cap;
    };
    auto deq = [&]() { if (f == r) return -1; int v = a[f]; f = (f + 1) % cap; return v; };
    auto cnt = [&]() { return (r - f + cap) % cap; };

    enq(1); enq(2); enq(3);
    deq();
    enq(4); enq(5); enq(6);           // enq6 → full → rejected
    cout << "count=" << cnt() << " front=" << a[f] << endl;   // 4, 2
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    cout << "count = " << task1_count(4, 1, 6) << endl;       // 3

    cout << "---- TASK 2 ----" << endl;
    cout << task2_full(3, 2, 5) << endl;                     // 1

    cout << "---- TASK 3 ----" << endl;
    cout << "front after 3 advances = " << task3_advanceFront(1, 3, 6) << endl;  // 4

    cout << "---- TASK 4 ----" << endl;
    int a[6] = {0, 11, 22, 33, 0, 0};                       // front=1 value 11
    int nf = task4_rotate(a, 1, 4, 6);
    cout << "new front idx = " << nf << " value = " << a[nf] << endl;  // 2, 22

    cout << "---- TASK 5 ----" << endl;
    task5_buildQueue();
    return 0;
}