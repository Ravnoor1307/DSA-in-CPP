/*
═══════════════════════════════════════════════
 TASKS — TIME-SPACE TRADE-OFF
═══════════════════════════════════════════════

 THEORY RECAP (use it to guide your solutions):
   Trade-off: extra memory (memo table) buys time by eliminating
   recomputation. Naive fib: T(n)=T(n−1)+T(n−2)+O(1) → O(2ⁿ).
   Memoised fib: each index computed once → O(n) time, O(n) space.
   Framing that matters: EMPIRICAL comparison is the goal — measure
   both step counts AND the bytes of the memo table.

   Ground rules for all tasks:
     (a) Always count BOTH time steps and memory bytes.
     (b) Recap the recurrence T(n)=T(n−1)+T(n−2)+O(1) whenever asked
         to derive a class.

──────────────────────────────────────────
 TASK 1 — MEMOISED FIB: BUILD IT, MEASURE BOTH METRICS
──────────────────────────────────────────
 Problem:
   Implement fibMemo(n) with:
     • a global counter memoSteps that counts EVERY function call;
     • a memo table (array of long long) + a filled[] flag array;
     • the rule "compute once, then look up".
   Also keep a naive fibRec(n) with its own counter. For n = 10, 20,
   30 print: answer, naive steps, memo steps, ratio, and the memo
   table bytes 8(n+1) + (n+1). Then answer in a comment: WHY is memo
   still O(n) space even though it's faster than naive's O(2ⁿ) time?

 💡 HINT: the two arrays are exactly the "extra memory" side of the
          trade-off; the counter difference is the "time saved" side.

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   long long memoSteps = 0;
   long long memo[200];
   bool filled[200] = {false};        // pehle sab false
   long long fibMemo(int n) {
       // 1) counter++ 2) base n<=1 3) if filled[n] return memo[n]
       // 4) compute, save in memo[n], set filled[n], return
   }
   int main() {
       // n=10,20,30 ke liye compare + table bytes print
       return 0;
   }

──────────────────────────────────────────
 TASK 2 — HOW MANY TIMES DOES fibMemo REVISIT A CELL? PROVE O(n)
──────────────────────────────────────────
 Problem:
   Instrument fibMemo so it also counts MEMO LOOKUPS (calls where
   filled[n]==true). Count them for n = 10, 20, 30. Derive in a
   comment: the total work = (number of fresh computations) + (number
   of lookups) = O(n) + O(n) = O(n). Also count (naively) how many
   times fibRec computes fib(3) when computing fib(n) — this is the
   redundant work the table eliminates.

 💡 HINT: fib(3) appears exactly F(n−2)·? times among leaves — count
          it with a tiny probe counter inside fibRec when x==3.

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   long long lookupCount = 0;
   long long fib3Count   = 0;
   long long fibRecProbe(int n) {
       // agar n == 3 → fib3Count++
       // normal naive recursion
   }
   long long fibMemoProbe(int n) {
       // agar filled[n] == true → lookupCount++
       // else compute & fill
   }
   int main() {
       // dono counters ko n=20 par print karo
       return 0;
   }

──────────────────────────────────────────
 TASK 3 — APPLY THE SAME TRADE-OFF: STAIR-CLIMBING (1 or 2 steps)
──────────────────────────────────────────
 Problem:
   There are n stairs. You may climb 1 or 2 stairs at a time. The
   number of ways is WAYS(n)=WAYS(n−1)+WAYS(n−2) (same recurrence,
   base WAYS(0)=WAYS(1)=1). Implementation parallels fib:
   naive WAYS (O(2ⁿ) time) vs memoised WAYS (O(n) time + O(n) memo).
   Compare step counters for n = 10, 20, 30 and confirm both answers
   equal (the staircase answers are fib(n+1)).

 💡 HINT: sol is fib(n+1). Reuse the memo[] table structure but adapt
          bases. Reset counters between runs!

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   long long wNaive = 0;
   long long waysNaive(int n) {
       // base n<=1 → 1 ; else two calls
   }
   long long wMemo = 0;
   long long memoW[1000];
   bool filledW[1000] = {false};
   long long waysMemo(int n) {
       // base; if filledW → return; else compute+store
   }
   int main() {
       // n=10,20,30 → print wNaive vs wMemo counters aur answers
       return 0;
   }

-------------- SOLUTIONS --------------
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 300;

// ---------- global counters for tasks 1 & 2 ----------
long long recSteps = 0;
long long memoSteps = 0;
long long lookupSteps = 0;
long long fib3Probe = 0;

long long memo[MAXN];
bool filled[MAXN] = {false};

// naive fib — har call count, aur x==3 jalate time probe bhi
long long fibRec(int n) {
    recSteps++;
    if (n == 3) fib3Probe++;          // TASK 2: kitni baar fib(3) kaam kiya
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

// memoised fib — compute-once, lookup-forever
long long fibMemo(int n) {
    memoSteps++;                       // EVERY call counted (fresh + lookup)
    if (n <= 1) return n;
    if (filled[n]) {
        lookupSteps++;                 // TASK 2: yahin lookup hua — saved work
        return memo[n];
    }
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2); // fresh compute + store
    filled[n] = true;
    return memo[n];
}

// ---------- TASK 3: stair-climbing, same recurrence, different base ----------
long long wNaive = 0;
long long waysNaive(int n) {
    wNaive++;
    if (n <= 1) return 1;              // 0 ya 1 stair → 1 way
    return waysNaive(n - 1) + waysNaive(n - 2); // 1-step ya 2-step
}

long long wMemo = 0;
long long memoW[MAXN];
bool filledW[MAXN] = {false};
long long waysMemo(int n) {
    wMemo++;
    if (n <= 1) return 1;
    if (filledW[n]) return memoW[n];   // lookup — spare time!
    memoW[n] = waysMemo(n - 1) + waysMemo(n - 2);
    filledW[n] = true;
    return memoW[n];
}

// sab memo tables reset
void resetTables() {
    for (int i = 0; i < MAXN; i++) { filled[i] = false; filledW[i] = false; }
}

int main() {
    cout << "══════════════════════════════════════════════════" << endl;
    cout << "   TIME-SPACE TRADE-OFF — TASK SOLUTIONS" << endl;
    cout << "══════════════════════════════════════════════════" << endl;

    // ==================== TASK 1 ====================
    cout << "\n═══ TASK 1 — naive vs memoised fib (steps + memo bytes) ═══" << endl;
    printf("┌──────┬──────────────┬──────────────┬──────────────┬────────────┬──────────────────┐\n");
    printf("│   n  │  naive steps │  memo steps  │     ratio    │  memo table │  answers equal   │\n");
    printf("├──────┼──────────────┼──────────────┼──────────────┼────────────┼──────────────────┤\n");
    int seq[] = {10, 20, 30};
    for (int k = 0; k < 3; k++) {
        int n = seq[k];
        recSteps = 0; memoSteps = 0; lookupSteps = 0;
        resetTables();
        long long r1 = fibRec(n);
        long long r2 = fibMemo(n);
        long long tableBytes = (long long)(sizeof(long long)) * (n + 1)   // memo[]
                             + (long long)(sizeof(bool)) * (n + 1);       // filled[]
        printf("│ %4d │ %12lld │ %12lld │ %10lld× │ %9lld B │          %s         │\n",
               n, recSteps, memoSteps, recSteps / (memoSteps > 0 ? memoSteps : 1),
               tableBytes, (r1 == r2 ? "YES" : "NO"));
    }
    printf("└──────┴──────────────┴──────────────┴──────────────┴────────────┴──────────────────┘\n");
    cout << " Why still O(n) space despite O(n) time? BECAUSE:\n"
         << "   trade-off buys TIME with SPACE;\n"
         << "   naive: O(2ⁿ) time, O(n) call-stack space (no table).\n"
         << "   memo:  O(n)  time, O(n) table + O(n) stack = O(n) total.\n"
         << "   Space class sama rehta (donon O(n)), time exponentially ghatta.\n";

    // ==================== TASK 2 ====================
    cout << "\n═══ TASK 2 — memo lookups vs naive redundancy ═══" << endl;
    for (int k = 0; k < 3; k++) {
        int n = seq[k];
        recSteps = 0; memoSteps = 0; lookupSteps = 0; fib3Probe = 0;
        resetTables();
        fibRec(n);                     // naive — probe fib(3) count
        fibMemo(n);                    // memo — lookup count
        printf(" n=%3d:  naive fib(3) computed %lld times.\n", n, fib3Probe);
        printf("         memo fresh steps = %lld, lookup steps = %lld\n",
               memoSteps - lookupSteps, lookupSteps);
    }
    cout << " Derivation: memo work = fresh(n+1 subproblems) + lookups,\n"
         << "   each O(1) → total O(n). Naive recomputes fib(3) ~2^(n−3) times\n"
         << "   — the table replaces ALL of those with a single O(1) read.\n";

    // ==================== TASK 3 ====================
    cout << "\n═══ TASK 3 — stair climbing: same trade-off pattern ═══" << endl;
    printf("┌──────┬──────────────┬──────────────┬──────────────┬─────────────┐\n");
    printf("│   n  │ waysNaive stp│ waysMemo stp │  ways(n) ans │  = fib(n+1)?│\n");
    printf("├──────┼──────────────┼──────────────┼──────────────┼─────────────┤\n");
    int sseq[] = {10, 20, 30};
    for (int k = 0; k < 3; k++) {
        int n = sseq[k];
        wNaive = 0; wMemo = 0;
        for (int i = 0; i < MAXN; i++) filledW[i] = false;
        long long w1 = waysNaive(n);
        long long w2 = waysMemo(n);

        // fib(n+1) cross-check: compute iterative fib(n+1)
        long long a = 0, b = 1, f = 1;
        for (int i = 2; i <= n + 1; i++) { f = a + b; a = b; b = f; }
        printf("│ %4d │ %12lld │ %12lld │ %10lld │        %s     │\n",
               n, wNaive, wMemo, w1, (w1 == f ? "YES" : "NO"));
    }
    printf("└──────┴──────────────┴──────────────┴──────────────┴─────────────┘\n");
    cout << " Insight: ways(n) = fib(n+1). Recurrence identical → same trade-off:\n"
         << "   naive O(2ⁿ) vs memoised O(n) time + O(n) memo space.\n";
    cout << "   Answer w1 == fib(n+1) confirms: WAYS(0)=WAYS(1)=1 base gives fib offset.\n";

    return 0;
}