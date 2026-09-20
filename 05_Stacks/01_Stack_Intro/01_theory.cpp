/*
═══════════════════════════════════════════════
 STACK INTRO — LIFO concept, operations, overflow/underflow, real-world uses
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A stack of dinner plates in a canteen. The LAST plate you place on the pile
 is the FIRST one you take off — you never pull from the middle, never from
 the bottom. Same with a Pringles can (last chip out first), an undo button
 (the most recent action gets undone first), and recursion (the innermost
 function call finishes before its caller). This "Last In, First Out" rule is
 called LIFO, and the data structure that enforces it is the STACK.

 📖 THEORY: (pure English, beginner-level)
 - STACK = an ordered collection open at exactly ONE end: the TOP.
 - LIFO: the element pushed LAST is always popped FIRST.
 - CORE OPERATIONS:
     * push(x)  — put x on top.
     * pop()    — remove & return the TOP element.
     * peek()/top() — view the top WITHOUT removing it.
     * isEmpty() — true if no elements.
     * size()    — current element count.
 - TOP PERSPECTIVE: the stack has no idea what is below the top until those
   elements are popped, one by one — exactly like plates.
 - OVERFLOW: stack implementation has a FIXED capacity (array-based) and you
   try push() when it is full → push fails. (Modern dynamic arrays rarely hit
   it, but the concept comes from bounded memory.)
 - UNDERFLOW: you try pop()/peek() on an EMPTY stack → invalid operation,
   usually a crash or an exception. ALWAYS check isEmpty() first.
 - WHERE STACKS APPEAR NATURALLY:
     * Undo/Redo systems (most recent action first).
     * Expression evaluation (postfix/infix), function call stack.
     * Backtracking (maze, N-Queens, DFS on graphs).
     * Browser back-button, recursion, bracket matching.

  ASCII — the plate stack / LIFO structure:
       push 30          push 40        push 50 effect...
       ┌───┐            ┌───┐
    ┌  │30 │        ┌  │40 │            ruko, pehle LIFO demo:
    └──┴───┘         29 │30 │
      (top=30)         └──┴───┘

  Actually, a cleaner picture:
        TOP
         │
         ▼
      ┌─────┐
      │  50 │  ← last pushed, popped FIRST
      │  40 │
      │  30 │
      │  20 │
      │  10 │  ← first pushed, popped LAST
      └─────┘
         BOTTOM

  SCENARIO — undo stack:
   typed:  "H" → "He" → "Hel" → "Hell" → "Hello"
   undo 1: "Hell" ; undo 2: "Hel"         (most recent edits revert first)

  WHEN TO USE A STACK:
  - Problem needs the MOST RECENT item first (reverse-style / nesting logic).
  - Symmetric pairing (brackets, parentheses, HTML tags).
  - State you must back out of in LIFO order (backtracking, DFS).
  - Do NOT use when you need FIFO order or random access by index.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Identify the operations as push/pop/top/isEmpty.
        WHY: those five ARE the interface; everything a stack does is a
        composition of them.
 Step 2: On push, place at the TOP and update top pointer/index.
        WHY: "top" is the only entry/exit; new data always replaces the
        visible head of the structure.
 Step 3: On pop, read top, remove it, move top to the next element.
        WHY: removing from the top preserves LIFO — the rest of the stack is
        untouched and stays in the same relative order.
 Step 4: Guard pop/peek with isEmpty check.
        WHY: popping an empty stack is underflow — reading a non-existent
        top crashes; the guard turns it into a safe no-op/error.
 Step 5: Guard push with capacity check on a FIXED-size array stack.
        WHY: writing past the array end is overflow and corrupts memory;
        checking size < capacity first keeps the structure in-bounds.

 VISUAL WALKTHROUGH: push 10, 20, 30 ; pop ; peek
   push 10: [10]
   push 20: [10, 20]
   push 30: [10, 20, 30]      top = 30
   pop():   returns 30 → [10, 20]
   peek():  returns 20, stack still [10, 20]
   pop():   returns 20 → [10]
   pop():   returns 10 → []
   pop():   UNDERFLOW guard → error message (empty)

 DRY RUN: (demo below, exact prints)
   push 10, push 20, push 30
   size() = 3 ; top() = 30
   pop() → 30 ; pop() → 20 ; peek() → 10
   pop() → 10 ; isEmpty() → true
   demo2 (array capacity 3): after 3 pushes, push 40 tries → "overflow"
   pop on empty after all popped → "underflow"

 TIME COMPLEXITY CALCULATION:
 - push: write at one index + increment top → constant instructions → O(1).
 - pop: read top, decrement → O(1).
 - peek/top: single array/pointer read → O(1).
 - isEmpty/size: constant comparisons → O(1).
 → Every core stack operation is O(1). Amortized resize (dynamic array):
   occasional O(n) copy, but averaged over n pushes still O(1) amortized.

 SPACE COMPLEXITY CALCULATION:
 - Storing the elements themselves: array of capacity c → O(c); or linked
   list of n nodes → O(n).
 - The top index/pointer + size counter: constant extra → O(1) auxiliary.
 → Space = O(n) for the data, O(1) auxiliary.

 APPROACH COMPARISON:
 ┌────────────────────┬────────────────────┬────────────────────────────────┐
 │ Aspect             │ Array-based stack  │ Linked-list-based stack        │
 ├────────────────────┼────────────────────┼────────────────────────────────┤
 │ Capacity           │ fixed (or resizing)│ unlimited (heap nodes)         │
 │ Overflow risk      │ yes, when full     │ no (until memory exhausts)     │
 │ Cache friendliness │ better (contiguous)│ worse (scattered nodes)        │
 │ Extra pointers     │ none               │ 1 pointer per node             │
 │ Predictable O(1)   │ yes                │ yes (all core ops O(1))        │
 └────────────────────┴────────────────────┴────────────────────────────────┘
 */
