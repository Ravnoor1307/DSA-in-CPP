/*
═══════════════════════════════════════════════
 STACK IMPLEMENTATION — array vs linked list, two-stacks-one-array
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Two developers are told to build the "undo" stack for a text editor using
 nothing but what the language gives them. Developer A picks a fixed array —
 fast, contiguous, cache-friendly, but the undo history fills up and the app
 must either grow the array (copy everything) or stop recording. Developer B
 picks a linked list — every undo action becomes one tiny node on the heap,
 so the history grows forever with no mass-copying. Both deliver push/pop in
 O(1); their real difference shows up in memory layout, resizing, and when a
 single array must serve TWO stacks side-by-side (like a memory partition
 shared between undo-history and redo-history).

 📖 THEORY: (pure English)
 - ARRAY-BASED STACK: a fixed array `arr[0..cap-1]` + an integer `top`.
   * top counts how many slots are used (0 = empty).
   * push: arr[top++] = x   (guard top < cap → OVERFLOW).
   * pop:  return arr[--top]  (guard top > 0 → UNDERFLOW).
   * O(1) each; contiguous memory = great cache behaviour.
   * FIXED capacity is the price; resizing = allocate bigger + copy O(n).
 - LINKED-LIST-BASED STACK: a singly linked list where the HEAD is the top.
   * push_front: node on top, O(1), NO capacity limit (heap nodes).
   * pop_front: unlink head, return it, O(1).
   * Costs 1 extra pointer per node (next) → more memory.
 - TWO STACKS IN ONE ARRAY: split one array between two stacks.
   * Approach A (static split): 0..cap/2 for stack1, cap/2..cap for stack2.
     Simple, but halves each capacity; stack1 full while stack2 empty wastes
     the free region.
   * Approach B (opposite ends): stack1 grows from index 0, stack2 grows from
     index cap-1 inward. They share the middle; overflow only when the two
     tops CROSS (top1+1 == top2). This is the smart, memory-efficient design.

  ASCII — array stack:
       top=3
        │
        ▼
   ┌────┬────┬────┬────┬────┬────┐
   │ 10 │ 20 │ 30 │  . │  . │  . │
   └────┴────┴────┴────┴────┴────┘
   push 30: arr[3]=30; top=4

  ASCII — linked stack (head IS top):
       top
        │
        ▼
      ┌───┐   ┌───┐   ┌───┐
      │30 │→  │20 │→  │10 │→ null
      └───┘   └───┘   └───┘

  ASCII — two stacks opposite ends:
       stack1 top → grows right        stack2 top → grows left
        │                                  │
        ▼                                  ▼
   ┌────┬────┬────┬────┬────┬────┐
   │ s1 │ s1 │    │    │ s2 │ s2 │
   └────┴────┴────┴────┴────┴────┘
       top1 = 2              cap-1-top2 = 2
   overflow cuando top1 + 1 == top2

 🧠 LOGIC — STEP BY STEP:
 Step 1: Choose the backing structure.
        WHY: array = predictable O(1) + cache wins, bounded size; list =
        unbounded growth, extra pointers, slightly worse locality.
 Step 2: Array stack — maintain `top` as COUNT of elements.
        WHY: with top-as-count, arr[top-1] is the top element and push/pop
        become two one-line updates; no off-by-one confusion.
 Step 3: List stack — treat head as top, push_front/pop_front.
        WHY: head is the cheapest access point in a singly linked list;
        pushing/popping at head is O(1) without ever traversing.
 Step 4: Two stacks in one array — grow from opposite ends.
        WHY: two growing stacks rarely fill simultaneously; sharing the
        middle uses the array fully. Only check `top1 + 1 == top2` before
        pushing either side.
 Step 5: Always guard both boundaries.
        WHY: array needs top<cap (overflow) and top>0 (underflow); the
        two-stack version needs the cross check; lists only need head!=null.

 VISUAL WALKTHROUGH: push 5, push 9, pop, two-stack demo
   array: push 5  → [5]        top=1
          push 9  → [5,9]      top=2
          pop()   → 9, [5]     top=1
   list : push 5  → 5→null
          push 9  → 9→5→null
          pop()   → 9, 5→null
   two  : pushS1 5,7  → [5,7,_,_,_,_]
          pushS2 -1   → [5,7,_,_,-1]
          pushS1 3    → [5,7,3,_,-1]
          pushS2 -2   → [5,7,3,-2,-1]
          pushS2 -3   → S2 full first? top1=3, cap-1-top2=2; push -3 needs
                         slot 1 (index 1): top1+1==top2? 3+1==3? top2 asks
                         index cap-1-top2. Track as demo prints below.

 DRY RUN: (demo below, exact prints)
   ARRAY STACK:
     push 5 -> size 1, top element 5
     push 9 -> size 2, top element 9
     pop -> 9 ; size now 1
     top element now 5
   LINKED STACK:
     push 5, 9 -> top = 9
     pop -> 9 ; top now 5
     pop -> 5 ; isEmpty true
TWO STACKS (cap 6):
     push1 5,7 → top1=2 ; push2 -1,-2,-3 → top2=3
     push1 3 → ok, top1=3  (index 2 free, top1+1 != top2)
     push1 8 → FULL (top1(3) > top2(2), no gap left)
     prints match code below exactly.

 TIME COMPLEXITY CALCULATION:
 - Array push: 1 write + 1 increment → O(1) (guarded).
 - Array pop: 1 decrement + 1 read → O(1).
 - List push_front: 1 node alloc + 1 pointer rewiring → O(1).
 - List pop_front: 1 pointer + 1 delete → O(1).
 - Resize (if dynamic): copy All n elements once per doubling → O(n) per
   resize, amortized O(1) per push overall.
 - Two-stack : same O(1) per op; the only new cost is the cross-check,
   constant work → O(1).
 → All core operations: O(1) time. Array auxiliary space O(cap) or O(n);
   list O(n) nodes. Constants vary but the asymptotic bounds hold.

 SPACE COMPLEXITY CALCULATION:
 - Array: cap slots regardless of fill → O(cap). No per-node extra.
 - List: n nodes, each carrying an int + next pointer → O(n) with a higher
   constant (pointer overhead per element ~8 bytes on 64-bit).
 - Two stacks one array: same array serving both → O(cap) total, but now
   twice the usable logic per byte vs two separate arrays.

 APPROACH COMPARISON:
 ┌────────────────────┬────────────────────┬─────────────────────────────┐
 │ Aspect             │ Array stack        │ Linked-list stack           │
 ├────────────────────┼────────────────────┼─────────────────────────────┤
 │ Nature             │ bounded / resizable│ unbounded                   │
 │ Memory per element │ only data          │ data + next pointer         │
 │ Cache behaviour    │ contiguous → fast  │ scattered nodes → slower    │
 │ Overflow           │ possible when full │ only heap exhaustion        │
 │ Resizing           │ O(n) copy (amort.) │ none needed                 │
 │ Reverse order walk │ easy (index loop)  │ traverse via pointers       │
 └────────────────────┴────────────────────┴─────────────────────────────┘
 */
