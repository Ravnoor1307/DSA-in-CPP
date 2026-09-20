/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_combination_sum.cpp
│
│ REAL-WORLD SCENARIO:
│ Shopping coupons values repeatedly use ho sakte hain. Target bill amount banana hai, all combinations chahiye. Choice use karo: same index reuse allowed.
│
│ ASCII VISUAL / DECISION STATE:
│ candidates = [2,3,6,7], target=7
│
│ Decision:
│ choose 2 -> target5
│ choose 2 -> target3
│ choose 2 -> target1
│ cannot continue, backtrack
│ from target3 choose 3 -> target0 -> [2,2,3]
│ backtrack
│ choose 7 directly -> target0 -> [7]
│
│ Reuse allowed: recursive call with same i, not i+1.

│
│ STEP-BY-STEP DRY RUN:
│ backtrack(start=0, remain=7, path=[])
│ i=0 choose2 path[2], remain5
│ choose2 path[2,2], remain3
│ choose3 path[2,2,3], remain0 store
│ undo all, choose7 path[7], remain0 store.

│
│ COMPLEXITY CALCULATION:
│ Search tree can be exponential because combinations grow with target.
│ If minimum candidate is m, depth can be target/m.
│ Branching up to n choices.
│ Upper bound often expressed exponential O(n^(target/m)).
│ Space recursion depth O(target/m), output can be large.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void solve(int start, int remain, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans) {
    if (remain == 0) { ans.push_back(path); return; }
    if (remain < 0) return;
    for (int i = start; i < (int)candidates.size(); i++) {
        path.push_back(candidates[i]);
        solve(i, remain - candidates[i], candidates, path, ans); // i same because reuse allowed.
        path.pop_back();
    }
}

int main() {
    vector<int> candidates = {2,3,6,7}, path;
    vector<vector<int>> ans;
    solve(0, 7, candidates, path, ans);
    for (auto comb : ans) {
        cout << "[";
        for (int x : comb) cout << x << ' ';
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
[2 2 3 ] [7 ]
*/

