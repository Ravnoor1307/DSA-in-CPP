/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_longest_subarray_zero_sum.cpp
│
│ REAL-WORLD SCENARIO:
│ Bank balance same value do baar aaya to beech transactions net zero. Longest zero-sum subarray ke liye same prefix sums ke beech longest gap chahiye.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. prefix sum calculate karo.
│ 2. Agar prefix pehli baar aaya, first index store karo.
│ 3. Agar prefix repeat hua, subarray firstIndex+1 to current has zero sum.
│ 4. Length = i - firstIndex[prefix].
│ 5. Maximum length update karo.
│ 6. prefix 0 ko virtual index -1 par store karo.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[15,-2,2,-8,1,7,10,23]
│ prefix sequence:
│ 15,13,15,7,8,15,25,48
│
│ prefix 15 first at i0, repeats at i2 length2 and i5 length5.
│ subarray i1..i5 = -2+2-8+1+7 = 0
│ longest length = 5
│
│ DRY RUN:
│ prefix map initially 0:-1.
│ i0 prefix15 store0.
│ i2 prefix15 repeat -> len=2.
│ i5 prefix15 repeat -> len=5 update best.
│ final best=5.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Loop n elements once.
│ - Each map operation average O(1).
│ - Total average n operations.
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores up to n+1 prefix sums.
│ -> Space Complexity = O(n).
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

int longestZeroSum(const vector<int>& arr) {
    unordered_map<int,int> first;
    first[0] = -1;
    int prefix = 0, best = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        prefix += arr[i];
        if (first.count(prefix)) {
            int len = i - first[prefix];
            best = max(best, len);
            cout << "repeat prefix " << prefix << " at i=" << i << ", len=" << len << "\n";
        } else {
            first[prefix] = i;
        }
    }
    return best;
}

int main() {
    vector<int> arr = {15,-2,2,-8,1,7,10,23};
    cout << "Longest zero-sum length = " << longestZeroSum(arr) << "\n";
    return 0;
}

/*
OUTPUT:
repeat prefix 15 at i=2, len=2
repeat prefix 15 at i=5, len=5
Longest zero-sum length = 5
*/

