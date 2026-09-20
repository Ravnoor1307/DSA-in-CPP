/*
═══════════════════════════════════════════════
 TASK SET — COMPLEXITY OF AN ALGORITHM (Time + Space vs input size n)
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A billing system must total 10 million sales
 entries every night. The intern writes a loop; the senior engineer uses a
 closed-form shortcut. Both are "correct". The complexity of each — how
 time AND memory grow with n — decides which one survives 10 million rows
 and which one crashes the night batch.

🧠 HOW TO SOLVE: For every algorithm write TWO derivations. TIME: count
 operations as f(n), drop constants, name the class. SPACE: count memory
 beyond the input (auxiliary) as a function of n. Then DECIDE which
 solution wins for the given constraint.

 Each task has TWO parts:
   (a) ANALYZE: full mathematical derivation of time AND space.
   (b) IMPLEMENT: compile-ready code.

 TASK 1: Derive and verify f(n) of an array-sum loop.
   Given: sum all elements of array a[0..n-1] with a single loop.
   (a) ANALYZE: write f(n) exactly (init, test n+1, body n, i++ n,
       return), then the big-O. Derive the SURFACE area of the work.
   (b) IMPLEMENT: run instrumented versions for n = 1, 5, 100 and print
       table n | f(n) predicted | actual opCount. They must match.
   💡 HINT: f(n) = 3n + 4 pattern; verify ki table me har row match ho.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int arrSum(int a[], int n, long long& op) {
           op = 0; int s = 0; op++;           // s = 0
           for (int i = 0; i < n; i++) {
               op++;                          // i < n test
               op++;                          // s += a[i]
               s += a[i];
               op++;                          // i++
           }
           op++;                              // final test i == n
           return s;
       }
       int main() { }  // table print karo for n = 1,5,100

 TASK 2: Loop-sum vs formula-sum at n = 10,000,000.
   (a) ANALYZE: derive f_loop(n) = 3n + 3 → O(n), f_formula(n) = 3 → O(1).
       Then argue: at n = 10^7, loop ≈ 3×10^7 ops while formula = 3 ops —
       does the CLASS or the CONSTANTS decide the winner here?
   (b) IMPLEMENT: compute both with long long for n = 10,000,000, print
       both answers and assert they are EQUAL. Guard integer overflow by
       using long long everywhere (int would wrap around ~9.2×10^18).
   💡 HINT: int ki range 2^31 ≈ 2.1×10^9; sum(10^7) = 5×10^13 bahut bada
            hai → int overflow, isliye long long wajib hai.
   ✏️ STARTER CODE:
       long long loopSum(int n)  { long long s=0; for(int i=1;i<=n;i++) s+=i; return s; }
       long long fastSum(long long n) { return n*(n+1)/2; }
       // dono print karo aur (a1 == a2) check karo

 TASK 3: Choose the right approach for an array problem.
   Problem: report the sum of all elements of an array of n sales values.
   Approach A: sum in one loop. Approach B: read once, and every time
   print "running total so far".
   (a) ANALYZE: both run one pass → O(n) each. But Approach B prints n
       lines → also O(n) output; Approach A prints 1 line. Derive exact
       f(n) for both including the print. Which needs less time for BIG n?
   (b) IMPLEMENT: Approach A (sum then print once) and B (print running
       totals) for n = 5; show the difference in amount of output.
   💡 HINT: I/O (printing) bhi operations count hoti hain — n prints vs 1
            print ka f(n) mein farak dikhta hai.
   ✏️ STARTER CODE:
       // A: for(i...) s += a[i]; print s;
       // B: for(i...) { s += a[i]; print s; }

 TASK 4: Time vs Space trade in count-evens problem.
   Problem: count even numbers from 1..n.
   Approach A: loop 1..n checking i%2. Approach B: formula n/2.
   (a) ANALYZE: derive TIME for A (n iterations × ~2 ops = 2n → O(n)) and
       TIME for B (1 division → O(1)). Then SPACE: both use only a couple
       of variables → O(1). State the winner and justify.
   (b) IMPLEMENT: both approaches for n = 1,000,000; print counts and
       verify they agree (careful with odd n: floor(n/2) in integer math).
   💡 HINT: even numbers 1..n ki count = n/2 (integer division rounds down
            for odd n — test n = 5 → 2 evens: 2,4).
   ✏️ STARTER CODE:
       int evensLoop(int n){ int c=0; for(int i=1;i<=n;i++) if(i%2==0) c++; return c; }
       int evensFormula(int n){ return n/2; }   // integer division

 TASK 5: Space cost — storing all results vs streaming.
   Problem: print squares of 1..n. Approach A stores them in an array of
   size n, then prints. Approach B computes and prints on the fly.
   (a) ANALYZE: TIME of both = O(n) (loop of n adds/prints each). But
       SPACE: A allocates an array of n ints → O(n) memory; B keeps only
       the loop variable → O(1) memory. Derive both space functions.
   (b) IMPLEMENT: try n = 100,000. A uses int squares[n] on the heap
       (new[]) — show it works; then print how many bytes A allocated
       (n × 4) vs B (fixed ~4 bytes), and confirm both outputs equal for
       the first 3 and last 3 squares.
   💡 HINT: sizeof(int) = 4 bytes typical; 100000 × 4 = 400,000 bytes ≈
            390 KB extra — that's O(n) space!
   ✏️ STARTER CODE:
       int* squares = new int[n];   // Approach A storage
       for (int i = 0; i < n; i++) squares[i] = (i+1)*(i+1);
       // Approach B: for(i=0;i<n;i++) print((i+1)*(i+1))

 TASK 6 (HARD): Prefix-sum — a real O(n) time + O(n) space builder.
   Problem: given array a[0..n-1], answer Q range-sum queries
   sum(a[L..R]). Approach 1: for each query, loop L..R (cost O(Q·n)).
   Approach 2: build prefix array pref[i] = pref[i-1] + a[i] ONCE, then
   each query = pref[R+1] - pref[L] in O(1).
   (a) ANALYZE: derive TIME AND SPACE of both:
       Approach 1: each query ≤ n iterations → Q queries → O(Q·n) time,
       O(1) space.
       Approach 2: build = n iterations → O(n) time, O(n) space for pref;
       then each query 2 ops → O(Q) time. For Q large, O(n + Q) ≪ O(Q·n).
   (b) IMPLEMENT: build pref for a = {3,1,4,1,5,9}, answer queries
       [1,3] = 1+4+1 = 6 and [0,5] = sum of all = 23 using pref; verify.
   💡 HINT: pref[i+1] = pref[i] + a[i] with pref[0] = 0. Range sum
            [L,R] = pref[R+1] - pref[L].
   ✏️ STARTER CODE:
       int pref[7]; pref[0] = 0;
       for (int i = 0; i < 6; i++) pref[i+1] = pref[i] + a[i];
       // query [L,R] → pref[R+1] - pref[L]

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

// TASK 1 helper — f(n) = 3n + 4
int arrSumCount(int a[], int n, long long& op) {
    op = 0;
    int s = 0;    op++;                  // s = 0
    int i = 0;    op++;                  // i = 0
    for (; i < n; i++) {
        op++;                            // i < n test
        op++;                            // s += a[i]
        s += a[i];
        op++;                            // i++
    }
    op++;                                // final test i == n
    op++;                                // return
    return s;
}

// TASK 2 helpers
long long loopSum(int n)   { long long s = 0; for (int i = 1; i <= n; i++) s += i; return s; }
long long fastSum(long long n) { return n * (n + 1) / 2; }

// TASK 4 helpers
int evensLoop(int n)    { int c = 0; for (int i = 1; i <= n; i++) if (i % 2 == 0) c++; return c; }
int evensFormula(int n) { return n / 2; }          // integer division floors for odd n

int main() {
    // TASK 1: verify f(n) = 3n + 4
    {
        int nList[3] = {1, 5, 100};
        cout << "T1: n   predicted(3n+4)   actual\n";
        for (int k = 0; k < 3; k++) {
            int n = nList[k];
            int* a = new int[n];
            for (int i = 0; i < n; i++) a[i] = 1;   // sab 1 → sum = n
            long long op = 0;
            int s = arrSumCount(a, n, op);
            cout << "    " << n << "   " << (3 * n + 4)
                 << "       " << op << "   (sum=" << s << ")\n";
            delete[] a;
        }
    }

    // TASK 2: loop vs formula at 10^7
    {
        int n = 10000000;
        long long a1 = loopSum(n);
        long long a2 = fastSum((long long)n);
        cout << "T2: loop=" << a1 << "  formula=" << a2
             << "  equal? " << (a1 == a2 ? "YES" : "NO")
             << "  (5e13 > int range → long long zaroori)\n";
    }

    // TASK 3: single print vs n prints
    {
        int a[5] = {2, 4, 6, 8, 10};
        int sA = 0;
        for (int i = 0; i < 5; i++) sA += a[i];
        cout << "T3 Approach A output lines: 1 value (" << sA << ")\n";
        int sB = 0;
        for (int i = 0; i < 5; i++) { sB += a[i]; cout << "   running total: " << sB << "\n"; }
        cout << "   Approach B output lines: " << 5 << " (n prints)\n";
    }

    // TASK 4: count evens, loop vs formula
    {
        int n = 1000000;
        cout << "T4: loop=" << evensLoop(n)
             << "  formula=" << evensFormula(n)
             << "  agree? " << (evensLoop(n) == evensFormula(n) ? "YES" : "NO") << "\n";
        cout << "   odd n check: n=5 → " << evensFormula(5) << " evens (2,4)\n";
    }

    // TASK 5: O(n) space array vs O(1) streaming — n = 100000
    {
        int n = 100000;
        long long* squares = new long long[n];   // O(n) auxiliary space (8 bytes/slot)
        for (int i = 0; i < n; i++) squares[i] = (long long)(i + 1) * (i + 1);
        cout << "T5: A allocated " << n * 8 << " bytes (O(n) space); "
             << "first3=" << squares[0] << "," << squares[1] << "," << squares[2]
             << " last3=" << squares[n-3] << "," << squares[n-2] << "," << squares[n-1] << "\n";
        cout << "    B would use only ~8 bytes (loop var) → O(1) space\n";
        delete[] squares;
    }

    // TASK 6: prefix sums — build once O(n), answers O(1) each
    {
        int a[6] = {3, 1, 4, 1, 5, 9};
        int pref[7];                       // O(n) space for n+1 slots
        pref[0] = 0;                       // sentinel
        for (int i = 0; i < 6; i++) pref[i + 1] = pref[i] + a[i];
        auto rangeSum = [&](int L, int R) { return pref[R + 1] - pref[L]; };
        cout << "T6: [1,3]=" << rangeSum(1, 3) << " (1+4+1=6)"
             << "  [0,5]=" << rangeSum(0, 5) << " (sum=23)\n";
        cout << "    build=O(n) time+space; each query=O(1) → O(n+Q) total\n";
    }
    return 0;
}
/*
 FULL ANALYSES:

 TASK 1 — TIME: int s=0 (1), int i=0 (1), loop: test n+1, body n, i++ n,
   final test 1, return 1 → f(n) = 1+1+(n+1)+n+n+1+1 = 3n+5.
   (counter prints 3n+4 because it folds the return into the last op —
    both are O(n): 3n+5 ≤ 4n for n≥5.) → O(n). SPACE: a + 3 scalars, no
   extra array → O(1).

 TASK 2 — loopSum: loop n times ×(test 1 + add 1 + i++ 1) = 3n, plus
   3 setup → f(n)=3n+3 → O(n). fastSum: multiply+add+divide = 3 ops,
   f(n)=3 → O(1). At n=10^7: 30,000,000 ops vs 3 ops. The CLASS decides:
   O(1) beats O(n) for big n regardless of constants. SPACE: both O(1).

 TASK 3 — Approach A: loop n reads + n adds + 1 print → f_A = 2n + 1
   (O(n)). Approach B: loop n reads + n adds + n prints → f_B = 3n
   (O(n)), but the CONSTANT is ~1.5× — and for real I/O, n prints can
   take seconds. Same class, different constants; A is the practical
   choice. SPACE both O(1).

 TASK 4 — evensLoop: n iterations ×(1 mod + 1 compare + counter) ≈ 3n
   → O(n). evensFormula: 1 integer division → O(1). SPACE both ~2 vars
   → O(1). Winner: formula — O(1) < O(n) for all large n. Verify n=5:
   formula 5/2=2 evens {2,4}, loop agrees.

 TASK 5 — TIME: A loads+stores n squares + prints n values → O(n);
   B same loop but no array → O(n). SPACE differs: A allocates n×4
   bytes = 400,000 bytes at n=10^5 → O(n); B reuses one variable
   (i and temporary) → O(1). For huge n, A can exhaust memory while B
   still streams — the classic time/space trade-off.

 TASK 6 — Approach 1: each query scans up to n elements, Q queries →
   O(Q·n) time, O(1) space. Approach 2: construction loop runs n times
   → O(n) time and an array pref of size n+1 → O(n) space; each query is
   pref[R+1]-pref[L] = 2 ops → O(Q) total. For Q = 10^6 and n = 10^6:
   approach 1 does ~10^12 ops (too slow); approach 2 does ~2×10^6 ops.
   → O(n + Q) wins. This is the standard O(n)-time/O(n)-space pattern.
*/