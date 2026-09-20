/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_min_window_substring_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Store se grocery list ke required items lene hain, minimum contiguous shelf segment chahiye jisme saare required items cover ho. Expand to satisfy, shrink to minimize.
│
│ VISUAL / PATTERN STATE:
│ s="ADOBECODEBANC", t="ABC"
│ need: A1 B1 C1
│
│ Expand right until all needs satisfied:
│ A D O B E C -> window "ADOBEC" valid length6
│ Shrink left:
│ remove A -> invalid
│ Continue expand until next A and C.
│ Later window "BANC" valid length4, best.
│
│ NEEDS map table idea:
│ right char | have formed | window | action
│ A          | A satisfied | A      | expand
│ B          | B satisfied | ADOB   | expand
│ C          | C satisfied | ADOBEC | shrink

│
│ STEP-BY-STEP DRY RUN:
│ required = number of unique chars in t.
│ formed = chars whose window count meets need count.
│ When formed==required, window valid.
│ Then while valid, update best and shrink left.

│
│ COMPLEXITY CALCULATION:
│ right pointer visits each char once -> n moves.
│ left pointer visits each char once -> n moves.
│ Map operations average O(1).
│ Total = O(2n + |t|) = O(n + m).
│ Space = need/window maps for charset -> O(m) or O(1) fixed ASCII.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> need, window;
    for (char c : t) need[c]++;
    int required = need.size(), formed = 0;
    int left = 0, bestLen = INT_MAX, bestStart = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];
        window[c]++;
        if (need.count(c) && window[c] == need[c]) formed++;

        while (formed == required) {
            int len = right - left + 1;
            if (len < bestLen) { bestLen = len; bestStart = left; }
            char drop = s[left];
            window[drop]--;
            if (need.count(drop) && window[drop] < need[drop]) formed--;
            left++; // Valid window ko minimum banane ki try.
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}

int main() {
    cout << "Minimum window = " << minWindow("ADOBECODEBANC", "ABC") << "\n";
    return 0;
}

/*
OUTPUT:
Minimum window = BANC
*/

