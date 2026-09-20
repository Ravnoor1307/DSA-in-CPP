/*
═══════════════════════════════════════════════
 STD::STACK — LIFO Container Adapter
 ⏱️ TIME COMPLEXITY:
   push: O(1)  — add to top
   pop:  O(1)  — remove from top
   top:  O(1)  — peek at top
   empty/size: O(1) — stored variable
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a stack of dinner plates in a cafeteria. You always
 place a new plate on the top and remove the top plate first.
 You cannot pull a plate from the middle or bottom without
 disturbing the ones above. This "last-in, first-out" (LIFO)
 pattern is exactly what std::stack models. It is used for
 undo history in text editors (last action undone first),
 browser back-button navigation (most recent page visited
 is the one you go back to), and function call stacks in
 the runtime (most recent call returns first).

 📖 THEORY: (pure English, beginner-level)
 - std::stack is a container ADAPTER in <stack>.
 - It wraps an underlying container (default: std::deque).
 - Only top element is accessible — no iteration, no [].
 - Supported operations: push, pop, top, empty, size.
 - emplace() constructs element in-place at top (avoids copy).
 - swap() exchanges contents with another stack.
 - You can specify underlying container:
   stack<int, vector<int>> s;  // uses vector
   stack<int, list<int>> s;    // uses list
 - Underlying container must support: push_back, pop_back,
   back, empty, size — all O(1).

 ASCII LIFO / STACK DIAGRAM:

    ┌─────────┐  ← top() here
    │   50    │  ← last pushed, first popped
    ├─────────┤
    │   40    │
    ├─────────┤
    │   30    │
    ├─────────┤
    │   20    │
    ├─────────┤
    │   10    │  ← bottom (pushed first, popped last)
    └─────────┘

    push(60) → adds to top
    pop()    → removes from top
    top()    → reads 60 (does NOT remove)

 ASCII BRACKET MATCHING CONCEPT:

    Input: { [ ( ) ] }

    Char   Action       Stack State
    ────   ──────       ───────────
    {      push '{'     { }
    [      push '['     { [ }
    (      push '('     { [ ( }
    )      matches '('  { [ }        ← pop!
    ]      matches '['  { }          ← pop!
    }      matches '{}' (empty)      ← pop!

    Stack empty at end → balanced!

 🧠 LOGIC — STEP BY STEP:
 Step 1: Push values onto the stack.
   WHY: push() adds to top — O(1). The underlying deque
   push_back is O(1).
 Step 2: Peek top without removing.
   WHY: top() returns reference to top element — O(1).
   Useful when you need to check before popping.
 Step 3: Pop all elements, printing them.
   WHY: Each pop removes top — O(1). Popping all gives
   elements in reverse insertion order (LIFO property).
 Step 4: Check empty and size.
   WHY: Both are O(1) — maintained as member variables.

 VISUAL WALKTHROUGH:

   push(10):     push(20):     push(30):
   ┌─────┐       ┌─────┐       ┌─────┐
   │ 10  │       │ 20  │       │ 30  │ ← top
   │     │       ├─────┤       ├─────┤
   │     │       │ 10  │       │ 20  │
   └─────┘       └─────┘       ├─────┤
                               │ 10  │
                               └─────┘

   pop():        pop():        pop():
   ┌─────┐       ┌─────┐       ┌─────┐
   │ 20  │       │ 10  │       │empty│
   ├─────┤       │     │       │     │
   │ 10  │       │     │       │     │
   └─────┘       └─────┘       └─────┘

 DRY RUN (demo in main):
   stack<int> s;
   s.push(10);  → top=10, size=1
   s.push(20);  → top=20, size=2
   s.push(30);  → top=30, size=3
   s.push(40);  → top=40, size=4
   s.push(50);  → top=50, size=5
   top()=50, pop → size=4, top=40
   top()=40, pop → size=3, top=30
   top()=30, pop → size=2, top=20
   top()=20, pop → size=1, top=10
   top()=10, pop → size=0, empty=true
   Output (reverse order): 50 40 30 20 10

 TIME COMPLEXITY CALCULATION:
 - push(): Adds element to top. Underlying deque push_back
   is O(1) amortized. Just one pointer update + alloc.
   → Total = O(1)

 - pop(): Removes top element. Underlying deque pop_back
   is O(1). Just one pointer update + dealloc.
   → Total = O(1)

 - top(): Returns reference to top element.
   Underlying deque back() is O(1) — direct access.
   → Total = O(1)

 - empty()/size(): Maintained as O(1) member variable.
   → Total = O(1)

 → Time Complexity = O(1) for all operations

 SPACE COMPLEXITY CALCULATION:
 - Stack stores n elements in underlying container.
 - Default container is deque (segmented storage).
 - Each element: sizeof(T) bytes.
 - No extra per-element overhead like list (no pointers).
 - deque overhead: small number of block pointers.
 → Space Complexity = O(n)

 APPROACH COMPARISON:
 ┌───────────────┬───────────┬───────────┐
 │   Operation   │   stack   │   list    │
 ├───────────────┼───────────┼───────────┤
 │ push          │  O(1)     │ push_back │
 │               │           │ O(1)      │
 │ pop           │  O(1)     │ pop_back  │
 │               │           │ O(1)      │
 │ top/peek      │  O(1)     │ back() O(│
 │               │           │ 1)        │
 │ iteration     │  not      │ yes       │
 │               │  allowed  │ O(n)      │
 │ random access │  none     │ none      │
 └───────────────┴───────────┴───────────┘

 Underlying container comparison:
 ┌───────────────┬───────────┬───────────┬───────────┐
 │               │  default  │  vector   │   list    │
 │               │ (deque)   │  backed   │  backed   │
 ├───────────────┼───────────┼───────────┼───────────┤
 │ push          │  O(1)*    │  O(1)*    │  O(1)     │
 │ pop           │  O(1)     │  O(1)     │  O(1)     │
 │ memory        │  blocks   │  contig.  │  per-node │
 │ cache perf    │  good     │  best     │  poor     │
 └───────────────┴───────────┴───────────┴───────────┘
 * amortized for vector (may trigger reallocation)
 ────────────────────────────────────────────────────
*/

