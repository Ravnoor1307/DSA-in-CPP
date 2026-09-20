/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_three_sum_approach1_bruteforce.cpp
│
│ REAL-WORLD SCENARIO:
│ Teen logon ki expense values choose karke total zero banana hai. Brute force har possible triplet try karta hai, jaise har teen-student group manually check karna.
│
│ VISUAL / PATTERN STATE:
│ nums = [-1,0,1,2,-1,-4]
│
│ Brute force loops:
│ i from 0..n-3
│   j from i+1..n-2
│     k from j+1..n-1
│       if nums[i]+nums[j]+nums[k]==0 -> store sorted unique triplet
│
│ Example valid groups:
│ -1 + 0 + 1 = 0
│ -1 + -1 + 2 = 0

│
│ STEP-BY-STEP DRY RUN:
│ Check triplets:
│ i=0(-1), j=1(0), k=2(1) -> sum0 store [-1,0,1]
│ i=0(-1), j=3(2), k=4(-1) -> sum0 store [-1,-1,2]
│ Many extra groups checked.

│
│ COMPLEXITY CALCULATION:
│ Triple nested loops.
│ Number of triplets = n choose 3 = n(n-1)(n-2)/6.
│ Leading term n³/6 -> O(n³).
│ Sorting each valid triplet is constant 3 items -> O(1).
│ Space for answers can be O(t), t valid unique triplets.

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

vector<vector<int>> threeSumBrute(vector<int> nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    if (find(ans.begin(), ans.end(), trip) == ans.end()) ans.push_back(trip);
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSumBrute(nums);
    for (auto t : ans) cout << t[0] << ' ' << t[1] << ' ' << t[2] << "\n";
    return 0;
}

/*
OUTPUT:
-1 -1 2
-1 0 1
*/

