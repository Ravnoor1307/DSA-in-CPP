/*
═══════════════════════════════════════════════
 TWO POINTER TECHNIQUE
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Two friends play a number-guessing game with a SORTED stack of index cards
 numbered 1 to 20. One friend holds the top card, the other holds the bottom
 card, and together they try to reach a combined sum of 12. If their sum is too
 small, the top person moves one card down; if too big, the bottom person moves
 one card up. Because the deck is sorted they never need to scan the whole deck
 — every step eliminates exactly one card. That is the two-pointer technique:
 two markers crawling toward each other from opposite ends, shrinking the
 problem by one position per step, so together they visit at most n positions.
 The same thinking packs all non-zero items to the front of a shelf without
 making extra copies elsewhere.

 📖 THEORY: (pure English)
 - Definition: two-pointer uses two indices that move toward each other (or at
   different speeds) over a sorted or partitionable array, replacing a full
   scan or nested loops with a single intertwined pass.
 - Pair sum (target t) on a sorted array: lo=0, hi=n-1. If sum equals t record
   and move both inward; if sum < t the sum is too small → ++lo (need a bigger
   number); if sum > t → --hi. Each step drops exactly one element.
 - Move zeros to end: a write-head w plus a scan-pointer i. For every non-zero
   a[i], place it at a[w] and w++. Finally fill the tail with zeros. This is a
   PARTITION — all non-zeros on the left, zeros on the right — and does NOT
   need sorted data.
 - Remove duplicates from a sorted array: write index w=1; scan from i=1; when
   a[i] != a[w-1] keep the new value by copying it to a[w++]. Returns the new
   length.
 - When the technique is valid: sorted arrays (sum/difference targets),
   partition problems (move zeros, odd/even, negative/positive) and
   converging-range problems (container with most water).
 - Each step the two pointers together cover at most n positions, turning
   O(n²) nested loops into a single O(n) pass.

   ASCII — pair sum narrowing:
     lo             target 12            hi
     |                                   |
     [ 1,  2,  4,  6,  8,  10 ]          sum 1+10=11 < 12 -> ++lo
         lo                              hi
     [ 1,  2,  4,  6,  8,  10 ]          sum 2+10=12 == 12 -> record (2,10)
             lo                  hi      then ++lo, --hi
     [ 1,  2,  4,  6,  8,  10 ]          sum 4+8 = 12 == 12 -> record (4,8)
                 lo/hi                   then ++lo, --hi; lo>=hi -> STOP

   ASCII — move zeros partition:
     i scans right, w is the write head
       i=0 skipped             [ 0,  1,  0,  3,  12 ]
       i=1 (1 != 0): a[w]=1,w=1 [ 1,  1,  0,  3,  12 ]
       i=2 skipped             [ 1,  1,  0,  3,  12 ]
       i=3 (3 != 0): a[w]=3,w=2 [ 1,  3,  0,  3,  12 ]
       i=4 (12!= 0): a[w]=12,w=3 [ 1, 3, 12,  3,  12 ]
     fill tail [w..end] with 0 : [ 1,  3,  12,  0,  0 ]  done ✅

 🧠 LOGIC — STEP BY STEP: (pure English with WHY)
 Pair sum two-pointer:
   Step 1: lo=0, hi=n-1. WHY: smallest and largest available numbers bound the
     range of possible sums.
   Step 2: compare a[lo]+a[hi] with target. WHY: the extreme pair carries
     maximum information — if it is too small, every lo-side pair is too small;
     if too big, every hi-side pair is too big.
   Step 3: equal → record and ++lo, --hi. WHY: both numbers are consumed, so
     the next inner pair must be examined.
   Step 4: too small → ++lo. WHY: keeping lo can never reach the target for
     any hi, so the lo pointer must grow.
   Step 5: too big → --hi. WHY: symmetric mirror of step 4; the hi pointer
     must shrink.
   Each iteration removes one pointer, so at most n iterations total.

 Move zeros:
   Step 1: w=0 (where the next non-zero is written). WHY: w is the partition
     boundary.
   Step 2: scan i; if a[i]!=0 copy to a[w], w++. WHY: non-zeros keep their
     relative order and land at the front.
   Step 3: fill a[w..n-1] with 0. WHY: the skipped zeros form the tail of the
     partition.

 Remove duplicates:
   Step 1: if n <= 1 return n. WHY: nothing can be duplicated.
   Step 2: w=1, scan i=1..n-1. WHY: only compare with the last written value
     a[w-1], which is guaranteed sorted.
   Step 3: a[i]!=a[w-1] → a[w++]=a[i]. WHY: first occurrence of a new value is
     unique and must be kept; repeats are skipped.

 VISUAL WALKTHROUGH: (two-pointer narrowing on pair sum)
 {1,2,4,6,8,10}, target 12
   lo=0 hi=5: 1+10 = 11  <  12  => ++lo
   lo=1 hi=5: 2+10 = 12  == 12  => record (2,10); ++lo --hi
   lo=2 hi=4: 4+8  = 12  == 12  => record (4,8);  ++lo --hi
   lo=3 hi=3: stop
   Pairs found: (2,10), (4,8)                               ✅

 Move zeros on {0,1,0,3,12}:
   step | i | w | array          | action
   1    | 0 | 0 | [0,1,0,3,12]   | a[0]=0 -> skip
   2    | 1 | 0 | [0,1,0,3,12]   | a[1]=1 -> a[0]=1, w=1
   3    | 2 | 1 | [1,1,0,3,12]   | a[2]=0 -> skip
   4    | 3 | 1 | [1,1,0,3,12]   | a[3]=3 -> a[1]=3, w=2
   5    | 4 | 2 | [1,3,0,3,12]   | a[4]=12 -> a[2]=12, w=3
   fill [3..4] with 0            [1,3,12,0,0]               ✅

 DRY RUN: (remove duplicates on a small sorted array)
 {0,0,1,1,1,2,2,3}, w=1
   i=1: a[1]=0 == a[0]=0 skip
   i=2: a[2]=1 != a[0]=0 -> a[1]=1, w=2
   i=3: a[3]=1 == a[1]=1 skip
   i=4: a[4]=1 == a[1]=1 skip
   i=5: a[5]=2 != a[1]=1 -> a[2]=2, w=3
   i=6: a[6]=2 == a[2]=2 skip
   i=7: a[7]=3 != a[2]=2 -> a[3]=3, w=4
   Result: length 4, first 4 elements [0,1,2,3], rest unused  ✅

 TIME COMPLEXITY CALCULATION:
 - Brute pair sum: nested loops try every i<j, that is n*(n-1)/2 comparisons,
   which is quadratic in n -> O(n²).
 - Two-pointer pair sum: every iteration moves lo right, or moves hi left, or
   both; across the whole run lo+hi move at most 2n steps -> O(n) with one pass.
 - Move zeros: scan writes n elements once + tail fill of at most n zeros
   -> O(n) total.
 - Remove duplicates: one scan of n elements, each compared once -> O(n).
 -> Time Complexity = O(n) for two-pointer vs O(n²) for brute-force.

 SPACE COMPLEXITY CALCULATION:
 - Brute pair sum: only loop counters and a result list; ignoring the answer
   storage the auxiliary space is O(1).
 - Two-pointer pair sum: two indices, no extra array -> O(1) auxiliary.
 - Move zeros: in-place partition using one write index -> O(1).
 - Remove duplicates: in-place compaction using one write index -> O(1).
 -> Space Complexity = O(1) auxiliary for all two-pointer versions (answer
    storage is not counted).

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Approach             │ Time                         │ Space (aux)                  │
 ├──────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Brute pair sum       │ i<j comparisons,        O(n²)│ result list only         O(1)│
 │ Two-pointer pair sum │ one pass, <= 2n moves   O(n) │ two indices only         O(1)│
 │ Move zeros extra arr │ 2 passes over n        O(n)  │ extra array              O(n)│
 │ Move zeros two-ptr   │ 1 scan + tail fill      O(n) │ one write index          O(1)│
 │ Remove duplicates    │ 1 scan over n           O(n) │ one write index          O(1)│
 └──────────────────────┴──────────────────────────────┴──────────────────────────────┘
*/

