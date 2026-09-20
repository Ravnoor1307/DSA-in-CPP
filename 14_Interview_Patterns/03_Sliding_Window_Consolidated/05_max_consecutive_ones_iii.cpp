/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_max_consecutive_ones_iii.cpp
│
│ REAL-WORLD SCENARIO:
│ CCTV road segment me at most k broken lights ko temporarily fix/flip kar sakte hain. Longest segment with at most k zeros sliding window se milta hai.
│
│ VISUAL / PATTERN STATE:
│ nums = [1,1,1,0,0,0,1,1,1,1,0], k=2
│
│ Window condition: zeros <= k
│ Expand right.
│ If zeros > k, shrink left until zeros <= k.
│
│ Best segment after processing:
│ [0,0,1,1,1,1] length 6 with two zeros flipped.
│ Answer = 6

│
│ STEP-BY-STEP DRY RUN:
│ right scans each bit.
│ zero count increments on 0.
│ while zero count > k:
│   if nums[left]==0 zero--
│   left++
│ best length update.

│
│ COMPLEXITY CALCULATION:
│ right pointer n moves.
│ left pointer n moves at most.
│ Each step constant bit checks.
│ Time = O(n).
│ Space = O(1).

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

int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeros = 0, best = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        if (nums[right] == 0) zeros++;
        while (zeros > k) {
            if (nums[left] == 0) zeros--;
            left++; // Too many flipped zeros, window shrink.
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout << "Longest ones after flips = " << longestOnes(nums, 2) << "\n";
    return 0;
}

/*
OUTPUT:
Longest ones after flips = 6
*/