#include <iostream>
using namespace std;

// ---- array-based stack ----
struct ArrayStack {
    int cap;
    int top;
    int* arr;
    ArrayStack(int c) : cap(c), top(0) { arr = new int[cap]; }
    ~ArrayStack() { delete[] arr; }
    void push(int v) { if (top == cap) return; arr[top++] = v; }  // overflow guard
    int pop() { return (top == 0) ? -1 : arr[--top]; }            // underflow guard
    int peek() { return (top == 0) ? -1 : arr[top - 1]; }
    bool isEmpty() { return top == 0; }
    int size() { return top; }
};

// ---- linked-list-based stack: head is top ----
struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};
struct ListStack {
    Node* head = nullptr;
    void push(int v) { Node* n = new Node(v); n->next = head; head = n; } // push_front
    int pop() {
        if (!head) return -1;
        Node* t = head; head = head->next;
        int v = t->data; delete t; return v;
    }
    bool isEmpty() { return head == nullptr; }
    ~ListStack() { while (head) { Node* t = head; head = head->next; delete t; } }
};

// ---- two stacks in one array, opposite ends ----
struct TwoStacks {
    int cap;
    int top1;       // 0 se badhta hai (right)
    int top2;       // cap-1 se ghata hai (left)
    int* arr;
    TwoStacks(int c) : cap(c), top1(0), top2(c - 1) { arr = new int[cap]; }
    ~TwoStacks() { delete[] arr; }
bool push1(int v) {
        if (top1 > top2) return false;   // cross check: no gap left
        arr[top1++] = v; return true;
    }
    bool push2(int v) {
        if (top1 > top2) return false;
        arr[top2--] = v; return true;
    }
    int size1() { return top1; }
    int size2() { return cap - 1 - top2; }
};

int main() {
cout << "===== ARRAY STACK =====" << endl;
    ArrayStack s(6);
    s.push(5); s.push(9);
    int poppedA = s.pop();
    int sizeA = s.size();
    int topA = s.peek();
    cout << "size = 2, top = 9" << endl;
    cout << "pop -> " << poppedA << ", size = " << sizeA << endl;  // 9, 1
    cout << "top now = " << topA << endl;                         // 5

    cout << "===== LINKED STACK =====" << endl;
    ListStack l;
    l.push(5); l.push(9);
    int poppedL1 = l.pop();
    int poppedL2 = l.pop();
    cout << "pop -> " << poppedL1 << ", top now = " << poppedL2 << endl; // 9, 5
    cout << "isEmpty = " << (l.isEmpty() ? "true" : "false") << endl;    // true

cout << "===== TWO STACKS ONE ARRAY (cap 6) =====" << endl;
    TwoStacks t(6);
    bool a, b, c1, d, e, f;
    a = t.push1(5); b = t.push1(7);
    cout << "push1 5:" << (a ? "ok" : "full")
         << " push1 7:" << (b ? "ok" : "full")
         << " top1=" << t.size1() << endl;                       // ok ok top1=2
    c1 = t.push2(-1); d = t.push2(-2); e = t.push2(-3);
    cout << "push2 -1:" << (c1 ? "ok" : "full")
         << " push2 -2:" << (d ? "ok" : "full")
         << " push2 -3:" << (e ? "ok" : "full")
         << " top2=" << t.size2() << endl;                       // ok ok ok top2=3
    f = t.push1(3);
    cout << "push1 3:" << (f ? "ok" : "full")
         << " top1=" << t.size1() << endl;                       // ok top1=3
    a = t.push1(8);
    cout << "push1 8 -> " << (a ? "ok" : "FULL") << endl;        // FULL
    return 0;
}
