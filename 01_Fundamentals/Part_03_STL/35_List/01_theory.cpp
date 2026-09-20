/*
═══════════════════════════════════════════════
 STD::LIST — Doubly Linked List in STL
 ⏱️ TIME COMPLEXITY:
   Insert/erase at iterator position: O(1)
   Access by index: O(n) — must traverse
   push_front/push_back: O(1)
   remove value: O(n) — must search first
   sort: O(n log n) — list has its own merge-sort
   merge/splice: O(n) — pointer rewiring only
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a train with coaches. Each coach knows the one
 before it and the one after it. You can uncouple any two
 coaches, insert a new coach in between, or remove a coach
 — all without shifting the entire train. A train inspector
 (iterator) must walk coach by coach to reach position 5;
 he cannot teleport. std::list models exactly this: each
 element stores a backward and forward pointer, so insertion
 and deletion near a known position are instant, but random
 access requires a walk.

 📖 THEORY: (pure English, beginner-level)
 - std::list is a doubly-linked list container in <list>.
 - Every node stores: [prev_ptr | data | next_ptr].
 - Iterators are bidirectional (not random-access).
 - push_front / push_back are O(1).
 - insert / erase at an iterator position are O(1) because
   only pointers are rewired — no element shifting.
 - std::list has its own sort() — O(n log n) merge-sort,
   because std::sort needs random-access iterators.
 - splice() transfers nodes from one list to another in O(1)
   by just relinking pointers.
 - unique() removes consecutive duplicates — O(n).
 - remove(value) removes ALL matching nodes — O(n).
 - merge() combines two sorted lists — O(n).

 ASCII DOUBLY-LINKED LIST:
   head                                        tail
    │                                           │
    ▼                                           ▼
 ┌──────┐    ┌──────┐    ┌──────┐    ┌──────┐
 │ NULL │◄──►│  10  │◄──►│  20  │◄──►│  30  │◄──► NULL
 │ prev │    │ prev │    │ prev │    │ prev │
 │ next │    │ next │    │ next │    │ next │
 └──────┘    └──────┘    └──────┘    └──────┘
   Each node has 3 fields: prev pointer, data, next pointer
   Total per node = overhead of 2 pointers + data

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create list and push values at both ends.
   WHY: push_front is O(1), push_back is O(1) — no shifting.
 Step 2: Use insert(iterator, value) to add at a position.
   WHY: iterator walks to position in O(n), then insertion
   itself is O(1) — just pointer rewiring.
 Step 3: Remove a value with remove().
   WHY: list must scan all nodes — O(n), but then removal of
   each matching node is O(1) pointer rewiring.
 Step 4: Call unique() to remove consecutive duplicates.
   WHY: scans once comparing neighbours — O(n).
 Step 5: Call sort() — list's own merge sort O(n log n).
   WHY: std::sort won't work because list lacks random access.

 VISUAL WALKTHROUGH:

   Initial:    10 ⇄ 20 ⇄ 30

   push_front(5):
               5 ⇄ 10 ⇄ 20 ⇄ 30
   head → 5

   push_back(40):
               5 ⇄ 10 ⇄ 20 ⇄ 30 ⇄ 40

   insert at 2nd position (value 15):
               5 ⇄ 10 ⇄ 15 ⇄ 20 ⇄ 30 ⇄ 40
                    ↑ new node linked here

   remove(20):
               5 ⇄ 10 ⇄ 15 ⇄ 30 ⇄ 40
                    15.next → 30, 30.prev → 15

   After sort(list with duplicates 5,10,5,30,5):
               5 ⇄ 5 ⇄ 5 ⇄ 10 ⇄ 30

   After unique():
               5 ⇄ 10 ⇄ 30

 DRY RUN (demo in main):
   list<int> l;  → empty list
   l.push_back(30);  → [30]
   l.push_back(10);  → [30, 10]
   l.push_front(50); → [50, 30, 10]
   l.push_back(20);  → [50, 30, 10, 20]
   l.push_front(10); → [10, 50, 30, 10, 20]
   Insert 25 after 30:
     find 30 → insert 25 → [10, 50, 30, 25, 10, 20]
   l.remove(10);     → [50, 30, 25, 20]
   l.sort();          → [20, 25, 30, 50]
   l.unique();        → [20, 25, 30, 50] (already unique)
   print: 20 25 30 50

 TIME COMPLEXITY CALCULATION:
 - push_front/push_back: Just allocate node + fix 2 pointers
   → pointer operations are O(1)
   → Total = O(1)

 - insert at iterator: Iterator already points to target.
   Rewire prev/next of 3 nodes → constant pointer work
   → Total = O(1) for the insertion itself
   (finding the iterator position is O(n) traversal)

 - remove(value): Must scan all n nodes → O(n) traversal.
   Each removal is O(1) pointer rewiring.
   → Total = O(n)

 - unique(): Single pass comparing adjacent nodes → O(n)

 - sort(): List uses internal merge-sort.
   Merge-sort divides list in half recursively → O(log n) levels.
   At each level, merging all n elements → O(n) work.
   → Total = O(n × log n) = O(n log n)

 - splice(): Just relink a few pointers — O(1)
   (moving entire sub-list)

 → Time Complexity Summary:
   push/pop ends: O(1) | insert at pos: O(1) after finding
   remove/search: O(n) | sort: O(n log n) | splice: O(1)

 SPACE COMPLEXITY CALCULATION:
 - Each node stores: data (e.g. 4 bytes for int)
                    + prev pointer (8 bytes on 64-bit)
                    + next pointer (8 bytes)
 - Overhead per node = 2 pointers = 16 bytes
 - For n nodes: n × (data + 2 pointers)
 - No extra arrays needed (unlike vector doubling)
 → Space Complexity = O(n) with higher constant than vector

 APPROACH COMPARISON:
 ┌──────────────┬───────────┬───────────┬───────────┐
 │   Operation  │  vector   │   list    │  deque    │
 ├──────────────┼───────────┼───────────┼───────────┤
 │ push_back    │  O(1)*    │  O(1)     │  O(1)     │
 │ push_front   │  O(n)     │  O(1)     │  O(1)     │
 │ insert(mid)  │  O(n)     │  O(1)**   │  O(n)     │
 │ erase(mid)   │  O(n)     │  O(1)**   │  O(n)     │
 │ access [i]   │  O(1)     │  O(n)     │  O(1)     │
 │ sort         │  O(nlng)  │  O(nlng)  │  O(nlng)  │
 │ memory/each  │  compact  │  2 ptrs   │  segments │
 └──────────────┴───────────┴───────────┴───────────┘
 * amortized  ** after iterator already positioned
 ────────────────────────────────────────────────────
*/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printList(const list<int>& l, const string& label) {
    cout << label << ": ";
    if (l.empty()) {
        cout << "(empty)";
    }
    for (const auto& val : l) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    cout << "========== STD::LIST DEMO ==========\n\n";

    // --- Basic construction ---
    list<int> l1;
    cout << "Created empty list: ";
    printList(l1, "l1");

    // --- push_back and push_front ---
    l1.push_back(30);
    l1.push_back(10);
    l1.push_front(50);
    l1.push_back(20);
    l1.push_front(10);
    printList(l1, "After pushes  ");

    // --- Insert at position (2nd element) ---
    auto it = l1.begin();
    ++it; // move to 2nd position
    l1.insert(it, 25);
    printList(l1, "Insert 25 @pos2");

    // --- Insert multiple copies ---
    it = l1.end();
    l1.insert(it, 3, 99); // insert 3 copies of 99 at end
    printList(l1, "Insert 3x 99  ");

    // --- Remove all occurrences of a value ---
    l1.remove(10);
    printList(l1, "Remove(10)    ");

    // --- Remove by iterator ---
    it = l1.begin();
    advance(it, 2);
    l1.erase(it);
    printList(l1, "Erase @pos3   ");

    // --- Sort (list's own merge-sort) ---
    l1.sort();
    printList(l1, "Sorted        ");

    // --- Unique (consecutive duplicates) ---
    l1.push_back(99);
    l1.push_back(99);
    l1.push_front(20);
    printList(l1, "Before unique ");
    l1.unique();
    printList(l1, "After unique  ");

    // --- Merge two sorted lists ---
    list<int> l2 = {5, 15, 35};
    l1.sort();
    l2.sort();
    l1.merge(l2);
    printList(l1, "Merged l1+l2  ");
    printList(l2, "l2 (empty now)");

    // --- Splice: move node from l3 into l1 ---
    list<int> l3 = {100, 200, 300};
    auto it3 = l3.begin();
    ++it3; // points to 200
    l1.splice(l1.begin(), l3, it3); // move 200 to front of l1
    printList(l1, "After splice  ");
    printList(l3, "l3 after splice");

    // --- Reverse ---
    l1.reverse();
    printList(l1, "Reversed      ");

    // --- Edge case: empty list operations ---
    list<int> empty;
    cout << "\n--- Edge Case: Empty List ---\n";
    cout << "empty.empty() = " << (empty.empty() ? "true" : "false") << endl;
    cout << "empty.size()  = " << empty.size() << endl;
    // DO NOT call empty.front() or empty.back() on empty list!

    cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
