/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_fibonacci_memoization_approach.cpp
│
│ REAL-WORLD SCENARIO:
│ Family tree style fibonacci calls repeat hote hain. Memo notebook me fib(i) result store karne se repeated calls crossed-out ho jaate hain.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ fib(5) recursion:
│ f5 -> f4 + f3
│ f4 -> f3 + f2
│ f3 repeated!
│ f2 repeated!
│
│ Memo array initially:
│ index: 0  1  2  3  4  5
│ memo: -1 -1 -1 -1 -1 -1
│
│ Fill as needed:
│ memo[0]=0, memo[1]=1
│ memo[2]=1
│ memo[3]=2
│ memo[4]=3
│ memo[5]=5
│
│ Repeated call fib(3)? direct memo[3]=2 return.

│
│ STEP-BY-STEP DRY RUN:
│ fibMemo(5)
│ compute fibMemo(4), fibMemo(3)
│ fibMemo(4) computes fib3 and fib2.
│ Later fibMemo(3) already memoized, no subtree expansion.

│
│ COMPLEXITY CALCULATION:
│ Without memo, recursion tree approximately doubles each level -> O(2^n).
│ With memo, unique states are 0,1,...,n = n+1 states.
│ Each state computes two transitions once -> O(2n)=O(n).
│ Space memo O(n) + call stack O(n) = O(n).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int fibMemo(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n]; // Repeated call crossed-out by memory.
    memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
    cout << "memo[" << n << "] = " << memo[n] << "\n";
    return memo[n];
}

int main() {
    int n = 5;
    vector<int> memo(n+1, -1);
    cout << "fib(" << n << ") = " << fibMemo(n, memo) << "\n";
    return 0;
}

/*
OUTPUT:
memo[2] = 1
memo[3] = 2
memo[4] = 3
memo[5] = 5
fib(5) = 5
*/

