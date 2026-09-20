/*
═══════════════════════════════════════════════
 TASK SET — ANALYZING AN ALGORITHM (Priori vs Posteriori)
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Your startup must sort 10 million customer
 records nightly. Before buying a bigger server you need to know: which
 sorting approach will finish in time? You first *count operations on
 paper* (Priori analysis), then you *run a prototype under a stopwatch*
 (Posteriori analysis). Both skills — math prediction and clock
 measurement — are exactly what these tasks train.

🧠 HOW TO SOLVE: For Priori — replace every loop with its iteration count
 and sum the constant work inside it into a formula f(n); then drop
 constants to get the class. For Posteriori — wrap the call between
 chrono::high_resolution_clock::now() calls and print elapsed time.

 Each task has TWO parts:
   (a) ANALYZE: give the FULL mathematical derivation (no bare O(?)).
   (b) IMPLEMENT: compile-ready code.

 TASK 1: Count operations of a linear-sum function (PRIORI).
   For the function below, count basic operations exactly:
       int sum(int a[], int n) {
           int s = 0;
           for (int i = 0; i < n; i++) s += a[i];
           return s;
       }
   (a) ANALYZE: write f(n) exactly (include i++ and the loop test), then
       derive the big-O class with the working shown.
   (b) IMPLEMENT: instrument this function with an opCount and verify
       that for n=5 the printed count matches your f(5).
   💡 HINT: i++ bhi ek operation hai aur i<n ka test bhi (n+1) baar hai.
   ✏️ STARTER CODE:
       // starter: copy karo aur opCount add karo
       #include <iostream>
       using namespace std;
       int sumWithCount(int a[], int n, int& op) {
           int s = 0;
           // TODO: loop har iteration pe op++ karo (test + i++ dono count karo)
           return s;
       }
       int main() {
           int a[5] = {1, 2, 3, 4, 5};
           int op = 0;
           int total = sumWithCount(a, 5, op);
           cout << total << " " << op << "\n";
           return 0;
       }

 TASK 2: Instrument findMax and verify the n-1 formula (PRIORI).
   (a) ANALYZE: prove that findMax needs exactly n-1 comparisons for any
       array of length n ≥ 1. Write the full derivation.
   (b) IMPLEMENT: run findMax with opCount on n = 1, 6, 100 and print a
       table: n | predicted n-1 | actual opCount.
   💡 HINT: loop i=1 se n-1 tak chalta hai, har iteration 1 comparison.
   ✏️ STARTER CODE:
       // starter: findMax copy karo jisme pehle element se loop start ho
       int findMaxCounted(int a[], int n, int& op) { }  // TODO: counter lagao

 TASK 3: Measure runtime at 3 input sizes (POSTERIORI).
   Run the SAME sum function for n = 10,000, then 100,000, then
   1,000,000 using chrono, and print elapsed microseconds each time.
   (a) ANALYZE: from your measurements, does the time roughly double when
       n grows 10x? Explain with the Priori expectation (linear → 10x ops
       → roughly 10x time, ignoring machine noise).
   (b) IMPLEMENT: a loop over three sizes, each timed separately.
   💡 HINT: 3 alag-alag arrays banao ya ek hi ko 3 baar chalao; timer
            SEEDHI tarah call ko wrap karo.
   ✏️ STARTER CODE:
       auto st = chrono::high_resolution_clock::now();
       long long s = sumBig(arr, n);
       auto en = chrono::high_resolution_clock::now();
       cout << duration_cast<chrono::microseconds>(en - st).count() << "us\n";

 TASK 4: Priori comparison of two code fragments.
   Fragment A has two loops one after another (each n iterations).
   Fragment B has two nested loops (outer n, inner n).
   (a) ANALYZE: derive f_A(n) and f_B(n) with full working; state both
       complexity classes. Show that "add for sequential, multiply for
       nested" is the rule.
   (b) IMPLEMENT: run both fragments for n = 1000 and count the exact
       number of i++/j++ operations actually executed; print the ratio
       f_B/f_A to confirm ~n/2 = 500.
   💡 HINT: A = n + n = 2n → O(n); B = n × n = n² → O(n²).
   ✏️ STARTER CODE:
       long long A = 0, B = 0;
       for (int i = 0; i < n; i++) A++;   // pehla loop
       for (int i = 0; i < n; i++) A++;   // dusra loop
       for (int i = 0; i < n; i++)
           for (int j = 0; j < n; j++) B++;   // nested → n^2

 TASK 5: Check correctness of code reading (ANALYZE characteristic).
   Take this function and decide whether it is CORRECT for all inputs:
       int max2(int a[], int n) {
           int m = a[0];
           for (int i = 1; i < n; i++)
               if (a[i] < m) m = a[i];      // "<" deliberately planted
           return m;
       }
   (a) ANALYZE: it returns the MINIMUM, not the maximum — the comparator
       is wrong. This shows correctness is an independent characteristic:
       an algorithm can be fast (O(n)) yet WRONG.
   (b) IMPLEMENT: a tester that calls max2 and a correct findMax on a few
       arrays and prints "PASS"/"FAIL" where they disagree.
   💡 HINT: ek pair jisme pehla element chhota do, e.g. {1, 9, 8} — max2
            dega 1 (sahi answer 9 hai) → FAIL print hoga.
   ✏️ STARTER CODE:
       // tester: do arrays pe compare karo
       int test1[] = {1, 9, 8};
       // max2 test1 → 1, findMax → 9 → mismatch milega

 TASK 6 (HARD): Predict then measure — when Priori beats Posteriori.
   Two functions compute the same thing:
       sumLoop(n)     — adds 1..n in a loop          (O(n))
       sumFormula(n)  — uses n*(n+1)/2                (O(1))
   (a) ANALYZE: derive both f(n) formulas fully (count statements for
       sumFormula — it is a constant, independent of n). Predict the time
       ratio for n = 5,000,000.
   (b) IMPLEMENT: time BOTH with chrono at n = 5,000,000 and print both
       times plus the measured ratio. Explain why sumLoop also allocates
       about 8 bytes and why the ratio is never exactly the theoretical
       value (machine noise, caching).
   💡 HINT: sumLoop me int i, s; sumFormula me bas ek calculation. Dono
            ek hi answer denge (check bhi karo!).
   ✏️ STARTER CODE:
       long long loopSum(int n)   { long long s=0; for(int i=1;i<=n;i++) s+=i; return s; }
       long long  fastSum(int n)  { return (long long)n*(n+1)/2; }
       // dono ko alag-alag chrono se time karo aur ratio print karo

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

/*
 TASK 1 SOLUTION + ANALYSIS
 (a) ANALYZE  — sum function:
   - int s = 0;                                     → 1 op
   - loop setup  int i = 0;                         → 1 op
   - test  i < n  runs for i=0..n  → (n + 1) times  → n+1 ops
   - body   s += a[i]  runs n times                 → n ops
   - i++    runs n times                            → n ops
   - return s                                       → 1 op
   Total f(n) = 1 + 1 + (n+1) + n + n + 1 = 3n + 4
   Since 3n + 4 ≤ 4n for n ≥ 4 → O(n)
   For n=5: f(5) = 15 + 4 = 19 (exactly what the counter prints below).
 (b) IMPLEMENT:
*/
#include <iostream>
#include <chrono>
using namespace std;

