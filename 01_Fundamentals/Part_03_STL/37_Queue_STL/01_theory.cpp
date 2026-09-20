/*
═══════════════════════════════════════════════
 STD::QUEUE — FIFO Container Adapter
 ⏱️ TIME COMPLEXITY:
   push (enqueue): O(1)  — add to back
   pop (dequeue):  O(1)  — remove from front
   front:          O(1)  — peek oldest element
   back:           O(1)  — peek newest element
   empty/size:     O(1)  — stored variable
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Picture a ticket counter at a busy railway station. People
 stand in a line. The person who arrives first gets served
 first and leaves first. New people join at the back of the
 queue. This "first-in, first-out" (FIFO) pattern is the
 essence of std::queue. Real uses include: printer spooler
 (jobs printed in order received), CPU scheduling (processes
 waiting in a ready queue), and BFS graph traversal where
 nodes are processed level by level.

 📖 THEORY: (pure English, beginner-level)
 - std::queue is a container ADAPTER in <queue>.
 - Wraps an underlying container (default: std::deque).
 - Only front (oldest) and back (newest) are accessible.
 - push() adds to back, pop() removes from front.
 - front() returns oldest element, back() returns newest.
 - No iteration, no random access — pure FIFO.
 - emplace() constructs element in-place at back.
 - swap() exchanges contents with another queue.
 - Underlying container must support: push_back, pop_front,
   front, back, empty, size — all O(1).

 ASCII FIFO / QUEUE DIAGRAM:

    FRONT (serve here)         BACK (new entries here)
        │                          │
        ▼                          ▼
    ┌───────┬───────┬───────┬───────┐
    │  10   │  20   │  30   │  40   │
    └───────┴───────┴───────┴───────┘
      ↑
      push(50) adds here →  [10, 20, 30, 40, 50]
      pop() removes 10    →  [20, 30, 40, 50]
      front() returns 10  (does NOT remove)
      back() returns 40   (does NOT remove)

 🧠 LOGIC — STEP BY STEP:
 Step 1: Push (enqueue) 5 elements at the back.
   WHY: push() is O(1). Underlying deque push_back is O(1).
   Elements are added in order — oldest at front.
 Step 2: Peek front and back.
   WHY: front() gives the element to be served next — O(1).
   back() gives the most recently added — O(1).
 Step 3: Pop (dequeue) all elements.
   WHY: FIFO — front element removed first. Each pop is O(1).
   Popping all gives elements in original insertion order.
 Step 4: Check empty and size.
   WHY: Both O(1) — maintained as member variables.

 VISUAL WALKTHROUGH:

   push(10):     push(20):     push(30):
   ┌─────┐       ┌─────┬─────┐  ┌─────┬─────┬─────┐
   │ 10  │       │ 10  │ 20  │  │ 10  │ 20  │ 30  │
   └─────┘       └─────┴─────┘  └─────┴─────┴─────┘
   front=10      front=10       front=10
   back=10       back=20        back=30

   pop():        pop():
   ┌─────┬─────┐  ┌─────┐
   │ 20  │ 30  │  │ 30  │
   └─────┴─────┘  └─────┘
   front=20      front=30
   back=30       back=30

 DRY RUN (demo in main):
   queue<int> q;
   q.push(10);  → [10]        front=10, back=10
   q.push(20);  → [10,20]     front=10, back=20
   q.push(30);  → [10,20,30]  front=10, back=30
   q.push(40);  → [10..40]    front=10, back=40
   q.push(50);  → [10..50]    front=10, back=50
   front()=10, pop → [20,30,40,50]
   front()=20, pop → [30,40,50]
   front()=30, pop → [40,50]
   front()=40, pop → [50]
   front()=50, pop → [] (empty)
   Output (FIFO order): 10 20 30 40 50

 TIME COMPLEXITY CALCULATION:
 - push(): Adds element to back of underlying deque.
   deque push_back is O(1) amortized — append to end block.
   → Total = O(1)

 - pop(): Removes element from front of underlying deque.
   deque pop_front is O(1) — remove from front block.
   → Total = O(1)

 - front()/back(): Underlying deque front()/back() — O(1)
   direct access to first/last element of blocks.
   → Total = O(1)

 - empty()/size(): O(1) member variable.
   → Total = O(1)

 → Time Complexity = O(1) for all operations

 SPACE COMPLEXITY CALCULATION:
 - Queue stores n elements in underlying deque.
 - deque uses segmented blocks — no full reallocation.
 - Each element: sizeof(T) bytes.
 - deque overhead: small array of block pointers.
 - No per-element pointer overhead (unlike list).
 → Space Complexity = O(n)

 APPROACH COMPARISON:
 ┌───────────────┬───────────┬───────────┐
 │   Operation   │  queue    │  stack    │
 ├───────────────┼───────────┼───────────┤
 │ add element   │ push(back)│ push(top) │
 │ remove        │ pop(front)│ pop(top)  │
 │ peek next     │ front()   │ top()     │
 │ order         │ FIFO      │ LIFO      │
 │ use case      │ BFS,print │ undo,DFS  │
 └───────────────┴───────────┴───────────┘

 Underlying container comparison:
 ┌───────────────┬───────────┬───────────┐
 │               │  default  │  list     │
 │               │ (deque)   │  backed   │
 ├───────────────┼───────────┼───────────┤
 │ push          │  O(1)     │  O(1)     │
 │ pop           │  O(1)     │  O(1)     │
 │ memory        │  blocks   │  per-node │
 │ cache perf    │  good     │  poor     │
 │ note          │  best     │  avoids   │
 │               │  default  │  deque    │
 └───────────────┴───────────┴───────────┘
 ────────────────────────────────────────────────────
*/

