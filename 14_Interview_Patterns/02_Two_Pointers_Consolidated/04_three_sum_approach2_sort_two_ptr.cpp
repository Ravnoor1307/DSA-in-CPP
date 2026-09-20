/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_three_sum_approach2_sort_two_ptr.cpp
│
│ REAL-WORLD SCENARIO:
│ Teen expenses ka zero sum find karna hai. Ek value fix karo, baaki sorted array me two-sum two pointers se find karo.
│
│ VISUAL / PATTERN STATE:
│ nums sorted = [-4,-1,-1,0,1,2]
│
│ Fix i=0 (-4): target for L+R = 4
│ l=1,r=5 -> -1+2=1 <4 -> l++
│ no triplet.
│
│ Fix i=1 (-1): target = 1
│ l=2(-1), r=5(2): sum1 found [-1,-1,2]
│ l=3(0), r=4(1): sum1 found [-1,0,1]
│
│ Skip duplicate fixed values.

│
│ STEP-BY-STEP DRY RUN:
│ Sort first.
│ For each i, l=i+1,r=n-1.
│ If total <0, need bigger sum -> l++.
│ If total >0, need smaller sum -> r--.
│ If total=0, store and skip duplicates.

│
│ COMPLEXITY CALCULATION:
│ Sorting costs O(n log n).
│ Outer i loop runs n times.
│ For each i, l/r together move at most n steps.
│ Two-pointer total per i = O(n).
│ Total = O(n log n + n*n) = O(n²).
│ Extra space excluding answer = O(1) or O(log n) sort stack.

│ APPROACH COMPARISON TABLE:
│ | 3Sum approach | Analogy | Calculation | Time | Space |
│ | Brute force | every 3-person group | nC3 = n(n-1)(n-2)/6 | O(n³) | O(t) |
│ | Sort + 2 ptr | fix one, two guards search | n fixed * n pointer moves | O(n²) | O(1) extra |
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

vector<vector<int>> threeSum(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                ans.push_back({nums[i], nums[l], nums[r]});
                l++; r--;
                while (l < r && nums[l] == nums[l-1]) l++;
                while (l < r && nums[r] == nums[r+1]) r--;
            } else if (sum < 0) l++; // Sum chhota hai, bigger value chahiye.
            else r--;                // Sum bada hai, smaller value chahiye.
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto t : ans) cout << t[0] << ' ' << t[1] << ' ' << t[2] << "\n";
    return 0;
}

/*
OUTPUT:
-1 -1 2
-1 0 1
*/

