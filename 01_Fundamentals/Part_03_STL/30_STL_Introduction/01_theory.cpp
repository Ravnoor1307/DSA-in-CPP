/*
═══════════════════════════════════════════════
 INTRODUCTION TO STL (Standard Template Library)
 ⏱️ TIME COMPLEXITY: derived below per operation.
     sort → O(n log n), find → O(n), push_back → amortized O(1).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are a teacher managing a classroom. You suddenly need a
 list of all student names, a way to sort them in alphabetical order,
 and a quick way to check "is Rohan in this class?" Every day you face
 the same boring jobs: storing data, arranging it, and searching it.
 Writing this from scratch every semester is painful and buggy.
 The C++ STL is like a well-stocked stationery cupboard: boxes for
 storing (containers), tools for arranging (algorithms), and pointers
 for pointing (iterators). Stop reinventing the wheel, open the
 cupboard, and grab the exact tool you need.

 📖 THEORY:

 - STL = Standard Template Library. A set of C++ template classes and
   functions that give you reusable, tested building blocks.

 - WHY use STL?
   1. No need to hand-code linked lists, dynamic arrays, sorting, search.
   2. Templates → one container works for int, double, string, custom class.
   3. Battle-tested by millions of programs → fewer bugs.
   4. Fast — the library is heavily optimized.

 - The FIVE main components (see map below):

   ┌────────────────────────────────────────────────────────────┐
   │                    STL COMPONENT MAP                       │
   ├────────────────────────────────────────────────────────────┤
   │                                                            │
   │   CONTAINERS ── store data                                 │
   │      vector, list, deque, set, map, stack, queue           │
   │                    │                                       │
   │   ITERATORS ───────┘  act like pointers to walk through    │
   │      begin()/end(), ++ , * ,  (glue between parts)         │
   │                    │                                       │
   │   ALGORITHMS ──────┘  operate on ranges                    │
   │      sort, find, binary_search, reverse, count             │
   │                                                            │
   │   FUNCTORS ─── function objects, callable like functions   │
   │      greater<int>, user-defined operator()                 │
   │                                                            │
   │   ADAPTERS ─── adapt existing containers to a new face     │
   │      stack (from deque), priority_queue, back_inserter     │
   │                                                            │
   └────────────────────────────────────────────────────────────┘

 - Template idea: a "stencil". `vector<int>` and `vector<string>` share
   the same code skeleton; the compiler fills in the type.
   template <class T> → T can be int, double, any class.

 - namespace std: all STL names (vector, sort, cout) live inside the
   `std` namespace. We write `using namespace std;` to avoid typing
   std:: everywhere.

 - Compile with modern C++:  g++ file.cpp -std=c++17 -O2 -o app

 - WHEN TO USE STL: almost always. Prefer vector for dynamic arrays,
   map/set for sorted lookup, sort + find for daily list jobs.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Pick the container. WHY: a normal array has fixed size; a
         vector grows automatically, so we never worry about capacity.

 Step 2: Fill data using push_back(). WHY: push_back appends at the end
         in amortized O(1) and keeps the order of insertion.

 Step 3: Call sort(v.begin(), v.end()). WHY: sort needs two iterators
         (start and end) to know which range to arrange; it sorts in
         ascending order by default in O(n log n).

 Step 4: Call find(v.begin(), v.end(), key). WHY: find scans a range
         linearly and returns an iterator to the first match, or end()
         if the key is absent — a clean, safe "not found" signal.

 Step 5: Check emptiness first. WHY: calling find/sort on an empty
         vector is legal, but printing `*it` on an empty result is not;
         always guard against end().

 VISUAL WALKTHROUGH:

   vector<int> v = {5, 2, 8, 1};
   v.push_back(9)  →  [5][2][8][1][9]
                          sort(v.begin(), v.end())
   v sorted         →  [1][2][5][8][9]
                        begin()            end()
                         ↓                  ↓
                       [1][2][5][8][9]  (end points ONE PAST the last)

   find(v.begin(), v.end(), 8):
                       begin()    found!        end()
                         ↓         ↓             ↓
                       [1][2][5][8][9]
       returns iterator pointing at 8 → value *it == 8.
   find(v.begin(), v.end(), 99):
       matches nothing → returns end() == "not found".

 DRY RUN:
   Input: v starts empty.
   1. push_back(5)  → v = {5}      size=1
   2. push_back(2)  → v = {5,2}    size=2
   3. push_back(8)  → v = {5,2,8}  size=3
   4. push_back(1)  → v = {5,2,8,1}size=4
   5. sort          → v = {1,2,5,8}
   6. find(8)       → found at index 3, printed as "8 found"
   7. find(99)      → equals end() → printed as "99 NOT found"

 TIME COMPLEXITY CALCULATION:
 - push_back one element: O(1) amortized — most pushes are immediate,
   rare pushes do a full copy of all n elements. (n copies spread over
   n pushes → about 2 copies per push → constant → O(1) amortized)
 - sort(v.begin(), v.end()): merge/quick/intro sort style; the number
   of comparisons is n·log2(n) because each pass halves the work.
   → O(n log n)
 - find: worst case the key is last or missing → walk all n elements.
   → O(n)
 → NET for demo (sort dominates) = O(n log n)

 SPACE COMPLEXITY CALCULATION:
 - vector stores exactly n ints; capacity may reach ~2n.
   (2n + small constant) → O(n)
 - sort() may use O(log n) recursion scratch → negligible.
 → Space Complexity = O(n)

 APPROACH COMPARISON:
 ┌───────────────────────┬───────────────────────┬────────────────────┐
 │  Approach             │  Time                │  Notes              │
 ├───────────────────────┼───────────────────────┼────────────────────┤
 │ Raw C array + manual  │  Hand-written sort   │  Fixed size,        │
 │ sort/search           │  usually O(n²)       │  easy to overrun    │
 │                       │  boxes               │                     │
 │ Hand-rolled functions │  Your own bugs       │  Reinventing wheel  │
 │                       │                      │                     │
 │ STL vector + sort +   │  sort O(n log n)     │  Tested, fast,      │
 │ find                  │  find O(n)           │  automatic memory   │
 │                       │                      │                     │
 └───────────────────────┴───────────────────────┴────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ======= DEMO: STL ki power ek saath dikhao =======
    vector<int> v;            // container: dynamic array
    v.push_back(5);
    v.push_back(2);
    v.push_back(8);
    v.push_back(1);
    v.push_back(9);           // abhi size 5 ho gaya

    cout << "Before sort : ";
    for (int x : v) cout << x << " ";   // range-based loop print
    cout << "\n";

    sort(v.begin(), v.end());           // ALGORITHM — arrange ascending
    cout << "After sort  : ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // ======= find() + edge case check =======
    int key = 8;
    auto it = find(v.begin(), v.end(), key); // returns iterator ya end()
    if (it != v.end()) {
        cout << key << " found at index " << (it - v.begin()) << "\n";
    } else {
        cout << key << " NOT found\n";
    }

    // EDGE CASE: missing element → find returns end()
    int missing = 99;
    auto it2 = find(v.begin(), v.end(), missing);
    if (it2 == v.end()) {
        cout << missing << " NOT found in container\n";
    }

    // EDGE CASE: EMPTY container — never dereference end()
    vector<int> empty;
    sort(empty.begin(), empty.end());            // safe (no-op)
    cout << "Empty container size = " << empty.size()
         << " (sort on empty is harmless)\n";
    if (empty.begin() == empty.end()) {
        cout << "begin() == end() for empty vector -> never deref it!\n";
    }

    return 0;
}