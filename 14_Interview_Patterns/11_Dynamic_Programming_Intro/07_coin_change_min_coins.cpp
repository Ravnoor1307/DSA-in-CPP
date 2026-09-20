/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_coin_change_min_coins.cpp
│
│ REAL-WORLD SCENARIO:
│ Shopkeeper ko amount minimum coins se banana hai. Har amount ke liye previous amount plus one coin decision se dp table fill hota hai.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ coins = [1,2,5], amount=11
│
│ dp[a] = minimum coins for amount a
│ dp[0] = 0
│
│ Fill:
│ dp[1]=1 using coin1
│ dp[2]=1 using coin2
│ dp[3]=2 (1+2)
│ dp[4]=2 (2+2)
│ dp[5]=1 (5)
│ ...
│ dp[10]=2 (5+5)
│ dp[11]=3 (5+5+1)
│
│ Choice tree can repeat states; DP table avoids repeats.

│
│ STEP-BY-STEP DRY RUN:
│ For amount a from1..11:
│ try each coin c.
│ if a-c >= 0 and dp[a-c] possible:
│    dp[a] = min(dp[a], dp[a-c] + 1)

│
│ COMPLEXITY CALCULATION:
│ amount = A, number of coins = C.
│ Outer loop A times.
│ Inner loop C coins.
│ Total checks = A*C -> O(A*C).
│ DP array A+1 -> O(A).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    const int INF = 1000000000;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int a = 1; a <= amount; a++) {
        for (int coin : coins) {
            if (a - coin >= 0 && dp[a - coin] != INF) {
                dp[a] = min(dp[a], dp[a - coin] + 1);
            }
        }
        cout << "dp[" << a << "]=" << (dp[a] == INF ? -1 : dp[a]) << "\n";
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1,2,5};
    cout << "Min coins = " << coinChange(coins, 11) << "\n";
    return 0;
}

/*
OUTPUT:
dp[1]=1
dp[2]=1
dp[3]=2
dp[4]=2
dp[5]=1
dp[6]=2
dp[7]=2
dp[8]=3
dp[9]=3
dp[10]=2
dp[11]=3
Min coins = 3
*/