#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

void printStack(stack<int> s, const string& label) {
    cout << label << " (top→bottom): ";
    if (s.empty()) { cout << "(empty)"; }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    cout << "========== STD::STACK DEMO ==========\n\n";

    stack<int> s;

    // --- Push 5 values ---
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "After pushing 10,20,30,40,50:\n";
    cout << "  size = " << s.size() << endl;
    cout << "  top  = " << s.top() << endl;
    printStack(s, "  Stack");

    // --- Peek without removing ---
    cout << "\nPeeking top (no removal): " << s.top() << endl;
    cout << "  size unchanged = " << s.size() << endl;

    // --- Pop all, print in reverse ---
    cout << "\nPopping all (LIFO order):\n  ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << "  size after pop all = " << s.size() << endl;
    cout << "  empty? " << (s.empty() ? "yes" : "no") << endl;

    // --- emplace (construct in-place) ---
    cout << "\n--- emplace demo ---\n";
    s.emplace(100);
    s.emplace(200);
    cout << "After emplace(100) and emplace(200):\n";
    cout << "  top = " << s.top() << endl;

    // --- Swap two stacks ---
    stack<int> s2;
    s2.push(999);
    s.swap(s2);
    cout << "\nAfter swap with s2:\n";
    cout << "  s.top() = " << s.top() << endl;
    cout << "  s2.top() = " << s2.top() << endl;

    // --- Underlying container: vector-backed stack ---
    cout << "\n--- vector-backed stack ---\n";
    stack<int, vector<int>> sVec;
    sVec.push(7);
    sVec.push(8);
    sVec.push(9);
    cout << "  top = " << sVec.top() << endl;

    // --- Underlying container: list-backed stack ---
    cout << "\n--- list-backed stack ---\n";
    stack<int, list<int>> sList;
    sList.push(101);
    sList.push(202);
    cout << "  top = " << sList.top() << endl;

    // --- Edge case: empty stack ---
    cout << "\n--- Edge Case: Empty Stack ---\n";
    stack<int> empty;
    cout << "  empty.empty() = " << (empty.empty() ? "true" : "false") << endl;
    cout << "  empty.size()  = " << empty.size() << endl;
    // NEVER call top() on empty stack — undefined behavior!
    // if (!empty.empty()) { empty.top(); } // safe guard

    cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
