/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_meeting_rooms_check.cpp
│
│ REAL-WORLD SCENARIO:
│ Ek conference room hai. Check karna hai ki person saari meetings attend kar sakta hai ya nahi. Start time sort karo; adjacent overlap means impossible.
│
│ ASCII VISUAL / PATTERN STATE:
│ meetings = [[0,30],[5,10],[15,20]]
│ Sort by start:
│ [0,30], [5,10], [15,20]
│
│ Check adjacent:
│ meeting1 start5 < previous end30 -> overlap
│ Can attend all? NO
│
│ Non-overlap example:
│ [5,8], [9,15]
│ next.start >= prev.end -> OK

│
│ STEP-BY-STEP DRY RUN:
│ Sort meetings by start.
│ For i=1..n-1:
│ if intervals[i][0] < intervals[i-1][1], return false.
│ Else continue.

│
│ COMPLEXITY CALCULATION:
│ Sort n meetings -> O(n log n).
│ Adjacent scan n-1 comparisons -> O(n).
│ Total = O(n log n).
│ Extra space O(1) excluding sort stack.

│ APPROACH COMPARISON TABLE:
│ | Interval problem | Analogy | Key sorting | Time | Space |
│ | Merge intervals | merge calendar blocks | start time | O(n log n) | O(n) |
│ | Insert interval | add new meeting | already sorted | O(n) | O(n) |
│ | Remove overlaps | maximize meetings | end time | O(n log n) | O(1) |
│ | Meeting rooms check | attend all meetings | start time | O(n log n) | O(1) |
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

bool canAttendMeetings(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] < intervals[i-1][1]) return false; // Timeline overlap.
    }
    return true;
}

int main() {
    vector<vector<int>> meetings = {{0,30},{5,10},{15,20}};
    cout << "Can attend all? " << (canAttendMeetings(meetings) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Can attend all? NO
*/

