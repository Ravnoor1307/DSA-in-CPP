/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 10_dp_problem_solving_framework.cpp
│
│ REAL-WORLD SCENARIO:
│ DP interview me direct table mat banao. Pehle recursion state socho, repeat dekho, memo lagao, tabulation me convert karo, then space optimize karo.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ 5-STEP METHOD:
│
│ 1. Recursion socho:
│    state kya hai? f(i), f(i,j), f(i,capacity)?
│
│ 2. Overlapping check:
│    same state repeat ho raha hai?
│
│ 3. Memoization:
│    dp[state] store karo.
│
│ 4. Tabulation:
│    base cases table me fill karo, order decide karo.
│
│ 5. Space optimize:
│    kya only previous row/value chahiye?
│
│ Template:
│ answer(state):
│   if base return
│   if memo exists return
│   compute transitions
│   store and return

│
│ STEP-BY-STEP DRY RUN:
│ Example house robber:
│ state f(i)=max loot till i.
│ choices: rob i or skip i.
│ recurrence f(i)=max(f(i-1), nums[i]+f(i-2)).
│ table left-to-right fill.
│ optimize with prev2, prev1.

│
│ COMPLEXITY CALCULATION:
│ DP complexity formula:
│ states count = S.
│ transition work per state = T.
│ Time = O(S*T).
│ Space = O(S) for memo/table, sometimes optimized.
│ Example LCS: S=n*m, T=1 -> O(n*m).

│ APPROACH COMPARISON TABLE:
│ | DP style | Analogy | Direction | Time idea | Space |
│ | Recursion | ask subproblems repeatedly | top-down no memory | often exponential | stack |
│ | Memoization | notebook cache | top-down | states * transitions | memo + stack |
│ | Tabulation | fill form row-wise | bottom-up | states * transitions | table |
│ | Space optimized | only needed previous data | bottom-up compact | same time | reduced |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    cout << "DP 5 steps:\n";
    cout << "1 recursion state\n";
    cout << "2 find overlapping states\n";
    cout << "3 memoize\n";
    cout << "4 tabulate\n";
    cout << "5 optimize space\n";
    cout << "Complexity = states * transition\n";
    return 0;
}

/*
OUTPUT:
DP 5 steps:
1 recursion state
2 find overlapping states
3 memoize
4 tabulate
5 optimize space
Complexity = states * transition
*/

