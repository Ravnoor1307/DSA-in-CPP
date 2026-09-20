/*
═══════════════════════════════════════════════
 TASK SET — CATEGORIES OF TIME COMPLEXITY
 (O(1) … O(log n) … O(n) … O(n log n) … O(n²) … O(n³) … O(2ⁿ) … O(n!))
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Your chat app must deliver the list of a user's
 friends: direct look-up (O(1)), search one by one (O(n)), or compare
 every friend-pair for common interests (O(n²)). At 1,000 friends these
 feel the same — at 1,000,000 the category decides success or server
 crash. Naming the category correctly is a survival skill.

🧠 HOW TO SOLVE: NEVER write a bare O(?); always derive f(n) by counting
 loop iterations/recursive calls, reduce to its dominant term, then name
 the class. Verify with an opCount++ and use the "n double hone par"
 test (O(1)→same, O(log n)→+1, O(n)→×2, O(n²)→×4, O(2ⁿ)→square).

 Each task has TWO parts:
   (a) ANALYZE: full derivation of the counting formula and the class.
   (b) IMPLEMENT: compile-ready code with verification counters.

 TASK 1: Classify five code snippets (no counters needed).
   Fragment snippets:
     A. while (x > 1) x /= 2;
     B. for (i=0;i<n;i++) x += i;
     C. for (i=0;i<n;i++) for (j=0;j<n;j++) x++;
     D. for (i=0;i<n;i++) { y=n; while (y>1) y/=2; }
     E. int f(int k){ if(k==0) return 1; return f(k-1)+f(k-1); }
   (a) ANALYZE: for each, write f(n) and name the class. Which grows
       most? Least? Draw the doubling behaviour.
   (b) IMPLEMENT: wrap this block in variables and count the operations
       at n = 1000 (careful: cap n for exponential), printing a table of
       actual counts.
   💡 HINT: A=halving, B=single loop, C=nested, D=loop×halving,
            E=two recursive branches.
   ✏️ STARTER CODE:
       int x = 1000, cnt = 0;
       while (x > 1) { x /= 2; cnt++; }    // A ka counter

 TASK 2: The complete category table at two chosen sizes.
   (a) ANALYZE: write the exact f(n) for all 8 categories (as functions
       of n) BEFORE printing.
   (b) IMPLEMENT: instrument all 8 (choose n=1000 for the loop ones, and
       n=10/15 for exponential, n=6/7 for factorial) and print a table:
       category | n | count | derived formula | match?
   💡 HINT: table banate time har row ka formula likh kar cross-check.
   ✏️ STARTER CODE:
       // reuse: opsConstant, opsLog, opsLinear, opsNLogN,
       //        opsQuadratic, opsCubic, expCalls, factCalls

 TASK 3: Prove the doubling law with a live experiment.
   For O(n) and O(n²): count at n and at 2n; verify counts scale
   ~×2 and ~×4. For O(2ⁿ): count at n and n+1; verify ~×2 more.
   (a) ANALYZE: derive why doubling ratios are 2, 4 and 2 exactly in
       the limit; state what tiny discrepancies (like e·n! floor) cause.
   (b) IMPLEMENT: print the exact three experiments with counts.
   💡 HINT: O(n²): (2n)²/(n²)=4; O(2ⁿ): 2^(n+1)/2ⁿ=2.
   ✏️ STARTER CODE:
       int q(int n){int c=0; for(i..n) for(j..n) c++; return c;}
       cout << q(10) << " " << q(20);   // 100 → 400

 TASK 4: Read code, name the class — pattern recognition.
   A. for (i=0;i<n;i++) if (a[i]==x) break;          // ?
   B. for (i=0;i<n;i++) for (j=0;j<i;j++) x++;        // ?
   C. sort-like: merge halves (O(log n) levels, n work each) // ?
   D. for (i=0;i<n;i++) for (j=0;j<n;j++) for (k=0;k<n;k++) x += a[i]*b[j]*c[k]; // ?
   (a) ANALYZE: derive each; especially B — count the triangle sum
       i(i-1)/2 and show it is still quadratic.
   (b) IMPLEMENT: verify B for n=1000 prints a count that matches
       n(n-1)/2, not n².
   💡 HINT: B ka inner loop i baar chalta hai → sum 1+2+...+(n-1).
   ✏️ STARTER CODE:
       long long c = 0;
       for (int i = 0; i < n; i++)
           for (int j = 0; j < i; j++) c++;
       cout << c;   // n(n-1)/2

 TASK 5: Constraint → allowed category (decision task).
   A judge allows 10⁸ operations. Which of these solutions PASS?
     X. O(n)   n = 10⁶
     Y. O(n²)  n = 10⁶
     Z. O(2ⁿ)  n = 10⁶
   (a) ANALYZE: compute each solution's operation count with full
       formulas; only X survives. Show O(1) also always survives.
   (b) IMPLEMENT: a helper that takes (class, n) and returns the
       estimated ops; print accept/reject lines for all three.
   💡 HINT: X=10⁶ ≤ 10⁸ PASS; Y=10¹² → 10⁴ sec → REJECT;
            Z=2^10⁶ — an absurd 10^301029 digit number → REJECT.
   ✏️ STARTER CODE:
       struct Sol { string name; long long ops; };
       void check(Sol s) { cout << s.name << " → "
            << (s.ops <= 100000000 ? "PASS" : "REJECT") << "\n"; }

 TASK 6 (HARD): Pick a sorting approach under n = 10⁶ and justify.
   Two candidate sorts: S1 is O(n²), S2 is O(n log n).
   (a) ANALYZE: full counts: S1 ≈ n² = 10¹² ops; S2 ≈ n·log₂n =
       10⁶ × 20 ≈ 2×10⁷ ops. Which passes the 10⁸ budget? Then explain
       the same comparison on n = 100 — where constants can flip the
       outcome (S1 may win by having a tiny constant factor) — prove
       that for a single tiny input the CATEGORY is less decisive.
   (b) IMPLEMENT: simulate: time a 2-loop (≈S1-style) vs a merge-style
       loop at n=100 and n=10⁶ (using counters, not real sort), print
       both counts and the winner per size.
   💡 HINT: chhote n pe constants matter karte hain, bade n pe class.
   ✏️ STARTER CODE:
       // S1-style: double loop counter
       // S2-style: n * while(x/=2) counter

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

long long opsLogN(int n)   { long long c=0; while (n>1) { n/=2; c++; } return c; }
long long opsLin(int n)    { long long c=0; for(int i=0;i<n;i++) c++; return c; }
long long opsNLog(int n)   { long long c=0; for(int i=0;i<n;i++){ int y=n; while(y>1){ y/=2; c++; } } return c; }
long long opsQuad(int n)   { long long c=0; for(int i=0;i<n;i++) for(int j=0;j<n;j++) c++; return c; }
long long opsCube(int n)   { long long c=0; for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) c++; return c; }
long long expCalls(int k, long long& c) { c++; if(k==0) return c; expCalls(k-1,c); expCalls(k-1,c); return c; }
long long factCalls(int k, long long& c){ c++; if(k==0) return c; for(int i=0;i<k;i++) factCalls(k-1,c); return c; }

int main() {
    // TASK 1: verify the five fragments at n=1000
    {
        cout << "T1 (n=1000):\n";
        int n = 1000;
        long long ca = 0; int x = n;
        while (x > 1) { x /= 2; ca++; }            // A: log2 1000 ≈ 9
        long long cb = 0;
        for (int i = 0; i < n; i++) cb++;          // B: n
        long long cc = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cc++;   // C: n²
        long long cd = 0;
        for (int i = 0; i < n; i++) { int y = n; while (y > 1) { y /= 2; cd++; } }  // D: n·log n
        long long ce = 0;                          // E: 2^(n+1)-1 — n se bahut bada!
        expCalls(10, ce);                          // n=10 liya, n=1000 pe freeze ho jata
        cout << "  A=" << ca << "   B=" << cb << "   C=" << cc
             << "   D=" << cd << "   E(10)=" << ce << "\n";
        cout << "  →  classes: A=O(log n)  B=O(n)  C=O(n²)  D=O(n log n)  E=O(2ⁿ)\n";
    }

    // TASK 2: full category table
    {
        cout << "\nT2 category table:\n";
        long long c = 0;
        expCalls(15, c); long long e15 = c;
        c = 0; factCalls(7, c); long long f7 = c;
        cout << "  O(1)       n=any    f=1           -> " << 1 << "\n";
        cout << "  O(log n)   n=1024   f=log2n=10    -> " << opsLogN(1024) << "\n";
        cout << "  O(n)       n=1000   f=n=1000      -> " << opsLin(1000) << "\n";
        cout << "  O(n log n) n=1024   f=n*10=10240  -> " << opsNLog(1024) << "\n";
        cout << "  O(n^2)     n=1000   f=n^2=1e6     -> " << opsQuad(1000) << "\n";
        cout << "  O(n^3)     n=100    f=1e6         -> " << opsCube(100) << "\n";
        cout << "  O(2^n)     n=15     f=2^16-1=65535-> " << e15 << "\n";
        cout << "  O(n!)      n=7      f≈e*7!=13700  -> " << f7 << "\n";
    }

    // TASK 3: doubling law experiments
    {
        cout << "\nT3 doubling law:\n";
        cout << "  O(n) :  n=10 -> " << opsLin(10) << "   n=20 -> " << opsLin(20)
             << "   ratio=" << (double)opsLin(20) / opsLin(10) << " (~2)\n";
        cout << "  O(n²):  n=10 -> " << opsQuad(10) << "   n=20 -> " << opsQuad(20)
             << "   ratio=" << (double)opsQuad(20) / opsQuad(10) << " (~4)\n";
        long long c1 = 0; expCalls(20, c1);
        long long c2 = 0; expCalls(21, c2);
        cout << "  O(2ⁿ): n=20 -> " << c1 << "   n=21 -> " << c2
             << "   ratio=" << (double)c2 / c1 << " (~2)\n";
    }

    // TASK 4: triangle loop B at n=1000 → n(n-1)/2
    {
        int n = 1000;
        long long c = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) c++;
        long long pred = (long long)n * (n - 1) / 2;
        cout << "\nT4 triangle: actual=" << c << "  n(n-1)/2=" << pred
             << "  match? " << (c == pred ? "YES" : "NO")
             << "  → still O(n²)\n";
    }

    // TASK 5: constraint decision
    {
        cout << "\nT5 budget = 10^8 ops:\n";
        long long budget = 100000000;
        long long xOps = 1000000;                 // O(n), n=10^6
        long long yOps = (long long)1000000 * 1000000; // O(n²), n=10^6
        cout << "  X O(n)  n=10^6 -> " << xOps << " ops → "
             << (xOps <= budget ? "PASS" : "REJECT") << "\n";
        cout << "  Y O(n²) n=10^6 -> " << yOps << " ops → "
             << (yOps <= budget ? "PASS" : "REJECT") << "\n";
        cout << "  Z O(2ⁿ) n=10^6 -> astronomically large → REJECT\n";
    }

    // TASK 6: sort-style simulation at two sizes
    {
        cout << "\nT6 S1(n²) vs S2(n log n):\n";
        int nA = 100;
        long long s1a = opsQuad(nA);
        long long s2a = opsNLog(nA);
        cout << "  n=100   : S1=" << s1a << "  S2=" << s2a
             << "  → " << (s1a < s2a ? "S1 (class pehle slow lag raha)" : "S2") << "\n";
        int nB = 1000000;
        long long s1b = (long long)nB * nB;       // 10^12
        long long s2b = (long long)nB * 20;       // 10^6 × log2(10^6)≈20
        cout << "  n=10^6  : S1=" << s1b << "  S2=" << s2b
             << "  → " << (s2b < s1b ? "S2 (class decides at scale)" : "S1")
             << "  [budget 10^8: S2 PASS]\n";
    }
    return 0;
}
/*
 FULL ANALYSES:

 TASK 1 — A: halving, k = log₂n iterations → O(log n).
   B: n iterations → O(n).  C: n×n → O(n²).  D: n × log₂n → O(n log n).
   E: recursion C(k)=1+2C(k−1) → 2^(k+1)−1 → O(2ⁿ), fastest growing of the
   five by far — printing E at n=1000 would run ~10³⁰¹ calls (frozen).

 TASK 2 — derived formulas (verified by counters above):
   1, log₂n, n, n·log₂n, n², n³, 2^(n+1)−1, e·n! (e≈2.718).

 TASK 3 — O(n): f(2n)/f(n)=2n/n=2. O(n²): (2n)²/n²=4. O(2ⁿ):
   2^(n+1)/2ⁿ=2. Small discrepancies come from floors (log₂) and hidden
   constants — the ratios APPROACH these limits as n grows.

 TASK 4 — A: O(n) worst (early break helps best case only). B: inner j<i
   runs i times, sum 1..(n−1)=n(n−1)/2 → still O(n²) (verified). C: O(n
   log n). D: triple loop → O(n³).

 TASK 5 — X: 10⁶ ≤ 10⁸ → PASS. Y: (10⁶)² = 10¹² > 10⁸ → ~10⁴ seconds →
   REJECT. Z: 2^10⁶ is a number with ~301,029 digits — REJECT. Always
   translate the class into a concrete count against the constraint.

 TASK 6 — at n=10⁶: S1 = 10¹² ops vs S2 = 2×10⁷ → S2 PASSES the 10⁸
   budget, S1 REJECTED. At n=100 both are tiny (10⁴ vs ≈660); constants
   could flip the winner — so for BIG n the CATEGORY is decisive, for
   tiny n the constant factor is. Rule: n constraints decide the class;
   the class decides the algorithm.
*/