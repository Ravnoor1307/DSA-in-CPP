/*
═══════════════════════════════════════════════
 DYNAMIC MEMORY ALLOCATION — new / delete
 ⏱️ TIME COMPLEXITY: new O(1)*, delete O(1)*, fill array O(n), print O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a movie theatre with 100 fixed seats (stack). On a busy day,
 150 people show up. The manager calls the furniture shop and says
 "bring me 50 extra chairs RIGHT NOW." Those extra chairs are placed in
 the open floor — this is HEAP allocation. The chairs are booked at
 RUNTIME (when we know how many people came), they stay until the manager
 says "remove them" (delete), and if the manager forgets, those chairs
 just sit there forever eating floor space (memory leak). If someone
 sits in a removed chair (dangling pointer), that's undefined behavior.

 📖 THEORY: (pure English, beginner-level)
 - Stack: fixed-size, automatic, fast. Local variables and parameters live here.
 - Heap: dynamic, manual, slower. Use when SIZE is not known at compile time.
 - new:   allocates memory on the heap, returns a pointer.
 - delete: frees heap memory back to the OS.
 - new[] / delete[]: array versions — MUST pair them correctly.
 - Memory leak: allocated memory never freed. Accumulates → crash.
 - Dangling pointer: pointer that still points to freed memory → UB.
 - Edge case n=0: new int[0] is legal, returns valid pointer, delete[] is safe.

 ASCII MEMORY LAYOUT:
   ┌─────────────────────────────────────────────┐
   │                  MEMORY                      │
   ├──────────────────────┬──────────────────────┤
   │       STACK          │        HEAP           │
   │  (auto, fast)        │  (manual, larger)     │
   │                      │                       │
   │  ┌──────────┐        │  ┌──────────────────┐ │
   │  │ main()   │        │  │ new int[5]       │ │
   │  │ frame:   │        │  │ [10][20][30][..] │ │
   │  │  int n=5 │        │  └──────────────────┘ │
   │  │  int* p──┼────────┤  ↑ p points here      │
   │  └──────────┘        │                       │
   │  ┌──────────┐        │  ┌──────────────────┐ │
   │  │ func()   │        │  │ new int(42)      │ │
   │  │ frame:   │        │  │ [42]              │ │
   │  └──────────┘        │  └──────────────────┘ │
   └──────────────────────┴──────────────────────┘

 KEY PAIRS to remember:
   new int      →  delete ptr;
   new int[n]   →  delete[] ptr;   (MUST use delete[])

 MEMORY LEAK = allocated heap memory, no pointer left to free it.
   {
       int* p = new int[1000];   // 4000 bytes allocated
   }                              // p goes out of scope → LEAK!
   // Those 4000 bytes are stuck until program exits

 DANGLING POINTER:
   int* p = new int(42);
   delete p;          // memory freed
   cout << *p;        // ⚠️ UNDEFINED BEHAVIOR
   // Fix: p = nullptr;  after every delete

 CHECKING new:
   By default, new throws std::bad_alloc on failure.
   Use nothrow:  int* p = new (nothrow) int[n];
   if (p == nullptr) {   // allocation failed — handle gracefully
       cout << "Out of memory!"; return 1;
   }

 🧠 LOGIC — STEP BY STEP:
 Step 1: Ask user for size n.
         WHY: dynamic allocation means size is decided at runtime.
 Step 2: Allocate array with new (nothrow variant).
         WHY: returns nullptr on failure instead of crashing.
 Step 3: Fill array from user input.
         WHY: demonstrates that heap memory behaves like a normal array.
 Step 4: Print array contents.
         WHY: verify data was stored correctly.
 Step 5: delete[] the array and set pointer to nullptr.
         WHY: free memory AND prevent dangling pointer.

 VISUAL WALKTHROUGH — Dynamic Array Life Cycle:

   User enters n = 3:

   new int[3] called:
     Heap:  ┌────┬────┬────┐
            │ ?? │ ?? │ ?? │   (uninitialized)
            └────┴────┴────┘
            ↑ p points here

   User fills: 10 20 30
     Heap:  ┌────┬────┬────┐
            │ 10 │ 20 │ 30 │
            └────┴────┴────┘

   delete[] p:
     Heap:  [freed — memory returned to system]
   p = nullptr:
     p → nullptr  (no longer dangling)

 DRY RUN — n=2, values 5 7:
   new (nothrow) int[2]  → p = 0x5578... (non-null)
   cin >> p[0] → p[0] = 5
   cin >> p[1] → p[1] = 7
   Print: 5 7
   delete[] p → 2 ints freed
   p = nullptr → safe

 TIME COMPLEXITY CALCULATION:
 - new int[n]: allocator finds a block → O(1)* (amortized by allocator)
 - Fill n elements: n reads from cin, n assignments → n × O(1) = O(n)
 - Print n elements: n iterations → n × O(1) = O(n)
 - delete[] n elements: n destructors called → O(n) for complex types, O(1)* for int
 → Time Complexity = O(n) for fill + print

 SPACE COMPLEXITY CALCULATION:
 - Heap array: n × sizeof(int) = 4n bytes → O(n)
 - Local variables: pointer p (8 bytes) + counter i (4 bytes) + n (4 bytes) → O(1)
 → Space Complexity = O(n)

 APPROACH COMPARISON:
 ┌────────────────────┬───────────────────────┬───────────────────────┐
 │ Feature            │ Stack (fixed array)   │ Heap (new int[n])     │
 ├────────────────────┼───────────────────────┼───────────────────────┤
 │ Size known at      │ Compile time only     │ Runtime (user input)  │
 │ Speed              │ Very fast             │ Slower (allocation)   │
 │ Max size           │ ~8 MB (default)       │ GBs (RAM limit)       │
 │ Lifetime           │ Scope-bound           │ Until delete          │
 │ Cleanup            │ Automatic             │ Manual (delete[])     │
 │ Memory leak risk   │ None                  │ HIGH if forgotten     │
 └────────────────────┴───────────────────────┴───────────────────────┘
*/

