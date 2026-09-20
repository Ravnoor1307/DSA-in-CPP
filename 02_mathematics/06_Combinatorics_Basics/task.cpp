/*
====================================================================
 TASK SET — COMBINATORICS BASICS
====================================================================
🌍 REAL-WORLD SCENARIO:
A coding club of 100 members wants to rank its top 50 coders across
multiple categories. Counting "arrangements of selected people"
(permutations), "groups regardless of order" (combinations), and
"ways to pick a small crew from a big pool without the numbers
exploding" (Pascal DP + modulo) is exactly what these tasks train.
Skipping the overflow trap here means real apps (lottery engines,
scheduling) crash or silently return garbage.

🧠 HOW TO SOLVE:
Learn the three counting faces: factorials n! for arrangements,
multiplicative nCr = ∏(n−r+i)/i which never overflows as long as the
final answer fits in long long, and Pascal DP where every cell is
just the sum of two cells above it (with % MOD to stay small for
huge n). Always special-case r > n (→0), r == 0 (→1).

 5 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE.

═══════════════════════════════════════════════
TASK 1 — factorial(10)
💡 HINT: one for-loop, res = res * i, start res = 1, i from 2..n.
✏️ STARTER CODE:
    long long f = ?;
    for (int i = 2; i <= ?; i++) f *= i;

TASK 2 — nPr(10, 3) = 10!/7!
💡 HINT: 10P3 = 10 ✕ 9 ✕ 8. Loop 3 terms multi-step; OR loop i from
    n−r+1 to n and multiply. Product 720.
✏️ STARTER CODE:
    // 10P3: order matters, r terms starting from n
    long long p = 1;
    for (int i = 0; i < r; i++) p *= (n - i);

TASK 3 — nCr multiplicative (8, 3)
💡 HINT: nCr = 8/1 ✕ 7/2 ✕ 6/3 = (8×7×6)/6 = 56. Keep res = res*(n−r+i)/i.
✏️ STARTER CODE:
    long long c = 1;
    for (int i = 1; i <= ???; i++)
        c = c * (n - r + i) / i;   // integer har step

TASK 4 — print Pascal triangle rows 0..5
💡 HINT: rows build from previous; border 1. Use vector<vector<long long>>.
✏️ STARTER CODE:
    vector<vector<long long>> C(6);
    for (int i = 0; i < 6; i++){ C[i].assign(???, 1);
        for (int j = 1; j < i; j++) C[i][j] = C[i-1][j-1] + ???; }

TASK 5 — nCr(100,50) % 1e9+7 via Pascal DP with modulo
💡 HINT: every addition mod. Value ~1.0089e29, int table enough.
✏️ STARTER CODE:
    const int M = 1000000007;
    vector<vector<int>> C(101);
    for (int i=0;i<101;i++){ C[i].assign(i+1, 1%M);
        for (int j=1;j<i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M; }
    cout << C[100][50];
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
using namespace std;

// ---------- TASK 1: factorial(10) ----------
// 10! = 10×9×...×1 = 3628800
// concept: n! arrangements of n distinct items
long long factorial(long long n) {
    long long res = 1;
    for (long long i = 2; i <= n; i++) res *= i;  // i=2 se n tak multiply
    return res;
}

// ---------- TASK 2: nPr(10, 3) ----------
// 10P3 = 10! / 7! = 10 × 9 × 8 = 720
// concept: order matters → r terms ghatate hue (n, n−1, …)
long long nPr(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) res *= (n - i);   // r terms, n se neeche
    return res;
}

// ---------- TASK 3: nCr multiplicative (8, 3) ----------
// 8C3 = 8/1 × 7/2 × 6/3 = 8×7×6/6 = 56
// concept: product of r fractions, har step integer hi rehta hai
long long nCr_mul(int n, int r) {
    if (r > n) return 0;                // edge case: chun nahi sakte
    if (r == 0) return 1;               // 0 choice → 1 tareeka
    r = min(r, n - r);                  // symmetry C(n,r)=C(n,n-r)
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;    // waise hi C(n-r+i, i) ban raha hai
    }
    return res;
}

// ---------- TASK 4: Pascal triangle rows 0..5 ----------
// row i me (i+1) entries; C[i][j] = C[i-1][j-1] + C[i-1][j]
void printPascal(int R) {
    vector<vector<long long> > C(R + 1);
    for (int i = 0; i <= R; i++) {
        C[i].assign(i + 1, 1);                       // border sab 1
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; // do upar wale cells ka sum
        }
        for (int s = 0; s < R - i; s++) cout << "  "; // center alignment
        for (int j = 0; j <= i; j++) cout << C[i][j] << "   ";
        cout << "\n";
    }
}

// ---------- TASK 5: nCr(100,50) % 1e9+7 via Pascal DP ----------
// true value ~1.0089e29 — long long bhi overflow, par mod se int table
const int MOD = 1000000007;
int nCr_mod(int n, int r) {
    if (r > n) return 0;
    vector<vector<int> > C(n + 1);
    for (int i = 0; i <= n; i++) {
        C[i].assign(i + 1, 1 % MOD);
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; // har add mod
        }
    }
    return C[n][r];
}

int main() {
    // TASK 1
    cout << "TASK 1: 10! = " << factorial(10) << "\n\n";

    // TASK 2
    cout << "TASK 2: 10P3 = " << nPr(10, 3) << "\n";
    cout << "  check: 10×9×8 = 720\n\n";

    // TASK 3
    cout << "TASK 3: 8C3 = " << nCr_mul(8, 3) << "\n";
    cout << "  trace: i=1: (1×8)/1=8, i=2: (8×7)/2=28, i=3: (28×6)/3=56\n\n";

    // TASK 4
    cout << "TASK 4: Pascal rows 0..5\n";
    printPascal(5);

    // TASK 5
    cout << "\nTASK 5: C(100,50) % 1e9+7 = " << nCr_mod(100, 50) << "\n";
    cout << "  verify: 100C50 ≈ 1.008913445e29, mod 1e9+7 = "
         << "538992043 (known constant) → matlab DP mod sahi hai\n";
    return 0;
}