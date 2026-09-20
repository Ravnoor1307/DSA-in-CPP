/*
 * ══════════════════════════════════════════════════
 *  TASKS — 05_Queue_Applications
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <queue>
#include <string>
using namespace std;

/* TASK 1 — peek at stack top without popping (EASY)
   Using two queues, return the top value but keep the stack intact.
   on [1,2,3] (top=3) → return 3, size 3. */
int task1_top() {
    queue<int> live, buf;
    for (int i = 1; i <= 3; i++) live.push(i);
    while (live.size() > 1) { buf.push(live.front()); live.pop(); }
    int top = live.front();
    buf.push(top);                 // wapas upper end par
    swap(live, buf);
    return top;                    // 3
}

/* TASK 2 — binary numbers n=3 by queue (EASY)
   Generate 1,10,11 → return the third generated string. */
string task2_binary3() {
    queue<string> q;
    q.push("1");
    string s;
    for (int i = 0; i < 3; i++) { s = q.front(); q.pop(); q.push(s + "0"); q.push(s + "1"); }
    return s;                      // 11
}

/* TASK 3 — stack push-cost vs pop-cost count (MEDIUM)
   For k=5 pops starting from an 11-element stack, count total elements
   moved (the drain transfers size-1 each pop). Sum = (10 + 9 + 8 + 7 + 6).
   Return the sum. */
int task3_moves(int startSize, int pops) {
    int total = 0, cur = startSize;
    for (int i = 0; i < pops && cur > 0; i++) {
        total += cur - 1;          // har pop par n-1 moves
        cur--;
    }
    return total;                  // 40 for 11,5 → 10+9+8+7+6 = 40
}

/* TASK 4 — first non-repeating using queue+count on "abac" (MEDIUM)
   Return the answer after the 4th char ("c"): queue [a,b,c]? freq a=2 → a
   removed, b single → answer 'b'. */
char task4_firstNonRep() {
    string s = "abac";
    int freq[256] = {0};
    queue<char> q;
    for (char c : s) {
        freq[(unsigned char)c]++;
        if (freq[(unsigned char)c] == 1) q.push(c);
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) q.pop();
    }
    return q.empty() ? '-' : q.front();   // b
}

/* TASK 5 — implement queue using ONE stack + recursion (HARD)
   Classic: use an auxiliary stack for enqueue cost. Simpler measurable:
   reverse a queue using a stack (push all → queue via reversed order) and
   return the final front. [1,2,3] → stack [1,2,3] → queue from stack pops
   → [3,2,1] → front = 3. */
int task5_reverseQueue() {
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    int st[4], top = 0;
    while (!q.empty()) { st[top++] = q.front(); q.pop(); }
    while (top > 0) q.push(st[--top]);
    return q.front();              // 3
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    cout << "top = " << task1_top() << endl;            // 3

    cout << "---- TASK 2 ----" << endl;
    cout << "3rd = " << task2_binary3() << endl;        // 11

    cout << "---- TASK 3 ----" << endl;
    cout << "total moves = " << task3_moves(11, 5) << endl;  // 40

    cout << "---- TASK 4 ----" << endl;
    cout << "res = " << task4_firstNonRep() << endl;    // b

    cout << "---- TASK 5 ----" << endl;
    cout << "front = " << task5_reverseQueue() << endl; // 3
    return 0;
}