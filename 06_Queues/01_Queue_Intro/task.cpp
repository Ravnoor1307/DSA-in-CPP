/*
 * ══════════════════════════════════════════════════
 *  TASKS — 01_Queue_Intro
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
using namespace std;

/* TASK 1 — first and last in a FIFO list (EASY)
   Return the front element. Queue built by enqueuing 5,9,2 → front 5. */
int task1_front(int a[], int n) {
    return a[0];
}

/* TASK 2 — copy FIFO order to array (EASY)
   Enqueue 1..5, dequeue all into b; print b. */
void task2_fifo(int n) {
    int q[16], f = 0, r = 0;
    for (int i = 1; i <= n; i++) q[r++] = i;
    int* out = new int[n];
    int idx = 0;
    while (f != r) out[idx++] = q[f++];
    for (int i = 0; i < n; i++) cout << out[i] << (i + 1 < n ? " " : "\n");
    delete[] out;
}

/* TASK 3 — equal after symmetric ops? (MEDIUM)
   Enqueue 4 then dequeue the SAME element. Does the queue go back to
   empty with the same front/rear? Return true if empty. */
bool task3_symmetric() {
    int q[8], f = 0, r = 0;
    q[r++] = 4;
    int value = q[0];          // somehow use it before removing
    f++;
    return f == r && value == 4;   // symmetric enq/deq → empty + value intact
}

/* TASK 4 — front without removing (peek) (MEDIUM)
   Build 10,20,30; peek twice → both times it must still return 10. */
void task4_peekTwice() {
    int q[8] = {10, 20, 30}, f = 0, r = 3;
    int p1 = (f == r) ? -1 : q[f];
    int p2 = (f == r) ? -1 : q[f];
    cout << "peek1=" << p1 << " peek2=" << p2 << " size=" << (r - f) << endl;
}

/* TASK 5 — interleave: dequeue one, enqueue it back (HARD)
   Rotate queue [1,2,3] by moving front to back once: front→2 after 1
   rotation. Return the new front. */
int task5_rotate(int a[], int n) {
    int tmp = a[0];
    for (int i = 1; i < n; i++) a[i - 1] = a[i];   // front to back
    a[n - 1] = tmp;
    return a[0];                                   // new front
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    int a1[3] = {5, 9, 2};
    cout << "front = " << task1_front(a1, 3) << endl;                 // 5

    cout << "---- TASK 2 ----" << endl;
    task2_fifo(5);                                                   // 1 2 3 4 5

    cout << "---- TASK 3 ----" << endl;
    cout << "empty after symmetric ops = " << (task3_symmetric() ? "true" : "false") << endl;

    cout << "---- TASK 4 ----" << endl;
    task4_peekTwice();                                               // peek1=10 peek2=10 size=3

    cout << "---- TASK 5 ----" << endl;
    int a5[3] = {1, 2, 3};
    cout << "after 1 rotation, front = " << task5_rotate(a5, 3) << endl;  // 2
    return 0;
}