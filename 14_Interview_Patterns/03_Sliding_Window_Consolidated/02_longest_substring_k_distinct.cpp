/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_longest_substring_k_distinct.cpp
│
│ REAL-WORLD SCENARIO:
│ Music playlist me contiguous song segment chahiye jisme at most k artists ho. Right se songs add karo; artists zyada ho gaye to left se remove karo.
│
│ VISUAL / PATTERN STATE:
│ s = "eceba", k=2
│
│ Window states:
│ right0 e -> "e" distinct1 best1
│ right1 c -> "ec" distinct2 best2
│ right2 e -> "ece" distinct2 best3
│ right3 b -> "eceb" distinct3 invalid
│ shrink left: remove e count becomes1 -> still3 distinct
│ remove c -> window "eb" distinct2
│ right4 a -> "eba" distinct3 invalid, shrink to "ba"
│ best = 3

│
│ STEP-BY-STEP DRY RUN:
│ freq map tracks char counts.
│ distinct = freq.size().
│ while distinct > k, decrement s[left], erase if zero, left++.
│ answer = max(answer, right-left+1).

│
│ COMPLEXITY CALCULATION:
│ right moves n times.
│ left also moves at most n times total.
│ Each char inserted/removed O(1) average in unordered_map.
│ Total = O(2n) = O(n).
│ Space = at most k+1 characters in map -> O(k), bounded by charset.

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

int longestKDistinct(const string& s, int k) {
    unordered_map<char,int> freq;
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        freq[s[right]]++;
        while ((int)freq.size() > k) {
            char ch = s[left];
            freq[ch]--;
            if (freq[ch] == 0) freq.erase(ch);
            left++; // Invalid window ko left se shrink.
        }
        best = max(best, right - left + 1);
        cout << "window [" << left << "," << right << "] best=" << best << "\n";
    }
    return best;
}

int main() {
    cout << "Longest length = " << longestKDistinct("eceba", 2) << "\n";
    return 0;
}

/*
OUTPUT:
window [0,0] best=1
window [0,1] best=2
window [0,2] best=3
window [2,3] best=3
window [3,4] best=3
Longest length = 3
*/

