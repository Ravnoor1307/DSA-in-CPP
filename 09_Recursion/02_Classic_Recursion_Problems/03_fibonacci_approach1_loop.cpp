/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_fibonacci_approach1_loop.cpp
│
│ REAL-WORLD SCENARIO:
│ Rabbit population month by month previous two months par depend karti hai. Fibonacci loop me last two values maintain karke next value banate hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Fibonacci: fib(0)=0, fib(1)=1.
│ 2. fib(n)=fib(n-1)+fib(n-2).
│ 3. Loop me prev2 and prev1 maintain karo.
│ 4. i=2 se n tak current = prev1 + prev2.
│ 5. Efficient O(n) time and O(1) space.
│
│ ASCII VISUAL / RECURSION STATE:
│ n=6 sequence:
│ index: 0 1 2 3 4 5 6
│ fib:   0 1 1 2 3 5 8
│
│ prev2=0, prev1=1
│ i=2 curr=1
│ i=3 curr=2
│ i=4 curr=3
│ i=5 curr=5
│ i=6 curr=8
│
│ DRY RUN:
│ n=6
│ iterations from i=2..6 = 5 iterations.
│ final prev1=8.
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Loop starts at 2 and ends at n, so n-1 iterations for n>=2.
│ - Each iteration one addition and assignments.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only prev2, prev1, current variables.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibLoop(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

int main() {
    cout << "fib(6) loop = " << fibLoop(6) << "\n";
    return 0;
}

/*
OUTPUT:
fib(6) loop = 8
*/

