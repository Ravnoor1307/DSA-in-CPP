/*
====================================================================
 COMBINATORICS BASICS
 ⏱️ TIME COMPLEXITY: derived per-approach below in TIME COMPLEXITY
    CALCULATION section (naive O(n), multiplicative O(r), Pascal DP
    O(R²)). NEVER bare O(?).
====================================================================

 🌍 REAL-WORLD SCENARIO:
 Imagine your college is forming a quiz team. The coach has 10 star
 players and must pick 3 of them. If order matters (captain,
 vice-captain, manager), that is a PERMUTATION — nPr. If order does
 not matter (all three are just "team members"), that is a
 COMBINATION — nCr. This is the same math behind lottery draws
 (pick 6 numbers from 49, order irrelevant), arranging books on a
 shelf (order matters!), and choosing which 2 of your 5 friends join
 you for dinner. Every "how many ways can I choose/arrange" question
 is secretly a permutation or a combination.

 📖 THEORY: (beginner level)
 - Factorial: n! = n × (n−1) × ... × 2 × 1, and 0! = 1. It counts
   the ways to ARRANGE n distinct items in a line.
 - Permutation  nPr = n! / (n−r)!  → number of ways to ARRANGE r
   items chosen from n, ORDER MATTERS. Running a race: 10 runners,
   3 medals → 10P3.
 - Combination  nCr = n! / (r! × (n−r)!)  → number of ways to CHOOSE
   r items from n, ORDER DOES NOT MATTER. Selecting a team → 10C3.
 - KEY insight: nCr = nPr / r!  because every group of r items can
   be internally arranged in r! ways, and those r! orders collapse
   into one group.
 - OVERFLOW PROBLEM: 20! ≈ 2.433e18 which fits in long long
   (max ≈ 9.22e18), but 21! ≈ 5.11e19 — WAY bigger than
   2^63 − 1 ≈ 9.22e18, so it overflows. Formula-first (naive)
   nCr overflows even for small numbers because n! itself explodes.
 - FIX: multiplicative formula — compute the product of r terms as
   fractions that stay INTEGER at every step:
     nCr = n/1 × (n−1)/2 × (n−2)/3 × ...  (r terms)
   Smallest intermediate value stays ≤ nCr, so no overflow while
   the answer fits in long long.
 - ALTERNATIVE: Pascal's triangle (DP). Row i is built ONLY from
   row i−1:  C[i][j] = C[i−1][j−1] + C[i−1][j]. Addition never
   exceeds the answer, so it is overflow-safe too, and it gives ALL
   nCr values for a given n at once. Use mod to keep values small
   for huge n.

 ASCII diagram — CHOICES (order matters = permutations, doesn't = combinations):
   3 letters {A,B,C} taken 2 at a time:
   Permutations (3P2 = 6):  AB AC BA BC CA CB
   Combinations (3C2 = 3):  {AB} {AC} {BC}   (AB and BA same group)

 ASCII — PASCAL'S TRIANGLE (rows 0..6):
            row 0:                   1
            row 1:                 1   1
            row 2:               1   2   1
            row 3:             1   3   3   1
            row 4:           1   4   6   4   1
            row 5:         1   5  10  10   5   1
            row 6:       1   6  15  20  15   6   1
   Each entry = C[row][col]. 20 sits at row 6, col 3 → C(6,3)=20.
   Every inner number = the two numbers diagonally above it.

 WHEN TO USE:
 - Use MULTIPLICATIVE formula nCr when you need ONE value and n is
   moderate (answer fits long long). Fast + no overflow.
 - Use PASCAL DP when you need a whole range of nCr values, or when
   you need nCr(i,j) for many (i,j) — compute the table once.
 - Use PASCAL + MOD when n is huge but answers modulo M suffice
   (competitive programming standard: M = 1e9+7).

 🧠 LOGIC — STEP BY STEP:
 Step 1: Read n, r and validate. WHY: if r > n the answer is 0,
         if r == 0 the answer is 1, and 0! = 1 by definition.
 Step 2: If using multiplicative, loop i from 1 to r building
         result = result × (n−r+i) / i with LONG LONG.
         WHY: after i multiplications the running value equals
         C(n−r+i, i) which is a clean integer; dividing early by i
         keeps numbers small and NEVER produces a fraction.
 Step 3: If using Pascal DP, boost a 2-row DP table: for row i scan
         j = 0..i computing C[i][j] = C[i−1][j−1] + C[i−1][j] with
         C[i][0] = C[i][i] = 1.
         WHY: each cell only needs the two cells above it, so the
         whole triangle builds left-to-right, row-by-row.
 Step 4: When mod is needed, add then take % M at EVERY cell.
         WHY: (a+b) mod M == ((a mod M) + (b mod M)) mod M, so we can
         keep every entry < M.

 VISUAL WALKTHROUGH (multiplicative build of C(6,3)):
   Start    res = 1
   i=1:     res = (1 × 6) / 1 = 6        → 6C1 = 6
   i=2:     res = (6 × 5) / 2 = 15       → 6C2 = 15
   i=3:     res = (15 × 4) / 3 = 20      → 6C3 = 20
   ASCII triangle confirms: 20 at row 6, col 3. ✓

 DRY RUN — multiplicative nCr(5,2):
   res = 1
   Step i=1: res = (1 * (5-2+1)) / 1 = (1*4)/1 = 4        (C(4,1)=4)
   Step i=2: res = (4 * (5-2+2)) / 2 = (4*5)/2 = 20/2 = 10 (C(5,2)=10)
   Result 10 ✓  (n=5: pick 2 → {AB}{AC}{AD}{AE}{BC}{BD}{BE}{CD}{CE}{DE})

 TIME COMPLEXITY CALCULATION:
 - NAIVE formula nCr = n!/(r!(n−r)!): each factorial is a single
   loop of length ≤ n, and we compute 3 of them → 3n operations ≈
   O(n). BUT every intermediate factorial explodes beyond long long
   as soon as n ≥ 21, so this approach is USELESS in practice — the
   real cost is the silent overflow.
 - MULTIPLICATIVE loop: exactly r multiplications and r divisions.
   r ≤ n → r = O(n) total operations and every held value stays
   ≤ nCr, overflow-proof for results that fit in long long.
   → Time Complexity = O(r) = O(n) in the worst case, with NO overflow.
 - PASCAL DP full table rows 0..R: row i has (i+1) cells, so total
   cells = 1+2+...+(R+1) = (R+1)(R+2)/2 ≈ R²/2 cells, each an O(1)
   addition.
   → Time Complexity = O(R²) for the whole triangle of size R.
   (Single query nCr with Pascal also runs the full double loop, so it
   is O(n²) per query — formula wins for one-off values.)

 SPACE COMPLEXITY CALCULATION:
 - Naive & multiplicative formulas: only a handful of scalar long
   longs (numerator, denominator, result).
   → Space Complexity = O(1).
 - Pascal FULL table stores (R+1)(R+2)/2 long long/int cells.
   → Space Complexity = O(R²).
 - Pascal KEPT-DOWN with 2 alternating rows needs only 2×(R+1)
   cells → O(R).
   → Space Complexity = O(R) with the rolling-row trick.

 APPROACH COMPARISON:
 ┌────────────────────┬───────────────────┬──────────────────────┬──────────────────────────┐
 │ Criterion          │ NAIVE (3 facs)    │ MULTIPLICATIVE loop  │ PASCAL DP                │
 ├────────────────────┼───────────────────┼──────────────────────┼──────────────────────────┤
 │ 1 value nCr        │ O(n) but FAC-PLODS│ O(r) no overflow     │ O(n²) table just for one │
 │ Overflow n≥21      │ YES — n! huge     │ NO (values ≤ nCr)    │ NO (additions only)      │
 │ All values up to n │ No                │ recompute each       │ YES — one table          │
 │ mod M for huge n   │ No                │ needs mod-inverse    │ YES — easy, keep int     │
 │ WHEN TO USE        │ textbook only     │ competitive 1 query  │ many queries / modulus   │
 └────────────────────┴───────────────────┴──────────────────────┴──────────────────────────┘

 CODE BELOW (demo only — no tasks).
*/

