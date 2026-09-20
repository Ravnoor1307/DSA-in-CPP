/*
═══════════════════════════════════════════════
 44_STL_Algorithms — <algorithm> + <numeric> Toolkit
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A school teacher keeps an unsorted list of 500 student names for the exam
 seating chart. She needs to: print them alphabetically (sort), find one
 student's seat quickly (binary_search on the sorted list), know how many
 students scored 95+ (count), add up all marks for the class total
 (accumulate), and remove duplicate roll numbers entered twice (unique).
 The whole C++ <algorithm> library exists so she never writes a sorting
 loop or a manual binary search by hand again — every operation is one
 battle-tested function call.

 📖 THEORY: (pure English, beginner-level)
 - <algorithm> is the pantry of ready-made operations on ranges
   [first, last) — everything works via iterators (topic 34).
 - SORTING: sort(begin, end) uses Introsort (quicksort + heapsort +
   insertionsort hybrid). Average AND worst case O(n log n). It is NOT
   stable — equal elements may swap order. For stable use stable_sort.
 - FINDING: find(first, last, value) walks the range, returns iterator
   to first match or end(). find_if uses a lambda predicate.
 - COUNTING: count(first, last, value) counts matches. count_if takes
   a lambda for a condition.
 - NUMERIC: accumulate(first, last, init) adds everything to init and
   returns the total. Provide a lambda third arg for custom folds
   (multiply, concat, etc.).
 - SORTED-RANGE algorithms: binary_search (yes/no), lower_bound (first
   position where value COULD go without breaking order, i.e. first >= x),
   upper_bound (first position strictly > x). ALL of these REQUIRE the
   range to be sorted — on unsorted data they give wrong answers or UB.
 - unique(first, last) shifts duplicates to the end and returns the new
   logical end. It only removes CONSECUTIVE duplicates, so sort first.
   The "removed" elements still physically exist — use erase() to shrink.
 - next_permutation(first, last) rearranges into the next lexicographic
   order. Returns false when already at the largest permutation.
 - fill(first, last, v) sets every element to v. copy(srcFirst, srcLast,
   destFirst) copies one range into another (dest must have room).
 - min(a,b), max(a,b), min_element(first,last), max_element(first,last)
   return the smallest/largest value or iterator. Complexity O(n) for
   the _element versions, O(1) for the two-value versions.

   SORT movement (Introsort — divide & conquer):
         [5, 2, 9, 1, 7]            pivot partitions
            3  1    1 your own merge at each level
        /         \
   [1, 2]        [7, 9]         each level total work O(n)
        \         /              log n levels of halving
      [1, 2, 5, 7, 9]           → O(n log n)

          FIND on unsorted v:          BINARY_SEARCH on sorted v:
   v = [5, 2, 9, 1, 7]                 v = [1, 2, 5, 7, 9]
     5?1  2?2  9?3  1?4  7?5           mid=5: 7 > 5 → go RIGHT half
     walk ALL → O(n)                   mid=7: found! → log₂(5)≈3 steps
                                     
          LOWER_BOUND vs UPPER_BOUND on [1,3,3,5]:
   lower_bound(3) -> idx1 (first >= 3)     upper_bound(3) -> idx3 (first > 3)
   → count of 3s = upper_bound(3) - lower_bound(3) = 3 - 1 = 2 ⭐

 - WHEN TO USE: default sort for 99% of sorting needs; binary_search +
   lower_bound whenever the data is sorted and you need fast lookups
   (phone book, leaderboard ranks); accumulate for totals; unique after
   sort for dedup; next_permutation to try all orderings of small inputs.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: SORT FIRST — all sorted-range tools (binary_search, lower_bound,
         upper_bound, and reliable unique) silently assume order. If you
         skip Step 1, binary_search returns garbage, not "not found".
         WHY: binary_search cuts the range in half using the ordering
         guarantee; an unsorted range breaks that guarantee.
 Step 2: For binary_search / lower_bound / upper_bound pick the exact
         tool. Need only yes/no → binary_search. Need "where 30 would
         fit / first >= x" → lower_bound. Need "first > x" → upper_bound.
         WHY: lower_bound minus upper_bound literally counts duplicates.
 Step 3: For unique, sort first, call unique, then erase() from the new
         end to the old end to actually shrink the vector. WHY: unique
         only merges ADJACENT equals; erase reclaims real capacity/space.
 Step 4: accumulate with initial value = the neutral element (0 for sum,
         1 for product) so the first element folds correctly. WHY: the
         accumulator starts at init and adds each element in order; a
         wrong init biases the result (sum starts at 0, product at 1).

 VISUAL WALKTHROUGH:
 vector v = {5, 2, 9, 1, 7, 5}

 sort(v.begin(), v.end())
   {5,2,9,1,7,5} --partition--> {1,2} {5,5} {7,9} --merge--> [1, 2, 5, 5, 7, 9]

 auto it = lower_bound(v.begin(), v.end(), 5);
   [1, 2, 5, 5, 7, 9]
    ^  ^    |<-it points to FIRST 5 (index 2)

 auto up = upper_bound(v.begin(), v.end(), 5);
   [1, 2, 5, 5, 7, 9]
              ^<-up points to 7 (index 4)  → 5 appears up-it = 2 times

 unique: [1, 2, 5, 5, 7, 9] → [1, 2, 5, 7, 9, _]  new end points after 9
 erase:  finally shrinks to [1, 2, 5, 7, 9]

 DRY RUN:
 Before: v = {5, 2, 9, 1, 7, 5}
 After sort:                       {1, 2, 5, 5, 7, 9}
 binary_search(v, 7)   → true      (mid 5 < 7 → right → found)
 lower_bound(v, 5)     → index 2   (first position >= 5)
 count(v, 5)           → 2         (two 5s)
 accumulate(v, 0)      → 29        (1+2+5+5+7+9)
 sum of sorted evens range [2..7): 2+5+5 = 12
 fill(first 3, -1)     → {-1,-1,-1,5,7,9}  → later copy to fix
 p = {1,2,3}: next_permutation → {1,3,2} → {2,1,3} → ∅ (returns false at end)
 max_element(v)        → iterator to 9

 TIME COMPLEXITY CALCULATION:
 - sort: Introsort = quicksort; each partition level processes all n
   elements (O(n) per level) and the range halves each time, giving
   log n levels → O(n log n). Worst case same (heapsort fallback).
 - reverse: swaps first/last pointers inward, n/2 swaps → O(n).
 - find / count / min_element / max_element: single left-to-right pass,
   at most n element comparisons → O(n).
 - binary_search / lower_bound / upper_bound: each step discards half
   the range: n → n/2 → n/4 … → 1 after log₂n steps → O(log n).
 - unique: one pass detecting adjacent duplicates → O(n).
 - accumulate: one pass, n additions → O(n).
 - next_permutation: scans from the right; worst case n swaps per call
   → O(n) per permutation. Generating ALL permutations: n! × O(n) =
   O(n·n!) total.
 - fill / copy: touch every element once → O(n).
 → Time Complexity (whole demo) = dominates at sort + linear passes = O(n log n)

 SPACE COMPLEXITY CALCULATION:
 - sort is in-place: quicksort recursion stack is O(log n) levels deep
   → auxiliary O(log n) worst.
 - reverse, find, count, binary_search, lower_bound, upper_bound,
   accumulate, fill: pure iterator work on the existing container, no
   new element storage → O(1) auxiliary.
 - unique/copy: unique works in-place (O(1) aux); copy needs a prepared
   destination vector with n slots → O(n) for the copy destination.
 - next_permutation: in-place swaps → O(1) auxiliary.
 → Space Complexity = O(1) auxiliary (log n recursion stack for sort;
   O(n) only when explicitly copying to a fresh container)

 APPROACH COMPARISON:
 ┌─────────────────────────────┬──────────────────────────┬───────────────────────────────┐
 │ Task                        │ Manual loop              │ STL algorithm                 │
 ├─────────────────────────────┼──────────────────────────┼───────────────────────────────┤
 │ Sort                        │ 20-line merge sort, bugs │ sort(v.begin(), v.end())      │
 │ Lookup in sorted data       │ hand-written binary tree │ binary_search / lower_bound   │
 │ Count matches               │ 5-line loop + counter    │ count / count_if (1 line)     │
 │ Sum of numbers              │ loop +=                  │ accumulate(v.begin(),v.end(),0)│
 │ Remove duplicates           │ set round-trip O(n log n)│ sort + unique + erase O(n log n)│
 │ Compare: find O(n) can be used on ANY data, binary_search O(log n)
 │ needs SORTED data — trade 0 sorting cost against log n lookups.
 └─────────────────────────────┴──────────────────────────┴───────────────────────────────┘
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void print(const string& label, const vector<int>& v) {
    cout << label;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    // ---------------- SORT + PRINT ----------------
    vector<int> v = {5, 2, 9, 1, 7, 5};
    sort(v.begin(), v.end());                 // {1,2,5,5,7,9} — ab sorted
    print("After sort          : ", v);

    // ---------------- REVERSE ----------------
    reverse(v.begin(), v.end());              // {9,7,5,5,2,1}
    print("After reverse       : ", v);
    reverse(v.begin(), v.end());              // wapas sorted

    // ---------------- MIN / MAX ----------------
    cout << "min(3,7) max(3,7)   : "
         << min(3, 7) << " / " << max(3, 7) << "\n";
    cout << "min_element / max_element: "
         << *min_element(v.begin(), v.end()) << " / "
         << *max_element(v.begin(), v.end()) << "\n";

    // ---------------- FIND + COUNT ----------------
    auto it = find(v.begin(), v.end(), 7);    // sorted list me 7 dhoondo
    if (it != v.end())
        cout << "find(7)             : mila index "
             << (it - v.begin()) << "\n";
    else
        cout << "find(7)             : nahi mila\n";
    cout << "count of 5          : " << count(v.begin(), v.end(), 5) << "\n";

    // ---------------- ACCUMULATE (numeric) ----------------
    int sum = accumulate(v.begin(), v.end(), 0); // 0 se shuru, sab jodo
    cout << "accumulate sum       : " << sum << "\n";

    // ---------------- BINARY_SEARCH + LOWER/UPPER_BOUND (must be sorted!) ----------------
    bool found = binary_search(v.begin(), v.end(), 7);
    cout << "binary_search(7)    : " << (found ? "true" : "false") << "\n";
    auto lb = lower_bound(v.begin(), v.end(), 5); // pehla >= 5
    auto ub = upper_bound(v.begin(), v.end(), 5); // pehla > 5
    cout << "lower_bound(5)      : index " << (lb - v.begin()) << "\n";
    cout << "upper_bound(5)      : index " << (ub - v.begin()) << "\n";
    cout << "count via (ub-lb)   : " << (ub - lb) << "\n";

    // edge: 0 unsorted → binary_search WRONG answer ka demo
    vector<int> raw = {3, 1, 4, 1, 5, 9, 2, 6};   // NOT sorted!
    cout << "\n[EDGE] unsorted binary_search(5): "
         << (binary_search(raw.begin(), raw.end(), 5) ? "true" : "false")
         << "  <-- sahi answer 5 hona chahiye; kabhi kabhi galat aata hai (UB)\n"
         << "      ⚠️ binary_search/lower_bound/upper_bound SEEDHA galt hote hain "
            "agar range sorted NAHIN hai.\n";

    // ---------------- UNIQUE + ERASE (sort pehle!) ----------------
    vector<int> dup = {5, 2, 5, 2, 9, 2};
    sort(dup.begin(), dup.end());              // {2,2,2,5,5,9}
    auto newEnd = unique(dup.begin(), dup.end()); // {2,5,9,?,?,?}
    dup.erase(newEnd, dup.end());              // asli size chhota
    print("After unique+erase  : ", dup);

    // ---------------- NEXT_PERMUTATION ----------------
    vector<int> p = {1, 2, 3};
    cout << "\nnext_permutation of {1,2,3}:\n";
    do {
        print("   ", p);
    } while (next_permutation(p.begin(), p.end()));

    // ---------------- FILL + COPY ----------------
    vector<int> fillv(5);
    fill(fillv.begin(), fillv.end(), -1);      // sab -1
    print("After fill(-1)      : ", fillv);
    vector<int> dest(6);
    copy(v.begin(), v.end(), dest.begin());    // v ko dest me copy
    print("After copy into dest: ", dest);

    // edge: empty container
    vector<int> emptyV;
    cout << "\n[EDGE] empty vector: min_element="
         << (min_element(emptyV.begin(), emptyV.end()) == emptyV.end()
                 ? "end() (khali)"
                 : "mil gaya")
         << ", accumulate="
         << accumulate(emptyV.begin(), emptyV.end(), 0) << "\n";

    return 0;
}