/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_largest_subarray_0_1.cpp
│
│ REAL-WORLD SCENARIO:
│ Attendance chart me 0 absent and 1 present hai. Equal 0 and 1 count wala longest segment chahiye. Trick: 0 ko -1 treat karo, problem zero-sum ban gayi.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. 0 ko -1 and 1 ko +1 maan lo.
│ 2. Equal 0 and 1 means transformed sum 0.
│ 3. Ab longest zero-sum subarray prefix-hash se solve karo.
│ 4. Same prefix sum repeat -> sum between them 0.
│ 5. This is classic transformation trick.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[0,1,0,1,1,1,0]
│ transform: [-1,+1,-1,+1,+1,+1,-1]
│
│ prefix:
│ -1,0,-1,0,1,2,1
│ prefix 0 at virtual -1 and i3 -> len 4
│ prefix 1 at i4 and i6 -> len 2
│ longest equal 0/1 length = 4 for [0,1,0,1]
│
│ DRY RUN:
│ start first[0]=-1.
│ i0 val0 add -1, store -1 at0.
│ i1 val1 add +1 prefix0 repeat length2.
│ i3 prefix0 repeat length4 best.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Loop scans n elements once.
│ - Each map lookup/insert average O(1).
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores prefix sums up to n distinct values.
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

int largestEqualZeroOne(const vector<int>& arr) {
    unordered_map<int,int> first;
    first[0] = -1;
    int prefix = 0, best = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        prefix += (arr[i] == 0 ? -1 : 1); // 0 ko -1 karo
        if (first.count(prefix)) best = max(best, i - first[prefix]);
        else first[prefix] = i;
    }
    return best;
}

int main() {
    vector<int> arr = {0,1,0,1,1,1,0};
    cout << "Largest equal 0/1 subarray length = " << largestEqualZeroOne(arr) << "\n";
    return 0;
}

/*
OUTPUT:
Largest equal 0/1 subarray length = 4
*/

