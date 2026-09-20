/*
═══════════════════════════════════════════════
 QUEUE IMPLEMENTATION — array: naive, wasted space, circular full conditions
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A billing counter has 8 printed tokens. The window worker uses tokens
 1,2,3,... and as people are served the used tokens are simply skipped over.
 Once all 8 tokens are handed out, the counter declares "tokens over" even
 though nobody is in the hall — because the worker forgot that the SAME 8
 tokens can be reused in a ring: after token 8 comes token 1 again. That is
 the "wasted space" problem of a naive array queue: front keeps moving
 forward and the cells behind it stay empty forever, while rear claims the
 array is full. The circular queue (ring buffer) is the fix — wrap around so
 the empty front cells get reused.

 📖 THEORY: (pure English)
 - NAIVE ARRAY QUEUE: `arr[0..cap-1]`, indices `front` (first live element)
   and `rear` (one past the last live element).
   * enqueue: arr[rear++] = x, guard rear<cap.
   * dequeue: return arr[front++], guard front<rear.
   * Both O(1), BUT front only grows: after n enqueues+dequeues front==rear
     ==cap → queue reports EMPTY yet is physically full → the first cap-1
     cells are dead space.
 - THE WASTED-SPACE PROBLEM:
   * After enough operations, unused cells at the FRONT can never be reused;
     enqueue fails (rear==cap) even though the array is half empty.
   * Fix idea = circular reuse: when rear reaches cap, wrap rear back to 0.
 - CIRCULAR QUEUE (ring buffer): indices `front` and `rear` that wrap with
   modulo: `(index+1) % cap`.
   * enqueue: arr[rear] = x; rear = (rear+1) % cap.
   * dequeue: v = arr[front]; front = (front+1) % cap.
   * empty when front == rear.
   * full when (rear+1) % cap == front — we SACRIFICE one slot so that
     front==rear unambiguously means EMPTY.
   * count = (rear - front + cap) % cap.
   * Thus every cell is reused; no wasted space; both ops stay O(1).
 - WHY THE +1 SLOT SACRIFICE: front==rear must mean "empty", the classic
   invariant. If we let rear wrap to front we'd LOSE the empty distinction.
 - OTHER FULL-CHECK FORMULAS: (capacity approach) using a separate `size`
   counter: full when size==cap, empty when size==0, enqueue/dequeue update
   size. Both designs are equivalent; the size-counter one wastes no slot.

  ASCII — naive queue drift (cap 8):
        enq 1,2,3    deq 1,2    deq continues…
        ┌───┬───┬───┬───┬───┬───┬───┬───┐
        │ X │ X │ 3 │   │   │   │   │   │   X = wasted
        └───┴───┴───┴───┴───┴───┴───┴───┘
          f=2               rear=3 → rear==cap eventually = "full"

  ASCII — circular queue wraps:
        cap 5, enq 1,2,3,4 (front 0, rear 4)
   deq 1,2  → front 2 ;  enq 5,6  → rear goes 4→0→1
        ┌────┬────┬────┬────┬────┐
        │ 5  │ 6  │ 3  │ 4  │    │   ← wrap: rear wrapped to 1
        └────┴────┴────┴────┴────┘
                  front=2    rear=1  (mod 5)
   Now the array looks "full" from the old mental model but is NOT — the
   two X-cells got reused, that's the whole point of circularity.

  ASCII — full vs empty on circular:
        EMPTY:  front == rear        FULL: (rear+1)%cap == front
        front=2 ________________     rear=1, front=2, cap=5 → (1+1)%5==2
        rear =2                        (waste slot index 2 kept free)

 🧠 LOGIC — STEP BY STEP (circular):
 Step 1: Front and rear both move in a RING via modulo.
        WHY: modulo makes the array "infinite" on the inside; index space is
        no longer [0,cap) but a circle.
 Step 2: Enqueue writes at rear then advances rear modulo.
        WHY: rear is the next free slot; writing then wrapping keeps rear
        always pointing one cell ahead of the last valid data.
 Step 3: Guard FULL with `(rear+1) % cap == front`; refuse to push.
        WHY: if rear+1 == front the ring would collide with the front, and
        we reserve that one gap to keep `front==rear → empty` unambiguous.
 Step 4: Dequeue reads front then advances front modulo; empty check first.
        WHY: an empty dequeue is underflow — reading arr[front] when
        front==rear reads a cell that holds no live data.
 Step 5: count via `(rear - front + cap) % cap`.
        WHY: raw rear-front can be negative after a wrap; adding cap and
        modding reconstructs the true positive distance on the ring.

 VISUAL WALKTHROUGH — cap 5 ring: enq 1,2,3, deq 1, enq 4,5, probe full
   step          front rear  contents (slot notation)
   enq 1         0     1     [1 _ _ _ _]
   enq 2         0     2     [1 2 _ _ _]
   enq 3         0     3     [1 2 3 _ _]
   deq 1         1     3     [_ 2 3 _ _]
   enq 4         1     4     [_ 2 3 4 _]
   enq 5         1     0     [_ 2 3 4 5]   (rear wrapped to 0)
   try enq 6     full? (0+1)%5==1 → YES → overflow
   deq 2         2     0     [_ _ 3 4 5]
   deq 3         3     0     [_ _ _ 4 5]
   mod apply...  front 3, rear 0 → count = (0-3+5)%5 = 2 ✓

 DRY RUN: (demo below, exact prints)
   NAIVE:
     enqueue 10,20,30 → rear 3, front 0
     dequeue → 10 ; front 1 ; size 2
   WASTED SPACE:
     enq 1..5, deq all → front 5, rear 5
     enqueue 6 → "overflow (rear==cap)" despite empty slots 0..4
   CIRCULAR:
     enq 1,2,3,4 → front 0 rear 4
     deq 1,2 → front 2
     enq 5 → rear 0 (wrapped); enq 6 → rear 1
     count = (1-2+5)%5 = 4
     enq 7 → FULL (rear+1)%cap==front → "overflow: full"
     deq 3,4,5,6 → all good until empty
 TIME COMPLEXITY CALCULATION:
 - enqueue: 1 write + 1 modulo → O(1).
 - dequeue: 1 read + 1 modulo → O(1).
 - peak/front: 1 read → O(1).
 - empty/full/count: 1-2 arithmetic ops → O(1).
   → All O(1), for both naive and circular; the circular fixes the wasted
     space / premature-overflow flaw without costing asymptotic time.

 SPACE COMPLEXITY CALCULATION:
 - We keep one array of cap cells no matter how few are live → O(cap).
 - Extra indices (front, rear, maybe size) → O(1) auxiliary.
 - The circular queue reserves at most 1 dead slot → O(1) “waste”.

 APPROACH COMPARISON:
 ┌────────────────────┐─────────────────────┬──────────────────────────────┐
 │ Aspect             │ Naive array         │ Circular array               │
 ├────────────────────┼─────────────────────┼──────────────────────────────┤
 │ front/rear         │ both grow           │ wrap via modulo              │
 │ Wasted cells       │ grows forever       │ None (1 slot reserved)       │
 │ Full condition     │ rear==cap           │ (rear+1)%cap==front          │
 │ "Full but empty"   │ yes — the bug       │ No                           │
 │ count formula      │ rear-front          │ (rear-front+cap)%cap          │
 └────────────────────┴─────────────────────┴──────────────────────────────┘
 */
