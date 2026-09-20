/*
═══════════════════════════════════════════════
 ITERATORS — THE POINTERS OF STL
 ⏱️ TIME COMPLEXITY: advance O(n) worst, '++' and '*' O(1),
     full traversal O(n), reverse iteration O(n).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A train conductor walks down the platform holding a finger list: he
 STARTS at coach one (begin), and keeps pointing at each coach until
 he passes the last one (end). He can look inside the coach (*finger),
 step forward one coach (++), or leap many coaches at once when the
 track is straight (advance). Sometimes he walks the train BACKWARDS,
 from the tail to the head (rbegin → rend) — that is exactly how
 reverse iterators feel. The conductor does not care whether the
 coaches are a metro (vector) or a goods line (list); his pointing
 rules stay the same — that uniformity is the whole point of
 iterators.

 📖 THEORY:

 - An iterator is a generalized pointer used to walk and modify
   containers WITHOUT using an index. Every container exposes:
     begin()  → iterator to the FIRST element
     end()    → iterator to ONE PAST the last element (never deref)

        begin                      end
          │                          │
          ▼                          ▼
        [10][20][30][40]            │
          ↑              (end is here, past 40)
          *it == 10,   ++it → *it == 20 ... it == end → STOP

 - KEY OPERATIONS:
   ++it    move forward          --it    move backward
   *it     read/write the value  it[n]   jump n ahead (random access)
   it1==it2, it1!=it2  compare positions

 - ITERATOR vs INDEX:
   - Index needs [] and the container type; it works only on
     random-access containers like vector.
   - Iterator works the SAME on vector, list, set, map, deque —
     that's the portability superpower.
   - Modifying a container INVALIDATES iterators; indices too.

 - CATEGORIES (power ladder):
   ┌────────────────────┐
   │ input     read *it only, ++ only            std::istream_iterator
   │ output    write *it only, ++ only           back_inserter
   │ forward   read + write + ++                  singly linked list
   │ bidirectional  + -- (backwards)              std::list, set, map
   │ random-access + it+n, it[n], it1-it2, <,>    std::vector, deque
   └────────────────────┘
   (weaker → stronger; a stronger iterator can be used anywhere a
    weaker one is expected)

 - auto keyword: iterator types are long and ugly
   (vector<int>::iterator), auto lets the compiler fill them in:
       auto it = v.begin();      // same type, zero typing

 - REVERSE iterators:
       rbegin() → last element,  rend() → before the first
       ++ on a reverse iterator moves BACKWARD toward begin().

 - CONST_iterator: read-only view.
       const_iterator  → *it = 5;  // ERROR (compile-time safety)

 - WHEN TO USE: generic code, container-agnostic loops, algorithms
   like sort(begin,end), removing/erasing while walking, printing
   anything that holds iterators.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Obtain begin() and end(). WHY: end() marks "workspace is over"
         like a fence — never dereference it, only compare with it.

 Step 2: Start a loop `for (it = begin(); it != end(); ++it)`.
         WHY: comparing to end() is the standard stop condition for
         every category of iterator.

 Step 3: Access the current element with *it (read or write).
         WHY: * is the only way to see the value under the pointer;
         writing through it modifies the container in place.

 Step 4: Use ++it to move. Prefer ++it over it++.
         WHY: it++ makes a temporary copy; ++it advances in place
         (micro-faster and clearer intent).

 Step 5: For jumps use std::advance(it, k) or it + k on vectors.
         WHY: advance works generically on ALL categories; it+k only
         on random-access.

 Step 6: Walk backwards with rbegin()/rend() when order matters.
         WHY: reverse iterators flip the direction for free.

 Step 7: Guard empty containers first.
         WHY: begin()==end() on empty; body never runs — safe.

 VISUAL WALKTHROUGH:

   forward print:
     v = [10][20][30]
          ↑it
     step:  print *it=10   → ++it
             print *it=20   → ++it
             print *it=30   → ++it
             it==end → STOP

   reverse print (rbegin/rend):
     v = [10][20][30]
                      ↑rbegin
     *rbegin=30 → ++rbegin → *rbegin=20 → ++rbegin → *rbegin=10
     → ++rbegin == rend → STOP

   modify via iterator:
     *it = *it + 100  turns [10][20][30] into [110][120][130]

 DRY RUN (demo):
   1. v = {1,2,3,4,5}; it=v.begin() writes 99 → v[0]=99;
      loop prints 99 2 3 4 5.
   2. advance(it, 2) from begin → lands on index 2 → value 3.
   3. reverse loop rbegin..rend prints 5 4 3 2 99.
   4. map iteration: m = {1:"one",2:"two"}; prints "key=1 val=one" etc.
   5. edge: empty vector → begin()==end() → "nothing to iterate".

 TIME COMPLEXITY CALCULATION:
 - *it (dereference): one memory access → O(1).
 - ++it on vector iterator: one pointer increment → O(1).
 - std::advance(it, k) on a vector: pointer arithmetic → O(1); on a
   list it must hop k nodes → O(k) ≡ O(n) worst.
 - Full traversal of n elements: n × O(1) dereferences/moves → O(n).
 - Reverse traversal: same work, opposite direction → O(n).
 → Time Complexity = O(n) per complete traversal

 SPACE COMPLEXITY CALCULATION:
 - Iterators themselves store only a pointer/position word → O(1) each.
 - No copies of the data are made while iterating (unless you build a
   new container); the container's own n elements are unchanged → O(n).
 → Space Complexity = O(1) for the iterator, O(n) for the container

 APPROACH COMPARISON:
 ┌───────────────────────┬──────────────────────┬──────────────────────────┐
 │  Access style         │  Container support   │  Notes                   │
 ├───────────────────────┼──────────────────────┼──────────────────────────┤
 │ index v[i]            │  vector, array,      │  crashes on wrong index, │
 │                       │  deque only          │  no list/map support     │
 │ iterator              │  EVERY container     │  uniform syntax, used by │
 │                       │                      │  all STL algorithms      │
 │ range-for (auto x : c)│  every container with│  read-only loop sugar;   │
 │                       │  begin/end           │  auto& to modify         │
 │ pointer arr+i         │  C-style arrays only │  no bounds, no growth    │
 └───────────────────────┴──────────────────────┴──────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>

using namespace std;

int main() {
    // ======= DEMO 1: iterate + MODIFY via iterator =======
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = v.begin();
    *it = 99;                            // pehla element change karo
    cout << "After *it=99: ";
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";               // 99 2 3 4 5
    cout << "\n";

    // ======= DEMO 2: std::advance =======
    auto it2 = v.begin();
    advance(it2, 2);                     // 2 position aage
    cout << "After advance(it,2) -> *it2 = " << *it2 << "\n";

    // ======= DEMO 3: reverse iteration (rbegin/rend) =======
    cout << "Reverse print: ";
    for (auto r = v.rbegin(); r != v.rend(); ++r)
        cout << *r << " ";               // 5 4 3 2 99
    cout << "\n";

    // ======= DEMO 4: iterate a map of pairs =======
    map<int, string> m;
    m[1] = "one";
    m[2] = "two";
    cout << "Map iterate: ";
    for (auto itm = m.begin(); itm != m.end(); ++itm)
        cout << "(" << itm->first << "," << itm->second << ") ";
    cout << "\n";

    // ======= DEMO 5: const_iterator (read only) =======
    vector<int>::const_iterator ci = v.begin();
    cout << "const_iterator reads *ci = " << *ci
         << " (cannot write)\n";

    // EDGE CASE: empty container — begin()==end()
    vector<int> empty;
    if (empty.begin() == empty.end()) {
        cout << "Empty vector: begin()==end(), loop body never runs.\n";
    }
    int sum = 0;
    for (auto e = empty.begin(); e != empty.end(); ++e) sum += *e;
    cout << "Sum of empty = " << sum << " (safe, 0)\n";

    return 0;
}