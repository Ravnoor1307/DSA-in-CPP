/*
═══════════════════════════════════════════════
 CATEGORIES OF TIME COMPLEXITY
 (constant → logarithmic → linear → n-log-n → quadratic → cubic → exponential → factorial)
═══════════════════════════════════════════════
 ⏱️ TOTAL TIME LOW: 0.0s · 0.5s max ... all 8 classes derived below
 (never an unknown O(?) — every category below has a full f(n) derivation)

 🌍 REAL-WORLD SCENARIO:
 Suppose you forward a chain-letter to your friends every day. If you mail
 1 person regardless of how many friends you have, that is CONSTANT effort
 (O(1)). If you ring every one of your 100 friends, that is LINEAR (O(n)).
 If everyone calls everyone else, there are 100×100 calls — QUADRATIC
 (O(n²)). If you arrange 8 dinner guests in every possible seating order,
 8! = 40320 arrangements — FACTORIAL (O(n!)), impossible for 30 guests.
 Real life and code share one law: the way the WORK COUNT grows when the
 crowd n grows decides what is possible at all. Choosing a category is
 choosing your survival strategy at scale.

 📖 THEORY: (pure English, formal)
 - definition: TIME COMPLEXITIES are grouped into a small number of named
   growth classes by how the operation count f(n) grows as input size n
   grows. From fastest to slowest (for large n):
      O(1)       constant   — work independent of n
      O(log n)   logarithmic— work grows by ~1 per doubling of n
      O(n)       linear     — work ∝ n
      O(n log n) linearithmic— n chunks × log n each (sorting, etc.)
      O(n²)      quadratic  — work ∝ n²
      O(n³)      cubic      — work ∝ n³
      O(2ⁿ)      exponential— work DOUBLES per extra element
      O(n!)      factorial  — work multiplies per extra element
 - key points / properties:
   • For large n, each category dominates the previous: n! > 2ⁿ > n³ >
     n² > n log n > n > log n > 1 (big-O ordering).
   • The category determines FEASIBILITY: n=30 is fine for 2ⁿ (≈10⁹ ops,
     borderline) but n=30 for n! is ~2.65×10³² — impossible.
   • Constants and small terms never change the category: 100n + 5
     is still O(n); n²/2 is still O(n²).
   • Real-world analogies: O(1) elevator, O(log n) dictionary search,
     O(n) read the book, O(n log n) sort a deck by halving, O(n²) pair
     everyone with everyone, O(n³) every trio, O(2ⁿ) every menu subset,
     O(n!) every seating arrangement.
 - when to use:
   • Name the category AFTER writing f(n): count first, classify second.
   • Use it with constraints: n ≤ 20 → maybe 2ⁿ/n! allowed; n ≤ 10⁶ →
     only up to O(n log n); n ≤ 10⁸ → only O(n).
   • Recognise patterns: single loop = O(n); nested pair = O(n²); halving
     = O(log n); recursion that splits in 2 = O(2ⁿ).

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Write one instrumented function for each category, counting
         basic operations (opCount++).
         WHY: Each class is a *pattern of loops/recursion*; a counter turns
         the abstract class into a concrete, verifiable number.
 Step 2: Use the same n in every function when possible and print counts.
         WHY: Side-by-side counts let you SEE 1 vs ~10 vs 10³ vs 10⁶ vs
         10⁹ — categories are made visible by comparing magnitudes.
 Step 3: Derive each f(n) BEFORE calling it a class.
         WHY: The rule is "derive f(n), then classify" — never guess O(?).
 Step 4: Keep exponential/factorial demos at small n (10 and 6/7).
         WHY: 2³⁰ is a billion calls — the program would hang; small n
         shows the pattern without freezing the terminal.
 Step 5: Print a final growth table (what happens when n doubles).
         WHY: The doubling behavior is the crispest way to remember and
         to explain a category in an interview.

 VISUAL WALKTHROUGH:

   Growth of work with input size n (log-scale behaviour):
   ops
   10^6 ┤                   ╱ O(n²)
   10^4 ┤             ╱ ╱
   10^2 ┤       ╱ ╱────── O(n log n)
   10^0 ┤ ╱ ╱───────────── O(n)
        └──────────────── O(log n)
                    O(1) ───────── flat line
        n= 1       10³      10⁶      10⁹
   Even without a real graph you see the ORDER:
   constant < log < linear < n log n < n² < n³ < 2ⁿ < n!

 DRY RUN: (n = 8 for a taste of every category)
   O(1)      : ops = 1                    (always 1)
   O(log n)  : 8→4→2→1 : 3 halvings        (floor log₂8 = 3)
   O(n)      : 8 iterations                (ops 8)
   O(n log n): 8 × log₂8 = 8 × 3 = 24
   O(n²)     : 8 × 8 = 64
   O(n³)     : 8 × 8 × 8 = 512
   O(2ⁿ)     : 2⁹ − 1 = 511 recursive calls = 2^(n+1)−1
   O(n!)     : calls ≈ e × n! = 109601 at n=8 (counted below at n=7→13700)

 TIME COMPLEXITY CALCULATION: (each category, full derivation)
   - O(1) constant: work = 1 op, no loop dependent on n.
        f(n) = 1                     → O(1)
   - O(log n): while (n>1) n/=2. After k steps n = n/2^k; stop when
     n/2^k ≤ 1 → k = log₂n.
        f(n) = log₂n                 → O(log n)
   - O(n): one loop 0..n-1, body O(1) each.
        f(n) = n × O(1) = n          → O(n)
   - O(n log n): outer loop n times; each inner halves → log₂n steps.
        f(n) = n × log₂n             → O(n log n)
   - O(n²): 2 nested loops, each n.
        f(n) = n × n = n²            → O(n²)
   - O(n³): 3 nested loops, each n.
        f(n) = n × n × n = n³        → O(n³)
   - O(2ⁿ): recursion splits into 2 calls per level. Calls C(k):
        C(0)=1; C(k)=1+2·C(k−1). Unfold: C(k)=2^(k+1)−1 = 2·2ⁿ−1.
        f(n) = 2^(n+1) − 1           → O(2ⁿ)
   - O(n!): recursion tries k branches per level. Calls T(k):
        T(0)=1; T(k)=1+k·T(k−1).
        T(k)/k! = Σ_{j=0}^{k} 1/j! → e ≈ 2.718, so T(n) ≈ e·n!.
        f(n) ≈ e·n!                  → O(n!)
   (Note: a flat formula can bound comparisons within each class — the
    class is the dominant term's doubling behaviour, listed above.)

 SPACE COMPLEXITY CALCULATION:
   - Iterative category demos (constant/log/linear/nlog/quad/cubic):
     only the loop counters + one accumulator → fixed few variables,
     no arrays → O(1) each.
   - Recursive category demos (2ⁿ, n!): each pending call occupies a
     stack frame. Depth for 2ⁿ = n (level 0..n) and n! = n → O(n) stack
     at peak. (The TIME blows up, but the DEPTH is only n.)
 → Iterative demos: O(1) space; recursive demos: O(n) stack space.

 APPROACH COMPARISON: (the 8 categories at a glance)
 ┌─────────┬──────────────────────────────┬─────────────┬─────────────────────────┐
 │ Category│ Real-world analogy           │ Example ops │ n doubles → new ops     │
 ├─────────┼──────────────────────────────┼─────────────┼─────────────────────────┤
 │ O(1)    │ press lift button at any    │ 1           │ stays 1                 │
 │         │ floor                       │             │                         │
 │ O(log n)│ dictionary, open in middle  │ log₂n       │ +1                      │
 │ O(n)    │ read a book page by page    │ n           │ ×2                      │
 │ O(n logn)│ sort deck by halving then  │ n·log₂n     │ >2× (plus log)          │
 │         │ merge                       │             │                         │
 │ O(n²)   │ everyone shakes hands w/    │ n²          │ ×4                      │
 │         │ everyone                    │             │                         │
 │ O(n³)   │ every trio of friends       │ n³          │ ×8                      │
 │ O(2ⁿ)   │ every subset of the menu    │ 2ⁿ          │ squared!                │
 │ O(n!)   │ all seating arrangements    │ n!          │ multiplied                │
 └─────────┴──────────────────────────────┴─────────────┴─────────────────────────┘
*/