// ══════════════ DEMO CODE (C++17, compile & run) ══════════════
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void printVec(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void printPairs(const vector<pair<int,int>>& p) {
    if (p.empty()) { cout << "(none)\n"; return; }
    for (auto& pr : p) cout << "(" << pr.first << "," << pr.second << ") ";
    cout << "\n";
}

// brute pair sum — O(n²): har (i,j) pair check karo
vector<pair<int,int>> pairSumBrute(const vector<int>& a, int target) {
    vector<pair<int,int>> res;
    int n = (int)a.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] + a[j] == target)
                res.push_back({a[i], a[j]});
    return res;
}

// two-pointer pair sum — O(n): sorted array confidentially chahiye
vector<pair<int,int>> pairSumTwoPointer(const vector<int>& a, int target) {
    vector<pair<int,int>> res;
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int sum = a[lo] + a[hi];
        if (sum == target) {                 // exact match mila
            res.push_back({a[lo], a[hi]});
            ++lo; --hi;                      // dono ko andar bhejo
        } else if (sum < target) {
            ++lo;                            // sum chhota => bada number chahiye
        } else {
            --hi;                            // sum bada => chhota number chahiye
        }
    }
    return res;
}

// move zeros to end — in-place partition, O(n) time, O(1) space
void moveZeros(vector<int>& a) {
    int w = 0;                               // write head
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] != 0)                       // non-zero ko aage rakho
            a[w++] = a[i];
    for (int i = w; i < (int)a.size(); ++i)
        a[i] = 0;                            // tail mein zeros bharo
}

