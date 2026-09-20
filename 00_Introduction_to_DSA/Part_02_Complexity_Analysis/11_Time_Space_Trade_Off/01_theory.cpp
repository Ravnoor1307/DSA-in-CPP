/*
═══════════════════════════════════════════════
 TIME-SPACE TRADE-OFF
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You are preparing for a mathematics exam. One student solves every
 problem from scratch — even the ones she cracked yesterday. She
 spends hours re-deriving the same results (huge time). A smarter
 student keeps a notebook: every answer she finds goes into the
 notebook once, then she simply LOOKS IT UP next time (extra space,
 but massive time saved). The notebook is memory; re-solving is time.
 That is the entire time-space trade-off: spend extra memory to save
 computation time, or recompute to save memory.

 📖 THEORY: (pure English, formal)

 The time-space trade-off is the principle that, for many problems,
 you may reduce running time by increasing memory usage, or reduce
 memory usage by increasing running time. The most important
 programming technique built on this is MEMOISATION (top-down DP):
 store the result of every subproblem the first time you compute it,
 then return the stored value instead of recomputing.

 OTHER TRADE-OFF EXAMPLES:
 - PREFETCHING: load the next data chunk into a cache BEFORE you need
   it — extra cache memory buys lower latency (e.g. CPU prefetchers).
 - INDEX TABLES: a database index is a separate sorted structure
   (extra space) that turns O(n) scans into O(log n) lookups.
 - LOOKUP TABLES: precompute sin/cos/factorial for 1…k once; each use
   is then O(1) instead of O(k).
 - COUNTING SORT: a count array of size k (extra space) sorts in
   O(n+k) instead of O(n²)-ish comparisons.

 KEY POINTS:
 - Memoisation works ONLY when subproblems OVERLAP (repeat).
 - Memo table dimensions = number of varying parameters of recursion.
 - Top-down (memoise) fills lazily; bottom-up (tabulate) fills all.
 - Extra memory is usually O(n) for 1-parameter, O(n²) for 2-parameter.
 - The trade-off is real: if memory were free, algorithms could
   precompute everything; if time were free, we'd recompute everything.

 ASCII: RECURSION TREE vs MEMO TABLE (n = 5):

  NAIVE RECURSION — full tree, repeated work:     MEMO TABLE — filled once:
                fib(5)                                ┌───┬───┬───┬───┬───┬───┐
               /      \                               │ 0 │ 1 │ 1 │ 2 │ 3 │ 5 │
          fib(4)       fib(3)                         └───┴───┴───┴───┴───┴───┘
          /    \       /    \                          fib[2]=fib[1]+fib[0]=1
      fib(3)  fib(2) fib(2) fib(1)                     fib[3]=fib[2]+fib[1]=2
       /  \    /  \    /  \                            fib[4]=fib[3]+fib[2]=3
   fib(2) fib(1) ... ... ...                          fib[5]=fib[4]+fib[3]=5
    / \                                                ────────────────
 fig(1) f(0)                                          Every cell written
   fib(3) computed 2x, fib(2) 3x,                       exactly ONCE —
   fib(1) 5x re-computed → waste!                      6 writes total.
   Lookup O(1) per reuse.

 WHEN TO USE IT:
 - Recursion revisits the SAME arguments repeatedly → memoise.
 - Need worst-case guarantees and memory is fine → trade time for space.
 - Input range small enough that extra space is affordable.
 - Do NOT use when subproblems are unique, or memory would explode.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Write the naive recursive Fibonacci and add a global step counter.
   WHY: You need a measurable baseline before you can show savings.

 Step 2: Write a memoised version: an array memo[0..n] + a flag array.
   WHY: memo stores answers; the flag tells whether memo[n] is ready
        (so you never recompute a finished value).

 Step 3: Trace the maximal recursion depth of each version.
   WHY: Recursion depth = call-stack memory = O(n) in BOTH versions
        (memoised still recurses n deep the first time it fills tables).

 Step 4: Count memory: naive stack O(n) vs memo table 8(n+1) bytes + stack.
   WHY: The trade-off's cost side is the extra TABLE (space) that buys
        us the time side.

 Step 5: Print a comparison table (n, steps, ~stack bytes, table bytes).
   WHY: Numbers make the trade-off concrete: n=30 → 2.7M vs 30 steps.

 VISUAL WALKTHROUGH:

  MEMOISED fib(5) recursion flow (each arrow fills one new cell):
    fib(5) → fib(4) → fib(3) → fib(2) → fib(1) =1  (base)
                       ↑        → fib(0) =0         (base)
              ← {memo[2] = fib(1)+fib(0) = 1}
         ← {memo[3] = memo[2]+fib(1) = 2}
    ← {memo[4] = memo[3]+memo[2] = 3}
  ← {memo[5] = memo[4]+memo[3] = 5}
  Total recursive calls = 9 (each subproblem exactly once).

 DRY RUN (n = 6):
  RECURSIVE:  fib(6) = fib(5)+fib(4)
    fib(5) visits: fib(4),fib(3),fib(2),fib(1),fib(0) many times.
    Total calls = 2·F(7)−1 = 2·13−1 = 25 calls.
  MEMOISED:  memo[6]  → memo[5] → memo[4] → memo[3] → memo[2] → memo[1]=1
                                                      → memo[0]=0
              memo[2]=1+0=1 ; memo[3]=1+1=2 ; memo[4]=2+1=3
              memo[5]=3+2=5 ; memo[6]=5+3=8 ✓
    Fresh computations = 7  (indices 0..6), total calls = 13.
  Ratio 25 vs 13 already; at n=30 it becomes 2.69M vs 59 calls.

 TIME COMPLEXITY CALCULATION:
  NAIVE RECURSIVE FIBONACCI:
    T(n) = T(n−1) + T(n−2) + O(1)
    Two sub-problems, each roughly half the size — a binary tree of
    height n with ≈ 2ⁿ nodes.
    Solving: characteristic equation x² = x + 1 → x = (1+√5)/2 = φ ≈ 1.618.
    T(n) = Θ(φⁿ). Since φ < 2, this is O(2ⁿ).
  MEMOISED FIBONACCI:
    Each distinct index k ∈ [0, n] is computed EXACTLY once (first visit),
    then looked up in O(1). So the work is the number of distinct
    subproblems (n+1) × O(1) per subproblem.
    T(n) = (n+1) · O(1) = O(n).
 → Time Complexity: naive O(2ⁿ)  vs  memoised O(n)

 SPACE COMPLEXITY CALCULATION:
  NAIVE: max recursion depth = n (call chain n → n−1 → … → 1).
         Each frame O(1) locals. Stack space = n · O(1) = O(n).
  MEMOISED: same recursion depth O(n) stack, PLUS:
         memo table = (n+1) × sizeof(long long) = 8(n+1) bytes,
         flag table = (n+1) × sizeof(bool)      =  (n+1) bytes,
         total table ≈ 9(n+1) bytes = O(n).
         Combined = O(n) stack + O(n) table = O(n).
 → Space Complexity: naive O(n) stack  vs  memoised O(n) (stack + table)

 APPROACH COMPARISON:
  ┌────────────────────┬──────────────────────┬──────────────────────┐
  │ Aspect             │ Naive recursion      │ Memoised (top-down DP)│
  ├────────────────────┼──────────────────────┼──────────────────────┤
  │ Time (n=30)        │ 2,692,537 steps      │ 59 steps             │
  │ Time (n=40)        │ ~331M steps (too slow)│ 79 steps             │
  │ Space (memo table) │ none (no table)      │ 8(n+1)+ (n+1) bytes  │
  │ Call-stack depth   │ O(n)                 │ O(n)                 │
  │ Result reuse       │ none — recompute     │ lookup after fill    │
  │ Trade-off          │ burns TIME to save   │ burns SPACE to save  │
  │                    │ SPACE                │ TIME                 │
  └────────────────────┴──────────────────────┴──────────────────────┘
*/

