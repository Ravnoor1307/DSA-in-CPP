/*
═══════════════════════════════════════════════
 MALLOC vs NEW in C++ (C-style vs C++ Memory)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are moving into a new apartment. With "malloc", the landlord
 gives you an empty room — you get the space, but no furniture, no paint,
 nothing is set up. You have to bring everything yourself. With "new",
 the landlord hands you a fully furnished room — the furniture is placed,
 walls are painted, and everything is ready to use. That is exactly the
 difference: malloc just allocates raw bytes, while new allocates AND
 constructs (calls constructors) so the object is ready to use.

 📖 THEORY:
 - malloc() is a C-style memory allocation function. It returns a void*
   pointer to raw, uninitialized memory. You must cast it to the right type.
 - new is a C++ keyword. It allocates memory AND calls the constructor of
   the object. It returns a properly typed pointer — no casting needed.
 - free() is used to release memory allocated by malloc(). It does NOT call
   destructors.
 - delete is used to release memory allocated by new. It DOES call the
   destructor before freeing memory.
 - For arrays: malloc needs manual size calculation (n * sizeof(type)),
   new[] handles it, and you must use delete[] for new[].

 KEY DIFFERENCES:
 ┌──────────────────┬────────────────────────┬────────────────────────┐
 │ Feature          │ malloc / free          │ new / delete           │
 ├──────────────────┼────────────────────────┼────────────────────────┤
 │ Language         │ C (works in C++)       │ C++ only               │
 │ Returns          │ void* (needs cast)     │ Typed pointer          │
 │ Constructor      │ NOT called             │ Called automatically   │
 │ Destructor       │ NOT called             │ Called by delete       │
 │ Size             │ Manual (sizeof)        │ Automatic              │
 │ Failure          │ Returns NULL           │ Throws bad_alloc       │
 │ Header needed    │ <cstdlib>              │ None (keyword)         │
 └──────────────────┴────────────────────────┴────────────────────────┘

 🧠 LOGIC — STEP BY STEP:

 Step 1: Allocate one int using malloc.
   WHY: Shows that malloc returns void* which must be cast. Memory is
   uninitialized — value could be anything before we assign.

 Step 2: Allocate one int using new.
   WHY: new returns int* directly — no cast needed. Simpler syntax.
   For POD types (plain old data like int), no constructor call matters,
   but for classes it makes a big difference.

 Step 3: Allocate a Node struct with malloc, assign data, then free.
   WHY: Demonstrates that malloc does NOT call constructors. If the struct
   had a constructor, it would be skipped. Free releases memory but
   does not call any destructor.

 Step 4: Allocate a Node struct with new, assign data, then delete.
   WHY: new calls the constructor (if any), ensuring the object is
   properly initialized. Delete calls destructor then frees memory.

 Step 5: Show what happens if you mix them (malloc + delete, new + free).
   WHY: Mixing is undefined behavior. Always match malloc with free and
   new with delete. This is a common bug source.

 VISUAL WALKTHROUGH:

  malloc(4 bytes)           new int
  ┌──────────────┐         ┌──────────────┐
  │ ??? (garbage) │         │ 0 (init val) │
  └──────────────┘         └──────────────┘
  raw bytes, no init        may call constructor

  malloc(sizeof(Node))      new Node
  ┌──────────┬──────┐      ┌──────────┬──────┐
  │ ???      │ ???  │      │ 0        │ NULL │
  └──────────┴──────┘      └──────────┴──────┘
  data and next are junk    properly initialized

  free(ptr)                 delete ptr
  - Just releases bytes     - Calls destructor first
  - No destructor called    - Then releases bytes

 DRY RUN:
  Line | Action                                  | State
  ─────┼─────────────────────────────────────────┼──────────────────
   31  | int* mPtr = (int*)malloc(sizeof(int))   | mPtr -> [???]
   32  | *mPtr = 42                              | mPtr -> [42]
   33  | cout << *mPtr                           | Output: 42
   35  | int* nPtr = new int                      | nPtr -> [???]
   36  | *nPtr = 99                              | nPtr -> [99]
   37  | cout << *nPtr                           | Output: 99
   41  | Node* mNode = (Node*)malloc(...)         | mNode -> [??? | ???]
   42  | mNode->data = 10; mNode->next = NULL    | mNode -> [10 | NULL]
   43  | print mNode                             | Output: data=10
   45  | Node* nNode = new Node                   | nNode -> [0 | NULL]
   46  | nNode->data = 20                        | nNode -> [20 | NULL]
   47  | print nNode                             | Output: data=20
   51  | free(mPtr); free(mNode)                  | C-style memory freed
   52  | delete nPtr; delete nNode                | C++ memory freed

 TIME COMPLEXITY CALCULATION:
 - malloc(): System call to reserve n bytes = O(1) amortized
 - free(): Release reserved block = O(1) amortized
 - new: System call + constructor call = O(1) amortized
 - delete: Destructor call + system free = O(1) amortized
 - All operations are constant time for single allocations
 → Time Complexity = O(1) per allocation/deallocation

 SPACE COMPLEXITY CALCULATION:
 - malloc(n): Reserves exactly n bytes of raw memory
 - new T: Reserves sizeof(T) bytes + possible vtable pointer for classes
 - For POD types: same space as malloc
 - For classes with virtual functions: new adds vtable pointer overhead
 → Space Complexity = O(1) per single allocation, O(n) for n allocations

 APPROACH COMPARISON:
 ┌─────────────────────────┬──────────────────┬──────────────────┐
 │ Scenario                │ Use malloc/free  │ Use new/delete   │
 ├─────────────────────────┼──────────────────┼──────────────────┤
 │ Plain C code            │ Required         │ Not available    │
 │ Simple POD types (int)  │ Works fine       │ Works fine       │
 │ Classes with ctors/dtor │ BAD — skips them │ REQUIRED         │
 │ Need constructor init   │ Impossible       │ Automatic        │
 │ Exception safety        │ Manual checks    │ Automatic throw  │
 │ C++ idiomatic code      │ Avoid            │ Preferred        │
 └─────────────────────────┴──────────────────┴──────────────────┘
═══════════════════════════════════════════════
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "=== MALLOC vs NEW in C++ ===" << endl;
    cout << endl;

    cout << "--- Part 1: Simple int allocation ---" << endl;

    int* mPtr = (int*)malloc(sizeof(int));
    *mPtr = 42;
    cout << "malloc: *mPtr = " << *mPtr
         << " (had to cast void* to int*)" << endl;

    int* nPtr = new int;
    *nPtr = 99;
    cout << "new:    *nPtr = " << *nPtr
         << " (no cast needed, returned int*)" << endl;

    free(mPtr);
    delete nPtr;

    cout << "\n--- Part 2: Node struct allocation ---" << endl;

    Node* mNode = (Node*)malloc(sizeof(Node));
    mNode->data = 10;
    mNode->next = NULL;
    cout << "malloc Node: data = " << mNode->data
         << ", next = " << mNode->next << endl;
    cout << "  (malloc did NOT call constructor, had to assign manually)" << endl;

    Node* nNode = new Node;
    nNode->data = 20;
    nNode->next = NULL;
    cout << "new Node:    data = " << nNode->data
         << ", next = " << nNode->next << endl;
    cout << "  (new called constructor if available)" << endl;

    free(mNode);
    delete nNode;

    cout << "\n--- Part 3: Edge case — uninitialized malloc ---" << endl;

    int* raw = (int*)malloc(sizeof(int));
    cout << "Uninitialized malloc value: " << *raw
         << " (garbage — never assigned!)" << endl;
    free(raw);

    cout << "\n--- Part 4: Important Rule ---" << endl;
    cout << "Rule: Always match malloc with free, new with delete." << endl;
    cout << "Mixing them is UNDEFINED BEHAVIOR!" << endl;

    cout << "\nAll memory freed. Program ends." << endl;
    return 0;
}
