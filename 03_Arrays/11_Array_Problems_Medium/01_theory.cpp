/*
═══════════════════════════════════════════════
 MEDIUM ARRAY CLASSICS
 ⏱️ TIME COMPLEXITY: Kadane brute O(n²) vs KP O(n); Moore's Voting O(n) two
 passes; rainwater brute O(n²), prefix O(n)/O(n), two-pointer O(n)/O(1) —
 every value derived in full below.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Three investors debate their portfolios. First: "which stretch of days gave
 the biggest net gain?" — Kadane. Second: "is any single stock more than half
 of my holdings?" — Moore's voting. Third: rainfall on a 2D cross-section of
 city apartments — how much water gets TRAPPED between the roofs? All three
 look brute-force simple but hide an O(n) insight that an interviewer expects
 you to both code AND prove.

 📖 THEORY (separate sections):

 ─── 1. KADANE — MAXIMUM SUBARRAY ───
 - problem: subarray = contiguous part. Find max(a[l..r]) sum over all l<=r.
 - brute: enumerate every (l,r) pair, sum each subarray → O(n²) subarrays (n(n+1)/2).
 - Kadane (Kadane's algorithm / DP): define current = best sum ENDING exactly
   at index i. Two choices at i: extend the previous best, or start fresh.
       current = max(a[i], current + a[i])
       best    = max(best, current)
   WHY reset to 0 brilliantly: current+a[i] < a[i] exactly when current<0
   (a[i]+current < a[i] ⇔ current < 0). A negative tail only drags the future
   sum down, so we ABANDON it and restart from a[i]. Another common phrasing:
       if (current < 0) current = 0; current += a[i];
   That phrasing returns 0 for an all-negative array (empty subarray), while
   the max(...) phrasing returns the max single negative element — the two
   variants differ ONLY on all-negative input.

 - ASCII — {-2,1,-3,4,-1,2,1,-5,4}:
     i:   0   1   2   3   4   5   6   7   8
     a:  -2   1  -3   4  -1   2   1  -5   4
     cur: -2   1  -2   4   3   5   6   1   5
     best:-2   1   1   4   4   5   6   6   6
                ^ restart   ^ restart        ^ answer 6
   best subarray = [4,-1,2,1] = 6.

 - when to use: max subarray sum, max profit series, max subarray with
   at-most-k changes — anything with "contiguous + sum + maximize".

 ─── 2. MOORE'S VOTING — MAJORITY ELEMENT ───
 - problem: element appearing > n/2 times (if it exists).
 - insight: cancel a majority element against any other element — the count
   can't drop to zero unless it truly is the majority, UNLESS none exists.
 - algorithm (pass 1): candidate=?, votes=0. For each x: if votes==0 → candidate=x,
   votes=1; else x==candidate ? votes++ : votes--.
   Why it works (pairing proof): each vote decrement pairs two DIFFERENT
   elements; the majority element has more than n/2 copies, so some copies
   survive every possible pairing and remain standing as candidate.
 - algorithm (pass 2 — the "proof of two passes"): count occurrences of
   candidate; if count > n/2 return candidate else return -1.
   Pass 2 is MANDATORY: with no majority, pass 1 can still leave a stale
   candidate (e.g. {1,2,3}: votes end at 1 with candidate=3).
 - ASCII — {2,2,1,1,1,2,2}:
     x:2 → c=2 v=1
     x:2 → c=2 v=2
     x:1 → c=2 v=1
     x:1 → c=2 v=0
     x:1 → c=1 v=1   (candidate switch)
     x:2 → c=1 v=0
     x:2 → c=2 v=1   → candidate 2
     pass 2: 2 occurs 4 > 3.5 → majority = 2

 ─── 3. TRAPPING RAIN WATER ───
 - problem: array of wall heights h[], after rain water sits atop lower cells
   between two higher walls. Total water = Σ water[i].
 - key identity: water[i] = min(max of heights left of i, max of heights
   right of i) - h[i], but never negative.
   The bounding wall is the SMALLER of the tallest-left and tallest-right —
   excess spills over that smaller side.
 - brute O(n²): for each i scan left to find L, scan right to find R; add
   min(L,R)-h[i]. Σ per cell O(n) → n cells × O(n) = O(n²).
 - prefix O(n)/O(n): build leftMax[] and rightMax[] in two passes then one
   summing pass → 3 passes, O(n) memory for both arrays.
 - two-pointer O(n)/O(1): l=0,r=n-1, L=lmax,R=rmax. Move the side whose lmax
   is smaller: water(l)=lmax-h[l], since the opposite max (rmax≥lmax) already
   guarantees the smaller cap. This converts the 3 passes into ONE.
 - ASCII — {4,2,0,3,2,5}:
     5 ║
     4 ╬═══════╗
     3 ╬═══╗   ║      water(l)[1]=2  water(0)=0
     2 ╬╗ ║¿¿¿║      water(2)=4     (2)
     0 ╬║ ║║║║║      totals: 2+4+1+2 = 9
        ┴─┴─┴─┴─
 - when to use: any "bounded between extremes" problem, histogram area, skyline.

 🧠 LOGIC — STEP BY STEP:
 Kadane:
  Step 1: cur=0 or a[0], best=a[0] (ya -∞).
    WHY: best must handle all-negative; starting best as a[0] makes the first
    comparison meaningful.
  Step 2: per i, cur = max(a[i], cur+a[i]).
    WHY: either the best subarray ending at i extends one that ended at i-1,
    or a[i] alone is better — this is the DP recurrence in disguise.
  Step 3: best = max(best, cur) and move on.
    WHY: the answer is the max over ALL end points; one running variable is
    enough because the subarray is contiguous.
 Moore's:
  Step 1: count cancellations with a `votes` integer.
    WHY: votes is the excess of majority copies over non-majority ones; a
    decrement pairs the current element against the candidate, removing one of
    each — pairs never destroy a >n/2 element completely.
  Step 2: change candidate only when votes hits 0.
    WHY: zero votes means the surviving prefix has no majority claim; the
    suffix from this point is the same problem, so restart.
  Step 3 (pass 2): count candidate in full array.
    WHY: voting only CERTIFIES a candidate; it PROVES majority only after
    recounting beats n/2.
 Rainwater:
  Step 1: brute — per i scan both sides.
    WHY: literal reading of the bounding-wall identity, correct but slow.
  Step 2: prefix — record L[i], R[i] arrays.
    WHY: recomputing L/R per i is the n² waste; storing extremes once turns
    each cell's work into O(1) array reads.
  Step 3: two-pointer — walk inward on the smaller cap side.
    WHY: at l, everything right of r is ≥ h[r] only... actually the invariant
    is: lmax is max of [0..l], rmax of [r..n-1]. When lmax ≤ rmax, cell l is
    capped by lmax because the right side has at least rmax ≥ lmax available;
    so we can charge water(l) and move l right without needing the true
    right-side peak.

 VISUAL WALKTHROUGH:
  Rainwater {4,2,0,3,2,5} step-by-step with prefix:
    h:     4  2  0  3  2  5
    L:     4  4  4  4  4  5
    R:     5  5  5  5  5  5
    min:   4  4  4  4  4  5
    min-h: 0  2  4  1  2  0   → Σ = 9
  Kadane table for {-2,1,-3,4,-1,2,1,-5,4} shown in ASCII above → 6.
  Moore's on {2,2,1,1,1,2,2} traced in ASCII above → 2.

 DRY RUN:
  Kadane {1,-2,3}:
    cur=0 → +1=1,best=1 → cur=-1, best=1 → max(3, -1+3)=3,best=3 → 3
  Kadane all-negative {-3,-1,-2} (max-form):
    cur=-3,best=-3 → max(-1,-4)=-1,best=-1 → max(-2,-3)=-2,best=-1 → -1 ✓
  Moore's no-majority {1,2,3}:
    c=1v=1 → c=1v=0 → c=3v=1 → pass2: 3 occurs once ≤1.5 → return -1 ✓
  Rainwater plateau heights {2,2,2}: L={2,2,2} R={2,2,2} → all water 0.
  Rainwater n=1 {5}: L=R=5 → water 0 ✓.

 TIME COMPLEXITY CALCULATION:
 - Kadane brute: number of subarrays = C(n+1,2) = n(n+1)/2; summing each takes
   up to O(n) naive, or O(1) with running sums → O(n²). Kadane: one pass with
   two constant-time updates per element → O(n).
 - Moore's: pass1 = n voting steps O(1) each; pass2 = n recount steps. Total
   2n → O(n). Space: 2 variables → O(1).
 - Rainwater brute: per cell i, left scan ≤ i and right scan ≤ n-1-i steps →
   Σ(i + (n-1-i)) = Σ(n-1) = n(n-1) → O(n²). Prefix: 2 build passes of n
   elements + 1 sum pass of n = 3n → O(n), space L and R arrays O(n). 
   Two-pointer: single while loop, each iteration moves l or r once, indices
   travel ≤ n total → O(n), space O(1).
    Σ-form for Kadane's n²: n(n+1)/2 subarrays each O(1) running sum → O(n²).
 → Time Complexity = Kadane O(n²) brute / O(n) KP; Moore's O(n); rainwater
   O(n²) brute / O(n) prefix / O(n) two-pointer.

 SPACE COMPLEXITY CALCULATION:
 - Kadane: cur+best only → O(1).
 - Moore's: candidate+votes → O(1).
 - Rainwater: brute O(1); prefix two extra arrays of size n → O(n); two-pointer
   four scalars (l,r,L,R) → O(1).
 → Space Complexity = Kadane/Moore O(1); rainwater brute O(1), prefix O(n),
   two-pointer O(1).

 APPROACH COMPARISON: (one table per classic)
 ┌───────────────────────┬──────────────────────────┬──────────────────────────┐
 │ KADANE                │ Brute                    │ Kadane O(n)              │
 ├───────────────────────┼──────────────────────────┼──────────────────────────┤
 │ subarray count        │ n(n+1)/2 enumerations    │ 1 pass, DP recurrence    │
 │ time                  │ O(n²)                    │ O(n)                     │
 │ all-negative result   │ max single (correct)     │ max single (max-form)    │
 │ space                 │ O(1)                     │ O(1)                     │
 └───────────────────────┴──────────────────────────┴──────────────────────────┘
 ┌───────────────────────┬──────────────────────────┬──────────────────────────┐
 │ MAJORITY              │ sort & pick middle       │ Moore's voting           │
 ├───────────────────────┼──────────────────────────┼──────────────────────────┤
 │ time                  │ O(n log n)               │ O(n) two passes          │
 │ correctness check     │ needs count walk anyway  │ pass-2 recount           │
 │ space                 │ O(1)                     │ O(1)                     │
 └───────────────────────┴──────────────────────────┴──────────────────────────┘
 ┌───────────────────────┬──────────────┬──────────────┬───────────────────────┐
 │ RAINWATER             │ Brute        │ Prefix       │ Two-pointer            │
 ├───────────────────────┼──────────────┼──────────────┼───────────────────────┤
 │ time                  │ O(n²)        │ O(n)         │ O(n)                  │
 │ space                 │ O(1)         │ O(n)         │ O(1)                  │
 │ passes                │ n scans      │ 2 build+1 sum│ single l/r walk       │
 │ best interview answer │ —            │ easy+clear   │ trickiest but optimal │
 └───────────────────────┴──────────────┴──────────────┴───────────────────────┘
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// --- KADANE ---
int kadaneBrute(const vector<int>& a) {           // O(n²)
    int n = (int)a.size(), best = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = i; j < n; ++j) { s += a[j]; best = max(best, s); }
    }
    return best;
}
int kadaneDP(const vector<int>& a) {               // O(n), max-form
    int cur = 0, best = INT_MIN;
    for (int x : a) {
        cur = max(x, cur + x);                    // restart ya extend?
        best = max(best, cur);
    }
    return best;
}

// --- MOORE'S VOTING ---
int majority(const vector<int>& a) {
    int cand = 0, votes = 0;
    for (int x : a) {                             // PASS 1 — cancellation
        if (votes == 0)      { cand = x; votes = 1; }
        else if (x == cand)  ++votes;
        else                 --votes;
    }
    int cnt = 0;                                  // PASS 2 — mandatory verify
    for (int x : a) if (x == cand) ++cnt;
    return (cnt > (int)a.size() / 2) ? cand : -1;
}

// --- TRAPPING RAIN WATER: 3 approaches ---
int rainBrute(const vector<int>& h) {              // O(n²)
    int n = (int)h.size(), water = 0;
    for (int i = 0; i < n; ++i) {
        int L = 0, R = 0;
        for (int j = 0; j <= i; ++j) L = max(L, h[j]);          // left max
        for (int j = i; j < n; ++j) R = max(R, h[j]);           // right max
        water += max(0, min(L, R) - h[i]);
    }
    return water;
}
int rainPrefix(const vector<int>& h) {             // O(n) time, O(n) space
    int n = (int)h.size();
    if (n == 0) return 0;
    vector<int> L(n), R(n);
    L[0] = h[0];
    for (int i = 1; i < n; ++i) L[i] = max(L[i-1], h[i]);
    R[n-1] = h[n-1];
    for (int i = n-2; i >= 0; --i) R[i] = max(R[i+1], h[i]);
    int water = 0;
    for (int i = 0; i < n; ++i) water += min(L[i], R[i]) - h[i];
    return water;
}
int rainTwoPointer(const vector<int>& h) {         // O(n) time, O(1) space
    int n = (int)h.size();
    int l = 0, r = n - 1, lmax = 0, rmax = 0, water = 0;
    while (l <= r) {
        if (lmax <= rmax) {                       // left cap decisive
            lmax = max(lmax, h[l]);
            water += lmax - h[l];
            ++l;
        } else {
            rmax = max(rmax, h[r]);
            water += rmax - h[r];
            --r;
        }
    }
    return water;
}

int main() {
    vector<int> k = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "KADANE on {-2,1,-3,4,-1,2,1,-5,4}\n";
    cout << "  brute = " << kadaneBrute(k) << "\n";
    cout << "  DP    = " << kadaneDP(k) << "   (expected 6)\n";

    vector<int> neg = {-3,-1,-2};
    cout << "  all-negative {-3,-1,-2} DP = " << kadaneDP(neg) << " (max single)\n";

    cout << "\nMOORE'S VOTING on {2,2,1,1,1,2,2}\n";
    cout << "  majority = " << majority({2,2,1,1,1,2,2}) << "   (expected 2)\n";
    cout << "  no-majority {1,2,3} = " << majority({1,2,3}) << "\n";
    cout << "  n=1 {9} = " << majority({9}) << "\n";

    vector<int> ra = {4,2,0,3,2,5};
    cout << "\nRAINWATER on {4,2,0,3,2,5}\n";
    cout << "  brute       = " << rainBrute(ra) << "\n";
    cout << "  prefix      = " << rainPrefix(ra) << "\n";
    cout << "  two-pointer = " << rainTwoPointer(ra) << "   (expected 9)\n";
    cout << "  plateau {2,2,2} = " << rainTwoPointer({2,2,2})
         << "   n=1 {5} = " << rainTwoPointer({5}) << "\n";

    return 0;
}