#include <iostream>
#include <vector>
using namespace std;

// 4> factorial: plain loop, long long. Guard against overflow.
//   20! fit hai, 21! nahi me — guard 0 return karte hain + warning.
long long fact(long long n) {
    long long res = 1;
    const long long LIMIT = 9223372036854775807LL; // 2^63 - 1 (long long max)
    for (long long i = 2; i <= n; i++) {
        if (res > LIMIT / i) {           // Overflow guard: res*i break ho jayega
            cout << "   [WARNING] overflow at " << i << "! — result unusable\n";
            return 0;
        }
        res *= i;
    }
    return res;
}

// 4> naive nCr — sirf theory ke liye, n r chhote ho to chalega
long long nCr_naive(int n, int r) {
    if (r > n) return 0;
    if (r == 0) return 1;
    return fact(n) / (fact(r) * fact(n - r));
}

// 4> multiplicative formula: nCr = product of r terms, har step pe divide
long long nCr_mul(int n, int r) {
    if (r > n) return 0;
    if (r == 0) return 1;
    r = min(r, n - r);                // C(n,r) == C(n,n-r) — chhoti side
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;  // ye integer hi rehta hai har step
    }
    return res;
}

// 4> Pascal DP full table (long long version) — O(R^2)
//    row i → row i+1; C[i][j] = C[i-1][j-1] + C[i-1][j]
vector<vector<long long> > pascal(int R) {
    vector<vector<long long> > C(R + 1);
    for (int i = 0; i <= R; i++) {
        C[i].assign(i + 1, 1);        // border 1 (j=0 aur j=i ho 1)
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; // upar ke do cells ka sum
        }
    }
    return C;
}

