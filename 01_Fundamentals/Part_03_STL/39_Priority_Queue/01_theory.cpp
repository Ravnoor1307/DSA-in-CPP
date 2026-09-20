/*
═══════════════════════════════════════════════
 STD::PRIORITY_QUEUE — Heap-Based Priority Queue
 ⏱️ TIME COMPLEXITY:
   push: O(log n)  — bubble up in heap
   pop:  O(log n)  — sift down in heap
   top:  O(1)      — root of heap
   empty/size: O(1) — stored variable
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Walk into a hospital emergency room. Not everyone is served
 in arrival order — the patient with the most critical
 condition (highest priority) is treated first, regardless
 of when they arrived. A heart attack victim cuts ahead of
 someone with a mild cold. std::priority_queue models exactly
 this: elements are not FIFO or LIFO — they are ordered by
 priority. The element with the highest priority is always at
 the top and is served (popped) first. By default, C++ uses
 max-heap (largest value = highest priority). You can flip it
 to min-heap using a comparator.

 📖 THEORY: (pure English, beginner-level)
 - std::priority_queue is a container ADAPTER in <queue>.
 - Underlying container: std::vector by default.
 - Internally maintains a binary heap using the vector.
 - Default: MAX-HEAP → largest element at top.
 - Push: O(log n) — add to end, bubble up.
 - Pop: O(log n) — swap root with last, sift down.
 - Top: O(1) — always at index 0 (root).
 - No iteration, no random access.
 - Custom comparator: greater<int> for min-heap.
 - Custom struct/class comparators for complex types.

 ASCII MAX-HEAP (binary tree in array):

         50              ← top() returns this (root)
        /    \
      30      40
     /  \    /  \
    10  20  35  25

   Array representation: [50, 30, 40, 10, 20, 35, 25]
   Index:                   0   1   2   3   4   5   6
   Parent of i:            (i-1)/2
   Left child of i:        2*i + 1
   Right child of i:       2*i + 2

   push(45) → add at end, bubble up:
   [50, 30, 40, 10, 20, 35, 25, 45]
   45 > parent 10? yes → swap
   [50, 30, 40, 45, 20, 35, 25, 10]
   45 > parent 30? yes → swap
   [50, 45, 40, 30, 20, 35, 25, 10]

   pop() → remove root, move last to root, sift down:
   Move 10 to root: [10, 45, 40, 30, 20, 35, 25]
   10 < max(45,40)? swap with 45: [45, 10, 40, 30, 20, 35, 25]
   10 < max(30,20)? swap with 30: [45, 30, 40, 10, 20, 35, 25]
   10 is leaf → done

 ASCII MIN-HEAP (with greater<int>):

         10              ← top() returns smallest
        /    \
      20      15
     /  \
    30  40

   push(5) → bubble up:
   5 < 20? yes, 5 < 30? yes → 5 becomes new child of root

 🧠 LOGIC — STEP BY STEP:
 Step 1: Push values into max-heap.
   WHY: push adds to vector end O(1), then bubbles up
   O(log n) — comparing with parent at most h levels up.
   Heap height h = floor(log2(n)).
 Step 2: Pop all values.
   WHY: pop removes root, moves last element to root,
   then sifts down O(log n) — comparing with children at
   most h levels down. Popping all gives descending order.
 Step 3: Create min-heap variant.
   WHY: Using greater<int> as comparator flips the order.
   Now top() returns smallest. Popping gives ascending order.

 VISUAL WALKTHROUGH (push operations):

   push(30):     push(50):     push(40):
   ┌─────┐       ┌─────┐       ┌─────┐
   │ 30  │       │ 50  │       │ 50  │
   └─────┘       └─────┘       ├─────┤
                               │ 30  │ 40│

   push(10):     push(20):
       ┌─────┐       ┌─────┐
       │ 50  │       │ 50  │
       ├─────┤       ├─────┤
       │ 30  │ 40│   │ 30  │ 40│
       ├────┤       ├────┤├────┤
       │ 10 │       │ 10 │ 20│

   pop() removes 50 (max), returns 50.

 DRY RUN (demo in main):
   priority_queue<int> pq;
   pq.push(30);  → heap: [30]
   pq.push(10);  → heap: [30, 10]  → bubble: [30, 10] (30>10 ok)
   pq.push(50);  → heap: [30, 10, 50] → bubble 50 up: [50, 10, 30]
   pq.push(20);  → bubble: [50, 20, 30, 10]
   pq.push(40);  → bubble: [50, 40, 30, 10, 20]

   Pop all:
     pop 50 → [40, 20, 30, 10] → sift → [40, 20, 30, 10]
     pop 40 → [10, 20, 30] → sift → [30, 20, 10]
     pop 30 → [10, 20] → sift → [20, 10]
     pop 20 → [10]
     pop 10 → []
   Output (descending): 50 40 30 20 10

   Min-heap variant:
     push same values, pop all → ascending: 10 20 30 40 50

 TIME COMPLEXITY CALCULATION:
 - push(val): Add val at end of vector → O(1).
   Bubble up: compare with parent, swap if larger.
   Height of heap h = floor(log2(n)).
   At most h swaps → O(h) = O(log n).
   → Total = O(1) + O(log n) = O(log n)

 - pop(): Remove root (index 0) → O(1).
   Move last element to root → O(1).
   Sift down: compare with larger child, swap if smaller.
   At most h swaps from root to leaf.
   Height h = floor(log2(n)) → O(log n).
   → Total = O(1) + O(log n) = O(log n)

 - top(): Root is always at index 0 of vector.
   Direct access → O(1).

 - empty()/size(): O(1) member variable.

 → Time Complexity Summary:
   push: O(log n) | pop: O(log n) | top: O(1)

 SPACE COMPLEXITY CALCULATION:
 - Underlying vector stores n elements contiguously.
 - Each element: sizeof(T) bytes.
 - Vector overhead: capacity may be > n (amortized doubling).
   Capacity grows as: n, 2n, 4n... → at most 2x memory.
 - No per-element overhead (unlike list nodes).
 - Heap property maintained by index math, not pointers.
 → Space Complexity = O(n) with ~2x capacity overhead worst case

 APPROACH COMPARISON:
 ┌───────────────┬───────────────┬───────────────┐
 │               │  max-heap     │  min-heap     │
 │               │ (default)     │ (greater<int>)│
 ├───────────────┼───────────────┼───────────────┤
 │ top() returns │  largest      │  smallest     │
 │ pop order     │  descending   │  ascending    │
 │ comparator    │  less<int>    │  greater<int> │
 │ use case      │  top-K largest│  top-K smallest│
 └───────────────┴───────────────┴───────────────┘

 Container adapter comparison:
 ┌───────────────┬───────────┬───────────┬───────────┐
 │               │  stack    │  queue    │ p_queue   │
 ├───────────────┼───────────┼───────────┼───────────┤
 │ order         │  LIFO     │  FIFO     │ priority  │
 │ add           │  push     │  push     │  push     │
 │ remove        │  pop      │  pop      │  pop      │
 │ peek          │  top      │  front    │  top      │
 │ time push     │  O(1)     │  O(1)     │  O(log n) │
 │ time pop      │  O(1)     │  O(1)     │  O(log n) │
 │ underlying    │  deque    │  deque    │  vector   │
 └───────────────┴───────────┴───────────┴───────────┘
 ────────────────────────────────────────────────────
*/

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