#include <iostream>
using namespace std;

int main() {

    // ═══════════════════════════════════════════════
    // DEMO 1: Single object — new / delete
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 1: new / delete (single int) ===" << endl;
    int *single = new int(42);       // heap pe ek int, value 42
    cout << "Value on heap: " << *single << endl;
    cout << "Heap address:  " << single << endl;
    delete single;                   // memory wapas karo
    single = nullptr;                // dangling se bacao
    cout << "After delete + nullptr: single = " << single << "\n\n";

    // ═══════════════════════════════════════════════
    // DEMO 2: Dynamic array — user decides size
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 2: Dynamic Array ===" << endl;
    int n;
    cout << "Enter array size n: ";
    cin >> n;

    // edge case: n = 0
    if (n < 0) {
        cout << "Invalid size (negative). Exiting." << endl;
        return 1;
    }

    int *arr = new (nothrow) int[n];   // nothrow: nullptr on failure
    if (arr == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];                 // heap array bilkul normal array jaisa
    }

    cout << "You entered: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;    // MUST use delete[] for new[]
    arr = nullptr;   // safe: no dangling pointer
    cout << "Array deleted and pointer set to nullptr.\n\n";

    // ═══════════════════════════════════════════════
    // DEMO 3: Edge case — n = 0
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 3: Edge Case n=0 ===" << endl;
    int *empty = new (nothrow) int[0];   // legal! returns valid pointer
    if (empty != nullptr) {
        cout << "new int[0] returned non-null pointer: " << empty << endl;
        cout << "delete[] on empty array is safe." << endl;
        delete[] empty;    // perfectly legal
        empty = nullptr;
    }
    cout << endl;

    // ═══════════════════════════════════════════════
    // DEMO 4: Memory leak (conceptual — DON'T leak in real code)
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 4: Memory Leak (conceptual) ===" << endl;
    cout << "void leak() {                       " << endl;
    cout << "    int* p = new int[1000];          " << endl;
    cout << "}  // p goes out of scope! LEAK!    " << endl;
    cout << "Memory never freed until program exits." << endl;
    cout << "Fix: always call delete[] before pointer goes out of scope.\n" << endl;

    // ═══════════════════════════════════════════════
    // DEMO 5: Dangling pointer avoidance
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 5: Dangling Pointer Avoidance ===" << endl;
    int *dp = new int(7);
    cout << "Before delete: *dp = " << *dp << endl;
    delete dp;
    dp = nullptr;          // ← THIS line prevents dangling
    // cout << *dp;        // would be UB if dp was not nullptr
    cout << "After delete + nullptr: dp = " << dp << " (safe)" << endl;
    // cout << *dp;        // would crash or print junk (UB)
    cout << "Dereferencing nullptr is also UB, but at least no accidental read.\n" << endl;

    // ═══════════════════════════════════════════════
    // DEMO 6: sizeof on heap pointer vs stack array
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 6: sizeof on Heap Pointer ===" << endl;
    int stackArr[5] = {1, 2, 3, 4, 5};
    int *heapArr = new int[5]{1, 2, 3, 4, 5};
    cout << "sizeof(stackArr) = " << sizeof(stackArr) << " bytes (full array)" << endl;
    cout << "sizeof(heapArr)  = " << sizeof(heapArr)  << " bytes (pointer only!)" << endl;
    cout << "Heap pointer is just 8 bytes — it doesn't store the array size." << endl;
    cout << "That's why we must pass 'n' separately.\n" << endl;
    delete[] heapArr;
    heapArr = nullptr;

    cout << "All dynamic memory demos complete." << endl;
    return 0;
}
