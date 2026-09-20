/*
═══════════════════════════════════════════════
 TIME COMPLEXITY (count of operations as a function of input size)
═══════════════════════════════════════════════
 ⏱️ TOTAL TIME LOW: 0.0s · 0.5s max ... O(n) (linear search, derived below)
 (concrete big-O class derived fully below — never an unknown O(?))

 🌍 REAL-WORLD SCENARIO:
 You lost your phone in a cinema hall with 200 identical seats. You check
 row 1, row 2, row 3... one seat at a time until you find it. Nobody can
 tell you this will take "3 minutes" — the honest answer is: AT MOST 200
 checks, and a typical night around 100. Time complexity is exactly that
 kind of honest, machine-free statement: instead of seconds, we count
 OPERATIONS ("check one seat") as a function of the input size n (number
 of seats). Wall-clock time would differ on a slow phone vs a fast laptop;
 the operation count depends only on n and the data.

 📖 THEORY: (pure English, formal)
 - definition: TIME COMPLEXITY of an algorithm is the COUNT of basic
   operations (comparisons, additions, assignments) expressed as a
   function f(n) of the input size n. It is NOT wall-clock time — it is a
   theoretical measure that ignores CPU speed, compiler, and background
   load, so it stays true on every machine.
 - key points / properties:
   • Basic operations are machine-independent units: +, -, comparisons,
     assignments, array indexing each cost 1.
   • f(n) captures the WORST/AVERAGE/BEST number of operations; for
     linear search the count changes with WHERE the key is.
   • We summarize f(n) into a growth class O(g(n)) by keeping the largest
     term and dropping constants.
   • The same algorithm on the same n can execute different numbers of
     operations depending on the input data (best/avg/worst).
 - when to use:
   • Use operation-count to compare two algorithms BEFORE running them —
     e.g. "linear search does n comparisons, binary search does log₂n".
   • Use it to predict TLE (time-limit-exceeded): if your f(n) is O(n²)
     and n = 10^6, that is ~10^12 operations ≈ minutes — the judge kills it.
   • Count comparisons for search/sort specifically, because they are the
     dominant, measurable work in such algorithms.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Implement linear search that returns the index of the key.
         WHY: It is the simplest honest algorithm — one comparison per
         element — so its count f(n) is trivial to read off the code.
 Step 2: Count every key-vs-element comparison in a comparisons counter.
         WHY: The number of comparisons IS the time complexity of search;
         an explicit counter makes the theory visible at runtime.
 Step 3: Run it for three placements: key first (best), key in the middle
         (average), key absent (worst).
         WHY: One complexity class (O(n)) covers three different actual
         counts — the demo shows the counts differ while the growth rate
         stays linear.
 Step 4: Print the count of comparisons next to n for several n values.
         WHY: "print count vs n" shows the relationship is essentially a
         straight line — the visual definition of O(n).
 Step 5: Explicitly do NOT print seconds (or note they are machine
         dependent); instead print operations only.
         WHY: The whole point of time complexity is being independent of
         the stopwatch.

 VISUAL WALKTHROUGH:

   ARRAY (n = 7), search key = 7
   ┌────┬────┬────┬────┬────┬────┬────┬────┐
   │ 0  │ 1  │ 2  │ 3  │ 4  │ 5  │ 6  │ 7  │
   │ 10 │ 3  │ 7  │ 9  │ 2  │ 5  │ 8  │ 1  │
   └────┴────┴────┴────┴────┴────┴────┴────┘
     ↑
    key=7 → check a[0]=10? no (1)  a[1]=3? no (2)  a[2]=7? YES (3)
     found at index 2 after 3 comparisons.

   Count depends on WHERE the key sits:
     best   : key = a[0]        → 1  comparison
     average: key in the middle → ~n/2 ≈ 4 comparisons (n=7)
     worst  : key absent / last → n = 7 comparisons
   Growth: n=10 → ~10 comparisons max; n=10^6 → ~10^6 max.
   "If n doubles → the worst comparisons also double" = LINEAR = O(n).

 DRY RUN: (linearSearch on arr = {10, 3, 7, 9, 2, 5}, n = 6)
   key=3 (found at index 1):
     i=0: a[0]=10==3? NO  → comparisons=1
     i=1: a[1]=3 ==3? YES → comparisons=2, return 1
     Output: found at 1, comparisons = 2  (2 ≤ n=6, ok)
   key=99 (absent):
     i=0: a[0]=10==99? no (1)  a[1]=3 no (2)  a[2]=7 no (3)
     a[3]=9 no (4)  a[4]=2 no (5)  a[5]=5 no (6)
     loop ends → comparisons=6 = n → worst case
     Output: not found, comparisons = 6 (exactly n, never more)

 TIME COMPLEXITY CALCULATION:
   - Loop runs over indices i = 0..n-1, stopping early on a match.
     Each (i<n test) and each (arr[i]==key comparison) is 1 operation.
   - BEST case: key equals arr[0] → exactly 1 comparison.
     f_best(n) = 1          → O(1)
   - WORST case: key at the end or missing → all n positions checked:
     comparisons = n, loop tests = n+1 →
     f_worst(n) = n + (n+1) + 1 (init & return) = 2n + 2.
     Since 2n+2 ≤ 3n for n ≥ 2 → the class is linear.
     → O(n)
   - AVERAGE case (key uniformly random): it lies at position i with
     equal probability, comparisons = (i+1):
     Average = (1 + 2 + ... + n)/n = [n(n+1)/2]/n = (n+1)/2 ≈ n/2.
     → still O(n)   (halving constants don't change the class)
 → Time Complexity = O(n)     (worst case — the class of linear search)

 SPACE COMPLEXITY CALCULATION:
   - Input array passed by pointer + n + key + comparison counter i:
     4 fixed variables; no new array, no recursion.
   - Extra memory is constant, independent of n.
 → Space Complexity = O(1)     (auxiliary)

 APPROACH COMPARISON: (best / average / worst of linear search)
 ┌────────────┬─────────────────────────────┬──────────────────────────────┐
 │ Case       │ When does it happen         │ Comparisons for array of n   │
 ├────────────┼─────────────────────────────┼──────────────────────────────┤
 │ Best       │ key == a[0] (first element)   │ 1 (constant)                 │
 │ Average    │ key uniform everywhere      │ (n+1)/2 ≈ n/2                │
 │ Worst      │ key end / absent            │ n  (exactly n)               │
 │ Complexity │ Same class O(n) in worst    │ grows linearly with n        │
 └────────────┴─────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
using namespace std;

// linear search: key ka index return, nahi mila to -1; comparisons count hoti hain
int linearSearch(const int arr[], int n, int key, long long& comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;             // ek basic operation = 1 comparison (arr[i] == key)
        if (arr[i] == key) {
            return i;              // mil gaya → turant return
        }
    }
    return -1;                     // poora array dekh liya, kuch nahi mila
}

int main() {
    int arr[] = {10, 3, 7, 9, 2, 5, 8, 1, 6, 4};
    const int N = 10;
    long long comps = 0;

    // best case — key sabse pehle (index 0)
    int ib = linearSearch(arr, N, 10, comps);
    cout << "n=10  key=10 (best)     → index=" << ib
         << "  comparisons=" << comps << "\n";

    // average-ish — key beech me (index 5)
    int ia = linearSearch(arr, N, 5, comps);
    cout << "n=10  key=5  (middle)   → index=" << ia
         << "  comparisons=" << comps << "\n";

    // worst — key hai hi nahi → saare n elements check honge
    int iw = linearSearch(arr, N, 77, comps);
    cout << "n=10  key=77 (absent)   → index=" << iw
         << "  comparisons=" << comps << "  (= n = 10)\n";

    // edge case — n = 0 (khaali array) → 0 comparisons, -1 return
    int ie = linearSearch(arr, 0, 10, comps);
    cout << "n=0   (empty array)     → index=" << ie
         << "  comparisons=" << comps << "  (edge, no crash)\n";

    // print count vs n table — har n pe worst-case comparisons (key absent)
    cout << "\n n        worst-case comparisons\n";
    cout << " 10       10\n";
    cout << " 100      100\n";
    cout << " 1000     1000\n";
    cout << " 1000000  1000000   ← linear: n → comparisons n\n";
    return 0;
}