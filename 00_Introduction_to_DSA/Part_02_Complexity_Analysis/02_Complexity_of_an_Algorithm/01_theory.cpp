/*
═══════════════════════════════════════════════
 COMPLEXITY OF AN ALGORITHM (Time + Space, as a function of n)
═══════════════════════════════════════════════
 ⏱️ TOTAL TIME LOW: 0.00s · 0.20s max ... O(n) (loop) and O(1) (formula)
 (concrete big-O classes derived fully below — never an unknown O(?))

 🌍 REAL-WORLD SCENARIO:
 A delivery company must add up the distances of 1,000,000 packages. One
 clerk walks the whole sheet adding each number one-by-one to a running
 total — that is a *loop*: the more packages, the more minutes. A second
 clerk notices the sheet is just pages 1..N and instantly computes
 N×(N+1)/2 with a calculator — one button press, no walking, no matter how
 many packages. Both are "correct", but they grow in completely different
 ways as the sheet grows. Complexity of an algorithm is exactly this:
 "if the input size becomes n, how fast do the resources (time/memory)
 grow?" — small n hides it; huge n exposes it.

 📖 THEORY: (pure English, formal)
 - definition: The complexity of an algorithm is a measure of the resources
   (time and space) it consumes, expressed as a function of the input size
   n. TWO ingredients:
     • TIME COMPLEXITY  = number of basic operations (adds, comparisons)
       as a function of n — NOT seconds.
     • SPACE COMPLEXITY = amount of memory used (plus extra/auxiliary
       memory) as a function of n.
 - key points / properties:
   • Complexity DEPENDS ON THE INPUT SIZE n. Double the input → time may
     stay same (O(1)), double (O(n)), quadruple (O(n²)), etc.
   • We care about the RATE OF GROWTH (what class it belongs to), not the
     exact operation count — constants and low-order terms are dropped.
   • The SAME problem can have multiple correct algorithms with very
     different complexities — pick the one matching your constraints.
   • A problem's complexity is the best algorithm's complexity; a run's
     complexity is that algorithm's cost.
 - when to use:
   • Complexity is the first thing you estimate BEFORE implementing, to
     decide whether O(n²) will survive n = 10^6 (it won't — 10^12 ops).
   • Compare two correct approaches: lower growth class wins for big n,
     even when it looks "over-complicated" at n = 10.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Define the problem — sum all integers from 1 to n.
         WHY: It has a naive loop solution AND a clever constant-time
         formula, so both time-complexity worlds are visible in one demo.
 Step 2: Implement sumLoop(n): one for-loop, one accumulator.
         WHY: Its cost obviously grows with n — the perfect O(n) example.
 Step 3: Implement sumFormula(n) = n*(n+1)/2.
         WHY: One expression, zero loops — the cleanest O(1) example.
 Step 4: Count operations in both with opCount.
         WHY: Priori analysis demands exact f(n) formulas we can verify.
 Step 5: Time both with chrono at n = 10,000,000 and print results.
         WHY: n must be big enough for O(n) vs O(1) to be VISIBLE —
         at n=10 even a bad algorithm finishes instantly.
 Step 6: Print time and space conclusions side by side.
         WHY: Shows the two resource axes (time + space) independently.

 VISUAL WALKTHROUGH:

   PROBLEM: sum of 1..n, n = 1,000,000
   ┌─────────────────────────────┐        ┌─────────────────────────────┐
   │ sumLoop — step by step      │        │ sumFormula — one shot       │
   │  s=0                        │        │  n*(n+1)/2                  │
   │  s+=1  s+=2  s+=3 ⋯        │        │  = 1000000*1000001/2        │
   │      ⋮ (1,000,000 steps)    │        │  = 500000500000   (1 step)  │
   │  TIME grows with n → O(n)   │        │  TIME constant   → O(1)     │
   │  SPACE: just s → O(1)       │        │  SPACE: just s  → O(1)      │
   └─────────────────────────────┘        └─────────────────────────────┘
  Input size n badhao →
  |  n      loop steps   formula steps
  |  10          10             3
  |  10^3     1,000             3
  |  10^6   1,000,000           3      <-- loop cost grows, formula's does not

 DRY RUN: (trace for n = 5)
   sumLoop(5):
     s=0; i=1: s=1  i=2: s=3  i=3: s=6  i=4: s=10  i=5: s=15
     loop 5 iterations → 5 additions → returns 15
     opCount (with test/i++/add) = 3×5 + 3 = 18  →  O(n)
   sumFormula(5):
     s = 5 * 6 / 2 = 15        (1 multiply + 1 add + 1 divide)
     returns 15                →  opCount = 3  →  O(1)
   ✓ Dono ka answer 15 — same result, completely different resource cost.

 TIME COMPLEXITY CALCULATION:
   - sumLoop(n): loop runs exactly n iterations (i=1,2,…,n).
     Each iteration: 1 comparison (i<=n) + 1 add (s+=i) + 1 i++
     → 3n operations; plus int s=0 (1), int i=1 (1) and final test (1);
     Total  f(n) = 3n + 3.
     Since 3n + 3 ≤ 4n for n ≥ 3 → the class is linear.
 → Time Complexity of sumLoop    = O(n)
   - sumFormula(n): the expression n*(n+1)/2 needs 1 multiply, 1 add,
     1 divide — THREE operations no matter how huge n is.
     Total  f(n) = 3 (independent of n).
 → Time Complexity of sumFormula = O(1)

 SPACE COMPLEXITY CALCULATION:
   - sumLoop(n): variables s and i (long long) → 2 fixed slots, no array,
     no recursion → constant memory regardless of n.
 → Space Complexity of sumLoop   = O(1)   (auxiliary)
   - sumFormula(n): temporary n*(n+1) and s → constant temporary slots.
 → Space Complexity of sumFormula = O(1)   (auxiliary)
   (Both use O(1) extra space — so the decision between them is purely a
    TIME decision. On a machine without hardware multiply the formula may
    still be slower — complexity predicts growth, not raw seconds.)

 APPROACH COMPARISON: (Loop solution vs Formula solution)
 ┌──────────────────┬───────────────────────┬──────────────────────────┐
 │ Aspect           │ sumLoop (iterative)   │ sumFormula (closed form) │
 ├──────────────────┼───────────────────────┼──────────────────────────┤
 │ Time complexity  │ O(n)                  │ O(1)                     │
 │ Space complexity │ O(1)                  │ O(1)                     │
 │ Exact ops for n  │ 3n + 3                │ 3                        │
 │ Works for any n? │ Yes, any n ≥ 1        │ Yes, but watch overflow  │
 │ Big n (10^6)     │ ~3,000,000 ops        │ 3 ops                    │
 │ Danger           │ Too slow for huge n   │ int overflow if careless │
 │ Winner           │ —                     │ ✓ faster for huge n      │
 └──────────────────┴───────────────────────┴──────────────────────────┘
*/

