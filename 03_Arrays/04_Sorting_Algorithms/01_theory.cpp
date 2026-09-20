/*
═══════════════════════════════════════════════
 SORTING ALGORITHMS
 ⏱️ TIME COMPLEXITY: read the full derivation below — never a bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a messy bookshelf with novels, dictionaries and notebooks dropped in
 random order. A librarian wants the books arranged by height so the shelf looks
 neat and any book can be found in seconds. You could keep swapping neighbours
 until the tallest "bubbles" to the end (bubble sort), or pick the smallest book
 and place it first (selection sort), or slide each book left into its correct
 position (insertion sort), or split the shelf in half, sort each half, and merge
 them back (merge sort). On a 5-book shelf every method is fine, but in a
 warehouse of a million books a careless method wastes hours — exactly why we
 study the cost of sorting before choosing one.

 📖 THEORY: (pure English)
 - Sorting = rearranging a collection so that every element is in non-decreasing
   (or non-increasing) order w.r.t. a comparator: a[i] <= a[i+1].
 - Stability = if two elements have equal keys, their relative order after sorting
   is the same as before sort. Stable sorts preserve this; unstable ones may not.
 - Comparison sorts (bubble, selection, insertion, merge, quick) compare elements
   pairwise. Counting sort is NOT a comparison sort — it tallies frequencies.
 - Bubble sort: adjacent-comparison + swap. After pass i the i-th largest element
   has "bubbled" to the end, so we can shrink the scan window each pass.
     compare neighbours, swap if out of order, largest floats to end:
     [5, 1, 4, 2, 8]  → swap(5,1) → [1, 5, 4, 2, 8]  → ... → [1, 4, 2, 5, 8]
   STABLE. Best for teaching; rarely used in practice due to O(n²).
 - Selection sort: repeatedly find the minimum in the unsorted part and swap it
   to the front. Minimal write cost (≤ n-1 swaps) — great when "swap" is costly.
     find min in a[i..n-1] and put it at index i:
     [5, 1, 4, 2, 8]  min=1 → [1, 5, 4, 2, 8]  min(5,4,2,8)=2 → [1, 2, 4, 5, 8]
   UNSTABLE (long-distance swap can jump identical keys). Simple; still O(n²).
 - Insertion sort: like arranging playing cards — take the current card and shift
     larger cards right to make a gap, then insert it.
     [5, 1, 4, 2, 8]  pick 1, shift 5 right → [1, 5, 4, 2, 8]
   STABLE. O(n) on nearly-sorted input — best for "array is almost sorted".
 - Merge sort: DIVIDE & CONQUER — cut the array in two halves, recursively sort
     each half, then merge the two sorted halves (two-pointer sweep).
     split: [38,27,43,3] → [38,27] [43,3] → ...  merge: compare heads, pick smaller.
   STABLE. Guaranteed O(n log n) — but needs O(n) extra space for merging.
 - Quick sort: DIVIDE & CONQUER — pick a pivot, PARTITION so that everything ≤ pivot
     is on the left and everything > pivot on the right (Lomuto partition), then
     recurse on both sides. Pivot lands in its final sorted position.
     pivot = last element:
     [10,80,30,90,40] pivot 40 → [10,30,40,90,80]
   UNSTABLE (Lomuto). Fast average O(n log n); worst O(n²) on already-sorted input
     unless the pivot is random.
 - Counting sort: count how many times each key appears, build prefix sums, then
     place each element into its sorted position by scanning right-to-left.
     arr [4,2,2,8] → freq{2:2, 4:1, 8:1} → output [2,2,4,8]
   STABLE (when built with prefix + right-to-left placement). Only for integers in
     a small known range [lo..hi]; hand-write O(n+k) beats O(n log n).
 - When to use which:
     already-sorted / nearly-sorted small input  → insertion sort
     swaps are very expensive, tiny arrays        → selection sort
     guaranteed worst-case time matters, stability matters → merge sort
     average case speed matters, in-place wanted  → quick sort with random pivot
     small integer keys in a known range          → counting sort
     teaching/proof that naive comparison sorts are O(n²) → bubble sort

 🧠 LOGIC — STEP BY STEP: (pure English with WHY)

 BUBBLE SORT (basic):
   1. Run n-1 passes over the array. WHY n-1? After pass k the k largest elements
      are already parked at the end, they need no more attention.
   2. In pass i compare every adjacent pair a[j] and a[j+1] for j in [0, n-i-1).
   3. Swap whenever a[j] > a[j+1], pushing the bigger value one step right. WHY?
      The largest value of the remaining window "bubbles" up to position n-i-1.
   4. After all passes the last unsorted window has size 1 → array is sorted.
   OPTIMIZED version adds a `swapped` flag; if a whole pass makes zero swaps the
   array is already sorted → break early (WHY: no further work can help).

 SELECTION SORT:
   1. For each index i from 0 to n-2: treat a[i..n-1] as the unsorted part.
   2. Scan the unsorted part tracking minIdx = index of the smallest value.
      WHY minIdx (not value)? We must know WHERE the minimum sits to swap it.
   3. Swap a[i] with a[minIdx]. The element at i is now final. WHY? It is the
      smallest of the unsorted part, so nothing after it can be smaller.
   4. Shrink the unsorted part (i++) and repeat.

 INSERTION SORT:
   1. Start from i=1: the prefix a[0..i-1] is already sorted (single element = sorted).
   2. Save key = a[i]. Shift every element a[j] (j from i-1 down) that is > key one
      position right. WHY shifting instead of swapping? It creates a gap and avoids
      many swaps — shifting is a single write per element.
   3. Insert key into the gap at j+1. The prefix a[0..i] is now sorted.
   4. i++ and repeat until i == n. WHY does it stop there? Every element is placed.

 MERGE SORT:
   1. If the segment has 1 (or 0) elements, return — a single element is already
      sorted (this is the BASE CASE that stops recursion).
   2. mid = (lo+hi)/2; recurse on a[lo..mid] and a[mid+1..hi]. WHY split exactly
      halves? So the "merge" work per level is even and the recursion depth is log₂n.
   3. MERGE: copy the two halves into temp arrays L and R. Walk with two pointers,
      always copying the smaller head (why? that produces sorted output in one pass),
      then append leftovers. Copy back into a[lo..hi].
   4. The recursion tree has log₂n levels; every level merges O(n) total.

 QUICK SORT (Lomuto partition):
   1. Base case: segment size ≤ 1 → done.
   2. Choose pivot = a[hi] (last element). WHY the last element? Lomuto's convention
      keeps code simple — the pivot is scanned over by the loop, and the left zone
      boundary pointer `i` marks where small elements accumulate.
   3. PARTITION: i = lo-1; for j from lo to hi-1: if a[j] <= pivot, increment i and
      swap a[i] with a[j]. WHY the <= boundary? To make the partition stable-ish and
      deterministic; all elements ≤ pivot go left of the final pivot position.
   4. Swap a[i+1] with pivot so it sits between the "small" and "big" zones — the
      pivot is now in its FINAL position, no element needs to cross it again.
   5. Recurse on the left segment a[lo..p-1] and right segment a[p+1..hi].
   WHY random pivot? On already-sorted input, a fixed first/last pivot creates one
      empty side every time → n levels of recursion → O(n²). A random pivot makes the
      bad split astronomically unlikely → expected O(n log n).

 COUNTING SORT (with negative support via offset):
   1. Find lo = minimum and hi = maximum of the array. Range k = hi - lo + 1.
   2. Make freq of size k; for each x, freq[x-lo]++ (this is the "tally" step, O(n),
      and the offset lo is why negatives work).
   3. Prefix sums: freq[i] += freq[i-1]. WHY prefix? freq[i] now equals the LAST
      output index reachable by key i+lo → lets us place elements from the back,
      which keeps the sort STABLE.
   4. BUILD OUTPUT: scan the array right → left; for x, pos = freq[x-lo]-1, out[pos]=x,
      then freq[x-lo]--. WHY right→left? It reverses nothing — placing from the end
      preserves the original order of EQUAL keys (the stability note).
   5. Copy out back into a.

 VISUAL WALKTHROUGH:

  BUBBLE sort — pass 1 on [5,1,4,2,8]:
    start      [5, 1, 4, 2, 8]
    j=0 swap   [1, 5, 4, 2, 8]
    j=1 swap   [1, 4, 5, 2, 8]
    j=2 swap   [1, 4, 2, 5, 8]
    j=3 no     [1, 4, 2, 5, 8]    8 (largest) is parked ✔
    pass 2 →   [1, 2, 4, 5, 8]    → sorted

  INSERTION shifting (key beam):
    [5, 1, 4, 2, 8]
    i=1 key=1:  [_, 5, 4, 2, 8]  shift 5 → [1, 5, 4, 2, 8]
    i=2 key=4:  1 < 4 → insert → [1, 4, 5, 2, 8]
    i=3 key=2:  shift 5, shift 4 → [1, 2, 4, 5, 8]
    i=4 key=8:  no shift → [1, 2, 4, 5, 8]

  MERGE tree (divide then conquer):
                  [38,27,43,3]
                /            \
          [38,27]            [43,3]
          /    \             /    \
       [38]   [27]        [43]   [3]
          \    /             \    /
          [27,38]           [3,43]
                \            /
              [3,27,38,43]      ← merge two sorted halves with two pointers

 DRY RUN:

  BUBBLE SORT [5,1,4,2,8] — all passes (naive, no early exit):
    Pass 1 (i=0, j=0..3):  5>1→swap [1,5,4,2,8]
                            5>4→swap [1,4,5,2,8]
                            5>2→swap [1,4,2,5,8]
                            5>8? no            → [1,4,2,5,8]
    Pass 2 (i=1, j=0..2):  1>4? no
                            4>2→swap [1,2,4,5,8]
                            4>5? no            → [1,2,4,5,8]
    Pass 3 (i=2, j=0..1):  1>2? no
                            2>4? no            → [1,2,4,5,8]
    Pass 4 (i=3, j=0):     1>2? no             → [1,2,4,5,8]  ✔ sorted
    comparisons = 4+3+2+1 = 10 = n(n-1)/2 ; swaps = 6

  MERGE SORT [38,27,43,3]:
    split:      [38,27,43,3]
                [38,27] | [43,3]
                [38]|[27] | [43]|[3]
    merge:      [27,38] | [3,43]        (compare heads, smaller first)
                [3,27,38,43]            (two-pointer merge)  ✔ sorted
    3 splits = log₂4 levels; each level merges total 4 elements → 4·(log₂4)=8 ops ≈ O(n log n)

 TIME COMPLEXITY CALCULATION:
 - BUBBLE (basic) — worst & average: pass i does (n-i-1) comparisons.
      T(n) = Σ_(i=0)^(n-2) (n-1-i)  =  (n-1) + (n-2) + ... + 2 + 1
          = n(n-1)/2  → O(n²).   Best case (already sorted, basic version) still
      runs all passes → O(n²); OPTIMIZED flag version stops after 1 pass → O(n).
 - SELECTION — always (n-1-i) scans:
      T(n) = Σ_(i=0)^(n-2) (n-1-i)  =  n(n-1)/2  → O(n²)  (both best & worst; the
      scan never short-circuits, swaps are few but comparisons dominate).
 - INSERTION — worst & average: for each i, up to i shifts:
      T(n) = Σ_(i=1)^(n-1) i  =  1+2+...+(n-1)  =  n(n-1)/2  → O(n²).
      BEST: sorted input → every key makes exactly 1 comparison and 0 shifts,
      loop runs n-1 times → T(n) = n-1 → O(n).
 - MERGE — recurrence: T(n) = 2·T(n/2) + O(n); merge costs O(n).
      Tree of T(n/2) splits has log₂n levels; every level merges n elements total:
      T(n) = n·log₂n → O(n log n). (Master theorem case a=2, b=2, d=1 → O(n log n).)
 - QUICK — best & average: balanced splits T(n) = 2·T(n/2) + O(n) → O(n log n).
      WORST: already-sorted array with fixed first/last pivot → one side empty:
      T(n) = T(n-1) + T(0) + O(n) = T(n-1) + O(n) → 1+2+...+n = O(n²).
      RANDOM pivot: every order equally likely as pivot → expected balanced split
      → expected O(n log n); a bad split collapses to O(n²) only with tiny chance.
 - COUNTING — tally O(n) + prefix sums O(k) + output O(n):
      T(n) = n + k + n  =  O(n + k).   Linear when k = O(n).
 → Time Complexity =
      Bubble: Best O(n) (optimized) / O(n²) otherwise | Avg & Worst O(n²)
      Selection: O(n²) always            | Insertion: Best O(n) | Avg & Worst O(n²)
      Merge: O(n log n) always           | Quick: Best/Avg O(n log n), Worst O(n²)
      Counting: O(n + k)

 SPACE COMPLEXITY CALCULATION:
 - Bubble / Selection / Insertion: only temp variables + the swap slot → O(1) in-place.
 - Merge: two temp arrays L+R sized ~n at the deepest merge + O(log n) call stack;
      stack is dwarfed by aux → O(n) total auxiliary space.
 - Quick: sorts in place (partition swaps inside the array) → O(1) per call, but
      recursion depth is O(log n) average (balanced) → space O(log n). Worst-case
      depth O(n) on bad splits (fixed pivot on sorted input).
 - Counting: freq array of size k + output array of size n → O(n + k).
 → Space Complexity =
      Bubble/Selection/Insertion: O(1) | Merge: O(n) | Quick: O(log n) avg
      Counting: O(n + k)

 APPROACH COMPARISON: (Algorithm | Best | Avg | Worst | Space | Stable | When to use)
 ┌──────────────┬─────────────┬─────────────┬─────────────┬───────────┬─────────┬────────────────────────────────┐
 │ Algorithm    │ Best        │ Average     │ Worst       │ Space     │ Stable  │ When to use                   │
 ├──────────────┼─────────────┼─────────────┼─────────────┼───────────┼─────────┼────────────────────────────────┤
 │ Bubble       │ O(n) opt    │ O(n²)       │ O(n²)       │ O(1)      │ Yes     │ Teaching / tiny inputs        │
 │ Selection    │ O(n²)       │ O(n²)       │ O(n²)       │ O(1)      │ No      │ Fewest swaps; small arrays    │
 │ Insertion    │ O(n)        │ O(n²)       │ O(n²)       │ O(1)      │ Yes     │ Nearly-sorted data; online    │
 │ Merge        │ O(n log n)  │ O(n log n)  │ O(n log n)  │ O(n)      │ Yes     │ Stable sort; guaranteed time  │
 │ Quick (ran)  │ O(n log n)  │ O(n log n)  │ O(n²)       │ O(log n)  │ No      │ Fastest in practice; in-place │
 │ Counting     │ O(n + k)    │ O(n + k)    │ O(n + k)    │ O(n + k)  │ Yes     │ Small int keys in known range │
 └──────────────┴─────────────┴─────────────┴─────────────┴───────────┴─────────┴────────────────────────────────┘
*/
#include <iostream>
#include <vector>

