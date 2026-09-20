/*
═══════════════════════════════════════════════
 QUEUE INTRO — FIFO concept, operations, stack-vs-queue, applications
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A godown queue at a railway counters. The FIRST person who arrives stands in
 front, and when the counter frees up, that FIRST person is served FIRST.
 Newcomers line up at the BACK. Nobody pushes in from the middle. This
 "First In, First Out" rule is called FIFO, and the data structure that enforces
 it is the QUEUE. Same model everywhere: printer jobs process in arrival
 order, OS schedules processes in arrival order, a phone helpdesk takes calls
 in order, and a server queues incoming requests so no one starves.

 📖 THEORY: (pure English)
 - QUEUE = an ordered collection open at TWO ends: FRONT (dequeue/removal)
   and REAR/BACK (enqueue/insertion). Insertion and removal happen at
   DIFFERENT ends — that asymmetric access is FIFO.
 - CORE OPERATIONS:
     * enqueue(x) — insert at REAR.
     * dequeue()  — remove & return the FRONT element.
     * front()/peek — view FRONT without removing.
     * isEmpty()   — true if empty.
     * size()      — element count.
 - FIFO vs LIFO at a glance:
     * Stack: push/pop at TOP (same end) → last-in-first-out.
     * Queue: enqueue at REAR, dequeue at FRONT (different ends) →
       first-in-first-out.
 - The front pointer only ever moves toward the rear; the rear only grows —
   in a naive array that means the front end fills with garbage "wasted
   space" (topic 02 fixes this with a circular buffer).
 - TYPE-ALIAS CONVENTION: some texts use "push/pop/front"; C++ STL queue
   uses push/pop/front/back where pop = dequeue(front). Standards diverge
   slightly in naming, but the underlying behaviour is identical.

  ASCII — the queue:
        dequeue           enqueue
        ← FRONT            REAR →
            │                 │
            ▼                 ▼
      ┌─────┬─────┬─────┬─────┐
      │  10 │  20 │  30 │  40 │
      └─────┴─────┴─────┴─────┘

  ASCII — where a printer queue grows and shrinks:
     job = 1 came first:
        ┌───┬───┬───┐
        │ 1 │ 2 │ 3 │   enqueue(4) → │ 1 2 3 4 │   dequeue() → 1 done
        └───┴───┴───┘                 │ 2 3 4 │

 🧠 LOGIC — STEP BY STEP:
 Step 1: Insert ONLY from back, remove ONLY from front.
        WHY: that rule literally IS FIFO; a queue that lets you delete from
        the middle stops being a queue.
 Step 2: front() guard: return error if empty.
        WHY: reading the front of an empty queue is undefined; the guard
        converts a crash into a safe no-op/error.
 Step 3: enqueue/dequeue must keep FRONT ahead of (or equal to) REAR in a
        naive array, or wrap around in a circular array.
        WHY: the array is the physical storage; keeping the two indices
        consistent is what prevents out-of-bounds reads/writes.
 Step 4: When dequeue empties the queue, reset BOTH indices to zero.
        WHY: resetting lets the next enqueue start fresh at index 0 instead
        of slowly drifting toward the end and hitting "wasted space".
 Step 5: If you ever need random access or LIFO order, do NOT reach for a queue.
        WHY: a queue offers strictly first-in-first-out semantics; forcing
        other semantics onto it breaks its contract.

 VISUAL WALKTHROUGH: enqueue 10,20,30 → dequeue → peek
   start:         (empty)              rear=0, front=0
   enqueue 10:    [10]                 rear=1, front=0
   enqueue 20:    [10,20]              rear=2, front=0
   enqueue 30:    [10,20,30]           rear=3, front=0
   dequeue():     returns 10 → [_,20,30] front=1
   front():       returns 20 (queue still [_,20,30])
   dequeue():     returns 20 → [_,_,30] front=2
   dequeue():     returns 30 → empty    front=3, rear=3
   dequeue():     UNDERFLOW → "empty queue"

 DRY RUN: (demo below, exact prints)
   enqueue 10, 20, 30
   queue size = 3 ; front = 10
   dequeue() → 10 ; queue size = 2 ; front now 20
   dequeue() → 20 ; dequeue() → 30 ; isEmpty() → true
   dequeue() on empty → "underflow: empty queue"

 TIME COMPLEXITY CALCULATION:
 - enqueue: write at rear + increment rear → constant instructions → O(1).
 - dequeue: read/return front + increment front → O(1).
 - front/peek: single index read → O(1).
 - isEmpty/size: constant comparisons → O(1).
   → Every core operation is O(1). (Applies to both naive and circular
     arrays; the circular variant just keeps those O(1)s from degrading as
     the queue continues.)

 SPACE COMPLEXITY CALCULATION:
 - Array portion: we reserve an array of capacity c → O(c); only the front
  ..rear window holds live data.
 - Linked variant (topic 03): n heap nodes → O(n).
 - Auxiliary (front/rear index, size counter): O(1).
 → Space = O(n) for the data plus O(1) auxiliary.

 APPROACH COMPARISON:
 ┌──────────────────────┬───────────────────┬───────────────────────────┐
 │ Aspect               │ Naive array queue │ Linked-list queue         │
 ├──────────────────────┼───────────────────┼───────────────────────────┤
 │ FIFO enqueue/dequeue │ O(1) but wastes   │ O(1) both, no waste       │
 │ Storage              │ fixed capacity    │ unbounded (heap nodes)    │
 │ Wasted space         │ front-end garbage │ none                      │
 │ Cache                │ contiguous → fast │ scattered nodes           │
 │ Reset                │ reset both idx=0  │ just move head/tail       │
 └──────────────────────┴───────────────────┴───────────────────────────┘
 */
#include <iostream>
using namespace std;

// naive array queue demo (front drifts forward)
struct NaiveQueue {
    int cap;
    int* arr;
    int front, rear;        // front = pehla, rear = agla khali slot
    NaiveQueue(int c) : cap(c), front(0), rear(0) { arr = new int[cap]; }
    ~NaiveQueue() { delete[] arr; }
    bool isEmpty() { return front == rear; }
    void enqueue(int v) {
        if (rear == cap) { cout << "overflow (rear==cap)" << endl; return; }
        arr[rear++] = v;
    }
    int dequeue() {
        if (isEmpty()) { cout << "underflow: empty queue" << endl; return -1; }
        return arr[front++];
    }
    int peek() { return isEmpty() ? -1 : arr[front]; }
    int size() { return rear - front; }
};

int main() {
cout << "===== demo: enqueue 10,20,30 then dequeue =====" << endl;
    NaiveQueue q(8);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "queue size = " << q.size() << " ; front = " << q.peek() << endl;   // 3, 10
    int d1 = q.dequeue();
    int s1 = q.size();
    int f1 = q.peek();
    cout << "dequeue() -> " << d1 << " ; size = " << s1
         << " ; front now = " << f1 << endl;                              // 10, 2, 20
    int d2 = q.dequeue();
    int d3 = q.dequeue();
    cout << "dequeue() -> " << d2 << endl;                             // 20
    cout << "dequeue() -> " << d3 << endl;                             // 30
    cout << "isEmpty() -> " << (q.isEmpty() ? "true" : "false") << endl;        // true
    int d4 = q.dequeue();
    cout << "dequeue() on empty -> " << d4 << endl;                    // underflow
    return 0;
}
