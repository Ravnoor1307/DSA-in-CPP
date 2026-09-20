/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_subarray_with_zero_sum.cpp
│
│ REAL-WORLD SCENARIO:
│ Bank transactions me agar same running balance dobara aa gaya, beech ke transactions ka net sum zero hai. Prefix sum + hash set se zero-sum subarray detect hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. prefix sum running total maintain karo.
│ 2. Agar prefix sum 0 ho gaya, start se current tak zero-sum subarray hai.
│ 3. Agar same prefix sum pehle dekha hai, beech ka sum zero hai.
│ 4. Prefix sums unordered_set me store karo.
│ 5. Same prefix repeat means currentPrefix - oldPrefix = 0.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[4,2,-3,1,6]
│ prefix sums:
│ i0: 4
│ i1: 6
│ i2: 3
│ i3: 4  <- 4 repeat
│
│ Repeat prefix 4 at i0 and i3:
│ sum arr[1..3] = 2 + (-3) + 1 = 0
│
│ Visual:
│ prefix before block = 4
│ prefix after block  = 4
│ difference = 0
│
│ DRY RUN:
│ seen initially {0}
│ prefix=4 insert
│ prefix=6 insert
│ prefix=3 insert
│ prefix=4 already seen -> zero-sum exists.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Loop visits n elements once.
│ - Each prefix update O(1).
│ - Each set count/insert average O(1).
│ - Total average = n * O(1).
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Set stores up to n+1 prefix sums.
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

bool hasZeroSumSubarray(const vector<int>& arr) {
    unordered_set<int> seen;
    int prefix = 0;
    seen.insert(0);
    for (int i = 0; i < (int)arr.size(); i++) {
        prefix += arr[i];
        cout << "i=" << i << ", value=" << arr[i] << ", prefix=" << prefix << "\n";
        if (seen.count(prefix)) return true;
        seen.insert(prefix);
    }
    return false;
}

int main() {
    vector<int> arr = {4,2,-3,1,6};
    cout << "Zero-sum subarray exists? " << (hasZeroSumSubarray(arr) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
i=0, value=4, prefix=4
i=1, value=2, prefix=6
i=2, value=-3, prefix=3
i=3, value=1, prefix=4
Zero-sum subarray exists? YES
*/

