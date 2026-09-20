/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_non_overlapping_intervals_remove.cpp
│
│ REAL-WORLD SCENARIO:
│ Meeting conflicts minimize karne hain. Greedy rule: jis meeting ka end earliest hai usko keep karo, kyunki future ke liye maximum room bachta hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ intervals = [[1,2],[2,3],[3,4],[1,3]]
│ Sort by end:
│ [1,2], [1,3], [2,3], [3,4]
│
│ keep [1,2], end=2
│ [1,3] overlaps because start1 < end2 -> remove
│ [2,3] start2 >= end2 -> keep end=3
│ [3,4] start3 >= end3 -> keep
│ Removed = 1

│
│ STEP-BY-STEP DRY RUN:
│ Greedy proof intuition:
│ Among overlapping meetings, keeping earlier ending meeting cannot hurt;
│ it leaves equal or more timeline for future meetings.

│
│ COMPLEXITY CALCULATION:
│ Sort by end time O(n log n).
│ One scan n intervals O(n).
│ Total O(n log n).
│ Extra space O(1) excluding sort stack.

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

int eraseOverlapIntervals(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    int removed = 0;
    int lastEnd = intervals[0][1];
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] < lastEnd) {
            removed++; // Conflict meeting remove.
        } else {
            lastEnd = intervals[i][1];
        }
    }
    return removed;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Remove = " << eraseOverlapIntervals(intervals) << "\n";
    return 0;
}

/*
OUTPUT:
Remove = 1
*/