std::vector<int>::size_type cmpCount = 0;   // global comparison counter (demo only)
std::vector<int>::size_type swapCount = 0;  // global swap counter (demo only)

void resetCounters() { cmpCount = 0; swapCount = 0; }

// print helper — prints array as [a, b, c]
void printArr(const std::vector<int>& a) {
    std::cout << "[";
    for (std::vector<int>::size_type i = 0; i < a.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << a[i];
    }
    std::cout << "]";
}

// ---------- BUBBLE SORT (basic) ----------
void bubbleSort(std::vector<int>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {           // n-1 passes
        for (int j = 0; j < n - i - 1; j++) {   // window shrinks each pass
            cmpCount++;
            if (a[j] > a[j + 1]) {              // out of order? swap
                std::swap(a[j], a[j + 1]);
                swapCount++;
            }
        }
    }
}

// ---------- BUBBLE SORT (optimized with swap flag) ----------
void optimizedBubble(std::vector<int>& a, int& passes) {
    int n = (int)a.size();
    passes = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;                   // swap flag: track any swap this pass
        for (int j = 0; j < n - i - 1; j++) {
            cmpCount++;
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapCount++;
                swapped = true;                 // pass did work → maybe more to do
            }
        }
        passes++;
        if (!swapped) break;                    // already sorted → no more passes
    }
}

