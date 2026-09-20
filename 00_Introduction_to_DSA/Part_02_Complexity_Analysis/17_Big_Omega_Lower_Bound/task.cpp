/*
═══════════════════════════════════════════════
 BIG OMEGA (LOWER BOUND) — PROBLEM SET
 File purpose: prove Ω for given functions, find Ω of algorithms,
 decide if a statement is TRUE/FALSE, and write a Ω-verifier.
═══════════════════════════════════════════════

 A task = Analyze + Implement (proof must be written, bare O(?) is BANNED).
 The "compare with n" trick used below prints, for chosen c and n0, what values
 actually satisfy f(n) ≥ c·g(n) so you can SEE the bound in action.
═══════════════════════════════════════════════
*/

#include <iostream>
using namespace std;

// Helper used by multiple tasks: verifies f(n) >= c·g(n) for all n in [start, end]
bool verifyOmega(long long (*f)(int), long long (*g)(int), long long c, int start, int end){
    for(int n = start; n <= end; n++)
        if( f(n) < c * g(n) )    // ek bhi violation → bound nahi hai
            return false;
    return true;
}

// generic brute-force count: worst-case comparisons of linear search
int worstComparisons(int n){
    int arr[100]; for(int i = 0; i < n; i++) arr[i] = i;
    int key = 1 << 30, cmp = 0;              // key pakka absent → worst case
    for(int i = 0; i < n; i++){ cmp++; if(arr[i] == key) return cmp; }
    return cmp;
}

// ------------------- helper "printOmegaDecisionbox" -------------------
void printDecision(bool ok, const char* claim){
    cout << "claim: " << claim << "  →  " << (ok ? "TRUE ✓" : "FALSE ✗") << "\n";
}

// ------------------- f(n) functions used in the tasks -------------------
long long fn_id(int n)     { (void)n; return n; }
long long fn_sq(int n)     { (void)n; return 1LL*n*n; }
long long fn_cube(int n)   { (void)n; return 1LL*n*n*n; }
long long gn_id(int n)     { (void)n; return n; }
long long gn_one(int n)    { (void)n; return 1; }
long long gn_sq(int n)     { (void)n; return 1LL*n*n; }

// ================================================================
// TASK 1 — PROVE the Ω bound of f(n) = n² + 2n
// ================================================================
// 💡 HINT:
//    We want a line below f(n). Guess g(n) = n². Then f(n) ≥ c·n² means
//    n² + 2n ≥ c·n²  ⟹  n² (1−c) + 2n ≥ 0. Pick c = 1: 2n ≥ 0 TRUE for all
//    n ≥ 1. So c = 1, n0 = 1 already works! In code: verify f(n) >= 1·n².
// ✏️ STARTER CODE:
//    // f(n) = n*n + 2n,  g(n) = n*n,  c = 1
//    // loop n=1 to 20:  if( f(n) < c*g(n) ) mark false
//    // print the verdict
//
// Complete the starter by filling this main-like block:

void solveTask1(){
    // 1) print a small table proving the inequality
    cout << "  n | f=n^2+2n | c·g = 1·n^2 | f >= c·g ?\n";
    cout << "  ---+----------+-------------+----------\n";
    bool ok = true;
    for(int n = 1; n <= 15; n++){
        long long f = 1LL*n*n + 2LL*n;     // f(n) = n² + 2n
        long long cg = 1LL*n*n;            // c·g(n) = 1·n²
        bool row = (f >= cg);
        if(!row) ok = false;
        cout << "  " << n << " | " << f << "      | " << cg << "          | "
             << (row ? "TRUE (2n slack)" : "FALSE") << "\n";
    }
    cout << "  Mathematical derivation:\n";
    cout << "    f(n) >= c·g(n)?\n";
    cout << "    n^2 + 2n >= 1·n^2\n";
    cout << "    2n >= 0   →   TRUE for every n >= 1\n";
    cout << "    So with c=1, n0=1 the inequality holds  →  f(n) = Ω(n^2)  "
         << (ok ? "✔ PROVEN" : "✗ WRONG") << "\n";
}

