/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_generate_permutations_backtracking.cpp
│
│ REAL-WORLD SCENARIO:
│ 3 students ko stage positions par arrange karna hai. Har position par koi unused student choose karo, swap se place karo, recursion ke baad undo swap.
│
│ ASCII VISUAL / DECISION STATE:
│ nums = [1,2,3]
│
│ swap template:
│ fix index0:
│   swap 0 with0 -> [1,2,3]
│   fix index1 -> [1,2,3], [1,3,2]
│   undo
│   swap 0 with1 -> [2,1,3]
│   fix index1 -> [2,1,3], [2,3,1]
│   undo
│   swap 0 with2 -> [3,2,1]
│   fix index1 -> [3,2,1], [3,1,2]
│
│ Total permutations = n!

│
│ STEP-BY-STEP DRY RUN:
│ index=0 choose each element for first position.
│ index=1 choose remaining for second.
│ index=2 leaf permutation.
│ After each recursive call, swap back to restore array.

│
│ COMPLEXITY CALCULATION:
│ Number of permutations = n!.
│ Each leaf copied length n -> O(n).
│ Time = O(n * n!).
│ Recursion depth n -> O(n), output O(n*n!).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void permuteBacktrack(int index, vector<int>& nums, vector<vector<int>>& ans) {
    if (index == (int)nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < (int)nums.size(); i++) {
        swap(nums[index], nums[i]); // CHOOSE: nums[i] ko current seat par lao.
        permuteBacktrack(index + 1, nums, ans);
        swap(nums[index], nums[i]); // UNDO: original order restore.
    }
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    permuteBacktrack(0, nums, ans);
    for (auto p : ans) {
        for (int x : p) cout << x;
        cout << ' ';
    }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
123 132 213 231 321 312
*/