// ---------- SELECTION SORT ----------
void selectionSort(std::vector<int>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;                         // assume current head is the min
        for (int j = i + 1; j < n; j++) {       // scan the unsorted part
            cmpCount++;
            if (a[j] < a[minIdx]) minIdx = j;   // track INDEX of the true min
        }
        if (minIdx != i) {                      // place min at front of unsorted part
            std::swap(a[i], a[minIdx]);
            swapCount++;
        }
    }
}

// ---------- INSERTION SORT ----------
void insertionSort(std::vector<int>& a) {
    int n = (int)a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];                         // card to be placed
        int j = i - 1;
        while (j >= 0) {                        // shift bigger cards right
            cmpCount++;
            if (a[j] > key) { a[j + 1] = a[j]; j--; }
            else break;                         // found its slot
        }
        a[j + 1] = key;                         // insert key into the gap
    }
}

// ---------- MERGE SORT (helper merge + recursive sort) ----------
void merge(std::vector<int>& a, int lo, int mid, int hi) {
    int n1 = mid - lo + 1;                      // size of left half
    int n2 = hi - mid;                          // size of right half
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[lo + i];      // copy left half
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j]; // copy right half

    int i = 0, j = 0, k = lo;                   // two-pointer + write pointer
    while (i < n1 && j < n2) {                  // merge while both halves remain
        cmpCount++;
        if (L[i] <= R[j]) a[k++] = L[i++];      // left head smaller → take it first
        else              a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];             // drain leftover left
    while (j < n2) a[k++] = R[j++];             // drain leftover right
}

