/*
═══════════════════════════════════════════════
 QUEUE APPLICATIONS — stack-from-queue, generate binary, first non-repeating
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Three classic "build with a queue" problems.
 1) You already own a queue object but need STACK behaviour for a plugin
    system — can you simulate LIFO using only FIFO? Yes: two queues.
 2) A ticket-printer must emit binary numbers 1,2,3,...10 in sequence —
    that's really "1, then append 0 and 1 to every existing number":
    a BFS-level queue expansion.
 3) A chat client must mark the FIRST character that has not repeated since
    the stream opened — a queue of candidates plus a count table solves a
    problem a naive re-scan would handle in O(n·n).

 📖 THEORY: (pure English)
 - STACK FROM TWO QUEUES:
   * Keep q1 live, q2 as buffer.
   * push(x): enqueue x into q1. Pop: move all but last from q1→q2, the
     last one is the top, then swap q1/q2.
   * That makes pop O(n) per call: one full transfer of the queue. The
     alternative "push = transfer" scheme is symmetric — O(n) on push.
   * Both achieve LIFO with only FIFO primitives; pick where the cost lands.
 - GENERATE BINARY NUMBERS 1..n (BFS level idea):
   * q = ["1"]; while output count < n: dequeue s, print s; enqueue s+"0"
     and s+"1".
   * WHY it works: every binary string is either "1" or (a parent string)+"0"
     or +"1"; a FIFO visits strings in length+breadth order → numbers 1..n.
 - FIRST NON-REPEATING CHARACTER in a STREAM:
   * freq[256] counts occurrences; a queue holds characters that might be
     first-non-repeating.
   * For each new char: bump freq; if freq==1 push to queue. While the queue
     front has freq>1 pop it (it has become a repeat). The front is now the
     answer, or -1 if empty.
   * WHY a queue: candidates appear in arrival order, which is exactly which
     to prefer if ties in "first non-repeating" — the earliest single count.
   * Each char enters the queue once and leaves once → O(1) amortized per
     character.

  ASCII — stack via two queues (push 1,2,3 then pop):
   q1: [1] → push2 → [1,2] → push3 → [1,2,3]
   pop: move all but last: q2 = [1,2], top=3   (q1 empty)
   swap → q1=[1,2], q2=[]   → pop again: q2=[1], top=2
   → LIFO order 3, 2, 1  ✓

  ASCII — binary generator:
        q
       [1]  → deq 1  print 1  enq 10, 11
       [10,11] → deq 10 print 10  enq 100,101
       [11,100,101] → deq 11 ...

  ASCII — first non-repeating for "aabc":
      a: freq[a]=1 q=[a]        → answer a
      a: freq[a]=2 q=[a,a] f a→pop ⇒ q=[a] → a repeated → pop ⇒ [] answer -1
      b: freq[b]=1 q=[b]        → answer b
      c: freq[c]=1 q=[b,c]      → answer b

 🧠 LOGIC — STEP BY STEP (stack from queues):
 Step 1: Always push into LIVE queue.
        WHY: the live queue holds the stack's bottom→top in FIFO order.
 Step 2: On pop, drain all but the LAST element into the buffer queue.
        WHY: the last-in is at the TAIL of FIFO; moving the others away
        exposes the tail as the top.
 Step 3: Return the last element, then SWAP live/buffer.
        WHY: the buffer now holds the remaining stack (bottom→top) — it
        becomes the new live queue so the next pop repeats the same plan.

 🧠 LOGIC — STEP BY STEP (binary generation):
 Step 1: Seed q with "1".
        WHY: every positive binary string starts with a leading 1.
 Step 2: Repeat n times: dequeue s, print s, push s+"0" and s+"1".
        WHY: prepending 0/1 to existing valid strings enumerates all binary
        strings without duplication, in breadth order.
 Step 3: FIFO ensures length order (short numbers before longer ones).
        WHY: levels are enqueued in order; dequeue is FIFO — guaranteed 1..n.

 🧠 LOGIC — STEP BY STEP (first non-repeating):
 Step 1: freq[c]++ whenever c arrives.
        WHY: a char "becomes repeated" exactly when its count crosses 1.
 Step 2: If the queue front repeats (freq>1) pop it — and keep popping.
        WHY: a repeated front can never be the answer again; it blocks later
        candidates that are still single.
 Step 3: Front of queue (or -1) = answer.
        WHY: among unrepeated candidates, arrival order wins — the queue
        preserves it.

 VISUAL WALKTHROUGH: stack pop trace (3 pops on [1,2,3]) + binary print 1..5
   stack : pop → 3 ; pop → 2 ; pop → 1
   binary: 1, 10, 11, 100, 101

 DRY RUN: (demo below, exact prints)
   STACK VIA TWO QUEUES:
     push 1,2,3 → top via pop = 3 ; size now 2
     pop → 2 ; pop → 1 ; empty
   BINARY 1..5:
     1 10 11 100 101
   FIRST NON-REPEATING for "aabc":
     process 'a' → a
     process 'a' → -1
     process 'b' → b
     process 'c' → b
 TIME COMPLEXITY CALCULATION:
 - Stack-via-queues: each pop transfers O(n) elements with O(1) work each →
   O(n) per pop, O(1) per push; k ops total → O(n·k) worst. (Alternative
   scheme pushes in O(n), pops O(1); same asymmetry.)
 - Binary generator: n outputs, each costs 2 enqueues + 1 dequeue of strings
   whose total length up to ~log2(n) → O(n log n) bit work; string-op count
   O(n). (If we ignore string copying: O(n) queue ops.)
 - First-non-repeating: each char enqueued once + popped at most once →
   O(n) amortized; freq counts O(256) board → effectively O(n).
 - Compare naive "scan whole history for each new char" = O(n·n).

 SPACE COMPLEXITY CALCULATION:
 - Stack-via-queues: two queues hold all n stack items → O(n).
 - Binary generator: queue holds O(n) strings of total length O(n log n) in
   the worst case; if we cap to the printed count, O(n).
 - First-non-repeating: freq[256] + queue of unrepeated candidates ≤ n
   characters → O(n); the count table is O(1) constant (256).

 APPROACH COMPARISON:
 ┌─────────────────────────┬────────────────────┬─────────────────────────┐
 │ Problem                 │ Naive              │ Queue technique         │
 ├─────────────────────────┼────────────────────┼─────────────────────────┤
 │ stack from queues       │ one-stack (2 queues)│ push O(1) / pop O(n)   │
 │ binary 1..n             │ per-number f(str)  │ BFS-enqueue 1..n        │
 │ first non-repeating     │ re-scan O(n·n)     │ queue+counts O(n)       │
 └─────────────────────────┴────────────────────┴─────────────────────────┘
 */
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// ---- stack built from two queues: push O(1), pop O(n) ----
struct StackViaQueues {
    queue<int> live, buf;
    void push(int x) { live.push(x); }
    int pop() {
        while (live.size() > 1) {           // last wala chhod do
            buf.push(live.front());
            live.pop();
        }
        int top = live.front();
        live.pop();
        swap(live, buf);                     // buffer ab live ban gya
        return top;
    }
    bool empty() { return live.empty(); }
};