#include <iostream>
using namespace std;

// har category ka operation counter (opCount++)
long long opsConstant(int n)            { (void)n; return 1; }       // bas 1 op

long long opsLog(int n) {
    long long c = 0;
    while (n > 1) { n = n / 2; c++; }   // har step aadha → log2n steps
    return c;
}

long long opsLinear(int n) {
    long long c = 0;
    for (int i = 0; i < n; i++) c++;    // n iterations
    return c;
}

long long opsNLogN(int n) {
    long long c = 0;
    for (int i = 0; i < n; i++) {       // n baar
        int x = n;
        while (x > 1) { x /= 2; c++; }  // har baar log2n steps
    }
    return c;
}

long long opsQuadratic(int n) {
    long long c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) c++;   // n × n
    return c;
}

long long opsCubic(int n) {
    long long c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) c++;   // n × n × n
    return c;
}

// O(2^n): ek call do calls me split — C(k) = 2^(k+1) - 1
long long expCalls(int k, long long& c) {
    c++;                                   // is call ko count karo
    if (k == 0) return c;
    expCalls(k - 1, c);                    // left subtree
    expCalls(k - 1, c);                    // right subtree
    return c;
}

// O(n!): ek call k branches banati hai — T(k) = 1 + k·T(k-1) ≈ e·n!
long long factCalls(int k, long long& c) {
    c++;
    if (k == 0) return c;
    for (int i = 0; i < k; i++) factCalls(k - 1, c);   // k options
    return c;
}

