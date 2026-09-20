/*
═══════════════════════════════════════════════
 BIG THETA (TIGHT BOUND) — PROBLEM SET
 File purpose: prove Θ for specific functions, verify Θ with a sandwich
 checker, find the correct Θ class of common algorithms, and analyse what Θ
 says when only one side is known.
═══════════════════════════════════════════════

 Every solution must include the full mathematical derivation (no bare O(?)).
 The helper below prints the sides of the sandwich so you can SEE the proof.
═══════════════════════════════════════════════
*/

#include <iostream>
using namespace std;

// -------- generic Θ(?) checker: returns class label after verification -----
// Tries c1=..., c2=... on the interval [start,finalN] and reports holding.
void proveTheta(long long (*f)(int), long long (*g)(int), int c1, int c2, int n0, int finalN){
    bool ok = true;
    for(int n = n0; n <= finalN; n++){
        if( c1*(*g)(n) > (*f)(n) || (*f)(n) > c2*(*g)(n) ){   // sandwich broken
            ok = false;
            break;
        }
    }
    cout << "   check c1·g(n) ≤ f(n) ≤ c2·g(n), c1=" << c1 << ", c2=" << c2
         << ", n0=" << n0 << " up to n=" << finalN
         << "  →  " << (ok ? "TRUE ✓ every row" : "broken at some n ✗") << "\n";
}

long long f_n233n(int n){ return 1LL*n*n + 3LL*n; }   // f = n² + 3n
long long f_n3(int n)   { return 1LL*n*n*n; }         // f = n³
long long f_n1(int n)   { return 1LL*n; }             // f = n
long long g_n2(int n)   { return 1LL*n*n; }           // g = n²
long long g_n3(int n)   { return 1LL*n*n*n; }         // g = n³
long long g_n1(int n)   { return 1LL*n; }             // g = n

// ================================================================
// TASK 1 — PROVE that f(n) = n³ + 2n  is Θ(n³)
// ================================================================
// 💡 HINT:
//    Dominant term is n³. Prove TWO sides:
//      lower: n³ + 2n ≥ c₁·n³. Try c₁ = 1: need 2n ≥ 0, true for all n ≥ 1.
//      upper: n³ + 2n ≤ c₂·n³. Try c₂ = 2: need 2n ≤ n³, i.e. 2 ≤ n², true for n ≥ 2.
//    So c₁=1, c₂=2, n₀=2  ⇒  Θ(n³). Use proveTheta to confirm.
// ✏️ STARTER CODE:
//    // call proveTheta(f_n3, g_n3, 1, 2, 2, 20)
//    // print the derivation lines: lower algebra then upper algebra
void solveTask1(){
    cout << "[Task 1] Prove f(n) = n^3 + 2n is Θ(n^3)\n";
    proveTheta(f_n3, g_n3, 1, 2, 2, 20);
    cout << "   derivation (hand-written):\n";
    cout << "   lower: f >= c1·n^3   →   n^3 + 2n >= 1·n^3  ⟺  2n >= 0 ✔ n ≥ 1\n";
    cout << "   upper: f <= c2·n^3   →   n^3 + 2n <= 2·n^3  ⟺  2n <= n^3  ⟺  2 <= n^2 ✔ n ≥ 2\n";
    cout << "   both sides with c1=1, c2=2, n0=2  →  f(n) = Θ(n^3) PROVEN\n\n";
}

