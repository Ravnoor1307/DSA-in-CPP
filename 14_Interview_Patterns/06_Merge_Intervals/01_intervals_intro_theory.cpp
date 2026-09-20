/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_intervals_intro_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Calendar meetings timeline par bars ki tarah hote hain. Agar bars overlap kar rahe hain, unhe merge karna ya conflict detect karna intervals pattern hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ Timeline:
│ [1,3]  =====
│ [2,6]    =========
│ [8,10]             =====
│
│ Overlap condition for sorted/current intervals:
│ next.start <= current.end
│
│ Merge:
│ [1,3] and [2,6] overlap -> [1,6]
│ [8,10] separate.
│
│ Signals:
│ meetings, intervals, schedule, overlap, timeline.

│
│ STEP-BY-STEP DRY RUN:
│ Start with current [1,3].
│ Next [2,6], 2 <= 3 -> overlap, current end=max(3,6)=6.
│ Next [8,10], 8 > 6 -> push [1,6], start new [8,10].

│
│ COMPLEXITY CALCULATION:
│ If intervals sorted, one scan n intervals -> O(n).
│ Sorting by start first costs O(n log n).
│ Space for answer O(n).

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

int main() {
    cout << "Interval pattern = timeline overlap logic\n";
    cout << "Overlap when next.start <= current.end\n";
    cout << "Example [1,3] + [2,6] -> [1,6]\n";
    return 0;
}

/*
OUTPUT:
Interval pattern = timeline overlap logic
Overlap when next.start <= current.end
Example [1,3] + [2,6] -> [1,6]
*/

