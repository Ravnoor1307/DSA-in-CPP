/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_sum_1_to_n_tail_recursion.cpp
│
│ REAL-WORLD SCENARIO:
│ Accountant running total carry karta hai: har step current amount accumulator me add, phir next smaller bill. Tail recursion me recursive call last operation hoti hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Tail recursion = recursive call function ka last kaam.
│ 2. sumTail(n, acc) me acc running answer hai.
│ 3. Base case: n==0 return acc.
│ 4. Recursive call: sumTail(n-1, acc+n).
│ 5. Compiler kabhi-kabhi tail recursion ko loop me optimize kar sakta hai, but C++ me guarantee nahi.
│
│ ASCII VISUAL / NUMBER STATE:
│ sumTail(5,0)
│ -> sumTail(4,5)
│ -> sumTail(3,9)
│ -> sumTail(2,12)
│ -> sumTail(1,14)
│ -> sumTail(0,15)
│ return 15
│
│ Last action is recursive call, no pending addition after return.
│
│ DRY RUN:
│ n=5 acc0
│ add 5 acc5
│ add 4 acc9
│ add 3 acc12
│ add 2 acc14
│ add 1 acc15
│ base n0 -> 15
│
│ FLOW OF EXECUTION:
│ input number -> reduce to smaller number/range -> base case -> return answer
│
│ COMPLEXITY CALCULATION:
│ - n decreases by 1 each call.
│ - Calls: n,n-1,...,0 = n+1 calls.
│ - Each call constant addition/check.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Without compiler tail-call optimization, stack depth n+1 -> O(n).
│ - If compiler optimizes, stack can become O(1), but not guaranteed in C++.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sumTail(int n, int acc) {
    if (n == 0) return acc;
    return sumTail(n - 1, acc + n); // tail call: last operation
}

int main() {
    cout << "sum 1..5 using tail recursion = " << sumTail(5, 0) << "\n";
    cout << "Tail recursion may be optimized like a loop, but C++ does not guarantee it.\n";
    return 0;
}

/*
OUTPUT:
sum 1..5 using tail recursion = 15
Tail recursion may be optimized like a loop, but C++ does not guarantee it.
*/