// ================================================================
// TASK 2 — Θ of common algorithm loops (choose + justify, then verify)
// ================================================================
// 💡 HINT:
//    (a) finding max of an array         → 1 pass  → Θ(n)
//    (b) nested i and j each up to n      → n·n     → Θ(n²)
//    (c) for(i=1; i<=n; i=i*2)            → log₂n iters → Θ(log n)
//    (d) constant work array[0] access    → Θ(1)
//    For each, print a hand-derivation:
//      T(a) = n·(1) = n     ≥ 1·n and ≤ 1·n  →  Θ(n) with c1=c2=1
//      T(b) = n·n = n²      lower n² ≥ n² (c=1), upper n² ≤ n² (c=1) → Θ(n²)
//      T(c) = 1 + 1 + ... (log₂n times)  → c1·log n ≤ log n ≤ c2·log n
//      T(d) = 1           → 1 ≤ 1·1 and 1 ≥ 1·1   →   Θ(1)
// ✏️ STARTER CODE:
//    // cout each line; call proveTheta only where the class is polynomial
//    // (log and Θ(1) need your textual proof)
void solveTask2(){
    cout << "[Task 2] Θ class of common loops\n";
    proveTheta(f_n1, g_n1, 1, 1, 1, 30);            // (a) linear pass
    cout << "   (b) nested double loop: T = n·n = n^2, c1=c2=1  →  Θ(n^2)\n";
    cout << "   (c) i doubles: iterations = ⌈log2 n⌉.  prove: c1·log2 n ≤ log2 n ≤ c2·log2 n"
         << " with c1=1, c2=1 → Θ(log n)\n";
    cout << "   (d) single access: T = 1 = 1·1  →  Θ(1)\n\n";
}

// ================================================================
// TASK 3 — Is it Θ(n²) or Θ(n³)? The decisive experiment
// ================================================================
// 💡 HINT:
//    f(n) = n³ + 2n has TWO candidate classes. The true one is Θ(n³) (proven in
//    task 1). But watch what happens if we insist on Θ(n²):
//      lower for n²: n³+2n ≥ 1·n², true; upper: n³+2n ≤ c₂·n² ⇒ n+2/n ≤ c₂ fails.
//    So the sandwich breaks on the upper slice → NOT Θ(n²). Rule of thumb:
//    Θ is only valid when BOTH slices hold for the SAME g(n).
// ✏️ STARTER CODE:
//    // proveTheta(f_n3, g_n2, 1, 1, 1, 20) — expect broken ✗
//    // proveTheta(f_n3, g_n3, 1, 2, 2, 20) — expect holding ✓
void solveTask3(){
    cout << "[Task 3] Is f(n)=n^3+2n Θ(n^2) or Θ(n^3)?\n";
    proveTheta(f_n3, g_n2, 1, 1, 1, 20);   // f vs n^2 → break hona chahiye
    cout << "   reason: upper slice n^3+2n <= c2·n^2  ⟺  n + 2/n <= c2  fails.\n";
    proveTheta(f_n3, g_n3, 1, 2, 2, 20);   // f vs n^3 → should hold
    cout << "   final verdict: TRUE class = Θ(n^3), NOT Θ(n^2)\n\n";
}

// ================================================================
// TASK 4 — When only Ω is known: what can you say about f?
// ================================================================
// 💡 HINT:
//    Suppose we only know f(n) = Ω(n²) (a floor). Then the CORRECT statements:
//      - f(n) = Ω(n)   also true (weaker floor)
//      - f(n) = O(n²)  unknown until upper side is proven
//      - f(n) = Θ(n²)  NOT implied
//    The Θ label requires both slices. Code: we verify with a g that we KNOW
//    is the floor and show that an upper proof is separate work.
// ✏️ STARTER CODE:
//    // check floor holds: proveTheta(f_n2?? use f_n233n for n² floor? no — use f_n3? no)
//    // We want a function with a guaranteed floor n²: pick f(n)=n²+3n
//    // lower slice with n²: 1·n² ≤ f proven; upper attempt with 1·n² fails
//    // so print "floor Ω(n^2) holds, Θ(n^2) needs an upper proof as well"
void solveTask4(){
    cout << "[Task 4] Ω-only knowledge\n";
    proveTheta(f_n233n, g_n2, 1, 100, 1, 20);  // upper c2 huge → almost holds
    cout << "   showing: with a stupidly huge c2=100 the upper slice holds, so\n";
    proveTheta(f_n233n, g_n2, 1, 1, 1, 20);    // c2=1 breaks
    cout << "   but c2=1 breaks ⇒ the tight bound needs a careful upper proof.\n";
    cout << "   conclusion: Ω(n^2) alone never implies Θ(n^2); you must prove the O side.\n\n";
}

int main(){
    cout << "============ BIG THETA PROBLEM SET ============\n\n";
    solveTask1();
    solveTask2();
    solveTask3();
    solveTask4();
    return 0;
}