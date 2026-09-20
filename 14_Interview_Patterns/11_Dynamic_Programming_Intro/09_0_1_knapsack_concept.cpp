/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 09_0_1_knapsack_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Bag capacity limited hai. Har item ya lo ya skip karo; item fractional nahi, isliye 0/1 knapsack DP original classic hai.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ weights = [1,3,4,5]
│ values  = [1,4,5,7]
│ capacity = 7
│
│ dp[i][cap] = first i items se max value under capacity cap
│
│ For item i:
│ skip = dp[i-1][cap]
│ take = value[i-1] + dp[i-1][cap-weight[i-1]] if weight fits
│ dp[i][cap] = max(skip, take)
│
│ Best for capacity7 = 9 by items weight3(value4)+weight4(value5).

│
│ STEP-BY-STEP DRY RUN:
│ item weight1 value1 updates capacities >=1.
│ item weight3 value4: cap4 can become 5.
│ item weight4 value5: cap7 can become 9.
│ item weight5 value7: cap7 max remains 9.

│
│ COMPLEXITY CALCULATION:
│ n items and capacity W.
│ Table cells = (n+1)*(W+1).
│ Each cell constant max/add.
│ Time = O(n*W).
│ Space = O(n*W), can optimize to O(W).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= W; cap++) {
            int skip = dp[i-1][cap];
            int take = 0;
            if (wt[i-1] <= cap) take = val[i-1] + dp[i-1][cap - wt[i-1]];
            dp[i][cap] = max(skip, take);
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    cout << "Max value = " << knapsack(wt, val, 7) << "\n";
    return 0;
}

/*
OUTPUT:
Max value = 9
*/

