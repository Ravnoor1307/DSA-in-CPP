/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_generate_subsets_backtracking.cpp
│
│ REAL-WORLD SCENARIO:
│ Pizza toppings choose karne hain: har topping include ya exclude. All subsets generate karne ke liye decision tree me dono choices explore karo.
│
│ ASCII VISUAL / DECISION STATE:
│ nums = [1,2,3]
│ Decision tree:
│              []
│          /        \
│       include1    exclude1
│        [1]          []
│      /    \       /    \
│   [1,2]  [1]    [2]    []
│
│ Leaves = 2^n subsets.
│ Output:
│ [], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]

│
│ STEP-BY-STEP DRY RUN:
│ backtrack(index=0,path=[])
│ choose1 -> path[1]
│ choose2 -> path[1,2]
│ choose3 -> path[1,2,3], store
│ undo3 -> path[1,2]
│ exclude3 branch store [1,2]
│ ...

│
│ COMPLEXITY CALCULATION:
│ Each element has 2 choices include/exclude.
│ Leaves = 2^n.
│ Copying each subset can cost up to n.
│ Time = O(n * 2^n).
│ Recursion stack O(n), output size O(n * 2^n).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void backtrack(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
    if (index == (int)nums.size()) {
        ans.push_back(path);
        return;
    }
    path.push_back(nums[index]); // CHOOSE include
    backtrack(index + 1, nums, path, ans); // EXPLORE
    path.pop_back(); // UNDO
    backtrack(index + 1, nums, path, ans); // exclude branch
}

int main() {
    vector<int> nums = {1,2,3}, path;
    vector<vector<int>> ans;
    backtrack(0, nums, path, ans);
    for (auto subset : ans) {
        cout << "[";
        for (int x : subset) cout << x;
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
[123] [12] [13] [1] [23] [2] [3] []
*/