int sumWithCount(int a[], int n, int& op) {
    op = 0;
    int s = 0;
    op++;                              // s = 0
    int i = 0;
    op++;                              // i = 0
    for (; i < n; i++) {
        op += 2;                       // i<n test + i++ dono count kiye
        op++;                          // s += a[i]
        s += a[i];
    }
    op++;                              // aakhri i<n test (i == n)
    op++;                              // return
    return s;
}

// TASK 2 SOLUTION
int findMaxCounted(int a[], int n, int& op) {
    op = 0;
    if (n <= 0) return -1;             // edge case guard
    int maxV = a[0];
    for (int i = 1; i < n; i++) {
        op++;                          // 1 comparison per iteration
        if (a[i] > maxV) maxV = a[i];
    }
    return maxV;
}

// TASK 4 SOLUTION helpers
long long fragmentA(int n) {
    long long A = 0;
    for (int i = 0; i < n; i++) A++;   // loop 1: n
    for (int i = 0; i < n; i++) A++;   // loop 2: n
    return A;                          // 2n total
}
long long fragmentB(int n) {
    long long B = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) B++;   // n * n = n^2
    return B;
}

// TASK 5 helpers — deliberately wrong max2 vs correct findMax
int max2(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < m) m = a[i];        // galat comparator: min mil raha hai
    return m;
}

// TASK 6 helpers — loop sum vs formula sum
long long loopSum(int n)  { long long s = 0; for (int i = 1; i <= n; i++) s += i; return s; }
long long  fastSum(int n) { return (long long)n * (n + 1) / 2; }

