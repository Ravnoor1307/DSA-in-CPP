/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_missing_number_cyclic.cpp
│
│ REAL-WORLD SCENARIO:
│ Attendance seats 0 to n roll numbers ke liye hain, but ek roll missing hai. Number x ko index x par bithao; jahan mismatch mile wahi missing.
│
│ ASCII VISUAL / PATTERN STATE:
│ nums = [3,0,1], n=3 means numbers 0..3 and one missing.
│
│ correct seat for value x is index x, but value n has no index.
│
│ i=0, value3 ignore because 3==n
│ i=1, value0 belongs index0 -> swap -> [0,3,1]
│ i=1 value3 ignore
│ i=2 value1 belongs index1 -> swap -> [0,1,3]
│
│ Scan:
│ index0 has0 OK
│ index1 has1 OK
│ index2 has3 mismatch -> missing=2

│
│ STEP-BY-STEP DRY RUN:
│ While nums[i] < n and nums[i] != nums[nums[i]], swap.
│ Then scan for first index i where nums[i] != i.
│ If all correct, missing n.

│
│ COMPLEXITY CALCULATION:
│ Each swap places one valid number at correct index.
│ Swaps <= n.
│ Final scan n.
│ Time = O(n), Space = O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int missingNumber(vector<int> nums) {
    int n = nums.size();
    int i = 0;
    while (i < n) {
        int correct = nums[i];
        if (nums[i] < n && nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
    }
    for (int idx = 0; idx < n; idx++) if (nums[idx] != idx) return idx;
    return n;
}

int main() {
    vector<int> nums = {3,0,1};
    cout << "Missing = " << missingNumber(nums) << "\n";
    return 0;
}

/*
OUTPUT:
Missing = 2
*/

