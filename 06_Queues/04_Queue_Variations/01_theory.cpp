/*
═══════════════════════════════════════════════
 QUEUE VARIATIONS — deque (double-ended), priority queue, STL containers
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A hospital's ER has the usual queue… but three tweaks are needed.
 1) The registration desk sometimes lets a walk-in who already has a ticket
 jump to the FRONT (front insert). A normal queue forbids that; a DOUBLE-ENDED
 QUEUE (deque) allows insert/remove from BOTH ends.
 2) A separate VIP entrance does not care who arrived first — it serves the
 MOST SEVERE patient first, no matter when they came. That is a PRIORITY
 QUEUE: it always hands out the biggest (or most urgent) item.
 3) Production code rarely hand-builds these — the C++ STL ships ready-made
 queue, deque and priority_queue templates; you just pick the right one.

 📖 THEORY: (pure English)
 - DEQUE (double-ended queue): open at BOTH ends for inserts AND removals.
   Operations: push_front/push_back/pop_front/pop_back, plus front/back.
   Classic impl = circular array (like the ring buffer) tracking `front` and
   `back`; both ends wrap modulo capacity. Doubling resize O(n) amortized
   O(1). Also implementable as a doubly linked list.
 - CIRCULAR DEQUE (array): same as circular queue but with push_front &
   pop_back too: `front = (front-1+cap)%cap` to push front; `back =
   (back-1+cap)%cap` to pop back. Same full/empty invariants as before:
   empty ⇔ front==back; full ⇔ (back+1)%cap==front (one slot reserved).
 - PRIORITY QUEUE: removes not the oldest but the LARGEST (max-heap) — or
   smallest (min-heap). Implemented with a binary heap (implicit in array):
     * push: append, then "bubble up" (heapify) while parent < child. O(log n).
     * pop (top): swap root with last, shrink, "bubble down" while child
       larger. O(log n).
     * top: root element, O(1).
   WHY O(log n): a binary heap with n nodes has height log2(n); each push or
   pop moves ONE element along ONE root-leaf path — at most h = O(log n) swaps.
   Approaches without a heap:
     * unsorted array: push O(1) but pop must SCAN for max → O(n); top O(n).
     * sorted array: top/pop O(1) (last element), but push inserts sorted →
       O(n) shift.
     → the heap nails both ends at O(log n).
 - STL:
     * std::queue<T> — FIFO adapter: front/back read, pop removes front.
     * std::deque<T> — double-ended, O(1) amortized at both ends.
     * std::priority_queue<T> — max-heap by default; to get a min-heap use
       priority_queue<int, vector<int>, greater<int>>.

  ASCII — deque both ends:
        push_front 5 → becomes head
        push_back 40 → becomes tail
      FRONT                       BACK
        │                           │
        ▼                           ▼
      [ 5 ][10][20][30][ 40 ]   (both can grow/shrink)

  ASCII — priority queue (max-heap implicit in array):
        heap array: [50, 30, 20, 10, 5]        root = 50 = max
                    index     0    1   2   3  4
                                  ┌────50───┐
                                  │    │    │
                               30  │   20
                                │ │
                              10 5
        push 60 → bubble up: 60 sits at leaf, swaps with 30 then 50 → root 60
        pop()   → take 50; leaf 5 to root; bubble down → next max on top

 🧠 LOGIC — STEP BY STEP (circular deque):
 Step 1: Extend the circular queue with front-modulo and back-modulo moves.
        WHY: front-1 mod cap opens the left side; back-1 mod cap opens the
        right side; modulo keeps everything inside the ring.
 Step 2: push_front: check full; back up front: front=(front-1+cap)%cap, write.
        WHY: the cell just left of front is free (unless full); moving front
        backwards logically inserts at the front end.
 Step 3: pop_back: check empty; step back: back=(back-1+cap)%cap  read.
        WHY: the cell just left of back is the rear element; stepping back
        removes it without shifting.

 🧠 LOGIC — STEP BY STEP (priority queue / heap):
 Step 1: Store the heap in an array; node i → children 2i+1 and 2i+2.
        WHY: the complete-tree shape makes pointers unnecessary; index math
        locates parent/children in O(1).
 Step 2: push = write at end, then bubble up.
        WHY: the heap property (parent ≥ children) may break after append;
        bubbling the new key upward restores it along a single path.
 Step 3: pop = save root, move last leaf to root, shrink, bubble down.
        WHY: the root is the max; replacing it with the last leaf keeps the
        tree complete, and bubbling down re-establishes the heap property.
 Step 4: both pushes/pops cost ≤ height = O(log n).
        WHY: each fix-up walks one root↔leaf path; height of an n-node
        complete binary tree is log2(n).

 VISUAL WALKTHROUGH: deque push_front/back sequence (cap 5), then PQ push/pop
   deque:
     push_back 10   → [10]
     push_back 20   → [10,20]
     push_front 5   → [5,10,20]
     pop_back()     → 20 → [5,10]
     push_front 1   → [1,5,10]
     pop_front()    → 1  → [5,10]
   priority_queue:
     push 3,10,5 → root=10 ; pop → 5 next ; push 8 → root=8 ; pop →5

 DRY RUN: (demo below, exact prints)
   DEQUE:
     push_back 10, 20, 30
     push_front 5  → front 5, back 30
     pop_front → 5 ; front now 10
     push_back 40 → back 40
     pop_back  → 40 ; back now 30
   PRIORITY QUEUE (min-heap via greater<int>):
     push 5,1,3 → top (smallest) = 1
     pop → 1 ; top now 3
     push 0 → top 0
   STL:
     queue<int> q:  push 10,20 → front 10 back 20 ; pop → front 20
     priority_queue<int> pq: push 3,10,5 → top 10 ; pop → top 5
 TIME COMPLEXITY CALCULATION:
 - Deque (circular array): push/pop each end = 1 write + 1 modulo → O(1);
   resize = copy n once per doubling → amortized O(1) per op.
   Linked-list deque: O(1) both ends too (4 pointers rewired).
 - Priority queue via heap: push does ≤ log2(n) swaps, pop likewise →
   O(log n) each; top = root → O(1).
 - PQ via unsorted array: push O(1), pop scans n → O(n).
   PQ via sorted array: top/pop O(1), push shifts up to n → O(n).
   → always prefer the heap for balanced O(log n) push+pop.
 - STL: stack adapters delegate to their underlying containers → same
   asymptotic bounds as above (deque O(1) ends; priority_queue O(log n)).

 SPACE COMPLEXITY CALCULATION:
 - Deque circular array: cap slots → O(cap); linked version O(n) nodes.
 - Heap implicit in array: O(n) for n elements; auxiliary O(1).
 - PQ unsorted/sorted arrays: O(n); sorted-shift costs no extra array.
   → all O(n) for storage with O(1) auxiliary.

 APPROACH COMPARISON (priority queue):
 ┌──────────────────────┬──────────┬──────────┬─────────────────────────┐
 │ Implementation       │ push     │ pop(top) │ notes                   │
 ├──────────────────────┼──────────┼──────────┼─────────────────────────┤
 │ unsorted array       │ O(1)     │ O(n)     │ scan for max            │
 │ sorted array (desc)  │ O(n)     │ O(1)     │ shift for insert        │
 │ binary heap          │ O(log n) │ O(log n) │ balanced, chosen        │
 │ STL priority_queue   │ O(log n) │ O(log n) │ max-heap by default     │
 └──────────────────────┴──────────┴──────────┴─────────────────────────┘
 */
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