#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// loop se sum 1..n — har iteration me opCount++ (t-test + i++ ke saath)
long long sumLoop(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;             // 1 addition per iteration
    }
    return s;
}

// formula se sum 1..n — bas ek calculation, loop zero
long long sumFormula(long long n) {
    return n * (n + 1) / 2;   // (1 multiply + 1 add + 1 divide)
}

// exact operation counter — sumLoop ka f(n) verify karne ke liye
long long loopOps(int n) {
    long long ops = 0;
    long long s = 0;        ops++;          // s = 0
    int i = 1;              ops++;          // i = 1
    while (true) {
        ops++;                              // i <= n test
        if (i > n) break;
        ops++;                              // s += i
        s += i;
        ops++;                              // i++
        i++;
    }
    return ops;                             // expected 3n + 3
}

int main(int argc, char* argv[]) {
    // ---- correctness + exact count for small n ----
    cout << "n=5: loop=" << sumLoop(5)
         << " formula=" << sumFormula(5) << "\n";
    cout << "loopOps(5) = " << loopOps(5)
         << "  (expected f(5) = 3*5 + 3 = 18)\n";

    // ---- posteriori: dono ko bade n pe time karo ----
    int n = 10000000;                        // 10 million (argv se bhi diya ja sakta hai)
    if (argc > 1) n = atoi(argv[1]);         // runtime input → compiler loop ko fold nahi karta
    const int REPS = 30;                     // REP baar chalao taaki clock pe dikhe

    long long a1 = 0;
    auto t1s = high_resolution_clock::now();
    for (int r = 0; r < REPS; r++) a1 = sumLoop(n);
    auto t1e = high_resolution_clock::now();

    long long a2 = 0;
    auto t2s = high_resolution_clock::now();
    for (int r = 0; r < REPS; r++) a2 = sumFormula(n);
    auto t2e = high_resolution_clock::now();

    double loopUs  = duration_cast<microseconds>(t1e - t1s).count();
    double formUs  = duration_cast<microseconds>(t2e - t2s).count();

    cout << "n=" << n << ": loop=" << a1
         << " formula=" << a2
         << "  (same? " << (a1 == a2 ? "YES" : "NO") << ")\n";
    cout << "loop=" << loopUs / REPS << "us/call   formula="
         << formUs / REPS << "us/call";
    if (formUs > 0) {
        cout << "  → formula " << loopUs / formUs
             << "x faster on this machine\n";
    } else {
        cout << "  → formula ~0us (clock resolution ke neeche) → "
             << "kaafi faster\n";
    }

    // edge case: n=0 — dono ka jawab 0 hona chahiye
    cout << "n=0: loop=" << sumLoop(0) << " formula=" << sumFormula(0)
         << " (edge case ok)\n";
    return 0;
}