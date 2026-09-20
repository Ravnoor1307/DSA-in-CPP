/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_pattern_template_summary.cpp
│
│ REAL-WORLD SCENARIO:
│ Interview me sliding window camera frame yaad rakho: right expand karta hai, left condition fix karta hai, answer har valid frame par update hota hai.
│
│ VISUAL / PATTERN STATE:
│ UNIVERSAL VARIABLE WINDOW TEMPLATE:
│
│ left = 0
│ for right in [0..n-1]:
│     add arr[right] to window
│     while window invalid:
│         remove arr[left]
│         left++
│     update answer with window [left..right]
│
│ Fixed window template:
│ running += arr[right]
│ if right >= k: running -= arr[right-k]
│ if right >= k-1: update answer
│
│ AT MOST K template:
│ while distinct/count > K: shrink
│
│ EXACT K trick:
│ exactK = atMost(K) - atMost(K-1)

│
│ STEP-BY-STEP DRY RUN:
│ Example max consecutive ones:
│ add right bit.
│ invalid if zeros > k.
│ shrink until zeros <= k.
│ answer max length.

│
│ COMPLEXITY CALCULATION:
│ Universal window condition where left/right monotonic:
│ right moves n times.
│ left moves n times.
│ Total pointer moves <= 2n.
│ Time = O(n) plus map operations.
│ Space depends on window state: O(1), O(k), or O(charset).

│ APPROACH COMPARISON TABLE:
│ | Window type | Analogy | Signal | Template | Time |
│ | Fixed | fixed CCTV frame | size k | add right remove old | O(n) |
│ | Variable max | stretchable frame | longest valid | expand then shrink invalid | O(n) |
│ | Variable min | smallest shelf segment | minimum valid | expand valid, shrink while valid | O(n) |
│ | At most K | baskets capacity | <=K distinct/zeros | shrink when count>K | O(n) |
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

int atMostKDistinct(const vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    int left = 0, ans = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        freq[nums[right]]++;
        while ((int)freq.size() > k) {
            int x = nums[left++];
            if (--freq[x] == 0) freq.erase(x);
        }
        ans += right - left + 1; // Subarrays ending at right.
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,1,2,3};
    cout << "Subarrays with at most 2 distinct = " << atMostKDistinct(nums, 2) << "\n";
    return 0;
}

/*
OUTPUT:
Subarrays with at most 2 distinct = 12
*/

