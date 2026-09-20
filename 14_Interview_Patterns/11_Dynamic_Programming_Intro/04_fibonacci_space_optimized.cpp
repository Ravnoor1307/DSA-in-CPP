/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_fibonacci_space_optimized.cpp
│
│ REAL-WORLD SCENARIO:
│ Fibonacci me next value ke liye sirf previous two values chahiye. Puri table rakhne ke bajay do variables ka travel bag enough hai.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ dp formula:
│ dp[i] = dp[i-1] + dp[i-2]
│
│ Only need:
│ prev2 = dp[i-2]
│ prev1 = dp[i-1]
│ cur = prev1 + prev2
│
│ n=6 states:
│ i=2 cur=1, prev2=1, prev1=1
│ i=3 cur=2, prev2=1, prev1=2
│ i=4 cur=3, prev2=2, prev1=3
│ i=5 cur=5
│ i=6 cur=8

│
│ STEP-BY-STEP DRY RUN:
│ Initialize prev2=0, prev1=1.
│ Loop i=2..n:
│ cur = prev1 + prev2
│ prev2 = prev1
│ prev1 = cur

│
│ COMPLEXITY CALCULATION:
│ Loop n-1 iterations -> O(n).
│ Each iteration constant addition/assignment.
│ Space uses prev2, prev1, cur -> 3 variables -> O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int fibOptimized(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int cur = prev1 + prev2;
        cout << "i=" << i << " cur=" << cur << "\n";
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << "fib(6) = " << fibOptimized(6) << "\n";
    return 0;
}

/*
OUTPUT:
i=2 cur=1
i=3 cur=2
i=4 cur=3
i=5 cur=5
i=6 cur=8
fib(6) = 8
*/

