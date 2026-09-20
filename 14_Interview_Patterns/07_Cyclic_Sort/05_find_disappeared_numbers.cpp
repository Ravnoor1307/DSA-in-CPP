/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_find_disappeared_numbers.cpp
│
│ REAL-WORLD SCENARIO:
│ Attendance sheet me kuch roll numbers missing hain. Har existing number ko apni seat par bithao; jo seats empty/wrong bachi, wahi disappeared numbers.
│
│ ASCII VISUAL / PATTERN STATE:
│ nums = [4,3,2,7,8,2,3,1]
│ After cyclic placement:
│ got:  [1,2,3,4,3,2,7,8]
│ want: [1,2,3,4,5,6,7,8]
│
│ index4 missing value5
│ index5 missing value6
│ Answer [5,6]

│
│ STEP-BY-STEP DRY RUN:
│ Cyclic sort with duplicates guard.
│ After placement, scan:
│ if nums[i] != i+1, then i+1 disappeared.

│
│ COMPLEXITY CALCULATION:
│ Swaps <= n, scan n.
│ Time = O(n).
│ Extra space excluding answer = O(1).

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

vector<int> findDisappearedNumbers(vector<int> nums) {
    int i = 0, n = nums.size();
    while (i < n) {
        int correct = nums[i] - 1;
        if (nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
    }
    vector<int> missing;
    for (int idx = 0; idx < n; idx++) if (nums[idx] != idx + 1) missing.push_back(idx + 1);
    return missing;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDisappearedNumbers(nums);
    for (int x : ans) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
5 6
*/

