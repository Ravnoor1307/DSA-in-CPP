/*
REAL-WORLD SCENARIO:
Maze and choices lab: all subsets/permutations/valid paths generate karne hain.

TASKS easy -> hard:
1. Backtracking mantra comments me likho.
2. Generate subsets implement karo.
3. Generate permutations implement karo.
4. Combination sum implement karo.
5. Word search grid implement karo.
6. 4-Queens solve karo.
7. Backtracking vs DP table likho.

HINTS:
- State change ke baad undo zaruri hai.
- Subsets: include/exclude.
- Permutations: swap and swap back.

STARTER CODE:
path.push_back(x); solve(...); path.pop_back();

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
using namespace std;

void subsets(int idx, vector<int>& nums, vector<int>& path) {
    if (idx == (int)nums.size()) {
        cout << "["; for (int x : path) cout << x; cout << "] ";
        return;
    }
    path.push_back(nums[idx]);
    subsets(idx+1, nums, path);
    path.pop_back(); // undo
    subsets(idx+1, nums, path);
}

int main() {
    vector<int> nums = {1,2};
    vector<int> path;
    subsets(0, nums, path);
    cout << "\n";
    return 0;
}

/*
OUTPUT:
[12] [1] [2] []
*/
