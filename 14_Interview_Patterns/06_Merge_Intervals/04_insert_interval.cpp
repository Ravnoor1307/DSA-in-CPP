/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_insert_interval.cpp
│
│ REAL-WORLD SCENARIO:
│ Calendar me new meeting insert karni hai. Pehle non-overlap meetings add karo, phir overlapping meetings merge karo, phir remaining add karo.
│
│ ASCII VISUAL / PATTERN STATE:
│ intervals = [[1,3],[6,9]], new = [2,5]
│
│ Timeline:
│ [1,3] overlaps [2,5] -> merge [1,5]
│ [6,9] starts after 5 -> append
│
│ Output [[1,5],[6,9]]
│
│ Steps:
│ 1. Add intervals ending before new.start.
│ 2. Merge intervals starting <= new.end.
│ 3. Add remaining intervals.

│
│ STEP-BY-STEP DRY RUN:
│ i=0 [1,3], end3 not < start2 -> go merge.
│ merge: start=min(2,1)=1, end=max(5,3)=5.
│ i=1 [6,9], start6 > end5 -> stop.
│ push [1,5], then [6,9].

│
│ COMPLEXITY CALCULATION:
│ Intervals are already sorted and non-overlapping.
│ Pointer i moves from 0 to n once across three while loops.
│ Time = O(n).
│ Answer stores up to n+1 intervals -> O(n).

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

vector<vector<int>> insertInterval(vector<vector<int>> intervals, vector<int> newInterval) {
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();
    while (i < n && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    while (i < n) ans.push_back(intervals[i++]);
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> nw = {2,5};
    for (auto in : insertInterval(intervals, nw)) cout << '[' << in[0] << ',' << in[1] << "] ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
[1,5] [6,9]
*/