// 4> Pascal DP with modulo M — n badha ho, int matrix se kaam chalta hai
vector<vector<int> > pascal_mod(int R, int M) {
    vector<vector<int> > C(R + 1);
    for (int i = 0; i <= R; i++) {
        C[i].assign(i + 1, 1 % M);
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M; // har add ke baad mod
        }
    }
    return C;
}

// 4> ASCII triangle print — centered thoda sa
void printPascal(const vector<vector<long long> >& C, int R) {
    for (int i = 0; i <= R; i++) {
        for (int s = 0; s < (R - i); s++) cout << "  ";  // leading space
        for (int j = 0; j <= i; j++) cout << C[i][j] << "   ";
        cout << "\n";
    }
}

int main() {
    cout << "================ FACTORIAL TABLE ================\n";
    for (int n : {5, 10, 15, 20}) {
        cout << n << "! = " << fact(n) << "\n";
    }
    // 21! overflow — guard se warning milegi aur 0 return hoga
    cout << "21! = " << fact(21) << "  (2^63-1 = 9223372036854775807, 21! ≈ 5.11e19 > 9.22e18)\n\n";

    cout << "================ nCr(10,3) — THREE METHODS ================\n";
    cout << "Naive (factorial)   : " << nCr_naive(10, 3) << "\n";
    cout << "Multiplicative loop : " << nCr_mul(10, 3) << "\n";
    vector<vector<long long> > P = pascal(10);
    cout << "Pascal DP           : " << P[10][3] << "\n\n";

    cout << "================ PASCAL TRIANGLE rows 0..6 ================\n";
    vector<vector<long long> > T = pascal(6);
    printPascal(T, 6);

    cout << "\n=== Compare multi-mass vs Pascal for row 6 (same numbers) ===\n";
    for (int r = 0; r <= 6; r++)
        cout << "C(6," << r << ") = mul:" << nCr_mul(6, r)
             << "  pascal:" << T[6][r] << "\n";

    cout << "\n================ EDGE CASES ================\n";
    cout << "C(10, 12)  (r>n) = " << nCr_mul(10, 12) << "\n";
    cout << "C(10, 0)   (r=0) = " << nCr_mul(10, 0) << "\n";
    cout << "C(0, 0)    (n=0) = " << nCr_mul(0, 0) << "\n";
    cout << "C(0, 3)    (n=0,r>0) = " << nCr_mul(0, 3) << "\n\n";

    cout << "================ MODULO VARIANT nCr(100,50) % 1e9+7 ================\n";
    const int MOD = 1000000007;
    vector<vector<int> > Cm = pascal_mod(100, MOD);
    cout << "C(100, 50) mod 1e9+7 = " << Cm[100][50] << "\n";
    cout << "(true value ~1.0089e29, mod se int me fit) \n";

    return 0;
}