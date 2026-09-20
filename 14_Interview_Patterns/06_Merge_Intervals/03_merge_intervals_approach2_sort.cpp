/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_merge_intervals_approach2_sort.cpp
│
│ REAL-WORLD SCENARIO:
│ Calendar meetings ko start time ke order me sort karo. Ab overlap sirf adjacent merged block se check karna hai, pairwise chaos nahi.
│
│ ASCII VISUAL / PATTERN STATE:
│ Input: [[1,3],[2,6],[8,10]]
│ Sort by start: same order
│
│ current answer empty.
│ Add [1,3]
│ Check [2,6]: 2 <= lastEnd3 -> merge to [1,6]
│ Check [8,10]: 8 > lastEnd6 -> new interval
│
│ Timeline:
│ [1,3]  =====
│ [2,6]    =========  merge -> [1,6]
│ [8,10]             ===== separate

│
│ STEP-BY-STEP DRY RUN:
│ ans=[[1,3]]
│ next [2,6] overlaps last [1,3] -> ans [[1,6]]
│ next [8,10] no overlap -> ans [[1,6],[8,10]]

│
│ COMPLEXITY CALCULATION:
│ Sort n intervals by start -> O(n log n).
│ One scan after sorting -> n-1 comparisons = O(n).
│ Total = O(n log n + n) = O(n log n).
│ Answer space O(n). Sorting stack O(log n) typical.

│ APPROACH COMPARISON TABLE:
│ | Merge approach | Analogy | Work calculation | Time | Space |
│ | Brute force | check every meeting pair | n*n comparisons | O(n²) | O(n) |
│ | Sort + scan | arrange by start time | sort nlogn + scan n | O(n log n) | O(n) |
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

vector<vector<int>> mergeSorted(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (auto cur : intervals) {
        if (ans.empty() || cur[0] > ans.back()[1]) {
            ans.push_back(cur);
        } else {
            ans.back()[1] = max(ans.back()[1], cur[1]); // Adjacent overlap merge.
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10}};
    vector<vector<int>> ans = mergeSorted(intervals);
    for (auto in : ans) cout << '[' << in[0] << ',' << in[1] << "] ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
[1,6] [8,10]
*/