void mergeSort(std::vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;                       // base case: 1 or 0 elements → sorted
    int mid = lo + (hi - lo) / 2;               // WHY lo + (hi-lo)/2? no overflow
    mergeSort(a, lo, mid);                      // sort left half
    mergeSort(a, mid + 1, hi);                  // sort right half
    merge(a, lo, mid, hi);                      // conquer: merge the two sorted halves
}

void mergeSort(std::vector<int>& a) {
    if (a.empty()) return;
    mergeSort(a, 0, (int)a.size() - 1);
}

// ---------- QUICK SORT (Lomuto partition) ----------
int lomutoPartition(std::vector<int>& a, int lo, int hi) {
    int pivot = a[hi];                          // Lomuto picks the last element
    int i = lo - 1;                             // i marks end of the "small" zone
    for (int j = lo; j < hi; j++) {
        cmpCount++;
        if (a[j] <= pivot) {                    // element belongs to small zone
            i++;
            std::swap(a[i], a[j]);              // grow the small zone
        }
    }
    std::swap(a[i + 1], a[hi]);                 // pivot → between small & big zones
    return i + 1;                               // pivot's final position
}

void quickSort(std::vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;                       // base case
    int p = lomutoPartition(a, lo, hi);         // pivot lands in place
    quickSort(a, lo, p - 1);                    // sort the left side
    quickSort(a, p + 1, hi);                    // sort the right side
}

