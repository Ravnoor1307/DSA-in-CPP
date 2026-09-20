/*
═══════════════════════════════════════════════
 STACK CLASS — custom class design + STL std::stack usage
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A junior gets two tasks. Task A: wrap a raw array+top into a clean class so
 callers just say `s.push(5)` / `s.pop()` — no exposed `top` variable to
 corrupt. Task B: a senior says "stop hand-rolling, use std::stack from the
 STL" because it is already correct, tested, and template-based. THIS
 section shows how the custom class looks internally (encapsulation, error
 handling, dynamic growth) and how the STL version behaves identically in
 usage — so you understand both the machinery and the ready-made tool.

 📖 THEORY: (pure English)
 - CUSTOM STACK CLASS = encapsulation of data (array/linked nodes) + methods.
   * private: buffer pointer, capacity, top counter.
   * public : push, pop, top, empty, size.
   * Why encapsulate? Callers can't read/write `top` directly, so they can't
     break LIFO invariants; the class guards overflow/underflow in one place.
   * Dynamic version: push grows the buffer when full (double + copy), so a
     custom class can behave 'unbounded' like the STL.
 - STD::STACK: <stack>, a container ADAPTER built on top of another container.
   * By default it wraps std::deque; the deque's O(1) push/pop at both ends
     makes it a natural backing store. Can also wrap std::vector or
     std::list via template param: std::stack<int, std::vector<int>>.
   * Member functions: push, pop, top, empty, size. NO direct iteration.
   * Since it is an adapter, the underlying container's complexity applies:
     push/pop/top/empty/size are all O(1).
   * C++17 note: pop() returns void (use top() first, then pop()).

  ASCII — custom vs STL side by side:
   custom:                   STL:
   Stack s;                  stack<int> st;   (wraps deque)
   s.push(5);                st.push(5);
   s.push(9);                st.push(9);
   s.top()   → 9             st.top()    → 9
   s.pop()   → removes top   st.pop()    → removes top
   s.empty()                 st.empty()

  ASCII — how std::stack adapts a deque:
       your code                    std::stack (adapter)
       st.push(x)  ─────────────→   dq.push_back(x)      (back = TOP)
       st.top()    ─────────────→   dq.back()
       st.pop()    ─────────────→   dq.pop_back()

 🧠 LOGIC — STEP BY STEP (custom class):
 Step 1: Store `buffer`, `capacity`, `top` privately.
        WHY: private fields force every mutation through the public API,
        preserving LIFO invariants no matter what the caller does.
 Step 2: push checks `top == capacity`; if full → grow, else write.
        WHY: without the guard, a full buffer overflows the array; growth
        (double + memcopy) keeps the class behaving unbounded like STL.
 Step 3: pop returns the value then decrements; guard `top == 0`.
        WHY: popping empty is underflow; the guard returns a safe sentinel
        (or throws) instead of reading garbage.
 Step 4: top() returns `buffer[top-1]` without changing `top`.
        WHY: peeking must NOT remove — else a single peek wrecks the stack.
 Step 5: destructor deletes the buffer (or nodes) to avoid leaks.
        WHY: the class owns heap memory; the dtor is the only guaranteed
        cleanup point, called automatically at scope end.

 🧠 LOGIC — STEP BY STEP (STL usage):
 Step 1: Declare `std::stack<T> st;` (default deque backing).
 Step 2: push/pop/top/empty/size exactly like the custom API.
 Step 3: Remember pop() does NOT return the value in STL.
        WHY: strong exception safety — returning by value in a void function
        that can throw is not possible; you take top() first.
 Step 4: No iteration (no begin/end).
        WHY: a stack conceptually only exposes the top; a container adapter
        deliberately hides iteration to enforce LIFO thinking.

 VISUAL WALKTHROUGH: custom class growing from cap 2 to 3 elements
   cap=2, push A → [A ]
   push B      → [A,B]
   push C      → FULL → grow: new[4], copy → [A,B,C,_ ]; cap=4
   top() → C ; pop() → C ; [A,B]

 DRY RUN: (demo below, exact prints)
   CUSTOM CLASS:
     start cap 2 → push 10, push 20 → top=2/20
     push 30 (grows to cap 4) → top=3, top element 30
     pop → 30 ; top now 20 ; pop → 20 ; size 1, empty? false
     pop → 10 ; empty? true ; pop on empty → sentinel -1
   STL STACK:
     push 1,2,3 → size 3, top 3
     pop → 3 ; top now 2 ; size 2
     copy the stack (st2 = st) → top 2
     print st2 size = 2
 TIME COMPLEXITY CALCULATION:
 - Custom push: 1 write + counter ++; on growth, copy all n → O(1) amortized
   (doubling makes every element copied O(1) times on average).
 - Custom pop/top/empty/size: constant work each → O(1).
 - STL: delegates to deque/vector; push_back/pop_back on those are O(1)
   amortized; top() is container.back() O(1); size O(1) (deque keeps count).
   → ALL operations O(1) amortized time.
 SPACE COMPLEXITY CALCULATION:
 - Custom: array capacity c → O(c); growth powers-of-two → O(n) storage, and
   resize temporarily needs 2 buffers → O(n) peak transient.
 - STL: deque stores n elements in chunked blocks → O(n) with the chunk
   overhead (typically a few pointers per chunk).
 - Stack of n items always needs Omega(n) space to hold the data; both are
   O(n) with small constants; auxiliary (non-data) space O(1).

 APPROACH COMPARISON:
 ┌────────────────────┬──────────────────┬─────────────────────────────┐
 │ Aspect             │ Custom class     │ std::stack (STL)            │
 ├────────────────────┼──────────────────┼─────────────────────────────┤
 │ Effort             │ write + test all │ include <stack>, done       │
 │ Correctness        │ your burden      │ battle-tested library       │
 │ Backing store      │ array or list    │ deque/vector/list (adapter) │
 │ pop() return value │ we return value  │ returns void (top() first)  │
 │ Type safety        │ int only (or T*) │ template: any type          │
 │ Learning value     │ HIGH             │ LOW (but practical)         │
 └────────────────────┴──────────────────┴─────────────────────────────┘
 */