int main() {
    // TASK 1: n=5 verifio — print count = 19 matches f(5) = 3*5 + 4
    {
        int a[5] = {1, 2, 3, 4, 5};
        int op = 0;
        int total = sumWithCount(a, 5, op);    // result pehle, op baad me print — order safe
        cout << "T1: sum=" << total << " opCount=" << op
             << " (expected f(5)=3*5+4=19)\n";
    }

    // TASK 2: table n | predicted | actual
    {
        cout << "T2: n  predicted(n-1)  actual\n";
        int sizes[3] = {1, 6, 100};
        for (int k = 0; k < 3; k++) {
            int n = sizes[k];
            int* a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i + 1;   // increasing data
            int op = 0;
            findMaxCounted(a, n, op);
            cout << "    " << n << "   " << (n - 1) << "              "
                 << op << "\n";
            delete[] a;
        }
    }

    // TASK 4: ratio check at n=1000
    {
        int n = 1000;
        long long A = fragmentA(n);   // expect 2000
        long long B = fragmentB(n);   // expect 1,000,000
        cout << "T4: A=" << A << " (2n=2000)  B=" << B
             << " (n^2=" << n * n << ")  ratio B/A="
             << (double)B / A << " (expected ~500)\n";
    }

    // TASK 5: correctness tester — fast but wrong vs correct
    {
        int t1[] = {1, 9, 8};
        int t2[] = {7, 3, 5, 4};
        int o, c1, c2;
        int r1 = max2(t1, 3);      // returns 1 (galat: min)
        c1 = findMaxCounted(t1, 3, o);              // returns 9
        int r2 = max2(t2, 4);      // 3
        c2 = findMaxCounted(t2, 4, o);              // 7
        cout << "T5: max2=" << r1 << " vs correct=" << c1
             << " → " << (r1 == c1 ? "PASS" : "FAIL") << "\n";
        cout << "    max2=" << r2 << " vs correct=" << c2
             << " → " << (r2 == c2 ? "PASS" : "FAIL") << "\n";
    }

    // TASK 6: posteriori comparison of O(n) vs O(1)
    {
        int n = 5000000;
        auto s1 = chrono::high_resolution_clock::now();
        long long a1 = loopSum(n);
        auto e1 = chrono::high_resolution_clock::now();
        auto s2 = chrono::high_resolution_clock::now();
        long long a2 = fastSum(n);
        auto e2 = chrono::high_resolution_clock::now();
        double tLoop  = chrono::duration_cast<chrono::microseconds>(e1 - s1).count();
        double tFast  = chrono::duration_cast<chrono::microseconds>(e2 - s2).count();
        cout << "T6: same answer? " << (a1 == a2 ? "YES" : "NO") << "\n";
        cout << "    loopSum=" << tLoop << "us  fastSum=" << tFast
             << "us  ratio=" << (tFast > 0 ? tLoop / tFast : 0)
             << "x (theoretical ~1e7x, machine noise se kabhi exact nahi)\n";
    }
    return 0;
}
/*
 (a) ANALYZE for TASK 2: findMax loop runs i=1..n-1 → (n-1) iterations,
     each with exactly 1 comparison → f(n) = (n-1) + 2 (init+return);
     (n-1)+2 ≤ n+2 ≤ 3n for n≥1 → O(n). Always n-1 comparisons, no matter
     where the max sits — the max is known only after seeing everything.
 (b) ANALYZE for TASK 4: fragment A: n + n = 2n → O(n) (loops sequential →
     ADD). fragment B: n × n = n² → O(n²) (nested → MULTIPLY). Ratio at
     n=1000: n²/2n = n/2 = 500 ✓ — matches the measured printout.
 (c) ANALYZE for TASK 5: max2 runs in O(n) same as findMax but uses "<",
     so it tracks the minimum → result wrong whenever max != min. Proof:
     fast+wrong O(n) tells us complexity ≠ correctness; always test with
     edge arrays like {1,9,8}. Here FAIL is the CORRECT tester outcome.
 (d) ANALYZE for TASK 6: loopSum: loop n iterations, each 1 add + i++ +
     test → f(n) ≈ 3n → O(n). fastSum: 1 multiply + 1 add + 1 divide →
     f(n) = 3 (constant) → O(1). Theoretically time ratio ~ (3n)/3 = n =
     5,000,000x, but measured ratio is far smaller because the loop version
     is memory-cache friendly and chrono has noise — Priori predicts the
     trend (fastSum wins massively), Posteriori measures the true multiple.
*/