// ---- generate binary numbers 1..n using a queue ----
void genBinary(int n) {
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++) {
        string s = q.front(); q.pop();
        cout << s;
        if (i + 1 < n) cout << " ";
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << endl;
}

// ---- first non-repeating char in a stream ----
void firstNonRepeating(const string& s) {
    int freq[256] = {0};
    queue<char> q;
    string out;
    for (char c : s) {
        freq[(unsigned char)c]++;
        if (freq[(unsigned char)c] == 1) q.push(c);
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) q.pop(); // repeat hatanao
        out += q.empty() ? "-1 " : string(1, q.front()) + " ";
    }
    if (!out.empty()) out.pop_back();
    cout << out << endl;
}

int main() {
    cout << "===== STACK VIA TWO QUEUES =====" << endl;
    StackViaQueues st;
    st.push(1); st.push(2); st.push(3);
cout << "pop -> " << st.pop() << " ; empty=" << (st.empty() ? "true" : "false") << endl; // 3, false
    int p1 = st.pop(); int p2 = st.pop();
    cout << "pop -> " << p1 << " ; pop -> " << p2 << endl;                               // 2, 1

    cout << "===== BINARY 1..5 =====" << endl;
    genBinary(5);                                 // 1 10 11 100 101

    cout << "===== FIRST NON-REPEATING of aabc =====" << endl;
    firstNonRepeating("aabc");                    // a -1 b b
    return 0;
}
