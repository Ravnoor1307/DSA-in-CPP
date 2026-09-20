/*
═══════════════════════════════════════════════
 ALGORITHMIC COMPLEXITY CLASSES
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Your friend gives you a phone book and asks three questions.
 "What is the first name?" — you read page 1, done (O(1)). "Is 'Zara'
 in the book?" — the book is sorted, so you flip to the middle and
 discard half each time (O(log n)). "Let me read every entry aloud"
 — you read all n entries (O(n)). "Sort all names alphabetically"
 — your lazy method ends up comparing every pair (O(n²)). "Try every
 possible ordering of all names" — that is O(n!), and you promptly
 give up. Exactly the same classes govern all computer algorithms.

 📖 THEORY: (pure English, formal)

 A complexity class groups algorithms by how their running time grows
 as a function of input size n. Each class corresponds to a canonical
 algorithm and a characteristic code pattern.

  ┌────────────┬──────────────────────┬────────────────────────────────┐
  │   Class    │  Representative algo │        Signature code pattern  │
  ├────────────┼──────────────────────┼────────────────────────────────┤
  │ O(1)       │ array[i] access      │ single direct step, no loop    │
  │ O(log₂ n)  │ binary search        │ halve the search space/loop    │
  │ O(n)       │ linear search        │ single loop over all n items   │
  │ O(n log n) │ merge sort / heap    │ divide in halves, merge O(n)   │
  │ O(n²)      │ bubble / selection   │ two nested loops over n        │
  │ O(n³)      │ matrix multiply      │ three nested loops over n      │
  │ O(2ⁿ)      │ subset generation    │ recursive include/exclude      │
  │ O(n!)      │ permutations         │ recursive swap every position  │
  └────────────┴──────────────────────┴────────────────────────────────┘

 KEY POINTS:
 - Worst case: assume the worst input (search hits the end, pivot is min).
 - Same class can contain very different algorithms (bubble & selection are both O(n²)).
 - A class is a guarantee about the WORST case, not the average.
 - Recursion is NOT automatically exponential: binary search is recursive + O(log n).

 ASCII CLASS MAP:
   fastest                                   slowest
   O(1)  <  O(log n)  <  O(n)  <  O(n log n)  <  O(n²)  <  O(2ⁿ)  <  O(n!)
     │          │           │          │             │          │          │
  arr[i]   binarySearch  linear   mergeSort    bubbleSort  naiveFib  permute
             1 half/sec    N steps   N-logN        N² steps   doubling   N×(N-1)…

 WHEN TO USE:
 - O(1)  → hash table lookup, direct index access — always prefer.
 - O(log n) → search in sorted data — extremely scalable.
 - O(n)  → scan-once problems (max, sum, count).
 - O(n log n) → general-purpose sorting (merge, heap, STL sort).
 - O(n²) → small inputs, simple sorts, brute-force checks.
 - O(2ⁿ)/O(n!) → only tiny n; better: memoisation/pruning.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Identify the dominant operation (compares, swaps, calls).
   WHY: Complexity is counted in dominant ops; discipline comes from
        knowing which op you're paying for.

 Step 2: Count how many times it executes as a function of n.
   WHY: The count IS the complexity. Two nested loops → Σ 1..n = n(n+1)/2.

 Step 3: Drop constants and lower-order terms.
   WHY: Big-O cares about growth, not exact counts:
        n²/2 + 3n → O(n²).

 Step 4: For the demo, instrument every algorithm with a step counter.
   WHY: Empirically measuring step counts turns abstract O() into
        numbers you can hold: bubble(1000) ≈ 500k steps vs merge ≈ 10k.

 Step 5: Compare naive recursive Fibonacci with iterative DP Fibonacci.
   WHY: It is the classic demonstration of O(2ⁿ) vs O(n) on one problem.

 VISUAL WALKTHROUGH:

  Same job "find a value", different preconditions → different classes:
   ┌──────────────┬─────────────────────┬───────────────┬────────────────┐
   │  Data        │  How we search      │  Steps @n=16  │  Class         │
   ├──────────────┼─────────────────────┼───────────────┼────────────────┤
   │ array        │  arr[0] (fixed)     │      1        │  O(1)          │
   │ sorted array │  binary search      │     4-5       │  O(log₂ n)     │
   │ any array    │  linear scan        │     ≤16       │  O(n)          │
   └──────────────┴─────────────────────┴───────────────┴────────────────┘

  Fibonacci call trees (n = 5):
   Naive (every call re-explores):        Memoised (each value ONCE):
           fib(5)                                  fib(5)
          /      \                               /        \
       fib(4)   fib(3)                     fib(4)        fib(3)
       /    \    /   \                     /      \      /
    fib(3) f(2) f(2) f(1)              fib(3)  fib(2) -------------
     /  \   / \   /\                  /      \
  f(2) f(1) f(1)f(0)…               fib(2)  fib(1)
   / \
 f(1) f(0)
   15 nodes total                     just 6 nodes, each computed once

 DRY RUN (n = 5):
  Naive fib(5) = fib(4)+fib(3)
    = (fib(3)+fib(2)) + (fib(2)+fib(1))
    = ((fib(2)+fib(1))+(fib(1)+fib(0))) + ((fib(1)+fib(0))+1)
    = (((1+1)+1)+(1+0)) + ((1+0)+1) = 3 + 2 = 5
  Function calls: fib(5)=1, f(4)=1, f(3)=2, f(2)=3, f(1)=5, f(0)=3 → 15 calls.
  DP fib(5): compute f(2)=1, f(3)=2, f(4)=3, f(5)=5 → 4 loop iterations, 4 steps.
  Ratio at n=30: naive ≈ 2.69 million calls vs DP = 29 steps → ~93,000×.

 TIME COMPLEXITY CALCULATION:
  NAIVE FIBONACCI:
  T(n) = T(n-1) + T(n-2) + O(1)      (two sub-calls + one addition)
  Characteristic equation: x² = x + 1 → x = (1+√5)/2 ≈ 1.618 (golden ratio φ)
  → T(n) = Θ(φⁿ). Since φ < 2, Θ(φⁿ) ⊆ O(2ⁿ).
  Commonly written O(2ⁿ); precisely Θ(1.618ⁿ).
  Emprically: call count = 2·F(n+1) − 1.
   n=10 → 177 calls; n=20 → 21,891; n=30 → 2,692,537; n=40 → 331,160,281.
  DP FIBONACCI:
  Loop runs from i=2 to n → (n−1) iterations, O(1) work each.
 → Time Complexity: naive O(2ⁿ) vs DP O(n)

 SPACE COMPLEXITY CALCULATION:
  NAIVE: recursion depth = n (each call nests one deeper) → call stack O(n).
  DP: only 3 scalar variables (prev2, prev1, cur) → O(1) auxiliary.
 → Space Complexity: naive O(n) stack vs DP O(1)

 APPROACH COMPARISON:
  ┌──────────────┬──────────────────┬──────────────────┬──────────────────┐
  │ Aspect       │  Naive recursive │  Iterative DP    │  Winner          │
  ├──────────────┼──────────────────┼──────────────────┼──────────────────┤
  │ Time (n=35)  │ ~29.9M calls     │ ~34 steps        │  DP ≈ 900k×      │
  │ Space        │ O(n) call stack  │ O(1)             │  DP              │
  │ Readability  │ mirrors math     │ simple loop      │  Draw            │
  │ Risk         │ stack overflow   │ none             │  DP              │
  └──────────────┴──────────────────┴──────────────────┴──────────────────┘
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ============ STEP-COUNTERS FOR EACH COMPLEXITY CLASS ============

// ---- O(1): direct array access — kitne bhi bade array ho, same 1 step ----
long long accessCounter = 0;
long long accessO1(int arr[]) {
    accessCounter++;                 // ek hi step, n pe depend nahi
    return arr[0];
}

// ---- O(log n): binary search — har step mein search space half ----
long long binarySearchSteps(int arr[], int n, int key) {
    int lo = 0, hi = n - 1;
    long long s = 0;
    while (lo <= hi) {
        s++;                         // har iteration ek step
        int mid = lo + (hi - lo) / 2; // overflow-safe mid
        if (arr[mid] == key) return s;      // mil gaya — worst case tak loop
        if (arr[mid] < key) lo = mid + 1;   // right half
        else hi = mid - 1;                  // left half
    }
    return s;                        // badluck case: s = log2(n)+1 round karega
}

// ---- O(n): linear search — worst case poori array scan ----
long long linearSearchSteps(int arr[], int n, int key) {
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s++;                         // har element check kiya
        if (arr[i] == key) return s;
    }
    return s;                        // worst case: n steps
}

// ---- O(n log n): merge sort with counter ----
long long mergeSteps = 0;
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int* L = new int[n1];            // temp left array
    int* R = new int[n2];            // temp right array
    for (int i = 0; i < n1; i++) { mergeSteps++; L[i] = arr[l + i]; }
    for (int j = 0; j < n2; j++) { mergeSteps++; R[j] = arr[m + 1 + j]; }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        mergeSteps++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) { mergeSteps++; arr[k++] = L[i++]; }
    while (j < n2) { mergeSteps++; arr[k++] = R[j++]; }
    delete[] L;                      // temp free — space O(n) transient
    delete[] R;
}
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;         // divide
    mergeSort(arr, l, m);            // conquer left  → T(n/2)
    mergeSort(arr, m + 1, r);        // conquer right → T(n/2)
    merge(arr, l, m, r);             // combine       → O(n)
}

// ---- O(n²): bubble sort with counter ----
long long bubbleSteps = 0;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)          // n-1 pas
        for (int j = 0; j < n - 1 - i; j++) { // har pas mein bubble upar
            bubbleSteps++;                    // har comparison count
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
}

// ---- O(2ⁿ): subset generation — har element: include ya exclude ----
long long subsetNodes = 0;
void genSubsets(int idx, int n) {
    subsetNodes++;                    // har call ek node
    if (idx == n) return;             // base: sab elements decide ho gaye
    genSubsets(idx + 1, n);           // 'exclude' branch
    genSubsets(idx + 1, n);           // 'include' branch → 2 branches/node
}
// nodes(total) = 2^(n+1) − 1  ≈ O(2ⁿ)

// ---- O(n!): permutations — har position pe n choices, phir n-1, phir n-2 ----
long long permNodes = 0;
void permute(int idx, int n) {
    permNodes++;                      // har state ek node
    if (idx == n) return;
    for (int i = idx; i < n; i++)
        permute(idx + 1, n);          // n × (n-1) × … branches
}
// leaves = n! ; total nodes = Σ k=0..n (n!/(n−k)!) ≈ e·n! ≈ O(n!)

// ============ FIBONACCI: naive recursion vs iterative DP ============

long long naiveCalls = 0;
long long fibNaive(int n) {
    naiveCalls++;                     // har recursive call count karo
    if (n <= 1) return n;             // base case
    return fibNaive(n - 1) + fibNaive(n - 2); // do recursive calls → 2ⁿ tree
}

long long fibDP(int n) {              // iterative dynamic programming
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1, cur = 1;
    for (int i = 2; i <= n; i++) {    // (n-1) iterations, O(1) each
        cur = prev1 + prev2;          // sirf 3 variables — space O(1)
        prev2 = prev1;
        prev1 = cur;
    }
    return cur;
}

// ek n ke liye dono counter reset karke result + steps print karta hai
void compareFib(int n) {
    naiveCalls = 0;
    long long r1 = fibNaive(n);
    long long naiveN = naiveCalls;

    long long r2 = fibDP(n);

    printf("│ %4d │ %18lld │ %14lld │ %26lld │",
           n, r1, naiveN, (long long)(n - 1));
    cout << "  match: " << (r1 == r2 ? "YES" : "NO") << " │" << endl;
}

int main() {
    cout << "══════════════════════════════════════════════════════════════" << endl;
    cout << "   COMPLEXITY CLASS COUNTERS — SAME PROBLEM, DIFFERENT CLASS" << endl;
    cout << "══════════════════════════════════════════════════════════════" << endl;

    // ---------- O(1) ----------
    {
        int a[] = {7, 9, 3, 5, 11, 2};
        accessCounter = 0;
        long long v = accessO1(a);   // aadha crore elements ho, phir bhi 1 step
        cout << "\n[1] O(1)   — arr[0] access: value=" << v
             << ", steps=" << accessCounter << " (n=6, but ANY n → 1 step)" << endl;
    }

    // ---------- O(log n) ----------
    {
        // sorted array for binary search
        int a[1024];
        for (int i = 0; i < 1024; i++) a[i] = i;
        long long stepsBS = binarySearchSteps(a, 1024, 1000); // worst-case-ish key
        // linearSearch comparison
        long long stepsLS = linearSearchSteps(a, 1024, 1000);
        printf("[2] O(log n) vs O(n) on n=1024:  binarySearch steps = %lld,  linearSearch steps = %lld\n",
               stepsBS, stepsLS);
        printf("    log2(1024)=10 → binary search ≤ 11 comparisons, linear ≤ 1024.\n");
    }

    // ---------- O(n log n) vs O(n²) ----------
    {
        int n = 1024;
        int* a = new int[n];
        int* b = new int[n];
        // ulta-sorted banate hain taaki worst-case sort ho
        for (int i = 0; i < n; i++) b[i] = a[i] = n - i; // descending → worst case

        mergeSteps = 0;
        mergeSort(a, 0, n - 1);
        long long ms = mergeSteps;

        bubbleSteps = 0;
        bubbleSort(b, n);
        long long bs = bubbleSteps;

        printf("[3] Sorting n=1024 (descending = worst case):\n");
        printf("    mergeSort steps = %6lld → O(n log n)\n", ms);
        printf("    bubbleSort steps = %8lld → O(n²)\n", bs);
        printf("    ratio ≈ %.1f× (merge sort ~%d× faster)\n",
               (double)bs / (double)ms, (int)(bs / ms));
        delete[] a;
        delete[] b;
    }

    // ---------- O(2ⁿ) subsets ----------
    {
        int n = 20;
        subsetNodes = 0;
        genSubsets(0, n);
        long long expected = (1LL << (n + 1)) - 1; // 2^(n+1)−1
        printf("[4] Subsets for n=20: nodes=%lld, expected 2^(n+1)−1=%lld → O(2ⁿ)\n",
               subsetNodes, expected);
    }

    // ---------- O(n!) permutations ----------
    {
        int n = 8;
        permNodes = 0;
        permute(0, n);
        long long expected = 109601; // Σ n!/(n−k)! for n=8 (e·5040−1 twinning)
        printf("[5] Permutations for n=8: nodes=%lld (n!=40320) → O(n!)\n", permNodes);
        printf("    (leaves=%lld!, total states ≈ e·n! ≈ %lld)\n", (long long)n, expected);
    }

    // ---------- FIBONACCI: the big gun ----------
    cout << "\n═══════════ NAIVE RECURSIVE (O(2ⁿ)) vs ITERATIVE DP (O(n)) FIBONACCI ═══════════" << endl;
    printf("┌──────┬────────────────────┬──────────────────┬────────────────────────┬────────────┐\n");
    printf("│   n  │   Fib(n) (answer)  │  naive call count │  DP loop steps (n−1)  │  answers   │\n");
    printf("├──────┼────────────────────┼──────────────────┼────────────────────────┼────────────┤\n");
    compareFib(10);
    compareFib(20);
    compareFib(25);
    compareFib(30);
    compareFib(35);
    printf("└──────┴────────────────────┴──────────────────┴────────────────────────┴────────────┘\n");
    cout << "\n  n=35: naive = 29,860,703 calls ; DP = 34 steps → ~878,000× faster.\n";
    cout << "  Future problem? Naive doubles per +1 of n (2ⁿ); DP grows by just +1 step per +1 of n.\n";

    return 0;
}