/*
═══════════════════════════════════════════════
 std::set — SORTED UNIQUE ELEMENTS (Red-Black Tree)
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a university admissions office. Every student is given a
 unique enrollment number like 102301, 102305, 102309. The office
 wants to keep them in sorted order so that calling out roll numbers
 in the assembly is easy, and nobody can appear twice in the list.
 Same idea applies to a social media app's "friends list" — you never
 want the same friend twice, and showing them alphabetically is nice.
 A std::set does exactly this: it stores ONLY unique values, keeps
 them SORTED automatically, and answers "is this number present?",
 "what is the next largest number?" instantly.

 📖 THEORY:
 - std::set is an associative container that stores UNIQUE elements
   in a SPECIFIC ORDER (default: ascending, via operator<).
 - Internally it is implemented as a SELF-BALANCING BINARY SEARCH TREE
   called a RED-BLACK TREE (not a plain array, not a hash table).
 - Because it is a BST, every tree operation (search, insert, delete)
   walks one path from root to leaf: cost = TREE HEIGHT.
 - The red-black tree keeps height balanced at log2(n), which is why
   each operation takes O(log n) comparisons.
 - Inserting a duplicate does NOT create a second copy — the duplicate
   is silently ignored (the set already >= 1 copy of that value).
 - Iteration walks an IN-ORDER traversal → you always get elements
   in sorted order for free.
 - lower_bound(x) → first element NOT LESS than x.
   upper_bound(x) → first element GREATER than x.
 - count(x) returns only 0 or 1 (because elements are unique).

                    ASCII: Binary Search Tree (Red-Black)
   ┌──────────────────────────────────────────────────────────────┐
   │                set = {3, 1, 4, 1, 5, 9, 2, 6}                │
   │                                                                │
   │               (balanced → height = ~log2(7))                  │
   │                                                                │
   │                         ┌── 4 ──┐                              │
   │                         │       │                              │
   │                    ┌── 2 ──┐    5 ──┐                          │
   │                    │       │        │                          │
   │                    1       3        9                          │
   │                                  ┌───┘                         │
   │                                  6                             │
   │                                                                │
   │   In-order walk: left → root → right gives:                    │
   │        1  2  3  4  5  6  9   (SORTED, UNIQUE)                  │
   │   Duplicate "1" was ignored ✅                                │
   └──────────────────────────────────────────────────────────────┘

 WHEN TO USE std::set:
 - You need unique values.
 - You need values in sorted order automatically.
 - You need predecessor/successor queries (lower_bound/upper_bound).
 - Frequency: your operations are O(log n) anyway, so a sorted set
   is the natural fit.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create the set.  WHY: we need a container that dedupes and sorts.
 Step 2: Insert values one by one. Each insert compares against the tree
         from the root down, walks the correct branch, and places the new
         node; self-balancing keeps height ~log n. WHY: log n cost.
 Step 3: Because duplicates are ignored, inserting the same value twice
         leaves the set size unchanged. WHY: set invariant = unique only.
 Step 4: Uso find(x) to get a pointer to x or end() if absent;
         count(x) to answer 0/1 "is it present?" quickly.
 Step 5: Use lower_bound(x) (first elem >= x) and upper_bound(x)
         (first elem > x) to split the sorted range.
 Step 6: Iterate with a range-for → elements come out already sorted.
 Step 7: erase(x) removes the value; the tree re-balances itself.

 VISUAL WALKTHROUGH:
   Insert: 4, 2, 6, 1, 3, 5, 7  (ordered input, worst case)
   ┌────────────────────────────────────────────────────────┐
   │ Without balancing the tree would be a SKEWED "line":    │
   │   4 → 6 → ... height n → O(n)! Bad!                     │
   │                                                          │
   │ With red-black self-balancing (example, simplified):     │
   │           4                                              │
   │         /   \                                            │
   │        2     6                                           │
   │       / \   / \                                          │
   │      1   3 5   7        height = 3 = log2(8) ✅ O(log n)│
   └────────────────────────────────────────────────────────┘

 DRY RUN (demo input: 5 3 8 3 9 1 5):
   step |        set content after op        | size | note
   -----|-----------------------------------|------|-------------------
   insert 5 | {5}                            |  1   |
   insert 3 | {3, 5}                         |  2   |
   insert 8 | {3, 5, 8}                      |  3   |
   insert 3 | {3, 5, 8}        DUPLICATE IGNORED |  3   | ✅ unique
   insert 9 | {3, 5, 8, 9}                  |  4   |
   insert 1 | {1, 3, 5, 8, 9}               |  5   |
   insert 5 | {1, 3, 5, 8, 9}   DUPLICATE IGNORED |  5   | ✅ unique
   find(8)  → found at index (iterator), value 8
   count(5) → 1 ,  count(99) → 0
   lower_bound(5) → 5 ,  upper_bound(5) → 8
   erase(3) → {1, 5, 8, 9}                  |  4   |

 TIME COMPLEXITY CALCULATION:
 - Tree height h: each level has twice as many nodes as the one above.
   So n nodes fit into h levels where 2^h ≈ n  →  h = log2(n).
 - insert(x): walk root→leaf following comparisons = h steps = O(log n).
 - erase(x): find the node (h steps) + fix the tree (another h) = O(log n).
 - find(x) / count(x): single root-to-leaf search = O(log n).
 - lower_bound / upper_bound: one guided descent = O(log n).
 - iterate whole set: visit all n nodes once = O(n).
 - Demo: 7 inserts × O(log 7) ≈ O(n log n) total for n inserts.
 → Time Complexity = O(log n) per operation, O(n log n) to build.

 SPACE COMPLEXITY CALCULATION:
 - Each element stored once in the tree = one node of ~constant size.
 - Distinct elements count = k (duplicates create no nodes).
 - Extra metadata per node (color/balance pointer) is constant.
 → Space Complexity = O(k) where k = number of distinct elements.

 APPROACH COMPARISON: set vs vector (for "unique + sorted + search")
 ┌──────────────────────┬──────────────────────┬──────────────────────┐
 │      Operation       │ vector (naive)       │ std::set             │
 ├──────────────────────┼──────────────────────┼──────────────────────┤
 │ dedupe               │ manual sort+unique   │ automatic            │
 │ insert any time      │ O(n) shift           │ O(log n)             │
 │ search               │ O(n) linear / O(n log│ O(log n)             │
 │                      │ n) if binary_search  │                      │
 │ sorted iteration     │ must sort first      │ free (in-order)      │
 │ next-larger query    │ not built-in         │ lower_bound/upper_b. │
 └──────────────────────┴──────────────────────┴──────────────────────┘
 Conclusion: set wins when the set has frequent inserts, deletes and
 lookups AND sorted order matters. Use unordered_set when you do NOT
 need order but want O(1) average (speed).

 GOTCHA: Do NOT rely on transitive includes even inside this demo —
 we always #include <set> explicitly.
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    // demo 1: unique student IDs — sorted roll numbers
    cout << "===== DEMO 1: UNIQUE STUDENT ROLL NUMBERS =====" << endl;
    set<int> students;                      // khali set bana liya

    int rolls[] = {5, 3, 8, 3, 9, 1, 5};    // kuch rolls repeat ho rahe hain
    for (int r : rolls) {
        students.insert(r);                 // insert karo — duplicate ignore ho jayega
    }
    cout << "Size (duplicates ignored): " << students.size() << endl;

    cout << "Sorted roll numbers: ";
    for (int s : students) {                // range-for — sorted order milti hai
        cout << s << " ";
    }
    cout << endl;

    // demo 2: find / count
    cout << "\n===== DEMO 2: FIND / COUNT =====" << endl;
    int key = 8;
    if (students.count(key)) {              // count() sirf 0 ya 1 (unique hai)
        cout << key << " present? YES (count=" << students.count(key) << ")" << endl;
    } else {
        cout << key << " present? NO" << endl;
    }

    auto it = students.find(3);             // iterator milta hai
    if (it != students.end()) {
        cout << "find(3) -> " << *it << endl;
    }
    it = students.find(999);                // jo hai hi nahi
    if (it == students.end()) {
        cout << "find(999) -> not found (== end())" << endl;
    }

    // demo 3: lower_bound / upper_bound
    cout << "\n===== DEMO 3: LOWER / UPPER BOUND =====" << endl;
    auto lb = students.lower_bound(5);      // pehla element >= 5
    auto ub = students.upper_bound(5);      // pehla element > 5
    if (lb != students.end())
        cout << "lower_bound(5) = " << *lb << endl;
    if (ub != students.end())
        cout << "upper_bound(5) = " << *ub << endl;

    // demo 4: erase
    students.erase(3);                      // value 3 ko set se hata do
    cout << "\nAfter erase(3): ";
    for (int s : students) cout << s << " ";
    cout << " (size=" << students.size() << ")" << endl;

    // EDGE CASES
    cout << "\n===== EDGE CASES =====" << endl;
    set<int> emptySet;
    cout << "empty set size: " << emptySet.size() << endl;
    cout << "count on empty set: " << emptySet.count(42) << endl;   // 0
    if (emptySet.find(42) == emptySet.end())
        cout << "find on empty set -> end(); dereferencing it is UB" << endl;
    if (emptySet.lower_bound(42) == emptySet.end())
        cout << "lower_bound on empty set -> end()" << endl;

    cout << "\nDemo complete. Sorted unique storage + O(log n) ops." << endl;
    return 0;
}