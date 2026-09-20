/*
═══════════════════════════════════════════════
 HARD ARRAY CLASSICS
 ⏱️ TIME COMPLEXITY: maxConsecutiveOnesK O(n) sliding window; longestConsecutive
 sort O(n log n)/O(1) vs hash-set O(n)/O(n); nextPermutation O(n); rotateMatrix
 O(n²) per 90° — every value derived step by step below.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Four notoriously slippery interview staples. A data-center analyst finds the
 longest streak of working servers when repairing at most k of them (flip K
 zeros). A sports league runner tries to see if a set of athletes' jersey
 numbers forms a consecutive rank run (longest consecutive sequence). A
 dictionary app shows the lexicographically next word after "1,3,5,4,2"
 (next permutation). And a photo editor rotates a camera matrix 90° clockwise
 (rotate matrix). Each hides a 5-line insight that replaces a naive variant.

 📖 THEORY (separate sections):

 ─── 1. MAX CONSECUTIVE ONES (with ≤ k zero flips) ───
 - problem: binary array, you may flip at most k zeros → maximize the longest
   run of consecutive 1s. (LeetCode "Max Consecutive Ones III")
 - naive expansion: for every start index, extend right while zeros ≤ k;
   total O(n²) because each start re-explores the tail.
 - sliding window O(n): maintain window [l,r] with a `zeros` count. Grow r;
   when zeros > k, shrink l until zeros ≤ k. Every index is l once and r once
   → at most 2n moves. Answer = max(r-l+1) over all valid windows.
 - key insight: the window is a "best prefix" — an element never needs to be
   evaluated twice because shrinking only removes what hurts the invariant.
 - ASCII — {1,1,0,1,1,0,1,1,1}, k=1:
     idx:  0 1 2 3 4 5 6 7 8
     val:  1 1 0 1 1 0 1 1 1
     window [0..8] has zeros at 2,5 → needs k=2
     window [3..8] has ONE zero (idx5) → len 6 ← max allowed with k=1
     shrink point: idx 2's zero, after removing l=0,1,2 we drop idx2 zero.
 - when to use: "longest subarray satisfying a count/sum constraint" — the
   exact signature of sliding-window.

 ─── 2. LONGEST CONSECUTIVE SEQUENCE ───
 - problem: given unsorted ints, find the length of the LONGEST sequence of
   consecutive integers (order irrelevant). {100,4,200,1,3,2} → 4 (1,2,3,4).
 - approach A — SORT O(n log n): sort, then sweep counting consecutive runs
   (skip duplicates); O(n log n) time, O(1) extra (in-place sort).
 - approach B — HASH SET O(n): insert all into unordered_set. For each x with
   (x-1) NOT in set → x is a run START. Stretch: while set contains x+len,
   len++. Because only run-starts stretch, total stretch work is O(n).
 - key insight: checking `set.count(x-1)` excludes a huge fraction of elements
   (non-starts), making the whole thing amortized linear instead of O(n²).
 - ASCII:
     set = {100, 4, 200, 1, 3, 2}
     x=100 has 99? no → start, stretch 101? no → len 1
     x=4   has 3? YES → not a start, skip
     x=200 has 199? no → start, stretch → len 1
     x=1   has 0? no → start → 2,3,4 → len 4  ← answer
     x=3   has 2? yes → skip;  x=2 has 1? yes → skip
 - when to use: "consecutive/longest streak" with O(n) implied, dedupe via set.

 ─── 3. NEXT PERMUTATION ───
 - problem: rearrange a[] into the next lexicographically greater arrangement
   (same multiset); if already the largest, wrap to sorted ascending.
   {1,3,5,4,2} → {1,4,2,3,5}.
 - steps (textbook, O(n)):
   (a) find pivot i = rightmost index with a[i] < a[i+1] (rightmost ascent),
       scanning from the end.
   (b) find j = rightmost index with a[j] > a[i]; swap a[i], a[j].
   (c) reverse the suffix (i+1..end) → it was decreasing, becomes increasing.
   (d) if NO pivot found, array was fully descending → reverse whole → sorted
       ascending (the "last permutation" edge case).
 - WHY it works: the suffix after i is strictly decreasing, i.e. already the
   maximum arrangement of that tail; the next permutation must bump a[i] to the
   smallest element greater than it (in that tail) and then re-arrange the tail
   into its smallest form (reverse).
 - ASCII — {1,3,5,4,2}:
     step a: scan ←  2→4 no, 4→5 no, 5→3 YES → pivot i=1 (value 3)
             suffix {5,4,2} is decreasing ✓
     step b: rightmost > 3 in suffix → 4 at j=3 → swap → {1,4,5,3,2}
     step c: reverse position 2..4 → {1,4,2,3,5} ✓
 - when to use: permutations in order, k-th permutation generation, "next
   greater arrangement" style problems.

 ─── 4. ROTATE MATRIX 90° ───
 - problem: rotate an n×n matrix CLOCKWISE in place.
 - approach A — TRANSPOSE + REVERSE ROWS: A_T = (A^T) flips across the main
   diagonal; then reverse each row. Combined = clockwise 90°.
 - approach B — FOUR-WAY CYCLE (in-place, no reverse): rotate four corners in
   a cycle for each ring position. Both are O(n²); transpose+reverse is far
   easier to write and explain.
 - ASCII — 3×3:
     original        transpose        reverse rows
     1 2 3           1 4 7           7 4 1
     4 5 6      →    2 5 8      →    8 5 2
     7 8 9           3 6 9           9 6 3
 - when to use: image/board rotation, any "matrix transformation" that can be
   decomposed into standard linear operations.

 🧠 LOGIC — STEP BY STEP:
 MaxConsecutiveOnesK:
  Step 1: l=0, zeros=0, best=0; loop r over array.
    WHY: window invariants need one growing side and one lazy shrink side.
  Step 2: if a[r]==0 → zeros++; while zeros>k → if a[l]==0 zeros--, l++.
    WHY: shrink ONLY until the invariant (≤k zeros) is restored; extra
    shrinking can't help maximize length.
  Step 3: best = max(best, r-l+1).
    WHY: every valid window is a candidate; r-l+1 is cheap to compute.
 LongestConsecutive:
  Step 1 (hash): insert all numbers into unordered_set.
    WHY: membership tests must be O(1) to allow stretching.
  Step 2: for x, if set.count(x-1) → continue (not a start).
    WHY: only the smallest of a run can be its start; every non-start would
    otherwise duplicate the stretch work of its run.
  Step 3: else stretch while set.count(x+len) len++; update best.
    WHY: total stretch across all starts is exactly n (each element stretched
    at most once), so overall amortized O(n).
 NextPermutation:
  Step 1: pivot scan from right for first a[i]<a[i+1].
    WHY: the rightmost ascent is the boundary between the "done" decreasing
    tail and the position we may legally bump.
  Step 2: swap with rightmost greater element.
    WHY: choosing the RIGHTMOST greater keeps the tail still decreasing, so a
    single reverse restores ascending order minimality.
  Step 3: reverse suffix.
    WHY: reversing a decreasing tail gives the smallest tail — exactly the
    next lexicographic arrangement.
  Step 4: if no pivot → whole array descending → reverse whole array.
    WHY: that is the largest permutation; wrapping to ascending is the
    required "next" answer.
 Rotate:
  Step 1: transpose: for i, for j>i swap(a[i][j], a[j][i]).
    WHY: transpose mirrors over main diagonal; it's the "half" that transports
    rows→columns.
  Step 2: reverse each row.
    WHY: reversing rows after transpose yields clockwise rotation; proven by
    tracking cell (i,j) → (j,i) → (j, n-1-i).

 VISUAL WALKTHROUGH:
  MAX ONES K — {1,1,0,1,1,0,1,1,1}, k=1 window trace:
   r=0 → [0..0] ones1 best1    r=1 → len2 best2   r=2 (0) zeros1 len3 best3
   r=3 len4  r=4 len5 best5
   r=5 (0) zeros2>1 → shrink l past idx2 zero → l=3, window[3..5] len3
   r=6 len4  r=7 len5  r=8 len6 → best6
   (final window 3..8 contains exactly one zero — index 5)
  LONGEST CONSECUTIVE hash on {100,4,200,1,3,2}:
   only tasks stretch from starts 1,100,200 → total stretches 4+1+1 → best 4.
  NEXT PERMUTATION traced above on {1,3,5,4,2}.
  ROTATE traced above on 3×3.
  LAST PERMUTATION {3,2,1} → pivot none → reverse → {1,2,3}.

 DRY RUN:
  maxConsecutiveOnesK {} → loop none → 0 (edge empty).
  maxConsecutiveOnesK {0} k=0 → r=0 zeros1>0 → l=1 → len 0 → best 0.
  longestConsecutive {} → 0; longestConsecutive {5} → 1 (edge single).
  longestConsecutive {1,2,2,3} → sequence 1,2,3 length 3 (dedupe via set).
  nextPermutation {1,2,3} → pivot 1 (idx1) → swap → {1,3,2} → reverse tail
    (len 0) → {1,3,2}.
  nextPermutation {3,2,1} → no pivot → reverse → {1,2,3}.
  rotateMatrix 1×1 {5} → transpose no-op → row reverse no-op → {5} ✓.

 TIME COMPLEXITY CALCULATION:
 - maxConsecutiveOnesK naive: for each of n starts, extend up to n more steps
   → worst n·n = O(n²). Sliding window: r advances n times total, l advances
   n times total → ≤ 2n pointer moves, O(1) work each → O(n).
 - longestConsecutive sort: sort is O(n log n), sweep is O(n) → O(n log n),
   O(1) aux (in-place sort). Hash-set: n inserts O(1) avg, then n start checks
   + total stretch length O(n) → O(n) average, O(n) space for the set.
   Worst-case hash O(n²) collisions, but average is linear.
 - nextPermutation: pivot scan ≤ n-1 steps, second scan ≤ n steps, reverse ≤
   n/2 swaps → O(n), O(1) extra.
 - rotateMatrix: transpose has n(n-1)/2 swaps, row reverse has n·n/2 swaps →
   total n² swaps = O(n²) for an n×n matrix → O(n²), O(1) extra (in-place).
 → Time Complexity = maxOnesK O(n) [brute O(n²)]; longestConsecutive O(n log n)
   sorted vs O(n) avg hash; nextPermutation O(n); rotate O(n²).

 SPACE COMPLEXITY CALCULATION:
 - maxConsecutiveOnesK: l,r,zeros,best scalars → O(1).
 - longestConsecutive sort: sort in-place → O(1) aux (lib sort may use O(log n)
   stack for introsort, commonly quoted O(1)). Hash-set: unordered_set holds n
   keys → O(n).
 - nextPermutation: pointer/scalar swaps, in-place → O(1).
 - rotateMatrix: transpose+reverse runs entirely in place → O(1) extra.
 → Space Complexity = maxOnesK O(1); longestConsecutive O(1) sorted vs O(n)
   hash; nextPermutation O(1); rotate O(1).

 APPROACH COMPARISON:
 ┌────────────────────┬──────────────────────────┬──────────────────────────┐
 │ MAX CONSEC ONES(K) │ Naive expansion          │ Sliding window           │
 ├────────────────────┼──────────────────────────┼──────────────────────────┤
 │ overshoot          │ restarts from each start │ one grow + one shrink    │
 │ time               │ O(n²)                    │ O(n)                     │
 │ space              │ O(1)                     │ O(1)                     │
 │ when               │ teaching only            │ interview answer         │
 └────────────────────┴──────────────────────────┴──────────────────────────┘
 ┌────────────────────┬──────────────────────────┬──────────────────────────┐
 │ LONGEST CONSEC     │ Sort + sweep             │ Hash-set starts          │
 ├────────────────────┼──────────────────────────┼──────────────────────────┤
 │ time               │ O(n log n)               │ O(n) avg                 │
 │ space              │ O(1)                     │ O(n)                     │
 │ ease of proof      │ very simple              │ needs amortization arg   │
 │ best when          │ need 0 extra memory      │ need linear time         │
 └────────────────────┴──────────────────────────┴──────────────────────────┘
 ┌────────────────────┬──────────────────────────┬──────────────────────────┐
 │ NEXT PERM          │ generate all (DFS)       │ pivot+swap+reverse       │
 ├────────────────────┼──────────────────────────┼──────────────────────────┤
 │ time               │ O(n!)                    │ O(n)                     │
 │ space              │ O(n) recursion           │ O(1)                     │
 │ production use     │ —                        │ std::next_permutation    │
 └────────────────────┴──────────────────────────┴──────────────────────────┘
 ┌────────────────────┬──────────────────────────┬──────────────────────────┐
 │ ROTATE 90          │ extra matrix             │ transpose + reverse      │
 ├────────────────────┼──────────────────────────┼──────────────────────────┤
 │ time               │ O(n²), copy              │ O(n²), in-place          │
 │ space              │ O(n²)                    │ O(1)                     │
 │ four-way cycle     │ (2nd in-place method)    │ harder to derive         │
 └────────────────────┴──────────────────────────┴──────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 1) MAX CONSECUTIVE ONES — flip at most k zeros, sliding window O(n)
int maxConsecutiveOnesK(const vector<int>& a, int k) {
    int l = 0, zeros = 0, best = 0;
    for (int r = 0; r < (int)a.size(); ++r) {
        if (a[r] == 0) ++zeros;
        while (zeros > k) {                    // invariant toot gaya → shrink
            if (a[l] == 0) --zeros;
            ++l;
        }
        best = max(best, r - l + 1);
    }
    return best;
}

// 2A) LONGEST CONSECUTIVE — sort approach O(n log n)
int longestConsecutiveSort(vector<int> a) {
    if (a.empty()) return 0;
    sort(a.begin(), a.end());
    int best = 1, run = 1;
    for (int i = 1; i < (int)a.size(); ++i) {
        if (a[i] == a[i-1]) continue;          // duplicate → skip
        if (a[i] == a[i-1] + 1) ++run;         // consecutive continue
        else                    run = 1;       // break → new run
        best = max(best, run);
    }
    return best;
}

// 2B) LONGEST CONSECUTIVE — hash set approach O(n) avg
int longestConsecutiveHash(const vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;          // mid/end → start nahi hai
        int len = 1;
        while (s.count(x + len)) ++len;        // stretch forward
        best = max(best, len);
    }
    return best;
}

// 3) NEXT PERMUTATION — pivot, swap, reverse suffix
void nextPermutation(vector<int>& a) {
    int n = (int)a.size();
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i+1]) --i;      // (a) pivot — rightmost ascent
    if (i < 0) { reverse(a.begin(), a.end()); return; }  // last permutation
    int j = n - 1;
    while (a[j] <= a[i]) --j;                  // (b) rightmost greater
    swap(a[i], a[j]);
    reverse(a.begin() + i + 1, a.end());       // (c) decreasing tail → ascending
}

// 4) ROTATE MATRIX — transpose + reverse rows
void rotateMatrix(vector<vector<int>>& m) {
    int n = (int)m.size();
    for (int i = 0; i < n; ++i)                // transpose main diagonal
        for (int j = i + 1; j < n; ++j)
            swap(m[i][j], m[j][i]);
    for (auto& row : m) reverse(row.begin(), row.end());  // reverse rows
}

void printMat(const vector<vector<int>>& m) {
    for (auto& row : m) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }
}

int main() {
    cout << "=== MAX CONSECUTIVE ONES (k flips) ===\n";
    vector<int> ones = {1,1,0,1,1,0,1,1,1};
    cout << "  {1,1,0,1,1,0,1,1,1} k=1 → " << maxConsecutiveOnesK(ones, 1) << "\n";

    cout << "\n=== LONGEST CONSECUTIVE SEQUENCE ===\n";
    vector<int> lc = {100,4,200,1,3,2};
    cout << "  {100,4,200,1,3,2} sort=" << longestConsecutiveSort(lc)
         << "  hash=" << longestConsecutiveHash(lc) << "   (both 4)\n";
    cout << "  {} sort=" << longestConsecutiveSort({})
         << " hash=" << longestConsecutiveHash({}) << "\n";

    cout << "\n=== NEXT PERMUTATION ===\n";
    vector<int> np = {1,3,5,4,2};
    cout << "  {1,3,5,4,2} → ";
    nextPermutation(np);
    for (int v : np) cout << v << " ";
    cout << " (expected {1,4,2,3,5})\n";
    vector<int> last = {3,2,1};
    cout << "  last perm {3,2,1} → ";
    nextPermutation(last);
    for (int v : last) cout << v << " ";
    cout << " (sorted)\n";

    cout << "\n=== ROTATE MATRIX 90° clockwise ===\n";
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(m);
    printMat(m);
    vector<vector<int>> one = {{5}};
    cout << "  1x1 → ";
    rotateMatrix(one);
    printMat(one);

    return 0;
}