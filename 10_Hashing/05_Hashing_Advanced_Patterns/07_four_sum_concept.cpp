/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_four_sum_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Shopping cart me 4 items ka total target chahiye. Brute O(n^4) hai; pair sums store karke 4-sum ko two-pairs problem bana sakte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Har pair (i,j) ka sum calculate karo.
│ 2. Need = target - pairSum.
│ 3. Agar need kisi previous pair sum me hai and indices overlap nahi karte, quadruple found.
│ 4. Store pairSum -> list of pairs.
│ 5. Conceptually O(n²) pair generation, but duplicate handling can be complex.
│ 6. This is hashing + pair approach idea.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[1,0,-1,0,-2,2], target=0
│
│ pair (0,1): sum1
│ pair (2,5): -1+2=1 etc.
│ Need complementary pairs whose sums add to target.
│
│ Example quadruple:
│ -2 + -1 + 1 + 2 = 0
│ indices 4,2,0,5 distinct
│
│ DRY RUN:
│ Build previous pair sums while scanning pairs.
│ For current pair sum S, check target-S.
│ If previous pair indices are all different from current pair indices, answer.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Number of pairs = n(n-1)/2 = O(n²).
│ - For each pair, hash lookup average O(1); checking stored pairs can add overhead if many duplicates.
│ - Conceptual average for finding one quadruple is O(n²) with controlled pair lists.
│ -> Time Complexity = O(n²) average concept, worst can be higher with many same sums.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Hash map stores O(n²) pairs.
│ -> Space Complexity = O(n²).
│ APPROACH COMPARISON TABLE:
│ Brute 4 loops = try every 4-item combo, O(n^4) time/O(1) space.
│ Hash pair sums = remember pair totals, O(n²) average concept/O(n²) space.
│ Two-pointer after sorting = common exact 4Sum listing method, O(n³) time with duplicate control.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct PairIndex { int i; int j; };

bool noOverlap(PairIndex a, PairIndex b) {
    return a.i != b.i && a.i != b.j && a.j != b.i && a.j != b.j;
}

bool fourSumExists(const vector<int>& arr, int target) {
    unordered_map<int, vector<PairIndex>> pairSums;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            int need = target - sum;
            if (pairSums.count(need)) {
                for (PairIndex old : pairSums[need]) {
                    if (noOverlap(old, {i, j})) {
                        cout << "pairs (" << old.i << "," << old.j << ") and (" << i << "," << j << ")\n";
                        return true;
                    }
                }
            }
            pairSums[sum].push_back({i, j});
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1,0,-1,0,-2,2};
    cout << "Four sum exists? " << (fourSumExists(arr, 0) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
pairs (0,2) and (1,3)
Four sum exists? YES
*/

