/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_fibonacci_tabulation_approach.cpp
│
│ REAL-WORLD SCENARIO:
│ Stairs ke marks bottom se fill karne jaise, fibonacci table small values se bigger values tak fill hota hai. Ye bottom-up tabulation hai.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ Table fill:
│ n=6
│ dp[0]=0
│ dp[1]=1
│ dp[2]=dp[1]+dp[0]=1
│ dp[3]=dp[2]+dp[1]=2
│ dp[4]=3
│ dp[5]=5
│ dp[6]=8
│
│ Visual:
│ index: 0 1 2 3 4 5 6
│ dp:    0 1 1 2 3 5 8

│
│ STEP-BY-STEP DRY RUN:
│ Start base cells.
│ for i=2..n:
│    dp[i] = dp[i-1] + dp[i-2]
│ Answer dp[n].

│
│ COMPLEXITY CALCULATION:
│ Loop from 2 to n inclusive runs n-1 iterations.
│ Each iteration one addition.
│ Time = O(n).
│ DP array n+1 cells -> O(n) space.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int fibTab(int n) {
    if (n <= 1) return n;
    vector<int> dp(n+1, 0);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]; // Bottom-up table fill.
        cout << "dp[" << i << "]=" << dp[i] << "\n";
    }
    return dp[n];
}

int main() {
    cout << "fib(6) = " << fibTab(6) << "\n";
    return 0;
}

/*
OUTPUT:
dp[2]=1
dp[3]=2
dp[4]=3
dp[5]=5
dp[6]=8
fib(6) = 8
*/

