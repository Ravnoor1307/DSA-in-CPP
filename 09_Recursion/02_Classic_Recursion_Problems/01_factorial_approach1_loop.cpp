/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_factorial_approach1_loop.cpp
│
│ REAL-WORLD SCENARIO:
│ Sweets shop me 4 boxes arrange karne ke total ways 4*3*2*1 hote hain. Factorial ko loop se multiply karna simplest iterative method hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Factorial n! = n*(n-1)*...*1.
│ 2. ans=1 se start karo.
│ 3. i=1 to n tak ans *= i.
│ 4. Loop method call stack use nahi karta.
│ 5. n=0 ke liye 0! = 1.
│
│ ASCII VISUAL / RECURSION STATE:
│ 4! loop journey:
│ ans=1
│ i=1 -> ans=1
│ i=2 -> ans=2
│ i=3 -> ans=6
│ i=4 -> ans=24
│
│ DRY RUN:
│ n=4
│ loop runs 4 iterations.
│ multiplications: by 1,2,3,4.
│ final ans=24.
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Loop runs from 1 to n: exactly n iterations.
│ - Each iteration one multiplication.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only ans and i variables.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long factorialLoop(int n) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

int main() {
    cout << "4! using loop = " << factorialLoop(4) << "\n";
    return 0;
}

/*
OUTPUT:
4! using loop = 24
*/