// ================================================================
// TASK 2 — TRUE/False on Ω statements (reason, then verify)
// ================================================================
// 💡 HINT:
//    (a) n = Ω(n)     →  n ≥ 1·n  always true           → TRUE
//    (b) n = Ω(n²)    →  n ≥ c·n²  ⟹  1 ≥ c·n  fails    → FALSE
//    (c) n = Ω(1)     →  n ≥ 1·1   true for n ≥ 1       → TRUE
//    (d) n² = Ω(n)    →  n² ≥ c·n  ⟹  n ≥ c  true       → TRUE
//    Code: verifyOmega(fn_id, gn_id,  1) => (a)
//          verifyOmega(fn_id, gn_sq,  1) => (b)
//          verifyOmega(fn_id, gn_one, 1) => (c)
//          verifyOmega(fn_sq, gn_id,  1) => (d)
// ✏️ STARTER CODE:
//    // call verifyOmega(...) for (a)..(d)
//    // print each claim and its verdict with the chosen c
void solveTask2(){
    bool a = verifyOmega(fn_id,  gn_id,  1, 1, 50);   // n >= n        → TRUE
    bool b = verifyOmega(fn_id,  gn_sq,  1, 1, 50);   // n >= n^2      → FALSE
    bool c = verifyOmega(fn_id,  gn_one, 1, 1, 50);   // n >= 1        → TRUE
    bool d = verifyOmega(fn_sq,  gn_id,  1, 1, 50);   // n^2 >= n      → TRUE
    printDecision(a, "n   = Ω(n)  ");
    printDecision(b, "n   = Ω(n^2)  (c=1, fail karta hai)");
    printDecision(c, "n   = Ω(1)   ");
    printDecision(d, "n^2 = Ω(n)   ");
    cout << "Reason (b): n >= c·n^2  ⟺  1 >= c·n  fails for n > 1/c.\n";
    cout << "Reason (d): n^2 >= c·n  ⟺  n >= c      true for n ≥ c.\n\n";
}

// ================================================================
// TASK 3 — LINEAR SEARCH: is the algorithm Ω(n)? Ω(1)?
// ================================================================
// 💡 HINT:
//    Worst case of linear search = n comparisons. So T(n) = n. We proved
//    earlier n = Ω(n). Best case = 1 comparison, so it is also Ω(1).
//    Code: compute worstComparisons(n) for n=1..20 and check it equals n;
//          this shows comparisons = n, hence T(n) = Ω(n).
// ✏️ STARTER CODE:
//    // loop n=1..20: worst = count comparisons with missing key
//    // print `worst == n ?`
void solveTask3(){
    cout << "  n | worst comparisons | 1·g(n)=1·n | equal? (T(n)=n)\n";
    cout << "  ---+-------------------+------------+-----------------\n";
    bool allEq = true;
    for(int n = 1; n <= 20; n++){
        int w = worstComparisons(n);
        if(w != n) allEq = false;
        cout << "  " << n << " |        " << w << "          |      " << n
             << "      |   " << (w == n ? "yes, T(n)=n" : "NO") << "\n";
    }
    cout << "  worst = n always → T(n) = n ≥ 1·n → Ω(n)  "
         << (allEq ? "✔ PROVEN" : "✗ WRONG") << "\n";
    cout << "  best  = 1 → T(n) ≥ 1·1 → Ω(1) also holds.\n\n";
}

// ================================================================
// TASK 4 — SMALLEST valid c for f(n)=7n over g(n)=n2 (design the proof)
// ================================================================
// 💡 HINT:
//    f(n)=7n, g(n)=n²: we need 7n ≥ c·n²  ⟹  7 ≥ c·n. For ALL n ≥ n0 this
//    FAILS as n grows, no matter how small c>0. So f(n)=7n is NOT Ω(n²).
//    With g(n)=n instead: 7n ≥ c·n ⟹ c ≤ 7, largest c = 7. So Ω(n), c=7.
//    Code: verifyOmega wants long long c; use c=7 against g=n.
// ✏️ STARTER CODE:
//    // check c = 7, g = n   → expect TRUE
//    // check c = 1, g = n^2 → expect FALSE
void solveTask4(){
    bool cWithG1 = verifyOmega(fn_id, gn_id, 7, 1, 200);   // 7n >= 7·n
    bool cWithG2 = verifyOmega(fn_id, gn_sq, 1, 1, 200);   // 7n >= n^2
    cout << "f(n)=7n vs g(n)=n,   c=7 → " << (cWithG1 ? "Ω(n) ✔ (7n=7·n)" : "✗") << "\n";
    cout << "f(n)=7n vs g(n)=n^2, c=1 → " << (cWithG2 ? "✗ something wrong!" : "FALSE as expected ✗")
         << "  (7n < n² when n > 7)\n";
    cout << "Derivation: 7n ≥ c·n²  ⟺  7 ≥ c·n  →  violates for n > 7/c.\n";
    cout << "Hence f(n) = Ω(n) (best c=7), but NOT Ω(n²).\n\n";
}

int main(){
    cout << "============ BIG OMEGA PROBLEM SET ============\n\n";
    solveTask1();
    solveTask2();
    solveTask3();
    solveTask4();
    return 0;
}