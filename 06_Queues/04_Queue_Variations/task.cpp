/*
 * ══════════════════════════════════════════════════
 *  TASKS — 04_Queue_Variations
 *  6 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

/* TASK 1 — deque alternate ends (EASY)
   push_back 10, push_front 5, pop_front → what's back? Return back. */
int task1_deque() {
    deque<int> d;
    d.push_back(10);
    d.push_front(5);
    d.pop_front();
    return d.back();               // 10
}

/* TASK 2 — priority queue keeps max on top (EASY)
   Push 4,9,2,7 → pop order must be 9,7,4,2. Return second popped. */
int task2_pq() {
    priority_queue<int> pq;
    pq.push(4); pq.push(9); pq.push(2); pq.push(7);
    pq.pop();
    int second = pq.top();
    return second;                 // 7
}

/* TASK 3 — min-heap: k-th smallest via priority_queue (MEDIUM)
   Given {8,3,10,1,6}, find the 2nd smallest by popping a min-heap once.
   Return the new top. */
int task3_minTop() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int a[5] = {8, 3, 10, 1, 6};
    for (int i = 0; i < 5; i++) pq.push(a[i]);
    pq.pop();                      // remove 1 (smallest)
    return pq.top();               // 3
}

/* TASK 4 — deque as sliding window buffer (MEDIUM)
   Keep a window of size 3 using a deque; push_back new items and
   pop_front when size > 3. Feed 1..5 → after all, front=3 back=5. */
void task4_sliding() {
    deque<int> d;
    for (int i = 1; i <= 5; i++) {
        d.push_back(i);
        if ((int)d.size() > 3) d.pop_front();
    }
    cout << "window front=" << d.front() << " back=" << d.back()
         << " size=" << d.size() << endl;   // front=3 back=5 size=3
}

/* TASK 5 — sort with two priority queues (MEDIUM-HARD)
   Push half into max-heap, half into min-heap, then interleave? No —
   simpler: use a min-heap to sort ascending by popping. Return the 3rd
   smallest of {12,4,9,7,2}. */
int task5_sortByHeap() {
    priority_queue<int, vector<int>, greater<int>> mpq;
    int a[5] = {12, 4, 9, 7, 2};
    for (int i = 0; i < 5; i++) mpq.push(a[i]);
    int third;
    for (int i = 0; i < 3; i++) { third = mpq.top(); mpq.pop(); }
    return third;                  // 7
}

/* TASK 6 — heap vs array: count comparisons (HARD)
   Not measured directly; instead return heap height for 13 nodes.
   h = floor(log2(13)) = 3 (levels 0..3). */
int task6_height(int n) {
    int h = 0;
    while ((1 << (h + 1)) <= n) h++;
    return h;                      // 3 for n=13
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    cout << "back = " << task1_deque() << endl;         // 10

    cout << "---- TASK 2 ----" << endl;
    cout << "second popped = " << task2_pq() << endl;   // 7

    cout << "---- TASK 3 ----" << endl;
    cout << "2nd smallest = " << task3_minTop() << endl;  // 3

    cout << "---- TASK 4 ----" << endl;
    task4_sliding();

    cout << "---- TASK 5 ----" << endl;
    cout << "3rd smallest = " << task5_sortByHeap() << endl;  // 7

    cout << "---- TASK 6 ----" << endl;
    cout << "heap height(13) = " << task6_height(13) << endl; // 3
    return 0;
}