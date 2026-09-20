/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_climbing_stairs_3_ways.cpp
│
│ REAL-WORLD SCENARIO:
│ Stairs chadhte time har step par 1 ya 2 steps le sakte ho. Ways(n) = ways(n-1)+ways(n-2), because last move 1-step ya 2-step ho sakta hai.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ n=4 stairs
│ Ways:
│ 1+1+1+1
│ 1+1+2
│ 1+2+1
│ 2+1+1
│ 2+2
│ total = 5
│
│ Three approaches:
│ Recursion: repeated calls, O(2^n)
│ Memo: states 0..n, O(n)
│ Tabulation: bottom-up dp, O(n)
│ Space optimized: two variables, O(1)

│
│ STEP-BY-STEP DRY RUN:
│ ways[0]=1, ways[1]=1
│ ways[2]=2
│ ways[3]=3
│ ways[4]=5

│
│ COMPLEXITY CALCULATION:
│ Recursion branches two calls per level -> O(2^n).
│ Memo/tab have n+1 states, each state one addition -> O(n).
│ Tab space O(n), optimized space O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int climbRec(int n) {
    if (n <= 1) return 1;
    return climbRec(n-1) + climbRec(n-2);
}

int climbMemo(int n, vector<int>& memo) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = climbMemo(n-1, memo) + climbMemo(n-2, memo);
}

int climbTab(int n) {
    vector<int> dp(n+1, 1);
    for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    int n = 4;
    vector<int> memo(n+1, -1);
    cout << "rec=" << climbRec(n) << "\n";
    cout << "memo=" << climbMemo(n, memo) << "\n";
    cout << "tab=" << climbTab(n) << "\n";
    return 0;
}

/*
OUTPUT:
rec=5
memo=5
tab=5
*/

