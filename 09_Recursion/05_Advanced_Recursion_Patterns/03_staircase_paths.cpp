/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_staircase_paths.cpp
│
│ REAL-WORLD SCENARIO:
│ Staircase par child ek baar me 1 ya 2 steps jump kar sakta hai. n steps tak pahunchne ke total ways Fibonacci jaisa pattern banate hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. ways(n) = ways(n-1) + ways(n-2).
│ 2. Base: n==0 means exact reach, return 1.
│ 3. Base: n<0 invalid path, return 0.
│ 4. Choice 1: take 1 step.
│ 5. Choice 2: take 2 steps.
│ 6. Ye Fibonacci in disguise hai.
│
│ ASCII VISUAL / RECURSION TREE STATE:
│ n=4 paths tree:
│
│ ways(4)
│ ├─ take1 -> ways(3)
│ │  ├─ take1 -> ways(2)
│ │  └─ take2 -> ways(1)
│ └─ take2 -> ways(2)
│
│ Actual paths:
│ 1+1+1+1
│ 1+1+2
│ 1+2+1
│ 2+1+1
│ 2+2
│ total=5
│
│ Fibonacci moment: ways(4)=5 like fib(5).
│
│ DRY RUN:
│ ways(3)=ways(2)+ways(1)
│ ways(2)=ways(1)+ways(0)=1+1=2
│ ways(1)=ways(0)+ways(-1)=1+0=1
│ ways(3)=3; ways(4)=5
│
│ FLOW OF EXECUTION:
│ input/problem state -> recursive choices -> base cases -> undo/unwind/output
│
│ COMPLEXITY CALCULATION:
│ - Naive recursion branches into 2 calls per non-base state.
│ - Tree height n, level k up to 2^k calls.
│ -> Time Complexity = O(2^n) naive.
│ - DP/memoization can make states 0..n once -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Deepest recursion path length n.
│ -> Space Complexity = O(n) call stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int countWays(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    cout << "Ways to climb 4 stairs = " << countWays(4) << "\n";
    cout << "This is Fibonacci in disguise.\n";
    return 0;
}

/*
OUTPUT:
Ways to climb 4 stairs = 5
This is Fibonacci in disguise.
*/