// remove duplicates from sorted — returns new length, O(n) time, O(1) space
int removeDuplicates(vector<int>& a) {
    if (a.empty()) return 0;
    int w = 1;                               // pehla element to hai hi
    for (int i = 1; i < (int)a.size(); ++i)
        if (a[i] != a[w - 1])                // naya unique value mila
            a[w++] = a[i];
    return w;
}

int main() {
    vector<int> a = {1, 2, 4, 6, 8, 10};

    cout << "brute pair sum target 12      : ";
    printPairs(pairSumBrute(a, 12));         // (2,10) (4,8)

    cout << "two-pointer pair sum target 12 : ";
    printPairs(pairSumTwoPointer(a, 12));    // (2,10) (4,8) — brute se verify

    vector<int> z = {0, 1, 0, 3, 12};
    moveZeros(z);
    cout << "move zeros                     : ";
    printVec(z);                             // 1 3 12 0 0

    vector<int> d = {0, 0, 1, 1, 1, 2, 2, 3};
    int len = removeDuplicates(d);
    cout << "remove duplicates len=" << len << " : ";
    for (int i = 0; i < len; ++i) cout << d[i] << " ";
    cout << "(rest garbage)\n";              // 0 1 2 3

    // edge cases
    vector<int> e;
    cout << "edge empty: pairs -> ";
    printPairs(pairSumTwoPointer(e, 5));     // (none)

    vector<int> s = {5};
    cout << "edge single: pairs -> ";
    printPairs(pairSumTwoPointer(s, 5));     // (none)

    vector<int> az = {0, 0, 0};
    moveZeros(az);
    cout << "edge all zeros     : ";
    printVec(az);                            // 0 0 0

    vector<int> allSame = {7, 7, 7};
    cout << "edge all same dups len="
         << removeDuplicates(allSame) << "\n"; // 1

    return 0;
}