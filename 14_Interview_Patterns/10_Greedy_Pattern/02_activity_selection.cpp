/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_activity_selection.cpp
│
│ REAL-WORLD SCENARIO:
│ One meeting room me maximum activities schedule karni hain. Earliest ending activity choose karo, kyunki future ke liye room sabse zyada bachta hai.
│
│ ASCII VISUAL / DECISION STATE:
│ Activities [start,end]:
│ [1,2], [3,4], [0,6], [5,7], [8,9], [5,9]
│
│ Sort by end:
│ [1,2], [3,4], [0,6], [5,7], [8,9], [5,9]
│
│ pick [1,2], lastEnd=2
│ pick [3,4], lastEnd=4
│ skip [0,6]
│ pick [5,7], lastEnd=7
│ pick [8,9], lastEnd=9
│ skip [5,9]
│
│ Selected = 4

│
│ STEP-BY-STEP DRY RUN:
│ Greedy proof:
│ If we choose activity that ends earliest, it leaves maximum remaining timeline.
│ Any optimal solution can replace its first selected activity with earliest-ending compatible activity without reducing count.

│
│ COMPLEXITY CALCULATION:
│ Sort n activities by end -> O(n log n).
│ Scan n activities -> O(n).
│ Total = O(n log n).
│ Extra space O(1) excluding sort stack.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int activitySelection(vector<pair<int,int>> acts) {
    sort(acts.begin(), acts.end(), [](auto a, auto b){ return a.second < b.second; });
    int count = 0, lastEnd = -1;
    for (auto act : acts) {
        if (act.first >= lastEnd) {
            count++;
            lastEnd = act.second;
            cout << "Pick [" << act.first << "," << act.second << "]\n";
        }
    }
    return count;
}

int main() {
    vector<pair<int,int>> acts = {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    cout << "Max activities = " << activitySelection(acts) << "\n";
    return 0;
}

/*
OUTPUT:
Pick [1,2]
Pick [3,4]
Pick [5,7]
Pick [8,9]
Max activities = 4
*/

