/*
═══════════════════════════════════════════════
 QUEUE IMPLEMENTATION — linked-list queue (enqueue at rear, dequeue at front)
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Two data-centres run the same task queue. Centre A pre-buys 50 slots of a
 fixed shelf (array) — but on a busy sale day the shelf overflows. Centre B
 instead writes each incoming task on one sticky-note and clips it to a
 growing paper chain (linked list) — the chain simply grows, no fixed
 capacity. The worker always takes the sticky-note at the FRONT and always
 clips new notes at the BACK. Centre B never "overflows", needs no resize,
 and pays O(1) per join ("enqueue") and O(1) per hand-off ("dequeue"). That
 is the linked-list queue: FIFO with head=front, tail=rear.

 📖 THEORY: (pure English)
 - LINKED-LIST QUEUE = a singly linked list where:
   * HEAD node is the FRONT of the queue (dequeue happens here).
   * TAIL node is the REAR of the queue (enqueue happens here).
   * Removed node is the old head; added node becomes the new tail.
 - enqueue(v): create node; if empty queue → head=tail=new; else
   tail->next = new ; tail = new.  O(1).
 - dequeue(): if empty error; save head node; head = head->next; if head
   became null → tail = null too (queue now empty); delete old head. O(1).
 - WHY tail pointer matters: brute-force enqueue without a tail would walk
   from head to the last node every time → O(n) per enqueue. Keeping tail
   makes enqueue O(1).
 - NO FIXED CAPACITY: nodes come from the heap on demand; growth is
   unbounded until the machine runs out of memory — unlike the array queue.
 - vs ARRAY:
   * array = cache-friendly, needs capacity/wrapping, wasting ≤ 1 slot.
   * list = flexible growth, costs 1 extra pointer per element, scattered
     allocations → worse cache locality.
   * Both give O(1) enqueue/dequeue asymptotically.

  ASCII — linked queue after enqueue 10, 20, 30:
        (front)                        (rear)
        head                           tail
         │                              │
         ▼                              ▼
      ┌────┐      ┌────┐            ┌────┐
      │ 10 │ ──▶  │ 20 │ ──▶  ..... │ 30 │  ──▶ null
      └────┘      └────┘            └────┘
   dequeue → head = head->next → front moves to 20
   enqueue 40 → tail->next = node(40); tail = node(40) → back of line

  ASCII — queue in action (people line):
        service ← head [A] → [B] → [C] → tail ← new joiners
     dequeue: A leaves → [B] → [C]
     enqueue D: [B] → [C] → [D]

 🧠 LOGIC — STEP BY STEP:
 Step 1: Keep BOTH head (front) and tail (rear) pointers in the queue.
        WHY: dequeue touches head, enqueue touches tail; holding both means
        each operation is O(1) without ever scanning the list.
 Step 2: Enqueue always mutates TAIL: tail->next = node; tail = node.
        WHY: FIFO says newcomers go to the back; the tail IS the back, so
        enqueue growth is a pure append.
 Step 3: Dequeue always mutates HEAD: head = head->next.
        WHY: FIFO says the longest-waiting element (front) leaves first;
        the front IS head.
 Step 4: On the dequeue that empties the queue, ALSO reset tail = null.
        WHY: if head becomes null the queue is empty; leaving a dangling
        tail pointing at a deleted node causes a later enqueue to write
        through a freed pointer (crash/UB).
 Step 5: Guard dequeue/front when head==null (empty queue).
        WHY: dequeue-from-empty is underflow; give a safe error instead of
        dereferencing null.

 VISUAL WALKTHROUGH: enq 5, 9 → deq 5 → enq 15 → deq 9
   enq5:  head=5, tail=5
   enq9:  5→9        head=5,tail=9
   deq:   pop 5      head=9,tail=9     (single node still)
   enq15: 9→15       head=9,tail=15
   deq:   pop 9      head=15,tail=15
   deq:   pop 15     head=null,tail=null (empty)

 DRY RUN: (demo below, exact prints)
   build: enqueue 10, 20, 30
   front = 10 ; size = 3
   dequeue -> 10 ; front now 20 ; size 2
   enqueue 40 → front 20, rear 40
   dequeue 20, dequeue 30, dequeue 40 → empty
   dequeue on empty → "underflow: empty queue"
 TIME COMPLEXITY CALCULATION:
 - enqueue: node alloc O(1) + pointer rewiring via tail O(1) → O(1).
 - dequeue: pointer move head=head->next + delete old O(1) → O(1).
 - front/empty: single pointer checks → O(1).
 - An enqueue would be O(n) WITHOUT the tail because finding the last node
   requires a full walk; the tail pointer is what keeps it O(1).
   → All core operations O(1).

 SPACE COMPLEXITY CALCULATION:
 - Each live element = one node (int + 1 pointer) → O(n) storage.
 - Auxiliary: head + tail pointers, size counter → O(1) extra.
 - NO unused slots (unlike array) — but pointer overhead per node ~ +8 bytes
   on 64-bit relative to array storage.

 APPROACH COMPARISON:
 ┌──────────────────────┬───────────────────┬────────────────────────────┐
 │ Aspect               │ Array queue (circ)│ Linked-list queue          │
 ├──────────────────────┼───────────────────┼────────────────────────────┤
 │ Capacity             │ fixed cap (or dyn)│ unbounded (heap nodes)     │
 │ enqueue/dequeue      │ O(1)              │ O(1) (needs tail ptr)      │
 │ Cache locality       │ contiguous → good │ scattered → poor           │
 │ Memory per element   │ int only (+waste) │ int + next pointer         │
 │ Wasted space         │ ≤ 1 slot          │ none                       │
 │ Fragility            │ wrap arith        │ dangling tail if mishandled│
 └──────────────────────┴───────────────────┴────────────────────────────┘
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// linked-list queue: head = front, tail = rear
struct LLQueue {
    Node* head = nullptr;
    Node* tail = nullptr;
    int sz = 0;

    void enqueue(int v) {
        Node* n = new Node(v);
        if (!tail) { head = tail = n; }   // pehla node
        else { tail->next = n; tail = n; }// app at back
        sz++;
    }
    int dequeue() {
        if (!head) { cout << "underflow: empty queue" << endl; return -1; }
        Node* old = head;
        head = head->next;
        if (!head) tail = nullptr;        // empty ho gaya → tail reset
        int v = old->data;
        delete old;
        sz--;
        return v;
    }
    int front() { return head ? head->data : -1; }
    int size() { return sz; }
    bool empty() { return head == nullptr; }

    ~LLQueue() {
        while (head) { Node* t = head; head = head->next; delete t; }
    }
};

int main() {
    cout << "===== build: enqueue 10,20,30 =====" << endl;
    LLQueue q;
    q.enqueue(10); q.enqueue(20); q.enqueue(30);
    cout << "front = " << q.front() << " ; size = " << q.size() << endl;        // 10, 3
    int d = q.dequeue();
    cout << "dequeue -> " << d << " ; front now " << q.front()
         << " ; size " << q.size() << endl;                                     // 10, 20, 2
    q.enqueue(40);
    cout << "after enqueue 40 -> front " << q.front()
         << " , rear " << q.tail->data << endl;                                 // 20, 40
    int e1 = q.dequeue(), e2 = q.dequeue(), e3 = q.dequeue();
    cout << "dequeue " << e1 << ", " << e2 << ", " << e3
         << " -> empty = " << (q.empty() ? "true" : "false") << endl;           // 20,30,40 → true
    int u = q.dequeue();
    cout << "dequeue on empty -> " << u << endl;                                // underflow
    return 0;
}
