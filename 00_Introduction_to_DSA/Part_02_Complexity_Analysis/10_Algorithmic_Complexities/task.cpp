/*
═══════════════════════════════════════════════
 TASKS — ALGORITHMIC COMPLEXITY CLASSES
═══════════════════════════════════════════════

 THEORY RECAP (use it to guide your solutions):
   Class lookup: nested loops → multiply; halving loop → log;
   recursion with 1 branch → linear/stack; 2 branches → exponential.
   Exact-count derivations: Σ i=1..n i = n(n+1)/2 → O(n²).

   Ground rules for all tasks:
     (a) NEVER write bare O(?); ALWAYS derive the count first.
     (b) Where possible, verify your prediction with a step counter.

──────────────────────────────────────────
 TASK 1 — CLASSIFY THE SNIPPETS (derive, then label)
──────────────────────────────────────────
 Problem:
   For each snippet below, (1) count exact operations as a function
   of n, (2) simplify to the O() class, (3) explain your derivation.

   [A] for (int i = 0; i < n; i++)      // sum of array, single loop
           sum += a[i];
   [B] for (int i = 0; i < n; i++)
           for (int j = 0; j < n; j++)  // full n×n grid, both full range
               work(i, j);
   [C] for (int i = 0; i < n; i++)
           for (int j = 0; j < i; j++)  // triangle — only i iterations of inner
               work(i, j);
   [D] while (high - low > 1) {         // standard halving search
           mid = low + (high - low) / 2;
           if (a[mid] < key) low = mid;
           else high = mid;
       }
   [E] int f(int x) { return x <= 1 ? x : f(x - 1) + f(x - 2); } // recursive

   Write your answer table on paper FIRST, then use the solution code's
   counters to verify [A]–[D] empirically and see [E] explode.

 💡 HINT: [C] sum equals n(n−1)/2. [D] the range halves each step.
          [E] is the Fibonacci recurrence T(n)=T(n−1)+T(n−2)+O(1).

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   int main() {
       long long ops = 0;
       // snippet A/B/C/D ko counters ke saath chalao
       // n = 1000 rakho, ops variable print karo
       return 0;
   }

──────────────────────────────────────────
 TASK 2 — EXACT STEP COUNTS VIA SUMS
──────────────────────────────────────────
 Problem:
   Prove with a hand-derived sum (not just intuition) that snippet [C]
   runs exactly n(n−1)/2 inner iterations. Then adapt the loop so the
   inner bound is `j < i+1` instead of `j < i`, and derive the new
   exact count. Print both.

 💡 HINT: Σ i=0..n−1  i  = 0 + 1 + ... + (n−1) = n(n−1)/2.

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   int main() {
       long long c = 0;
       for (int i = 0; i < 5; i++)
           for (int j = 0; j < i; j++)
               ++c;   // count inner visits
       cout << "n=5 → " << c << endl;       // expected 10
       // ab j < i+1 wala variant likho, expected 15
       return 0;
   }

──────────────────────────────────────────
 TASK 3 — NAIVE vs DP FIBONACCI, VERIFY THE 2ⁿ vs n GAP
──────────────────────────────────────────
 Problem:
   Implement BOTH fibNaive(n) (with a global call counter) and fibDP(n)
   (iterative, no recursion). For n = 10, 15, 20, 25, 30 print:
   answer, naive call count, DP loop steps. Then print the theoretical
   naive call count 2·F(n+1)−1 for n=30 and compare with measured.

 💡 HINT: naive fib counts obey the same Fibonacci recurrence plus 1:
          calls(n) = calls(n−1) + calls(n−2) + 1, calls(0)=calls(1)=1
          → solu:<calls(n) = 2·F(n+1) − 1>.

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   long long naiveCalls = 0;
   long long fibNaive(int n) {
       // har call pe counter ++ , base n<=1, else two calls
   }
   long long fibDP(int n) {
       // iterative — loop i=2..n, sirf 3 variables
   }
   int main() {
       // n = 10..30 compare karke print karo
       return 0;
   }

-------------- SOLUTIONS --------------
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long naiveCalls = 0;
long long fibNaive(int n) {
    naiveCalls++;                    // har call count
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2); // 2 sub-calls → exponential tree
}

long long fibDP(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c = 1;
    for (int i = 2; i <= n; i++) {   // (n−1) iterations total
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    cout << "══════════════════════════════════════════════" << endl;
    cout << "   ALGORITHMIC COMPLEXITY — TASK SOLUTIONS" << endl;
    cout << "══════════════════════════════════════════════" << endl;

    // ==================== TASK 1 + TASK 2 ====================
    cout << "\n═══ TASK 1+2 — empirical verification of loop derivations ═══" << endl;
    int n = 1000;
    long long opsA = 0, opsB = 0, opsC1 = 0, opsC2 = 0, opsD = 0;

    for (int i = 0; i < n; i++) opsA++;                     // [A] single loop → n
    printf(" [A] single loop over n=%d: ops = %lld, theory = n       → O(n)\n", n, opsA);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) opsB++;                 // [B] full grid → n²
    printf(" [B] n×n grid: ops = %lld, theory = n^2 = %lld → O(n²)\n", opsB, (long long)n * n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) opsC1++;                // [C] triangle → n(n−1)/2
    long long theoryC = (long long)n * (n - 1) / 2;
    printf(" [C] triangle (j<i): ops = %lld, theory = n(n-1)/2 = %lld → O(n²)\n", opsC1, theoryC);

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) opsC2++;               // [C'] variant j<=i
    long long theoryC2 = (long long)n * (n + 1) / 2;
    printf(" [C'] variant (j<=i): ops = %lld, theory = n(n+1)/2 = %lld → O(n²)\n", opsC2, theoryC2);

    // [D] halving: simulate binary search range reduction
    {
        int lo = 0, hi = n;          // range [0, n)
        while (hi - lo > 1) {
            opsD++;
            int mid = lo + (hi - lo) / 2;
            if (mid * 2 < n) lo = mid;   // deterministic fake probe
            else hi = mid;
        }
    }
    long long theoryD = (long long)(log2((double)n)) + 1;  // steps = ⌈log2 n⌉ + 1 approx
    printf(" [D] halving loop: ops = %lld, theory ≈ log2(%d)+1 = %lld → O(log n)\n",
           opsD, n, theoryD);

    cout << "\n Derivation notes:\n"
         << "   [A] loops i=0..n−1 → exactly n iterations → O(n).\n"
         << "   [B] i×j both range 0..n−1 → n·n = n² → O(n²).\n"
         << "   [C] sum_{i=0}^{n−1} i = n(n−1)/2 → O(n²).\n"
         << "   [C'] sum_{i=0}^{n−1} (i+1) = n(n+1)/2 → O(n²).\n"
         << "   [D] each step halves the interval length → ⌈log2(n)⌉+1 → O(log n).\n"
         << "   [E] T(n)=T(n−1)+T(n−2)+O(1) → golden-ratio tree φⁿ ≈ 1.618ⁿ → O(2ⁿ).\n";

    // ==================== TASK 3 ====================
    cout << "\n═══ TASK 3 — naive vs DP fibonacci: measured vs theoretical ═══" << endl;
    printf("┌──────┬──────────────┬─────────────────────┬───────────────┬───────────┐\n");
    printf("│   n  │  Fib(n)      │  naive call counter │  DP steps     │  verified │\n");
    printf("├──────┼──────────────┼─────────────────────┼───────────────┼───────────┤\n");
    int seq[] = {10, 15, 20, 25, 30};
    for (int k = 0; k < 5; k++) {
        int n = seq[k];
        naiveCalls = 0;
        long long r1 = fibNaive(n);
        long long cNaive = naiveCalls;
        long long r2 = fibDP(n);
        printf("│ %4d │ %12lld │ %17lld │ %13lld │      %s    │\n",
               n, r1, cNaive, (long long)(n - 1), (r1 == r2 ? "YES" : "NO"));
    }
    printf("└──────┴──────────────┴─────────────────────┴───────────────┴───────────┘\n");

    // theoretical check: calls(n) = 2·F(n+1) − 1
    long long F0 = 0, F1 = 1, Fn = 1;
    int n30 = 30;
    for (int i = 2; i <= n30 + 1; i++) { Fn = F0 + F1; F0 = F1; F1 = Fn; }
    // ab F1 = F(n+1)
    long long theory = 2 * F1 - 1;
    naiveCalls = 0;
    fibNaive(n30);
    printf("\n theoretical calls(30) = 2·F(31) − 1 = 2·%lld − 1 = %lld\n", F1, theory);
    printf(" measured calls(30)   = %lld   → MATCH = %s\n",
           naiveCalls, (naiveCalls == theory ? "YES" : "NO"));
    printf(" DP steps(30)         = 29   → gap = %lld / 29 ≈ %lld× faster\n", theory, theory / 29);

    return 0;
}