#include <iostream>
#include <cstdio>
using namespace std;

// ---------- counters ----------
long long recSteps = 0;                 // naive recursion ke calls
long long memoSteps = 0;                // memoised version ke calls

// frame byte estimate: stack frame ≈ 2 longs + return addr + bookkeeping ≈ 48B on 64-bit
const long long FRAME_BYTES = 48;
const long long FIB_MAX = 200;          // memo array size, n chhota hi rakhenge baaki theory ke liye

long long memo[FIB_MAX];                // memo table — har value YAHIN save hoti hai (space)
bool  filled[FIB_MAX] = {false};        // flag — memo[k] ready hai ya nahi

// NAIVE recursive — time bachat 0, har value baar-baar recompute
long long fibRec(int n) {
    recSteps++;                          // 1 call = 1 step
    if (n <= 1) return n;                // base case
    return fibRec(n - 1) + fibRec(n - 2); // 2 naye calls → binary tree
}

// MEMOISED recursive — pehli baar compute karke memo mein store, agle baar lookup
long long fibMemo(int n) {
    memoSteps++;                         // har call count (including lookups)
    if (n <= 1) return n;                // edge case
    if (filled[n]) return memo[n];       // TABLE: pehle se pata hai → O(1) lookup, koi compute nahi!
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2); // first time — compute aur save
    filled[n] = true;                    // ab flag mark — dubara recompute nahi hoga
    return memo[n];
}

