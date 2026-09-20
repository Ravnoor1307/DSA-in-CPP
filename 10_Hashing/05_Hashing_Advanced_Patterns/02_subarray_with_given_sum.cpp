/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_subarray_with_given_sum.cpp
│
│ REAL-WORLD SCENARIO:
│ Transaction list me target balance change chahiye. Agar current prefix - target pehle dekha hai, to beech ka subarray target sum deta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. prefix sum maintain karo.
│ 2. Need = prefix - target.
│ 3. Agar need pehle prefix map me hai, subarray after that index to current index has target sum.
│ 4. prefix sum ka first/latest index map me store karo.
│ 5. Works with negative numbers too, unlike simple sliding window.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[10,2,-2,-20,10], target=-10
│ prefix:
│ i0 10, need20 absent, store10
│ i1 12, need22 absent, store12
│ i2 10, need20 absent
│ i3 -10, need0 present at virtual index -1
│ subarray [0..3] sum -10 found
│
│ Formula: prefix[j] - prefix[i-1] = target
│
│ DRY RUN:
│ prefix starts 0 at index -1.
│ at i3 prefix=-10.
│ need=prefix-target=-10-(-10)=0.
│ prefix 0 exists -> subarray 0..3.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Loop visits n elements once.
│ - Each map lookup/insert average O(1).
│ -> Average Time Complexity = O(n).
│ - Worst hash collisions can degrade, but expected average O(1).
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

pair<int,int> subarrayGivenSum(const vector<int>& arr, int target) {
    unordered_map<int,int> firstIndex;
    int prefix = 0;
    firstIndex[0] = -1;
    for (int i = 0; i < (int)arr.size(); i++) {
        prefix += arr[i];
        int need = prefix - target;
        cout << "i=" << i << ", prefix=" << prefix << ", need=" << need << "\n";
        if (firstIndex.count(need)) return {firstIndex[need] + 1, i};
        if (!firstIndex.count(prefix)) firstIndex[prefix] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {10,2,-2,-20,10};
    pair<int,int> ans = subarrayGivenSum(arr, -10);
    cout << "Subarray with sum -10 = [" << ans.first << "," << ans.second << "]\n";
    return 0;
}

/*
OUTPUT:
i=0, prefix=10, need=20
i=1, prefix=12, need=22
i=2, prefix=10, need=20
i=3, prefix=-10, need=0
Subarray with sum -10 = [0,3]
*/

