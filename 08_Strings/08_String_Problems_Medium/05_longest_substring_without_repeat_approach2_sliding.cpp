/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_longest_substring_without_repeat_approach2_sliding.cpp
│
│ REAL-WORLD SCENARIO:
│ Playlist window ko right se expand karo; repeat song aate hi left pointer move karke duplicate remove karo. Ye sliding window + freq array hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. left=0, freq[256]=0.
│ 2. right pointer har char include karta hai.
│ 3. freq[s[right]]++.
│ 4. Jab freq current char > 1, left se chars remove karo until duplicate gone.
│ 5. Window [left..right] always no-repeat maintain karo.
│ 6. best=max(best,right-left+1).
│
│ ASCII VISUAL / WINDOW STATE:
│ s="abcabcbb"
│
│ window expands:
│ [a] best1
│ [ab] best2
│ [abc] best3
│ add a -> [abca] duplicate a
│ move left remove a -> [bca]
│ continue...
│ best=3
│
│ Arrays pattern reuse: freq[ch] works like count window.
│
│ DRY RUN:
│ right0 a window a best1
│ right1 b window ab best2
│ right2 c window abc best3
│ right3 a duplicate -> remove left a -> window bca best3
│ right4 b duplicate -> remove b -> cab best3
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - right pointer moves n times.
│ - left pointer also moves at most n times total.
│ - Each char added once and removed at most once.
│ - Total operations <= 2n plus constant checks.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - freq array fixed 256.
│ -> Extra Space Complexity = O(1).
│ APPROACH COMPARISON TABLE:
│ Brute = try every playlist segment and inspect duplicates, O(n³) time/O(1) space.
│ Sliding window = adjustable live playlist window, O(n) time/O(1) space.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

int longestUniqueSliding(const string& s) {
    vector<int> freq(256, 0);
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        unsigned char ch = s[right];
        freq[ch]++;
        while (freq[ch] > 1) {
            freq[(unsigned char)s[left]]--;
            left++;
        }
        best = max(best, right - left + 1);
        cout << "window [" << left << "," << right << "] length=" << right-left+1 << "\n";
    }
    return best;
}

int main() {
    cout << "Longest unique substring length sliding = " << longestUniqueSliding("abcabcbb") << "\n";
    cout << "Comparison: brute O(n^3), sliding window O(n).\n";
    return 0;
}

/*
OUTPUT:
window [0,0] length=1
window [0,1] length=2
window [0,2] length=3
window [1,3] length=3
window [2,4] length=3
window [3,5] length=3
window [5,6] length=2
window [7,7] length=1
Longest unique substring length sliding = 3
Comparison: brute O(n^3), sliding window O(n).
*/