int main() {
    cout << "=== CATEGORY vs OPERATION COUNT (opCount++) ===\n\n";

    cout << "O(1)      constant  : n=any   -> ops = "
         << opsConstant(100000000) << "\n";

    cout << "O(log n)  log       : n=1024  -> ops = " << opsLog(1024)
         << "  (log2 1024 = 10)\n";

    cout << "O(n)      linear    : n=1000  -> ops = "
         << opsLinear(1000) << "\n";

    int nlogn = opsNLogN(1024);
    cout << "O(n log n) n-log-n  : n=1024  -> ops = " << nlogn
         << "  (1024 * 10)\n";

    cout << "O(n^2)    quadratic : n=1000  -> ops = "
         << opsQuadratic(1000) << "  (1000^2)\n";

    cout << "O(n^3)    cubic     : n=100   -> ops = "
         << opsCubic(100) << "  (100^3)\n";

    long long c = 0;
    expCalls(15, c);
    cout << "O(2^n)    exponential: n=15   -> ops = " << c
         << "  (2^16 - 1)\n";

    c = 0;
    factCalls(7, c);
    cout << "O(n!)     factorial : n=7    -> ops = " << c
         << "  (e * 7! ~ 2.718*5040 = 13700)\n";

    cout << "\n=== n double hone par kya hota hai ===\n";
    cout << "n=10 ->  n=20 :\n";
    cout << "  O(1)      " << opsConstant(10) << "   ->   "
         << opsConstant(20) << "   (same)\n";
    cout << "  O(log n)  " << opsLog(10) << "   ->   "
         << opsLog(20) << "   (+1)\n";
    cout << "  O(n)      " << opsLinear(10) << "  ->   "
         << opsLinear(20) << "   (2x)\n";
    cout << "  O(n logn) " << opsNLogN(10) << "  ->   "
         << opsNLogN(20) << "   (>2x)\n";
    cout << "  O(n^2)    " << opsQuadratic(10) << "  ->   "
         << opsQuadratic(20) << "   (4x)\n";
    cout << "  O(n^3)    " << opsCubic(10) << "  ->   "
         << opsCubic(20) << "   (8x)\n";

    c = 0; expCalls(10, c);  long long e10 = c;
    c = 0; expCalls(20, c);  long long e20 = c;
    cout << "  O(2^n)    " << e10 << " ->   " << e20
         << "   (squared!)\n";

    c = 0; factCalls(6, c);  long long f6 = c;
    c = 0; factCalls(7, c);  long long f7 = c;
    cout << "  O(n!)     " << f6 << " ->   " << f7
         << "   (x" << f7 / f6 << " approx)\n";
    return 0;
}
/*
 COMPLETE DERIVATION CLUB (repeated compactly):
   O(1)      : f(n) = 1                                → O(1)
   O(log n)  : after k halvings n/2^k ≤ 1 → k = log₂n   → O(log n)
   O(n)      : n iterations × O(1) body                  → O(n)
   O(n log n): n iterations × log₂n inner steps         → O(n log n)
   O(n²)     : n × n nested iterations                  → O(n²)
   O(n³)     : n × n × n nested iterations              → O(n³)
   O(2ⁿ)     : C(k)=1+2C(k−1) → 2^(k+1)−1              → O(2ⁿ)
   O(n!)     : T(k)=1+k·T(k−1) → ≈ e·k!                → O(n!)
*/