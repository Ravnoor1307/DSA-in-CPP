/*
═══════════════════════════════════════════════
 TASK SET — TIME COMPLEXITY (counting operations as a function of n)
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A flight booking site must check whether an
 entered PNR exists among n bookings. The simplest way checks one booking
 after another (linear search). Before choosing this approach for 10
 million records, you must know HOW MANY comparisons it performs as n
 grows — that count, not our stopwatch, is its time complexity.

🧠 HOW TO SOLVE: Instrument the code with a `comparisons`/`opCount`
 counter, run it at a few input sizes, and confirm the printed count
 matches a derived formula f(n). Then reduce f(n) to its growth class.

 Each task has TWO parts:
   (a) ANALYZE: full mathematical derivation of the operation count.
   (b) IMPLEMENT: compile-ready code with a live counter.

 TASK 1: Linear search at three n sizes — print count vs n.
   (a) ANALYZE: prove worst-case comparisons = n (every element checked),
       best = 1, average = (n+1)/2. Write the sum '1+2+...+n' working.
   (b) IMPLEMENT: for n = 10, 100, 1000 build arrays, search for an
       ABSENT key (worst case), print n | comparisons. Ratio
       comparisons/n should be exactly 1.
   💡 HINT: absent key se loop kabhi early return nahi karta → poora n
            check hota hai.
   ✏️ STARTER CODE:
       long long linearSearch(int a[], int n, int key, long long& cmp) {
           cmp = 0;
           for (int i = 0; i < n; i++) { cmp++; if (a[i] == key) return i; }
           return -1;
       }

 TASK 2: Count comparisons of findMax (n − 1, always).
   (a) ANALYZE: loop i=1..n-1, 1 comparison each → exactly n−1
       comparisons; show it does NOT depend on where the max sits.
   (b) IMPLEMENT: compare arrays {5,1,1,1,...} (max first) vs {1,...,5}
       (max last) — both must print n−1 comparisons.
   💡 HINT: max ka position matter nahi karta — candidate ko tabhi pata
            chalta hai jab sab dekh liya.
   ✏️ STARTER CODE:
       int findMaxCount(int a[], int n, long long& cmp) { }  // TODO: 1 comparison per iteration

 TASK 3: Duplicate check with nested loops — the triangle sum.
   (a) ANALYZE: outer i=0..n-2, inner j=i+1..n-1 → total comparisons =
       sum_{i=0}^{n-2}(n-1-i) = (n-1)+(n-2)+...+1 = n(n-1)/2 → O(n²).
       Show the full Gauss working.
   (b) IMPLEMENT: for n = 100 count comparisons of hasDuplicate (exact
       count = 4950) and print: predicted n(n-1)/2 vs actual.
   💡 HINT: Gauss — (n-1) + (n-2) + ... + 2 + 1 = (n-1)*n/2.
   ✏️ STARTER CODE:
       bool hasDuplicate(int a[], int n, long long& cmp) {
           cmp = 0;
           for (int i = 0; i < n - 1; i++)
               for (int j = i + 1; j < n; j++) { cmp++; if (a[i] == a[j]) return true; }
           return false;
       }

 TASK 4: Exact operation count of sum-of-array (f(n) = 3n + 4).
   (a) ANALYZE: derive f(n) including initialization, the n+1 tests, and
       n additions + n increments. Reduce to O(n).
   (b) IMPLEMENT: print n | 3n+4 | actual for n = 1, 10, 1000 and show
       the rows match exactly.
   💡 HINT: i<n test (n+1) baar, body n baar, i++ n baar.
   ✏️ STARTER CODE:
       long long arrSum(int a[], int n, long long& op) { }  // TODO: counter lagao

 TASK 5: First-element check vs full scan — different counts, same class.
   Problem: search key in array but you may STOP after checking if key >
   all remaining (array is SORTED ascending). If key ≤ a[i] stop.
   (a) ANALYZE: worst case still n comparisons (key > everything) → O(n).
       Show the class does not become "better than linear" just because
       early exit helps some inputs.
   (b) IMPLEMENT: sorted array {1,3,5,7,9,...}, search key=6 → must stop
       at first element > 6 (i.e., value 7) and count those comparisons.
       Print count for n=5 and n=100,000.
   💡 HINT: arr sorted hai → a[i] > key dikhte hi loop break.
   ✏️ STARTER CODE:
       int sortedSearch(int a[], int n, int key, long long& cmp) {
           for (int i = 0; i < n; i++) { cmp++;
               if (a[i] == key) return i;
               if (a[i] > key) break;          // aage sab bade hain
           }
           return -1;
       }

 TASK 6 (HARD): Prove count/n ratio = 1 and explain "not wall-clock".
   (a) ANALYZE: for worst-case linear search derive f(n) INCLUDING the
       loop test: tests (n+1) + comparisons (n) + init/return (2) =
       2n+3 → still O(n). Argue why the RATIO comparisons/n → 1 and why
       these printed integers are IDENTICAL on every machine while elapsed
       seconds differ.
   (b) IMPLEMENT: run absent-key searches for n = 10^3, 10^4, 10^5, 10^6
       printing n | comparisons | comparisons/n (always 1) AND the chrono
       time (varies with machine/load) — together they prove "count is
       stable, seconds are not".
   💡 HINT: chrono time alag-alag aayega, par comparisons/n hamesha 1.0.
   ✏️ STARTER CODE:
       for each n: build array, auto s=now(); linearSearch(absent key);
       auto e=now(); print n, cmp, cmp/n, elapsed us.

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// TASK 1 & 6 helper
long long linearSearch(const int a[], int n, int key, long long& cmp) {
    cmp = 0;
    for (int i = 0; i < n; i++) {
        cmp++;
        if (a[i] == key) return i;
    }
    return -1;
}

// TASK 2 helper
int findMaxCount(const int a[], int n, long long& cmp) {
    cmp = 0;
    if (n <= 0) return -1;
    int m = a[0];
    for (int i = 1; i < n; i++) {
        cmp++;
        if (a[i] > m) m = a[i];
    }
    return m;
}

// TASK 3 helper
bool hasDuplicate(const int a[], int n, long long& cmp) {
    cmp = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            cmp++;
            if (a[i] == a[j]) return true;
        }
    return false;
}

// TASK 4 helper
long long arrSum(const int a[], int n, long long& op) {
    op = 0;
    int s = 0;   op++;                 // s = 0
    int i = 0;   op++;                 // i = 0
    for (; i < n; i++) {
        op++;                          // i < n test
        op++;                          // s += a[i]
        s += a[i];
        op++;                          // i++
    }
    op++;                              // last test (i == n)
    op++;                              // return
    return s;
}

// TASK 5 helper — sorted array se early exit
int sortedSearch(const int a[], int n, int key, long long& cmp) {
    for (int i = 0; i < n; i++) {
        cmp++;
        if (a[i] == key) return i;
        if (a[i] > key) break;         // sorted → aage sab > key
    }
    return -1;
}

int main() {
    // TASK 1: count vs n, worst case
    {
        cout << "T1:\n";
        int sizes[3] = {10, 100, 1000};
        for (int k = 0; k < 3; k++) {
            int n = sizes[k];
            int* a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i;      // data sorted
            long long cmp = 0;
            linearSearch(a, n, -1, cmp);               // absent key → worst
            cout << "    n=" << n << "  comparisons=" << cmp
                 << "  ratio=" << (double)cmp / n << "\n";
            delete[] a;
        }
    }

    // TASK 2: max first vs max last — both n-1 comparisons
    {
        cout << "T2:\n";
        const int n = 1000;
        int* firstMax = new int[n];
        int* lastMax  = new int[n];
        for (int i = 0; i < n; i++) { firstMax[i] = 1; lastMax[i] = 1; }
        firstMax[0] = 9999;          // max sabse pehle
        lastMax[n - 1] = 9999;       // max sabse aakhri
        long long c1 = 0, c2 = 0;
        findMaxCount(firstMax, n, c1);
        findMaxCount(lastMax, n, c2);
        cout << "    max-first comparisons=" << c1
             << "  max-last comparisons=" << c2
             << "  (both = n-1 = " << n - 1 << ")\n";
        delete[] firstMax;
        delete[] lastMax;
    }

    // TASK 3: triangle sum verification for n=100
    {
        cout << "T3: ";
        const int n = 100;
        int* a = new int[n];
        for (int i = 0; i < n; i++) a[i] = i;          // no duplicates
        long long cmp = 0;
        hasDuplicate(a, n, cmp);
        long long pred = (long long)(n - 1) * n / 2;
        cout << "predicted n(n-1)/2=" << pred
             << "  actual=" << cmp
             << "  match? " << (pred == cmp ? "YES" : "NO") << "\n";
        delete[] a;
    }

    // TASK 4: f(n) = 3n+4 rows
    {
        cout << "T4:\n";
        int nList[3] = {1, 10, 1000};
        for (int k = 0; k < 3; k++) {
            int n = nList[k];
            int* a = new int[n];
            for (int i = 0; i < n; i++) a[i] = 1;
            long long op = 0;
            arrSum(a, n, op);
            cout << "    n=" << n << "  predicted 3n+4=" << 3 * n + 4
                 << "  actual=" << op << "\n";
            delete[] a;
        }
    }

    // TASK 5: early exit on sorted array
    {
        cout << "T5:\n";
        const int n = 5;
        int a5[5] = {1, 3, 5, 7, 9};
        long long cmp = 0;
        sortedSearch(a5, n, 6, cmp);       // 6 se pehla bada = 7 (index 3)
        cout << "    n=5 key=6 → comparisons=" << cmp << "\n";
        const int big = 100000;
        int* aBig = new int[big];
        for (int i = 0; i < big; i++) aBig[i] = 2 * i + 1;   // odd numbers
        cmp = 0;
        sortedSearch(aBig, big, 99999, cmp); // aadhe se thoda pehle milega
        cout << "    n=100000 key=99999 → comparisons=" << cmp
             << "  (≈ key/2 + 1, worst still n)\n";
        delete[] aBig;
    }

    // TASK 6: count is stable, seconds are not
    {
        cout << "T6:\n";
        int sizes[4] = {1000, 10000, 100000, 1000000};
        for (int k = 0; k < 4; k++) {
            int n = sizes[k];
            int* a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i;
            long long cmp = 0;
            auto s = high_resolution_clock::now();
            linearSearch(a, n, -1, cmp);
            auto e = high_resolution_clock::now();
            double us = duration_cast<microseconds>(e - s).count();
            cout << "    n=" << n << "  cmp=" << cmp
                 << "  cmp/n=" << (double)cmp / n
                 << "  time=" << us << "us (machine dependent)\n";
            delete[] a;
        }
    }
    return 0;
}
/*
 FULL ANALYSES:

 TASK 1 — Worst case (key absent): loop checks every element, so
   comparisons = n. Best = 1. Average = (1+2+...+n)/n using Gauss:
   1+2+...+n = n(n+1)/2, divide by n → (n+1)/2 ≈ n/2. All three are
   different COUNTS but the class is O(n) — halving a constant picture
   does not change the growth. Table proofs: cmp/n = 1.0 every row.

 TASK 2 — findMax runs i from 1 to n-1 (why not 0? a[0] is the seed),
   each iteration exactly one comparison → f(n) = n-1 + O(1) → O(n).
   Independent of data: the maximum is only *known* after the whole pass,
   so the counter is identical whether the max sits at index 0 or n-1.

 TASK 3 — inner loop j=i+1..n-1 runs (n-1-i) times, summing over
   i=0..n-2: (n-1)+(n-2)+...+2+1. Pair first+last: (n-1)+1 = n,
   (n-2)+2 = n, ... there are (n-1)/2 such pairs → n(n-1)/2.
   n=100 → 99*100/2 = 4950 = the printed actual. → O(n²).

 TASK 4 — f(n) = s=0(1) + i=0(1) + tests(n+1) + bodies(n) + i++(n)
   = 3n + 4 → O(n). Rows print exactly 3n+4 for n=1,10,1000 — the
   instrumented counter is an exact mirror of the derivation.

 TASK 5 — sorted early-exit: still worst O(n) (key larger than all
   elements → full scan). It only helps average case. For key=6 in
   {1,3,5,7,9} it stops when a[i]>6 → at i=3 (value 7) with 4
   comparisons — 4 < 5, so early exit is real but the class is still O(n).

 TASK 6 — INCLUDING loop tests: tests n+1, comparisons n, init/return 2
   → f(n) = 2n+3 → O(n). comparisons/n ratio is exactly 1.0 on every
   machine — it is the TIME COMPLEXITY. The chrono microseconds column
   changes between runs/machines — that is wall-clock time, NOT the
   complexity. Counting operations is the stable, portable measure.
*/