// ---- circular deque demo (array, both ends wrap) ----
struct CircularDeque {
    int cap; int* a; int f, b;      // b = back (one past last) like queue
    CircularDeque(int c) : cap(c), f(0), b(0) { a = new int[cap]; }
    ~CircularDeque() { delete[] a; }
    bool empty() { return f == b; }
    bool full()  { return (b + 1) % cap == f; }
    void push_back(int v)  { if (full()) return; a[b] = v; b = (b + 1) % cap; }
    void push_front(int v) { if (full()) return; f = (f - 1 + cap) % cap; a[f] = v; }
    int pop_front() { if (empty()) return -1; int v = a[f]; f = (f + 1) % cap; return v; }
    int pop_back()  { if (empty()) return -1; b = (b - 1 + cap) % cap; return a[b]; }
    int front() { return empty() ? -1 : a[f]; }
    int back()  { return empty() ? -1 : a[(b - 1 + cap) % cap]; }
    void dump() {
        cout << "  deque now:";
        for (int i = f; i != b; i = (i + 1) % cap) cout << " " << a[i];
        cout << "  (front=" << front() << " back=" << back() << ")" << endl;
    }
};

int main() {
    cout << "===== CIRCULAR DEQUE =====" << endl;
    CircularDeque d(6);
    d.push_back(10); d.push_back(20); d.push_back(30);
    d.dump();                                            // 10 20 30 front10 back30
    d.push_front(5);
    d.dump();                                            // 5 10 20 30 front5
    int x = d.pop_front();
    cout << "pop_front -> " << x << endl; d.dump();      // 10 20 30
    d.push_back(40);
    d.dump();                                            // 10 20 30 40
    int y = d.pop_back();
    cout << "pop_back  -> " << y << endl; d.dump();      // 10 20 30

    cout << "===== PRIORITY QUEUE (min-heap) =====" << endl;
    priority_queue<int, vector<int>, greater<int>> pq;   // chhota sabse upar
    pq.push(5); pq.push(1); pq.push(3);
    cout << "top = " << pq.top() << endl;                // 1
    pq.pop();
    cout << "after pop, top = " << pq.top() << endl;     // 3
    pq.push(0);
    cout << "after push 0, top = " << pq.top() << endl;  // 0

    cout << "===== STL queue & max priority_queue =====" << endl;
    queue<int> q;
    q.push(10); q.push(20);
    cout << "queue: front=" << q.front() << " back=" << q.back() << endl;  // 10, 20
    q.pop();
    cout << "after pop: front=" << q.front() << endl;                     // 20

    priority_queue<int> mpq;
    mpq.push(3); mpq.push(10); mpq.push(5);
    cout << "max-pq top = " << mpq.top() << endl;         // 10
    mpq.pop();
    cout << "after pop, top = " << mpq.top() << endl;     // 5
    return 0;
}
