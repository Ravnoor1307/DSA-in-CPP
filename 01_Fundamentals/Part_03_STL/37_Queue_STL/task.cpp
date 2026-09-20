/*
═══════════════════════════════════════════════
 TASK SET — STD::QUEUE
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
A printer spooler serves jobs exactly in the order they arrived —
first in, first out (FIFO). A network router does the same with
outgoing packets. Live-streaming services also reconstruct data in
order, and BFS walks a graph level-by-level using a queue. In one
famous trick, you can even build a binary counter — printing 1,
10, 11, 100, 101... — by enqueueing "0" and "1" appended strings.

🧠 HOW TO SOLVE:
std::queue gives access ONLY at front (oldest) and back (newest).
To reverse a queue, dump into a stack and push back. To build
sequences, push the NEXT states while popping the CURRENT one.
For "stack using queue", the newest element must sit at front —
re-queue everything older behind it.

 6-6 tasks EASY → HARD:
──────────────────────────────────────────────
 TASK 1 — Binary counter (1, 10, 11, 100...)
 Statement: Print the first N binary numbers using a queue:
            N=5 → 1 10 11 100 101.
 💡 HINT: Start with "1". For every front x, push x+"0" and x+"1".
 ✏️ STARTER CODE:
 // queue<string> q; q.push("1");
 // while (n--) { string cur = q.front(); q.pop();
 //   cout << cur << " ";
 //   q.push(cur + "0"); q.push(cur + "1"); }
──────────────────────────────────────────────
 TASK 2 — Reverse a queue
 Statement: Reverse {1, 2, 3, 4, 5} → {5, 4, 3, 2, 1} using a stack.
 💡 HINT: Pop all into a stack (LIFO), then push back into queue.
 ✏️ STARTER CODE:
 // stack<int> st;
 // while (!q.empty()) { st.push(q.front()); q.pop(); }
 // while (!st.empty()) { q.push(st.top()); st.pop(); }
──────────────────────────────────────────────
 TASK 3 — First n numbers with digits {5, 6}
 Statement: Using digits {5, 6}, generate first N numbers in
            increasing order: N=6 → 5 6 55 56 65 66.
 💡 HINT: Same pattern as binary counter: cur+"5" and cur+"6"
          always stay sorted.
 ✏️ STARTER CODE:
 // queue<string> q; q.push("5"); q.push("6");
 // while (n--) { string cur = q.front(); q.pop();
 //   cout << cur << " ";
 //   q.push(cur + "5"); q.push(cur + "6"); }
──────────────────────────────────────────────
 TASK 4 — Stack using two queues (push cost heavy)
 Statement: Build a Stack (push/pop/top) from two queues only.
            push(1,2,3) then top → 3, pop → removes 3.
 💡 HINT: In push: put x first, then move all old front elements
          behind x so x becomes the new FRONT.
 ✏️ STARTER CODE:
 // queue<int> q1, q2;
 // void push(int x) {
 //   q2.push(x);                    // naya element q2 me
 //   while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
 //   swap(q1, q2);                  // ab q1 ka front = sabse naya
 // }
 // int pop() { int v = q1.front(); q1.pop(); return v; }
──────────────────────────────────────────────
 TASK 5 — First non-repeating character in a stream (intro)
 Statement: Stream = 'a','b','a','c'. After each char print the
            first non-repeating char seen so far, or '#' if none.
            Output: a a b b  (characters: a, ab, aba, abac).
 💡 HINT: enqueue into a queue; count occurrences in a map. At each
          step pop front until its count == 1; that front is answer.
 ✏️ STARTER CODE:
 // queue<char> q; int cnt[26] = {0};
 // for (char c : stream) {
 //   cnt[c-'a']++; q.push(c);
 //   while (!q.empty() && cnt[q.front()-'a'] > 1) q.pop();
 //   char ans = q.empty() ? '#' : q.front();
 //   cout << ans << " ";
 // }
──────────────────────────────────────────────
 TASK 6 — Stock span (intro to queue/stack hybrid thinking)
 Statement: Daily prices = {100, 80, 60, 70, 60, 75, 85}. The span is
            how many price-arrivals ≤ today's price are consecutive
            before a bigger price. Use the queue order. Output spans:
            1 1 1 2 1 4 6.
 💡 HINT: Hard version uses a monotonic stack; here, simply walk BACK
          from today while prices[j] <= today and count. Use a queue
          free walk — indices are processed in FIFO order.
 ✏️ STARTER CODE:
 // vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
 // for (int i = 0; i < n; ++i) {
 //   int span = 1;
 //   for (int j = i-1; j >= 0 && prices[j] <= prices[i]; --j) span++;
 //   cout << span << " ";
 // }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// ---------- TASK 1: binary counter ----------
void task1() {
    cout << "\n=== TASK 1: First 5 binary numbers ===\n";
    queue<string> q;
    q.push("1");
    int n = 5;
    while (n--) {
        string cur = q.front(); q.pop();   // current number lo
        cout << cur << " ";                // print karo
        q.push(cur + "0");                 // aur uske bachche banao
        q.push(cur + "1");
    }
    cout << endl; // expect 1 10 11 100 101
}

// ---------- TASK 2: reverse a queue ----------
void task2() {
    cout << "\n=== TASK 2: Reverse a queue ===\n";
    queue<int> q;
    for (int i = 1; i <= 5; ++i) q.push(i);

    stack<int> st;                          // LIFO to ulta kar dega
    while (!q.empty()) { st.push(q.front()); q.pop(); }
    while (!st.empty()) { q.push(st.top()); st.pop(); }

    cout << "Reversed queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl; // expect 5 4 3 2 1
}

// ---------- TASK 3: first n numbers with digits {5,6} ----------
void task3() {
    cout << "\n=== TASK 3: First 6 numbers from digits {5,6} ===\n";
    queue<string> q;
    q.push("5");
    q.push("6");
    int n = 6;
    while (n--) {
        string cur = q.front(); q.pop();
        cout << cur << " ";
        q.push(cur + "5");   // "5x" forms chhote hain "6x" se, isliye
        q.push(cur + "6");   // sequences hamesha sorted hi milti hain
    }
    cout << endl; // expect 5 6 55 56 65 66
}

// ---------- TASK 4: stack using two queues ----------
class StackByQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);                            // naya element q2 me daalo
        while (!q1.empty()) {                  // purane wale uske peeche
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);                          // ab q1 front = sabse naya element
    }

    int pop() {
        int v = q1.front();
        q1.pop();
        return v;
    }

    int top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

void task4() {
    cout << "\n=== TASK 4: Stack using two queues ===\n";
    StackByQueues st;
    st.push(1); st.push(2); st.push(3);
    cout << "After push 1,2,3 -> top = " << st.top() << endl;
    cout << "pop -> " << st.pop() << " | new top = " << st.top() << endl;
    cout << "pop -> " << st.pop() << " | new top = " << st.top() << endl;
}

// ---------- TASK 5: first non-repeating char in stream ----------
void task5() {
    cout << "\n=== TASK 5: First non-repeating char in stream ===\n";
    string stream = "abac";
    queue<char> q;
    int cnt[26] = {0};

    cout << "Stream:  ";
    for (char c : stream) cout << c << " ";
    cout << "\nAnswer:  ";

    for (char c : stream) {
        cnt[c - 'a']++;
        q.push(c);
        // front tab tak nikaalo jab tak wo repeat ho raha ho
        while (!q.empty() && cnt[q.front() - 'a'] > 1) q.pop();
        char ans = q.empty() ? '#' : q.front();
        cout << ans << " ";
    }
    cout << endl; // expect a a b b
}

// ---------- TASK 6: stock span ----------
void task6() {
    cout << "\n=== TASK 6: Stock span ===\n";
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    int n = prices.size();

    for (int i = 0; i < n; ++i) {
        int span = 1;
        // piche jao jab tak prices chhote/barabar hain aur consecutive
        for (int j = i - 1; j >= 0 && prices[j] <= prices[i]; --j) ++span;
        cout << "Day " << i + 1 << " (price " << prices[i] << "): span = "
             << span << endl;
    }
}

int main() {
    cout << "========== STD::QUEUE TASK SET ==========\n";
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    cout << "\n========== ALL TASKS COMPLETE ==========\n";
    return 0;
}