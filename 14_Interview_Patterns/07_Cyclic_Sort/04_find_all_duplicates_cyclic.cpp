/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_find_all_duplicates_cyclic.cpp
│
│ REAL-WORLD SCENARIO:
│ Class seats 1..n me duplicate students baithe hain. Cyclic sort ke baad jis seat par wrong number reh gaya, wo duplicate identify karta hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ nums = [4,3,2,7,8,2,3,1]
│ After cyclic placement:
│ index: 0 1 2 3 4 5 6 7
│ want:  1 2 3 4 5 6 7 8
│ got:   1 2 3 4 3 2 7 8
│
│ index4 should have5 but has3 -> duplicate3
│ index5 should have6 but has2 -> duplicate2
│
│ Answer [3,2] or [2,3]

│
│ STEP-BY-STEP DRY RUN:
│ During sort, if nums[i] already equals nums[correct], i++.
│ This prevents infinite loop on duplicates.
│ Then scan mismatches.

│
│ COMPLEXITY CALCULATION:
│ Each successful swap puts a number in correct index.
│ Total swaps <= n.
│ Scan n.
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

vector<int> findDuplicates(vector<int> nums) {
    int i = 0, n = nums.size();
    while (i < n) {
        int correct = nums[i] - 1;
        if (nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
    }
    vector<int> ans;
    for (int idx = 0; idx < n; idx++) {
        if (nums[idx] != idx + 1) ans.push_back(nums[idx]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDuplicates(nums);
    for (int x : ans) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
2 3
*/