void printPQ(priority_queue<int> pq, const string& label) {
    cout << label << " (top→bottom): ";
    if (pq.empty()) { cout << "(empty)"; }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    cout << "========== STD::PRIORITY_QUEUE DEMO ==========\n\n";

    // --- Max-heap (default) ---
    priority_queue<int> maxPQ;
    maxPQ.push(30);
    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(20);
    maxPQ.push(40);
    cout << "Max-heap after pushing 30,10,50,20,40:\n";
    cout << "  size = " << maxPQ.size() << endl;
    cout << "  top  = " << maxPQ.top() << " (largest)\n";
    printPQ(maxPQ, "  Heap");

    // --- Pop all — descending order ---
    cout << "\nPopping all (descending order):\n  ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    cout << endl;

    // --- Min-heap using greater<int> ---
    cout << "\n--- Min-heap (greater<int>) ---\n";
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);
    minPQ.push(40);
    cout << "  top = " << minPQ.top() << " (smallest)\n";
    cout << "Popping all (ascending order):\n  ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;

    // --- emplace ---
    cout << "\n--- emplace demo ---\n";
    priority_queue<int> pq2;
    pq2.emplace(100);
    pq2.emplace(50);
    pq2.emplace(200);
    cout << "  top = " << pq2.top() << " (largest)\n";

    // --- Swap ---
    cout << "\n--- Swap demo ---\n";
    priority_queue<int> pq3;
    pq3.push(999);
    pq2.swap(pq3);
    cout << "  After swap: pq2.top() = " << pq2.top() << endl;

    // --- Edge case: empty priority_queue ---
    cout << "\n--- Edge Case: Empty Priority Queue ---\n";
    priority_queue<int> empty;
    cout << "  empty.empty() = " << (empty.empty() ? "true" : "false") << endl;
    cout << "  empty.size()  = " << empty.size() << endl;
    // NEVER call top() on empty — undefined behavior!
    // if (!empty.empty()) { empty.top(); } // safe guard

    cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
