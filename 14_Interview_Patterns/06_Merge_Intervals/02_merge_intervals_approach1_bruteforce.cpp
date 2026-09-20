/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_merge_intervals_approach1_bruteforce.cpp
│
│ REAL-WORLD SCENARIO:
│ Meetings merge karne ka brute approach: har meeting ko baaki sab meetings se compare karo, jaise calendar me every pair manually check karna.
│
│ ASCII VISUAL / PATTERN STATE:
│ intervals = [[1,3],[2,6],[8,10]]
│
│ Brute idea:
│ For each unvisited interval i:
│   current = intervals[i]
│   scan all j:
│      if j overlaps current, merge and mark visited
│
│ Pair comparisons:
│ [1,3] with [2,6] -> overlap -> [1,6]
│ [1,6] with [8,10] -> no overlap
│
│ Answer: [[1,6],[8,10]]

│
│ STEP-BY-STEP DRY RUN:
│ i=0 current [1,3]
│ j=1 overlaps -> current [1,6]
│ j=2 no
│ i=2 not visited -> current [8,10]

│
│ COMPLEXITY CALCULATION:
│ Outer loop n intervals.
│ Inner loop can scan n intervals.
│ Comparisons <= n*n = n².
│ Time = O(n²).
│ visited array O(n), answer O(n) -> O(n).

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

bool overlap(vector<int> a, vector<int> b) {
    return max(a[0], b[0]) <= min(a[1], b[1]);
}

vector<vector<int>> mergeBrute(vector<vector<int>> intervals) {
    int n = intervals.size();
    vector<int> used(n, 0);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        vector<int> cur = intervals[i];
        used[i] = 1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && overlap(cur, intervals[j])) {
                cur[0] = min(cur[0], intervals[j][0]);
                cur[1] = max(cur[1], intervals[j][1]);
                used[j] = 1;
            }
        }
        ans.push_back(cur);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10}};
    for (auto in : mergeBrute(intervals)) cout << '[' << in[0] << ',' << in[1] << "] ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
[1,6] [8,10]
*/