// ek value n ke liye dono versions chala ke table row print karta hai
void compare(int n) {
    recSteps = 0;
    memoSteps = 0;
    for (int i = 0; i < FIB_MAX; i++) filled[i] = false; // memo reset

    long long rRec = fibRec(n);          // naive
    long long rMem = fibMemo(n);         // memoised

    // memory accounting — stack depth dono mein O(n); table sirf memoised mein
    long long stackBytesBoth = FRAME_BYTES * (long long)n;         // depth n ka stack
    long long tableBytes     = (long long)(sizeof(long long)) * (n + 1)  // memo[]
                             + (long long)(sizeof(bool)) * (n + 1);      // filled[]
    bool ok = (rRec == rMem);

    printf("│ %3d │ %16lld │ %14lld │ %14lld │ %12lld KB │ %12lld KB │ %s │\n",
           n, rRec, recSteps, memoSteps,
           (stackBytesBoth + (n == 0 ? 0 : tableBytes)) / 1024,
           (tableBytes) / 1024,  ok ? "YES" : "NO");
}

int main() {
    cout << "══════════════════════════════════════════════════════════════════" << endl;
    cout << "   TIME-SPACE TRADE-OFF — FIBONACCI: recursion vs memoisation" << endl;
    cout << "══════════════════════════════════════════════════════════════════" << endl;

    cout << "\n Fibonacci Definition:\n"
         << "   fib(0)=0, fib(1)=1, fib(n)=fib(n-1)+fib(n-2)\n"
         << "   Naive → T(n)=T(n-1)+T(n-2)+O(1) ≈ O(2ⁿ)\n"
         << "   Memo  → har index exactly 1 baar compute, baaki lookup → O(n)\n";

    printf("\n┌─────┬──────────────────┬────────────────┬────────────────┬─────────────────┬─────────────────┬───────┐\n");
    printf("│  n  │  Fib(n) answer   │  naive steps  │  memo steps   │ ~stack+table KB │  ~memo table KB │ equal │\n");
    printf("├─────┼──────────────────┼────────────────┼────────────────┼─────────────────┼─────────────────┼───────┤\n");
    compare(5);
    compare(10);
    compare(15);
    compare(20);
    compare(25);
    compare(30);
    compare(35);
    printf("└─────┴──────────────────┴────────────────┴────────────────┴─────────────────┴─────────────────┴───────┘\n");

    cout << "\n Observation:\n"
         << "  • n=30 → naive ~2.69M steps, memoised only ~59 steps (≈46,000× faster)\n"
         << "  • TRADE-OFF: woh speed 8(n+1)+(n+1) bytes ke memo table se aayi\n"
         << "  • Naive assumes stack O(n) but recomputes; memo keeps BOTH stack O(n)\n"
         << "    AND table O(n) — same space class, exponentially less time.\n";

    cout << "\n═══════════ SECOND TRADE-OFF DEMO — INDEX/LUT: counting sort (O(n+k)) vs bubble (O(n²)) ═══════════" << endl;
    // Index/Lookup-table pattern: extra count array buys linear time.
    {
        const int MAXV = 1000;
        int n = 5000;
        int* a = new int[n];
        int* b = new int[n];
        for (int i = 0; i < n; i++) a[i] = b[i] = ((i * 37) % MAXV); // deterministic pseudo-random

        // bubble: O(n²) comparisons
        long long cnt = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1 - i; j++) {
                cnt++;
                if (b[j] > b[j + 1]) swap(b[j], b[j + 1]);
            }

        // counting sort: extra count[] array (size MAXV) → O(n + MAXV)
        int* countArr = new int[MAXV]();  // index table — extra space MAXV ints
        for (int i = 0; i < n; i++) countArr[a[i]]++;   // O(n) — count frequency
        int w = 0;
        for (int v = 0; v < MAXV; v++)
            while (countArr[v]--) a[w++] = v;           // O(n + MAXV) write-back
        delete[] countArr;

        printf(" n=%d, value range ≤ %d:\n", n, MAXV);
        printf("   bubble  comparisons = %lld  → O(n²)\n", cnt);
        printf("   counting ops ~ O(n+k) → index/LUT table(extra %d ints) ne time O(n²)→O(n+k) kar diya\n", MAXV);
        delete[] a;
        delete[] b;
    }

    // Edge case demo: n=0 aur n=1 — dono versions same answer
    cout << "\n Edge cases:" << endl;
    recSteps = 0; memoSteps = 0;
    for (int i = 0; i < FIB_MAX; i++) filled[i] = false;
    cout << "   fibRec(0)=" << fibRec(0) << "  steps=" << recSteps << endl;
    cout << "   fibMemo(0)=" << fibMemo(0) << "  steps=" << memoSteps << endl;
    recSteps = 0; memoSteps = 0;
    for (int i = 0; i < FIB_MAX; i++) filled[i] = false;
    cout << "   fibRec(1)=" << fibRec(1) << "  steps=" << recSteps << endl;
    cout << "   fibMemo(1)=" << fibMemo(1) << "  steps=" << memoSteps << endl;

    return 0;
}