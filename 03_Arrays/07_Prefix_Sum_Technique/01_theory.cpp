/*
═══════════════════════════════════════════════
 PREFIX SUM TECHNIQUE
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Suppose your teacher wants your cumulative marks for a whole term — instead of
 adding subject marks again every time she asks, she keeps a running total that
 only grows forward. Similarly, when you check your monthly expenses, your bank
 shows "spent so far this month" as a running total. That running total is
 exactly a prefix sum: every future question ("how much did I spend between
 March and June?") is answered by subtracting two saved totals instead of
 re-adding the amounts every single time.

 📖 THEORY: (pure English)
 - Definition: prefix[i] = sum of all elements from index 0 to index i.
   Recurrence:  prefix[i] = prefix[i-1] + arr[i];   prefix[0] = arr[0].
 - Range sum:  sum(arr[l..r]) = prefix[r] - prefix[l-1].
   When l == 0 the answer is just prefix[r], because prefix[-1] does not
   exist — so that case is special-cased.
 - Key properties:
   • Built once in a single pass O(n); afterwards every range query is O(1).
   • Works with negative numbers too — subtracting two totals cancels cleanly.
   • 2D version uses inclusion–exclusion:
       P[i][j] = A[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]
   • Submatrix sum of rectangle (r1,c1)-(r2,c2):
       P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1]
     (if r1-1 < 0 or c1-1 < 0, treat that term as 0)
 - ASCII diagram (1D prefix array with arrows):
   arr    : [  2    4   -3    5    1 ]
   prefix : [  2    6    3    8    9 ]
             └──────── running total ───────┘
   sum(1..3) = prefix[3] - prefix[0] = 8 - 2 = 6   (4+(-3)+5 = 6) ✓

 - When to use: many range/add queries on a STATIC array (no updates),
   2D rectangles, equilibrium index check, subarrays divisible by k, product
   except self, cumulative scores, daily running balances, etc.

 🧠 LOGIC — STEP BY STEP: (pure English with WHY)
 Step 1: Create prefix[0..n-1] and set prefix[0] = arr[0].
         WHY: the first element has nothing before it, so its running total
              is just itself.
 Step 2: For i from 1 to n-1: prefix[i] = prefix[i-1] + arr[i].
         WHY: the total so far equals the previous total plus the new element.
              Constant work per slot, so one full pass does everything — O(n).
 Step 3: For a query (l, r): if l == 0 return prefix[r], else return
         prefix[r] - prefix[l-1].
         WHY: prefix[r] holds everything of [0..r]; prefix[l-1] holds
              everything strictly before l. Subtracting removes that prefix
              part and leaves exactly [l..r] — three operations, no matter
              how large the window is.
 Step 4: For 2D, build the table row by row with inclusion–exclusion, then
         answer any rectangle with the four-term cancellation formula.
         WHY: adding the "up" total and the "left" total double-counts the
              top-left corner rectangle, so subtracting P[i-1][j-1] fixes the
              double count exactly once.

 VISUAL WALKTHROUGH: (ASCII state diagrams — prefix build)
   arr  = {2, 4, -3, 5, 1}
   prefix fills left → right:

   i=0  p[0]=2                → [ 2   ·   ·   ·   · ]
   i=1  p[1]=2+4 = 6          → [ 2   6   ·   ·   · ]
   i=2  p[2]=6+(-3) = 3       → [ 2   6   3   ·   · ]
   i=3  p[3]=3+5 = 8          → [ 2   6   3   8   · ]
   i=4  p[4]=8+1 = 9          → [ 2   6   3   8   9 ]

   rangeSum(1,3):  p[3]-p[0] = 8-2 = 6  (4+(-3)+5 = 6) ✓
   rangeSum(0,2):  l==0 → p[2] = 3      (2+4+(-3) = 3) ✓

   2D inclusion-exclusion:
     P[i][j]      = A[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]
     rect(r1,c1,r2,c2) = P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1]

 DRY RUN: (line-by-line trace on small concrete arrays)
  Query rangeSum(1,3) on {2, 4, -3, 5, 1}:
   BRUTE:  sum = 0
           i=1 → sum = 0 + 4      = 4
           i=2 → sum = 4 + (-3)   = 1
           i=3 → sum = 1 + 5      = 6     → answer 6 (3 additions)
   PREFIX: p = [2, 6, 3, 8, 9];  l=1, r=3
           p[3] - p[0] = 8 - 2    = 6     → answer 6 (1 subtraction) ✓ same!

  Equilibrium index on {-7, 1, 5, 2, -4, 3, 0}  (total = 0):
   i=0: left = 0,            right = total - a[0] - 0 = 7              → no
   i=1: left = -7,           right = 0 - 1 - (-7) = 6                  → no
   i=2: left = -6,           right = 0 - 5 - (-6) = 1                  → no
   i=3: left = -1,           right = 0 - 2 - (-1) = -1                 → YES  ✓
   i=4: left = 1,            right = 0 - (-4) - 1 = 3                  → no
   i=5: left = -3,           right = 0 - 3 - (-3) = 0                  → no
   i=6: left = 0,            right = 0 - 0 - 0 = 0                     → YES  ✓ (both empty)

 TIME COMPLEXITY CALCULATION:
 - Build: one pass over n elements, constant work each → O(n).
 - k range-sum queries: naive re-adds each query's window (worst window
   length n) → O(k·n). With prefix: one O(n) build + each query is two
   lookups and one subtraction → O(n) + O(k). Single query: O(1) vs O(n).
 - 2D build: visits all R·C cells once, O(1) arithmetic each → O(rows*cols).
   2D query: four lookups + three arithmetic ops → O(1).
 Slow path can't report a bare "O(?)": the arrow states the derived result.
 → Time Complexity = O(n) build for 1D, O(R·C) build for 2D, O(1) per query.
   Brute single range query = O(n); brute per 2D rectangle = O(R·C) cells.

 SPACE COMPLEXITY CALCULATION:
 - 1D prefix array holds n running totals of same magnitude as input → O(n).
 - 2D prefix table holds R·C numbers → O(R*C).
 - The query path itself allocates nothing extra — only the stored tables.
 → Space Complexity = O(n) for 1D; O(R·C) for 2D.

 APPROACH COMPARISON: (real table — brute vs prefix)
 ┌─────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Aspect              │ Brute                        │ Prefix Sum                   │
 ├─────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Range sum per query │ Re-add arr[l..r] → ≤ n steps │ prefix[r]-prefix[l-1] → 3 ops│
 │ q queries total     │ O(q·n)                       │ O(n) build + O(q) total      │
 │ 2D rectangle query  │ Re-add all cells in the box  │ 4 lookups + 3 ops            │
 │ Extra memory        │ None (in-place scratch)      │ n numbers (1D) / R·C (2D)    │
 │ Best when           │ Array changes a lot          │ Static array, many queries   │
 └─────────────────────┴──────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
#include <vector>
using namespace std;

// prefix array build karna — O(n)
vector<long long> buildPrefix(const vector<int>& a) {
    int n = (int)a.size();
    vector<long long> p(n, 0);
    if (n == 0) return p;                     // empty case: kuch nahi hai
    p[0] = a[0];
    for (int i = 1; i < n; ++i)
        p[i] = p[i-1] + a[i];                 // running total aage badhao
    return p;
}

// brute: window ko phir se sum karo — O(r-l+1)
int rangeSumBrute(const vector<int>& a, int l, int r) {
    long long s = 0;
    for (int i = l; i <= r; ++i) s += a[i];
    return (int)s;
}

// prefix se O(1) query; l==0 special case (prefix[-1] invalid hai)
long long rangeSumPrefix(const vector<long long>& p, int l, int r) {
    if (l == 0) return p[r];
    return p[r] - p[l-1];
}

// 2D prefix build — inclusion-exclusion
void build2DPrefix(vector<vector<long long>>& P, const vector<vector<int>>& A) {
    int R = (int)A.size();
    if (R == 0) return;
    int C = (int)A[0].size();
    P.assign(R, vector<long long>(C, 0));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            long long v = A[i][j];
            if (i > 0) v += P[i-1][j];        // upar wala block
            if (j > 0) v += P[i][j-1];        // baaya block
            if (i > 0 && j > 0) v -= P[i-1][j-1]; // corner double-count hatao
            P[i][j] = v;
        }
    }
}

// 2D rectangle sum — O(1) using four corners
long long rectSum(const vector<vector<long long>>& P, int r1, int c1, int r2, int c2) {
    long long res = P[r2][c2];
    if (r1 > 0) res -= P[r1-1][c2];
    if (c1 > 0) res -= P[r2][c1-1];
    if (r1 > 0 && c1 > 0) res += P[r1-1][c1-1];
    return res;
}

// equilibrium index: left sum == right sum — O(n)
int equilibriumIndex(const vector<int>& a) {
    int n = (int)a.size();
    if (n == 0) return -1;
    long long total = 0;
    for (int x : a) total += x;               // ek baar pura sum
    long long left = 0;
    for (int i = 0; i < n; ++i) {
        long long right = total - a[i] - left;
        if (left == right) return i;
        left += a[i];                          // agla index ke liye update
    }
    return -1;                                 // nahi mila
}

int main() {
    cout << "===== PREFIX SUM DEMO =====\n";

    // 1) build prefix for {2,4,-3,5,1}
    vector<int> arr = {2, 4, -3, 5, 1};
    vector<long long> p = buildPrefix(arr);

    cout << "arr    : "; for (int x : arr) cout << x << "  ";
    cout << "\nprefix : "; for (long long x : p) cout << x << "  ";
    cout << "\n";

    // 2) rangeSum(1,3) brute vs prefix — same answer hona chahiye
    int l = 1, r = 3;
    cout << "\nrangeSum(1,3):  brute = " << rangeSumBrute(arr, l, r)
         << "   prefix = " << rangeSumPrefix(p, l, r) << "   (same? "
         << (rangeSumBrute(arr, l, r) == rangeSumPrefix(p, l, r) ? "YES" : "NO") << ")\n";

    // edge: l == 0 → prefix[r] hi answer
    cout << "rangeSum(0,2):  brute = " << rangeSumBrute(arr, 0, 2)
         << "   prefix = " << rangeSumPrefix(p, 0, 2) << "\n";

    // 3) 2D prefix — 3x3 matrix
    vector<vector<int>> M = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<long long>> P2;
    build2DPrefix(P2, M);

    cout << "\n2D prefix table:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) cout << P2[i][j] << "  ";
        cout << "\n";
    }
    cout << "submatrix(0,0)-(2,2) = " << rectSum(P2, 0, 0, 2, 2) << "   (total = 45)\n";
    cout << "submatrix(1,1)-(2,2) = " << rectSum(P2, 1, 1, 2, 2) << "   (5+6+8+9 = 28)\n";

    // 4) equilibrium index
    vector<int> eq = {-7, 1, 5, 2, -4, 3, 0};
    cout << "\nequilibriumIndex({-7,1,5,2,-4,3,0}) = "
         << equilibriumIndex(eq) << "   (index 3)\n";

    // 5) edge cases
    vector<int> empty;
    cout << "\nedge cases:\n";
    cout << "empty prefix size      = " << buildPrefix(empty).size() << "\n";
    cout << "empty equilibriumIndex = " << equilibriumIndex(empty) << "\n";

    vector<int> neg = {-1, -2, -3, -4};       // all negative
    vector<long long> pn = buildPrefix(neg);
    cout << "all-negative prefix    = ";
    for (long long x : pn) cout << x << " ";

    vector<int> k1 = {100};
    vector<long long> p1 = buildPrefix(k1);
    cout << "\nsingle element prefix  = " << p1[0] << "\n";

    return 0;
}