#include <iostream>
using namespace std;

// ---- naive array queue (drifts, wastes front cells) ----
struct NaiveQ {
int cap; int* a; int f, r;
    NaiveQ(int c) : cap(c), f(0), r(0) { a = new int[cap]; }
    ~NaiveQ() { delete[] a; }
    void enq(int v) { if (r == cap) { cout << "overflow (rear==cap)" << endl; return; } a[r++] = v; }
    int deq() { return (f == r) ? -1 : a[f++]; }
    int size() { return r - f; }
};

// ---- circular queue with the (rear+1)%cap full check ----
struct CircularQ {
    int cap; int* a; int f, r;
    CircularQ(int c) : cap(c), f(0), r(0) { a = new int[cap]; }
    ~CircularQ() { delete[] a; }
    bool full()  { return (r + 1) % cap == f; }
    bool empty() { return f == r; }
    void enq(int v) {
        if (full()) { cout << "overflow: full" << endl; return; }
        a[r] = v;
        r = (r + 1) % cap;
    }
    int deq() {
        if (empty()) { cout << "underflow: empty" << endl; return -1; }
        int v = a[f];
        f = (f + 1) % cap;
        return v;
    }
int count() { return (r - f + cap) % cap; }
    int front() { return empty() ? -1 : a[f]; }
};

int main() {
    cout << "===== NAIVE QUEUE =====" << endl;
    NaiveQ q(8);
    q.enq(10); q.enq(20); q.enq(30);
    int nq = q.deq();
    cout << "deq -> " << nq << " ; size=" << q.size() << endl;          // 10, 2

    cout << "===== WASTED SPACE: enq 1..5, deq all, then enq 6 =====" << endl;
    NaiveQ w(5);
    for (int i = 1; i <= 5; i++) w.enq(i);
    while (w.size() > 0) w.deq();
    w.enq(6);                                                     // r==cap → overflow msg
    cout << "empty-still-overflow: enq 6 rejected, size=" << w.size() << " but cells 0..4 free" << endl;

    cout << "===== CIRCULAR QUEUE (cap 5) =====" << endl;
    CircularQ c(5);
    c.enq(1); c.enq(2); c.enq(3); c.enq(4);
    cout << "after enq 1..4  count=" << c.count() << " front=" << c.front() << endl; // 4, 1
    int cd1 = c.deq(); int cd2 = c.deq();
    cout << "deq " << cd1 << " " << cd2 << " front now=" << c.front() << endl;       // 1, 2, 3
    c.enq(5); c.enq(6);
    cout << "after enq 5(wraps),6  count=" << c.count()
         << " front=" << c.front() << endl;                                          // 4, 3
    c.enq(7);                                                      // full → overflow msg
    cout << "deq rest: ";
    while (!c.empty()) cout << c.deq() << " ";                     // 3 4 5 6
    cout << endl;
    return 0;
}
