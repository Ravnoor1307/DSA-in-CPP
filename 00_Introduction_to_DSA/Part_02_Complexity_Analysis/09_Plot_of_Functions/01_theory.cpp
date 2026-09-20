/*
═══════════════════════════════════════════════
 PLOTTING COMMON FUNCTIONS / GROWTH OF FUNCTIONS
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are a chef scaling a recipe for a growing guest list.
 Serving a single pre-plated dessert (O(1)) takes the same time whether
 5 or 5,000 guests arrive. Cooking one pot of pasta (O(n)) doubles when
 guests double. Making every guest shake hands with every other guest
 (O(n²)) quadruples when guests double. Trying every possible seating
 arrangement (O(n!)) becomes impossible beyond a small dinner party.
 The same maths governs every algorithm: pick the wrong growth function
 and your "instant" program becomes a room-warming heater.

 📖 THEORY: (pure English, formal)

 A growth function f(n) describes how resource usage (time or space)
 scales as input size n increases. The Big-O notation expresses the
 worst-case growth class, ignoring constants and lower-order terms.

                   THE GROWTH HIERARCHY (slow → fast)
  ┌────────────┬───────────────────┬────────────────────────────────┐
  │   Class    │       Name        │      Behaviour as n → large    │
  ├────────────┼───────────────────┼────────────────────────────────┤
  │ O(1)       │ constant          │ stays the same forever         │
  │ O(log₂ n)  │ logarithmic       │ grows slower and slower        │
  │ O(n)       │ linear            │ grows in a straight line       │
  │ O(n log n) │ linearithmic      │ just above linear, 99% sorts   │
  │ O(n²)      │ quadratic         │ square of input size           │
  │ O(n³)      │ cubic             │ cube of input size             │
  │ O(2ⁿ)      │ exponential       │ doubles on every +1 of n       │
  │ O(n!)      │ factorial         │ multiplied by n every step     │
  └────────────┴───────────────────┴────────────────────────────────┘

 KEY PROPERTIES:
 - For sufficiently large n, the faster-growing term dominates: O(n²+n) = O(n²).
 - Constants are dropped: O(2n) = O(n); O(0.5n²) = O(n²).
 - log₂ n vs log₁₀ n: same class; when counting halving steps use log₂.
 - O(n log n) sits between O(n) and O(n²) — the "sweet spot" for sorting.
 - 2ⁿ and n! are feasible ONLY for tiny n (n ≤ 20 for 2ⁿ, n ≤ 12 for n!).
 - 2³² ≈ 4.29×10⁹ and 32! ≈ 2.63×10³⁵ — beyond 32-bit and 64-bit range.

 ASCII GROWTH BAR CHART (log₂-scale bars, bars ∝ log₂(value)):
   n = 32 →                      ┌────────────────────────┐
   1        ▏                    │ constant — 1 bar only │
   log₂n    ██████               │ 5 steps of halving    │
   n        ████████████████████  │ 32 steps              │
   nlog₂n   ██████████████████████████████████████████████│ 160 steps
   n²       ████████████████████████████ (1024)
   n³       █████████████████████████████████ (32768)
   2ⁿ       ██████████████████████████████████████████████│ 1.34×10¹⁰
   n!       (bar capped — log₂(32!) ≈ 117 units!)
   The bars visually confirm: each step up the hierarchy is a
   different league entirely.

 WHEN TO USE:
 - Target the LOWEST class that solves your problem correctly.
 - O(1)/O(log n): hash lookups, sorted-array search.
 - O(n)/O(n log n): scanning, sorting — "fast enough" for most apps.
 - O(n²): only for small inputs or when brute force is required.
 - O(2ⁿ)/O(n!): tiny inputs only, or theoretical/reference algorithms.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Pick test values n = 1, 2, 4, 8, 16, 32 (powers of 2).
   WHY: Powers of 2 make log₂(n) an exact integer (0,1,2,3,4,5), which
        keeps the table clean and shows exponential doubling exactly.

 Step 2: Compute each of the 8 functions at every chosen n.
   WHY: Concrete numbers make abstract growth classes tangible, e.g.
        at n=16: n²=256, 2ⁿ=65,536, n!=2.09×10¹².

 Step 3: Guard against integer overflow (use long long, check limits).
   WHY: 2³² overflows a 32-bit int; 21! overflows even a long long.
        An overflow guard prints a clean marker instead of garbage.

 Step 4: Print bars whose length is ∝ log₂(value), capped at 12.
   WHY: Linear scaling makes small values invisible next to 2ⁿ & n!;
        log scaling compresses 1 → 10¹² into a readable 12-column chart.

 Step 5: Draw the bar chart at n=32 (capped at 40) to compare all 8 rows.
   WHY: At a single large n the hierarchy 1 < log n < n < n log n
        < n² < n³ < 2ⁿ < n! becomes visually unmistakable.

 VISUAL WALKTHROUGH:

  VALUE TABLE (n = 1 to 32):
  ┌─────┬────────┬──────┬─────────┬─────────┬─────────┬──────────┬──────────┐
  │  n  │  log₂n │   n  │  n×log₂n│    n²   │    n³   │    2ⁿ    │    n!    │
  ├─────┼────────┼──────┼─────────┼─────────┼─────────┼──────────┼──────────┤
  │  1  │   0    │   1  │    0    │    1    │    1    │    2     │    1     │
  │  2  │   1    │   2  │    2    │    4    │    8    │    4     │    2     │
  │  4  │   2    │   4  │    8    │   16    │   64    │   16     │   24     │
  │  8  │   3    │   8  │   24    │   64    │  512    │  256     │ 40320    │
  │  16 │   4    │  16  │   64    │  256    │ 4096    │ 65536    │ 2.1×10¹² │
  │  32 │   5    │  32  │  160    │ 1024    │ 32768   │ 4.29×10⁹ │ 2.6×10³⁵ │
  └─────┴────────┴──────┴─────────┴─────────┴─────────┴──────────┴──────────┘
  Notice n=16 → n=32: n² goes 256→1024 (×4), 2ⁿ goes 65536→4.3×10⁹ (×65536).

 DRY RUN (full trace for n = 4):
  log₂(4):  4→2→1 (halved twice)  → log₂n = 2
  n        = 4
  n·log₂n  = 4 × 2   = 8
  n²       = 4 × 4   = 16
  n³       = 16 × 4  = 64
  2ⁿ       = 1<<4    = 16
  n!       = 4·3·2·1 = 24
  Order at n=4: 1(1) < log₂n(2) < n(4) < n·log₂n(8) < n²(16) = 2ⁿ(16) < n³(64) < n!(24)?
  Wait — n!(24) < n³(64). The FULL hierarchy only holds for large n;
  at small n the ordering can differ (this is WHY we test big n!).

 TIME COMPLEXITY CALCULATION:
  The demo loop runs over 6 fixed values of n. For each n it carries out
  a constant number of operations (compute 8 functions + print 1 row).
  ops per n = c₁ (say ~30 elementary ops)
  total     = 6 × c₁
  → independent of any growing input.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
  Memory used: 2 arrays of fixed size (ns[6], logs[8][6]),
  8 scalar long longs for the current row, a few loop indices.
  All sizes are constants independent of n.
 → Space Complexity = O(1)

 APPROACH COMPARISON (function growth order vs real-world feasibility):
  ┌─────────────┬──────────────────────────┬────────────────────────────┐
  │ Growth class│ Effect when n doubles   │ Practical n limit (@1s)      │
  ├─────────────┼──────────────────────────┼────────────────────────────┤
  │ O(1)        │ time stays identical     │ unlimited                   │
  │ O(log₂ n)   │ +1 step of halving       │ effectively unlimited       │
  │ O(n)        │ time doubles             │ ~10⁸                        │
  │ O(n log n)  │ slightly more than 2×    │ ~10⁷                        │
  │ O(n²)       │ time quadruples          │ ~10⁴–10⁵                    │
  │ O(n³)       │ time octuples (×8)       │ ~10³                        │
  │ O(2ⁿ)       │ n+1 → ×2 work            │ ~30                         │
  │ O(n!)       │ n+1 → ×(n+1) work        │ ~12                         │
  └─────────────┴──────────────────────────┴────────────────────────────┘
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// n! ka log2 nikalne ke liye Stirling approximation use karte hain
// log2(n!) ≈ (n·ln(n) − n + 0.5·ln(2πn)) / ln(2)
double stirlingLog2Fact(long long n) {
    const double PI = 3.14159265358979323846;
    if (n <= 1) return 0.0;                            // edge case: 0! = 1! = 1
    double v = n * log((double)n) - n + 0.5 * log(2.0 * PI * n);
    return v / log(2.0);
}

// ek bar/row print karta hai — bar length ∝ log2(value), cap 12 tak
void printRow(const char* name, const double log2Vals[], int cnt, int cap) {
    printf(" %-8s", name);
    for (int c = 0; c < cnt; c++) {
        int len = (int)log2Vals[c] + 1;
        if (len > cap) len = cap;                       // overflow guard for bar
        cout << " ";
        for (int b = 0; b < len; b++) cout << '#';
        for (int b = len; b < cap; b++) cout << ' ';    // padding → aligned columns
    }
    cout << endl;
}

int main() {
    cout << "══════════════════════════════════════════════════════════════════════" << endl;
    cout << "   GROWTH OF FUNCTIONS — VALUE TABLE  (n = 1, 2, 4, 8, 16, 32)" << endl;
    cout << "══════════════════════════════════════════════════════════════════════" << endl;

    long long ns[6] = {1, 2, 4, 8, 16, 32};
    int cnt = 6;

    // table header
    printf("\n┌──────┬────────┬────────┬──────────┬──────────┬──────────┬────────────┬──────────────┐\n");
    printf("│   n  │ log2(n)│    n   │ n*log2(n)│    n^2   │    n^3   │     2^n    │      n!      │\n");
    printf("├──────┼────────┼────────┼──────────┼──────────┼──────────┼────────────┼──────────────┤\n");

    for (int i = 0; i < cnt; i++) {
        long long n = ns[i];

        // log2(n): baar baar half karte jao, count karo
        long long lg = 0;
        long long t = n;
        while (t > 1) { t >>= 1; lg++; }

        long long nlogn = n * lg;      // n * log2(n)
        long long nsq   = n * n;       // n²
        long long ncube = nsq * n;     // n³

        // 2^n — overflow guard: n ≤ 62 hi safe hai (1LL<<63 undefined hai)
        long long pow2 = -1;           // -1 = overflow marker
        if (n <= 62) pow2 = 1LL << n;

        // n! — overflow guard: 20! ≈ 2.43×10¹⁸ (< 9.22×10¹⁸) safe, 21! overflow
        long long fact = -1;
        if (n <= 20) {
            fact = 1;
            for (long long k = 2; k <= n; k++) fact *= k;
        }

        printf("│ %4lld │ %6lld │ %6lld │ %8lld │ %8lld │ %8lld │",
               n, lg, n, nlogn, nsq, ncube);
        if (pow2 == -1) printf("   OVERFLOW  │");
        else            printf(" %10lld │", pow2);
        if (fact == -1) printf("   OVERFLOW  │\n");
        else            printf(" %12lld │\n", fact);
    }
    printf("└──────┴────────┴────────┴──────────┴──────────┴──────────┴────────────┴──────────────┘\n");
    cout << "OVERFLOW = value exceeds long long range (9.22×10^18). n! overflow already at n=21." << endl;

    // ── GROWTH TRAJECTORY CHART (bar ∝ log2(value), cap 12) ─────────────────
    cout << "\n═══════════ GROWTH TRAJECTORY CHART — bar length ∝ log2(value), capped at 12 ═══════════" << endl;
    cout << "            n=1      n=2      n=4        n=8         n=16        n=32" << endl;

    const int CAP = 12;
    double logs[8][6];

    for (int i = 0; i < cnt; i++) {
        long long n = ns[i];
        long long lg = 0;
        long long t = n;
        while (t > 1) { t >>= 1; lg++; }

        // har function ka log2 value precompute karte hain
        logs[0][i] = 0.0;                              // constant 1 → log2(1)=0
        logs[1][i] = (double)lg;                        // log2(n) itself
        logs[2][i] = log2((double)n);                   // n
        logs[3][i] = lg > 0 ? log2((double)(n * lg)) : 0.0; // n·log2(n)
        logs[4][i] = 2.0 * logs[2][i];                 // n² → log = 2·log(n)
        logs[5][i] = 3.0 * logs[2][i];                 // n³ → log = 3·log(n)
        logs[6][i] = (double)n;                        // 2ⁿ → log = n
        logs[7][i] = stirlingLog2Fact(n);              // n! → Stirling
    }

    printRow("1",       logs[0], cnt, CAP);
    printRow("log2n",   logs[1], cnt, CAP);
    printRow("n",       logs[2], cnt, CAP);
    printRow("nlog2n",  logs[3], cnt, CAP);
    printRow("n^2",     logs[4], cnt, CAP);
    printRow("n^3",     logs[5], cnt, CAP);
    printRow("2^n",     logs[6], cnt, CAP);
    printRow("n!",      logs[7], cnt, CAP);
    cout << "(bars capped at 12 units; real log2(32!) ≈ 117 — imagine 10× that bar)" << endl;

    // ── BAR CHART AT n=32 (fuller scale, cap 40) ─────────────────────────────
    cout << "\n═══════════ GROWTH AT n = 32 — bar ∝ log2(value), capped at 40 ═══════════" << endl;
    const int CAP2 = 40;

    // n = 32 ke liye exact values
    long long n    = 32;          // n
    long long lg   = 5;           // log2(32)
    double bConst = log2(1.0) + 1;                       // constant → 1 bar
    double bLog   = log2(32.0) + 1;                      // log2n
    double bN     = log2(32.0) + 1;                      // n
    double bNLogn = log2(32.0 * 5.0) + 1;                // n·log2(n)
    double bN2    = log2(1024.0) + 1;                    // n²
    double bN3    = log2(32768.0) + 1;                   // n³
    double b2N    = log2(4294967296.0) + 1;              // 2³² exactly 33
    double bFact  = stirlingLog2Fact(32) + 1;            // ≈118 → capped

    // lamba helper: length cap karke # print karta hai
    auto barAt32 = [&](const char* name, double log2v) {
        int len = (int)log2v;
        if (len > CAP2) len = CAP2;
        printf(" %-9s ", name);
        for (int b = 0; b < len; b++) cout << '#';
        if (len == CAP2) cout << " (capped)";
        cout << endl;
    };

    barAt32("1",       bConst);  // 1 bar — flat
    barAt32("log2n",   bLog);    // 6 bars
    barAt32("n",       bN);      // 6 bars
    barAt32("nlog2n",  bNLogn);  // ~9 bars
    barAt32("n^2",     bN2);     // 11 bars
    barAt32("n^3",     bN3);     // 16 bars
    barAt32("2^n",     b2N);     // 33 bars
    barAt32("n!",      bFact);   // capped at 40
    cout << "\n  → 'n!' ka real bar 117 units ka hota — chart mein itna jagah nahi hai!\n";

    return 0;
}