void quickSort(std::vector<int>& a) {
    if (a.empty()) return;
    quickSort(a, 0, (int)a.size() - 1);
}

// ---------- COUNTING SORT (stable; handles negatives via offset) ----------
void countingSort(std::vector<int>& a, int lo, int hi) {
    if (a.empty()) return;
    int range = hi - lo + 1;                    // size of value universe (offset for negatives)
    std::vector<int> freq(range, 0);
    for (int x : a) freq[x - lo]++;             // tally frequencies: x-lo maps x to [0,range)

    for (int i = 1; i < range; i++) freq[i] += freq[i - 1];  // prefix sums → last index of each key

    std::vector<int> out(a.size());             // output buffer (why? stability)
    for (int i = (int)a.size() - 1; i >= 0; i--) {           // right → left keeps order of equals
        int pos = freq[a[i] - lo] - 1;          // final position of this element
        out[pos] = a[i];
        freq[a[i] - lo]--;                      // next equal key goes one slot earlier
    }
    a = out;
}

// =========================== DEMO ===========================
int main() {
    std::cout << "========== SORTING ALGORITHMS — DEMO ==========\n\n";

    // --- fixed array for swap/step counters ---
    resetCounters();
    std::vector<int> a = {5, 1, 4, 2, 8};
    std::cout << "1) Bubble Sort      before "; printArr(a);
    bubbleSort(a);
    std::cout << "  →  after "; printArr(a);
    std::cout << "\n      counters: cmp = " << cmpCount << ", swaps = " << swapCount << "\n\n";

    resetCounters();
    std::vector<int> b = {5, 1, 4, 2, 8};
    int passes = 0;
    std::cout << "2) Optimized Bubble before "; printArr(b);
    optimizedBubble(b, passes);
    std::cout << "  →  after "; printArr(b);
    std::cout << "\n      counters: cmp = " << cmpCount << ", swaps = " << swapCount
              << ", passes = " << passes << "\n\n";

    resetCounters();
    std::vector<int> c = {5, 1, 4, 2, 8};
    std::cout << "3) Selection Sort   before "; printArr(c);
    selectionSort(c);
    std::cout << "  →  after "; printArr(c);
    std::cout << "\n      counters: cmp = " << cmpCount << ", swaps = " << swapCount << "\n\n";

    resetCounters();
    std::vector<int> d = {5, 1, 4, 2, 8};
    std::cout << "4) Insertion Sort   before "; printArr(d);
    insertionSort(d);
    std::cout << "  →  after "; printArr(d);
    std::cout << "\n      counters: cmp = " << cmpCount
              << " (comparisons, shifts inside) \n\n";

    std::vector<int> e = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "5) Merge Sort       before "; printArr(e);
    mergeSort(e);
    std::cout << "  →  after "; printArr(e);
    std::cout << "\n      (O(n log n) guaranteed — stable)\n\n";

    std::vector<int> f = {10, 7, 8, 9, 1, 5};
    std::cout << "6) Quick Sort (Lomuto) before "; printArr(f);
    quickSort(f);
    std::cout << "  →  after "; printArr(f);
    std::cout << "\n      (average O(n log n); random pivot avoids O(n²) worst case)\n\n";

    std::vector<int> g = {4, 2, 2, 8, 3, 3, 1};
    std::cout << "7) Counting Sort    before "; printArr(g);
    countingSort(g, 1, 8);
    std::cout << "  →  after "; printArr(g);
    std::cout << "\n      (freq + prefix + right-to-left build → stable, O(n + k))\n\n";

    // --- edge cases ---
    std::cout << "========== EDGE CASES ==========\n";

    std::vector<int> emp;
    std::cout << "Empty arr:        "; printArr(emp); std::cout << " → ";
    bubbleSort(emp); selectionSort(emp); insertionSort(emp); mergeSort(emp); quickSort(emp);
    printArr(emp); std::cout << "  (all sorts no-op)\n";

    std::vector<int> one = {7};
    std::cout << "Single element:   "; printArr(one); std::cout << " → ";
    mergeSort(one); quickSort(one); countingSort(one, 7, 7);
    printArr(one); std::cout << "  (base cases return immediately)\n";

    resetCounters();
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::cout << "Already sorted:   "; printArr(sorted); std::cout << " → ";
    int p2 = 0; optimizedBubble(sorted, p2);
    printArr(sorted);
    std::cout << "  optimizedBubble: cmp = " << cmpCount << ", passes = " << p2
              << "  (flag stops after pass 1)\n";

    resetCounters();
    std::vector<int> rev = {5, 4, 3, 2, 1};
    std::cout << "Reversed input:   "; printArr(rev); std::cout << " → ";
    bubbleSort(rev);
    printArr(rev);
    std::cout << "  bubble: swaps = " << swapCount
              << "  (worst case n(n-1)/2 = 10)\n";

    std::vector<int> dup = {3, 3, 1, 2, 2};
    std::cout << "Duplicates:       "; printArr(dup); std::cout << " → ";
    insertionSort(dup);
    printArr(dup); std::cout << "  (stable — equal keys keep original order)\n";

    std::vector<int> neg = {-4, 2, -1, 0, -4, 2};
    std::cout << "Negatives:        "; printArr(neg); std::cout << " → ";
    countingSort(neg, -4, 2);
    printArr(neg); std::cout << "  (offset lo = -4 makes keys non-negative)\n";

    std::cout << "\nAll demo sorts complete ✔\n";
    return 0;
}