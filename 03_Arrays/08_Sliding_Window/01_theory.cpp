/*
═══════════════════════════════════════════════
 SLIDING WINDOW
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Your doctor checks blood sugar for diabetes using a 3-day rolling average —
 each new day drops the oldest reading and adds today's, instead of re-reading
 every past value. Stock traders watch a moving average of the last N days:
 the window slides forward one day at a time. That "drop one old item, add
 one new item" motion is the sliding window: whatever leaves on the left is
 cancelled, whatever enters on the right is added, and the middle stays put.

 📖 THEORY: (pure English)
 - Definition: a contiguous subarray window of fixed size k (or a variable
   length that grows/shrinks) that moves one step at a time across the array.
 - FIXED window (size k): maintain the first window, then for each slide:
       newSum = oldSum - arr[outgoing] + arr[incoming]
   Each new window reuses the previous answer instead of re-summing k items.
 - ASCII diagram — window of size 3 sliding right:
   arr = { 2, 1, 5, 1, 3, 2 }
   window1: [ 2  1  5 ] → sum 8
                 └───────┘ out = arr[0]=2     in = arr[3]=1
   window2: [ 1  5  1 ] → 8 - 2 + 1 = 7
                 └───────┘ out = arr[1]=1     in = arr[4]=3
   window3: [ 5  1  3 ] → 7 - 1 + 3 = 9   ← maximum
                 └───────┘ out = arr[2]=5     in = arr[5]=2
   window4: [ 1  3  2 ] → 9 - 5 + 2 = 6
        O---O---O           each arrow = one subtraction + one addition
        ─────► sliding direction
 - VARIABLE window: grow `right`, and while the invariant breaks (sum > k,
   more than one zero, too many distinct values), shrink `left`. Longest
   valid window is tracked during the slide.
 - "First negative / max of each window" needs a DEQUE storing indices in
   decreasing (for max) order; each element pushes and pops at most once.
 - When to use: any "every window of size k" or "longest/shortest window
   satisfying a sum/count condition" problem over a static array.

 🧠 LOGIC — STEP BY STEP: (pure English with WHY)
 Step 1 (fixed): Compute the sum of the first k elements.
         WHY: that is the initial window; there is nothing to reuse yet.
 Step 2 (fixed): Slide from k to n-1: newSum = oldSum - arr[i-k] + arr[i].
         WHY: arr[i-k] is exactly the element leaving the window, arr[i] is
              the element entering; everything between stays, so only two
              adjustments are needed — O(1) per slide.
 Step 3 (deque): before pushing index i, pop back while the back element is
         ≤ the new one (for max).  WHY: those popped indices can never be
         the answer while i is present, so the deque stays decreasing and
         the front is always the current window's answer.
 Step 4 (variable): grow right by one, then while the condition breaks
         subtract arr[left] and move left forward.
         WHY: shrinking left restores the invariant; every element is
              visited at most twice in total (right once, left once), so
              the total cost stays linear.

 VISUAL WALKTHROUGH: (ASCII state diagrams — window moving)
   fixed size k = 3 on {2, 1, 5, 1, 3, 2}
   [ 2  1  5 ] sum = 8      slide: -2
      [ 1  5  1 ] sum = 7   slide: -1, +3
         [ 5  1  3 ] sum = 9 → max   slide: -5, +2
            [ 1  3  2 ] sum = 6
   best window = (5,1,3), maxSum = 9.

   deque for window max on {1,3,-1,-3} k=3 (indices kept in decreasing order):
   i=0: dq=[0]                → max = 1
   i=1: 3 ≥ 1 so pop 0 → [1]  → max = 3
   i=2: [1,2] (3,-1)          → max = 3 (front index 1)
   i=3: -3 ≥ -1? no, push 3; index 1 is now outside window (1 ≤ 3-3=0? no)
        [2,3] (-1,-3)         → max = -1 (front index 2)

 DRY RUN: (line-by-line trace on small concrete arrays)
  maxSumK sliding {2,1,5,1,3,2}, k=3:
   sum=2+1+5=8 → best=8
   i=3: sum=8-2+1=7   best=8
   i=4: sum=7-1+3=9   best=9
   i=5: sum=9-5+2=6   best=9
   → 9 (window 5,1,3) ✓ matches brute (8,7,9,6)

  firstNegative {12,-1,-7,8,-15,30,16,28} k=3:
   w1 (12,-1,-7) → -1      w2 (-1,-7,8)  → -1
   w3 (-7,8,-15) → -7      w4 (8,-15,30) → -15
   w5 (-15,30,16) → -15    w6 (30,16,28) → none
   output: -1 -1 -7 -15 -15 0

  longestSubarraySumLeqK {1,2,3,4,1,1,1} k=5:
   [1]=1 → [1,2]=3 → [1,2,3]=6>5 shrink → [2,3]=5 (len2)
   → [2,3,4]=9>5 shrink → [3,4]=7>5 → [4]=4 (len1)
   → [4,1]=5 (len2) → [1,1]=2 → [1,1,1]=3 (len3) → answer 3.

 TIME COMPLEXITY CALCULATION:
 - Fixed-window max sum brute: (n-k+1) windows × summing k items each
   ≈ (n-k+1)·k → O(n·k). Sliding: first window O(k) + (n-k) slides, each
   is one add + one subtract → total O(k) + O(n-k) = O(n).
 - Deque variant: every element is pushed once and popped at most once
   across the whole run → O(n) total with O(1) work per element.
 - Variable window: right pointer visits each index once and left pointer
   visits each index at most once → at most 2n moves → O(n).
 → Time Complexity = O(n·k) brute vs O(n) sliding for fixed windows;
                      first-negative/deque/variable windows = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Fixed sum: one `sum` and one `best` variable → O(1) auxiliary.
 - Deque approach: deque holds at most k indices at any moment → O(k).
 - Variable window: two pointers + a running sum/count → O(1).
 → Space Complexity = O(1) plain fixed/variable; O(k) for the deque.

 APPROACH COMPARISON: (real table — brute vs sliding)
 ┌─────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Aspect              │ Brute                        │ Sliding Window               │
 ├─────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Fixed window sum    │ Re-sum all k items each move │ oldSum - out + in (2 ops)    │
 │ Total cost (size k) │ (n-k+1)·k → O(n·k)           │ k + (n-k) → O(n)             │
 │ Window max          │ Scan k items per window      │ Deque front gives O(1)       │
 │ Longest valid window│ Re-scan from each start      │ Two pointers, ≤ 2n moves    │
 │ Extra memory        │ O(1)                         │ O(1) or deque O(k)           │
 └─────────────────────┴──────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// fixed window: max sum of any size-k subarray — O(n)
long long maxSumKSliding(const vector<int>& a, int k) {
    int n = (int)a.size();
    if (n < k || k <= 0) return 0;              // edge: k>n / k<=0 → guard
    long long sum = 0, best;
    for (int i = 0; i < k; ++i) sum += a[i];     // pehla window ka sum
    best = sum;
    for (int i = k; i < n; ++i) {
        sum = sum - a[i-k] + a[i];               // outgoing hatao, incoming jodo
        if (sum > best) best = sum;              // naya best track karo
    }
    return best;
}

// brute: har window ka sum naya banake compare — O(n*k)
long long maxSumKBrute(const vector<int>& a, int k) {
    int n = (int)a.size();
    if (n < k || k <= 0) return 0;             // guard: window banti hi nahi
    long long best;
    bool first = true;                          // first window hi pehla best
    for (int i = 0; i + k <= n; ++i) {
        long long s = 0;
        for (int j = i; j < i + k; ++j) s += a[j];
        if (first || s > best) { best = s; first = false; }
    }
    return best;                                // all-negative bhi sahi
}

// first negative in every window of size k — deque, O(n)
vector<int> firstNegative(const vector<int>& a, int k) {
    int n = (int)a.size();
    vector<int> res;
    if (k <= 0 || n < k) return res;             // guard: k>n → koi window nahi
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) dq.push_back(i);           // negative index line me daalo
        if (i >= k && !dq.empty() && dq.front() <= i - k)
            dq.pop_front();                      // window se bahar nikal gaya
        if (i >= k - 1)
            res.push_back(dq.empty() ? 0 : a[dq.front()]); // 0 = koi neg nahi
    }
    return res;
}

// max of every window of size k — deque, O(n)
vector<int> maxOfWindows(const vector<int>& a, int k) {
    int n = (int)a.size();
    vector<int> res;
    if (k <= 0 || n < k) return res;
    deque<int> dq;                              // indices, decreasing value order
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();                       // chhote back ko hamesha ke liye hatao
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front(); // stale index bahar phenko
        if (i >= k - 1)
            res.push_back(a[dq.front()]);        // front = is window ka max
    }
    return res;
}

// variable window: longest subarray with sum <= k — O(n)
int longestSumLeqK(const vector<int>& a, long long k) {
    int n = (int)a.size(), l = 0, best = 0;
    long long sum = 0;
    for (int r = 0; r < n; ++r) {
        sum += a[r];                             // window ko right se badhao
        while (sum > k) sum -= a[l++];           // invariant toota → left shrink
        if (r - l + 1 > best) best = r - l + 1;  // har step me best update
    }
    return best;
}

// variable window: longest run of 1s with at most one 0 flip — O(n)
int longestOnesFlipOne(const vector<int>& a) {
    int n = (int)a.size(), l = 0, zeros = 0, best = 0;
    for (int r = 0; r < n; ++r) {
        if (a[r] == 0) ++zeros;
        while (zeros > 1) {                      // ek se zyada 0 allowed nahi
            if (a[l] == 0) --zeros;
            ++l;
        }
        if (r - l + 1 > best) best = r - l + 1;
    }
    return best;
}

int main() {
    cout << "===== SLIDING WINDOW DEMO =====\n";

    // 1) max sum of size-3 window — sliding vs brute
    vector<int> a1 = {2, 1, 5, 1, 3, 2};
    cout << "maxSumK sliding = " << maxSumKSliding(a1, 3)
         << "   brute = " << maxSumKBrute(a1, 3)
         << "   (window 5,1,3 → 9)\n";

    // 2) first negative in each window of size 3
    vector<int> a2 = {12, -1, -7, 8, -15, 30, 16, 28};
    cout << "firstNegative : ";
    for (int x : firstNegative(a2, 3)) cout << x << " ";
    cout << "  (0 = none)\n";

    // 3) max of each window of size 3 (deque)
    vector<int> a3 = {1, 3, -1, -3, 5, 3, 6, 7};
    cout << "maxOfWindows  : ";
    for (int x : maxOfWindows(a3, 3)) cout << x << " ";
    cout << "\n";

    // 4) longest subarray sum <= 5
    vector<int> a4 = {1, 2, 3, 4, 1, 1, 1};
    cout << "longestSumLeqK(5) = " << longestSumLeqK(a4, 5) << "   (expected 3)\n";

    // 5) longest consecutive 1s with at most one 0 flip
    vector<int> a5 = {1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1};
    cout << "longestOnesFlipOne = " << longestOnesFlipOne(a5)
         << "   (expected 6: window {1,1,0,1,1,1})\n";

    // 6) edge cases
    cout << "\nedge cases:\n";
    vector<int> empty;
    cout << "k>n guard      = " << maxSumKSliding(a1, 99) << "  (0)\n";
    cout << "k=1 on {7,8}   = " << maxSumKSliding({7, 8}, 1) << "  (8)\n";
    vector<int> neg = {-1, -2, -3, -4, -5};
    cout << "all-negative k=3 sliding = " << maxSumKSliding(neg, 3)
         << "  brute = " << maxSumKBrute(neg, 3) << "  (both -6)\n";
    cout << "empty firstNegative size = " << (int)firstNegative(empty, 3).size()
         << "\n";
    cout << "empty maxOfWindows size  = " << (int)maxOfWindows(empty, 3).size()
         << "\n";

    return 0;
}