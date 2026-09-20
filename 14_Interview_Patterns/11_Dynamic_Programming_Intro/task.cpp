/*
REAL-WORLD SCENARIO:
DP final lab: repeated calculations ko memory se optimize karna hai.

TASKS easy -> hard:
1. Fibonacci recursion tree draw karo.
2. Fibonacci memoization implement karo.
3. Fibonacci tabulation implement karo.
4. Fibonacci space optimized implement karo.
5. Climbing stairs 3 ways solve karo.
6. House robber solve karo.
7. Coin change min coins solve karo.
8. LCS and 0/1 knapsack recurrence comments me likho.

HINTS:
- State define karo first.
- Memo: if dp[state] exists return.
- Tab: base cases then fill order.

STARTER CODE:
vector<int> dp(n+1, -1);

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
using namespace std;

int fibMemo(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
}

int main() {
    int n = 6;
    vector<int> dp(n+1, -1);
    cout << fibMemo(n, dp) << "\n";
    return 0;
}

/*
OUTPUT:
8
*/
