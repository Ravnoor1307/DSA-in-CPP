/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_range_sum_query_immutable.cpp
│
│ REAL-WORLD SCENARIO:
│ Bank statement immutable hai, baar-baar range total queries aati hain. Precompute prefix once, then every query O(1).
│
│ VISUAL / PATTERN STATE:
│ nums = [-2,0,3,-5,2,-1]
│ prefix:
│ index:   0  1  2  3   4  5  6
│ prefix: [0,-2,-2,1,-4,-2,-3]
│
│ sumRange(0,2) = prefix[3]-prefix[0] = 1-0 = 1
│ sumRange(2,5) = prefix[6]-prefix[2] = -3 - (-2) = -1
│ sumRange(0,5) = prefix[6]-prefix[0] = -3

│
│ STEP-BY-STEP DRY RUN:
│ Constructor builds prefix in one pass.
│ Query reads prefix[right+1] and prefix[left].
│ No loop per query.

│
│ COMPLEXITY CALCULATION:
│ Constructor: n iterations -> O(n).
│ Each query: two reads + subtraction -> O(1).
│ q queries total = O(n + q).
│ Space: prefix n+1 integers -> O(n).

│ APPROACH COMPARISON TABLE:
│ | Prefix problem | Analogy | Calculation | Time | Space |
│ | Range query naive | count bills each time | q*n | O(qn) | O(1) |
│ | Range query prefix | passbook balance | build n + q reads | O(n+q) | O(n) |
│ | Subarray sum k | old balances freq | n hashmap ops | O(n) avg | O(n) |
│ | Product except self | left/right production | 2n passes | O(n) | O(1) extra |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.assign(nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); i++) {
            prefix[i+1] = prefix[i] + nums[i]; // Running total passbook.
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2,0,3,-5,2,-1};
    NumArray obj(nums);
    cout << obj.sumRange(0,2) << "\n";
    cout << obj.sumRange(2,5) << "\n";
    cout << obj.sumRange(0,5) << "\n";
    return 0;
}

/*
OUTPUT:
1
-1
-3
*/

