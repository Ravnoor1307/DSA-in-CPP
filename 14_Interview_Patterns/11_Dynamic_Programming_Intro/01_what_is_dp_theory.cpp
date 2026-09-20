/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_what_is_dp_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Restaurant me same bill total baar-baar calculate karne ke bajay notebook me result likh lo. DP = recursion plus memory, repeated subproblems ko yaad rakhta hai.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ Fibonacci recursion tree fib(5):
│
│                  f5
│              /        \
│            f4          f3
│          /    \       /  \
│        f3     f2     f2  f1
│       /  \    / \    / \
│     f2   f1 f1 f0  f1 f0
│    / \
│   f1 f0
│
│ Repeated calls highlighted conceptually:
│ f3 appears 2 times, f2 appears 3 times, f1 many times.
│
│ DP = Recursion + Memory.
│ Journey:
│ plain recursion exponential -> memoization O(n) -> tabulation O(n) -> space optimized O(1)

│
│ STEP-BY-STEP DRY RUN:
│ fib(5) needs fib(4)+fib(3).
│ fib(4) again needs fib(3)+fib(2).
│ fib(3) repeated hota hai.
│ Memo stores fib(3) once, next time direct return.

│
│ COMPLEXITY CALCULATION:
│ Plain fibonacci recursion roughly branches 2 calls per level for n levels -> O(2^n).
│ Memoization has states fib(0)..fib(n), total n+1 states.
│ Each state constant work after subcalls -> O(n).
│ Memo array O(n), recursion stack O(n).

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
    cout << "DP = Recursion + Memory\n";
    cout << "Use when overlapping subproblems repeat.\n";
    cout << "Flow: recursion -> memoization -> tabulation -> optimize space.\n";
    return 0;
}

/*
OUTPUT:
DP = Recursion + Memory
Use when overlapping subproblems repeat.
Flow: recursion -> memoization -> tabulation -> optimize space.
*/