#include <iostream>
#include <queue>
#include <list>
using namespace std;

void printQueue(queue<int> q, const string& label) {
    cout << label << " (front→back): ";
    if (q.empty()) { cout << "(empty)"; }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    cout << "========== STD::QUEUE DEMO ==========\n\n";

    queue<int> q;

    // --- Enqueue 5 elements ---
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << "After enqueue 10,20,30,40,50:\n";
    cout << "  size  = " << q.size() << endl;
    cout << "  front = " << q.front() << endl;
    cout << "  back  = " << q.back() << endl;
    printQueue(q, "  Queue");

    // --- Dequeue all (FIFO order) ---
    cout << "\nDequeueing all (FIFO order):\n  ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << "  size after dequeue all = " << q.size() << endl;
    cout << "  empty? " << (q.empty() ? "yes" : "no") << endl;

    // --- emplace (construct in-place) ---
    cout << "\n--- emplace demo ---\n";
    q.emplace(100);
    q.emplace(200);
    cout << "After emplace(100) and emplace(200):\n";
    cout << "  front = " << q.front() << endl;
    cout << "  back  = " << q.back() << endl;

    // --- Swap two queues ---
    queue<int> q2;
    q2.push(999);
    q.swap(q2);
    cout << "\nAfter swap with q2:\n";
    cout << "  q.front()  = " << q.front() << endl;
    cout << "  q2.front() = " << q2.front() << endl;

    // --- List-backed queue ---
    cout << "\n--- list-backed queue ---\n";
    queue<int, list<int>> qList;
    qList.push(7);
    qList.push(8);
    qList.push(9);
    cout << "  front = " << qList.front() << endl;
    cout << "  back  = " << qList.back() << endl;

    // --- Edge case: empty queue ---
    cout << "\n--- Edge Case: Empty Queue ---\n";
    queue<int> empty;
    cout << "  empty.empty() = " << (empty.empty() ? "true" : "false") << endl;
    cout << "  empty.size()  = " << empty.size() << endl;
    // NEVER call front()/back() on empty queue — UB!
    // if (!empty.empty()) { empty.front(); } // safe guard

    cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
