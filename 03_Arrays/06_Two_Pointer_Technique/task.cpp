/*
═══════════════════════════════════════════════
 TASK SET — TWO POINTER TECHNIQUE
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Two estimators measure a building from both ends and
meet in the middle; finding pairs, partitions and duplicate-free lists all
speed up when two pointers converge over sorted or partitionable data.

🧠 HOW TO SOLVE: Sort when the problem allows; put lo at the start and hi at
the end and shrink one step each iteration. For partitions (move zeros) use a
fast scan pointer plus a write head. Target O(n) time with O(1) extra space.

7 tasks EASY → HARD:

TASK 1 — TWO SUM EXACT PAIR (SORTED, TWO POINTER)
💡 HINT: compare lo+hi with target; equal→record both inward, small→++lo, big→--hi.
✏️ STARTER: vector<pair<int,int>> twoSum(const vector<int>& a, int t) { // while(lo<hi) }

TASK 2 — BRUTE PAIR SUM (verify Task 1)
💡 HINT: nested i<j loops, compare each sum with target.
✏️ STARTER: vector<pair<int,int>> pairSumBrute(const vector<int>& a, int t) { // double loop }

TASK 3 — THREE SUM (SORTED)
💡 HINT: fix i, then run two-pointer on i+1..n-1 chasing required = t - a[i].
✏️ STARTER: vector<vector<int>> threeSum(vector<int>& a, int t) { // fix + two-pointer }

TASK 4 — MOVE ZEROS TO END
💡 HINT: write head w filled with non-zeros while scanning; zeros go to the tail.
✏️ STARTER: void moveZerosToEnd(vector<int>& a) { // partition w }

TASK 5 — REMOVE DUPLICATES (SORTED)
💡 HINT: keep first occurrence; compare a[i] with a[w-1].
✏️ STARTER: int removeDups(vector<int>& a) { // w write head }

TASK 6 — CONTAINER WITH MOST WATER
💡 HINT: area = min(h[lo],h[hi]) * (hi-lo); move the SHORTER line inward.
✏️ STARTER: int maxWater(const vector<int>& h) { // shrink shorter side }

TASK 7 — COUNT PAIRS DIVISIBLE BY k
💡 HINT: remainder frequency; r with k-r; r==0 and r==k-r pairs use nC2.
✏️ STARTER: long long countPairs(const vector<int>& a, int k) { // freq[rem] }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void printPairs(const vector<pair<int,int>>& p) {
    if (p.empty()) { cout << "(none)\n"; return; }
    for (auto& pr : p) cout << "(" << pr.first << "," << pr.second << ") ";
    cout << "\n";
}

void printVec(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

// TASK 1: sorted array par two-pointer two-sum — O(n) time, O(1) space
vector<pair<int,int>> twoSum(const vector<int>& a, int t) {
    vector<pair<int,int>> res;
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int sum = a[lo] + a[hi];
        if (sum == t) { res.push_back({a[lo], a[hi]}); ++lo; --hi; }
        else if (sum < t) ++lo;   // sum chhota -> lo aage badao
        else --hi;                // sum bada -> hi peeche lao
    }
    return res;
}

// TASK 2: brute verification — O(n²): har (i,j) pair try
vector<pair<int,int>> pairSumBrute(const vector<int>& a, int t) {
    vector<pair<int,int>> res;
    int n = (int)a.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] + a[j] == t)
                res.push_back({a[i], a[j]});
    return res;
}

// TASK 3: three-sum — sort karo, i fix karo, baaki par two-pointer
// WHY O(n²): har i par (n-i) tak ka two-pointer = ~n²/2 steps total.
vector<vector<int>> threeSum(vector<int>& a, int t) {
    vector<vector<int>> res;
    int n = (int)a.size();
    sort(a.begin(), a.end());                     // two-pointer ke liye sorted
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && a[i] == a[i - 1]) continue;  // duplicate i skip
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int s = a[i] + a[lo] + a[hi];
            if (s == t) {
                res.push_back({a[i], a[lo], a[hi]});
                ++lo; --hi;
                while (lo < hi && a[lo] == a[lo - 1]) ++lo;  // dup skip
                while (lo < hi && a[hi] == a[hi + 1]) --hi;
            } else if (s < t) ++lo;
            else --hi;
        }
    }
    return res;
}

// TASK 4: move zeros to end — partition, O(n) time, O(1) space
void moveZerosToEnd(vector<int>& a) {
    int w = 0;                                    // write head
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] != 0) a[w++] = a[i];             // non-zero ko aage bharo
    for (int i = w; i < (int)a.size(); ++i)
        a[i] = 0;                                 // baaki tail par zero
}

// TASK 5: remove duplicates from sorted — returns new length
// WHY O(n): ek hi scan, har element ek baar compare hota hai.
int removeDups(vector<int>& a) {
    if (a.empty()) return 0;
    int w = 1;                                    // index 0 to hai hi
    for (int i = 1; i < (int)a.size(); ++i)
        if (a[i] != a[w - 1])                     // naya unique value
            a[w++] = a[i];
    return w;
}

// TASK 6: container with most water — chhoti wall ko andar move karo
// WHY O(n): har step ek wall discard hoti hai, total n steps.
int maxWater(const vector<int>& h) {
    int lo = 0, hi = (int)h.size() - 1, best = 0;
    while (lo < hi) {
        int area = min(h[lo], h[hi]) * (hi - lo);
        best = max(best, area);
        if (h[lo] < h[hi]) ++lo;                  // chhoti wall hatao
        else --hi;
    }
    return best;
}

// TASK 7: pairs with sum divisible by k — remainder frequency
// WHY O(n+k): ek remainder count pass + ek remainder combine pass.
long long countPairs(const vector<int>& a, int k) {
    vector<long long> freq(k, 0);
    for (int x : a) freq[((x % k) + k) % k]++;    // negative-safe remainder
    long long ans = freq[0] * (freq[0] - 1) / 2;  // r=0: dono 0 do pair
    for (int r = 1; r < k; ++r) {
        if (r * 2 == k)
            ans += freq[r] * (freq[r] - 1) / 2;   // r == k-r wale pairs
        else if (r < k - r)
            ans += freq[r] * freq[k - r];         // complementary remainder
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10};

    cout << "T1 twoSum t=12       : "; printPairs(twoSum(arr, 12));     // (2,10) (4,8)
    cout << "T2 brute  t=12       : "; printPairs(pairSumBrute(arr, 12));// (2,10) (4,8)

    vector<int> arr3 = {-1, 0, 1, 2, -1, -4};
    auto ts = threeSum(arr3, 0);
    cout << "T3 threeSum 0        : ";
    for (auto& tr : ts) cout << "[" << tr[0] << "," << tr[1] << "," << tr[2] << "] ";
    cout << "\n";                                      // [-1,-1,2] [-1,0,1]

    vector<int> z = {0, 1, 0, 3, 12};
    moveZerosToEnd(z);
    cout << "T4 moveZeros         : "; printVec(z);    // 1 3 12 0 0

    vector<int> d = {0, 0, 1, 1, 1, 2, 2, 3};
    int len = removeDups(d);
    cout << "T5 removeDups len=" << len << " : ";
    for (int i = 0; i < len; ++i) cout << d[i] << " ";
    cout << "\n";                                      // 0 1 2 3

    vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "T6 maxWater          : " << maxWater(h) << "\n";   // 49

    vector<int> pk = {1, 2, 3, 4, 5, 6};
    cout << "T7 pairs div by 3    : " << countPairs(pk, 3) << "\n"; // 5

    return 0;
}