/*
═══════════════════════════════════════════════
 TASK SET — SLIDING WINDOW
═══════════════════════════════════════════════

🌍 REAL-WORLD SCENARIO:
 A hospital computes the 3-day rolling average of a patient's sugar readings
 each morning without re-adding old days; a trader tracks the 30-day average
 of a stock the same way. Whenever you must process every length-k block, or
 find the longest block satisfying a condition, a sliding window reuses work
 instead of scanning from scratch.

🧠 HOW TO SOLVE:
 Fixed windows: compute the first window, then slide with
 sum = sum - arr[left going out] + arr[right coming in]. For "max/first
 negative of each window" keep a monotonic deque of indices. Variable
 windows: grow `right`, shrink `left` while the condition breaks, and track
 the best length. Every element is touched O(1) times amortised.

 5 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE

  ── TASK 1 (EASY) — fixed window max sum ─────────────────────────────
  (a) Given arr and k, return the maximum sum of any contiguous subarray
      of size k.
  💡 HINT: first compute the sum of the first k elements; then in every
           slide do sum = sum - arr[i-k] + arr[i]; update best.
  ✏️ STARTER CODE:
      long long maxSumK(vector<int>& a, int k) {
          // if (n < k) return 0;  // guard edge case
          // sum = a[0..k-1]; best = sum;
          // for i = k..n-1: sum += a[i] - a[i-k]; best = max(best, sum);
      }

  ── TASK 2 (EASY) — first negative in every window ──────────────────
  (b) For every window of size k, print the first negative number present
      (0 if none).
  💡 HINT: keep a deque of only the negative indices; any index that has
           left the window (front <= i-k) must be pop_front'd; the front
           is the answer.
  ✏️ STARTER CODE:
      vector<int> firstNegativeInEach(vector<int>& a, int k) {
          // deque<int> dq;   // negative indeces
          // har i: if a[i]<0 push; expire front; when i>=k-1 → answer
      }

  ── TASK 3 (MEDIUM) — longest subarray sum ≤ k ───────────────────────
  (c) Length of the longest subarray whose total sum ≤ k (all values
      non-negative).
  💡 HINT: variable window: grow right, while sum>k shrink left
           (sum -= a[l++]); track the max length at every step.
  ✏️ STARTER CODE:
      int longestSumLeqK(vector<int>& a, int k) {
          // l=0, sum=0, best=0;
          // for r: sum+=a[r]; while(sum>k) sum-=a[l++];
          //         best = max(best, r-l+1);
      }

  ── TASK 4 (MEDIUM) — max of each window (deque) ─────────────────────
  (d) Return a vector with the maximum of every window of size k.
  💡 HINT: monotonic (decreasing) deque of indices; while a[dq.back()] ≤
           a[i] pop_back; expiring front when dq.front() ≤ i-k; answer
           = a[dq.front()].
  ✏️ STARTER CODE:
      vector<int> maxInEach(vector<int>& a, int k) {
          // deque<int> dq; int n = a.size();
          // for i: pop_back smaller; push i; pop_front expired; record when i>=k-1
      }

  ── TASK 5 (HARD) — minimum window length with sum ≥ target ──────────
  (e) Length of the SHORTEST window whose sum ≥ target (non-negative
      values). Return 0 if impossible.
  💡 HINT: minimize best with a variable window; while sum ≥ target,
           answer = min(answer, r-l+1) and sum -= a[l++] (keep checking
           for an even smaller best).
  ✏️ STARTER CODE:
      int minWindowLen(vector<int>& a, int target) {
          // l=0,sum=0,best=INF; for r: sum+=a[r];
          // while(sum>=target){ best=min(best,r-l+1); sum-=a[l++]; }
          // return best==INF ? 0 : best;
      }

  ── TASK 6 (HARD) — subarrays with ≤ 2 distinct elements ─────────────
  (f) Count subarrays that contain at most 2 distinct values.
  💡 HINT: freq map + variable window; for every valid (l..r) the subarrays
           ending at that r = r-l+1; count them all while the distinct
           count stays within 2.
  ───────────────────────────────────────────────
  ✏️ STARTER CODE:
      long long countAtMostTwo(vector<int>& a) {
          // unordered_map<int,int> freq; int l=0; long long ans=0;
          // for r: freq[a[r]]++;
          // while (freq.size()>2){ if(--freq[a[l]]==0) freq.erase(a[l]); ++l; }
          // ans += (r-l+1);
          // return ans;
      }

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <climits>
using namespace std;

// ---- Task 1: fixed window max sum — O(n) ----
long long maxSumK(vector<int>& a, int k) {
    int n = (int)a.size();
    if (n < k || k <= 0) return 0;              // edge guard: k>n ho to 0
    long long sum = 0, best;
    for (int i = 0; i < k; ++i) sum += a[i];     // pehla window
    best = sum;
    for (int i = k; i < n; ++i) {
        sum += a[i] - a[i-k];                    // incoming jodo, outgoing ghatao
        if (sum > best) best = sum;
    }
    return best;
}

// ---- Task 2: first negative in every window — O(n) ----
vector<int> firstNegativeInEach(vector<int>& a, int k) {
    int n = (int)a.size();
    vector<int> res;
    if (n < k || k <= 0) return res;
    deque<int> dq;                              // sirf negative indeces
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) dq.push_back(i);
        if (i >= k && !dq.empty() && dq.front() <= i - k)
            dq.pop_front();                      // expire hone wala hatao
        if (i >= k - 1)
            res.push_back(dq.empty() ? 0 : a[dq.front()]);
    }
    return res;
}

// ---- Task 3: longest subarray with sum ≤ k — O(n) ----
int longestSumLeqK(vector<int>& a, int k) {
    int n = (int)a.size(), l = 0, best = 0;
    long long sum = 0;
    for (int r = 0; r < n; ++r) {
        sum += a[r];                             // window grow
        while (sum > k) sum -= a[l++];           // too bada → left shrink
        if (r - l + 1 > best) best = r - l + 1;
    }
    return best;
}

// ---- Task 4: max of each window via monotonic deque — O(n) ----
vector<int> maxInEach(vector<int>& a, int k) {
    int n = (int)a.size();
    vector<int> res;
    if (n < k || k <= 0) return res;
    deque<int> dq;                              // decreasing order wale indeces
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();                       // naya bada hai to purane chhote hatao
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front(); // index window ke bahar
        if (i >= k - 1) res.push_back(a[dq.front()]); // front = max
    }
    return res;
}

// ---- Task 5: minimum window length with sum ≥ target — O(n) ----
int minWindowLen(vector<int>& a, int target) {
    int n = (int)a.size(), l = 0;
    long long sum = 0;
    int best = INT_MAX;
    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (sum >= target) {                  // target hit → chhota window dekh lo
            if (r - l + 1 < best) best = r - l + 1;
            sum -= a[l++];                       // left se hata ke aur try karo
        }
    }
    return best == INT_MAX ? 0 : best;           // 0 = impossible
}

// ---- Task 6: count subarrays with ≤ 2 distinct values — O(n) ----
long long countAtMostTwo(vector<int>& a) {
    unordered_map<int, int> freq;                // value → count
    int l = 0;
    long long ans = 0;
    for (int r = 0; r < (int)a.size(); ++r) {
        ++freq[a[r]];
        while ((int)freq.size() > 2) {           // 2 se zyada distinct nahi chahiye
            if (--freq[a[l]] == 0) freq.erase(a[l]);
            ++l;
        }
        ans += (r - l + 1);                      // r par end har valid subarray
    }
    return ans;
}

int main() {
    cout << "===== SLIDING WINDOW TASKS =====\n";

    // Task 1: expected window (5,1,3) → 9
    vector<int> a1 = {2, 1, 5, 1, 3, 2};
    cout << "T1 maxSumK(k=3) = " << maxSumK(a1, 3) << "   (9)\n";

    // Task 2: expected -1 -1 -7 -15 -15 0
    vector<int> a2 = {12, -1, -7, 8, -15, 30, 16, 28};
    cout << "T2 firstNegative: ";
    for (int x : firstNegativeInEach(a2, 3)) cout << x << " ";
    cout << "\n";

    // Task 3: expected 3 ({1,1,1})
    vector<int> a3 = {1, 2, 3, 4, 1, 1, 1};
    cout << "T3 longestSumLeqK(k=5) = " << longestSumLeqK(a3, 5) << "   (3)\n";

    // Task 4: expected 3 3 5 5 6 7
    vector<int> a4 = {1, 3, -1, -3, 5, 3, 6, 7};
    cout << "T4 maxInEach(k=3): ";
    for (int x : maxInEach(a4, 3)) cout << x << " ";
    cout << "\n";

    // Task 5: {2,3,1,2,4,3} target 7 → window (4,3) length 2
    vector<int> a5 = {2, 3, 1, 2, 4, 3};
    cout << "T5 minWindowLen(target=7) = " << minWindowLen(a5, 7) << "   (2)\n";

    // Task 6: {1,2,1,2,3} → subarrays with <=2 distinct
    vector<int> a6 = {1, 2, 1, 2, 3};
    cout << "T6 countAtMostTwo = " << countAtMostTwo(a6) << "\n";

    // edge cases
    vector<int> empty;
    vector<int> neg = {-1, -2, -3, -4};
    cout << "\nedge cases:\n";
    cout << "T1 k>n   = " << maxSumK(a1, 99) << "   (0 guard)\n";
    cout << "T1 k=1   = " << maxSumK(neg, 1) << "   (-1)\n";
    cout << "T3 empty = " << longestSumLeqK(empty, 5) << "   (0)\n";
    cout << "T5 impossible = " << minWindowLen(empty, 5) << "   (0)\n";
    return 0;
}