#include <iostream>
#include <stack>
using namespace std;

// ---- custom dynamic stack class (grows like STL) ----
class MyStack {
private:
    int* buf;
    int cap;
    int top;                 // elements count
    void grow() {
        int ncap = cap * 2;
        int* nb = new int[ncap];
        for (int i = 0; i < cap; i++) nb[i] = buf[i];   // old copy
        delete[] buf;
        buf = nb;
        cap = ncap;
    }
public:
    MyStack() : cap(2), top(0) { buf = new int[cap]; }
    ~MyStack() { delete[] buf; }
    void push(int v) {
        if (top == cap) grow();        // full → double
        buf[top++] = v;
    }
    int pop() {
        if (top == 0) return -1;       // underflow guard
        return buf[--top];
    }
    int topOf() const { return (top == 0) ? -1 : buf[top - 1]; }
    int size() const { return top; }
    bool empty() const { return top == 0; }
};

int main() {
    cout << "===== CUSTOM CLASS =====" << endl;
    MyStack s;
    s.push(10); s.push(20);
    cout << "top = " << s.topOf() << " size = " << s.size() << endl;      // 20, 2
    s.push(30);                                                          // grows 2→4
    cout << "after push 30 (grow), size = " << s.size()
         << " top = " << s.topOf() << endl;                              // 3, 30
    int p1 = s.pop(), p2 = s.pop(), p3 = s.pop(), p4 = s.pop();
    cout << "pop " << p1 << ", " << p2 << ", " << p3
         << " ; pop empty = " << p4 << endl;                             // 30 20 10 -1

    cout << "===== STL STACK =====" << endl;
    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    cout << "size = " << st.size() << ", top = " << st.top() << endl;     // 3, 3
    int t1 = st.top(); st.pop();
    cout << "pop -> " << t1 << ", top now " << st.top()
         << ", size " << st.size() << endl;                               // 3, 2, 2
    stack<int> st2 = st;                                                 // copy constructor
    cout << "st2 (copy) top = " << st2.top() << ", size = " << st2.size() << endl; // 2, 2
    return 0;
}
