/*
═══════════════════════════════════════════════
 TASK SET — PREFIX SUM TECHNIQUE
═══════════════════════════════════════════════

🌍 REAL-WORLD SCENARIO:
 A teacher stores term-wise cumulative marks and gets many "sum between two
 weeks" questions; a cashier pastes a running-total bill so a customer never
 re-adds the items. Every problem here is "answer repeated sum questions fast
 by pre-computing running totals once."

🧠 HOW TO SOLVE:
 Always precompute a prefix array first (one O(n) pass), then reduce each
 query to a couple of lookups/subtractions. For "divisible by k" use prefix
 remainders; for "except self" use prefix and suffix products; for 2D use the
 inclusion-exclusion rectangle formula.

 5 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE

  ── TASK 1 (EASY) — build & print prefix ─────────────────────────────
  (a) Given arr, build prefix[i] = arr[0]+...+arr[i] and print both.
  💡 HINT: prefix[i] = prefix[i-1] + arr[i]; prefix[0] = arr[0].
  ✏️ STARTER CODE:
      vector<long long> buildPrefix(const vector<int>& a) {
          // n = a.size(); vector<long long> p(n);
          // p[0] = a[0]; for i=1..n-1: p[i] = p[i-1] + a[i];
          // return p;
      }
      int main() { // take arr, buildPrefix, print -- 2 loops
      }

  ── TASK 2 (EASY) — range sum queries (l, r) ─────────────────────────
  (b) For q queries (l,r) print sum of arr[l..r] — compare brute & prefix.
  💡 HINT: l==0 → prefix[r]; else prefix[r] - prefix[l-1].
  ✏️ STARTER CODE:
      long long rangeSumPrefix(const vector<long long>& p, int l, int r) {
          // special-case l==0
          // return p[r] - p[l-1];
      }

  ── TASK 3 (MEDIUM) — subarrays with sum divisible by k ──────────────
  (c) Count subarrays whose sum % k == 0.
  💡 HINT: sum(l..r)%k==0 ⟺ prefix[r]%k == prefix[l-1]%k. Store each
          remainder in a box; when the same remainder appears again,
          count += freq. Make negative mods safe with ((x%k)+k)%k.
  ✏️ STARTER CODE:
      int countDivisible(vector<int>& a, int k) {
          // freq[k] = 0; freq[0] = 1; running = 0; ans = 0;
          // for each element: running = (running + a[i]) % k (safe mod)
          // ans += freq[running]; freq[running]++;
      }

  ── TASK 4 (MEDIUM) — equilibrium index ──────────────────────────────
  (d) Return first index where sum(left side) == sum(right side).
  💡 HINT: compute the total sum first; keep left in the loop, right =
          total - a[i] - left. When left == right, return i.
  ✏️ STARTER CODE:
      int equilibriumIndex(const vector<int>& a) {
          // total = sum(a); left = 0;
          // for i: right = total - a[i] - left; if (left==right) return i;
          //         left += a[i];
          // return -1;
      }

  ── TASK 5 (HARD) — 2D submatrix sum queries ─────────────────────────
  (e) Build 2D prefix, then answer many rectangle-sum queries in O(1).
  💡 HINT: P[i][j] = A[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
          query = P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1];
          out-of-range terms = 0.
  ✏️ STARTER CODE:
      void build2D(vector<vector<long long>>& P, const vector<vector<int>>& A);
      long long rectSum(const vector<vector<long long>>& P, int r1,int c1,int r2,int c2);

  ── TASK 6 (HARD) — product of array except self ─────────────────────
  (f) For each i, ans[i] = product of all elements except a[i] — NO division.
  💡 HINT: keep left prefix products in one array and right suffix products
          in another, ans[i] = left[i-1] * right[i+1] (use 1 at the
          boundaries).
  ✏️ STARTER CODE:
      vector<long long> productExceptSelf(const vector<int>& a) {
          // left[i] = product of a[0..i], right[i] = product of a[i..n-1]
          // ans[i] = (i>0? left[i-1] : 1) * (i<n-1? right[i+1] : 1)
      }

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
using namespace std;

// ---- Task 1: build & print prefix ----
vector<long long> buildPrefix(const vector<int>& a) {
    int n = (int)a.size();
    vector<long long> p(n, 0);
    if (n == 0) return p;                    // empty safe
    p[0] = a[0];                             // pehle ka running total = khud
    for (int i = 1; i < n; ++i)
        p[i] = p[i-1] + a[i];                // purana total + naya element
    return p;
}

// ---- Task 2: range sum queries ----
long long rangeSumPrefix(const vector<long long>& p, int l, int r) {
    if (l == 0) return p[r];                 // prefix[-1] valid nahi hota
    return p[r] - p[l-1];                    // aage ka pura minus peeche ka
}

// ---- Task 3: subarrays with sum divisible by k ----
int safeMod(long long x, int k) {            // negative remainder bachao
    return (int)(((x % k) + k) % k);
}
int countDivisible(const vector<int>& a, int k) {
    vector<int> freq(k, 0);                  // har remainder kitni baar aaya
    freq[0] = 1;                             // empty prefix ki remainder 0
    long long running = 0;
    int ans = 0;
    for (int x : a) {
        running = safeMod(running + x, k);
        ans += freq[running];                // same remainder walo se naye subarrays
        freq[running]++;
    }
    return ans;
}

// ---- Task 4: equilibrium index ----
int equilibriumIndex(const vector<int>& a) {
    int n = (int)a.size();
    if (n == 0) return -1;
    long long total = 0;
    for (int x : a) total += x;              // pura sum ek baar
    long long left = 0;
    for (int i = 0; i < n; ++i) {
        long long right = total - a[i] - left; // middle element ko hatao
        if (left == right) return i;
        left += a[i];                        // agle index ke liye badhao
    }
    return -1;
}

// ---- Task 5: 2D submatrix sum ----
void build2D(vector<vector<long long>>& P, const vector<vector<int>>& A) {
    int R = (int)A.size();
    if (R == 0) return;
    int C = (int)A[0].size();
    P.assign(R, vector<long long>(C, 0));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            long long v = A[i][j];
            if (i > 0) v += P[i-1][j];       // upar ka pura block
            if (j > 0) v += P[i][j-1];       // baya pura block
            if (i > 0 && j > 0) v -= P[i-1][j-1]; // corner double-count
            P[i][j] = v;
        }
}
long long rectSum(const vector<vector<long long>>& P, int r1, int c1, int r2, int c2) {
    long long res = P[r2][c2];
    if (r1 > 0) res -= P[r1-1][c2];
    if (c1 > 0) res -= P[r2][c1-1];
    if (r1 > 0 && c1 > 0) res += P[r1-1][c1-1];  // minus-minus wapas add
    return res;
}

// ---- Task 6: product except self (prefix/suffix) ----
vector<long long> productExceptSelf(const vector<int>& a) {
    int n = (int)a.size();
    vector<long long> left(n, 1), right(n, 1), ans(n, 1);
    if (n == 0) return ans;
    left[0] = a[0];
    for (int i = 1; i < n; ++i) left[i] = left[i-1] * a[i];   // prefix product
    right[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i) right[i] = right[i+1] * a[i]; // suffix product
    for (int i = 0; i < n; ++i)
        ans[i] = (i > 0 ? left[i-1] : 1) * (i < n-1 ? right[i+1] : 1);
    return ans;
}

int main() {
    cout << "===== PREFIX SUM TASKS =====\n";

    // Task 1 demo
    vector<int> a = {2, 4, -3, 5, 1};
    vector<long long> p = buildPrefix(a);
    cout << "T1 prefix: ";
    for (long long x : p) cout << x << " ";
    cout << '\n';

    // Task 2 demo
    cout << "T2 rangeSum(1,3) = " << rangeSumPrefix(p, 1, 3)
         << "  rangeSum(0,2) = " << rangeSumPrefix(p, 0, 2) << '\n';

    // Task 3 demo — {4,5,0,-2,-3,1}, k=5 → answer 7
    vector<int> c = {4, 5, 0, -2, -3, 1};
    cout << "T3 countDivisible(k=5) = " << countDivisible(c, 5)
         << "   (expected 7)\n";

    // Task 4 demo
    vector<int> e = {-7, 1, 5, 2, -4, 3, 0};
    cout << "T4 equilibriumIndex = " << equilibriumIndex(e) << "   (index 3)\n";

    // Task 5 demo
    vector<vector<int>> M = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<long long>> P2;
    build2D(P2, M);
    cout << "T5 rect(0,0,2,2) = " << rectSum(P2, 0, 0, 2, 2)
         << "  rect(1,1,2,2) = " << rectSum(P2, 1, 1, 2, 2) << '\n';

    // Task 6 demo
    vector<int> f = {1, 2, 3, 4};
    vector<long long> res = productExceptSelf(f);
    cout << "T6 productExceptSelf: ";
    for (long long x : res) cout << x << " ";
    cout << "   (2*3*4, 1*3*4, 1*2*4, 1*2*3)\n";

    return 0;
}