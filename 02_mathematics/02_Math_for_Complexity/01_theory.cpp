/*
═══════════════════════════════════════════════
 MATH FOR COMPLEXITY ANALYSIS
 ⏱️ TIME COMPLEXITY: O(1) per formula / O(log n) per log trick / loop versions O(n) or O(log n). Derived below — never bare.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You are packing boxes into a warehouse. Each day you halve the number of
 remaining boxes — 32 boxes, then 16, then 8, then 4, then 2, then 1. That
 feels fast because you only work ~5 days. But a scam company promises to
 double your money every day starting from ₹1 — day 1 you have ₹1, day 2 ₹2,
 day 3 ₹4 ... by day 30 you owe them a billion. Halving is the log (fast),
 doubling is the exponential (dangerous). Every Big-O analysis in coding is
 really just this profit/loss story: log growth wins, exponential loses.
 Understanding logarithms tells you whether your loop "doubling to reach n"
 runs 5 times (log) or 2^30 times (exponential) — the difference between a
 feature shipping and a server melting.

 📖 THEORY: (pure English, beginner-level)
 - definition: log2(n) asks "how many times must you halve n to reach 1?"
   log2(32) = 5 because 32→16→8→4→2→1 is five halvings. Equivalently 2^5 = 32.
 - log10(n) asks the same with division by 10: "how many digits does n have?"
   log10(1000) = 3 → 1000 has 4 digits. digits = floor(log10(n)) + 1.
 - key points:
   * log grows VERY slow — log2(1,000,000) ≈ 20. Loops that halve (binary
     search, division by 2) are nearly "free" compared to n loops.
   * 2^n grows so fast that even n = 100 is astronomically larger than the
     number of atoms in the universe — never write an algorithm that scans
     all subsets when n can exceed 25.
   * sum 1+2+...+n has the closed form n(n+1)/2. A loop needs n steps; the
     formula is O(1). Same idea: geometric sum 1+2+4+...+2^(k-1) = 2^k − 1.
   * log property used everywhere: log(a·b) = log a + log b (multiplication
     becomes addition), and log(2^k) = k·log 2.
 - ASCII diagram (halving loop growth vs loop count):
         n=32: 32 → 16 → 8 → 4 → 2 → 1     (5 halvings = 5 iterations ≅ log2)
         n=16: 16 → 8 → 4 → 2 → 1           (4 halvings)
         n=8 :  8 → 4 → 2 → 1               (3 halvings)
     doubling growth (danger!):
         1 → 2 → 4 → 8 → 16 → 32 → ... → 2^n
         1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 ... 1 billion at n=30
 - when to use: every time you ask "how many times does my loop shrink the
   input" (halving → log), or "should I sum this in a loop or use a formula"
   (formula → O(1)), or "can I scan all 2^n subsets" (NO if n > ~25).

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Count iterations of a halving loop. Loop runs while n > 0, n halves
         each round.
         WHY: 2^k = n → k = log2(n). Halving loop ≈ log2(n) rounds.
 Step 2: Count digits of n by loop (divide by 10 until 0) versus by math.
         WHY: both are O(log10 n) rounds, but log10(n)+1 is O(1) work after
         one function call — the "loop" of division shrinks logarithmically.
 Step 3: Convert O(n) summation to O(1). Sum 1..n loop does n additions; the
         formula n(n+1)/2 does 1 multiplication — constant time.
         WHY: closed forms remove the growth entirely (O(1)).
 Step 4: Measure exponential danger. 2^n doubles each step; every +10 to n
         multiplies result by ~1000.
         WHY: multiplicative growth beats polynomial growth at large n.

 VISUAL WALKTHROUGH: (ASCII table: n vs log2(n) vs 2^n)
     n     log2(n)    2^n
     1        0        2
     2        1        4
     4        2       16
     8        3      256
    16        4    65536
    32        5    4294967296        <- log crawls, exponent explodes

 DRY RUN: (line-by-line trace on n = 16, doubling loop)
   doubling count k for n=16: 1→2→4→8→16, that is 5 values emitted → k=5.
   Logically: 16 = 2^4, so we printed 4 doublings + the value 16 itself,
   which is exactly floor(log2(16))+1 = 5 printings. Both agree.
   Digits of 874: loop 874→87→8→0 = 3 divisions; log10(874) = 2.94 → floor
   2 + 1 = 3 digits. Both agree.
   Sum 1..5: loop 1+2+3+4+5 = 15; formula 5·6/2 = 15. Same answer, loop O(n).

 TIME COMPLEXITY CALCULATION:
 - Halving loop: runs k times where 2^k = n → k = log2(n).
   → Time Complexity = O(log n)
 - Digits-by-loop: divisions until n becomes 0 → O(log10 n) = same growth.
   Digits-by-log: one cmath call, constant work.
   → Time Complexity (loop) = O(log n); (log trick) = O(1)
 - Sum 1..n with loop → O(n). With formula n(n+1)/2 → single expression.
   → Time Complexity (loop) = O(n); (formula) = O(1)
 - Geometric series 1+2+4+...+2^(k-1): summing doubles k times → O(k); the
   closed form 2^k − 1 is one expression.
   → Time Complexity (loop) = O(k); (formula) = O(1)
 - 2^n table: printing n rows where each value is O(1) → O(n) prints.
   → Time Complexity (table) = O(n)

 SPACE COMPLEXITY CALCULATION:
 - All demos use a handful of long long / double / loop counters; no arrays,
   no recursion.
   → Space Complexity = O(1)

 APPROACH COMPARISON: (real table)
 ┌────────────────────┬──────────────────────────┬──────────────────────────┐
 │ Problem            │ Loop approach            │ Math approach            │
 ├────────────────────┼──────────────────────────┼──────────────────────────┤
 │ sum 1..n           │ O(n) additions           │ n(n+1)/2 → O(1)          │
 │ digits of n        │ O(log n) divisions       │ floor(log10 n)+1 → O(1)  │
 │ 1+2+4+..+2^(k-1)   │ O(k) additions           │ 2^k − 1 → O(1)           │
 │ find k where 2^k=n │ O(log n) doublings       │ k = log2(n) → O(1)       │
 └────────────────────┴──────────────────────────┴──────────────────────────┘
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // ---------- 1) LOG2 TABLE: doubling vs halving logic ----------
    // har baar value double hoti hai, print karte jao — jaise halving loop
    // ke ulta. Dono ka count log2(n)+1 jaisa hi growth dikhata hai.
    cout << "1) LOG2 TABLE  n -> floor(log2(n))  (doubling growth == halving count)\n";
    cout << "   n:    log2(n)   doubling sequence\n";
    for (long long n = 1; n <= 32; n <<= 1) {
        long long count = 0;           // kitne doublings?
        for (long long v = 1; v < n; v <<= 1) count++;   // v: 1,2,4,...<n
        cout << "   " << n << "         " << (long long)floor(log2((double)n))
             << "        " << count << " doublings (plus value itself)\n";
    }

    cout << "\n2) COUNT DIGITS: loop vs log10 trick, same n\n";
    for (long long n : {0LL, 1LL, 7LL, 99LL, 1000LL, 123456789LL}) {
        long long loop = (n == 0) ? 1 : 0;   // edge: 0 has 1 digit
        long long temp = n;
        while (temp > 0) { loop++; temp /= 10; }
        long long trick = (n == 0) ? 1 : (long long)floor(log10((double)n)) + 1;
        cout << "   n=" << n << "  loop=" << loop << "  log10=" << trick
             << "  " << (loop == trick ? "MATCH" : "MISMATCH!") << "\n";
    }

    cout << "\n3) 2^n EXPLODES: n vs 2^n (overflow guard beyond n=30)\n";
    cout << "   n:         2^n\n";
    for (int n = 1; n <= 32; n++) {
        if (n <= 30) {
            long long p = 1LL << n;      // long long ka max ~9.2e18, 2^30 safe
            cout << "   " << n << "         " << p;
            if (n == 30) cout << "   <- ~1.07e9, already huge!";
            cout << "\n";
        } else {
            cout << "   " << n << "         OVERFLOW (2^n exceeds long long)\n";
        }
    }

    cout << "\n4) SUM 1..n : loop vs formula n(n+1)/2\n";
    for (long long n : {0LL, 1LL, 5LL, 100LL, 1000LL}) {
        long long loopSum = 0;
        for (long long i = 1; i <= n; i++) loopSum += i;         // O(n)
        long long formula = n * (n + 1) / 2;                     // O(1)
        cout << "   n=" << n << "  loop=" << loopSum
             << "  formula=" << formula
             << "  " << (loopSum == formula ? "EQUAL" : "WRONG!") << "\n";
    }

    cout << "\n5) SUM OF SQUARES 1^2+2^2+...+n^2: loop vs n(n+1)(2n+1)/6\n";
    for (long long n : {0LL, 1LL, 5LL, 10LL}) {
        long long loopSq = 0;
        for (long long i = 1; i <= n; i++) loopSq += i * i;      // O(n)
        long long formulaSq = n * (n + 1) * (2 * n + 1) / 6;     // O(1)
        cout << "   n=" << n << "  loop=" << loopSq
             << "  formula=" << formulaSq
             << "  " << (loopSq == formulaSq ? "EQUAL" : "WRONG!") << "\n";
    }

    cout << "\n6) GEOMETRIC SERIES 1+2+4+...+2^(k-1): loop vs 2^k - 1\n";
    for (int k = 1; k <= 10; k++) {
        long long loopG = 0, term = 1;              // term = 2^(i)
        for (int i = 0; i < k; i++) { loopG += term; term *= 2; }   // O(k)
        long long formulaG = (1LL << k) - 1;                         // O(1)
        cout << "   k=" << k << "  loop=" << loopG
             << "  formula=" << formulaG
             << "  " << (loopG == formulaG ? "EQUAL" : "WRONG!") << "\n";
    }

    cout << "\nEdge cases covered: n=0 (1 digit, sum/squares = 0), n=1 (base),\n";
    cout << "    n>30 (2^n overflow guarded), k=10 geometric = 1023.\n";

    return 0;
}