#include <iostream>
using namespace std;

// simple fixed-capacity array stack for the demo
struct ArrayStack {
    int* arr;
    int cap;
    int top;                        // top = kitne elements hain

    ArrayStack(int c) : cap(c), top(0) {
        arr = new int[cap];
    }
    ~ArrayStack() { delete[] arr; }

    void push(int v) {
        if (top == cap) {           // overflow guard
            cout << "overflow: " << v << " can't fit (top==cap)" << endl;
            return;
        }
        arr[top] = v;
        top++;
    }
    int pop() {
        if (top == 0) {             // underflow guard
            cout << "underflow: nothing to pop" << endl;
            return -1;
        }
        top--;
        return arr[top];
    }
    int peek() {
        if (top == 0) {
            cout << "underflow: nothing to peek" << endl;
            return -1;
        }
        return arr[top - 1];
    }
    bool isEmpty() { return top == 0; }
    int size() { return top; }
};

int main() {
    cout << "===== demo 1: push 10,20,30 then pop/peek =====" << endl;
    ArrayStack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "size() = " << s.size() << endl;      // 3
    cout << "top() = " << s.peek() << endl;       // 30
    cout << "pop() -> " << s.pop() << endl;       // 30
    cout << "pop() -> " << s.pop() << endl;       // 20
    cout << "peek() = " << s.peek() << endl;      // 10
    cout << "pop() -> " << s.pop() << endl;       // 10
    cout << "isEmpty() -> " << (s.isEmpty() ? "true" : "false") << endl; // true

    cout << endl << "===== demo 2: capacity 3, overflow + underflow =====" << endl;
    ArrayStack t(3);
    t.push(5);
    t.push(6);
    t.push(7);
    t.push(40);                               // overflow
    cout << "size after overflow attempt = " << t.size() << endl;   // 3
    cout << "pop() -> " << t.pop() << endl;   // 7
    cout << "pop() -> " << t.pop() << endl;   // 6
    cout << "pop() -> " << t.pop() << endl;   // 5
    cout << "pop() -> " << t.pop() << endl;   // underflow
    return 0;
}
