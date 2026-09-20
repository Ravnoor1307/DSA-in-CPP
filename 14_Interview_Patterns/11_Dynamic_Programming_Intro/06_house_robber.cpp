/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_house_robber.cpp
│
│ REAL-WORLD SCENARIO:
│ Chor adjacent houses loot nahi kar sakta. Har house par decision hai: loot karo plus i-2 best, ya skip karo and i-1 best.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ houses = [2,7,9,3,1]
│
│ dp[i] = max(skip, loot)
│ skip = dp[i-1]
│ loot = nums[i] + dp[i-2]
│
│ Table:
│ i0 house2 -> dp0=2
│ i1 house7 -> max(2,7)=7
│ i2 house9 -> max(skip7, loot9+2=11)=11
│ i3 house3 -> max(11, 3+7=10)=11
│ i4 house1 -> max(11, 1+11=12)=12
│ answer 12

│
│ STEP-BY-STEP DRY RUN:
│ At every index:
│ Option A skip current house.
│ Option B rob current house and add best till i-2.
│ Store best till i.

│
│ COMPLEXITY CALCULATION:
│ Loop n houses once -> n iterations.
│ Each iteration constant max/add.
│ Time = O(n).
│ DP array O(n), optimized possible O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    cout << "dp[0]=" << dp[0] << " dp[1]=" << dp[1] << "\n";
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        cout << "dp[" << i << "]=" << dp[i] << "\n";
    }
    return dp[n-1];
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << "Max loot = " << rob(nums) << "\n";
    return 0;
}

/*
OUTPUT:
dp[0]=2 dp[1]=7
dp[2]=11
dp[3]=11
dp[4]=12
Max loot = 12
*/

