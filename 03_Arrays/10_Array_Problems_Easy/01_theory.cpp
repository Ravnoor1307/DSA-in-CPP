/*
═══════════════════════════════════════════════
 EASY ARRAY CLASSICS
 ⏱️ TIME COMPLEXITY: each classic is O(n) single-pass with O(1) extra space —
 isSorted O(n), removeElement O(n), threeLargest O(n), segregate O(n),
 leaders O(n), maxProfit O(n) vs brute O(n²) — all derived below.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A quality-control inspector scans one product each second on a conveyor
 belt: is this batch still sorted by weight? Remove all defective items from
 the box by sliding good ones forward. Which three are the heaviest? Route
 even/odd items to different bins. Who leads the race right now (a racer
 whose time beats everyone behind him)? And the stock question every trader
 asks: buy low, sell high ONCE. All of these are "walk the line once, keep a
 couple of variables" problems — the foundation interviewers expect by heart.

 📖 THEORY:
 - PROBLEM 1 — isSorted: given a[], decide if a[i] <= a[i+1] for all i<n-1.
   Single pass; the moment a[i] > a[i+1] the array is NOT sorted.
 - PROBLEM 2 — removeElement: remove ALL copies of value `val` in-place,
   return the new length. Order of survivors need NOT be preserved.
   Two-pointer (read index r, write index w): copy only non-matching values.
 - PROBLEM 3 — threeLargest distinct: find the 3 largest DISTINCT values.
   Three running variables first,second,third + shift-down on each bigger hit.
 - PROBLEM 4 — segregateEvenOdd: move all evens before all odds (relative
   order of either group is optional). Two-pointer from both ends; swap when
   left has an odd and right has an even.
 - PROBLEM 5 — leaders: a[i] is a leader if it is greater than EVERY element
   to its right. The last element is always a leader. Scan right→left keeping
   max-so-far; a[i] > maxOfRight ⇒ leader. (Also prints in L→R order by
   reversing the collected leaders.)
 - PROBLEM 6 — stockBuySell ONE transaction: choose buy day i and sell day j
   (i<j) maximizing profit a[j]-a[i]; if no profit possible, answer 0.
   Brute checks all (i,j) pairs; O(n) keeps min-price-so-far and updates
   best profit = price - minSoFar.

   ASCII map of the six tools:
     isSorted       → 1 2 3 4 ✓   (any descent kills it)
     removeElement  → w r pointers sliding together
     threeLargest   → 3 pigeonholes, each new big pushes down
     segregate      → <-- swap --> two ends meet
     leaders        → scan ←  with max so far
     maxProfit      → keep min, best = price - min

 - When to use: every one of these is a "one scan + answer" problem. If an
   interviewer says "can you do it in ONE pass / O(1) extra?", reach for
   running-variable tricks or two pointers.

 🧠 LOGIC — STEP BY STEP:
 Step 1 (isSorted): for i=0..n-2, if a[i] > a[i+1] return false; else true.
      WHY: sorted means no adjacent descent anywhere; testing neighbours is
      cheaper than comparing to min/max and just as correct.
 Step 2 (removeElement): w=0; for r in 0..n-1: if a[r]!=val → a[w++]=a[r].
      WHY: the write pointer only advances when we KEEP a value, the read
      pointer always advances; victims of `val` get overwritten by kept
      values — no shifting, O(n), and w is exactly the new length.
 Step 3 (threeLargest): init first=second=third = very small; for each x:
      skip if x equals one of them (distinct!), else shift chain down.
      WHY: keeping only the TOP-3 means at most 3 compares per element; an
      element moves first→second→third as bigger ones arrive, so we never
      rescan history.
 Step 4 (segregate): left points at first odd, right points at last even;
      while left<right swap them, then advance both inward.
      WHY: evens belong in the low half, odds in the high half; a swap fixes
      exactly one misplaced pair, and since both pointers only move toward
      each other, total work is n/2 swaps → O(n).
 Step 5 (leaders): mx=-∞; for i=n-1 down to 0: if a[i] > mx → push leader,
      mx = a[i]. Then reverse the result.
      WHY: "greater than all to the right" is exactly "greater than the max
      of the right side"; scanning backwards makes that max a running
      variable instead of a re-scan.
 Step 6 (maxProfit): mn=+∞, best=0; for each price: mn=min(mn,price),
      best=max(best, price-mn). Brute: i<j loops.
      WHY: any profit a[j]-a[i] is maximised when a[i] is the global min
      BEFORE j; tracking one running min computes every candidate cheaply.

 VISUAL WALKTHROUGH:
  removeElement {3,2,2,3}, val=3:
    r=0 (3≠ kept? no) w=0    r=1 (2 kept) a[0]=2 w=1
    r=2 (2 kept) a[1]=2 w=2   r=3 (3 skip) → new length 2 → {2,2,*,*}
    Actually scan residuals:
       [ 3  2  2  3 ]
       w
       r→3 skip          w stays
          r→2 copy → [2 2 2 3] ... see DRY RUN for true trace.

  threeLargest distinct on {10,4,3,10,8}:
    x=10 → f=10
    x=4  → f=10 s=4
    x=3  → f=10 s=4 t=3
    x=10 → already present → skip
    x=8  → f=10 s=8 t=4  → {10,8,4}

  leaders on {16,17,4,3,5,2}:
    ← 2 is leader (mx=2)
    ← 5>2 leader (mx=5)
    ← 3 no  ← 4 no
    ← 17>5 leader (mx=17)
    ← 16 no → leaders L→R = {17,5,2}

  maxProfit {7,1,5,3,6,4}:
    mn=7  best=0
    mn=1  best=0
    price5 best=4 (5-1)
    price3 best=4
    price6 best=5 (6-1) → answer 5 (buy 1, sell 6)
    price4 best=5

 DRY RUN:
  isSorted {1,2,2,3} → 1≤2 ✓, 2≤2 ✓, 2≤3 ✓ → true
  isSorted {3,2,1}   → 3>2 → false
  isSorted {}        → loop doesn't run → true (vacuously sorted)
  isSorted {9}       → true (single element is sorted)

  removeElement {3,2,2,3}, val=3:
    w=0 r=0: a[0]=3==val skip                    (array {3,2,2,3})
    w=0 r=1: a[1]=2 !=val → a[0]=2, w=1          (array {2,2,2,3})
    w=1 r=2: a[2]=2 !=val → a[1]=2, w=2          (array {2,2,2,3})
    w=2 r=3: a[3]=3==val skip
    → new length 2, prefix {2,2} ✓

  maxProfit decreasing {5,4,3,2,1}: per daam kam → best stays 0 ✓ (edge)
  maxProfit single {7} → loop once → best=0 ✓
  all equal {3,3,3}: mn=3 best stays 0 ✓ (no profitable trade)

 TIME COMPLEXITY CALCULATION:
 - isSorted: single loop of n-1 comparisons → n-1 ≤ n → O(n), O(1) space.
 - removeElement: read pointer visits n elements, write ≤ n times → O(n),
   O(1) extra (in-place overwrites).
 - threeLargest: each element: 1 duplicate-check + ≤3 comparisons → 4n → O(n),
   constant variables → O(1).
 - segregate: two pointers travel toward each other, total ≤ n moves → O(n)
   with at most n/2 swaps → O(1) space.
 - leaders: one reverse pass of n steps + reverse of result (d leaders) → n+d
   ≤ 2n → O(n); output array O(d) ⊆ O(n).
 - maxProfit brute: Σ(i=0..n-2)(n-1-i) pairs = n(n-1)/2 → O(n²), O(1) space.
   maxProfit O(n): one pass, each step 2 constant ops → O(n), O(1) space.
 → Time Complexity = O(n) each for the O(n)-style classics; brute maxProfit O(n²).
   All use O(1) auxiliary space except leaders' output list (O(d), d=no. leaders).

 SPACE COMPLEXITY CALCULATION:
 - isSorted / removeElement / threeLargest / segregate / maxProfit: only a
   handful of scalars (pointers, running minima, bests) → O(1).
 - leaders: needs to return an array of results; at most d ≤ n leaders
   collected, then reversed in place → O(d) ⊆ O(n) for the answer, O(1)
   beyond that.
 → Space Complexity = O(1) all classics (output storage for leaders O(n) worst).

 APPROACH COMPARISON: (brute vs O(n) single-pass snapshot)
 ┌──────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Problem          │ Brute                        │ O(n)/O(1) single-pass        │
 ├──────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ isSorted         │ n² compares of every pair    │ n-1 neighbour compares        │
 │ removeElement    │ copy to new array + move     │ two-pointer overwrite w/r     │
 │ threeLargest     │ sort then take last 3        │ shift-chain of 3 variables    │
 │ segregate        │ stable partition (extra buf) │ swap two ends, order-free     │
 │ leaders          │ for each i scan right O(n²)  │ reverse scan with max O(n)    │
 │ maxProfit        │ all (i,j) pairs O(n²)        │ running min, best=price-min   │
 └──────────────────┴──────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 1) SORTED CHECK — O(n), doosre element se neighbours compare
bool isSorted(const vector<int>& a) {
    for (int i = 1; i < (int)a.size(); ++i)
        if (a[i] < a[i-1]) return false;   // koi descent mila → not sorted
    return true;                            // empty/single also sorted
}

// 2) REMOVE ELEMENT (in-place) — w=write r=read pointers; return new length
int removeElement(vector<int>& a, int val) {
    int w = 0;
    for (int r = 0; r < (int)a.size(); ++r)
        if (a[r] != val) a[w++] = a[r];    // sirf keep-worthy values copy
    return w;
}

// 3) THREE LARGEST DISTINCT — chain: first > second > third
vector<int> top3(const vector<int>& a) {
    vector<int> f(3, INT_MIN);
    for (int x : a) {
        if (x == f[0] || x == f[1] || x == f[2]) continue;
        if (x > f[0])      { f[2]=f[1]; f[1]=f[0]; f[0]=x; }
        else if (x > f[1]) { f[2]=f[1]; f[1]=x; }
        else if (x > f[2]) { f[2]=x; }
    }
    // drop sentinel placeholders for missing slots
    vector<int> out;
    for (int v : f) if (v != INT_MIN) out.push_back(v);
    return out;
}

// 4) SEGREGATE EVEN/ODD — evens first, odds after (order optional)
void segregateEvenOdd(vector<int>& a) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        if (a[l] % 2 == 0)      { ++l; }      // left even → already right side
        else if (a[r] % 2 == 1) { --r; }      // right odd → already on right
        else                    { swap(a[l], a[r]); ++l; --r; } // misplaced pair
    }
}

// 5) LEADERS — element greater than all to its right; right→left scan
vector<int> leaders(const vector<int>& a) {
    vector<int> res;
    int mx = INT_MIN;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (a[i] > mx) { res.push_back(a[i]); mx = a[i]; } // greater than max(right)
    }
    reverse(res.begin(), res.end());   // L→R order me print karna hai
    return res;
}

// 6) STOCK BUY/SELL — one transaction
int maxProfitBrute(const vector<int>& p) {
    int best = 0, n = (int)p.size();
    for (int i = 0; i < n; ++i)                // buy day
        for (int j = i+1; j < n; ++j)          // sell day (after buy)
            best = max(best, p[j] - p[i]);
    return best;
}

int maxProfitO1(const vector<int>& p) {
    int mn = INT_MAX, best = 0;
    for (int price : p) {
        mn = min(mn, price);                  // aaj tak ka sabse sasta buy
        best = max(best, price - mn);         // is buy se kitna profit milta
    }
    return best;
}

void show(const vector<int>& v) {
    cout << "{";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << (i+1 < v.size() ? ", " : "");
    cout << "}";
}

int main() {
    cout << "=== 1) isSorted ===\n";
    vector<vector<int>> s = {{1,2,2,3}, {3,2,1}, {}, {9}, {5,5,5}};
    for (auto& v : s) { cout << "  a="; show(v); cout << " → " << (isSorted(v) ? "yes":"no") << "\n"; }

    cout << "\n=== 2) removeElement ===\n";
    vector<int> rm = {3,2,2,3};
    int newLen = removeElement(rm, 3);
    cout << "  {3,2,2,3} remove 3 → newLen=" << newLen << ", prefix=";
    for (int i = 0; i < newLen; ++i) cout << rm[i] << " ";
    cout << "\n";

    cout << "\n=== 3) three largest distinct ===\n";
    vector<int> t = {10,4,3,10,8};
    cout << "  {10,4,3,10,8} → "; show(top3(t)); cout << "\n";

    cout << "\n=== 4) segregate even/odd ===\n";
    vector<int> se = {1,2,3,4,5,6};
    segregateEvenOdd(se);
    cout << "  {1,2,3,4,5,6} → "; show(se); cout << "\n";

    cout << "\n=== 5) leaders ===\n";
    vector<int> ld = {16,17,4,3,5,2};
    vector<int> lres = leaders(ld);
    cout << "  {16,17,4,3,5,2} → "; show(lres); cout << "\n";

    cout << "\n=== 6) stock max profit ===\n";
    vector<int> px = {7,1,5,3,6,4};
    cout << "  {7,1,5,3,6,4} brute=" << maxProfitBrute(px)
         << "  O(n)=" << maxProfitO1(px) << "\n";
    vector<int> dec = {5,4,3,2,1};
    cout << "  decreasing {5,4,3,2,1} brute=" << maxProfitBrute(dec)
         << "  O(n)=" << maxProfitO1(dec) << "\n";
    cout << "  single {4} → " << maxProfitO1({4}) << "\n";

    return 0;
}