/*
═══════════════════════════════════════════════
 LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS — APPROACH 2 (SLIDING WINDOW)
 ⏱️ TIME COMPLEXITY: O(n) — right moves n times and left moves at most n times, each char added once and removed once, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Expand a playlist window to the right; as soon as a song repeats, move the left
 pointer to drop the duplicate. This is the sliding window plus frequency array.

 📖 THEORY:
 - Start left=0 with freq[256]=0.
 - The right pointer includes each character.
 - Increment freq[s[right]].
 - While freq of the current char is > 1, remove chars from the left until the
   duplicate is gone.
 - The window [left..right] always has no repeats.
 - Update best = max(best, right-left+1).

 ASCII VISUAL / WINDOW STATE:
 s="abcabcbb"

 window expands:
 [a] best1
 [ab] best2
 [abc] best3
 add a -> [abca] duplicate a
 move left remove a -> [bca]
 continue...
 best=3

 Arrays pattern reuse: freq[ch] works like a count window.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Initialize left=0 and freq[256]=0.
    WHY: the window starts empty at the left edge.
 Step 2: For each right, include s[right] and increment its freq.
    WHY: the window grows by one character.
 Step 3: While freq[s[right]] > 1, remove s[left] and left++.
    WHY: shrinking from the left restores uniqueness.
 Step 4: Update best with the current window length.
    WHY: the window is always a valid no-repeat segment.

 DRY RUN:
 right0 a window a best1
 right1 b window ab best2
 right2 c window abc best3
 right3 a duplicate -> remove left a -> window bca best3
 right4 b duplicate -> remove b -> cab best3

 FLOW OF EXECUTION:
 input string -> expand right into window -> shrink left on duplicate -> track max length -> print result

 TIME COMPLEXITY CALCULATION:
 - right pointer moves n times.
 - left pointer also moves at most n times total.
 - Each char added once and removed at most once.
 - Total operations <= 2n plus constant checks.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - freq array fixed 256.
 -> Extra Space Complexity = O(1).
 APPROACH COMPARISON TABLE:
 Brute = try every playlist segment and inspect duplicates, O(n³) time/O(1) space.
 Sliding window = adjustable live playlist window, O(n) time/O(1) space.
═══════════════════════════════════════════════
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

